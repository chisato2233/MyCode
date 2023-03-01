#include<bits/stdc++.h>
using namespace std;
void slove() {
    int n, flag = 0, min_num = 0x3f3f3f3f;
    long long sum = 0;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        if (a[i] < 0) flag = !flag;
        min_num = abs(a[i]) < min_num ? abs(a[i]) : abs(min_num);
        sum += 1ll * abs(a[i]);
    }
    if (flag) sum -= 2ll * min_num;
    cout << sum << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) slove();
}