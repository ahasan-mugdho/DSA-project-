#include <stdio.h>

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int max_f = (n * n) / 4; 
        printf("%d\n", max_f + 1);
    }
    return 0;
}
