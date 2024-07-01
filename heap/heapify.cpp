#include<iostream>
using namespace std;

void heapify(int arr[],int n,int i)
{
    
    
    int left = 2*i;
    int right = 2*i+1;
    int largest = i;
    if (left <= n && arr[largest] < arr[left])
        largest = left;
    if (right <= n && arr[largest] < arr[right])
        largest = right;
    if(largest == i) return ;
    else
    {
        swap(arr[i],arr[largest]);
        i = largest;
        heapify(arr,n,i); 
    }
}
void buildHeap(int arr[],int n)
{
    for(int i =n/2;i>0;i--)
    {
        heapify(arr,n,i);
    }
}


int main()
{
    int arr[] = {-1,12,15,13,11,14};
    int n = 5;
    buildHeap(arr,n);
    for(int i =1; i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}