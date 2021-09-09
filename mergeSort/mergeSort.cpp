void merge(int arr[],int low,int mid,int high){
  int n1,n2;
  
  n1 = mid-low+1;
  n2 = high-mid;

  int arr1[n1],arr2[n2];

  for(int i = 0;i<n1;i++) arr1[i]=arr[low+i];
  for(int i = 0;i<n2;i++) arr2[i]=arr[mid+1+i];

  int l,i,r;
  l=r=0;
  i=low;
  while(l<n1 && r<n2){
    if(arr1[l] <= arr2[r]){
      arr[i] = arr1[l];
      l++; 
    }else{
      arr[i] = arr2[r];
      r++;
    }
    i++;
  }

  while( l < n1){
    arr[i] = arr1[l];
    l++;
    i++;
  }
  while( r < n2){
    arr[i] = arr2[r];
    r++;
    i++;
  }
}
void mergeSort(int arr[],int low,int high){
  if(low<high){
    int mid = (low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
  }
}


int main(){
  int a[]={9,10,5,6,2,1,3,4,7,8};
  // for(int i=0;i<10;i++) cout<<a[i]<<" ";

  mergeSort(a,0,9);
  for(int i=0;i<10;i++) cout<<a[i]<<" ";
}