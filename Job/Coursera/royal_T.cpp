#include<iostream>
#include<vector>
#include<utility> 
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

int trans(string s) {
	unordered_map<string, int> dict;
	dict["I"] = 1;
	dict["II"] = 2;
	dict["III"] = 3;
	dict["IV"] = 4;	
	dict["V"] = 5;
	dict["VI"] = 6;
	dict["VII"] = 7;
	dict["VIII"] = 8;
	dict["IX"] = 9;
	dict["X"] = 10;
	dict["XX"] = 20;
	dict["XXX"] = 30;
	dict["XL"] = 40;
	dict["L"] = 50; 
	int res = 0;
	if(s.size() == 0)
		return res;
	if(s.size() == 1) {
		cout << dict[s] << endl;
		return dict[s];
	} 
	if(s.size() == 2) {
		if(dict.find(s) != dict.end()) {
			//2,4,6,9,20,40,
			cout << dict[s] << endl;
			return dict[s];
		} else {
			//10s, 50s
			if(s[0] == 'X') {
				int sum = 10;
				std::string str(1, s[1]);				
				sum = sum + dict[str];
				cout << sum << endl;
				return sum;
			}
			if(s[0] == 'L') {
				int sum = 50;
				std::string str(1, s[1]);				
				cout << (sum + dict[str]) << endl;
				return (sum + dict[str]);
			}
		}

	}
	//string temp(1,s[0]);
	int prevVal = 0;
	int currVal = 0;
	for(int i = 1; i < s.size(); i++) {
		string temp = string(1, s[i - 1]);
		prevVal = dict[temp];
		temp = string(1, s[i]);
		currVal = dict[temp];
		if(s[i - 1] == 'I' && (s[i] == 'X' || s[i] == 'V'))
			res += - prevVal;
		else if(s[i - 1] == 'X' && s[i] == 'L')
			res += - prevVal;
		else 
			res += prevVal;
		prevVal = currVal;
	}
	res = res + prevVal;
	cout << res << endl;
	return res;
}

bool isLess(string s1,string s2) {
	int num1 = trans(s1);
	int num2 = trans(s2);
	return (num1 <= num2) ? true : false;	
}

struct myStruct {
	bool operator() (string s1,string s2) {
		std::size_t found = s1.find(" ");
		string firstName1 = s1.substr(0,found);
		string royalName1 = s1.substr(found+1);
		//char lower1 = firstName1[0] + 32;
		//firstName1 = lower1 + firstName1.substr(1);	
		//cout<<firstName1<<endl;
		//cout<<royalName1<<endl;
		found = s2.find(" ");
		string firstName2 = s2.substr(0, found);
		string royalName2 = s2.substr(found + 1);		
		//char lower2 = firstName2[0] + 32;
		//firstName2 = lower2 + firstName2.substr(1);
		//cout<<firstName2<<endl;
		//cout<<royalName2<<endl;
		//so far, we have firstNamei and royalNamei
		if(firstName1.compare(firstName2) < 0) {
			//cout << "haha" << endl;
			return true;
			//return false;
		} else if(firstName1.compare(firstName2) == 0){
			if(isLess(royalName1,royalName2))
				return true;
				//return false;
			else 
				return false;
				//return true;
		} else {
			cout << "haha" << endl;
			return false;
			//return true;
		}
	}
} comparator;



class Solution {
public:
	vector<string> compare(vector<string> names) {
		//vector<string> res;
		if(names.size()==0)
			return names;
		sort(names.begin(), names.end(), comparator);	

		for(int i = 0;i < names.size(); i++)
			cout << names[i] << endl;
		return names;
	}
};

int main() {
	vector<string> names;
	names.push_back("Louis XL");
	//names.push_back("Louis IV");
	names.push_back("Victoria LL");
	//names.push_back("Victoria II");
	Solution mySolution;
	mySolution.compare(names);

	string a = "Louis";
	string b = "Victoria";
	cout << a.compare(b) << endl;
	return 0;
}
