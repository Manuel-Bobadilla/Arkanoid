//
// Created by Facundo Barafani on 15/5/21.
//

#include "SoundManager.h"

void SoundManager::loadSoundBuffer(std::string name, std::string filePath) {
    sf::SoundBuffer sb;
    sf::Sound s;

    if (sb.loadFromFile(filePath)) {
        this->soundBuffers[name] = sb;
        s.setBuffer(sb);
        this->sounds[name] = s;
    }
}

void SoundManager::playSound(std::string name) {
    this->sounds.at(name).play();
}

void SoundManager::playMusic(sf::Music &music, std::string filePath) {

    if (music.openFromFile(filePath)) {
        music.play();
    }
}