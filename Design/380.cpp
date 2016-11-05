//Find online
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (map.find(val) != map.end()) return false;
        tmp.push_back(val);
        map[val] = tmp.size() - 1;          //index of val in vector tmp
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (map.find(val) == map.end()) return false;
        int indx = map[val];                //index of val in vector tmp
        tmp[indx] = tmp[tmp.size() - 1];    //replace val with the last element in the vector
        map[tmp[indx]] = indx;              //update the vector index (stored in hashmap) of that element 
        tmp.pop_back();
        map.erase(map.find(val));
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return tmp[rand() % tmp.size()];
    }
    
private:
    vector<int> tmp;
    unordered_map<int, int> map;
};