vector<pt> convex_hull(vector<pt> p) {
    // < : return all points on the convex hull
    // <= : only return minimum points required for the convex hull
    sort(p.begin(), p.end());
    int n = 0;
    vector<pt> ans(2 * p.size());
    for (int i = 0; i < p.size(); i++) {
        while (n >= 2 && (ans[n - 1] - ans[n - 2]) % (p[i] - ans[n - 2]) < 0)
            n--;
        ans[n++] = p[i];
    }
    for (int i = p.size() - 2, t = n + 1; i >= 0; i--) {
        while (n >= t && (ans[n - 1] - ans[n - 2]) % (p[i] - ans[n - 2]) < 0)
            n--;
        ans[n++] = p[i];
    }
    ans.resize(n - 1);
    return ans;
}