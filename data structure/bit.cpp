template <typename T>
struct bit {
    vector<T> t;
    bit(vector<T> x) : t(x.size() + 1, 0) {
        for (int i = 0; i < x.size(); i++)
            modify(i, x[i]);
    }
    void modify(int x, T val) {
        for (x++; x < t.size(); x += x & (-x))
            t[x] += val;
    }
    T query(int x) {
        T r = 0;
        for (x++; x; x -= x & (-x))
            r += t[x];
        return r;
    }
};