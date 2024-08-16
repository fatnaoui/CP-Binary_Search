#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define F(i,a,b) for(ll i=a;i<=b;i++)
#define RF(i,a,b) for(ll i=a;i>=b;i--)

ll max_crossing(ll s,ll middle,ll e,ll arr[]){
    ll sum = 0;
    ll left_sum = LLONG_MIN;
    RF(k,middle,s){
        sum += arr[k];
        left_sum = max(left_sum,sum);
    }
    sum = 0;
    ll right_sum = LLONG_MIN;
    F(k,middle+1,e){
        sum += arr[k];
        right_sum = max(right_sum,sum);
    }
    return left_sum + right_sum;
}

ll max_sum(ll s,ll e,ll arr[]){
    if(s == e){
        return arr[s];
    } 
    ll middle = (s+e)/2;
    ll a = 0, b = 0, c = 0;
    a = max_sum(s,middle,arr);
    b = max_sum(middle+1,e,arr);
    c = max_crossing(s,middle,e,arr);
    return max(a,max(b,c));
}

int main() {
    ll t; cin>>t;
    while(t--){
        ll n; cin>>n;
        ll arr[100];
        F(i,0,n-1){
            cin>>arr[i];
        }
        cout<<max_sum(0,n-1,arr)<<endl;
    }
}
