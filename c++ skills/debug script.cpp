#define TP template
#define TN typename
TP<TN T> using is_iter = decltype(begin(declval<T>()), end(declval<T>()), true_type());
#define IOUT TP<TN T> TN enable_if<is_iter<T>::value && !is_same<string,\
             T>::value, ostream &>::type operator<<(ostream &o, const T &t)
#define POUT TP<TN T1, TN T2> ostream &operator<<(ostream &o, const pair<T1, T2> &p)
POUT; IOUT;
POUT { return o << '(' << p.first << ':' << p.second << ')'; }
IOUT { o << '['; for (auto &&i: t) o << i << ' '; return o << (t.empty() ? "]" : "\b]"); }
void dbg() { cerr << endl; }
TP<TN T1, TN... T2> void dbg(T1 v1, T2... v2) { cerr << v1 << ' ', dbg(v2...); }

// C++ 17 readable version
#define dbg(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl;
template<typename T1, typename T2>
ostream &operator<<(ostream &o, const pair<T1, T2> &p);
template<typename T1, typename T2>
enable_if_t<is_same_v<T1, ostream>, T1 &> operator<<(T1 &o, const T2 &v) {
    o << "[ ";
    for (auto &&i: v)
        o << i << ' ';
    return o << ']';
}
template<typename T1, typename T2>
ostream &operator<<(ostream &o, const pair<T1, T2> &p) {
    return o << '(' << p.first << ':' << p.second << ')';
}
