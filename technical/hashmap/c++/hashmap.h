#include <vector>
#include <string>

static const size_t MIN_CAPACITY = 4;
static const double UPPER_LOAD_FACTOR = 0.75;
static const double LOWER_LOAD_FACTOR= 0.25;

template <typename Value>
class HashMap {
private:
  struct bucket {
    std::string key;
    Value value;
    bucket() {}
    bucket(const std::string& k, const Value& v): key(k), value(v) {}
  };
  bucket* buckets;
  size_t len;
  size_t capacity;
  double load;
  bool* valid;
  std::hash<std::string> hasher;
  // compressess a hashvalue to the space [0, N-1]
  size_t compressor(size_t hashvalue) const {return hashvalue % capacity;}
  // update the load factor for the table
  void updateLoad() {
    load = (double)len / (double)capacity;
  }
  // grow the hashtable and rehash all of the items to the new table.
  // expensive operation with O(N) runtime and O(N) space
  void rehashTo(size_t next_capacity) {
    size_t old_capacity = capacity;
    capacity = next_capacity;
    bucket* old_buckets = buckets; // save current buckets
    bool* old_valid = valid;
    // blank slate buckets with next_capacity space
    buckets = new bucket[next_capacity];
    // blank slate valid with next_capacity space
    valid = new bool[next_capacity];
    for(int i = 0; i < capacity; i++) {
      valid[i] = true;
    }
    load = 0; // reset load
    // insert everything from old_buckets into new
    for(int i = 0; i < old_capacity; i++) {
      if(!old_valid[i]) {
        put(old_buckets[i].key, old_buckets[i].value);
      }
    }
    //deallocate old_buckets
    delete[] old_buckets;
    delete[] old_valid;
  }
public:
  HashMap(): buckets(new bucket[MIN_CAPACITY]), len(0), capacity(MIN_CAPACITY), valid(new bool[MIN_CAPACITY]) {
    for(size_t i = 0; i < MIN_CAPACITY; i++) {
      valid[i] = true;
    }
    updateLoad();
  }
  ~HashMap() {
    // deallocate buckets
    delete[] buckets;
  }
  void put(const std::string& k, const Value& v) {
    size_t offset = 0;
    size_t index = compressor(hasher(k) + offset);
    // resolve collisions if they exist
    while(!valid[index]) { 
      if(buckets[index].key == k) { 
        // an entry for this key already exists. update it's value
        buckets[index].value = v;
        return;
      } else {
        index = compressor(index + (offset <<= 1));
      }
    }
    valid[index] = false; // reserve this spot
    buckets[index] = bucket(k, v); // fill this spot
    len++;
    updateLoad();
    if(load > UPPER_LOAD_FACTOR) {
      rehashTo(capacity*2);
    }
  }
  Value get(const std::string& k) const {
    size_t offset = 0;
    size_t index = compressor(hasher(k) + offset);
    while(!valid[index]) {
      if(buckets[index].key == k) {
        return buckets[index].value;
      } else {
        index = compressor(index + (offset <<= 1));
      }
    }
    // hashed to spot where no value exists. key k doesn't have a value.
    throw "key does not exist";
  }
  bool find(const std::string& k) const {
    size_t offset = 0;
    size_t index = compressor(hasher(k) + offset);
    while(!valid[index]) {
      if(buckets[index].key == k) {
        return true;
      } else {
        index = compressor(index + (offset <<= 1));
      }
    }
    return false;
  }
  void del(const std::string& k) {
    size_t offset = 0;
    size_t index = compressor(hasher(k) + offset);
    while(!valid[index]) { 
      if(buckets[index].key == k) { 
        // let subsequent puts override this data.
        valid[index] = true; 
        len--;
        return;
      } else {
        index = compressor(index + (offset <<= 1));
      }
    }
    
    updateLoad();
    if(load < LOWER_LOAD_FACTOR && len != 0) {
      rehashTo(capacity >>= 1);
    }
  }
  size_t size() {return len;}
};