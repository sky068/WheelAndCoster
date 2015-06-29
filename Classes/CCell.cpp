//
//  CCell.cpp
//  Wheel
//
//  Created by xujw on 15/6/25.
//
//

#include "CCell.h"
#include "CCosterSystem.h"

CCell::CCell():_light(nullptr)
                ,_cellID(-1)
{}
CCell::~CCell(){}

CCell * CCell::create(const std::string &fileName,bool light)
{
    auto cell = new(std::nothrow) CCell();
    if (cell && cell->init(fileName,light))
    {
        cell->autorelease();
        return cell;
    }
    CC_SAFE_DELETE(cell);
    return nullptr;
}
bool CCell::init(const std::string &fileName,bool light)
{
    if (!Node::init())
    {
        return false;
    }
    auto bd = Sprite::create("bd.png");
    this->addChild(bd);
    _light = Sprite::create("xz.png");
    bd->addChild(_light,0);
    auto sp = Sprite::create(fileName);
    bd->addChild(sp,1);
    sp->setPosition(sp->getContentSize()/2);
    
    _light->setPosition(_light->getContentSize()/2);
    if (!light)
    {
        auto fout = FadeOut::create(0.1f);
        _light->runAction(fout);;
    }
    
    return true;
}

CCell * CCell::createWithIndex(const int index,bool light)
{
    auto cell = new(std::nothrow) CCell();
    if (cell && cell->initWithIndex(index,light))
    {
        cell->autorelease();
        return cell;
    }
    CC_SAFE_DELETE(cell);
    return nullptr;
}
bool CCell::initWithIndex(const int index,bool light)
{
    auto dic = CCosterSystem::getInstance()->getCellDataByIndex(index);
    
    auto bd = Sprite::create("bd.png");
    this->addChild(bd);
    _light = Sprite::create("xz.png");
    bd->addChild(_light,0);
    
    auto sp = Sprite::create(dic.at("img").asString());
    bd->addChild(sp,1);
    sp->setPosition(sp->getContentSize()/2);
    
    _light->setPosition(_light->getContentSize()/2);
    if (!light)
    {
        auto fout = FadeOut::create(0.1f);
        _light->runAction(fout);;
    }
    
    this->setCellID(dic.at("Fid").asInt());
    
    return true;
}

void CCell::setLight(bool flag)
{
    if (flag)
    {
        auto fin = FadeIn::create(0.1f);
        _light->runAction(fin);
    }
    else
    {
        auto fout = FadeOut::create(0.5f);
        _light->runAction(fout);
    }
    return;
}