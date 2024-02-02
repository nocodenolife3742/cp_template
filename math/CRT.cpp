int inv(int x, int m) {
    return 1 < x ? m - inv(m % x, x) * m / x : 1;
}

int crt(vector<int> m, vector<int> r) {
    int p = 1, ans = 0;
    for (int i : m)
        p *= i;
    for (int i = 0; i < m.size(); i++)
        ans = (ans + r[i] * (p / m[i]) * inv(p / m[i], m[i])) % p;
    return (ans % p + p) % p;
}