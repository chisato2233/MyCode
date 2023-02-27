#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, count = 0;
    cin >> n;
    map<int,int> m;
    for (int i = 1;i <= n;i++) {
        int temp;
        cin >> temp;
        m[temp]++;
    }
        for (auto i : m) count += m[i.first];
    cout << count / 2;
}