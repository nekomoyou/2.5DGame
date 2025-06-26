#pragma once

class GameManager;
class Result;
class Sound;
class SoundSE;

class SceneManager
{
public:
    SceneManager();
    ~SceneManager();

    void Draw();
    void Update();

private:
    GameManager* game;
    Result* result;
    Sound* sound;
    SoundSE* soundse;

    enum Scene
    {
        title,
        play,
        explanation,
        record
    };
    Scene scene;
    int img;
    bool bottonflg;
    bool bottonflg2;
};

