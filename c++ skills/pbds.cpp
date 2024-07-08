// 若 include 過 bits/extc++.h ，下⾯不需要再 include 其他標頭檔
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

// hash_table：可以當作 unordered_map 使⽤
#include <ext/pb_ds/hash_policy.hpp>
gp_hash_table<int, int> m; // usually faster
cc_hash_table<int, int> m;

// trie：字典樹
#include <ext/pb_ds/trie_policy.hpp>
trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> t;
// special operations
t.join(another trie) // 合併另⼀個 trie 到⾃⼰
t.split(string, another trie) // 分割⼤於 string 的部分到另⼀個 trie
t.prefix_range(string) // 取得前缀為 string 的 iterator，型態是 pair [begin, end)

// tree：平衡樹
#include <ext/pb_ds/tree_policy.hpp>
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> t;
// special operations
t.join(another tree) // 合併另⼀個 tree 到⾃⼰
t.split(value, another tree) // 分割⼤於 value 的部分到另⼀個 tree
t.find_by_order(k) // 取得第 k 個的 iterator
t.order_of_key(value) // 取得 value 在 tree 中的位置
