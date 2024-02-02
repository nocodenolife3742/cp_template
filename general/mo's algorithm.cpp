const int K = sqrt(N) * 3;
struct query {
    int l, r, idx;
};
void add(int idx) {} // add a[idx] into the answer
void sub(int idx) {} // remove a[idx] from the answer
bool cmp(query a, query b) {
    if (a.l / K == b.l / K)
        return (a.l / K) & 1 ? a.r > b.r : a.r < b.r;
    return a.l < b.l;
}
void moalgo() {
    sort(querys, querys + q_cnt, cmp);
    int l = 0, r = -1;
    for (int i = 0; i < q_cnt; i++) {
        while (l < querys[i].l) sub(l++);
        while (l > querys[i].l) add(--l);
        while (r < querys[i].r) add(++r);
        while (r > querys[i].r) sub(r--);
        ans[querys[i].idx] = now_ans;
    }
}