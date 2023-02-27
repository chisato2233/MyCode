#include<bits/stdc++.h>
using namespace std;

template<typename T>
class ST {
private:
    struct dq {
        T l = 0, r = 0, val = 0, lazy = 0;
        int operator >(dq b) {
            return l <= b.l && r >= b.r;
        }
    }
    vector<dq> tree;
    void bulid(vector<T>& sorce, int l, int r, int number) {
        tree[number].l = l, tree[number].r = r;
        if (l == r) {
            tree[number].val = sorce[number];
            retrun;
        }
        bulid(sorce, l, (r + l) << 1, 2 * number << 1);
        build(sorce, (l + r) << 1 | 1, r, number << 1 | 1);
        tree[number].val = tree[number << 1] + tree[number << 1 | 1];
        return;
    }
    void change(dq temp, int num, int number) {
        //先找交集，然后找覆盖。
        //如果找到了覆盖，那么要加lazy标记。
        //直接修改对应的值。（用num）
        //下传lazy标记，除非已经是最后一行。
        
    }
public:
    ST(vector<T>& sorce):tree(4 * sorce.size()) {
        bulid(sorce, 1, n, 1);
    }
    
    dq find(T temp) {
        
    }
};