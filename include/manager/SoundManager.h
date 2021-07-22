//
// Created by Facundo Barafani on 15/5/21.
//

#ifndef INCLUDE_SOUNDMANAGER_H
#define INCLUDE_SOUNDMANAGER_H

#include <SFML/Audio.hpp>
#include <map>

class SoundManager {
private:
    std::map<std::string, sf::Sound> sounds;
    std::map<std::string, sf::SoundBuffer> soundBuffers;
public:
    SoundManager() {}
    ~SoundManager() {}
    void loadSoundBuffer(std::string name, std::string filePath);
    void playSound(std::string name);
    void playMusic(sf::Music &music, std::string filePath);
};


#endif //INCLUDE_SOUNDMANAGER_H
