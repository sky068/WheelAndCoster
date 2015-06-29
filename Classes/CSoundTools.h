//
//  CSoundTools.h
//  Wheel
//
//  Created by xujw on 15/6/25.
//
//

#ifndef __Wheel__CSoundTools__
#define __Wheel__CSoundTools__

#include <stdio.h>
#include "../cocos2d/cocos/audio/include/SimpleAudioEngine.h"
using namespace CocosDenshion;

#define TURN_TABLE "sounds/game_turntable.mp3"
#define COSTER_JUMP "sounds/game_jump.mp3"
#define BTN_TOUCH "sounds/btn_bubble.mp3"
#define BTN_SPIN "sounds/spin_button.mp3"
#define ON_WIN "sounds/game_win.mp3"


class CSoundTools
{
public:
    static void loadMusic(const char* file);
    static void loadEffect(const char* file);
    static void playEffect(const char* file);
    static void playMusic(const char* file);
    static void pauseMusic();
    static void resumeMusic();
    static void pauseAllEffect();
    static void resumeAllEffect();
};

#endif /* defined(__Wheel__CSoundTools__) */
