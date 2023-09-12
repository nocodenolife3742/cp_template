// default code version : 1.4

ll qpow(ll b, ll e, ll m)
{
    ll res = 1;
    rep(i, 0, 62)
    {
        if (1 & (e >> i))
            res = (res * b) % m;
        b = (b * b) % m;
    }
    return res;
}