#include<iostream>
using namespace std;

void merge(int a[],int l,int h,int mid){
    int i,j,k;
    i = l;
    j = mid+1;
    k = l;
    int b[h+1];
   while(i <= mid && j <= h){
       if(a[i] < a[j])
            b[k++] = a[i++];
        else    
            b[k++] = a[j++];
   }
   for(;i <= mid; i++){
       b[k++]= a[i];
   }
   for(;j <= h; j++){
       b[k++]= a[j];
   }
   for(i = l;i <= h; i++){
       a[i] = b[i];
   }
}
 void mergeSort(int a[],int l,int h){
     int mid;
     if(l < h){
         mid = (l+h)/2;
         mergeSort(a,l,mid);
         mergeSort(a,mid+1,h);
         merge(a,l,h,mid);
     }
 }
int main(){
    int n;
    cout<<"Enter size: ";
    cin>> n;
    int arr[n];
    cout<<"Enter elements : ";
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    mergeSort(arr,0,n-1);
    cout<<"Sorted array is \n";
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}