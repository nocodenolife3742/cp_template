template <typename T>
struct BIT {
    vector<T> d, di;
    int lb(int x) {
        return x & -x;
    }
    BIT(vector<T> x) : d(x.size() + 2), di(x.size() + 2) {
        for (int i = 1, t; i <= x.size(); i++) {
            d[i] = x[i - 1], t = i - lb(i);
            for (int j = i - 1; j > t; j -= lb(j))
                d[i] += d[j];
        }
    }
    void modify(int x, T v) { // range modify
        for (int t = ++x; t; t -= lb(t))
            di[t] += v;
        for (int t = x + lb(x); t && t <= d.size(); t += lb(t))
            d[t] += v * (x - t + lb(t));
    }
    T query(int x) {
        T ret = 0;
        for (int t = ++x; t; t -= lb(t))
            ret += di[t] * lb(t) + d[t];
        for (int t = x + lb(x); t && t <= d.size(); t += lb(t))
            ret += di[t] * (x - t + lb(t));
        return ret;
    }
};