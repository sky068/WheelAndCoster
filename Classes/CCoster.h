//
//  CWheelLayer.h
//  Wheel
//
//  Created by xujw on 15/6/25.
//
//

#ifndef __Wheel__CWheelLayer__
#define __Wheel__CWheelLayer__

#include <stdio.h>
#include "CCell.h"
#include <vector>

class CCoster:public Layer
{
public:
    CCoster();
    ~CCoster();
    bool init();
    CREATE_FUNC(CCoster);
    static void popCosterLayer();
private:
    std::vector<CCell*> _cellVect;
    void addCells();
    void run(float dt);
    //用来让格子循环的计数 0--_cellVect.size()-1
    int _cellNum;
    //一次旋转累走格子的计数
    int _allRunNum;
    //一次旋转结束时所走的格子计数
    int _stopAllNum;
    //一次旋转想要挺的位置 0--_cellVect.size()-1
    int _desNum;
    //当前停在的位置 左下角为0
    int _curNum;
    
    void popRewarsLayer();
};

#endif /* defined(__Wheel__CWheelLayer__) */
