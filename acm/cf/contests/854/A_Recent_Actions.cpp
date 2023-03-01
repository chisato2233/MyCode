#include<bits/stdc++.h>
using namespace std;


void slove() {
    int n, m;
    cin >> n >> m;
    vector<int> change(m + 1), res(n + 1, -1), vis(m + 1);
    int x = n;
    for (int i = 1;i <= m;i++) {
        cin >> change[i];
        if (x > 0) {
            if (!vis[change[i] - n]) {
                vis[change[i] - n]++;
                res[x] = i;
                x--;
            }
        }
    }
    for (int i = 1;i <= n;i++) cout << res[i] << ' ';
    cout << '\n';
}

int main() {
    int t;
    for (cin >> t;t > 0;t--) slove();
}