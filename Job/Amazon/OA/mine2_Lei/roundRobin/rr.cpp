//效率最大化 给了arrive time 和excute time 求最高效的执行最多的任务
//RTOS执行process分配的问题
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
	int curTime = 0;
	int waitTime = 0;
	int proIdx = 0;
	queue<Process*> que;
	while (proIdx < len || !que.empty()) {
		if (que.empty()) {
			Process * tmp = new Process(arrival[proIdx], run[proIdx]);
			curTime = arrival[proIdx++];
			que.push(tmp);
		}
		Process* cur = que.front();
		que.pop();
		waitTime += curTime - cur -> arriveTime;
		curTime += min (q, cur -> excuteTime);
		//push the process which arrive in this round
		for (int i = proIdx; i < len && arrival[i] <= curTime; ++i, ++ proIdx) {
			que.push(new Process (arrival[i], run[i]));
		}
		// repush to the new process to the queue must follow the arrival process;
		if (cur -> excuteTime > q) {
			cur -> arriveTime = curTime;//change the arrivetime
			cur -> excuteTime -= q;//change the excutime;
			que.push(cur);
		} else {
			delete cur;
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
		cout << waitingTimeRobin(arrival2, run2, 4, q2);
		return 0;
}