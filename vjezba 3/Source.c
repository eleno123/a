#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 50

typedef struct _osoba osoba;
typedef osoba* pozicija;
struct _osoba {
	char ime[M];
	char prezime[M];
	int god;
	osoba* next;
};

osoba* AddAtBeggining(osoba* people);
void Ispis(osoba* people);
osoba* AddAtEnd(osoba* people);
void SearchBySurname(osoba* people);
void Delete(osoba* people);
osoba* AddBefore (osoba* people);
osoba* AddAfter(osoba* people);
void WriteFile(osoba* people);
osoba* ReadFile();

int main() {

	pozicija head = NULL;
	head = (pozicija)malloc(sizeof(osoba));
	head->next = NULL;
	

	char znak = NULL;
	printf("\nUnesi A za dodat na pocetak liste\n"
		"unesi B za ispis liste\n"
		"unesi C za dodat na kraj\n"
		"unesi D za trazizt po prezimenu\n"
		"unesi E za brisanje\n"
		"unesi F za dodat prije\n"
		"unesi G za dodat iza\n"
		"unesi W ta file\n"
		"unesi R ta citat file\n"
		"unesi H za kraj\n");

	scanf("%c", &znak);

	while (znak != 'H' && znak != 'h')
	{
		switch (znak) {
			
		case 'A':
		case'a':
			head->next = AddAtBeggining(head->next);
			break;
		case 'B':
		case 'b':
			Ispis(head->next);
			break;
		case 'C':
		case 'c':
			head->next=AddAtEnd(head->next);
			break;
		case 'D':
		case 'd':
			SearchBySurname(head->next);
			break;
		case 'E':
		case 'e':
			Delete(head);
			break;
		case 'F':
		case 'f':
			head=AddBefore(head);
			break;
		case 'G':
		case 'g':
			head->next=AddAfter(head->next);
			break;

		case 'W':
		case 'w':
			WriteFile(head->next);
			break;
			
		case 'R':
		case 'r':
			head->next= ReadFile();
			break;

		default:
			break;
		}

		printf("\nUnesi A za dodat na pocetak liste\n"
			"unesi B za ispis liste\n"
			"unesi C za dodat na kraj\n"
			"unesi D za trazizt po prezimenu\n"
			"unesi E za brisanje\n"
			"unesi F za dodat prije\n"
			"unesi G za dodat iza\n"
			"unesi H za kraj\n");

		scanf(" %c", &znak);
	}

	return 0;
}

osoba* AddAtBeggining(osoba* head)
{
	osoba* new = (osoba*)malloc(sizeof(osoba));
	
	printf("unesi ime osobe\n");
	scanf("%s", new->ime);
	printf("unesi prezime osobe\n");
	scanf("%s", new->prezime);
	printf("unesi godiste osobe\n");
	scanf("%d", &new->god);
	new->next = NULL;

	if (head == NULL) return new;
	else {
		 new->next=head;
			return new;
	}
}

void Ispis(osoba* head) {
	if (head == NULL) printf("greska");

	while (head != NULL)
	{
		printf("%s %s %d\n", head->ime, head->prezime, head->god);
		head = head->next;

	}
}

osoba* AddAtEnd(osoba* people)
{
	osoba* current = people;
	osoba* new=(osoba*)malloc(sizeof(osoba));
	
	printf("unesi ime osobe\n");
	scanf("%s", new->ime);
	printf("unesi prezime osobe\n");
	scanf("%s", new->prezime);
	printf("unesi godiste osobe\n");
	scanf("%d", &new->god);
	new->next = NULL;

	if (people == NULL) return new;
	
	while (current->next != NULL)
		current = current->next;

	current->next = new;
	return people;
}

void SearchBySurname(osoba* people)
{
	char prez[M] = {0};
	printf("\nunesi prezime koje trazis");
	scanf("%s", prez);

	if (people == NULL) printf("greska");

	while (people != NULL) {
		if (!strcmp(prez, people->prezime))
		{
			printf("%s %s %d\n", people->ime, people->prezime, people->god);
		}
		people = people->next;
	}
}

void Delete(osoba* previous)
{
	osoba* current;
	current = previous->next;

	char prez[M] = { 0 };
	printf("\nunesi prezime koje brises");
	scanf("%s", prez);

	while (current != NULL) {
		if (!strcmp(prez, current->prezime))
		{
			previous->next= current->next;
				free(current);
				return;
		}
		current = current->next;
		previous = previous->next;
	}
}

osoba* AddBefore(osoba* current)
{
	

	osoba* people = current;
	osoba* previous=current;
	current = current->next;
	osoba* new = (osoba*)malloc(sizeof(osoba));
	
	char prez[M] = { 0 };
	printf("unesi prez isprid koeg zelis novi el");
	scanf("%s", prez);

	printf("unesi ime osobe\n");
	scanf("%s", new->ime);
	printf("unesi prezime osobe\n");
	scanf("%s", new->prezime);
	printf("unesi godiste osobe\n");
	scanf("%d", &new->god);
	new->next = NULL;

	

	while (current != NULL) {
		if (!strcmp(prez, current->prezime))
		{
			new->next = current;
			previous->next = new;
			return people;
		}
		current = current->next;
		previous = previous->next;
	}
	printf("ne postoji");
	return people;
}

osoba* AddAfter(osoba* people)
{
	char prez[M] = { 0 };
	printf("unesi prez iza koeg zelis novi el");
	scanf("%s", prez);
	osoba* current = people;

	osoba* new = (osoba*)malloc(sizeof(osoba));

	printf("unesi ime osobe\n");
	scanf("%s", new->ime);
	printf("unesi prezime osobe\n");
	scanf("%s", new->prezime);
	printf("unesi godiste osobe\n");
	scanf("%d", &new->god);
	new->next = NULL;

	if (people == NULL) printf("greska");

	while (current != NULL)
	{
		if (!strcmp(current->prezime, prez)) {
			new->next= current->next;
			current->next = new;
			return people;

		}

		current = current->next;
	}
	printf("ne postoji");
	return people;
}

void WriteFile(osoba* people) {

	FILE* fp;
	fp = fopen("ljudi.txt", "w");

	while (people != NULL) {

		fprintf(fp, "%s %s %d\n", people->ime, people->prezime, people->god);
		people = people->next;
	}
	fclose(fp);
}

osoba* ReadFile() {

	FILE* fp;
	int red=0,i;
	char buffer[1289]={0};
	osoba* current=NULL;
	osoba* begin = NULL;
	
	
	fp = fopen("TextFile1.txt", "r");
	
	while (fgets(buffer, sizeof(buffer), fp) != NULL)
	{
		red++;
	}
	rewind(fp);

	for (i = 0;i < red;i++) {
		osoba* new = (osoba*)malloc(sizeof(osoba));
		fprintf(fp, "%s %s %d", new->ime, new->prezime, new->god);
		if (i == 0) {
			current = new;
			begin = new;
			continue;
		}

		current->next = new;
		current = new;
	}
	current->next = NULL;
	fclose(fp);
	return begin;
}