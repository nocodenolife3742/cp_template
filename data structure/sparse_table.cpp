template<class T>
struct sparse_table {
    // change these
    T merge(T &a, T &b);
    const T ue;
    const int level; // at least ceil(log n) 

    vector<vector<T> > t;

    sparse_table(vector<T> &a) : t(level, vector<T>(a.size())) {
        for (int i = 0; i < a.size(); i++)
            t[0][i] = a[i];
        for (int i = 1; i < level; i++)
            for (int j = 0; j + (1 << i - 1) < a.size(); j++)
                t[i][j] = merge(t[i - 1][j], t[i - 1][j + (1 << i - 1)]);
    }

    // query [l, r]
    T query(int l, int r) {
        T ret = ue;
        for (int i = level - 1; i >= 0; i--)
            if (1 << i <= r - l + 1)
                ret = combine(ret, t[i][l]), l += 1 << i;
        return ret;
    }
};
