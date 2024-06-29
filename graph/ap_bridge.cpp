struct ap_bridge {
    ap_bridge(int n) : vcnt(n), num(0), adj(n), low(n), dfn(n) {}
    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void build() {
        for (int i = 0; i < vcnt; i++)
            if (!dfn[i])
                dfs(i, -1);
    }
    void dfs(int u, int p) {
        low[u] = dfn[u] = ++num;
        int cnt = 0;
        for (int &v: adj[u]) {
            if (!dfn[v]) {
                cnt++;
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] >= dfn[u] && p != -1)
                    ap.insert(u);
                if (low[v] > dfn[u])
                    bridges.insert({u, v});
            } else if (v != p)
                low[u] = min(low[u], dfn[v]);
        }
        if (p == -1 && cnt > 1)
            ap.insert(u);
    }
    int vcnt, num;
    vector<vector<int>> adj;
    vector<int> low, dfn;
    set<pair<int, int>> bridges;
    set<int> ap;
};
