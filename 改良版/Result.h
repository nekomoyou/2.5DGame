#pragma once
#include"DxLib.h"

class Result
{
public:
    Result();
    ~Result();

    void Init();
    void LoadRanking(const char* filename);                             // ランキングデータをファイルから読み込む関数
    void SaveRanking(const char* filename);                             // ランキングデータをファイルに保存する関数
    void DisplayRanking(int imgposx, int imgposy, int pulsimgx, int pulsimgy, int x, int y, int fontsize);// ランキングを画面に表示する関数
    void UpdateRanking(int score);                                      // 新しいスコアが出たときにランキングを更新する関数
    void SortRanking();                                                 // ランキングのソート
    void StringDraw();                                                  //リザルトの文章表記
    bool ReturnFlg() { return RankingInFlg; }

private:
    int scores[6];              //ランキングスコア
    int size;                   //ランキングの数
    int myScore;                //今回のゲームのスコア
    int img;                    //ランキングの看板
    int congraImg;              //ランキング内の時の画像
    int regretImg;              //ランキング外の時の画像
    bool RankingInFlg;          //ランキングに入ったかどうかのフラグ
    float angle;                //角度
    float rate;                 //拡大率
};

