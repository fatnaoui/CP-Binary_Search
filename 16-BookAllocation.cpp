#include <bits/stdc++.h>
using namespace std;

bool is_possible(int n,int m,int arr[],int middle){
    int c = 1;
    int reset = 0;
    for(int i=0;i<n;i++){
        if(reset+arr[i] > middle){
            c++;
            reset = arr[i];
            if(c > m){ return false;}
        }
        else{
            reset += arr[i];
        }
    }
    return true;
}

int min_pages(int n,int m,int arr[],int sum){
    int s = arr[n-1];
    int e = sum;
    int ans = INT_MAX;
    while(s <= e){
        int middle = (s+e)/2;
        if(is_possible(n,m,arr,middle)){
            ans = min(ans,middle);
            e = middle - 1;
        }
        else{
            s = middle + 1;
        }
    }
    return ans;
}

int main() {
    int n,m;
    cin>>n>>m;
    int arr[100];
    int sum = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum += arr[i];
    }
    cout<<min_pages(n,m,arr,sum);
}
