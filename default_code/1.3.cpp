// author : 1e-9
// version : 1.3

#include <bits/stdc++.h>
using namespace std;

// macros
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define rep(i, l, r) for (ll i = (l); i <= ((ll)(r)); i++)
#define repr(i, r, l) for (ll i = (r); i >= ((ll)(l)); i--)
#define repi(i, x) for (auto &i : (x))
#define dbg(x) cout << #x << " = " << x << '\n'
#define clk() std::chrono::high_resolution_clock::now().time_since_epoch().count()

// variables
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;

// constants
const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;
const ld EPS = 1e-6;
// const ld EPS = 1e-9;
const ll INF = 0x3F3F3F3F;
// const ll INF = INT_MAX;
// const ll INF = LONG_LONG_MAX;
const ld PI = 3.141592653589793;

void solve()
{
    // solve here
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll cnt = 1;
    cin >> cnt;
    rep(i, 1, cnt)
    {
        solve();
    }
    return 0;
}