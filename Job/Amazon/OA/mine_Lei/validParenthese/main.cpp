// ascii code 
// ( 40  ) 41
// [ 91  ] 93
// { 123 } 125
bool isValid(string s){
	stack<char> stk;
	for (int i = 0; i < s.size(); ++i)
	{
		if (stk.empty()) stk.push(s[i]);
		else if (s[i] - stk.top() == 1 || s[i] - stk.top() == 2)
			stk.pop();
		else stk.push(s[i]);
	}
	return stk.empty();
}

bool isValid(char * s) {
	stack<char> stk;
	for(int i = 0; i < strlen(s); ++i) {
		if (stk.empty()) stk.push(s[i]);
		else if (s[i] - stk.top() == 1 || s[i] - stk.top() == 2)
			stk.pop();
		else stk.push(s[i]);
	}
	return stk.empty();
}




bool isValid(string s){
	stack<char> stk;
	for (int i = 0; i < s.size(); ++i)
	{
		switch(s[i]) {
			case '(' :
			case '[' :
			case '{' :
				stk.push(s[i]);
				break;
			case ')' :
				if(!stk.empty() && stk.top() == '(')
					stk.pop();
				else return false;
				break;
			case ']' :
				if (!stk.empty() && stk.top() == '[')
					stk.pop();
				else return false;
				break;
			case '}' :
				if (!stk.empty() && stk.top() == '{')
					stk.pop();
				else return false;
				break;
		}
	}
	return stk.empty();
}


int isValid(string s)
{
	if (s == "" || s.size()) return 0;
	int count = 0;
	stack <char> stk;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '(') stack.push('(');
		else {
			if (stk.empty()) return -1;
			else {
				stk.pop();
				count++;
			}
		}
	}
	if (stk.empty()) return count;
	return -1;
}