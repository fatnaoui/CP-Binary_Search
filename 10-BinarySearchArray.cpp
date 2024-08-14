#include <iostream>
using namespace std;

int n,key;
int arr[100];

int binary_search(int *arr,int s,int e){
    while(s <= e){
        int middle = (s+e)/2;
        if(arr[middle] == key){
            return middle;
        }
        else if(arr[middle] < key){
            s = middle+1;
        }
        else{
            e = middle-1;
        }
    }
    return -1;
}

int main() {
    cin>>n>>key;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<binary_search(arr,0,n-1);
}
