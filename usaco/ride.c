/*
ID: jhpooor1
LANG: C
TASK: test
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ride(char *str) {
    int l, sum, i;
    sum = 1;
    l = strlen(str);
    for (i = 0; i < l; i++) {
        sum *= str[i] - 'A' + 1;
    }
    return sum % 47;
}

main() {
    FILE *fin = fopen("ride.in", "r");
    FILE *fout = fopen("ride.out", "w");

    char str1[10], str2[10];
    fscanf(fin, "%s%s", str1, str2);
    if (ride(str1) == ride(str2)) {
        fprintf(fout, "GO\n");
    } else {
        fprintf(fout, "STAY\n");
    }

    return 0;
}
