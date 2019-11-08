#include <cstdio>
using namespace std;

int arr[1005] = {0};
int res[1005] = {0};

int f(int n) {
    int res_max = 1;
    for(int i=0;i<n;i++) {
        if(i == 0)
            res[i] = 1;
        else {
            int max = 1;
            for(int j = 0;j<i;j++) {
                if(arr[j] < arr[i] && res[j] + 1 > max) {
                    max = res[j] + 1;
                }
            }
            res[i] = max;
        }
        if(res[i] > res_max) {
            res_max = res[i];
        }
    }
    return res_max;
}

int main() {
    int n;
    scanf("%d",&n);
    while(n > 0) {
        for(int i=0;i<n;i++) {
            scanf("%d",&arr[i]);
        }
        printf("%d\n",f(n));
        scanf("%d",&n);
    }
    return 0;
}