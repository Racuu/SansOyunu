#ifndef KISI_H
#define KISI_H 


typedef struct Person{ 
	char Name[100];
	float Money;
	float Rate;
	int Number;
}Person;

int CountPeople();
int Gamer(Person *persons,int personCount);
#endif
