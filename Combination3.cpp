Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can 
be used and each combination should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
Solution is below:
class Solution {
private:
    int k;
    void combination(vector<int>& cur,int index,int curSum,int sum,vector<vector<int> >& result){
        if(curSum==sum){//rememer that to check whether sum and cur size has meet the condition
            if(cur.size()==k)
                result.push_back(cur);
            return;
        }
        if(index>9||cur.size()>k) return;
        if(cur.size()==k&&curSum<sum) return;
        if(curSum+index<=sum) {
            cur.push_back(index);
            combination(cur,index+1,curSum+index,sum,result);
            cur.pop_back();
            combination(cur,index+1,curSum,sum,result);
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> cur;
        vector<vector<int>> result;
        this->k=k;
        combination(cur,1,0,n,result);
        return result;
    }
};
