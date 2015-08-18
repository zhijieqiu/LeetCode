#include <iostream>
double myramd(){
    return rand()*1.0/RAND_MAX;
}
void shuffle2(vector<int>& arr){
  srand(time(NULL));
  for(int i=0;i<arr.size();i++){
    int t = i+myrand()*(arr.size()-1-i);
    swap(arr[i],arr[t]);
  }
  for(int i=0;i<arr.size();i++){
    cout<<arr[i]<<endl;
  }
}
void shuffle(vector<int>& arr){
    srand(time(NULL));
    //rand();
    for(int i=0;i<arr.size();i++){
        int t = myramd()*i;
        swap(arr[t],arr[i]);
    }
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}

