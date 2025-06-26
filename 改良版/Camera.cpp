#include "Camera.h"
#define _USE_MATH_DEFINES
#include<math.h>
#define USE_LERP_CAMERA 1

Camera::Camera(const PlayerBase& player)
    :flg(false)
    ,lightflg(true)
{
    //���s0.1�`1000.0�܂ł��J�����̕`��͈͂Ƃ���
    SetCameraNearFar(0.1f, 1000.0f);
    
    // z����ŁA�v���C���[�����苗�����ꂽ��ԂŃv���C���[����Ɍ�������悤�ʒu����
    pos = VGet(0, player.GetPos().y + 100, player.GetPos().z - 500.0f);

    //�J�����̈ʒu
    SetCameraPositionAndTarget_UpVecY(pos,VGet(0,200,0));

    //ChangeLightTypeDir(Lightpos);

    //SetLightEnable(false);
}

void Camera::Update()
{
    
}

Camera::~Camera()
{
    //�����Ȃ�
}