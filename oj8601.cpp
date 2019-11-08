#include <iostream>
using namespace std;

int maxSum(int n, int *a) {
    int sum = 0, b = 0;
    for(int i=0;i<n;i++) {
        if(b > 0)
            b += a[i];
        else
            b = a[i];
        if(b > sum)
            sum = b;
    }
    return sum;
}

int maxSum2(int m, int n, int **a) {
    int sum = 0;
    int *b = new int[n];
    for(int i=0;i<m;i++) {
        for(int k=0;k<n;k++)
            b[k] = 0;
        for(int j=i;j<m;j++) {
            for(int k=0;k<n;k++)
                b[k] += a[j][k];
            int max = maxSum(n,b);
            if(max > sum)
                sum = max;
        }
    }
    return sum;
}

int maxSum3(int m, int n, int p, int ***a) {
    int sum = 0;
    int **b = new int*[m];
    for(int i=0;i<m;i++)
        b[i] = new int[n];
    for(int i=0;i<p;i++) {
        for(int k=0;k<m;k++)
            for(int l=0;l<n;l++)
                b[k][l] = 0;
        for(int j=i;j<p;j++) {
            for(int k=0;k<m;k++)
                for(int l=0;l<n;l++)
                    b[k][l] += a[k][l][j];
            int max = maxSum2(m,n,b);
            if(max > sum)
                sum = max;
        }
    }
    return sum;
}

int main() {
    int m,n,p;
    //三维测试
    cin >> m >> n >> p;
    int ***a = new int**[m];
    for(int i=0;i<m;i++) {
        a[i] = new int *[n];
        for(int j=0;j<n;j++) {
            a[i][j] = new int[p];
        }
    }
    for (int i=0;i<m;i++)
        for (int j=0;j<n;j++)
            for (int k=0;k<p;k++)
                cin >> a[i][j][k];
    cout << maxSum3(m,n,p,a) << endl;
    return 0;
}