#pragma once


#include <mutex>
#include <memory>
#include <list>
#include <chrono>
#include <unordered_map>

namespace shudao {
namespace lib {


template <typename K, typename V>
class ExpireLRUCache {
 private:
  using Timestamp = std::chrono::time_point<std::chrono::system_clock>;
  struct Node {
    K key;
    V value;
    Timestamp timestamp;
  };

 public:
  using NodePtr = std::shared_ptr<Node>;
  using NodeIter = typename std::list<NodePtr>::iterator;
  using ExpiredCallBack = std::function<void(K, V)>;

  // Default timeout is 3000ms.
  ExpireLRUCache(size_t max_size)
     : max_size_(max_size), time_out_(3000), expired_callback_(nullptr) {}

  ExpireLRUCache(size_t max_size, uint32_t time_out, ExpiredCallBack call_back)
     : max_size_(max_size), time_out_(time_out), expired_callback_(call_back) {}

  void Add(K key, V value);
  V Get(K key);

  size_t Size() const;

 private:
  void Expired();

  mutable std::mutex mutex_;
  std::list<NodePtr> list_;
  std::unordered_map<K, NodeIter> map_;

  size_t max_size_;
  // ms
  uint32_t time_out_;

  ExpiredCallBack expired_callback_;
};

template <typename K, typename V>
void ExpireLRUCache<K, V>::Add(K key, V value) {
  std::lock_guard<std::mutex> lock(mutex_);
  // if full, delete oldest
  if (list_.size() >= max_size_) {
    auto oldest = list_.back();
    list_.pop_back();
    map_.erase(oldest->key);
  }

  // if exist, delete it in the list, and then add to the front
  // then overwrite in map.
  if (map_.find(key) != map_.end()) {
    NodeIter iter = map_[key];
    list_.erase(iter);
  }

  auto timestamp = std::chrono::system_clock::now();
  NodePtr node = std::make_shared<Node>(Node{key, value, timestamp});
  list_.push_front(node);
  map_[key] = list_.begin();
}

template <typename K, typename V>
V ExpireLRUCache<K, V>::Get(K key) {
  std::lock_guard<std::mutex> lock(mutex_);

  // Todo(zero): how to call
  Expired();

  if (map_.find(key) != map_.end()) {
    return (*map_[key])->value;
  } else {
    return V{};
  }
}

template <typename K, typename V>
void ExpireLRUCache<K, V>::Expired() {
  auto time_now = std::chrono::system_clock::now();

  while( !list_.empty() ) {
    auto oldest = list_.back();
    auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(
                    time_now - oldest->timestamp);
    if (diff.count() > time_out_) {
      list_.pop_back();
      map_.erase(oldest->key);
      expired_callback_(oldest->key, oldest->value);
    } else {
      break;
    }
  }
}

template <typename K, typename V>
size_t ExpireLRUCache<K, V>::Size() const {
  std::lock_guard<std::mutex> lock(mutex_);
  return map_.size();
}


}  // namespace lib
}  // namespace shudao