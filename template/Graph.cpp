#include<bits/stdc++.h>
using namespace std;
class Graph {
public:
    struct edge {
        int from, to, val;
        friend int operator<(edge a, edge b) {
            return a.val > b.val;
        }
    };
    vector<list <edge>> g;
    Graph(int n):g(n + 1) { }
    list<edge>& operator[](int i) {
        return g[i];
    }
    void input(int from, int to, int val = 0) {
        g[from].push_front(edge{ from,to,val });
    }
    friend istream& operator>>(istream& cin, Graph& _g) {
        int n = _g.g.size();
        for (int i = 1;i <= n;i++) {
            int u, v, val;
            cin >> u >> v >> val;
            _g[u].push_front(edge{ u,v,val });
        }
        return cin;
    }
};