int longestValidParentheses(string s) {
	int max = 0;
	int curStart = 0;
	int curValid = 0;
	stack<pair<char, int>> st;//存储字符和它出现的位置

	vector<pair<int, int>> validPairs;//存储合理的括号对的左右位置，（（））会记录两次分别是(1,2) (0,3)
	//因此需要在最后的扫描过程中判断
	int i = 0;
	//from line 11 to line 32, is to generate validPairs
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
	max = right-curLeft;//从第一个中获得合理的位置，以及记录他们的左右位置
	for (int i = validPairs.size() - 2; i >= 0; i--)
	{
		if (validPairs[i].second == curLeft - 1)//如果该合理的右位置值和当前的范围的左值相同那么就合并
		{
			max = right - validPairs[i].first > max ? right - validPairs[i].first : max;
			curLeft = validPairs[i].first;
		}
		else if (validPairs[i].first > curLeft&&validPairs[i].second < right)//如果已经在之前的范围中出现就不需要任何操作
			;
		else//否则就是已经出现了隔离段，要重新开始记录了，重新设定左右范围，并且计算它的合理情况
		{
			right = validPairs[i].second;
			curLeft = validPairs[i].first;
			max = right - curLeft > max ? right - curLeft : max;
		}
	}
	return max+1;//remember to add 1 here 
}
