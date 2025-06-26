#include "Result.h"

Result::Result()
    :size(6),myScore(0)
{
    Init();
    img = LoadGraph("img/rankingbox.png");
    congraImg = LoadGraph("img/omedetou.png");
    regretImg = LoadGraph("img/zannnenn.png");
}

/// <summary>
/// ������
/// </summary>
void Result::Init()
{
    for (int i = 0; i < size; i++)
    {
        scores[i] = 0;
    }
    myScore = 0;
    RankingInFlg = false;
    angle = 0;
    rate = 0.2;
}

/// <summary>
/// �����L���O���[�h
/// </summary>
/// <param name="filename">�����L���Otxt</param>
void Result::LoadRanking(const char* filename)
{
    FILE* file;
    fopen_s(&file,filename, "r");
    if (file != NULL)
    {
        // �t�@�C�����烉���L���O�f�[�^��ǂݍ���
        fread(scores, sizeof(int), size, file);
        fclose(file);
    }
}

/// <summary>
/// �����L���O�̕ۑ�
/// </summary>
/// <param name="filename">�����L���Otxt</param>
void Result::SaveRanking(const char* filename)
{
    FILE* file;
    fopen_s(&file,filename, "w");
    if (file != NULL) 
    {
        // �����L���O�f�[�^���t�@�C���ɏ�������
        fwrite(scores, sizeof(int), size, file);
        fclose(file);
    }
}

/// <summary>
/// ���͕\�L
/// </summary>
void Result::StringDraw()
{
    static int f;
    int s = f % 60;
    f++;
    if (s <= 40)
    {
        DrawString(150, 800, "�ēx�v���C:ENTER", GetColor(245, 255, 250));
        DrawString(150, 900, "�^�C�g���֖߂�:SPACE", GetColor(245, 255, 250));
    }
    if (f >= 120)
    {
        f = 0;
    }
}

/// <summary>
/// �����L���O�̕\��
/// </summary>
/// <param name="imgposx">�摜�̍���X</param>
/// <param name="imgposy">�摜�̍���Y</param>
/// <param name="pulsimgx">�摜�̉E��X</param>
/// <param name="pulsimgy">�摜�̉E��Y</param>
/// <param name="x">�����L���O�X�R�A�̈ʒu</param>
/// <param name="y">�����L���O�X�R�A�̕\������</param>
/// <param name="fontsize">�t�H���g�T�C�Y</param>
void Result::DisplayRanking(int imgposx,int imgposy,int pulsimgx,int pulsimgy,int x,int y,int fontsize)
{
    //DrawGraph(0, 0, img, true);
    DrawExtendGraph(imgposx, imgposy, imgposx + pulsimgx, imgposy + pulsimgy, img, true);
    SetFontSize(fontsize);
    DrawString(x + 20, y - fontsize, "Ranking", GetColor(25, 25, 112));

    for (int i = 0; i < size - 1 ; i++) 
    {
        if (scores[i] == myScore)
        {
            static int f;
            int a = f % 60;
            f++;
            if (a <= 30)
            {
                DrawFormatString(x, y + i * fontsize, GetColor(255, 215, 0), "%d. %d", i + 1, myScore);
                //DrawTriangle()
            }
            if (f >= 120)
            {
                f = 0;
            }
            RankingInFlg = true;
        }
        else
        {
            DrawFormatString(x, y + i * fontsize, GetColor(25, 25, 112), "%d. %d", i + 1, scores[i]);
        }
    }
    static int s = 1;
    if (myScore >= 1)
    {
        DrawString(1200, 50, "Score", GetColor(255, 215, 0));
        DrawFormatString(1300, 150, GetColor(255, 215, 0), "%d", myScore);
        if (RankingInFlg)
        {
            angle += s;
            if (angle >= 20)
            {
                s *= -1;
            }
            if (angle <= -20)
            {
                s *= -1;
            }
            DrawRotaGraph(1400, 600, 0.8, angle * DX_PI_F / 180.0f, congraImg, true);
            //DrawExtendGraph(1000, 400, 1800, 700, congraImg, true);
        }
        else
        {
            if (angle <= 380)
            {
                rate += 0.025;
                angle += 5;
            }
            DrawRotaGraph(1450, 550, rate, angle * DX_PI_F / 180.0f, regretImg, true);
        }
    }
}

/// <summary>
/// �����L���O�̍X�V
/// </summary>
/// <param name="score">����Ƃ����X�R�A</param>
void Result::UpdateRanking(int score)
{
    if (score > 0)
    {
        myScore = score;
    }
    scores[size - 1] = score;
    SortRanking();
}

/// <summary>
/// �����L���O�\�[�g
/// </summary>
void Result::SortRanking()
{
    //int c = 0;
    for (int i = 0; i < size - 1; ++i) 
    {
        for (int j = 1; j < size - i ; ++j) 
        {
            if (scores[j] > scores[j - 1]) 
            {
                int temp = scores[j];
                scores[j] = scores[j - 1];
                scores[j - 1] = temp;
                //c++;
            }
        }
    }
}

Result::~Result()
{
    DeleteGraph(img);
    DeleteGraph(congraImg);
    DeleteGraph(regretImg);
}