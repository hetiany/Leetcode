#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <vector> 
using namespace std;
class Point  {
public:
	double x, y;
	Point(double a, double b) : x(a), y(b) {} 
};
//can specify it with a static funtion;
//standard forbids, static function only access the static member, the content of Point is 
//differ from each other, can't use static function to overload
struct compare {//max heap
	bool operator() (const Point & p, const Point & q) {
		return p.x * p.x + p.y * p.y < q.x * q.x + q.y * q.y;
	}
};
vector<Point> findKCloest(vector<Point> p, int k) {
	int len = p.size();
	vector<Point> res;
	priority_queue <Point, vector<Point>, compare> pq;
	int i = 0;
	for (; i < k; ++i)
		pq.push(p[i]);
	compare c;
	while (i < len) {
		Point temp = pq.top();
		//if (p[i].x * p[i].x + p[i].y * p[i].y < temp.x * temp.x + temp.y * temp.y) {
		if (c.operator()(p[i], temp)) {//if p[i] < temp; push to the pq;
				pq.pop();
				pq.push(p[i]);
		}
		++i;
	}
	while (!pq.empty()) {
		res.push_back (pq.top());
		pq.pop();
	}
	return res;
}

int main(int argc, char const *argv[])
{
	Point a1(1.1,1.1), a2(1.0,1.2),a3(0,2), a4(10,0),a5(-1,2);
	vector<Point> p = {a1, a2, a3, a4, a5};
	vector<Point> res = findKCloest(p, 1);
	for (auto i : res)
	{
		cout << i.x << " "<< i.y <<"\n";
	}
	return 0;
}