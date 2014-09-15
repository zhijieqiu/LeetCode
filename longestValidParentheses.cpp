int longestValidParentheses(string s) {
	int max = 0;
	int curStart = 0;
	int curValid = 0;
	stack<pair<char, int>> st;

	vector<pair<int, int>> validPairs;
	int i = 0;
	while (i < s.length())
	{
		if (s[i] == '(')
		{
			st.push(make_pair('(', i));
		}
		else
		{
			if (!st.empty() && st.top().first == '(')
			{
				int left = st.top().second;
				st.pop();
				validPairs.push_back(make_pair(left, i));
			}
			else
			{
				curValid = 0;
				curStart = i + 1;
			}
		}
		i += 1;
	}
	if (validPairs.size() == 0)
		return 0;
	int curLeft = validPairs[validPairs.size() - 1].first;
	int right = validPairs[validPairs.size() - 1].second;
	max = right-curLeft;
	for (int i = validPairs.size() - 2; i >= 0; i--)
	{
		if (validPairs[i].second == curLeft - 1)
		{
			max = right - validPairs[i].first > max ? right - validPairs[i].first : max;
			curLeft = validPairs[i].first;
		}
		else if (validPairs[i].first > curLeft&&validPairs[i].second < right)
			;
		else
		{
			right = validPairs[i].second;
			curLeft = validPairs[i].first;
			max = right - curLeft > max ? right - curLeft : max;
		}
	}
	return max+1;
}
