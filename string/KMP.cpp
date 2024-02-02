vector<int> kmp(string &s, string &t) {
    if (t.size() == 0)
        return {};
    vector<int> pos;
    vector<int> nxt(t.size(), 0);
    for (int i = 1, j = 0; i < t.size(); i++) {
        while (j > 0 && t[i] != t[j])
            j = nxt[j - 1];
        if (t[i] == t[j])
            j++;
        nxt[i] = j;
    }
    for (int i = 0, j = 0; i < s.size(); i++) {
        if (j > 0 && s[i] != t[j])
            j = nxt[j - 1];
        if (s[i] == t[j])
            j++;
        if (j == t.size()) {
            pos.push_back(i - t.size() + 1);
            j = nxt[j - 1];
        }
    }
    return pos;
}