#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 30
#define MAX_HOBBIES 10
#define MAX_HOBBY_LENGTH 30

struct record {
  char name[MAX_NAME_LENGTH];
  int h;
  char hobbies[MAX_HOBBIES][MAX_HOBBY_LENGTH];
};

int read_records_from_file(char *filename, struct record records[], int max_records) {
  FILE *fp;
  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening file %s\n", filename);
    return 0;
  }

  int i, j;
  for (i = 0; i < max_records; i++) {
    if (fscanf(fp, "%s %d", records[i].name, &records[i].h) == EOF) {
      break;
    }
    for (j = 0; j < records[i].h; j++) {
      fscanf(fp, "%s", records[i].hobbies[j]);
    }
  }

  fclose(fp);
  return i;
}

void print_record(struct record r) {
  int i;
  printf("%s %d\n", r.name, r.h);
  for (i = 0; i < r.h; i++) {
    printf("%s\n", r.hobbies[i]);
  }
}

void find_and_print_records_by_hobby(char *hobby, struct record records[], int num_records) {
  int i, j;
  for (i = 0; i < num_records; i++) {
    for (j = 0; j < records[i].h; j++) {
      if (strcmp(hobby, records[i].hobbies[j]) == 0) {
        printf("%s\n", records[i].name);
        break;
      }
    }
  }
}

int main() {
  char filename[100];
  printf("Enter the name of the file: ");
  scanf("%s", filename);

  struct record records[100];
  int num_records = read_records_from_file(filename, records, 100);
  if (num_records == 0) {
    return 1;
  }

  char hobby[MAX_HOBBY_LENGTH];
  printf("Enter the name of a hobby: ");
  scanf("%s", hobby);

  find_and_print_records_by_hobby(hobby, records, num_records);

  return 0;
}
