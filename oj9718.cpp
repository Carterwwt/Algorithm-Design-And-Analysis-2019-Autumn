#include <iostream>

using namespace std;

int num = 0;

void solve(int n) {
    if(n == 1)
        num++;
    for(int i = 2;i <= n;i++) {
        if(n % i == 0)
            solve(n / i);
    }
}

int main() {
    int n;
    cin>>n;
    solve(n);
    cout<<num<<endl;
    return 0;
}