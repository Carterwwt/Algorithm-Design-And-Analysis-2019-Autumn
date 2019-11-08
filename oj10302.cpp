#include <iostream>
#include <cmath>
using namespace std;

long long a[10000][14] = {0};

long long f(int n, int k) {
    if(k == 0 || n == 0)
        return 1;
    if(k > (int)log2(n))
        return f(n, (int)log2(n));
    if(k > 0) {
        if(a[n][k] > 0)
            return a[n][k];
        long long sum = 0;
        for(int i=0;i<=k;i++)
            sum += f(n - (int)pow(2, i), i);
        a[n][k] = sum;
        return sum;
    }
}

int main() {
    int n;
    cin >> n;
    cout << f(n, n) % 1000000000 << endl;
    return 0;
}