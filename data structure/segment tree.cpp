template <typename T>
struct segtree {
    // implementation details
    int size;
    struct node {
        T val, tag;
        int l, r;
        node *lc, *rc;
        node(T val, int l, int r) : val(val), l(l), r(r) {
            lc = rc = nullptr;
            tag = 0;
        }
        void down() {
            if (!lc || !rc)
                return;
            if (tag) {
                add_tag(lc, tag);
                add_tag(rc, tag);
                tag = 0;
            }
        }
        void up() {
            if (!lc || !rc)
                return;
            val = merge(lc->val, rc->val);
        }
    } *root;
    node *build(int l, int r, vector<T> &a) {
        node *n = new node(a[l], l, r);
        n->l = l, n->r = r;
        if (l == r)
            return n;
        int mid = (l + r) >> 1;
        n->lc = build(l, mid, a);
        n->rc = build(mid + 1, r, a);
        return n->up(), n;
    }
    T query(node *n, int l, int r, int ql, int qr) {
        n->down();
        if (ql <= l && r <= qr)
            return n->val;
        int mid = (l + r) >> 1;
        if (qr <= mid)
            return query(n->lc, l, mid, ql, qr);
        if (ql > mid)
            return query(n->rc, mid + 1, r, ql, qr);
        return merge(query(n->lc, l, mid, ql, qr),
                     query(n->rc, mid + 1, r, ql, qr));
    }
    void modify(node *n, int l, int r, int ml, int mr, T val) {
        if (l > mr || r < ml)
            return;
        n->down();
        if (ml <= l && r <= mr)
            return add_tag(n, val), void();
        int mid = (l + r) >> 1;
        modify(n->lc, l, mid, ml, mr, val);
        modify(n->rc, mid + 1, r, ml, mr, val);
        n->up();
    }

    // implementation these two functions
    static T merge(T a, T b);            // merge two children
    static void add_tag(node *n, T val); // add tag to this node

    // public operations
    segtree(vector<T> &a) {
        size = a.size();
        root = build(0, size - 1, a);
    }
    T query(int ql, int qr) {
        return query(root, 0, size - 1, ql, qr);
    }
    void modify(int l, int r, T val) {
        modify(root, 0, size - 1, l, r, val);
    }
};