//Find online, changed by java
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        if(!num) {
            res.push_back("0:00");
            return res;
        }
        vector<int> record{1, 2, 4, 8, 1, 2, 4, 8, 16, 32};
        get_result(record, num, res, 0, 0, 0);
        return res;
    }
    void get_result(vector<int> record, int num, vector<string>& res, int index, int hour, int minute) {
        if(num < 0) {
            return ;
        }
        if(num == 0) {
            if(hour < 12 && minute < 60) {
                if(minute < 10) {
                    res.push_back(to_string(hour) + ":0" + to_string(minute));
                } else {
                    res.push_back(to_string(hour) + ":" + to_string(minute));
                }
            }
        } else {
            for(int i = index; i < record.size(); ++i) {
                if(i < 4) {
                    get_result(record, num - 1, res, i + 1, hour + record[i], minute);
                } else {
                    get_result(record, num - 1, res, i + 1, hour, minute + record[i]);
                }
            }
            
        }
    }
};