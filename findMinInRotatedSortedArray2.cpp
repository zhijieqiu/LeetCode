class Solution {
private:
    int _find(vector<int>&num,int left,int right)
    {
        if(left==right)
            return num[left];
        int mid = -1;
        while(left<=right)
        {
            if(left == right)
                return num[left];
            mid = left+((right-left)>>1);
            if(num[mid+1]<num[mid])
            {
                mid++;
                break;
            }
            else{
                if(num[left]<num[mid])// 4 5 6 7 8 1 2
                    left= mid;
                else if(num[left]>num[mid])//4 5 6 7 1 1 2 2 3 3 3 
                    right = mid;
                else
                {
                    if(num[mid]>num[right]) // 9 9 6
                        left = mid;
                    else  // if the mid value is the same as the value as left and right value then we need to search both [left mid] and [mid+1 right]
                        return min(_find(num,left,mid),_find(num,mid+1,right));// 9 9 9 9 9 6 9
                }
            }
        }
        return num[mid];
    }
public:
    int findMin(vector<int> &num) {
        if(num[0]<num[num.size()-1])
            return num[0];
        return _find(num,0,num.size()-1);
    }
};
