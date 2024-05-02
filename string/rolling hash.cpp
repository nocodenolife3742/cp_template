// double hash version
namespace hs {
    int m = 1e9 + 7;
    int b1 = 999999937; // 999999893, 999999797
    int b2 = 999999929; // 999999883, 999999761
    vector<int> p1 = {1};
    vector<int> p2 = {1};
    struct poly_hash {
        vector<int> h1 = {0}, h2 = {0};
        template <typename T>
        poly_hash(vector<T> arr) {
            while (p1.size() < arr.size()) {
                p1.emplace_back((int64_t(p1.back()) * b1) % m);
                p2.emplace_back((int64_t(p2.back()) * b2) % m);
            }
            for (int i = 0; i < arr.size(); i++) {
                h1.emplace_back((int64_t(h1.back()) * b1 + arr[i]) % m);
                h2.emplace_back((int64_t(h2.back()) * b2 + arr[i]) % m);
            }
        }
        poly_hash(string s) : poly_hash(vector<int>(s.begin(), s.end())) {}
        pair<int, int> operator()(int l, int r) { // [l, r]
            int val1 = (h1[r + 1] - int64_t(h1[l]) * p1[r - l + 1]) % m;
            int val2 = (h2[r + 1] - int64_t(h2[l]) * p2[r - l + 1]) % m;
            return {val1 < 0 ? val1 + m : val1, val2 < 0 ? val2 + m : val2};
        }
    };
}

// min version
struct ph {
    int m = 1e9 + 7, b = 999999937;
    vector<int> p{1}, h{0};
    ph(vector<int> arr) {
        for (int i = 0; i < arr.size(); i++) {
            p.push_back((int64_t(p[i]) * b) % m);
            h.push_back((int64_t(h[i]) * b + arr[i]) % m);
        }
    }
    ph(string s) : ph(vector<int>(s.begin(), s.end())) {}
    int operator()(int l, int r) { // [l, r]
        return ((h[r + 1] - int64_t(h[l]) * p[r - l + 1]) % m + m) % m;
    }
};