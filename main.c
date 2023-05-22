#include "slotmachine.h"


int main()
{
    int betting = 0;
    int money = 10000;
    char *answer = 'y';

    SetConsole();
    StartingScreen();

    while(money > 0)
    {
        Betting(&betting, &money);
        slotMachine(&betting, &money);
        
        gotoxy((MapWidth / 2) - 8, 39);
        printf("계속 하시겠습니까 ? ( y / n )");
        
        gotoxy((MapWidth / 2) + 7, 39);
        scanf("%s", &answer);

        if (answer == 'y')
        {
            if (money <= 0)
            {
                gotoxy((MapWidth / 2) - 8, 41);
                printf("돈이 없습니다. 게임을 종료합니다.");
                _getch();
                break;
            }
            else
            {
            gotoxy((MapWidth / 2) - 6, 41);
            printf("게임을 계속 진행합니다.");
            _getch();
            continue;
            }
        }

        if (answer == 'n')
        {
            gotoxy((MapWidth / 2) - 5, 41);
            printf("게임을 종료합니다.");
            _getch();
            break;
        }
        system("cls");
            
    }

    return 0;
}
