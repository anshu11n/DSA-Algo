#include<bits/stdc++.h>
using namespace std;
#define ll long long

void merge(vector<int> &arr, int left, int mid, int right){
    vector<int> l,r;

    for(int i=left; i<=mid; i++){
        l.push_back(arr[i]);
    }

    for(int i=mid+1; i<=right; i++){
        r.push_back(arr[i]);
    }

    int i=0, j=0;
    int k=left;

    while(i<l.size() && j<r.size()){
        if(l[i] < r[j]){
            arr[k] = l[i];
            i++;
        }else{
            arr[k] = r[j];
            j++;
        }

        k++;
    }

    while(i<l.size()){
        arr[k] = l[i];
        i++;
        k++;
    }

    while(j<r.size()){
        arr[k] = r[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int left, int right){
    if(left>=right) return;

    int mid = left + (right - left)/2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);

    merge(arr,  left, mid, right);
}

void solve(){
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    mergeSort(arr, 0, n-1);

    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
    return 0;
}