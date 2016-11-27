#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Process {
	public:
           int arriveTime;
           int excuteTime;
           Process(int arr, int exc) {
                arriveTime = arr;
                excuteTime = exc;
           }
};

float waitingTimeRobin(int * arrival, int* run, int len, int q) {
	if (len <= 0) return 0;
	queue <Process>  que;
	int waitTime = 0, curTime = 0;
	int nextProIdx = 0;
	while (!que.empty() || nextProIdx < len) {
		if (que.empty()) {
			que.push(Process(arrival[nextProIdx], run[nextProIdx]));
			curTime = arrival[nextProIdx ++];
		}
		Process cur = que.front();
		waitTime += curTime - cur.arriveTime;
		curTime += min(q, cur.excuteTime);
		que.pop();
		for (int i = nextProIdx; i < len && arrival[i] <= curTime; ++i, ++ nextProIdx)
			que.push(Process(arrival[i], run[i]));
		if (cur.excuteTime > q) {
			que.push(Process (curTime, cur.excuteTime - q));
		}
	}
	return (float) waitTime / len;
}
int main(int argc, char const *argv[])
{
		int arrival1[] = {0, 1, 4};
		int run1[] = {5, 2, 3};
		int q1 = 3;
		int arrival2[] = {0, 1, 3, 9};
		int run2[] = {2, 1, 7, 5};
		int q2 = 2;
		cout << waitingTimeRobin(arrival1, run1, 3, q2);
		return 0;
}