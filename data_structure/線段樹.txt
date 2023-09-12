// default code version : 1.4

template <typename T>
class segtree
{
private:
    int n;
    vector<T> seg;

    // change below
    const T uelem = 0;
    T merge(T a, T b)
    {
        return a + b;
    }

public:
    segtree(int sz)
    {
        n = sz;
        seg.resize(2 * n);
    }
    T &at(int idx)
    {
        return seg[idx + n];
    }
    void build()
    {
        for (int i = n - 1; i > 0; i--)
            seg[i] = merge(seg[i << 1], seg[i << 1 | 1]);
    }
    void modify(int p, T val)
    {
        for (seg[p += n] = val; p; p >>= 1)
            seg[p >> 1] = merge(seg[p], seg[p ^ 1]);
    }
    T query(int l, int r)
    {
        T ret = uelem;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                ret = merge(ret, seg[l++]);
            if (r & 1)
                ret = merge(ret, seg[--r]);
        }
        return ret;
    }
};