class LRUCache {
  
  std::unordered_map<int, std::pair<int,std::list<int>::iterator>> key_to_value_and_iterator;
  std::list<int> list_of_keys;
  size_t sz;
  public:
  LRUCache(int capacity): sz(capacity) {}

  int get(int key) {
    if(key_to_value_and_iterator.count(key) == 0){
      return -1;
    }
    const auto [value,it] = key_to_value_and_iterator[key];
    list_of_keys.erase(it);
    list_of_keys.push_front(key);
    key_to_value_and_iterator[key].second = list_of_keys.begin();
    return  value;
  }

  void put(int key, int value) {
    if(key_to_value_and_iterator.size()  == sz &&  key_to_value_and_iterator.count(key) == 0){
      key_to_value_and_iterator.erase(list_of_keys.back());
      list_of_keys.pop_back();

    } else if(key_to_value_and_iterator.count(key) != 0){
      list_of_keys.erase(key_to_value_and_iterator[key].second);
    }
    list_of_keys.push_front(key);
    key_to_value_and_iterator[key] = std::make_pair(value,list_of_keys.begin());
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
