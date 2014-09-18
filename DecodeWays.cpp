class Solution {
public:
   int numDecodings(string s)
    {
    	int length = s.length();
    	if (length == 0)// if the strlen is 0 then return 0
    		return 0;
    	int *dp = new int[length];
    	dp[0] = s[0] == '0' ? 0 : 1; // if the first one is zero then return 0;
    	if (length >= 2)//if length>=2 then compute the decode ways of the first two card
    	{
    		if (s[0] == '0')  
    			return 0;
    		string ss = s.substr(0, 2);
    		if (atoi(ss.c_str()) <= 26 && ss[1]!='0') // 23 12
    			dp[1] = 2;
    		else//31  72 89
    		    dp[1] = 1;
    		if(ss[1]=='0'&&ss[0]>='3')//like 3011 
    		    return 0;
    		
    	}
    	for (int i = 2; i < length; i++)
    	{
    		if (s[i] == '0')
    		{
    			if (s[i - 1] == '1' || s[i - 1] == '2')
    			{
    				dp[i] = dp[i - 2];
    			}
    			else
    				return 0;
    		}
    		else
    		{
    			if (s[i - 1] == '0')
    				dp[i] = dp[i - 1];
    			else
    			{
    				string ss = s.substr(i - 1, 2);
    				if (atoi(ss.c_str()) <= 26)
    					dp[i] = dp[i - 1] + dp[i - 2];
    				else
    					dp[i] = dp[i - 1];
    			}
    			
    		}
    	}
    	return dp[length - 1];
    }
};
