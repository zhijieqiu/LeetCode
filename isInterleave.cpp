class Solution {
public:
    /*
      思路类似使用：最长公共子序列的方法，使用动态数组dp[i][j]记录当前s1的前i个字符和s2的前j个字符
      能够组合成s3的前i+j个字符
    */
    bool isInterleave(string s1, string s2, string s3)
    {
    	int len1 = s1.length();
    	int len2 = s2.length();
    	int **dp = new int*[len1+1];
    	for (int i = 0; i < len1+1; i++)
    	{
    		dp[i] = new int[len2 + 1];
    		for (int j = 0; j < len2 + 1; j++)
    			dp[i][j] = 0;
    	}
    	dp[0][0] = 1;
    	for (int i = 0; i <= len1; i++)
    	{
    		for (int j = 0; j <= len2; j++)
    		{
    			if (i == 0)//判断s2与时s3的交集情况
    			{
    				if (j == 0)
    					continue;
    				if (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1])
    					dp[i][j] = 1;
    				continue;
    			}
    			if (j == 0)
    			{
    				if (i == 0)
    					continue;
    				if (dp[i-1][j] && s1[i - 1] == s3[i + j - 1])
    					dp[i][j] = 1;
    				continue;
    			}
    			//s3的最后一个字符要么是s1的最后一个字符，要么是s2的最后一个字符
    			if ((dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]))
    				dp[i][j] = 1;
    			
    		}
    		
    	}
    	return dp[len1][len2] == 1&&len1+len2==s3.length();
    }
};
