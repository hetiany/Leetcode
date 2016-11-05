template <typename K, typename V>
class HashNode {
public:
    HashNode(const K &key, const V &value) :
    key(key), value(value), next(NULL) {
    }
 
    K getKey() const {
        return key;
    }
 
    V getValue() const {
        return value;
    }
 
    void setValue(V value) {
        HashNode::value = value;
    }
 
    HashNode *getNext() const {
        return next;
    }
 
    void setNext(HashNode *next) {
        HashNode::next = next;
    }
 
private:
    // key-value pair
    K key;
    V value;
    // next bucket with the same key
    HashNode *next;
};


template <class K, class V, class F = KeyHash<K>> 
class HashMap {
public:
	HashMap() {
		table = new HashNode< K, V> *[TABLE_SIZE]();                  
	}                                                                 
	~HashMap() {                                                        
		for (int i = 0; i < TABLE_SIZE; ++i) {
			HashNode<K, V> *entry = table[i];
			while (entry != NULL) {
				HashNode <K, V> * prev = entry;
				entry = entry -> getNext();
				delete prev;
			}
			table[i] = NULL;
		}
		delete [] table;
	}

	bool get(const K & key, V & value) {
		unsigned long hashValue = hashFunc(key);
		HashNode<K, V> * entry = table[hashValue];
		while (entry != NULL){
			if(entry -> getKey() == key) {
				value = entry -> getValue;
				return true;
			}
			entry = entry -> getNext();
		}
		return false;
	}

	void put (const K & key, const V &value) {
		unsigned long hashValue = hashFunc(key);
		HashNode<K, V> * prev = NULL;
		HashNode<k, V> * entry = table[hashValue];
		while (entry != NULL && entry -> getKey() != key){
			prev = entry;
			entry = entry -> getNext();
		}
		if(entry == NULL) {
			entry = new HashNode<K,V>(key, value);
			if (prev == NULL)
				table[hashValue] = entry;
			else 
				prev -> setNext(entry);
		} else {
			entry -> setValue(value);
		}
	}

	void remove(const K & key) {
		unsigned long hashValue = hashFunc(key);
		HashNode<K, V> * prev = NULL;
		HashNode<k, V> * entry = table[hashValue];
		while (entry != NULL && entry -> getKey() != key){
			prev = entry;
			entry = entry -> getNext();
		}
		if(entry == NULL) {
			return;
		} else {
			if(prev == NULL)
				table[hashValue] = entry -> getNext();
		 	else 
				prev -> setValue(entry -> getNext());
			delete entry;
		}
	}

private:
	HashNode<K, V> ** table;
	F hashFunc;
};



table = new int*[50]();  myMap = new hashmap<k, v, f>();  HashMap<string, int> mpMap; 

hashMap<string, int> mp;


string, int<
hashnode<string, int>


int 
unordered_map

template<class k>
struct {
    k value;
    k val;
} struction;

struction <string, int>

aa -> 5  bb -> 6
aa -> 1000
bb -> 1000
table[1000] pointer -> (aa, 5)  (bb, 6)

        
        |------   |
1000    |         |
        |         |
        | &(aa/5) | ---->  bb/ 6
        |------   |
1001cla
        |zxxs / 5
        
        
1000   |  &{aa , 5} |  ->   -> {bb, 6}


"abcXducXada"
getline
vector<string> store{"abc", "duc", "ada"};

 while (std::getline(ss, item, delim)) {
         elems.push_back(item);
    }
}


