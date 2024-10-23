#include "PlayerBase.h"

PlayerBase::PlayerBase(const char* ModelHandle)
    :modelHandle(-1), pos(VGet(0, 0, 0)), pushLeft(false), pushRight(false), AnimPlayTime(0)
{
    modelHandle = MV1LoadModel(ModelHandle);
    if (modelHandle < 0)
    {
        printfDx("データ読み込みに失敗. sourceId:%d", ModelHandle);
    }
    MV1SetScale(modelHandle, VGet(0.3, 0.3, 0.3));
    //付属モーションのアタッチ
    //AnimStopIndex = MV1AttachAnim(modelHandle, 3, -1, false);
    AnimWalkIndex = MV1AttachAnim(modelHandle, 14, -1, false);

    //AnimPlaybackIndex = Walk;

    Hitpos = VGet(890, 650, 0);

    //総再生時間の取得
    AnimTotalTime = MV1GetAttachAnimTotalTime(modelHandle, AnimWalkIndex);

    angle = MV1GetRotationXYZ(modelHandle);
}

void PlayerBase::IsMove()
{
    if (CheckHitKey(KEY_INPUT_LEFT))
    {
        pos = VAdd(pos, VGet(-PlayerSpeed, 0, 0));
        MV1SetRotationXYZ(modelHandle, VGet(0.0f, 90.0f * DX_PI_F / 180.0f, 0.0f));
        pushLeft = true;
        Hitpos = VAdd(Hitpos, VGet(-PlayerSpeed*1.8, 0, 0));
        //MV1DetachAnim(modelHandle, AnimStopIndex);
        //AnimPlaybackIndex = Walk;
    }
    else
    {
        pushLeft = false;
        //AnimPlaybackIndex = Stop;
    }
    if (CheckHitKey(KEY_INPUT_RIGHT))
    {
        pos = VAdd(pos, VGet(PlayerSpeed, 0, 0));
        MV1SetRotationXYZ(modelHandle, VGet(0.0f, -90.0f * DX_PI_F / 180.0f, 0.0f));
        pushRight = true;
        Hitpos = VAdd(Hitpos, VGet(PlayerSpeed * 1.8, 0, 0));
        //AnimPlaybackIndex = Walk;
    }
    else
    {
        pushRight = false;
        //AnimPlaybackIndex = Stop;
    }
    if (pushLeft == false && pushRight == false)
    {
        MV1SetRotationXYZ(modelHandle, angle);
    }
}

void PlayerBase::Draw()
{
    MV1DrawModel(modelHandle);
    DrawBox(Hitpos.x, Hitpos.y, Hitpos.x + 130, Hitpos.y + 30, GetColor(255, 0, 0), false);
}

void PlayerBase::Update()
{
    MV1SetPosition(modelHandle, pos);
}

void PlayerBase::animtion()
{
    //再生時間の調整
    if (AnimPlayTime++ >= AnimTotalTime)
    {
        AnimPlayTime = 0;
    }
    MV1SetAttachAnimTime(modelHandle, AnimWalkIndex, AnimPlayTime);
}

PlayerBase::~PlayerBase()
{
    MV1DeleteModel(modelHandle);
}

void PlayerBase::a()
{
    switch (AnimPlaybackIndex)
    {
    //case Stop:
        //MV1DetachAnim(modelHandle, AnimWalkIndex);
        //AnimStopIndex= MV1AttachAnim(modelHandle, 3, -1, false);
    //case Walk:
        //MV1DetachAnim(modelHandle, AnimStopIndex);
        //AnimWalkIndex = MV1AttachAnim(modelHandle, 14, -1, false);
        //MV1SetAttachAnimTime(modelHandle, AnimWalkIndex, AnimPlayTime);
    }
}