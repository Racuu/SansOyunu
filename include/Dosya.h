#ifndef DOSYA_H
#define DOSYA_H 1
#include "../include/Oyun.h"
#include "../include/Kisi.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct File{
	FILE* file;
	int personCount;
	int lineCount;
	int counter;
}File; 

Person *persons;
Game FindNumbers();
Person* FindPersons();
#endif
