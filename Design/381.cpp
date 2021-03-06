//my code, compile error
class RandomizedCollection {
public:
    unordered_multimap<int, int> record;
    vector<int> store;
    
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        if(record.find(val) == record.end()) {
            store.push_back(val);
            record[val] = store.size() - 1;
            return true;
        } else {
            store.push_back(val);
            record[val] = store.size() - 1;
            return false;
        }
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(record.find(val) == record.end()) {
            return false;
        }
        int index = record[val];
        store[index] = store[store.size() - 1];
        record[store[index]] = index;
        store.pop_back();
        record.erase(record.find(val));
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int count = store.size();
        return store[rand() % count];
    }
};


//Find online
class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        int count = map.count(val);
        map.insert(make_pair(val, elements.size()));
        elements.push_back(val);
        
        return !count;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto inSet = map.find(val);
        
        if(inSet != map.end()){
            int pos = map.find(val) -> second;
            map.erase(map.find(val));
            
            int last = elements.back(); 
            elements.pop_back();
            elements[pos] = last;
            
            for(auto findPos = map.find(last); findPos != map.end(); ++findPos) {
                if(findPos -> second == elements.size()) {
                    map.erase(findPos);
                    map.insert( make_pair(last, pos));
                    break;
                }
            }
        }
        
        return inSet != map.end();
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int pos = rand() % elements.size();
        return elements[pos];
    }
    
private:
    unordered_multimap<int, int> map;
    vector<int> elements;
};

