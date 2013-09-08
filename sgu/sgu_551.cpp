#include <stdio.h>
#include <string.h>

int tm[2], nm[2];

int main() {
    int n, t1, t2;
    while (scanf("%d%d%d", &n, &t1, &t2) != EOF) {
        memset(tm, 0, sizeof(tm));
        memset(nm, 0, sizeof(nm));
        int t = 0;
        while (1) {
            if (t == tm[0] && t == tm[1]) {
                nm[0] += (t==0)?(0):(1);
                nm[1] += (t==0)?(0):(1);
                if (nm[0]+nm[1]>=n) {
                    break;
                }
                tm[0] += t1;
                tm[1] += t2;
            } else if (t == tm[0]) {
                nm[0] += (t==0)?(0):(1);
                if (nm[0]+nm[1]==n) {
                    nm[1]++;
                    break;
                }
                tm[0] += t1;
            } else if (t == tm[1]) {
                nm[1] += (t==0)?(0):(1);
                if (nm[0]+nm[1]==n) {
                    nm[0]++;
                    break;
                }
                tm[1] += t2;
            }
            t = (tm[0]<tm[1])?(tm[0]):(tm[1]);
        }
        printf("%d %d\n", nm[0]+nm[1], (tm[0]>tm[1])?(tm[0]):(tm[1]));
    }
    return 0;
}
