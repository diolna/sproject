#include "test_runner.h"

#include <forward_list>
#include <iterator>
#include <algorithm>


using namespace std;




template <typename Type, typename Hasher>
class HashSet {
public:
  using BucketList = forward_list<Type>;

public:
  explicit HashSet(
      size_t num_buckets,
      const Hasher& hasher = {}
  ) :
  num_buckets_(num_buckets)
  {
	  hasher_.resize(num_buckets_);
	  hash = hasher;

  }

  void Add(const Type& value);
  bool Has(const Type& value) const;
  void Erase(const Type& value);
  const BucketList& GetBucket(const Type& value) const;

private:
  size_t GetIndex(const Type& value,vector<forward_list<Type>>& hasher);
  size_t num_buckets_;
  vector<forward_list<Type>> hasher_;
  size_t count = 0;
  Hasher hash;
};

template<typename Type, typename Hasher>
size_t HashSet<Type, Hasher>::GetIndex(const Type& value,   vector<forward_list<Type>>& hasher ) {

	for(size_t i = 0; i < hasher.size(); ++i) {
		if(hasher.at(i).empty()) {
	 		return i;
		} else if (find(hasher.at(i).begin(), hasher.at(i).end(), value)!= hasher.at(i).end()) {
			size_t res = hasher.size() +1;
			return res;
		}


	}

	if(count = num_buckets_) {
		count = 0;
		++count;
		return 0;
	}else {
	++ count;
	return count;
	}
}



template <typename Type, typename Hasher>
void HashSet<Type, Hasher>::Add(const Type& value){
//size_t index = GetIndex(value, hasher_);
	size_t index = hash(value);
	if(index >= hasher_.size()){
		index = hasher_.size()-1;
	}
		auto it = find(hasher_.at(index).begin(), hasher_.at(index).end(), value);
		if(it == hasher_.at(index).end()) {
			hasher_.at(index).push_front(value);

	}

//	cout << index << " " << endl;
//	if(index!= hasher_.size() + 1) {
//		if( find(hasher_.at(index).begin(), hasher_.at(index).end(), value)
//			== hasher_.at(index).end()) {
//		hasher_.at(index).push_front(value);
//		}
//	}
}

template<typename Type, typename Hasher>
bool HashSet<Type, Hasher>::Has(const Type& value) const {
	size_t index = hash(value);
	if(index >= hasher_.size()) {
		index = hasher_.size() - 1;
	}
		auto it = find(hasher_.at(index).begin(), hasher_.at(index).end(), value);
		if(it == hasher_.at(index).end()) {
			return false;
		} else {
			return true;
		}

//	for(auto& i : hasher_) {
//		if(find(i.begin(), i.end(), value) != i.end()) {
//			return true;
//		}
//
//	}
//	return false;
}

template<typename Type, typename Hasher>
void HashSet<Type, Hasher>::Erase(const Type& value) {
	size_t index = hash(value);
	if(index >= hasher_.size()){
		index = hasher_.size() -1;
	}

	auto it = find(hasher_.at(index).begin(), hasher_.at(index).end(), value);
	if(it!= hasher_.at(index).end()) {
//		for(auto& i : hasher_.at(index)) {
//			cout << i << " ";
//		}
//		cout << endl;
//		cout << "del element = " << *it << endl;

//		if(it == hasher_.at(index).begin()) {
//
//						hasher_.at(index).erase_after(hasher_.at(index).before_begin());
//					} else {


					hasher_.at(index).remove(*it);
//					}
//	for(auto& i : hasher_) {
//		auto it = find(i.begin(), i.end(), value);
//		if(it != i.end()) {
//			if(it == i.begin()) {
//				i.pop_front();
//			} else {
//			i.erase_after(prev(it));
//			}
//		}

	}


}

template<typename Type, typename Hasher>
const forward_list<Type>& HashSet<Type, Hasher>::GetBucket(const Type& value) const {
//		for(auto& i: hasher_){
//			auto it = find(i.begin(), i.end(), value);
//			if(it != i.end()) return i;
//		}
	size_t index = hash(value);
		if(index >= hasher_.size()){
			index = hasher_.size() -1;
		}
		return hasher_.at(index);
}





struct IntHasher {
  size_t operator()(int value) const {
    // Это реальная хеш-функция из libc++, libstdc++.
    // Чтобы она работала хорошо, std::unordered_map
    // использует простые числа для числа бакетов
    return value;
  }
};

struct TestValue {
  int value;

  bool operator==(TestValue other) const {
    return value / 2 == other.value / 2;
  }
};

struct TestValueHasher {
  size_t operator()(TestValue value) const {
    return value.value / 2;
  }
};

void TestSmoke() {
  HashSet<int, IntHasher> hash_set(2);
  hash_set.Add(3);
  hash_set.Add(4);

  ASSERT(hash_set.Has(3));
  ASSERT(hash_set.Has(4));
  ASSERT(!hash_set.Has(5));

  hash_set.Erase(3);

  ASSERT(!hash_set.Has(3));
  ASSERT(hash_set.Has(4));
  ASSERT(!hash_set.Has(5));

  hash_set.Add(3);
  hash_set.Add(5);

  ASSERT(hash_set.Has(3));
  ASSERT(hash_set.Has(4));
  ASSERT(hash_set.Has(5));
}

void TestEmpty() {
  HashSet<int, IntHasher> hash_set(10);
  for (int value = 0; value < 10000; ++value) {
    ASSERT(!hash_set.Has(value));
  }
}

void TestIdempotency() {
  HashSet<int, IntHasher> hash_set(10);
  hash_set.Add(5);
  ASSERT(hash_set.Has(5));
  hash_set.Add(5);
  ASSERT(hash_set.Has(5));
  hash_set.Erase(5);
  ASSERT(!hash_set.Has(5));
  hash_set.Erase(5);
  ASSERT(!hash_set.Has(5));
}

void TestEquivalence() {
  HashSet<TestValue, TestValueHasher> hash_set(10);
  hash_set.Add(TestValue{2});
  hash_set.Add(TestValue{3});

  ASSERT(hash_set.Has(TestValue{2}));
  ASSERT(hash_set.Has(TestValue{3}));

  const auto& bucket = hash_set.GetBucket(TestValue{2});
  const auto& three_bucket = hash_set.GetBucket(TestValue{3});
  ASSERT_EQUAL(&bucket, &three_bucket);

  ASSERT_EQUAL(1, distance(begin(bucket), end(bucket)));
  ASSERT_EQUAL(2, bucket.front().value);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestSmoke);
  RUN_TEST(tr, TestEmpty);
  RUN_TEST(tr, TestIdempotency);
  RUN_TEST(tr, TestEquivalence);
  return 0;
}
