#include <iostream>
#define MAXN 10005
using namespace std;

int main() {
    int a[MAXN];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int i = n - 1, j = n - 1, res = 0;
    int r = abs(a[j]);
    while(i >= 0) {
        if(a[i] <= r)
            i--;
        else {
            res = max(res,j-i);
            j--;
            r = abs(a[j]);
        }
    }
    res = max(res,j-i);
    cout << res << endl;
    return 0;
}