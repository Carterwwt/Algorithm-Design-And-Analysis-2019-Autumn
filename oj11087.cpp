#include <iostream>
using namespace std;

int count_inversion(int *a, int l, int r) {
    if(l + 1 == r)
        return a[l] > a[r] ? 1 : 0;
    int mid = l + (r - l) / 2;
    int count_left = count_inversion(a, l, mid);
    int count_right = count_inversion(a, mid+1, r);
    return count_left + count_right + ((mid - l + 1) - (r - mid));
}

int main() {
    int n;
    cin >> n;
    int *a = new int [n];

    return 0;
}