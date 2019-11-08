#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 10005
using namespace std;

char sour[MAXN];
char dest[MAXN];
int dp[MAXN][MAXN] = {0};

void LCS(int n, int m) {
    int max_len = 0;
    int start_index = 0;
    int end_index = 0;
    for(int i = 0;i<=n;i++) {
        for(int j=0;j<=m;j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (sour[i - 1] == dest[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = 0;
            }
            if (dp[i][j] > max_len) {
                max_len = dp[i][j];
                start_index =(i-1) - max_len + 1;
                end_index = i-1;
            }
        }
    }
    cout << max_len << endl;
    if(max_len != 0) {
        for (int i = start_index; i <= end_index; i++)
            printf("%c", sour[i]);
    }
    printf("\n");
}

int main() {
    memset(sour, '\0', MAXN);
    memset(dest, '\0', MAXN);
    for(int i=0;i<MAXN;i++)
        memset(dp[i], -1, MAXN);
    cin >> sour;
    cin >> dest;
    LCS(strlen(sour), strlen(dest));
    return 0;
}