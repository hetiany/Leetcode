#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <vector> 
using namespace std;
class Point{
public:
	int x, y;
	Point(int a, int b) : x(a), y(b) {} 
};
bool operator<=(const Point& p, const Point& q)
{
	return ((p.x * p.x + p.y * p.y) <= (q.x * q.x + q.y * q.y));
}
bool operator>=(const Point& p, const Point& q)
{
	return ((p.x * p.x + p.y * p.y) >= (q.x * q.x + q.y * q.y));
}

void swap(Point& p,  Point& q)
{
	swap(p.x, q.x);
	swap(p.y, q.y);
	return;
}

int partition(vector<Point>& p, int left, int right)
{
	Point pivot = p[left];
	int l = left + 1, r = right;
	while (l <= r)
	{
		while (l <= r && p[l] <= pivot) ++l;
		while (l <= r && p[r] >= pivot) --r;
		if (l <= r)
			swap(p[l++], p[r--]);
	}
	swap(p[left], p[r]);
	return r;
}

vector<Point> findKCloest(vector<Point>& p, int k)
{
	int left = 0, right = p.size() - 1;
	while (true)
	{
		int pos = partition(p, left, right);
		if (pos == k - 1) { return vector<Point>(p.begin(), p.begin() + k);}
		if (pos > k - 1) right = pos - 1;
		else left = pos + 1;
	}
}

int main(int argc, char const *argv[])
{
	Point a1(2,2), a2(2,2),a3(3,4), a4(0,0), a5(-1,2);
	//for (int i = 0; i < 5; ++i) {
	vector<Point> p;
	p.push_back(a1);
	p.push_back(a2);
	p.push_back(a3);
	p.push_back(a4);
	p.push_back(a5);
	//vector<Point> p = {a1, a2, a3, a4, a5};
	vector<Point> res = findKCloest(p, 5);
	reverse(res.begin(), res.end());
	for (vector<Point> :: iterator i = res.begin(); i != res.end(); ++i)
	{
		cout << (*i).x << (*i).y <<"\n";
	}
	return 0;
}