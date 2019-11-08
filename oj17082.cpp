#include <iostream>
using namespace std;

int find_k(int xBeg, int xEnd, int yBeg, int yEnd, int *x, int *y, int k) {
    if(xBeg > xEnd)
        return y[yBeg + k - 1];
    if(yBeg > yEnd)
        return x[xBeg + k - 1];
    int xMid = xBeg + (xEnd - xBeg) / 2;
    int yMid = yBeg + (yEnd - yBeg) / 2;
    int halfLen = xMid - xBeg + yMid - yBeg + 2;
    if(x[xMid] < y[yMid]) {
        if(k < halfLen) {
            return find_k(xBeg, xEnd, yBeg, yMid - 1, x, y, k);
        } else {
            return find_k(xMid + 1, xEnd, yBeg, yEnd, x, y, k - (xMid - xBeg + 1));
        }
    } else {
        if(k < halfLen) {
            return find_k(xBeg, xMid - 1, yBeg, yEnd, x, y, k);
        } else {
            return find_k(xBeg, xEnd, yMid + 1, yEnd, x, y, k - (yMid - yBeg + 1));
        }
    }
}

int main() {
    int m,n,k;
    cin >> m >> n >> k;
    int *a = new int[m];
    int *b = new int[n];
    for(int i=0;i<m;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
        cin >> b[i];
    cout << find_k(0, m-1, 0, n-1, a, b, k) << endl;
    return 0;
}