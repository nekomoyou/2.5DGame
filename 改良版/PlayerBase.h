#pragma once
#include"DxLib.h"

class PlayerBase
{
public:
    PlayerBase(const char *ModelHandle);
    virtual~PlayerBase();
    virtual void Draw();
    virtual void Update();
    virtual void IsMove();

    void animtion();
    void a();

    int GetModelHandle() { return modelHandle; }

    // ポジションのgetter/setter.
    const VECTOR& GetPos() const { return pos; }
    void SetPos(const VECTOR set) { pos = set; }

    VECTOR Hitpos;//当たり判定

    typedef enum Anim
    {
        Stop,
        Walk
    };

protected:
    int modelHandle;//モデルハンドル
    VECTOR pos;//モデルのポジション
    bool pushLeft;//左を押したかのフラグ
    bool pushRight;//右を押したかのフラグ

    const float PlayerSpeed = 2;//プレイヤーの移動スピード

    VECTOR angle;

    //アニメーションの関数
    int AnimTotalTime;//トータル時間
    int AnimPlayTime;//再生時間
    int AnimStopIndex;//立ち止まる
    int AnimWalkIndex;//歩く
    int AnimPlaybackIndex;//再生する番号
    int AnimIndex;
};

