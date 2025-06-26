#pragma once
#include"DxLib.h"

class Time
{
public:
    Time();
    virtual ~Time();
    void Count();               //カウント処理
    void Draw();                //描画
    void Init();                //初期化
    bool lightManager();        //光源管理
    bool bombManager(bool flg);


    int ReturnTime() { return Countdown; };     //カウントの時間
    int ReturnStaet() { return StartCount; };   //スタートまでの時間

private:
    const int StartTime = 3;        //ゲーム開始前
    const int CountTime = 130;       //ゲーム時間
    int Countdown;                  //カウントダウン
    int NowTime;                    //現在時間
    int time;                       //１フレーム前の時間
    int StartCount;                 //スタートまでの時間

    bool Switchflg;                 //光源フラグ
    int morningCount;               //昼のカウント
    int nightCount;                 //夜のカウント
    int SwitchSum;                  //合計値

    bool bombflg;
    int bombCount;
    int bombbeetween;

    int startimg;
};

