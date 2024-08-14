#include <bits/stdc++.h>
using namespace std;

// Here, there is no need to use find function (nlog(n)).
// You can go with binary functions that take log(n) in a sorted array

int main() {
    int arr[] = {1,2,40,40,40,58};
    int n = sizeof(arr) / sizeof(int);
    bool present = binary_search(arr,arr+n,40);
    if(present){
        auto lb = lower_bound(arr,arr+n,40); // index of the first element that is >= key 
        auto ub = upper_bound(arr,arr+n,40); // index of the first element that is > key
        cout<<"the occ freq of 40 is "<<ub-lb;
    }
    else{
        cout<<0;
    }
}
