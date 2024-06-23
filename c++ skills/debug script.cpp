// macros
#define TP template
#define TN typename
#define iter_print TP<TN T> TN enable_if<is_iter<T>::value, ostream &>::type operator<<(ostream &o, const T &t)
#define pair_print TP<TN T1, TN T2> ostream &operator<<(ostream &o, const pair<T1, T2> &p)
TP<TN T> using is_iter = decltype(begin(declval<T>()), end(declval<T>()), true_type());
// definitions
iter_print;
pair_print;
iter_print {
    o << '[';
    for (auto i = t.begin(); i != t.end(); ++i)
        o << *i << ",]"[next(i) == t.end()];
    return o;
}
pair_print {
    o << '(' << p.first << ':' << p.second << ')';
    return o;
}
// debug function
void dbg() { cerr << '\n'; }
TP<TN T1, TN... T2> void dbg(T1 v1, T2... v2) { cerr << v1 << ' ', dbg(v2...); }
