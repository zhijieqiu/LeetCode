class Solution {
public:
    /*
      从左向右扫描，分别记录左边的第一个非空和右边的第一个非空，用列表进行记录，然后将所有的元素都逆序相加
    */
    void reverseWords(string &s) {
    	vector<string> strs;
    	int i = 0;
    	int begin = -1, end = -1;//
    	while (true)
    	{
    		if (i == s.length())
    		{
    			if (begin != -1 && end != -1)
    			{
    				strs.push_back(s.substr(begin, end - begin + 1));
    			}
    			break;
    		}
    		if (s[i] == ' ')
    		{
    			if (begin != -1 && end != -1)
    			{
    				strs.push_back(s.substr(begin, end - begin + 1));
    				begin = -1;
    				end = -1;
    			}
    		}
    		else
    		{
    			if (begin == -1)
    			{
    				begin = i;
    				end = i;
    			}
    			else
    			{
    				end++;
    			}
    		}
    		i++;
    	}
    	string ret = "";
    	s="";
    	if (strs.size() == 0)
    		return;
    	ret = strs[strs.size() - 1];
    	for (int i = strs.size() - 2; i >= 0; i--)
    	{
    		ret += " ";
    		ret += strs[i];
    	}
    	s = ret;
    }
};
