#include "Camera.h"
#define _USE_MATH_DEFINES
#include<math.h>
#define USE_LERP_CAMERA 1

Camera::Camera(const PlayerBase& player)
    :Lightpos(VGet(0,-0.5,1))
    ,flg(false)
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
    //DeleteLightHandle(light[1]);
    //SetLightRangeAttenHandle(light[1], Range, Atten0, Atten1, Atten2);
    //light[1] = CreatePointLightHandle(VGet(0, 0, -100),Range,Atten0,Atten1,Atten2);
    // ＤＣキーでライトの影響範囲を変更
    if (CheckHitKey(KEY_INPUT_D) == 1)
    {
        Range += 20.0f;
    }
    if (CheckHitKey(KEY_INPUT_C) == 1)
    {
        Range -= 20.0f;
    }

    // ＦＶキーでライトの距離減衰パラメータ０の値を変更
    if (CheckHitKey(KEY_INPUT_F) == 1)
    {
        Atten0 += 0.001f;
    }
    if (CheckHitKey(KEY_INPUT_V) == 1)
    {
        Atten0 -= 0.001f;
    }

    // ＧＢキーでライトの距離減衰パラメータ１の値を変更
    if (CheckHitKey(KEY_INPUT_G) == 1)
    {
        Atten1 += 0.00001f;
    }
    if (CheckHitKey(KEY_INPUT_B) == 1)
    {
        Atten1 -= 0.00001f;
    }

    // ＨＮキーでライトの距離減衰パラメータ２の値を変更
    if (CheckHitKey(KEY_INPUT_H) == 1)
    {
        Atten2 += 0.0000001f;
    }
    if (CheckHitKey(KEY_INPUT_N) == 1)
    {
        Atten2 -= 0.0000001f;
    }

    // 影響距離の値を補正
    if (Range < 0.0f) Range = 0.0f;

    // 距離減衰パラメータの値を補正
    if (Atten0 < 0.0f) Atten0 = 0.0f;
    if (Atten1 < 0.0f) Atten1 = 0.0f;
    if (Atten2 < 0.0f) Atten2 = 0.0f;

    // モデルの上空にポイントライトを設定
    //light[0] = CreateDirLightHandle(VGet(0, 0, 0));
    //light[0] = CreateDirLightHandle(VGet(0, -100, 0.15));
    //ChangeLightTypePoint(VGet(0, 100, 0), Range, Atten0, Atten1, Atten2);
    //ChangeLightTypePoint(VGet(150.0f, 500.0f, -100.0f), Range, Atten0, Atten1, Atten2);
    //ChangeLightTypePoint(VGet(0.0f, 500.0f, -100.0f),Range,Atten0,Atten1,Atten2);
}

Camera::~Camera()
{
    //処理なし
}