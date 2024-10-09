#pragma once

class DelteTime
{
public:
    DelteTime();
    ~DelteTime();

    bool Update();
    void Draw();
    void Wait();

    int Count;
    float mFPS;
    int StartTime;

    static const int N = 60;
    static const int FPS = 60;
};

