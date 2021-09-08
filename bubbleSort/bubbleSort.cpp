#include<iostream>
using namespace std;

int main(){
  int arr[]={1,2,3};

  for(int i=0;i<3;i++){
    bool check = false;
    for(int j=0;j<3-i-1;j++){
      if(arr[j] > arr[j+1]){
        swap(arr[j],arr[j+1]);
        check = true;
      } 
    }
    if(!check) break; 
  }

  for(auto i:arr) cout<<i<<" ";
  return 0;
}