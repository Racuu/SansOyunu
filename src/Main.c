#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/Oyun.h"
#include "../include/Dosya.h"
#include "../include/Kisi.h"

int main() { 
	system("cls");
	Game game = FindNumbers(); //1000
	Person* persons = FindPersons(); 
	int personCount = CountPeople(); //1000
	game = PlayGame(game,persons,personCount);
}

