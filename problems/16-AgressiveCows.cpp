#include <bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=b;i++)
#define ll long long int

bool is_possible(ll n,ll c,ll arr[],ll middle){
    c--;
    ll cur_dist = arr[0];
    F(i,1,n-1){
        if((arr[i] - cur_dist) >= middle){
            cur_dist = arr[i];
            c--;
            if(c == 0){
                return true;
            }
        }
    }
    return false;
}

ll max_dist(ll n,ll arr[],ll c,ll maxx,ll &ans){
    ll s = 1;
    ll e = maxx;
    while(s <= e){
        ll middle =(s + e)/2;
        if(is_possible(n,c,arr,middle)){
            s = middle+1;
            ans = max(ans,middle);
        }
        else{
            e = middle-1;
        }
    }
    return ans;
}

int main() {
    ll n,c; cin>>n>>c;
    ll arr[100];
    ll maxx = LLONG_MIN;
    ll ans = LLONG_MIN;
    F(i,0,n-1){
        cin>>arr[i];
        maxx = max(maxx,arr[i]);
    }
    sort(arr,arr+n);
    cout<<max_dist(n,arr,c,maxx,ans);
}
