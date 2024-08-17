#include <bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=b;i++)
#define ll long long int

ll find_index(ll s,ll e,ll arr[],int target){
    while(s <= e){
        int midde = (s + e)/2;
        if(arr[midde] == target){
            return midde;
        }
        else if(arr[s] <= arr[midde]){
            if(arr[midde] > target){
                e = midde-1;
            }
            else{
                s = midde+1;
            }
        }
        else{
            if(arr[s] > target){
                s = midde+1;
            }
            else{
                e = midde-1;
            }
        }
    }
    return -1;
}

int main() {
    ll n,target; cin>>n;
    ll arr[100];
    F(i,0,n-1){
        cin>>arr[i];
    }
    cin>>target;
    cout<<find_index(0,n-1,arr,target);
}
