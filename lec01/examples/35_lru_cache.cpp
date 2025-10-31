#include <iostream>
#include <list>
#include <unordered_map>
#include <utility>
#include <string>
/*
Minimal LRU cache with std::list + std::unordered_map.
Shows moving list nodes to front on access and erase by iterator on eviction.
*/
using namespace std;

template <typename Key, typename Value>
class LruCache {
 public:
  explicit LruCache(size_t capacity) : capacity_(capacity) {}

  bool get(const Key& k, Value& out) {
    auto it = key_to_it_.find(k);
    if (it == key_to_it_.end()) return false;
    // Move node to front (most recently used)
    items_.splice(items_.begin(), items_, it->second);
    out = it->second->second;
    return true;
  }

  void put(const Key& k, const Value& v) {
    auto it = key_to_it_.find(k);
    if (it != key_to_it_.end()) {
      it->second->second = v;
      items_.splice(items_.begin(), items_, it->second);
      return;
    }
    items_.emplace_front(k, v);
    key_to_it_[k] = items_.begin();
    if (items_.size() > capacity_) {
      // erase least recently used (back)
      auto last = prev(items_.end());
      key_to_it_.erase(last->first);
      items_.erase(last); // erase by iterator
    }
  }

 private:
  size_t capacity_;
  list<pair<Key, Value>> items_;
  unordered_map<Key, typename list<pair<Key, Value>>::iterator> key_to_it_;
};

int main() {
  LruCache<string, int> cache(2);
  cache.put("a", 1);
  cache.put("b", 2);

  int x;
  if (cache.get("a", x)) cout << x << '\n'; // 1, a becomes MRU
  cache.put("c", 3); // evicts b (LRU)

  cout << boolalpha;
  cout << (cache.get("b", x)) << '\n'; // false
  cout << (cache.get("a", x) && x == 1) << '\n'; // true
  cout << (cache.get("c", x) && x == 3) << '\n'; // true
  return 0;
}


