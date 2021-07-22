#include "CollisionManager.h"

CollisionManager::CollisionManager(Player &p, Ball &b, std::vector<Powerup*> &pu, std::vector<Bullet> &bu){
    powerups = &pu;
    player = &p;
    ball = &b;
    bullets = &bu;
    factory = new PowerupFactory(b, p, bu);
}

void CollisionManager::setBrickInterface(BrickInterface* brickInterface){
    this->brickInterface = brickInterface;
}

void CollisionManager::collision(){
    int i = 0; //bullet position counter
    int j = 0; //brick position counter
    bool collision = false;
    for (auto &border : brickInterface->getBorderb()){
        if(!collision){
            collision = collisionBlock(*border, j);
        }
    }
    collision = false;
    for (auto &mapBrick : brickInterface->getMapb()){
        if(!collision){
            collision = collisionBlock(*mapBrick, j);
        }
        j++;
    }
    collision = false;
    for (auto &p : *powerups){
        collisionPowerup(*p);
    }
    for (auto &b : *bullets){
        j = 0;
        for (auto &br : brickInterface->getMapb()){
            if(!collision){
                collision = collisionBullet(b,*br,i,j);
            }
            j++;
        }
        for (auto &br : brickInterface->getBorderb()){
            if(!collision){
                collision = collisionBullet(b,*br,i,j);
            }
        }
        i++;
        collision = false;
    }
    collisionPlayer();
}

bool CollisionManager::collisionBlock(Brick &b, int j){
    sf::FloatRect rec_ball = ball->getSprite().getGlobalBounds();
    sf::FloatRect rec_Brick = b.getSprite().getGlobalBounds();
    tmx::Vector2f newVelocity = ball->getVelocity();

    if (rec_ball.intersects(rec_Brick)){

        if(b.getId() == 1){ //distinguir entre bloques del contorno y los internos
            if(100 > rand() % 100){
                powerups->push_back(factory->getPowerup());
                powerups->at(powerups->size() - 1)->setPosition(ball->getPosition());
            }
            brickInterface->getMapb().erase(brickInterface->getMapb().begin() + j);
        }

        if (ball->getVelocity().x >= 0 && rec_ball.left + rec_ball.width - ball->getVelocity().x >= rec_Brick.left){
            newVelocity.y *= -1;
            ball->setVelocity(newVelocity);
            return true;
        }
        if (ball->getVelocity().x <= 0 && rec_ball.left - ball->getVelocity().x <= rec_Brick.left + rec_Brick.width){
            newVelocity.y *= -1;
            ball->setVelocity(newVelocity);
            return true;
        }
        if (ball->getVelocity().y <= 0 && rec_ball.top - ball->getVelocity().y <= rec_Brick.top + rec_Brick.height){
            newVelocity.x *= -1;
            ball->setVelocity(newVelocity);
            return true;
        }
        if (ball->getVelocity().y >= 0 && rec_ball.top + rec_ball.height - ball->getVelocity().y >= rec_Brick.top){
            newVelocity.x *= -1;
            ball->setVelocity(newVelocity);
            return true;
        }
    }
    return false;
}

void CollisionManager::collisionPlayer(){
    int moduloVelocidad = 5;
    float cociente, constante = atan(1) * 4;
    sf::FloatRect rec_ball = ball->getSprite().getGlobalBounds();
    sf::FloatRect rec_player = player->getSprite().getGlobalBounds();
    tmx::Vector2f newVelocity;

    if (rec_ball.intersects(rec_player)){
        cociente = ((rec_ball.left + rec_ball.width / 2 ) - (rec_player.left - rec_ball.width / 2)) / (rec_player.width + rec_ball.width);
        if (cociente < 0.15) cociente = 0.15;
        if (cociente > 0.85) cociente = 0.85;
        cociente *= constante;
        newVelocity.x = -cos(cociente) * moduloVelocidad;
        newVelocity.y = -sin(cociente) * moduloVelocidad;
        ball->setVelocity(newVelocity);
    }
}

void CollisionManager::collisionPowerup(Powerup &p){
    sf::FloatRect rec_powerup = p.getSprite().getGlobalBounds();
    sf::FloatRect rec_player = player->getSprite().getGlobalBounds();
    tmx::Vector2f posicion(0,1800);

    if (rec_player.intersects(rec_powerup)){
        p.effect();
        p.setPosition(posicion);
    }
}

bool CollisionManager::collisionBullet(Bullet &b,Brick &br, int i, int j){
    sf::FloatRect rec_bullet = b.getSprite().getGlobalBounds();
    sf::FloatRect rec_brick = br.getSprite().getGlobalBounds();

    if (rec_brick.intersects(rec_bullet)){
        bullets->erase(bullets->begin() + i);
        if(br.getId() == 1){
            brickInterface->getMapb().erase(brickInterface->getMapb().begin() + j);
        }
        return true;
    }
    return false;
}