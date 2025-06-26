#pragma once
#include"DxLib.h"

class Text
{
public:
    Text();
    ~Text();

private:
    const static int Xnum = 12;
    const static int Ynum = 6;
    const static int ImgXSize = 15;
    const static int ImgYSize = 25;

    int textImg[Xnum * Ynum];
};

