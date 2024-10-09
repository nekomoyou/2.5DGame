#include "Camera.h"
#define _USE_MATH_DEFINES
#include<math.h>
#define USE_LERP_CAMERA 1

Camera::Camera()
{
    //奥行0.1～1000.0までをカメラの描画範囲とする
    SetCameraNearFar(0.1f, 1000.0f);
    
    //カメラの位置
    SetCameraPositionAndTarget_UpVecY(VGet(0.0f, 10.0f, -20.0f), VGet(0.0f, 10.0f, -20.0f));
}

Camera::~Camera()
{
    //処理なし
}