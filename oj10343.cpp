#include <iostream>
using namespace std;

int res[21] = {0};

int total(int n) {
    if(n == 2 || n == 3)
        return 1;
    if(n >= 4) {
        if(res[n] > 0)
            return res[n];
        int sum = 0;
        for(int i = 2;i <= n - 1;i++) {
            sum += total(i) * total(n - i + 1);
        }
        res[n] = sum;
        return sum;
    }
}

int main() {
    int n;
    cin >> n;
    if(n <= 2)
        cout << "No answer" << endl;
    else
        cout << total(n) << endl;
    return 0;
}