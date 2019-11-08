#include <iostream>

using namespace std;

typedef char Type;
int perm_count = 0;

inline void Swap(Type& a, Type& b) {
    Type t = a;
    a = b;
    b = t;
}

bool FindSame(Type list[], int k, int i) {
    bool findSame = false;
    for(;k < i;k++) {
        if(list[k] == list[i])
            findSame = true;
    }
    return findSame;
}

void PermExcludeSame(Type list[], int k, int m) {
    if(k == m) {
        perm_count++;
        for(int i = 0;i <= m;i++)
            cout<<list[i];
        cout<<endl;
    } else {
        for(int i = k; i <= m;i++) {
            if(FindSame(list,k,i))
                continue;
            Swap(list[k],list[i]);
            PermExcludeSame(list,k+1,m);
            Swap(list[k],list[i]);
        }
    }
}

int main() {
    Type a[20];
    int size;
    cin>>size;
    cin>>a;
    PermExcludeSame(a,0,size-1);
    cout<<perm_count<<endl;
    return 0;
}