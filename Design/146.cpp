//Lei
class LRUCache{
public:
     void touch(unordered_map<int, pair<int, list<int> :: iterator> > :: iterator it) {
        int key = it -> first;
        table.erase(it -> second.second);
        table.push_front(key);
        it -> second.second = table.begin();
    }
    
    LRUCache(int capacity) {
        // write your code here
        _capacity = capacity;
    }
    
    int get(int key) {
        if (cache.count(key)) {
			touch(cache.find(key));
			return cache[key].first;
		}
		return -1;
    }
    
    void set(int key, int value) {
        auto itr = cache.find(key);
		if (itr != cache.end()){
			touch(itr);
			itr->second.first = value;
		} else {
			if (_capacity == cache.size()) {
				cache.erase(table.back());
				table.pop_back();
			}
			table.push_front(key);
			cache[key] = make_pair(value, table.begin());
		}
    }
    
private:
    private:
    int _capacity;
    list<int> table;
    unordered_map < int, pair<int, std::list<int> :: iterator > > cache;
};

fasdfadf
//***************************  Lei, codepair ************************//

[1, value2], [2, value2] , 4, 3, 2, 1, 2, 1, 4

3
[1, value2], [2, value2], [4, value2]
2 4 3
4 3 2


3 2 1
3 1 2
3 2 1
2 1 4

class LRUCache{
private:
    int _capacity;
    list<int> table; // data : 1,2,3,4; 
    unordered_map < int, pair<int, std::list<int> :: iterator > > cache;  // key: data;          value : <key: value2;  value : pointer>
    
    
public:

    void touch(unordered_map<int, pair<int, list<int> :: iterator> > :: iterator it) {
        int key = it -> first; //data; 2, 4, 1;
        table.erase(it -> second.second);
        table.push_front(key);
        it -> second.second = table.begin();
    }
    
    LRUCache(int capacity) {
        // write your code here
        _capacity = capacity;
    }
    
    int get(int key) {
        if (cache.count(key)) {
            touch(cache.find(key));
            return cache[key].first;
        }
        return -1;
    }
    
    void set(int key, int value) {
        auto itr = cache.find(key);
        if (itr != cache.end()){
            touch(itr);
            itr->second.first = value;
        } else {
            if (_capacity == cache.size()) {
                cache.erase(table.back());
                table.pop_back();
            }
            table.push_front(key);
            cache[key] = make_pair(value, table.begin());
        }
    }
    
   
    

};

(data ; index)
  
  mp<data,index>
  1, 1,
  2, 2,
  3, 3,
 
  4
  
  new ------------ old
