// default code version : 1.4

class bit
{
private:
    vector<ll> t;

public:
    bit(ll n)
    {
        t.resize(n + 1, 0);
    }

    void modify(ll idx, ll val)
    {
        while (idx < sz(t))
        {
            t[idx] += val;
            idx += idx & (-idx);
        }
    }

    ll query(ll idx)
    {
        ll ret = 0;
        while (idx > 0)
        {
            ret += t[idx];
            idx -= idx & (-idx);
        }
        return ret;
    }
};