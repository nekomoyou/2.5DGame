#include "BackObject.h"

BackObject::BackObject()
    :pos(VGet(0,0,0))
{  
    ModelHandle[0] = MV1LoadModel("3Dモデル/2Story_Double_Mat.mv1");
    ModelHandle[1] = MV1LoadModel("3Dモデル/3Story_Balcony_Mat.mv1");
    ModelHandle[2] = MV1LoadModel("3Dモデル/1Story_Sign_Mat.mv1");
    ModelHandle[3] = MV1LoadModel("3Dモデル/4Story_Center_Mat.mv1");
    ModelHandle[4] = MV1LoadModel("3Dモデル/2Story_Stairs_Mat.mv1");
    ModelHandle[5] = MV1LoadModel("3Dモデル/3Story_Small_Mat.mv1");
    ModelHandle[6] = MV1LoadModel("3Dモデル/4Story_Mat.mv1");

    for (int i = 0; i < ObjNum; i++)
    {
        if (ModelHandle[i] < 0)
        {
            printfDx("データ読み込みに失敗. sourceId:%d", ModelHandle[i]);
        }
    }
}

/// <summary>
/// オブジェクトの設置
/// </summary>
void BackObject::SetObj()
{
    for (int i = 0; i < ObjNum; i++)
    {
        MV1SetPosition(ModelHandle[i], VGet(-550 + band * i, 0, 150));
    }
}

/// <summary>
/// 描画
/// </summary>
void BackObject::Draw()
{
    for (int i = 0; i < ObjNum; i++)
    {
        MV1DrawModel(ModelHandle[i]);
    }
}

BackObject::~BackObject()
{
    for (int i = 0; i < ObjNum; i++)
    {
        MV1DeleteModel(ModelHandle[i]);
    }
    DeleteGraph(Sky);
    DeleteGraph(Night);
}