#include <iostream>
#include <vector>
using namespace std;

int cc = 0;

bool func(int num) {
    int cur = num - 1;
    if(cur % 5 == 0 && cc < 5) {
        cc++;
        return func(cur / 5 * 4);
    } else {
        return cc == 5;
    }
}

int main() {
    int n;
    cin>>n;
    vector<int> res;
    for(int i=1;i<=n;i++) {
        cc = 0;
        if(func(i))
            res.push_back(i);
    }
    if(res.size() == 0)
        cout<<"impossible"<<endl;
    else {
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}