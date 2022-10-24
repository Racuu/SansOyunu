#include "../include/Kisi.h"
#include "../include/Dosya.h"
int CountPeople()
{
	File file;
	file.file = fopen("./doc/Kisiler.txt", "r");
	file.counter = 0;
	char buf;
	while (!feof(file.file))
	{
		fscanf(file.file, "%c", &buf);
		if (buf == '\n')
		{
			file.counter++;
		}
	}
	fclose(file.file);
	return file.counter+1;
}

int Gamer(Person *persons, int personCount)
{
	int j = 0, i = 0;
	float money = 0;
	char name[100];
	Person richest = persons[0];
	for (i = 0; i < personCount; i++)
	{
			if (persons[i].Money > money)
			{
				richest = persons[i];
				money = persons[i].Money;
			}
	}
	strcpy(name,richest.Name);
	gotoxy(10, 10);
	printf("##\t\t%s\t\t##", name);
	gotoxy(10, 11);
	printf("##\t\tBAKIYESI: %-20.f\t##", money);
	if (money >= 1000)
	{
		return 1;
	}
	else{
		return -1;
	}
}