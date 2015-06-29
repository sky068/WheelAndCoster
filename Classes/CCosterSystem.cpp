//
//  CCosterSystem.cpp
//  Wheel
//
//  Created by xujw on 15/6/27.
//
//

#include "CCosterSystem.h"

static CCosterSystem *ins = nullptr;

CCosterSystem* CCosterSystem::getInstance()
{
    if (!ins) {
        ins = new(std::nothrow) CCosterSystem();
        ins->readData();
    }
    return ins;
}

void CCosterSystem::readData()
{
    _allData = FileUtils::getInstance()->getValueMapFromFile("CosterCellConfig.plist");
}

const ValueVector CCosterSystem::getCellOrder() const
{
    return _allData.at("CellOrder").asValueVector();
}

const ValueMap CCosterSystem::getCellDataByIndex(const int index) const
{
    auto order = getCellOrder();
    auto id = order.at(index).asInt();
    auto key = StringUtils::format("%d",id);
    return _allData.at(key).asValueMap();
}

const int CCosterSystem::getCellRewardByIndex(const int index) const
{
    auto data = this->getCellDataByIndex(index);
    return data.at("reward").asInt();
}