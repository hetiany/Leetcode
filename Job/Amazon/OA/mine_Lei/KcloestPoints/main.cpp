// nlogk
// n;
//The template parameter should be the type of the comparison function
//can't use a function pointers
#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <vector> 
using namespace std;

class Point{
public:
	int x, y;
	Point(int a, int b) : x(a), y(b) {} 
};

//build max root heap
class compare{
public:
	bool operator()(const Point& p, const Point& q){
	return ((p.x * p.x + p.y * p.y) < (q.x * q.x + q.y * q.y));
	}
};

//build max root heap
bool compare2(const Point & p, const Point q){
	return ((p.x * p.x + p.y * p.y) < (q.x * q.x + q.y * q.y));
}

vector<Point> findKCloest(vector<Point> p, int k)
{
	
	auto compare1 = [](Point p, Point q){
		return p.x * p.x + p.y * p.y < q.x * q.x + q.y * q.y;
	};

	//You need to create lambda object, pass it to the template using decltype and also pass it to the constructor.
	//priority_queue < Point, vector<Point>, decltype(compare1) > pq(compare1);//maximum heap
	priority_queue < Point, vector<Point>, compare> pq;
	//priority_queue<Point, std::vector<Point>, function<bool(Point, Point)> > pq(compare2);

	for (int i = 0; i < p.size(); ++i)
	{
		if (i < k)
			pq.push(p[i]);
		else {
			Point temp = pq.top();
			if (p[i].x * p[i].x + p[i].y * p[i].y < temp.x * temp.x + temp.y * temp.y)
			{
				pq.pop();
				pq.push(p[i]);
			}
		}
	}
	
	vector<Point> res;
	while (!pq.empty())
	{
		res.push_back(pq.top());
		pq.pop();
	}
	return res;
}


int main(int argc, char const *argv[])
{
	Point a1(2,3), a2(2,2),a3(3,4), a4(0,0),a5(-1,2);
	vector<Point> p = {a1, a2, a3, a4, a5};
	vector<Point> res = findKCloest(p, 3);

	for (auto i : res)
	{
		cout << i.x << " " << i.y <<"\n";
	}
	return 0;
}