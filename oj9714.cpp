#include <iostream>
using namespace std;

int q(int n, int m) {
    if((n < 1) || (m < 1))
        return 0;
    if(n == 1 || m == 1)
        return 1;
    if(n < m)
        return q(n, n);
    if(n == m)
        return 1 + q(n, m - 1);
    return q(n, m - 1) + q(n - m, m);
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << q(n, m) << endl;
    return 0;
}