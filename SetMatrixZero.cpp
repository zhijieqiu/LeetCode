//remember when the problem desires to use const extra space to store some information on the source matrix
//同样的有一题关于某个算法的题目，minStack 使用O(1)的存储空间
Class Solution{
public:
  void setZeros(vector<vector<int> >& matix){
    if(matrix.size()==0) return;
    int height = matrix.size(),width=matrix[0].size();
    bool firstRow = false,firstCol=false;
    for(int i=0;i<width;i++){
      if(matrix[0][i]==0){ firstRow=true; break;}
    }
    for(int i=0;i<height;i++){
      if(matrix[i][0] == 0) {firstCol=true;break;};
    }
    for(int i=1;i<height;i++){
      for(int j=1;j<width;j++){
        if(matrix[i][j]==0){
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }
    for(int i=1;i<height;i++){
      for(int j=1;j<width;j++){
        if(matrix[i][0]==0||matrix[0][j]==0) matrix[i][j] = 0;
      }
    }
    if(firstRow)
      for(int i=0;i<width;i++) matrix[0][i] = 0;
    if(firstCol) for(int i=0;i<height;i++) matrix[i][0]=0;
  }
};
