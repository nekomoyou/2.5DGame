#include "Camera.h"
#define _USE_MATH_DEFINES
#include<math.h>
#define USE_LERP_CAMERA 1

Camera::Camera()
{
    //���s0.1�`1000.0�܂ł��J�����̕`��͈͂Ƃ���
    SetCameraNearFar(0.1f, 1000.0f);
    
    //�J�����̈ʒu
    SetCameraPositionAndTarget_UpVecY(VGet(0.0f, 10.0f, -20.0f), VGet(0.0f, 10.0f, -20.0f));
}

Camera::~Camera()
{
    //�����Ȃ�
}