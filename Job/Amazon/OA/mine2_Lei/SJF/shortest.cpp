//requestTime[]每个request到达处理器的时间，durations[]每个request要处理的持续时间。
//两个数组一一对应，并按requestTime[]从小到大排列
// requestTime[0, 2, 4, 5]
//duration[7, 4, 1, 4] 题目要求，short task first，就是先处理p1，处理之后时间是7，之后处理p4
//因为她处理时间为1，最短，然后p2，最后p5，这个例子average waiting time是4#include <iostream>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

8888922253;
􏰀􏰁􏰂􏰃􏰱􏰲􏰀􏰁􏰳􏰙􏰊􏰑􏰒􏰁􏰓􏰗􏰚􏰴􏰵􏰶􏰷􏰊􏰸􏰗􏰁􏰕􏰹􏰲􏰺 􏰁􏰄􏰋􏰊􏰻􏰼􏰽􏰄􏰂􏰃􏰛􏰾􏰿􏰗􏰁􏰕􏰧􏱀􏱁􏰲􏰼􏰽􏱂􏰓􏰊􏱃􏱄􏱅􏱆􏱇 􏰁􏱈􏱉􏰻􏰀􏰁􏱊􏰕􏰛
􏰀􏰁􏰂􏰃􏰱􏰲􏰀􏰁􏰳􏰙􏰊􏰑􏰒􏰁􏰓􏰗􏰚􏰴􏰵􏰶􏰷􏰊􏰸􏰗􏰁􏰕􏰹􏰲􏰺 􏰁􏰄􏰋􏰊􏰻􏰼􏰽􏰄􏰂􏰃􏰛􏰾􏰿􏰗􏰁􏰕􏰧􏱀􏱁􏰲􏰼􏰽􏱂􏰓􏰊􏱃􏱄􏱅􏱆􏱇 􏰁􏱈􏱉􏰻􏰀􏰁􏱊􏰕􏰛
􏰀􏰁􏰂􏰃􏰀􏰁􏰂􏰃

class Process {
public:
	int arrTime;
	int excTime;
	Process(int x, int y){
		arrTime = x;
		excTime = y;
	}
};
struct compare{
	bool operator()(const Process* p, const Process* q) {
		//return p -> excTime > q -> excTime;
		if (p -> excTime > q->excTime)
		 	return 1;
		else if (p -> excTime == q -> excTime)
			return p->arrTime > q ->arrTime;
		return 0;
	}
};

float SJFaverage(int* request, int* duration, int n) {
	if (n <= 0 ) return 0;
	int curTime = 0;
	int waitTime = 0;
	int proIdx = 0;
	priority_queue<Process*, vector<Process*>, compare> pq;
	while (proIdx < n || !pq.empty()) {
		if (pq.empty()) {
			Process *tmp = new Process (request[proIdx], duration[proIdx]);
			curTime = request[proIdx++];
			pq.push(tmp);
		}
		Process* pro = pq.top();
		pq.pop();
		waitTime += curTime - pro -> arrTime;
		curTime += pro -> excTime;
		delete pro;
		for (int i = proIdx; i < n; ++i) {
			if(request[i] <= curTime) {
				pq.push(new Process (request[proIdx], duration[proIdx]));
				proIdx++;
			} else {
				break;
			}
		}

	}
	return float(waitTime) / n;
}

	int main(int argc, char const *argv[])
{
		int arrival1[] = {0,2, 4, 5};
		int run1[] = {7,4, 1, 4};
		int arrival2[] = {0, 1, 3, 9};
		int run2[] = {2, 1, 7, 5};
		cout << SJFaverage(arrival1, run1, 4);
		return 0;
	}











