#include "head.h"

void getPersons(Person persons[], int *n) {
    FILE *fp;
    char fileName[100];

    printf("Enter input file name: ");
    scanf("%s", fileName);

    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("File does not exist\n");
        return;
    }

    *n = 0;
    while (fscanf(fp, "%s", persons[*n].name) == 1) {
        fscanf(fp, "%d", &persons[*n].H);
        for (int i = 0; i < persons[*n].H; i++) {
            fscanf(fp, "%s", persons[*n].hobbies[i]);
        }
        (*n)++;
    }
    fclose(fp);
}

void getHobbies(Person persons[], int n, char hobby[], Person fans[], int *m) {
    *m = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < persons[i].H; j++) {
            if (strcmp(persons[i].hobbies[j], hobby) == 0) {
                strcpy(fans[*m].name, persons[i].name);
                (*m)++;
                break;
            }
        }
    }
}

void writeFans(Person fans[], int m) {
    FILE *fp;
    char fileName[100];

    printf("Enter output file name: ");
    scanf("%s", fileName);

    fp = fopen(fileName, "w");
    if (fp == NULL) {
        printf("File could not be created\n");
        return;
    }

    for (int i = 0; i < m; i++) {
        fprintf(fp, "%s\n", fans[i].name);
    }
    fclose(fp);
}
