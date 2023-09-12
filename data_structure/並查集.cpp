// default code version : 1.4

class dsu
{
private:
    vector<int> p, rk;

public:
    dsu(int n)
    {
        p.resize(n + 1, 0);
        rk.resize(n + 1, 0);
        rep(i, 1, n)
            p[i] = i;
    }

    int find(int x)
    {
        if (p[x] == x)
            return x;
        else
            return p[x] = find(p[x]);
    }

    bool unite(int x, int y)
    {
        x = find(x), y = find(y);
        if (x == y)
            return false;
        if (rk[x] < rk[y])
            swap(x, y);
        p[x] = y;
        if (rk[x] == rk[y])
            rk[y]++;
        return true;
    }

    bool same(int x, int y)
    {
        return find(x) == find(y);
    }
};