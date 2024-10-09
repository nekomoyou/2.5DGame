#include "PlayerBase.h"

PlayerBase::PlayerBase(int ModelHandle)
    :modelHandle(-1),pos(VGet(0,0,0))
{
    modelHandle = MV1DuplicateModel(ModelHandle);
    if (modelHandle < 0)
    {
        printfDx("ƒf[ƒ^“Ç‚Ýž‚Ý‚ÉŽ¸”s. sourceId:%d", ModelHandle);
    }
}

void PlayerBase::Draw()
{
    MV1DrawModel(modelHandle);
}

PlayerBase::~PlayerBase()
{
    MV1DeleteModel(modelHandle);
}