/*
ID: jhpooor1
LANG: C
TASK: gift1
 */
#include <stdio.h>
#include <string.h>

#define MAXLEN 15
#define MAXP 10

typedef struct Person Person;
struct Person {
    char name[MAXLEN];
    int total;
};

Person people[MAXP];
int num;

void addPerson(char *name) {
    strcpy(people[num].name, name);
    num++;
}

Person *find(char *name) {
    int i;
    for (i=0; i<num; i++) {
        if (strcmp(name, people[i].name) == 0) {
            return &people[i];
        }
    }
    return NULL;
}

int main() {
    FILE *fin = fopen("gift1.in", "r");
    FILE *fout = fopen("gift1.out", "w");

    char name[MAXLEN];
    int i, j, np, amt, ng;
    Person *giver, *receiver;

    fscanf(fin, "%d", &np);
    for (i=0; i<np; i++) {
        fscanf(fin, "%s", name);
        addPerson(name);
    }

    for (i=0; i<np; i++) {
        fscanf(fin, "%s%d%d", name, &amt, &ng);
        giver = find(name);
        for (j=0; j<ng; j++) {
            fscanf(fin, "%s", name);
            receiver = find(name);
            giver->total -= amt/ng;
            receiver -> total+=amt/ng;
        }
    }

    for (i=0; i<np; i++) {
        fprintf(fout, "%s %d\n", people[i].name, people[i].total);
    }

    return 0;
}
