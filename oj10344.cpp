#include <iostream>
using namespace std;

int res[20] = {0};

int P(int n) {
    if(res[n] > 0)
        return res[n];
    if(n == 1)
        return 1;
    if(n > 1) {
        int sum = 0;
        for(int i=1;i<n;i++) {
            sum += P(i) * P(n-i);
        }
        res[n] = sum;
        return sum;
    }
}

int main() {
    int n;
    cin >> n;
    cout << P(n) << endl;
    return 0;
}