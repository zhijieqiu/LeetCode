int sqrt2(int x)
{
	
	
	long long left=0,right = x;
	long long target = x;
	while(left<right)
	{
		long long t = (left+right)>>1;
		if(t*t>target)
		{
			right=t-1;
		}
		else if(t*t<target)
			left=t+1;
		else 
			return t;
	}
	return right*right>target?right-1:right;
}
