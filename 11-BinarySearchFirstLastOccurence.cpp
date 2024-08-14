#include <iostream>
using namespace std;

int n,key;
int arr[100];

int first_occurence(){
    int result = -1;
    int s = 0;
    int e = n-1;
    while(s <= e){
        int middle = (e+s)/2;
        if(arr[middle] == key){
            result = middle;
            e = middle-1;
        }
        else if(arr[middle] < key){
            s = middle+1;
        }
        else{
            e = middle-1;
        }
    }
    return result;
}

int last_occurence(){
    int result = -1;
    int s = 0;
    int e = n-1;
    while(s <= e){
        int middle = (e+s)/2;
        if(arr[middle] == key){
            result = middle;
            s = middle+1;
        }
        else if(arr[middle] < key){
            s = middle+1;
        }
        else{
            e = middle-1;
        }
    }
    return result;
}

int main() {
    cin>>n>>key;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<first_occurence();
    cout<<endl;
    cout<<last_occurence();
}
