#include "BackOject.h"

BackOject::BackOject(const char* modelHandle)
    :pos(VGet(0,0,0))
{
    ModelHandle = MV1LoadModel(modelHandle);
    if (ModelHandle < 0)
    {
        printfDx("�f�[�^�ǂݍ��݂Ɏ��s. sourceId:%d", ModelHandle);
    }
}

BackOject::~BackOject()
{

}