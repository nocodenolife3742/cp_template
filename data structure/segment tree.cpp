struct range {
    int l, r;
    bool contain(range &o) { return l <= o.l && o.r <= r; }
    bool intersect(range &o) { return l <= o.r && o.l <= r; }
    pair<range, range> split() {
        int mid = l + ((r - l) >> 1);
        return {{l, mid}, {mid + 1, r}};
    }
};
template<typename T1, typename T2>
struct segtree {
    static T1 merge(T1 a, T1 b) {
        // merge two values
    }
    struct node {
        T1 data;
        T2 tag;
        range seg;
        node *lc, *rc;
        bool upd;
        node(range s) : seg(s), upd(false) {
            lc = rc = nullptr;
            // init data and tag
        }
        void apply(T2 t) {
            upd = true;
            // apply tag to node
        }
        void up() {
            if (lc && rc)
                data = merge(lc->data, rc->data);
        }
        void down() {
            if (lc && rc && upd)
                lc->apply(tag), rc->apply(tag);
            upd = false;
            // clear tag
        }
    } *root;
    range a;
    node *build(range s) {
        node *p = new node(s);
        if (s.l == s.r) return p;
        auto [l, r] = s.split();
        p->lc = build(l);
        p->rc = build(r);
        return p->up(), p;
    }
    void modify(range s, range t, node *p, T2 x) {
        if (!s.intersect(t)) return;
        p->down();
        if (t.contain(s)) return p->apply(x);
        auto [l, r] = s.split();
        modify(l, t, p->lc, x), modify(r, t, p->rc, x);
        p->up();
    }
    T1 query(range s, range t, node *p) {
        p->down();
        if (t.contain(s)) return p->data;
        auto [l, r] = s.split();
        if (!r.intersect(t)) return query(l, t, p->lc);
        if (!l.intersect(t)) return query(r, t, p->rc);
        return merge(query(l, t, p->lc), query(r, t, p->rc));
    }
    segtree(int n) : a({0, n - 1}) {
        root = build(a);
    }
    void modify(range t, T2 x) {
        modify(a, t, root, x);
    }
    T1 query(range t) {
        return query(a, t, root);
    }
};
