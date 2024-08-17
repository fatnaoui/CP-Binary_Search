#include <bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=b;i++)
#define ll long long int

void quick_sort(ll s,ll e,ll arr[]){
    if(s >= e){
        return ;
    }
    ll pivot_idx = s + (rand() % (e - s + 1));
    ll pivot = arr[pivot_idx];
    swap(arr[e],arr[pivot_idx]);
    ll i = s, j = e-1;
    while(i <= j){
        if((arr[i] > arr[e]) && (arr[j] < arr[e])){
            swap(arr[i++],arr[j--]);
        }
        if(arr[i] <= arr[e]){
            i++;
        }
        if(arr[j] >= arr[e]){
            j--;
        }
    }
    swap(arr[e],arr[i]);
    quick_sort(s,i-1,arr);
    quick_sort(i+1,e,arr);
    return ;
}

int main() {
    ll n; cin>>n;
    ll arr[100];
    F(i,0,n-1){
        cin>>arr[i];
    }
    quick_sort(0,n-1,arr);
    F(i,0,n-1){
        cout<<arr[i]<<' ';
    }
}
