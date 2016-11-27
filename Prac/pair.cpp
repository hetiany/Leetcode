/*
#include <iostream>
#include <unordered_map>
#include <utility>
using namespace std;


int main() {
	//unordered_map<pair<int, int>, int> record;
	unordered_map<int, pair<int, int> > record;
	//pair<int, int> boo = make_pair(1, 1);
	//pair<int, int> foo =  make_pair(2, 2);

	//record[boo] = 10;
	//record[foo] = 20;
	//cout << record[boo] << " " << record[foo] << endl;
	return 0;
}
*/

#include <map>
#include <string>
#include <iostream>
using namespace std;

class Key {
public: 
    Key(string s, int i) {
      this -> s = s;
      this -> i = i;
    }
    bool operator< (const Key& k) const {
      int s_cmp = this -> s.compare(k.s);
      if(s_cmp == 0) {
        return this -> i < k.i;
      }
      return s_cmp < 0;
    }
//private:
	string s;
    int i;
};

int main() {
  Key p1 ("Apple", 45);
  Key p2 ("Berry", 20);

  map<Key, string> mapa;

  mapa[p1] = "Manzana";
  mapa[p2] = "Arandano";

  cout << mapa.begin() -> second << endl;
  cout << (++mapa.begin()) -> second << endl; 

  // printf("mapa[%s,%d] --> %s\n",
  //   p1.s.c_str(),p1.i,mapa.begin()->second.c_str());
  // printf("mapa[%s,%d] --> %s\n",
  //   p2.s.c_str(),p2.i,(++mapa.begin())->second.c_str());

  return 0;
}


