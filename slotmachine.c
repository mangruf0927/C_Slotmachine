#include "slotmachine.h"


void StartingScreen()
{
    CursorView(0);
    while (1)
    {
        border();

        gotoxy((MapWidth / 2) - 7, 33);
        printf("<Press Any Key to Start>");
        gotoxy((MapWidth / 2) - 7, 34);
        printf("<Press Any Key to Start>");
        gotoxy((MapWidth / 2) - 7, 35);
        printf("<Press Any Key to Start>");

        for (int i = 10; i < 15; i++)
        {
            SetColor(i);
            gotoxy((MapWidth / 2) - 32, 7);
            printf("■■      ■■      ■■■■■      ■  ■■■■        ■■■■■        ■■■■■■      ■          ■      ■■■■■■");
            gotoxy((MapWidth / 2) - 32, 8);
            printf("■■■  ■■■              ■■    ■■        ■    ■          ■      ■          ■    ■          ■    ■");
            gotoxy((MapWidth / 2) - 32, 9);
            printf("■  ■■■  ■                ■    ■          ■    ■          ■      ■          ■    ■          ■    ■");
            gotoxy((MapWidth / 2) - 32, 10);
            printf("■    ■    ■      ■■■■■■    ■          ■    ■        ■■      ■        ■      ■          ■    ■■■■■■■");
            gotoxy((MapWidth / 2) - 32, 11);
            printf("■          ■    ■          ■    ■          ■      ■■■■  ■      ■■■■■        ■          ■    ■");
            gotoxy((MapWidth / 2) - 32, 12);
            printf("■          ■    ■          ■    ■          ■                ■      ■      ■        ■          ■    ■");
            gotoxy((MapWidth / 2) - 32, 13);
            printf("■          ■    ■          ■    ■          ■    ■        ■■      ■        ■        ■      ■      ■");
            gotoxy((MapWidth / 2) - 32, 14);
            printf("■          ■      ■■■■■      ■          ■    ■■■■■■        ■          ■        ■■■        ■");
            gotoxy((MapWidth / 2) - 19, 17);
            printf("■                  ■■■■■      ■  ■■■■                  ■");
            gotoxy((MapWidth / 2) - 19, 18);
            printf("■                          ■■    ■■        ■                ■");
            gotoxy((MapWidth / 2) - 19, 19);
            printf("■                            ■    ■          ■                ■");
            gotoxy((MapWidth / 2) - 19, 20);
            printf("■                  ■■■■■■    ■          ■      ■■■■■■");
            gotoxy((MapWidth / 2) - 19, 21);
            printf("■                ■          ■    ■          ■    ■          ■");
            gotoxy((MapWidth / 2) - 19, 22);
            printf("■                ■          ■    ■          ■    ■          ■");
            gotoxy((MapWidth / 2) - 19, 23);
            printf("■                ■          ■    ■          ■    ■        ■■");
            gotoxy((MapWidth / 2) - 19, 24);
            printf("■■■■■■■      ■■■■■      ■          ■      ■■■■  ■");
            Sleep(500);
        }

        SetColor(7);

        if (_kbhit())
        {
            getchar();
            break;
        }

        Sleep(300);
    }

}

void border()
{
    int i, j;
    for (i = 0; i < MapWidth - 1; i += 2)
    {
        gotoxy(i, 0);
        printf("■");
        gotoxy(i, MapHeight - 2);
        printf("■");
    }
    for (i = 1; i < MapWidth - 1; i += 2)
    {
        gotoxy(i, 0);
        printf("□");
        gotoxy(i, MapHeight - 2);
        printf("□");
    }
    for (j = 1; j < MapHeight - 1; j += 2)
    {
        gotoxy(0, j);
        printf("□");
        gotoxy(MapWidth - 2, j);
        printf("□");
    }
    for (j = 2; j < MapHeight - 1; j += 2)
    {
        gotoxy(0, j);
        printf("■");
        gotoxy(MapWidth - 2, j);
        printf("■");
    }
}


