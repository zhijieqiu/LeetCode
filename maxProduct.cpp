
class Solution {
public:
	int maxProduct(int A[], int n) {
		int ret = 0;
		if (1 == n)
			return A[0];//check whether it is one element
		// 2 3 -2 4
		int maxP = 0, maxN = 0;
		for (int i = 0; i < n; i++)
		{
			if (A[i]>0)
			{
				maxP = max(maxP*A[i],A[i]);//maxp has only two ways to come here
				maxN = min(maxN*A[i], 0);//maxn can only be two ways to come here
			}
			else if (A[i] < 0)
			{
				int t = maxP;
				maxP = max(maxN*A[i], 0);
				maxN = min(t*A[i],A[i]);
			}
			else
			{
				maxP = 0;
				maxN = 0;
			}
			ret = max(ret,maxP);
		}
		return ret;
	}
};
