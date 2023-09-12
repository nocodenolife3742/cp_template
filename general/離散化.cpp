// default code version : 1.4

vector<ll> uni(vector<ll> x)
{
    vector<ll> res = x;
    sort(all(x));
    x.erase(unique(all(x)), x.end());
    repi(i, res)
        i = lb(all(x), i) - x.begin();
    return res;
}