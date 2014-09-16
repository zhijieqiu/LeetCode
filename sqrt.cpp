int sqrt(int x)
{
    long long left=0,right = x;//此处将int转换为long long 是为了防止当x太大的时候溢出
    long long target = x;
    while(left<right)
    {
	long long t = (left+right)>>1;//取中值
	if(t*t>target)
	{
		right=t-1;
	}
	else if(t*t<target)
		left=t+1;
	else 
		return t;//if t*t == target then t is the result
    }
    return right*right>target?right-1:right;// when left>=right,then we can make a conclusion that the right value is the result
    //or the (right-1) is the result
}
