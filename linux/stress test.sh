for ((i = 1; ; ++i)); do
    ./gen > t
    diff -w <(./code < t) <(./hack < t) || break
done
