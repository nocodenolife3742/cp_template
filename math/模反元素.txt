// default code version : 1.4

ll inv(ll x, ll m)
{
    return 1 < x ? m - inv(m % x, x) * m / x : 1;
}