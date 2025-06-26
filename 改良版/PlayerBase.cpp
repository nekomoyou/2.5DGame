#include "PlayerBase.h"

PlayerBase::PlayerBase(const char* ModelHandle)
    :modelHandle(-1)
    ,pos(VGet(0, 0, 0))
    ,dir(VGet(0,0,0))
    ,pushLeft(false)
    ,pushRight(false)
    ,pushDash(true)
    ,PlayerSpeed(5)
    ,dashframe(0)
{
    //モデルの読み込み
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
    gauge = VGet(895, 710, 0);

    angle = MV1GetRotationXYZ(modelHandle);

    //hitfallflg = false;
    Init();
}

/// <summary>
/// 初期化
/// </summary>
void PlayerBase::Init()
{
    pos = VGet(0, 0, 0);
    MV1SetPosition(modelHandle, pos);
    Hitpos = VGet(890, 710, 0);
    AnimPlaybackIndex = 3;
    pushDash = true;
    MV1SetRotationXYZ(modelHandle, angle);
    gauge = VGet(895, 710, 0);
    dashframe = 0;
    graphflg = false;
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
        Hitpos = VGet(1800, Hitpos.y, Hitpos.z);
        //dir = VGet(0, 0, 0);
        dir = VGet(-PlayerSpeed, 0, 0);
    }
    if (Hitpos.x <= 0)
    {
        Hitpos = VGet(0, Hitpos.y, Hitpos.z);
        //dir = VGet(0, 0, 0);
        dir = VGet(PlayerSpeed, 0, 0);
    }

    //ダッシュを押したときの処理
    if (CheckHitKey(KEY_INPUT_SPACE))
    {
        dashframe += 12;
        if (!pushDash || dashframe < 120)
        {
            PlayerSpeed = 5 * 2.5;
            pushDash = true;
        }
        else
        {
            PlayerSpeed = 5;
        }
    }
    else
    {
        dashframe -= 2;
        PlayerSpeed = 5;
        pushDash = false;
        if (dashframe <= 0)
        {
            dashframe = 0;
        }
    }
    if (dashframe >= 120)
    {
        dashframe = 120;
    }
    Hitpos = VAdd(Hitpos, VScale(dir, HitSpeed));
    pos = VAdd(pos, dir);
    gauge = VAdd(gauge, VScale(dir, HitSpeed));
}

/// <summary>
/// 描画
/// </summary>
void PlayerBase::Draw(bool flg,bool drawflg)
{
    static int f;
    if (drawflg)
    {
        graphflg = true;
    }
    if (graphflg)
    {
        f++;
        if (f >= 75 && f % 5 != 0)
        {
            MV1SetOpacityRate(modelHandle, 0);
        }
        else
        {
            MV1SetOpacityRate(modelHandle, 1);
        }
    }
    if(f >= 100)
    {
        graphflg = false;
        f = 0;
    }
    MV1DrawModel(modelHandle);
    //DrawBox(Hitpos.x, Hitpos.y, Hitpos.x + 130, Hitpos.y + 30, GetColor(255, 0, 0), false);
        DrawBox(gauge.x - 3, gauge.y - 3, gauge.x + 123, gauge.y + 33, GetColor(0, 0, 0), true);
        DrawBox(gauge.x, gauge.y, gauge.x + 120 - dashframe, gauge.y + 30, GetColor(255, 0, 0), true);
    
}

void PlayerBase::ResultAnim()
{
    pos = VGet(150, 0, -200);
    MV1SetRotationXYZ(modelHandle, VGet(0, 30.0f * DX_PI_F / 180.0f,0));
    MV1SetPosition(modelHandle, pos);
    MV1DrawModel(modelHandle);
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