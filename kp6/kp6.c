#include <stdio.h>
#include <stdlib.h>

typedef struct enrolee_data {
    char surname[25];
    char initials[3];
    char male[2];
    int school_number;
    char medal;
    int math;
    int russ;
    int phys;
    char essay;
} enrolee_data;

int main(int argc, char* argv[]) {
    
    char name[20];
    printf("Enter name of file\n");
    scanf("%s", name);
    char *filename;
    filename = name;

    const int count = 25;
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("The file not exists\n");
        exit(1);
    }

    enrolee_data *students = (enrolee_data*)calloc(count, sizeof(enrolee_data));
    int i = 0;
    while (!feof(file)) {
        enrolee_data s;
        fscanf(file, "%s %2s %s %d %c %d %d %d %c", s.surname, s.initials, s.male, &s.school_number,
               &s.medal, &s.math, &s.russ, &s.phys, &s.essay);
        students[i++] = s;
    }

    int p;
    int m = 0;
    printf("Enter average score\n>>> ");
    scanf("%d", &p);

    printf("--------------------------------------------------------\n");
    printf("|Surname     |In|Male|School|Medal|Math|Russ|Phys|Essay|\n");
    printf("--------------------------------------------------------\n");

    for (int j = 0; j < count; ++j) {
        enrolee_data s = students[j];
        if (s.math + s.phys + s.russ < p && s.medal == 43) {
            printf("|%12s|%2s|%4s|%6d|%5c|%4d|%4d|%4d|%5c|\n", s.surname, s.initials, s.male,
                   s.school_number, s.medal, s.math, s.russ, s.phys, s.essay);
            m++;
        }
    }
    if (m == 0) {
        printf("|                      NOT FOUND                       |\n");
    }

    printf("--------------------------------------------------------");
    
    
    fclose(file);
}