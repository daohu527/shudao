#include <string>
#include <thread>

#include "gtest/gtest.h"
#include "lib/expire_lru_cache.h"

namespace shudao {
namespace lib {


TEST(AddTest, Add) {
  ExpireLRUCache<int, std::string> cache(5);
  cache.Add(1, "aaa");
  EXPECT_EQ(cache.Get(1), "aaa");
  cache.Add(2, "bbb");
  EXPECT_EQ(cache.Get(1), "aaa");
  EXPECT_EQ(cache.Get(2), "bbb");

  cache.Add(1, "ccc");
  EXPECT_EQ(cache.Get(1), "ccc");

  EXPECT_EQ(cache.Size(), 2);
}

TEST(AddFullTest, AddFull) {
  ExpireLRUCache<int, std::string> cache(5);
  cache.Add(1, "aaa");
  cache.Add(2, "bbb");
  cache.Add(3, "ccc");
  cache.Add(4, "ddd");
  cache.Add(5, "eee");
  cache.Add(6, "fff");
  EXPECT_EQ(cache.Size(), 5);

  EXPECT_EQ(cache.Get(1), "");
  EXPECT_EQ(cache.Get(2), "bbb");
  EXPECT_EQ(cache.Get(3), "ccc");
  EXPECT_EQ(cache.Get(4), "ddd");
  EXPECT_EQ(cache.Get(5), "eee");
  EXPECT_EQ(cache.Get(6), "fff");
}

TEST(GetTest, Get) {
  ExpireLRUCache<int, std::string> cache(5);
  cache.Add(1, "aaa");
  cache.Add(2, "bbb");

  EXPECT_EQ(cache.Get(1), "aaa");
  EXPECT_EQ(cache.Get(2), "bbb");
  EXPECT_EQ(cache.Get(5), "");
}

TEST(ExpireTest, Expire) {
  ExpireLRUCache<int, std::string> cache(5, 10, [] (int, std::string){});
  cache.Add(1, "aaa");
  EXPECT_EQ(cache.Get(1), "aaa");
  std::this_thread::sleep_for(std::chrono::milliseconds(15));
  EXPECT_EQ(cache.Get(1), "");
  EXPECT_EQ(cache.Size(), 0);
}

TEST(ExpireOldestTest, ExpireOldest) {
  ExpireLRUCache<int, std::string> cache(5, 10, [] (int, std::string){});
  cache.Add(1, "aaa");
  cache.Add(2, "bbb");

  EXPECT_EQ(cache.Get(1), "aaa");
  EXPECT_EQ(cache.Get(2), "bbb");
  std::this_thread::sleep_for(std::chrono::milliseconds(9));
  EXPECT_EQ(cache.Get(1), "aaa");
  EXPECT_EQ(cache.Get(2), "bbb");
  EXPECT_EQ(cache.Get(3), "");

  cache.Add(2, "nnn");
  cache.Add(3, "ccc");
  std::this_thread::sleep_for(std::chrono::milliseconds(2));
  EXPECT_EQ(cache.Get(1), "");
  EXPECT_EQ(cache.Get(2), "nnn");
  EXPECT_EQ(cache.Get(3), "ccc");
}

TEST(ExpireCallbackTest, ExpireCallback) {
  int key = 0;
  std::string value;
  ExpireLRUCache<int, std::string> cache(5, 10,
    [&] (int k, std::string v){
      key = k;
      value = v;
    });
  cache.Add(1, "aaa");
  EXPECT_EQ(cache.Get(1), "aaa");
  EXPECT_EQ(cache.Size(), 1);
  std::this_thread::sleep_for(std::chrono::milliseconds(15));
  EXPECT_EQ(cache.Get(1), "");
  EXPECT_EQ(key, 1);
  EXPECT_EQ(value, "aaa");
}


}  // namespace lib
}  // namespace shudao
