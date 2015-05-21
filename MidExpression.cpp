class MidExpression{
    struct Node{
        bool isOp;
        int num;
        char op;
    };
public:
    int computeExpression(char* buffer){
        int len = static_cast<int>(strlen(buffer));
        stack<Node> numStack;
        std::stringstream sstream;
        for(int i=0;i<len;i++){
            if(buffer[i]>='0'&&buffer[i]<='9')
            {
                int num = 0;
                int j=i;
                for(j=i;j<len;j++){
                    if(buffer[j]>='0'&&buffer[j]<='9')
                        num = num*10+buffer[j]-'0';
                    else
                        break;
                }
                i=j-1;
                Node node;
                node.isOp = false;
                node.num = num;
                numStack.push(node);
            }else if(buffer[i]=='*'||buffer[i]=='/'){
                int num = 0;
                int j=i+1;
                for(;j<len;j++){
                    if(buffer[j]>='0'&&buffer[j]<='9')
                        num = num*10+buffer[j]-'0';
                    else
                        break;
                }
                Node n = numStack.top();
                numStack.pop();
                if(buffer[i]=='*')
                    n.num*=num;
                else
                    n.num/=num;
                numStack.push(n);
                i=j-1;
            }else if(buffer[i]=='('||buffer[i]=='+'||buffer[i]=='-')
            {
                Node n;
                n.isOp = true;
                n.op=buffer[i];
                numStack.push(n);
            }
            else{
                vector<int> nums;
                vector<char> ops;
                while(numStack.empty()==false){
                    Node n = numStack.top();
                    numStack.pop();
                    if(n.isOp==true&&n.op=='(')
                        break;
                    if(n.isOp)
                        ops.push_back(n.op);
                    else
                        nums.push_back(n.num);
                }
                int beforeNum = nums[nums.size()-1];
                for(int i=ops.size()-1;i>=0;i--){
                    char op = ops[i];
                    int num = nums[i];
                    if(op=='+')
                        beforeNum+=num;
                    else
                        beforeNum-=num;
                }
                Node n;
                n.isOp = false;
                n.num = beforeNum;
                numStack.push(n);
            }
        }
        vector<int> nums;
        vector<char> ops;
        while(numStack.empty()==false){
            Node n = numStack.top();
            numStack.pop();
            if(n.isOp==true&&n.op=='(')
                break;
            if(n.isOp)
                ops.push_back(n.op);
            else
                nums.push_back(n.num);
        }
        int beforeNum = nums[nums.size()-1];
        for(int i=ops.size()-1;i>=0;i--){
            char op = ops[i];
            int num = nums[i];
            if(op=='+')
                beforeNum+=num;
            else
                beforeNum-=num;
        }
        return beforeNum;
    }
};

