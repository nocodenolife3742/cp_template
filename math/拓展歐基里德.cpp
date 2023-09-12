// default code version : 1.4

pair<ll, ll> exgcd(ll a, ll b)
{
    if (b == 0)
        return mp(1, 0);
    pair<ll, ll> t = exgcd(b, a % b);
    return mp(t.se, t.fi - (a / b) * t.se);
}