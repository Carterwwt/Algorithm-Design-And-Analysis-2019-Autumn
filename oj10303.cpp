#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 100;
int a[maxn][maxn];
int dp[maxn][maxn];
int route[maxn][maxn];

void solve(int i, int j, int n) {
    if(i == n)
        dp[i][j] = a[i][j];
    else {
        if(dp[i][j] >= 0)
            return;
        solve(i+1, j, n);
        solve(i+1, j+1, n);
        int left = dp[i+1][j], right = dp[i+1][j+1];
        dp[i][j] = max(left,right) + a[i][j];
        if(right >= left)
            route[i][j] = 1;
        else
            route[i][j] = 0;
    }
}

int main() {
    //初始化数组
    for(int i=0;i<maxn;i++) {
        memset(dp[i], -1, maxn);
        memset(route[i], -1, maxn);
    }
    //输入三角形
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<=i;j++) {
            cin >> a[i][j];
        }
    }
    //输出结果
    solve(0,0,n);
    cout << dp[0][0] << endl;
    int j=0;
    for(int i=0;i<n;i++) {
        cout << a[i][j] << " ";
        if(route[i][j] == 1) {
            j += 1;
        }
    }
    cout << endl;
    return 0;
}