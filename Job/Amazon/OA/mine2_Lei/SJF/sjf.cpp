//requestTime[]每个request到达处理器的时间，durations[]每个request要处理的持续时间。
//两个数组一一对应，并按requestTime[]从小到大排列
// requestTime[0, 2, 4, 5]
//duration[7, 4, 1, 4] 题目要求，short task first，就是先处理p1，处理之后时间是7，之后处理p4
//因为她处理时间为1，最短，然后p2，最后p5，这个例子average waiting time是4
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Process {
public:
	int arrTime;
	int excTime;
	Process(int x, int y){
		arrTime = x;
		excTime = y;
	}
};
struct compare {
	bool operator()(const Process* p, const Process* q){
		return p -> excTime > q -> excTime;
	}
};
float SJFaverage(vector<int> request, vector<int> duration) {
	if (request.size() == 0 || request.size() != duration.size())
		return 0;
	priority_queue <Process*, vector<Process*>, compare> pq;
	//priority_queue
	int waitTime = 0;
	int curTime = 0;
	int len = request.size();
	int proIdx = 0;
	while (!pq.empty() || proIdx < len)
	{
		if (pq.empty())
		{
			pq.push (new Process(request[proIdx], duration[proIdx]));
			curTime += request[proIdx++];
		}
		Process* curPro = pq.top();
		pq.pop();
		waitTime += curTime - curPro -> arrTime;
		curTime += curPro -> excTime;
		delete curPro;
		for (int i = proIdx; i < len && request[i] <= curTime; ++i, ++proIdx)
			pq.push (new Process (request[proIdx], duration[proIdx]));
	}
	return (float)waitTime/ len;
}

	int main(int argc, char const *argv[])
{
		vector<int> arrival1 = {0,2, 4, 5};
		vector<int> run1 = {7,4, 1, 4};
		int q1 = 3;
		vector<int> arrival2 = {0, 1, 3, 9};
		vector<int> run2 = {2, 1, 7, 5};
		int q2 = 2;
		cout << SJFaverage(arrival1, run1);
		return 0;
	}



