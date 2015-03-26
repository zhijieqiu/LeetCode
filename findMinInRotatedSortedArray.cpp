class Solution {
public:
    int findMin(vector<int> &num) {
        if(num.size()==1)
            return num[0];
        int mid = -1,left = 0,right = num.size()-1;
        if(num[left]<num[right])//check whether it has reversed
            return num[left];//if it does not has reversed , return the left most value
        while(left<=right)
        {
            if(left==right)//if only the value is left, than it must be the smallest value
            {
                mid = left;
                break;
            }
            mid  = (left + ((right-left)>>1));
            if(num[mid+1]<num[mid])
            {
                mid++;
                break;
            }
            else{
                if(num[mid]>num[left])// 0 1 
                    left = mid;
                else 
                    right = mid;
            }
        }
        return num[mid];
        
    }
};
//test cases 
//1
//1 2
//2 1
//1 2 3
//3 2 1
//4 5 6 7 1 2 3
