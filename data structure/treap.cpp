struct treap  {
    struct node {
        node *l, *r;
        int pri, val, sz;
        // add varibles if needed
        // !!remember to initialize!!
        node(int v) : pri(rand()), val(v) {
            sz = 1;
            l = r = 0;
        }
        void push();
    } *root = 0;

    int size(node *p) { return p ? p->sz : 0; }
    void pull(node *p);

    node *merge(node *a, node *b) {
        if (!a || !b)
            return a ? a : b;
        a->push(), b->push();
        if (a->pri > b->pri)
            return a->r = merge(a->r, b), pull(a), a;
        else
            return b->l = merge(a, b->l), pull(b), b;
    }

    void split(node *t, int k, node *&a, node *&b) {
        if (!t)
            return a = b = 0, void();
        t->push();
        if (size(t->l) < k)
            a = t, split(a->r, k - size(t->l) - 1, a->r, b), pull(a);
        else
            b = t, split(b->l, k, a, b->l), pull(b);
    }

    // add operations here
    void insert_back(int val) {
        static int idx = 0;
        node *l, *r;
        split(root, idx++, l, r);
        root = merge(merge(l, new node(val)), r);
    }

    void range_operation(int lidx, int ridx) {
        node *l, *mid, *r, *tmp;
        split(root, ridx + 1, tmp, r);
        split(tmp, lidx, l, mid);
        // do operation here
        root = merge(l, merge(mid, r));
    }
};

void treap::pull(node *p) { // update from subtree
    p->sz = 1 + size(p->l) + size(p->r);
}

void treap::node::push() { // push tag to subtree
    if (tag) { // tag exist
        // do operation here
        if (l)
            // give tag to left subtree
        if (r)
            // give tag to right subtree
        tag = 0;
    }
}