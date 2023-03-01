#include<bits/stdc++.h>
using namespace std;
void slove() {
    struct box{
        int val, lid;
   };
    int n;
    cin >> n;
    vector<box> a(n + 1);
    vector<int> dp(n+1);
    string temp;
    cin >> temp;
    for (int i = 0;i < n;i++) cin >> a[i + 1].val, a[i + 1].lid = temp[i];
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) slove();
}