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

float waitingTimeRobin(vector<int> arrival, vector<int> run, int q)
{
	if (arrival.size() == 0 || arrival.size() != run.size())
		return 0;
	//use queue to store process; FIFO
	queue <Process*> que;
	int num = arrival.size();
	int curTime = 0;
	int waitTime = 0;
	//use a int type variable to track the next Process index
	int nextProIdx = 0;
	while (!que.empty() || nextProIdx < num)
	{
		if (!que.empty()) {
			Process * cur = que.front();
			que.pop();
			waitTime += curTime - cur -> arriveTime;
			curTime += min(cur -> excuteTime, q);
			//push the process which arrive in this round
			for (int i = nextProIdx; i < num; ++i)
			{
				if (arrival[i] <= curTime) {
					que.push(new Process(arrival[nextProIdx], run[nextProIdx]));
					nextProIdx = i + 1;
				}
				else break;
			}
			//push current unfinished process to the end of que, update its time; 
			if (cur -> excuteTime > q) {
				cur -> arriveTime = curTime;
				cur -> excuteTime -= q;
				que.push(cur);
			}
			else delete cur;// memory leak;
		}
		else {
			que.push(new Process(arrival[nextProIdx], run[nextProIdx]));
			curTime += arrival[nextProIdx++];
		}
	}
	return (float)waitTime / num;
}

int main(int argc, char const *argv[])
{
		vector<int> arrival1 = {0, 1, 4};
		vector<int> run1 = {5, 2, 3};
		int q1 = 3;
		vector<int> arrival2 = {0, 1, 3, 9};
		vector<int> run2 = {2, 1, 7, 5};
		int q2 = 2;
		cout << waitingTimeRobin(arrival2, run2, q2);
		return 0;
	}