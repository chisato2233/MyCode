#include<bits/stdc++.h>
using namespace std;
class BIT {
public:
    vector<int> sorce;
    BIT(int n):sorce(n + 1) { }
    void insert(int position, int num) {
        for (int i = position;i <= sorce.size();i += i & (-i)) sorce[i] += num;
    }
    long long sum(int num) {
        long long r = 0;
        for (int i = num;i >= 1;i -= i & (-i)) r += sorce[i];
        return r;
    }
};