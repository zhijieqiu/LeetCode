int largest(vector<int> heights)
{
	stack<int> st;
	int maxArea = 0;
	for (int i = 0; i < heights.size(); i++)
	{
		if (st.empty() || heights[i]>=st.top())
			st.push(heights[i]);
		else
		{
			int len = 0;
			while (!st.empty())
			{
				int tmp = st.top();
				len++;
				if (tmp>heights[i])
				{
					
					maxArea = max(maxArea, len*tmp);
					st.pop();
				}
				else
					break;
			}
			if (st.empty())
				st.push(heights[i]);
			for (int j = 0; j < len; j++)
				st.push(heights[i]);
		}
	}
	int len = 0;
	while (!st.empty())
	{
		len++;
		int tmp = st.top();
		maxArea = max(maxArea, len*tmp);
		st.pop();
	}
	return maxArea;
}
