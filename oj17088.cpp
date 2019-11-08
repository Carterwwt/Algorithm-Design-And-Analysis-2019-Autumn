#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int a[1000005];
map<int, int> m;

// 左右两边与中间数相同的数的起始、终止界限
void split(int a[], int n, int &l, int &r)
{
    int mid = n/2;
    // 连续两个for求与s[mid]相同的数有多少个
    for(l=0; l<n; ++l)
    {
        if (a[l] == a[mid])
            break;
    }
    for(r=l+1; r<n; ++r)
    {
        if (a[r] != a[mid])
            break;
    }

}

void getMaxCnt(int a[], int n, int& mid, int& maxCnt) {
    int l,r;
    split(a,n,l,r);
    int cnt = r - l;
    int num = n / 2;
    //更新最大值
    if(cnt > maxCnt) {
        maxCnt = cnt;
        mid = a[num];
        m.clear();
        m[mid] = maxCnt;
    } else if(cnt == maxCnt) {
        mid = a[num];
        m[mid] = maxCnt;
    }
    if(l >= maxCnt) {
        getMaxCnt(a,l,mid,maxCnt);
    }
    if(n - r >= maxCnt) {
        getMaxCnt(a,n-r,mid,maxCnt);
    }
}

int main() {
    int size;
    int mid = 0;
    int maxCnt = 0;
    cin>>size;
    for(int i=0;i<size;i++)
        cin>>a[i];
    sort(a,a+size);
    getMaxCnt(a,size,mid,maxCnt);
    int minVal = INT32_MAX, minCount = 0;
    for(auto it = m.begin();it != m.end();it++) {
        if(it->second > minCount) {
            minVal = it->first;
            minCount = it->second;
        } else if(it->second == minCount && it->first < minVal) {
            minVal = it->first;
            minCount = it->second;
        }
    }
    cout<<minVal<<" "<<minCount<<endl;
    return 0;
}