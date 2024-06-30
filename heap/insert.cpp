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
             swap(arr[parent"]",arr[idx]);
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
};
int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
}