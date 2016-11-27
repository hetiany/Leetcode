int isValid (string s)
{
	if (s == "" || s.size() == 0)
		return 0;
	stack<char> stk;
	for (int i = 0; i < s.size(); ++i)
	{
		if (stk.empty()) stk.push(s[i]);
		else if (s[i] - stk.top() == 1 || s[i] - stk.top() == 2)
			stk.pop();
		else stk.push(s[i]);
	}
	if (stk.empty()) return s.size() / 2;
		return -1;
}