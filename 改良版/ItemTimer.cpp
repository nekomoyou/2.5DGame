#include "ItemTimer.h"

ItemTimer::ItemTimer()
    :ItemNum(1)
    ,Count(5)
{
    
}

/// <summary>
/// ‰Šú‰»
/// </summary>
void ItemTimer::Init()
{
    ItemNum = 1;
    Count = 5;
}

/// <summary>
/// —‚Æ‚·ƒAƒCƒeƒ€‚Ì”
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