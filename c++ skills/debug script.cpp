void dbg() { cerr << '\n'; }
template <class A, class... B>
void debug(A a, B... b) {
    cerr << a << ' ', debug(b...);
}