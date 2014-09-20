int largest(vector<int> heights)
{
	stack<int> st;
	int maxArea = 0;
	for (int i = 0; i < heights.size(); i++)
	{
		if (st.empty() || heights[i]>=st.top())//if st is empty or the height is bigger than the top element then push it into the stack
			st.push(heights[i]);
		else
		{
			int len = 0;
			while (!st.empty())//否则，计算区域内面积
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
			if (st.empty())//如果该元素比任何之前的高度都小，就要多加一次
				st.push(heights[i]);
			for (int j = 0; j < len; j++)//去除了多少个元素就要添加多少个当前元素回去
				st.push(heights[i]);
		}
	}
	int len = 0;
	while (!st.empty())//别忘了最后一轮扫描
	{
		len++;
		int tmp = st.top();
		maxArea = max(maxArea, len*tmp);
		st.pop();
	}
	return maxArea;
}
