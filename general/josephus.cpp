int josephus(int n, int k) {
    if (n == 1)
        return 0;
    if (k == 1)
        return n - 1;
    if (k > n)
        return (josephus(n - 1, k) + k) % n;
    int t = josephus(n - n / k, k) - n % k;
    return t < 0 ? t + n : t + t / (k - 1);
}