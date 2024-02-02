vector<int> dis(vector<int> x) {
    vector<int> ret = x;
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    for (auto &i : ret)
        i = lower_bound(x.begin(), x.end(), i) - x.begin();
    return ret;
}