// work with M = 1e7, 998244353
using ll = long long;
typedef complex<double> cd;
typedef complex<long double> cld;

void fft(vector<cd> &a) {
    int n = a.size(), l = 31 - __builtin_clz(n);
    vector<cld> R(2, {1, 0});
    vector<cd> rt(2, {1, 0});
    for (int k = 2; k < n; k *= 2) {
        R.resize(n), rt.resize(n);
        cld x = polar(1.0L, acos(-1.0L) / k);
        for (int i = k; i < 2 * k; i++)
            rt[i] = R[i] = i & 1 ? R[i / 2] * x : R[i / 2];
    }
    vector<int> rev(n);
    for (int i = 0; i < n; i++)
        rev[i] = (rev[i / 2] | (i & 1) << l) / 2;
    for (int i = 0; i < n; i++)
        if (i < rev[i])
            swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2)
        for (int i = 0; i < n; i += 2 * k)
            for (int j = 0; j < k; j++) {
                auto *x = (double *) &rt[j + k], *y = (double *) &a[i + j + k];
                cd z(x[0] * y[0] - x[1] * y[1], x[0] * y[1] + x[1] * y[0]);
                a[i + j + k] = a[i + j] - z;
                a[i + j] += z;
            }
}

template<int M>
vector<ll> conv(vector<ll> &a, vector<ll> &b) {
    if (a.empty() || b.empty())
        return {};
    vector<ll> res(a.size() + b.size() - 1);
    int B = 32 - __builtin_clz(res.size()), n = 1 << B, cut = floor(sqrt(M));
    vector<cd> L(n), R(n), outs(n), outl(n);
    for (int i = 0; i < a.size(); i++)
        L[i] = {a[i] / cut, a[i] % cut};
    for (int i = 0; i < b.size(); i++)
        R[i] = {b[i] / cut, b[i] % cut};
    fft(L), fft(R);
    for (int i = 0; i < n; i++) {
        int j = -i & (n - 1);
        outl[j] = (L[i] + conj(L[j])) * R[i] / (2.0 * n);
        outs[j] = (L[i] - conj(L[j])) * R[i] / (2.0 * n) / cd{0, 1};
    }
    fft(outl), fft(outs);
    for (int i = 0; i < res.size(); i++) {
        ll av = llround(outl[i].real()), cv = llround(outs[i].imag());
        ll bv = llround(outl[i].imag()) + llround(outs[i].real());
        res[i] = ((av % M * cut + bv) % M * cut + cv) % M;
    }
    return res;
}