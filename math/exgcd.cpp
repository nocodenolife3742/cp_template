pair<int, int> exgcd(int a, int b) {
    if (b == 0)
        return {1, 0};
    pair<int, int> t = exgcd(b, a % b);
    return {t.second, t.first - (a / b) * t.second};
}