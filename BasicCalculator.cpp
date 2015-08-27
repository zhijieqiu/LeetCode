class Solution {
private:
    int cal(int a,int b,char op){
        if(op=='+') return a+b;
        else if(op=='-') return a-b;
        else if(op=='*') return a*b;
        else return a/b;
    }
    int getPriority(char c){
        if(c=='+'||c=='-') return 0;
        else if(c=='*'||c=='/') return 1;
        return -1;
    }
    
public:
    int calculate(string s) {
        stack<char> ops;
        stack<int> nums;
        if(!s.length()) return 0;
        int i=0;
        set<char> operators;
        //operators.insert('+'),operators.insert('-'),operators.insert('*'),operators.insert('/');
        while(i<s.length()){
            if(s[i]==' '){
                i++;
                continue;
            }
            if(s[i]>='0'&&s[i]<='9'){
                int j=i;
                string tmp;
                while(s[j]>='0'&&s[j]<='9'){
                    tmp+=s[j++];
                }
                nums.push(stol(tmp));
                i=j;
            }else{
                char c =s[i++];
                if(ops.empty()){
                    ops.push(c);
                }else{
                    while(!ops.empty()){//here must be while not if
                        char topc = ops.top();
                        if(getPriority(topc)<getPriority(c)) break;
                        ops.pop();
                        int num2 = nums.top();
                        nums.pop();
                        int num1 = nums.top();
                        nums.pop();
                        nums.push(cal(num1,num2,topc));
                    }
                    ops.push(c);
                }
            }
        }
        int ret = 0;
        while(!ops.empty()){
            char topc = ops.top();
            ops.pop();
            int num2=nums.top();
            nums.pop();
            int num1=nums.top();
            nums.pop();
            nums.push(cal(num1, num2,topc));
        }
        ret+=nums.top();
        return ret;
    }
};
