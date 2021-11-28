#include<iostream>
using namespace std;

int binarySearch(int arr[],int l,int r,int key){
    
    if(r >= l){
        int mid = (l+(r-1))/2;
        if(arr[mid] == key)
            return mid;
        if(arr[mid] > key){
            return binarySearch(arr,l,mid-1,key);
        }
        return binarySearch(arr,mid+1,r,key);
    }
    
    return -1;
}
int main(){
    int n;
    cout<<"Enter size: ";
    cin>> n;
    int arr[n];
    cout<<"Enter elements : ";
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    int key;
    cout<<"Enter key : ";
    cin>>key;
	int res = binarySearch(arr,0,n-1,key);
    if(key == -1){
        cout << "KEY not found \n";
    }else{
        cout<<"Key found at "<<res<<endl;
    }
	return 0;
}