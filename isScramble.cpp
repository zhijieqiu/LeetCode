
/////////////////////////////////////////////////////////////////////////
/*
使用递归的方法，这种方法的复杂度是指数级别的，所以很容易超时
但是她确实是其他方法的基石，从这个方法我们可以看到最优子结构以及子问题重复的现象，这样的话我们很自然的就想到能不能使用
动态规划的方法
*/
class Solution {
public:
    bool stramble(string s1, string s2)
    {
    	if (s1.compare(s2) == 0)
    		return true;
    	else if (s1.length() == 1)
    		return false;
    	else
    	{
    		for (int i = 1; i <= s1.length() - 1; i++)
    		{
    			bool left = stramble(s1.substr(0, i), s2.substr(0, i));
    			bool right = left ? stramble(s1.substr(i, s1.length() - 1), s2.substr(i, s1.length() - 1)) : false;
    			if (left&&right)
    				return true;
    			left = stramble(s1.substr(0, i), s2.substr(s2.length() - i, i));
    			right = left ? stramble(s1.substr(s1.length() - i), s2.substr(0, i)) : false;
    			if (left&&right)
    				return true;
    		}
    	}
    	return false;
    }
    bool isScramble(string s1, string s2)
    {
    	return stramble(s1, s2);
    }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
下面的方案是基于上面的思考得到的，我使用一个四维数组dp[s1f][s1e][s2f][s2e]，用来保存s1[s1f:s1e]与s2[s2f:s2e]的结果
使用0表示还没有判断过，使用-1表示不能满足scramble的交换要求，使用1表示能够满足scramble的要求，每次计算之前先判断结果
如果已经判断过了就直接返回结果
*/
class Solution {
public:
    int ****dpdp;
    string s1;
    string s2;
    bool stramble(int s1f,int s1e,int s2f,int s2e)
    {
    	if (dpdp[s1f][s1e][s2f][s2e])
    	{
    		if (dpdp[s1f][s1e][s2f][s2e] == 1)
    			return true;
    		else
    			return false;
    	}
    	if (s1.substr(s1f,s1e-s1f+1).compare(s2.substr(s2f,s2e-s2f+1)) == 0)
    		return true;
    	else if (s1e-s1f == 0)
    		return false;
    	else
    	{
    		for (int i = 1; i <= s1.substr(s1f, s1e - s1f + 1).length() - 1; i++)
    		{
    			bool left = stramble(s1f + 0, s1f + i-1, s2f + 0, s2f + i-1);
    			dpdp[s1f][s1f + i - 1][s2f][s2f + i - 1] = left?1:-1;
    			bool right = left ? stramble(s1f + i, s1e, s2f+i, s2e) : false;
    			dpdp[s1f+i][s1e][s2f+i][s2e] = right?1:-1;
    			if (left&&right)
    				return true;
    			left = stramble(s1f+0, s1f+i-1, s2e - i+1, s2e);
    			dpdp[s1f][s1f + i - 1][s2e - i + 1][s2e] = left ? 1 : -1;
    			right = left ? stramble(s1e-i+1,s1e, s2f+0,s2f+i-1) : false;
    			if (left&&right)
    				return true;
    			dpdp[s1e - i + 1][s1e][s2f][s2f + i - 1] = right?1:-1;
    		}
    	}
    	dpdp[s1f][s1e][s2f][s2e] = -1;
    	return false;
    }
    bool isScramble(string s1, string s2)
    {
        this->s1 = s1;
        this->s2= s2;
        int len = this->s1.length();
        dpdp = new int***[len];
        for(int i=0;i<len;i++)
            dpdp[i] = new int**[len];
        for(int i=0;i<len;i++)
           for(int j=0;j<len;j++)
           {
               dpdp[i][j]=new int*[len];
           }
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<len;j++)
            {
                for(int k=0;k<len;k++)
                {
                    dpdp[i][j][k] = new int[len];
                }
            }
        }
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<len;j++)
            {
                for(int k=0;k<len;k++)
                {
                    for(int m=0;m<len;m++)
                        dpdp[i][j][k][m] = 0;
                }
            }
        }
    	return stramble(0,s1.length()-1,0,s2.length()-1);
    }
};
/*
上面的改进虽然将问题从指数级别降到了多项式级别，应该是N4的复杂度，但是我们很容易发现，事实上保存的信息冗余了，因为
dp[s1f][s1e][s2f][s2e]中存在一个已知的事实s1e-s1f == s2e-s2f因此我们不需要保存这么多信息，任意去掉一维都可以了，这里
我去掉了最后一维，也就是不保存s2e,得到如下代码
*/class Solution {
public:
    string s1;
    string s2;
    int ***F;
    bool stramble2(int s1f, int s1e, int s2f)
    {
    	int len = s1e - s1f + 1;
    	if (F[s1f][s1e][s2f])
    		return F[s1f][s1e][s2f]==1;
    	if (s1.substr(s1f, len).compare(s2.substr(s2f, len)) == 0)
    		return true;
    	else if (s1e - s1f == 0)
    		return false;
    	else
    	{
    		for (int i = 1; i <= len-1; i++)
    		{
    			bool left = stramble2(s1f + 0, s1f + i - 1, s2f + 0);
    			F[s1f][s1f + i - 1][s2f] = left ? 1 : -1;
    			bool right = stramble2( s1f + i, s1e, s2f + i);
    			F[s1f + i][s1e][s2f + i] = right ? 1 : -1;
    			if (left&&right)
    				return true;
    			
    			left = stramble2( s1f + 0, s1f + i - 1, s2f + len - i);
    			F[s1f][s1f + i - 1][s2f+len-i]= left ? 1 : -1;
    			right = stramble2( s1f+i, s1e, s2f + 0);
    			F[s1f+i][s1e][s2f] = right ? 1 : -1;
    			if (left&&right)
    				return true;
    		}
    	}
    	F[s1f][s1e][s2f] = -1;
    	return false;
    
    }
    bool isScramble(string s1, string s2)
    {
        this->s1 = s1;
        this->s2= s2;
        int len = this->s1.length();
    	F = new int**[len];
    	for (int i = 0; i < len; i++)
    	{
    		F[i] = new int*[len];
    	}
    	for (int i = 0; i<len; i++)
    		for (int j = 0; j<len; j++)
    		{
    		F[i][j] = new int[len];
    		}
    	for (int i = 0; i<len; i++)
    	{
    		for (int j = 0; j<len; j++)
    		{
    			for (int k = 0; k<len; k++)
    			{
    				F[i][j][k] = 0;
    			}
    		}
    	}
    	return stramble2(0,s1.length()-1,0);
    }
};

