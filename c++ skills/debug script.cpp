// macros
#define TP template
#define TN typename
#define OS ostream
#define iter_print TP<TN T> TN enable_if<is_iter<T>::value && !is_same<string, T>::value, OS &>::type operator<<(OS &o, const T &t)
#define pair_print TP<TN T1, TN T2> OS &operator<<(OS &o, const pair<T1, T2> &p)
TP<TN T> using is_iter = decltype(begin(declval<T>()), end(declval<T>()), true_type());

// definitions
iter_print;
pair_print;
iter_print {
    o << '[';
    for (auto &&i : t)
        o << *i << ' ';
    o << ']';
    return o;
}
pair_print {
    o << '(' << p.first << ':' << p.second << ')';
    return o;
}

// debug function
void dbg() { cerr << '\n'; }
TP<TN T1, TN... T2>
void dbg(T1 v1, T2... v2) { cerr << v1 << ' ', dbg(v2...); }
