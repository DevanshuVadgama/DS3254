#include <iostream>
#include <chrono>

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        std::cout << arr[i] << " ";
    }
}

void insertionsort(int arr[],int n){

for(int i=1;i<n;i++){
    int prev = i-1;
    int curr = i;
    while(prev>=0 && arr[prev]>arr[curr]){
        int holder = arr[prev];
        arr[prev] = arr[curr];
        arr[curr] = holder;
        prev--;
        curr--;
    }
}

}




int main() {
    int arr[] = {3,0,9,1,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    auto start = std::chrono::high_resolution_clock::now();
    insertionsort(arr, n);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    printArray(arr, n);
    std::cout << "Time taken: " << elapsed.count() << " seconds" << std::endl;
    return 0;
}