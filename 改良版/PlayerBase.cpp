#include "PlayerBase.h"

PlayerBase::PlayerBase(const char* ModelHandle)
    :modelHandle(-1)
    ,pos(VGet(0, 0, 0))
    ,dir(VGet(0,0,0))
    ,pushLeft(false)
    ,pushRight(false)
    ,pushJump(true)
    ,onGround(true)
    ,BodyHitpos(VGet(920,720,0))
{
    modelHandle = MV1LoadModel(ModelHandle);
    if (modelHandle < 0)
    {
        printfDx("データ読み込みに失敗. sourceId:%d", ModelHandle);
    }
    MV1SetScale(modelHandle, VGet(0.3, 0.3, 0.3));

    AnimPlaybackIndex = 3;

    Gravity = 5.0f;
    JumpPow = 100.0f;

    Hitpos = VGet(890, 710, 0);

    angle = MV1GetRotationXYZ(modelHandle);
}

/// <summary>
/// 初期化
/// </summary>
void PlayerBase::Init()
{
    pos = VGet(0, 0, 0);
    MV1SetPosition(modelHandle, pos);
    Hitpos = VGet(890, 650, 0);
    AnimPlaybackIndex = 3;
    pushJump = true;
    MV1SetRotationXYZ(modelHandle, angle);
}

/// <summary>
/// 移動処理
/// </summary>
void PlayerBase::IsMove()
{
    //左を押したときの処理
    if (CheckHitKey(KEY_INPUT_LEFT))
    {
        dir = VGet(-PlayerSpeed, 0, 0);
        MV1SetRotationXYZ(modelHandle, VGet(0.0f, 90.0f * DX_PI_F / 180.0f, 0.0f));
        pushLeft = true;
        AnimPlaybackIndex = 11;
    }
    else
    {
        pushLeft = false;
    }
    //右を押したときの処理
    if (CheckHitKey(KEY_INPUT_RIGHT))
    {
        dir = VGet(PlayerSpeed, 0, 0);
        MV1SetRotationXYZ(modelHandle, VGet(0.0f, -90.0f * DX_PI_F / 180.0f, 0.0f));
        pushRight = true;
        AnimPlaybackIndex = 11;
    }
    else
    {
        pushRight = false;
    }

    //どちらも押してないときの処理
    if (pushLeft == false && pushRight == false)
    {
        dir = VGet(0, 0, 0);
        MV1SetRotationXYZ(modelHandle, angle);
        AnimPlaybackIndex = 3;
    }

    //端に行った時の処理
    if (Hitpos.x >= 1800)
    {
        dir = VGet(-PlayerSpeed, 0, 0);
    }
    if (Hitpos.x <= 0)
    {
        dir = VGet(PlayerSpeed, 0, 0);
    }
    Hitpos = VAdd(Hitpos, VScale(dir, HitSpeed));

    //ジャンプを押したときの処理
    if (CheckHitKey(KEY_INPUT_SPACE))
    {
        if (!pushJump && onGround)
        {
            dir = VAdd(dir, VGet(0, JumpPow, 0));
            Hitpos = VSub(Hitpos, VGet(0, JumpPow , 0));
            pushJump = true;
        }
    }
    else
    {
        pushJump = false;
    }
    //重力
    if (Hitpos.y < 650)
    {
        dir = VSub(dir, VGet(0, Gravity, 0));
        Hitpos = VAdd(Hitpos, VGet(0, Gravity, 0));
        onGround = false;
    }
    else
    {
        onGround = true;
    }
    pos = VAdd(pos, dir);
}

/// <summary>
/// 描画
/// </summary>
void PlayerBase::Draw()
{
    MV1DrawModel(modelHandle);
    DrawBox(Hitpos.x, Hitpos.y, Hitpos.x + 130, Hitpos.y + 30, GetColor(255, 0, 0), false);
    DrawBox(BodyHitpos.x, BodyHitpos.y, BodyHitpos.x + 80, BodyHitpos.y + 120, GetColor(255, 0, 0), false);
}

/// <summary>
/// 更新処理
/// </summary>
void PlayerBase::Update()
{
    MV1SetPosition(modelHandle, pos);
}

PlayerBase::~PlayerBase()
{
    MV1DeleteModel(modelHandle);
}