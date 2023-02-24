/**
 * File: main.c
 * Author: aleks bratsun 222821IACB
 * Created: 07.02.2023
 * Last edit: 
 * Kirjeldus: 1 kodune ylesanne
 */
 
/* INCLUDID */
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "head.h"
#include "funkt.c"

#include "head.h"

int main() {
    Person persons[100];
    int n;
    char hobby[MAX_HOBBY_LEN];
    Person fans[100];
    int m;

    getPersons(persons, &n);
    printf("Sisesta hobi: ");
    scanf("%s", hobby);
    getHobbies(persons, n, hobby, fans, &m);
    writeFans(fans, m);
    
    return 0;
    
}
