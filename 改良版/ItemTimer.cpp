#include "ItemTimer.h"

ItemTimer::ItemTimer()
    :ItemNum(2)
    ,Count(5)
{
    //ˆ—‚È‚µ
}

/// <summary>
/// ‰Šú‰»
/// </summary>
void ItemTimer::Init()
{
    ItemNum = 2;
    Count = 4;
}

/// <summary>
/// —‚Æ‚·ƒAƒCƒeƒ€‚Ì”
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