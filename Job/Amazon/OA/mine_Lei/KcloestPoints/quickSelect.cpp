#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <vector> 
using namespace std;
class Point {
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

int partition(vector<Point>& p, int left, int right)
{
		int l = left + 1, r = right;
		Point pivot = p[left];
		while (l <= r) {
			while (l <= r && p[l] <= pivot) ++l;
			while (l <= r && p[r] >= pivot) --r;
			if (l <= r) {
				swap (p[l++], p[r--]);
			} 
		}
		swap (p[left], p[r]);//shouldn't be pivot
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













