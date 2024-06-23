#define TP template
#define TN typename
#define iout TP<TN T> TN enable_if<is_iter<T>::value && !is_same<string,\
             T>::value, ostream &>::type operator<<(ostream &o, const T &t)
#define pout TP<TN T1, TN T2> ostream &operator<<(ostream &o, const pair<T1, T2> &p)
TP<TN T> using is_iter = decltype(begin(declval<T>()), end(declval<T>()), true_type());

pout;
iout;
pout { return o << '(' << p.first << ':' << p.second << ')'; }
iout {
    if (t.empty())
        return o << "[{empty}]";
    o << '[';
    for (auto &&i: t)
        o << i << ' ';
    return o << "\b]";
}

void dbg() { cerr << endl; }
TP<TN T1, TN... T2>
void dbg(T1 v1, T2... v2) { cerr << v1 << ' ', dbg(v2...); }
