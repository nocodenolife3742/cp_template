struct dsu {
    vector<int> p;
    vector<array<int, 3>> his;
    dsu(int n) : p(n, -1) {}
    int par(int x) {
        return p[x] < 0 ? x : par(p[x]);
        // without undo : p[x] < 0 ? x : p[x] = par(p[x]);
    }
    bool same(int a, int b) {
        return par(a) == par(b);
    }
    int size(int x) {
        return -p[par(x)];
    }
    bool unite(int x, int y) {
        x = par(x), y = par(y);
        if (x == y)
            return false;
        if (p[x] > p[y])
            swap(x, y);
        his.push_back({x, y, p[y]});
        p[x] += p[y], p[y] = x;
        return true;
    }
    bool undo() {
        if (his.empty())
            return false;
        auto [x, y, py] = his.back();
        p[y] = py, p[x] -= p[y];
        his.pop_back();
        return true;
    }
};