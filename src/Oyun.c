#include "../include/Oyun.h"
#include <stdio.h>
#include <windows.h>

void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
} // Hazır koordinat fonksiyonu.

Game PlayGame(Game game, Person *persons, int personCount)
{
	int i = 0, round = 1;
	personCount = CountPeople();
	int st = 1;
	game.totalMoney = 0.0f;
	while (st == 1)
	{
		for (int j = 0; j <= personCount; j++)
		{
			if (persons[j].Money >= 1000)
			{
				float bet = persons[j].Money * persons[j].Rate;
				game.totalMoney = game.totalMoney + bet;
				persons[j].Money =persons[j].Money - bet;
				if (persons[j].Number == game.numbers[i])
				{
					float win = bet * 10;
					persons[j].Money = persons[j].Money +win;
					game.totalMoney = game.totalMoney -win;
				}
			}
		}
		
		gotoxy(10, 2);
		printf("##\tSansli Sayi: %-2d                         ##\n", game.numbers[i]);
		gotoxy(10, 5);
		printf("##\tTur: %-6d                             ##\n", i + 1);
		gotoxy(10, 6);
		printf("##\tMasa Bakiye: %-20.2f TL\t##\n", game.totalMoney);
		gotoxy(10, 9);
		printf("##\tEN ZENGIN KISI\t\t\t\t##\n");
		st = Gamer(persons, personCount);

		if (st == -1)
		{
			system("cls");
			gotoxy(10, 2);
			printf("##\tSansli Sayi: %-2d                         ##\n", game.numbers[i]);
			gotoxy(10, 5);
			printf("##\tTur: %-6d                             ##\n", round);
			gotoxy(10, 6);
			printf("##\tMasa Bakiye: %-20.2f TL\t##\n", game.totalMoney);
			gotoxy(10, 9);
			printf("##\tOYUN BITTI\t\t\t\t##\n");
			gotoxy(10, 10);
			printf("##                                            ##\n");
			gotoxy(10, 11);
			printf("##                                            ##\n");
			Print();
		}
		Print();
		i++;
		if (i > personCount)
		{
			i = 0;
		}
		usleep(10 * 1000);
		round++;
	}
	return game;

	
}
Game Print()
{
	gotoxy(10, 1);
	printf("################################################\n");
	gotoxy(10, 3);
	printf("################################################\n");
	gotoxy(10, 4);
	printf("################################################\n");
	gotoxy(10, 7);
	printf("##                                            ##\n");
	gotoxy(10, 8);
	printf("##--------------------------------------------##\n");
	gotoxy(10, 12);
	printf("##                                            ##\n");
	gotoxy(10, 13);
	printf("################################################\n");
}
