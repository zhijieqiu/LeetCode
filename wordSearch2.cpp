struct TrieNode{
  TrieNode* childs[26];
  bool isLeaf;
  TrieNode(){
      memset(childs,nullptr,sizeof(childs));
      isLeaf = false;
  }
};
void insert(TrieNode* root,const string& word){
    for(int i=0;i<word.length();i++){
        if(root->childs[word[i]-'a']){
            root = root->childs[word[i]-'a'];
        }else{
            root->childs[word[i]-'a'] = new TrieNode();
            root = root->childs[words[i]-'a'];
        }
    }
    root->isLeaf = true;
}
int dir[][2]={{1,0},{-1,0},{0,1},{0,-1}};
void dfs(vector<string>& result,TrieNode* root,vector<vector<char>>& board,int r,int c,string& cur){
    char t =board[r][c];
    cur+=t;
    board[r][c] = 'a'-1;
    if(root->isLeaf) result.push_back(cur);
    for(int i=0;i<4;i++){
        int rr=dir[i][0]+r,cc= dir[i][1]+c;
        if(rr>=board.size()||rr<0||cc>=board[0].size()||cc<0) continue;
        char nextchar = board[rr][cc];
        if(nextchar!='a'-1&&root->childs[nextchar-'a'])
            dfs(result,root->childs[nextchar-'a'],board,rr,cc);
    }
    cur.pop_back();
    board[r][c] = t;
}
TrieNode* root;
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        for(int i=0;i<words.size();i++) insert(root,words[i]);
        vector<string> result;
        if(board.size()==0) return result;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++){
                string cur = "";
                dfs(result,root,board,i,j,cur);
            }
        }
    }
};
