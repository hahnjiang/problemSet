#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverseWords(char *s) {
    int st = 0, en = 0, i, j, l = strlen(s);
    char tmp;
    i = j = 0;
    while (i < l)
    {
        while (s[i] == ' ') {
            i++;
        }
        if (i >= l) break;
        while (s[i] != ' ' && s[i] != '\0') {
            s[j] = s[i];
            j++;
            i++;
        }
        s[j] = ' ';
        j++;
        i++;
    }
    if (j > 0) j--;
    s[j] = '\0';

    i=0;
    while (s[i] != '\0') {
        while (s[i] != '\0' && s[i] == ' ') i++;
        st = i;
        while (s[i] != '\0' && s[i] != ' ') i++;
        en = i-1;
        while (st<en) {
            tmp = s[st]; s[st] = s[en]; s[en] = tmp;
            st++; en--;
        }
    }
    st = 0; en = i-1;
    while (st<en) {
        tmp = s[st]; s[st] = s[en]; s[en] = tmp;
        st++; en--;
    }
}

int main() {
    char *s = "abcde defg asf";
    reverseWords("abcde defg dsef");
    printf("%s\n", s);
}

