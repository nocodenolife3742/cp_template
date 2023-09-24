// default code version : 1.4

vector<ll> dijstra(ll start, vector<vector<pair<ll, ll>>> &edges, ll vcnt)
{
    vector<ll> ans(vcnt + 1, INF);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push(mp(0, start));
    while (!pq.empty())
    {
        ll u = pq.top().se;
        ll val = pq.top().fi;
        pq.pop();
        if (ans[u] != INF)
            continue;
        ans[u] = val;
        repi(i, edges[u])
        {
            ll v = i.fi;
            ll w = i.se;
            pq.push(mp(val + w, v));
        }
    }
    return ans;
}