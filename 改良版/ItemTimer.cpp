#include "ItemTimer.h"

ItemTimer::ItemTimer()
    :ItemNum(2)
    ,Count(5)
{
    //�����Ȃ�
}

/// <summary>
/// ������
/// </summary>
void ItemTimer::Init()
{
    ItemNum = 2;
    Count = 4;
}

/// <summary>
/// ���Ƃ��A�C�e���̐�
/// </summary>
int ItemTimer::showItem()
{
    if (CountTime <= 25 * Count && Count >= 1)
    {
        ItemNum+=2;
        Count--;
    }
    return ItemNum;
}

ItemTimer::~ItemTimer()
{

}