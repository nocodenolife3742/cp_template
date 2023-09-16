// default code version : 1.4

vector<ll> e[(ll)1e5 + 5], er[(ll)1e5 + 5];
bool vis[(ll)1e5 + 5];
vector<ll> ord, temp;

void dfs1(ll n)
{
    if (vis[n])
        return;
    vis[n] = true;
    repi(i, e[n])
        dfs1(i);
    ord.pb(n);
}

void dfs2(ll n)
{
    if (vis[n])
        return;
    vis[n] = true;
    repi(i, er[n])
        dfs2(i);
    temp.pb(n);
}

vector<vector<ll>> kosaraju(ll vcnt)
{
    vector<vector<ll>> scc;
    rep(i, 1, vcnt)
        vis[i] = false;
    rep(i, 1, vcnt)
        dfs1(i);
    reverse(all(ord));
    rep(i, 1, vcnt)
        vis[i] = false;
    repi(i, ord)
    {
        if (!vis[i])
        {
            temp.clear();
            dfs2(i);
            scc.pb(temp);
        }
    }
    return scc;
}