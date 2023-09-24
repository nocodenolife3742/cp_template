// default code version : 1.4

vector<vector<ll>> floyd_warshall(vector<vector<ll>> &edges, ll vcnt)
{
    vector<vector<ll>> ans = edges;
    rep(k, 1, vcnt)
        rep(i, 1, vcnt)
            rep(j, 1, vcnt)
                ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);
    return ans;
}