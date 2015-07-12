//http://bestcoder.acmcoder.com/contests/contest_showproblem.php?cid=608&pid=1003
1003 Senior's String
首先我们用O(n2)的动态规划算法处理出dp数组，dp[i][j]表示X串的前i个字符和Y串的前j个字符的最长公共子序列的长度，
在这个基础上我们再进行一个动态规划。用f[i][j]表示在X串的前i个字符中，
有多少个长度为dp[i][j]的子序列在Y的前j个字符中也出现了。
转移：若dp[i−1][j]==dp[i][j]，则f[i][j]+=f[i−1][j]，表示i这个字符不选；
再考虑选i这个字符，找到Y串前j个字符中最靠后的与X[i]匹配的字符的位置，设为p，若dp[i−1][p−1]+1==dp[i][j]，则f[i][j]+=f[i−1][p−1]。
最终的答案即为f[n][m]。复杂度O(n2)。
