//
//  CWheelLayer.cpp
//  Wheel
//
//  Created by xujw on 15/6/25.
//
//

#include "CCoster.h"
#include "../cocos2d/cocos/ui/CocosGUI.h"
#include "CSoundTools.h"
#include "CCosterSystem.h"

using namespace ui;

const int height = 94;
const int weight = 94;
#define winSize Director::getInstance()->getWinSize()

CCoster::CCoster():_cellNum(0)
                        ,_allRunNum(0)
                        ,_stopAllNum(0)
                        ,_curNum(0)
                        ,_desNum(0)
{}
CCoster::~CCoster(){}

bool CCoster::init()
{
    if (!Layer::init())
    {
        return false;
    }
    auto btn = Button::create("start.png","start0.png");
    this->addChild(btn,0,100);
    btn->setPosition(winSize/2);
    btn->addTouchEventListener([this,btn](Ref* tar,Widget::TouchEventType type)
    {
        if (type == Widget::TouchEventType::ENDED)
        {
            CCLOG("run...");
            CSoundTools::playEffect(BTN_SPIN);
            _allRunNum = 0;
            btn->setEnabled(false);
            //随机转2-3圈 然后停在指定位置 一圈18个格子
            //改变_desNum来改变挺的位置 0--_cellVec.size()-1
            _desNum = arc4random()%18;
            _stopAllNum = 2*18 + (18-_curNum) + _desNum;
            this->schedule(schedule_selector(CCoster::run), 0.5f);
        }
        
    });
    
    addCells();
    _cellVect.at(_curNum)->setLight(true);
    
    return true;
}

void CCoster::popCosterLayer()
{
    auto l = CCoster::create();
    Director::getInstance()->getRunningScene()->addChild(l);
}

void CCoster::run(float dt)
{
    CCLOG("dt = %f",dt);
    CSoundTools::playEffect(COSTER_JUMP);
    if (_cellVect.size()>0)
    {
        _cellNum++;
        if (_cellNum>_cellVect.size()-1)
        {
            _cellNum = 0;
        }
        auto cell = _cellVect.at(_cellNum);
        cell->setLight(true);
        //把上一个变回来
        int lastNum = _cellNum-1;
        if (lastNum<0)
        {
            lastNum = _cellVect.size()-1;
        }
        cell = _cellVect.at(lastNum);
        cell->setLight(false);
    }
    _allRunNum++;

    if (_allRunNum<_stopAllNum-15)
    {
        unschedule(schedule_selector(CCoster::run));
        //加速 然后匀速
        float nextTime = dt - 0.1;
        if (nextTime<=0.06)
        {
            nextTime = 0.06;
        }
        this->schedule(schedule_selector(CCoster::run), nextTime);
    }
   
    if (_allRunNum>(_stopAllNum-10) && _allRunNum<_stopAllNum)
    {
        unschedule(schedule_selector(CCoster::run));
        float nextTime = dt + 0.05;
        if (nextTime>=1.0) {
            nextTime = 1.0;
        }
        this->schedule(schedule_selector(CCoster::run), nextTime);
    }
    if(_allRunNum>=_stopAllNum)
    {
        unschedule(schedule_selector(CCoster::run));
        auto btn = dynamic_cast<Button*>(getChildByTag(100));
        if (btn)
        {
            btn->setEnabled(true);
        }
        _curNum = _desNum;
        
        CCLOG("cur cell index:%d,cur cell id:%d",_curNum,_cellVect.at(_desNum)->getCellID());
        
        //记录摇奖结果
//        std::string path = FileUtils::getInstance()->getWritablePath();
//        path += "test.txt";
//        CCLOG("write path:%s",path.c_str());
//        FILE *file = fopen(path.c_str(), "a+");
//        std::string s = StringUtils::format("cur cell:%d,cur cell id:%d \n",_curNum,_cellVect.at(_desNum)->getCellID());
//        fprintf(file, s.c_str());
//        fclose(file);
        popRewarsLayer();
    }
}

void CCoster::popRewarsLayer()
{
    auto reward = CCosterSystem::getInstance()->getCellRewardByIndex(_desNum);
    if (reward!=0)
    {
        CSoundTools::playEffect(ON_WIN);
        auto s = StringUtils::format("You have got %d chips!",reward);
        MessageBox(s.c_str(),"Congratulation");
    }
}

void CCoster::addCells()
{
    //格子从左下角开始顺时针编号0-17。
    //对应数据表的CellOrder:0-17
    //然后通过序号可以找到对应的格子的数据
    //left
    int id = 0;
    for (int i=0; i<5; i++)
    {
        auto cell = CCell::createWithIndex(id);
        cell->setPosition(240,150+height*i);
        this->addChild(cell);
        _cellVect.push_back(cell);
        id++;
    }
    //up
    for (int i = 1; i<5; i++)
    {
        auto cell = CCell::createWithIndex(id);
        cell->setPosition(240+weight*i,150+height*4);
        this->addChild(cell);
        _cellVect.push_back(cell);
        id++;
    }
    //right
    for (int i=4; i>=0; i--)
    {
        auto cell = CCell::createWithIndex(id);
        cell->setPosition(240+weight*5,150+height*i);
        this->addChild(cell);
        _cellVect.push_back(cell);
        id++;
    }
    //down
    for (int i = 4; i>=1; i--)
    {
        auto cell = CCell::createWithIndex(id);
        cell->setPosition(240+weight*i,150);
        this->addChild(cell);
        _cellVect.push_back(cell);
        id++;
    }
}