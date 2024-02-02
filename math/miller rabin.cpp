namespace mr {
    using u64 = uint64_t;
    using u128 = __uint128_t;
    u64 qpow(u64 base, u64 e, u64 mod) {
        u64 result = 1;
        base %= mod;
        while (e) {
            if (e & 1)
                result = (u128)result * base % mod;
            base = (u128)base * base % mod;
            e >>= 1;
        }
        return result;
    }
    bool check(u64 n, u64 a, u64 d, int s) {
        u64 x = qpow(a, d, n);
        if (x == 1 || x == n - 1)
            return false;
        for (int r = 1; r < s; r++) {
            x = (u128)x * x % n;
            if (x == n - 1)
                return false;
        }
        return true;
    }
    bool is_prime(u64 n, int iter = 5) {
        if (n < 4)
            return n == 2 || n == 3;
        u64 r = 0, d = n - 1;
        while (!(d & 1))
            d >>= 1, r++;
        for (int i = 0; i < iter; i++) {
            int a = 2 + rand() % (n - 3);
            if (check(n, a, d, r))
                return false;
        }
        return true;
    }
    bool is_prime64(u64 n) {
        if (n < 2)
            return false;
        u64 r = 0, d = n - 1;
        while (!(d & 1))
            d >>= 1, r++;
        // 32bit : 2, 7, 61
        // 64bit : 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37
        for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
            if (n == a)
                return true;
            if (check(n, a, d, r))
                return false;
        }
        return true;
    }
}