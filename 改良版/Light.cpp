#include "Light.h"
#include"Time.h"

Light::Light()
    :Lightpos(VGet(300,500,-30))
    ,Lightpos2(VGet(-300,500,-30))
    ,lightflg(true)
    ,Count(3)
{
    light[0] = CreateSpotLightHandle(Lightpos, VGet(0, -1, 0), 25.0f * DX_PI_F / 180.0f, 125.0f * DX_PI_F / 180.0f, Range, Atten0, Atten1, Atten2);
    light[1] = CreateSpotLightHandle(Lightpos2, VGet(0, -1, 0), 25.0f * DX_PI_F / 180.0f, 125.0f * DX_PI_F / 180.0f, Range, Atten0, Atten1, Atten2);
}

void Light::Init()
{
    SetLightEnableHandle(light[0], false);
    SetLightEnableHandle(light[1], false);
    SetLightEnable(true);
}

void Light::Update(bool flg)
{
    if (flg)
    {
        SetLightEnableHandle(light[0], false);
        SetLightEnableHandle(light[1], false);
    }
    else
    {
        SetLightEnableHandle(light[0], true);
        SetLightEnableHandle(light[1], true);
    }
    SetLightEnable(flg);
}

Light::~Light()
{

}