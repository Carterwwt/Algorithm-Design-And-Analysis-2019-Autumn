#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int per_count = 0;

void permutation(char *str, char *res, int cur, int n, int m, int str_len) {
    if(m == 0) {
        per_count++;
        cout << per_count << " " << res << endl;
    }
    else {
        if(m >= str_len - cur) {
            res[n - m] = str[cur];
            permutation(str, res, cur + 1, n, m - 1, str_len);
        } else {
            res[n - m] = str[cur];
            permutation(str, res, cur + 1, n, m - 1, str_len);
            permutation(str, res, cur + 1, n, m, str_len);
        }
    }
}

int main() {
    int n;
    cin >> n;
    char *str = new char[n+1];
    char *res = new char[n+1];
    cin >> str;
    sort(str, str + n);
    for(int i=1;i<=n;i++) {
        for(int k=0;k<=n;k++)
            res[k] = '\0';
        permutation(str, res, 0, i, i, strlen(str));
    }
    return 0;
}