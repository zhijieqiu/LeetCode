class Solution {
public:
    //主要是看当中5的倍数的数
    // 5 10 15 20 ... 105 ... 将产生一个末尾的0
    // 25 50 75 讲产生2哥末尾的0。。。。
    //首先计算有多少5的倍数，然后计算25的倍数的数，125的倍数
    //�由于25的倍数肯定也是5的倍数所以前面已经计算过了
    int trailingZeroes(int n) {
    	long long  i = 5;
    	long long nn = n;
    	int ret = 0;
    	while (i <= nn)
    	{
    		ret += nn / i;
    		i *= 5;
    	}
    	return ret;
    }
};
