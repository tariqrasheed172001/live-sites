#include<iostream>
using namespace std;

int search(int arr[],int n,int key){
    int i ;
    for(i = 0; i < n; i++){
        if(arr[i] == key){
            return i;
        }
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
	int res = search(arr, n,key);
    if(key == -1){
        cout << "KEY not found \n";
    }else{
        cout<<"Key found at "<<res<<endl;
    }
	return 0;
}