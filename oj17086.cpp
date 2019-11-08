#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    char a[10];
    int n;
    cin>>n;
    cin>>a;
    sort(a,a+n);
    bool next = true;
    int num = 1;
    while(next) {
        cout<<num<<" "<<a<<endl;
        next = next_permutation(a,a+n);
        num++;
    }
    return 0;
}