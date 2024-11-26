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
        printfDx("�f�[�^�ǂݍ��݂Ɏ��s. sourceId:%d", ModelHandle);
    }
    MV1SetScale(modelHandle, VGet(0.3, 0.3, 0.3));

    AnimPlaybackIndex = 3;

    Gravity = 5.0f;
    JumpPow = 100.0f;

    Hitpos = VGet(890, 710, 0);

    angle = MV1GetRotationXYZ(modelHandle);
}

/// <summary>
/// ������
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
/// �ړ�����
/// </summary>
void PlayerBase::IsMove()
{
    //�����������Ƃ��̏���
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
    //�E���������Ƃ��̏���
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

    //�ǂ���������ĂȂ��Ƃ��̏���
    if (pushLeft == false && pushRight == false)
    {
        dir = VGet(0, 0, 0);
        MV1SetRotationXYZ(modelHandle, angle);
        AnimPlaybackIndex = 3;
    }

    //�[�ɍs�������̏���
    if (Hitpos.x >= 1800)
    {
        dir = VGet(-PlayerSpeed, 0, 0);
    }
    if (Hitpos.x <= 0)
    {
        dir = VGet(PlayerSpeed, 0, 0);
    }
    Hitpos = VAdd(Hitpos, VScale(dir, HitSpeed));

    //�W�����v���������Ƃ��̏���
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
    //�d��
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
/// �`��
/// </summary>
void PlayerBase::Draw()
{
    MV1DrawModel(modelHandle);
    DrawBox(Hitpos.x, Hitpos.y, Hitpos.x + 130, Hitpos.y + 30, GetColor(255, 0, 0), false);
    DrawBox(BodyHitpos.x, BodyHitpos.y, BodyHitpos.x + 80, BodyHitpos.y + 120, GetColor(255, 0, 0), false);
}

/// <summary>
/// �X�V����
/// </summary>
void PlayerBase::Update()
{
    MV1SetPosition(modelHandle, pos);
}

PlayerBase::~PlayerBase()
{
    MV1DeleteModel(modelHandle);
}