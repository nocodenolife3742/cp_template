int qpow(int b, int e, int m) {
    int ans = 1;
    while (e) {
        if (1 & e)
            ans = (ans * b) % m;
        b = (b * b) % m;
        e >>= 1;
    }
    return ans;
}