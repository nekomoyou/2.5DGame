#include "Camera.h"
#define _USE_MATH_DEFINES
#include<math.h>
#define USE_LERP_CAMERA 1

Camera::Camera(const PlayerBase& player)
    :flg(false)
    ,lightflg(true)
{
    //奥行0.1～1000.0までをカメラの描画範囲とする
    SetCameraNearFar(0.1f, 1000.0f);
    
    // z軸上で、プレイヤーから一定距離離れた状態でプレイヤーを常に見続けるよう位置調整
    pos = VGet(0, player.GetPos().y + 100, player.GetPos().z - 500.0f);

    //カメラの位置
    SetCameraPositionAndTarget_UpVecY(pos,VGet(0,200,0));

    //ChangeLightTypeDir(Lightpos);

    //SetLightEnable(false);
}

void Camera::Update()
{
    
}

Camera::~Camera()
{
    //処理なし
}