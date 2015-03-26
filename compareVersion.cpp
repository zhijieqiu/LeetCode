class Solution {
public:
    void split(string str,vector<string>& ret,string gap)
    {
    	int i = 0;
    	while (i != -1)
    	{
    		int index = str.find_first_of(gap, i);
    		if (index != -1)
    		{
    			ret.push_back(str.substr(i, index - i));
    		}
    		else
    			break;
    		i = index+1;
    	}//1.2.3
    	if (i < str.length())
    	{
    		ret.push_back(str.substr(i,str.length()-i+1));
    	}
    }
    int compareVersion(string version1, string version2)
    {
    	vector<string> str1, str2;
    	split(version1, str1, "."), split(version2, str2, ".");
    	int i;
    	for (i = 0; i < str1.size() && i < str2.size(); i++)
    	{
    		int a = atoi(str1[i].c_str()),b=atoi(str2[i].c_str());//check from begin to end make the things to int and compare
    		if (a > b)
    			return 1;
    		else if (a < b)
    			return -1;
    	}
    	//check the rest ones ,if str1 size is great than str2 and the rest of str1 is not all zero then str1 is bigger
    	if (str1.size() > str2.size())
    	{
    		while (i<str1.size())
    		{
    			if (atoi(str1[i++].c_str()) != 0)
    				return 1;
    		}
    		return 0;
    	}
    	else if (str1.size() < str2.size())
    	{ 
    		while (i<str2.size())
    		{
    			if (atoi(str2[i++].c_str()) != 0)
    				return -1;
    		}
    		return 0;
    	}
    	return 0;
    }
};
