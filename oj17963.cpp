#include <iostream>
#include <cmath>

using namespace std;

long long p[] = {2, 3, 5, 7, 13, 17, 19, 31};

int main() {
    int size = sizeof(p) / sizeof(p[0]);
    long long perfect;
    for(int i=0;i<size;i++) {
        perfect = (long long)pow(2,p[i]-1) * (pow(2,p[i]) - 1);
        cout<<i+1<<" "<<perfect<<endl;
    }
    return 0;
}