int inv(int x, int m) { // only for prime m
    return 1 < x ? m - inv(m % x, x) * m / x : 1;
}