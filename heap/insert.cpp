#include<iostream>
using namespace std;

class heap{
  public:
  int arr[100];
  int size =0;
  heap(){
      arr[0] = -1;
      size =0;
  }
  
  void insert(int val){
     size+=1;
     int idx = size;
     arr[idx] = val;
     // put in correct position
     while(idx>1){
         int parent = idx/2;
         if(arr[parent]<arr[idx]){
             swap(arr[parent],arr[idx]);
             idx = parent;
         }
         else{
             return ;
         }
     }
  }
  
  void print(){
      for(int i =1;i<=size;i++){
          cout<<arr[i]<<" ";
      }
  }
  
  void deleteFrom(){
      if(size ==0 ){
          cout<<"no element present";
          return;
      }
      int idx = size;
      size--;
      arr[1] = arr[idx];
      int lrg = 1;
      while(lrg<size){
          int lc = 2*idx;
          int rc = 2*idx+1;
          if(lc<size &&arr[lrg]<arr[lc]){
              lrg = lc;
          }
          if(lc<size && arr[lrg]<arr[rc]){
              lrg = rc;
          }
          
          if(lrg == idx){
              return;
          }
          else{
              swap(arr[lrg],arr[idx]);
              idx = lrg;
          }
      }
      
  }
};
int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deleteFrom();
    cout<<endl;
    h.print();
    
    h.deleteFrom();
    cout<<endl;
    h.print();
}