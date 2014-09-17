class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
    	vector<string> ret;
    	int i = 0;
    	while (i<words.size())
    	{
    		string cur = "";
    		vector<string> tmp;
    		int curWordsLength = words[i].length();
    		tmp.push_back(words[i]);
    		int gaps = 0;
    		i++;
    		while (i<words.size()&&curWordsLength + words[i].length() + 1 <= L)
    		{
    			gaps++;
    			curWordsLength = curWordsLength + words[i].length() + 1;
    			tmp.push_back(words[i]);
    			i++;
    		}
    		cur = tmp[0];
    		if (gaps == 0)
    		{
    			for (int j = cur.length() + 1; j <= L; j++)
    				cur += ' ';
    			ret.push_back(cur);
    			continue;
    		}
    		if (i == words.size())
    		{
    			for (int j = 1; j <= gaps; j++)
    			{
    				cur += ' ';
    				cur += tmp[j];
    			}
    			while (cur.length() < L)
    				cur += ' ';
    			ret.push_back(cur);
    			return ret;
    		}
    		int everyGap = (L - curWordsLength + gaps) / gaps, moreOnes = (L - curWordsLength + gaps) - (everyGap*gaps);
    		for (int j = 1; j <= gaps; j++)
    		{
    			for (int k = 0; k < everyGap; k++)
    				cur += ' ';
    			if (moreOnes > 0)
    			{
    				cur += " ";
    				moreOnes--;
    			}
    			cur += tmp[j];
    		}
    		ret.push_back(cur);
    	}
    	return ret;
    }
};
