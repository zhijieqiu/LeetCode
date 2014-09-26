class Solution {
public:
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
    			if (i == 0)
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
    			if ((dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]))
    				dp[i][j] = 1;
    			
    		}
    		
    	}
    	return dp[len1][len2] == 1&&len1+len2==s3.length();
    }
};
