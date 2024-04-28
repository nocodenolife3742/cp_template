template <typename T>
struct zkw_seg {
    T merge(T a, T b) { return min(a, b); }
    const T ue = 0x3f3f3f3f;

    int n;
    vector<T> seg;
    zkw_seg(int n) : n(n), seg(2 * n, ue) {}
    void modify(int p, T val) {
        for (seg[p += n] = val; p; p >>= 1)
            seg[p >> 1] = merge(seg[p], seg[p ^ 1]);
    }
    T query(int l, int r) {
        T ret = ue;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ret = merge(ret, seg[l++]);
            if (r & 1) ret = merge(seg[--r], ret);
        }
        return ret;
    }
};