#include "ItemTimer.h"

ItemTimer::ItemTimer()
    :ItemNum(1)
    ,Count(5)
{
    
}

/// <summary>
/// ������
/// </summary>
void ItemTimer::Init()
{
    ItemNum = 1;
    Count = 5;
}

/// <summary>
/// ���Ƃ��A�C�e���̐�
/// </summary>
void ItemTimer::showItem()
{
    if (CountTime <= 15 * Count && Count >= 1)
    {
        ItemNum++;
        Count--;
    }
}

ItemTimer::~ItemTimer()
{

}