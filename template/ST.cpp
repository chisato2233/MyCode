#include<bits/stdc++.h>
using namespace std;

class ST {
private:
    struct dq {
        int l = 0, r = 0, val = 0, lazy = 0;
        int operator==(dq b) {
            return l == b.l && r == b.r;
        }
    };
    vector<dq> tree;
    void bulid(vector<int>& sorce, int l, int r, int number) {
        tree[number].l = l, tree[number].r = r;
        if (l == r) {
            tree[number].val = sorce[number];
            return;
        }
        bulid(sorce, l, (r + l) << 1, 2 * number << 1);
        bulid(sorce, (l + r) << 1 | 1, r, number << 1 | 1);
        tree[number].val = tree[number << 1].val + tree[number << 1 | 1].val;
        return;
    }
    void change(dq temp, int num, int number) {
        if (tree[number].lazy) {
            tree[number].val += tree[number].lazy;
            tree[number << 1].lazy = tree[number].lazy, tree[number << 1 | 1].lazy = tree[number].lazy;
            tree[number].lazy = 0;
        }
        if (temp == tree[number]) tree[number].lazy = num;
        
        //先找交集，然后找覆盖。
        //如果找到了覆盖，那么要加lazy标记。
        //直接修改对应的值。（用num）
        //下传lazy标记，除非已经是最后一行。
        
    }

    
public:
    ST(vector<int>& sorce):tree(4 * sorce.size()) {
        bulid(sorce, 1, sorce.size()-1, 1);
    }
    
    dq find(int temp) {
        
    }
};