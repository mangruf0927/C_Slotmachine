#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>

#define MapWidth 80
#define MapHeight 46

void StartingScreen(); // 시작화면
void border(); // 테두리
void GamePlayBox(); // 게임화면 박스
void slotMachine();
void DrawDigitNum(int i, int num);
int Betting();
void ending();
