#include <iostream>
#include <chrono>

//creating a function to print output as array

void printArray(int arr[],int n){
    for (int i=0;i<n;i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}


int main(){
    int arr[]={1,8,5,5,7};

    int n =sizeof(arr)/sizeof(arr[0]);

    //we have size of the array given by user ,Now I will sort the array using selection sort

auto t0 = std::chrono::high_resolution_clock::now();

    for(int i=0;i<n;i++){
        int minm=i;
        for (int j=i+1;j<n;j++){
            if (arr[j]<arr[minm]){
                minm=j;
            }
        }
            std::swap(arr[i],arr[minm]);
    }
    auto t1=std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time=t1-t0;
    printArray(arr,n);
    std::cout<<"Time taken to sort the array using selection sort is :"<<elapsed_time.count()<<" seconds"<<std::endl;

return 0;
}