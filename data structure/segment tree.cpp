// implement merge, apply function
// and initialize data and lazy of node
template<typename T1, typename T2>
struct segtree {
    static T1 merge(T1 a, T1 b) {
        return a + b;
    }
    struct node {
        T1 data;
        T2 lazy;
        node *lc, *rc;
        void apply(T2 t, int l, int r) {
            data += (r - l + 1) * t;
            lazy += t;
        }
        void up() {
            if (lc) data = merge(lc->data, rc->data);
        }
        void down(int l, int r) {
            if (lc) {
                int m = (l + r) / 2;
                lc->apply(lazy, l, m);
                rc->apply(lazy, m + 1, r);
            }
            lazy = 0;
        }
    } *root;
    int n;
    node *build(int l, int r) {
        node *p = new node();
        if (l == r) return p;
        int m = (l + r) / 2;
        p->lc = build(l, m);
        p->rc = build(m + 1, r);
        return p->up(), p;
    }
    void modify(int a, int b, int l, int r, node *p, T2 x) {
        if (r < a || l > b) return;
        p->down(l, r);
        if (a <= l && b >= r)
            return p->apply(x, l, r);
        int m = (l + r) / 2;
        modify(a, b, l, m, p->lc, x);
        modify(a, b, m + 1, r, p->rc, x);
        p->up();
    }
    T1 query(int a, int b, int l, int r, node *p) {
        p->down(l, r);
        if (a <= l && b >= r) return p->data;
        int m = (l + r) / 2;
        if (b <= m) return query(a, b, l, m, p->lc);
        if (a > m) return query(a, b, m + 1, r, p->rc);
        return merge(query(a, b, l, m, p->lc),
                     query(a, b, m + 1, r, p->rc));
    }
    segtree(int size) : n(size) {
        root = build(0, n - 1);
    }
    void modify(int l, int r, T2 x) {
        modify(l, r, 0, n - 1, root, x);
    }
    T1 query(int l, int r) {
        return query(l, r, 0, n - 1, root);
    }
};
