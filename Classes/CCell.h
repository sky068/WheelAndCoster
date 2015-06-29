//
//  CCell.h
//  Wheel
//
//  Created by xujw on 15/6/25.
//
// cell of Coster

#ifndef __Wheel__CCell__
#define __Wheel__CCell__

#include <stdio.h>

#include "cocos2d.h"
USING_NS_CC;

class CCell:public Node
{
public:
    CCell();
    ~CCell();
    static CCell * create(const std::string &fileName,bool light = false);
    static CCell * createWithIndex(const int index,bool light = false);

    bool init(const std::string &fileName,bool light = false);
    bool initWithIndex(const int index,bool light = false);

    void setLight(bool flag);
    CC_SYNTHESIZE(int, _cellID, CellID);
private:
    Sprite *_light;
};

#endif /* defined(__Wheel__CCell__) */
