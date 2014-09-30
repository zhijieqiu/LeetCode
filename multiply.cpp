/*
计算两个大整数的成绩，将大整数转换为字符串来处理
然后模拟乘法的计算方式，使用一个数组来保存计算结果
*/

string multiply(string s1, string s2)
{
	string ret = "";
	int *dp = new int[s1.length() + s2.length()];
	for (int i = 0; i < s1.length() + s2.length(); i++)
		dp[i] = 0;
	for (int i = s1.length() - 1; i >= 0; i--)
	{
		for (int j = s2.length() - 1; j >= 0; j--)
		{
			int cur = s1.length() - 1 - i + s2.length() - 1 - j;
			dp[cur] += (s1[i]-'0')*(s2[j]-'0');
		}
	}
	int i = 0;
	
	for (i = 0; i < s1.length() + s2.length()-1; i++)
	{
		dp[i + 1] += dp[i] / 10;
		dp[i] %= 10;
	}
	bool needflag = false;
	for (int j = s1.length()+s2.length()-1; j >= 0; j--)
	{
		if (dp[j] == 0 && !needflag)
		{
			continue;
		}
		needflag = true;
		ret += ('0' + dp[j]);
	}
	cout << endl;
	delete dp;
	return ret;
}
