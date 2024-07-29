pair<vector<int>, vector<int> > sa_lcp(string &s) {
    s += '$';
    int n = s.size();
    vector<int> ord(n), rank(n), cnt(n + 1), tmp(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) { return s[i] < s[j]; });
    for (int i = 1; i < n; i++) {
        rank[ord[i]] = rank[ord[i - 1]];
        if (s[ord[i]] != s[ord[i - 1]]) rank[ord[i]]++;
    }
    for (int len = 1; len < n; len *= 2) {
        fill(cnt.begin(), cnt.end(), 0);
        for (int j: rank) cnt[j + 1]++;
        for (int j = 1; j <= n; j++) cnt[j] += cnt[j - 1];
        for (int &x: ord) x = (x - len + n) % n;
        for (int j: ord) tmp[cnt[rank[j]]++] = j;
        swap(ord, tmp);
        tmp[ord[0]] = 0;
        int rcnt = 0;
        for (int j = 1; j < n; j++) {
            if (rank[ord[j - 1]] != rank[ord[j]] ||
                rank[(ord[j - 1] + len) % n] != rank[(ord[j] + len) % n])
                rcnt++;
            tmp[ord[j]] = rcnt;
        }
        swap(rank, tmp);
    }
    for (int i = 0, k = 0; i < n - 1; i++) {
        while (s[i + k] == s[ord[rank[i] - 1] + k]) k++;
        tmp[rank[i] - 1] = k;
        if (k > 0) k--;
    }
    return {ord, vector<int>(tmp.begin(), tmp.end() - 1)};
}
