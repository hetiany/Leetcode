//my code, time limit exceeded
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        //minNum = INT_MAX;
    }
    
    void push(int x) {
        store.push_back(x);
        /*if(x <= minNum) {
            temp = minNum;
            minNum = x;
        }*/
    }
    
    void pop() {
        auto itr = store.end() - 1;
        /*if(*itr == minNum) {
            minNum = temp;
        }*/
        store.erase(itr);
    }
    
    int top() {
        auto itr = store.end() - 1;
        return *itr;
    }
    
    int getMin() {
        int minNum = INT_MAX;
        for(auto i : store) {
            if(i < minNum) {
                minNum = i;
            }
        }
        return minNum;
    }
private:
    vector<int> store;
    //int minNum;
    int temp;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */


//my code, 10/12/2016
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    void push(int x) {
        store.push_back(x);
        ++record[x];
            
    }
    
    void pop() {
        auto itr = store.end() - 1;
        store.erase(itr);
        if(--record[*itr] == 0) {
            std:: map<int, int>:: iterator ptr = record.find(*itr);
            record.erase(ptr);
        }
    }
    
    int top() {
        auto itr = store.end() - 1;
        return *itr;
    }
    
    int getMin() {
        auto itr = record.begin();
        return itr -> first;
    }
    
private:
    vector<int> store;
    map<int, int> record;
};


//Find online
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        if (mins.empty() || x<=mins.top()) {
            mins.push(x);
        }
    }

    void pop() {
        int temp = s.top();
        s.pop();
        if (temp == mins.top()) {
            mins.pop();
        }
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return mins.top();
    }
    
private:
    stack<int> s;
    stack<int> mins;
};


//my code, 10/17/2016
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        store.push(x);
        if(!min.size()) {
            min.push(x);
        } else {
            if(min.top() >= x) {
                min.push(x);
            }
        }
    }
    
    void pop() {
        if(store.top() == min.top()) {
            min.pop();
        }
        store.pop();
    }
    
    int top() {
        return store.top();
    }
    
    int getMin() {
        return min.top();
    }
private:
    stack<int> store;
    stack<int> min;
};
