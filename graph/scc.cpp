struct scc {
    scc(int n) : vcnt(n), num(0), adj(n), low(n), dfn(n), instk(n) {}
    void add_edge(int u, int v) {
        adj[u].push_back(v);
    }
    void build() {
        for (int i = 0; i < vcnt; i++)
            if (!dfn[i])
                dfs(i);
    }
    void dfs(int u) {
        low[u] = dfn[u] = ++num;
        stk.push(u), instk[u] = 1;
        for (int &v: adj[u]) {
            if (!dfn[v]) {
                dfs(v);
                low[u] = min(low[u], low[v]);
            } else if (instk[v]) {
                low[u] = min(low[u], dfn[v]);
            }
        }
        if (low[u] == dfn[u]) {
            vector<int> scc;
            do {
                temp = stk.top(), stk.pop(), instk[temp] = 0;
                scc.push_back(temp);
            } while (temp != u);
            sccs.push_back(scc);
        }
    }
    int vcnt, num, temp;
    vector<vector<int>> adj, sccs;
    vector<int> low, dfn, instk;
    stack<int> stk;
};
