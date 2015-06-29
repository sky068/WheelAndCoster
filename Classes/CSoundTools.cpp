//
//  CSoundTools.cpp
//  Wheel
//
//  Created by xujw on 15/6/25.
//
//

#include "CSoundTools.h"

void CSoundTools::loadMusic(const char* file)
{
    SimpleAudioEngine::getInstance()->preloadBackgroundMusic(file);
}
void CSoundTools::loadEffect(const char* file)
{
    SimpleAudioEngine::getInstance()->preloadEffect(file);
}
void CSoundTools::playEffect(const char *file)
{
    SimpleAudioEngine::getInstance()->playEffect(file);
}
void CSoundTools::playMusic(const char *file)
{
    SimpleAudioEngine::getInstance()->playBackgroundMusic(file);
}
void CSoundTools::pauseMusic()
{
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}
void CSoundTools::resumeMusic()
{
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
void CSoundTools::pauseAllEffect()
{
    SimpleAudioEngine::getInstance()->pauseAllEffects();
}
void CSoundTools::resumeAllEffect()
{
    SimpleAudioEngine::getInstance()->resumeAllEffects();
}