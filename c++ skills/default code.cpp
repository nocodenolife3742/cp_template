#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using l128 = __int128_t;
using ull = unsigned long long;
using ul128 = __uint128_t;
using ld = long double;

template<typename T>
using min_heap = std::priority_queue<T, vector<T>, greater<T> >;
template<typename T>
using max_heap = std::priority_queue<T, vector<T>, less<T> >;
template<typename T>
using tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define F firstl
#define S second
#define all(x) x.begin(), x.end()

#pragma region debug_print

#ifdef DEBUG
#define dbg(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl;
#else
#define dbg(x)
#endif

template<typename T1, typename T2>
ostream &operator<<(ostream &o, const pair<T1, T2> &p);

template<typename os, typename T>
enable_if_t<is_same_v<os, ostream>, os &> operator<<(os &o, const T &v) {
    o << '[';
    for (auto &&x: v)
        o << x << ' ';
    return o << (v.empty() ? "]" : "\b]");
}

template<typename T1, typename T2>
ostream &operator<<(ostream &o, const pair<T1, T2> &p) {
    return o << '(' << p.first << ':' << p.second << ')';
}

#pragma endregion

void solve() {
    // code hrer
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
