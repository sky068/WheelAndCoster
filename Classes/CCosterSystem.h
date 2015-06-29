//
//  CCosterSystem.h
//  Wheel
//
//  Created by xujw on 15/6/27.
//
//

#ifndef __Wheel__CCosterSystem__
#define __Wheel__CCosterSystem__

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class CCosterSystem
{
public:
    static CCosterSystem* getInstance();
    const ValueMap getCellDataByIndex(const int index) const;
    const int getCellRewardByIndex(const int index) const;
private:
    ValueMap _allData;
    void readData();
    //获取cell的顺序列表，通过index从而找到对应的cell
    const ValueVector getCellOrder() const;
};

#endif /* defined(__Wheel__CCosterSystem__) */
