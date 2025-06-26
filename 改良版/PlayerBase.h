#pragma once
#include"DxLib.h"

class PlayerBase
{
public:
    PlayerBase(const char *ModelHandle);
    virtual~PlayerBase();

    void Init();//初期化

    virtual void Draw(bool flg,bool drawflg);    //描画
    virtual void Update();          //更新処理
    virtual void IsMove();          //移動処理
    void ResultAnim();

    //再生するアニメーション番号
    int ReturnAnim() { return AnimPlaybackIndex; };

    //モデルハンドル
    int GetModelHandle() { return modelHandle; }

    // ポジションのgetter/setter.
    const VECTOR& GetPos() const { return pos; }
    void SetPos(const VECTOR set) { pos = set; }

    const VECTOR& ReturnHitpos() { return Hitpos; };

    bool returnflg() { return graphflg; }

protected:
    int modelHandle;        //モデルハンドル
    VECTOR pos;             //モデルのポジション
    VECTOR dir;             //移動距離
    VECTOR Hitpos;          //アイテムの当たり判定

    bool pushLeft;          //左を押したかのフラグ
    bool pushRight;         //右を押したかのフラグ

    bool pushDash;          //ダッシュフラグ
    int dashframe;          //ダッシュのフレーム
    VECTOR gauge;           //ゲージの位置

    float JumpPow;          //ジャンプの高さ
    float Gravity;          //重力

    float PlayerSpeed;      //プレイヤーの移動スピード
    const float HitSpeed = 1.9;//当たり判定のスピード調整

    VECTOR angle;           //角度

    int AnimPlaybackIndex;  //再生する番号

    bool graphflg;
};