void GamePlayBox()
{

    border();
    for (int i = 0; i < 15; i++)
    {
        gotoxy((MapWidth / 2) - 28 + i, 8);
        printf("▦");
        gotoxy((MapWidth / 2) - 8 + i, 8);
        printf("▦");
        gotoxy((MapWidth / 2) + 13 + i, 8);
        printf("▦");
        gotoxy((MapWidth / 2) - 28 + i, 24);
        printf("▦");
        gotoxy((MapWidth / 2) - 8 + i, 24);
        printf("▦");
        gotoxy((MapWidth / 2) + 13 + i, 24);
        printf("▦");
    }
    for (int j = 8; j < 25; j++)
    {
        gotoxy((MapWidth / 2) - 28, j);
        printf("▦");


        gotoxy((MapWidth / 2) - 13, j);
        printf("▦");
        gotoxy((MapWidth / 2) - 8, j);
        printf("▦");
        gotoxy((MapWidth / 2) + 7, j);
        printf("▦");
        gotoxy((MapWidth / 2) + 13, j);
        printf("▦");
        gotoxy((MapWidth / 2) + 28, j);
        printf("▦");
    }
    for (int i = 0; i < MapWidth - 1; i += 2)
    {
        gotoxy(i, 32);
        printf("■");
    }
    for (int i = 1; i < MapWidth - 1; i += 2)
    {
        gotoxy(i, 32);
        printf("□");
    }
}

int Betting(int* betting, int* money)
{
    while (1)
    {
        system("cls");
        border();

        SetColor(6);
        gotoxy((MapWidth / 2) - 10, 16);
        printf("☆★ 현재 소지 금액 : %d원 ☆★", *money);

        SetColor(15);
        gotoxy((MapWidth / 2) - 9, 18);
        printf("얼마 베팅하시겠습니까?  :");

        gotoxy((MapWidth / 2) + 4, 18);
        scanf("%d", betting);

        if (*betting > *money)
        {
            gotoxy((MapWidth / 2) - 5, 23);
            printf("돈이 부족합니다.");
            _getch();
            continue;
        }
        else if (*betting <= 0)
        {
            gotoxy((MapWidth / 2) - 8, 23);
            printf("1원부터 베팅 가능합니다");
            _getch();
            continue;
        }
        else
        {
            *money -= *betting;
            gotoxy((MapWidth / 2) - 5, 23);
            printf("%d원 베팅하였습니다.", *betting);
            gotoxy((MapWidth / 2) - 10, 25);
            printf("엔터키를 누르면 슬롯머신이 작동합니다 !");
            _getch();
            break;
        }
        return betting;
    }
}


void slotMachine(int* betting, int* money)
{
    while (1)
    {
        system("cls");
        GamePlayBox();
        SetColor(8);

        DrawDigitNum(0, 0);
        DrawDigitNum(1, 0);
        DrawDigitNum(2, 0);


        Sleep(700);


        int slot[4], i;
        srand(time(NULL));
        for (i = 0; i < 3; i++)
        {
            Sleep(900);
            SetColor(15);
            int random = rand() % 10;
            slot[i] = random;
            DrawDigitNum(i, slot[i]);
        }

        Sleep(900);

        if (slot[0] == slot[1] && slot[1] == slot[2])
        {
            gotoxy((MapWidth / 2) - 4, 35);
            printf("축하합니다 !!!!!");
            gotoxy((MapWidth / 2) - 7, 36);
            printf("베팅 금액의 5배를 획득하셨습니다.");
            *money += (*betting * 5);

            SetColor(12);
            DrawDigitNum(0, slot[0]);
            DrawDigitNum(1, slot[1]);
            DrawDigitNum(2, slot[2]);

        }
        else
        {
            gotoxy((MapWidth / 2) - 4, 35);
            printf("꽝입니다 ㅠ ㅠ");
        }

        SetColor(15);
        gotoxy((MapWidth / 2) - 5, 37);
        printf("남은 돈 : %d원\n", *money);
        _getch();

        return money;
        break;
    }

}


