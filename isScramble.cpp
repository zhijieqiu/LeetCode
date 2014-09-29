
/*
给定两个字符串如何判断这两个字符串能够通过不断的交换一个字符串的前后两部分得到
例如great 和 rgeat 我们可以通过交换r和g得到
使用dp[i][j][k]代表字符串s1从第i个字符开始和从第j个字符开始的k个字符能否通过交换得到
事实上，如果一个字符串可以通过交换得到的话，必须满足如下的条件：
dp[i][j][l]成立的条件是(dp[i][j][k]&&dp[i+k][j+k][l-k])||(dp[i][j+l-k][k]&&dp[i+k][j][l-k])
上面的这段话的解释是这样子的：从中间任何某个位置切分满足要求的话，就有这两个字符串的前k个字符串满足条件并且后面ll-k个字符满足条件
或者第一个字符串的前k个字符和第二个字符串的后面k个字符满足条件，并且第一个字符串的后ll-k个字符和第二个字符串的前ll-k个字符满足条件
*/
class scrambleSolution
{
private:
	string s1, s2;
	bool ***dp;
	bool realScramble()
	{
		int len = s1.length();
		for (int i = 0; i < len; i++)
			for (int j = 0; j < len; j++)
				dp[i][j][0] = (s1[i] == s2[j]);//长度为1的时候只能是相同的字符符合要求的
		for (int i = 0; i < len - 1; i++)
		{
			for (int j = 0; j < len - 1; j++)
			{
				dp[i][j][1] = ((dp[i][j][0] && dp[i+1][j+1][0]) || (dp[i][j+1][0] && dp[i+1][j][0]));//长度为2的时候
			}
		}
		for (int ll = 2; ll < len; ll++)
		{
			for (int i = 0; i < len - ll; i++)
			{
				for (int j = 0; j < len - ll; j++)
				{
					for (int k = 0; k < ll; k++)
						dp[i][j][ll] |= ((dp[i][j][k] && dp[i + k + 1][j + k + 1][ll - k - 1]) || (dp[i][j + ll - k][k] && dp[i + k + 1][j][ll - k - 1]));
						//长度大于等于3的时候需要考虑中间de ll-1种切分的可能
				}
			}
		}
		return dp[0][0][len - 1];
	}
public:
	
	bool isScramble(string s1, string s2)
	{
		this->s1 = s1;
		this->s2 = s2;
		int len = s1.length();
		dp = new bool**[len];
		for (int i = 0; i < len; i++)
			dp[i] = new bool*[len];
		for (int i = 0; i < len; i++)
			for (int j = 0; j < len; j++)
			{
			    dp[i][j] = new bool[len];
				for (int k = 0; k < len; k++)
					dp[i][j][k] = false;
			}
		bool ret = realScramble();
		for (int i = 0; i < len; i++)
			for (int j = 0; j < len; j++)
				delete dp[i][j];
		for (int i = 0; i < len; i++)
			delete dp[i];
		delete dp;
		return ret;
	}
};
