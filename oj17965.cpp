#include <cstdio>

int lucky1(int n) {
    if(n == 1)
        return 1;
    return 2 * lucky1(n / 2);
}

int lucky2(int n, int m) {
    int *b = new int[n+1];
    b[1] = 1;
    for(int i=2;i<=n;i++) {
        b[i] = (b[i-1] + m - 1) % i + 1;
    }
    return b[n];
}

int main() {
    int n,m;
    scanf("%d %d", &n, &m);
    printf("%d %d", lucky1(n), lucky2(n, m));
    return 0;
}