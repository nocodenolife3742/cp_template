struct binary_trie {
    const int MAX_BIT = 30;
    vector<array<int, 2>> nxt{{0, 0}};
    vector<int> cnt{0};

    void insert(int num) {
        int n = 0;
        for (int i = MAX_BIT - 1; i >= 0; i--) {
            int t = (num >> i) & 1;
            if (!nxt[n][t]) {
                nxt[n][t] = nxt.size();
                nxt.push_back({0, 0});
                cnt.push_back(0);
            }
            n = nxt[n][t];
            cnt[n]++;
        }
    }

    void remove(int num) {
        int n = 0;
        for (int i = MAX_BIT - 1; i >= 0; i--) {
            n = nxt[n][(num >> i) & 1];
            cnt[n]--;
        }
    }

    bool exist(int num, int xor_all = 0) {
        int n = 0;
        for (int i = MAX_BIT - 1; i >= 0; i--) {
            int t = ((num ^ xor_all) >> i) & 1;
            if (!nxt[n][t] || !cnt[nxt[n][t]])
                return false;
            n = nxt[n][t];
        }
        return true;
    }

    int find_max(int xor_all = 0) {
        int n = 0;
        for (int i = MAX_BIT - 1; i >= 0; i--) {
            int t = (xor_all >> i) & 1;
            // find_min : t = (xor_all >> i) & 1 ^ 1
            if (nxt[n][1 ^ t] && cnt[nxt[n][1 ^ t]])
                t ^= 1;
            n = nxt[n][t];
            xor_all ^= t << i;
        }
        return xor_all;
    }
};