class Solution {
public:
    /*
      words:input strings
      L:the max length of a line
    */
    vector<string> fullJustify(vector<string> &words, int L) {
    	vector<string> ret;
    	int i = 0;
    	while (i<words.size())
    	{
    		string cur = "";
    		vector<string> tmp;
    		int curWordsLength = words[i].length();//to record the current min length of the current words
    		tmp.push_back(words[i]);// push the first word to tmp,remember that tmp is empty at first
    		int gaps = 0;// to record hom many gaps between words
    		i++;
    		while (i<words.size()&&curWordsLength + words[i].length() + 1 <= L)
    		{
    			gaps++;
    			curWordsLength = curWordsLength + words[i].length() + 1;
    			tmp.push_back(words[i]);
    			i++;
    		}
    		cur = tmp[0];
    		if (gaps == 0)//if just one word then append ' ' util it reach L
    		{
    			for (int j = cur.length() + 1; j <= L; j++)
    				cur += ' ';
    			ret.push_back(cur);
    			continue;
    		}
    		if (i == words.size())// if the last word is finished,then we need to justification it well
    		{
    			for (int j = 1; j <= gaps; j++)//the gap between words is just one ' '
    			{
    				cur += ' ';
    				cur += tmp[j];
    			}
    			while (cur.length() < L)// make it reach the Length
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
