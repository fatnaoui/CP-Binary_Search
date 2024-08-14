#include <bits/stdc++.h>
using namespace std;

float square_root(int n,int p){
    int s = 0;
    int e = n;
    float ans = 0;
    while(s <= e){
        int middle = (s+e)/2;
        if(middle*middle == n){ return middle;}
        if(middle*middle < n){
            if(((middle+1)*(middle+1)) > n){
                ans = middle;
                break;
            }
            else{s = middle+1;}
        }
        else{
            e = middle-1;
        }
    }
    float inc = 0.1;
    for(int i=0;i<p;i++){
        while(ans*ans <n){
            ans += inc;
        }
        ans -= inc;
        inc /= 10;
    }
    return ans;
}

int main() {
    int n; cin>>n;
    cout<<square_root(n,3);
}
