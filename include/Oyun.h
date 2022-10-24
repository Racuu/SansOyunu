#ifndef OYUN_H
#define OYUN_H 1
#include "../include/Kisi.h"


typedef struct Game{
	float totalMoney;
	int numbers[1000];
	int numberCount;
}Game;

Game PlayGame(Game game,Person *persons,int personCount);
void gotoxy(int x,int y);
Game Print();
#endif
