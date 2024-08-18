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
    int kth(T k) { // lower bound index of prefix sum
        int r = 0;
        for (int i = __lg(t.size()); i >= 0; i--) {
            int p = (1 << i) + r;
            if (p < t.size() && k - t[p] >= 0)
                k -= t[p], r = p;
        }
        return r;
    }
};
