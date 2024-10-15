#include<bits/stdc++.h>
using namespace std;
#define ll long long

class heap{
    public:
    int arr[100];
    int size;

    heap(){
        arr[0]=-1;
        size=0;
    }

    void insert(int val){
        // O(log n)

        size++;
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parent = index/2;

            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }else{
                return;
            }
        }
    }

    void deletion(){
        // O(log n)

        // always root node delete
        // last node to root node replace first
        // remove last node
        // propagate root node to correct poistion

        if(!size) cout<<"nothing to delete"<<endl;

        arr[1] = arr[size];
        size--;

        // take root node to its correct pos

        int i=1; 
        while(i<size){
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;

            if(leftIndex < size && arr[i] < arr[leftIndex] && arr[leftIndex] > arr[rightIndex]){
                swap(arr[i], arr[leftIndex]);
                i=leftIndex;
            }else if(rightIndex < size && arr[i] < arr[rightIndex] && arr[leftIndex] < arr[rightIndex]){
                swap(arr[i], arr[rightIndex]);
                i=rightIndex;
            }else{
                return;
            }
        }
    }

    void print(){
        for(int i=1; i<=size; i++){
            cout<<arr[i]<<" ";
        } cout<<endl;
    }
};

void heapify(int arr[], int n, int i){
    // O(log n)

    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }

    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    int size=n;

    while(size>1){
        // step1 swap
        swap(arr[1], arr[size]);

        // step2
        size--;

        // step3
        heapify(arr, size, 1);
    }
}

void solve(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.deletion();
    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n=5;

    // leaf node lies from (n/2+1)th to n th

    // from n/2+1 to n there will be leaf nodes, so no need to do them 
    for(int i=n/2; i>0; i--){
        heapify(arr, n, i);
    }

    // O(n) Time complexity

    for(int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    } cout<<endl;

    // so to convert an array to heap (max or min) we can use this above algo of heapify


    // ----------------------------------
    heapSort(arr, n);
    // TC O(n (log n))

    for(int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    } cout<<endl;  

    // so to normally sort an arr, first convert it in heap, then apply heap sort  
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
    return 0;
}