void DrawDigitNum(int k, int num)
{
    int loc[3] = { 17, 37, 58 };
    char* numDigits[10][7][6] =
    {
        {
            { "■","■","■","■","■","■" },
            { "■","  ","  ","  ","  ","■"},
            { "■","  ","  ","  ","  ","■"},
            { "■","  ","  ","  ","  ","■"},
            { "■","  ","  ","  ","  ","■"},
            { "■","  ","  ","  ","  ","■"},
            { "■","■","■","■","■","■"}
        },
        {
            { "  ","  ","  ","■","  ","  "},
            { "  ","  ","  ","■","  ","  "},
            { "  ","  ","  ","■","  ","  "},
            { "  ","  ","  ","■","  ","  "},
            { "  ","  ","  ","■","  ","  "},
            { "  ","  ","  ","■","  ","  "},
            { "  ","  ","  ","■","  ","  "}
        },
        {
            { "■","■","■","■","■","■" },
            { "  ","  ","  ","  ","  ","■" },
            { "  ","  ","  ","  ","  ","■" },
            { "■","■","■","■","■","■" },
            { "■","  ","  ","  ","  ","  " },
            { "■","  ","  ","  ","  ","  " },
            { "■","■","■","■","■","■" }
        },
        {
            { "■","■","■","■","■","■" },
            { "  ","  ","  ","  ","  ","■" },
            { "  ","  ","  ","  ","  ","■" },
            { "■","■","■","■","■","■" },
            { "  ","  ","  ","  ","  ","■" },
            { "  ","  ","  ","  ","  ","■" },
            { "■","■","■","■","■","■" }
        },
        {
            { "■","  ","  ","  ","  ","■"},
            { "■","  ","  ","  ","  ","■"},
            { "■","  ","  ","  ","  ","■"},
            { "■","■","■","■","■","■" },
            { "  ","  ","  ","  ","  ","■" },
            { "  ","  ","  ","  ","  ","■" },
            { "  ","  ","  ","  ","  ","■" },
        },
        {
            { "■","■","■","■","■","■" },
            { "■","  ","  ","  ","  ","  " },
            { "■","  ","  ","  ","  ","  " },
            { "■","■","■","■","■","■" },
            { "  ","  ","  ","  ","  ","■" },
            { "  ","  ","  ","  ","  ","■" },
            { "■","■","■","■","■","■" },
        },
        {
            { "■","  ","  ","  ","  ","  " },
            { "■","  ","  ","  ","  ","  " },
            { "■","  ","  ","  ","  ","  " },
            { "■","■","■","■","■","■" },
            { "■","  ","  ","  ","  ","■"},
            { "■","  ","  ","  ","  ","■"},
            { "■","■","■","■","■","■" },
        },
        {
            { "■","■","■","■","■","■" },
            { "■","  ","  ","  ","  ","■" },
            { "■","  ","  ","  ","  ","■" },
            { "  ","  ","  ","  ","  ","■" },
            { "  ","  ","  ","  ","  ","■" },
            { "  ","  ","  ","  ","  ","■" },
            { "  ","  ","  ","  ","  ","■" }
        },
        {
            { "■","■","■","■","■","■" },
            { "■","  ","  ","  ","  ","■" },
            { "■","  ","  ","  ","  ","■" },
            { "■","■","■","■","■","■" },
            { "■","  ","  ","  ","  ","■" },
            { "■","  ","  ","  ","  ","■" },
            { "■","■","■","■","■","■" },
        },
        {
            { "■","■","■","■","■","■" },
            { "■","  ","  ","  ","  ","■" },
            { "■","  ","  ","  ","  ","■" },
            { "■","■","■","■","■","■" },
            { "  ","  ","  ","  ","  ","■" },
            { "  ","  ","  ","  ","  ","■" },
            { "  ","  ","  ","  ","  ","■" }
        }
    };

    int y, x;
    for (y = 0; y < 7; y++)
    {
        for (x = 0; x < 6; x++)
        {
            gotoxy(loc[k] + x, 13 + y);
            printf(numDigits[num][y][x]);
        }
        printf("\n");
    }
}




