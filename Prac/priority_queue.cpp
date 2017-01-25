// constructing priority queues
#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <vector>         // std::vector
#include <functional>     // std::greater
using namespace std;


class mycomparison {
public:
    mycomparison(const bool& revparam = false) {
      reverse = revparam;
    }

    bool operator()(const int& lhs, const int& rhs) const {
      if (reverse) {
        return lhs > rhs;
      } else {
        return lhs < rhs;
      } 
    }

private:
   bool reverse;
};


int main () {
  int myints[] = {10,60,50,20};

  std::priority_queue<int> first;
  std::priority_queue<int> second(myints,myints + 4);
  std::priority_queue<int, vector<int>, greater<int> > third;
  third.push(5);
  third.push(6);
  third.push(7);

  // using mycomparison:
  typedef std::priority_queue<int, std::vector<int>, mycomparison> mypq_type;

  mypq_type fourth(myints,myints + 4);     // less-than comparison
  mypq_type fifth(myints, myints + 4, mycomparison(true));   // greater-than comparison
  //fifth.push(5);
  //fifth.push(6);
  //fifth.push(7);

  //priority_queue<int, std::vector<int>, mycomparison(true)> sixth(myints,myints + 4);
  

  //cout << "first top" << first.top() << endl;

  cout << "second top： " << second.top() << endl;
  second.pop();
  cout << second.top() << endl;
  //second.pop();
  /*cout << second.top() << endl;
  second.pop();*/

  cout << "third top: " << third.top() << endl;
  cout << "fourth top: " << fourth.top() << endl;
  cout << "fifth top: " << fifth.top() << endl;
  //cout << "sixth top" << sixth.top() << endl;

  return 0;
}