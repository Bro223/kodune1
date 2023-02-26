#ifndef FUNCTIONS_H
#define FUNCTIONS_H



/* INCLUDID */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>




#define MAX_NAME_LEN 20
#define MAX_HOBBIES_LEN 10
#define MAX_HOBBY_LEN 20

typedef struct {
char name[MAX_NAME_LEN];
int H;
char hobbies[MAX_HOBBIES_LEN][MAX_HOBBY_LEN];
} Person;

void getPersons(Person persons[], int *n);
void getHobbies(Person persons[], int n, char hobby[], Person fans[], int *m);
void writeFans(Person fans[], int m);

#endif
