template <typename T>
struct bit {
    vector<T> t;
    bit(int n) : t(n + 1, 0) {}
    void modify(int idx, T val) { // add val to a[idx]
        for (idx++; idx < t.size(); idx += idx & (-idx))
            t[idx] += val;
    }
    T query(int idx) { // query sum of a[0 ~ idx]
        T r = 0;
        for (idx++; idx; idx -= idx & (-idx))
            r += t[idx];
        return r;
    }
};