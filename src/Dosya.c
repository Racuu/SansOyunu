#include "../include/Dosya.h" 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Game FindNumbers(){
	Game game;
	File file;
	int index = 0;
	file.file = fopen("./doc/Sayilar.txt","r");
	int sayac = 0;
	int* array = (int*) malloc(sizeof(int)*(sayac+1));
	int i=0;
	while(!feof(file.file)){
		fscanf(file.file,"%d\n",&game.numbers[i]);
		i++;
	} 
	game.numberCount = i;
	fclose(file.file);
	return game;
}

Person* FindPersons(){
	File file;
	file.personCount = CountPeople();
	persons = (Person*)malloc(sizeof(Person)*file.personCount);
	file.counter=0;
	file.file = fopen("./doc/Kisiler.txt","r");
	char buf[1000],temp[1000];
	char* value;
	const char ayrac[2] = "#";
	while(!feof(file.file)){
		fscanf(file.file,"%[^\n]\n",buf);
		strcpy(temp,buf);
		value = strtok(temp,ayrac);
		strcpy(persons[file.counter].Name,value);
		value = strtok(NULL,ayrac);
		persons[file.counter].Money = atof(value);
		value = strtok(NULL,ayrac);
		persons[file.counter].Rate = atof(value);
		value = strtok(NULL,ayrac);
		persons[file.counter].Number = atoi(value);
		file.counter++;
	}
	
	fclose(file.file);
	return persons;
}