/*
上面的动态规划的代码都是使用自顶向下的编程方式，针对上面的的这段代码，我们可以转换为自底向上的解决方案
*/
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
/*
后面我从别人那里学到了一种使用递归解决的方案，这种方案是用了一个减枝的方案，那就是如果两个子字符串排序之后不相同的话，那么它肯定
不会是符合scremble要求，下面的这段代码速度也是很好的，但是我个人认为这并不能认为它的最终复杂度会很低，有可能存在一些例子
会使得计算时间达到指数级别，但是还没有发现
*/
class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s1.size() != s2.size()) return false;
        if(s1 == s2) return true;
        string ts1 = s1,ts2 = s2;
        sort(ts1.begin(), ts1.end());
        sort(ts2.begin(), ts2.end());
        if(ts1 != ts2) return false;
        for(int isep = 1; isep < s1.size(); ++ isep) {
            //seporate s1 as [0,isep - 1],[isep, s1.size() - 1]
            string seg11 = s1.substr(0,isep);
            string seg12 = s1.substr(isep);
            {//see if forward order is ok
                string seg21 = s2.substr(0,isep);
                string seg22 = s2.substr(isep);
                if(isScramble(seg11,seg21) && isScramble(seg12,seg22)) return true;
            }
            {//see if reverse order is ok
                string seg21 = s2.substr(s2.size() - isep);
                string seg22 = s2.substr(0,s2.size() - isep);
                if(isScramble(seg11,seg21) && isScramble(seg12,seg22)) return true;
            }
        }
        return false;
    }
};
