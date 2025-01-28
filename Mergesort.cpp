#include <iostream>
#include <chrono>

void printarr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void merge(int arr[], int l, int m, int r) {
    // Calculate the sizes of the two subarrays
    int x = m - l + 1;
    int y = r - m;

    int* Arr1 = new int[x];
    int* Arr2 = new int[y];

    for (int i = 0; i < x; i++) {
        Arr1[i] = arr[l + i];
    }
    for (int i = 0; i < y; i++) {
        Arr2[i] = arr[m + 1 + i];
    }

    int i = 0, j = 0, k = l;
    while (i < x && j < y) {
        if (Arr1[i] <= Arr2[j]) {
            arr[k] = Arr1[i];
            i++;
        } else {
            arr[k] = Arr2[j];
            j++;
        }
        k++;
    }

    while (i < x) {
        arr[k] = Arr1[i];
        i++;
        k++;
    }

    while (j < y) {
        arr[k] = Arr2[j];
        j++;
        k++;
    }

    // Deallocating the memory used by the temporary arrays
    delete[] Arr1;
    delete[] Arr2;
}

void mergesort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int arr[] = {8, 10, 9, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();


    mergesort(arr, 0, n - 1);  

    printarr(arr, n); 

    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
     std::chrono::duration<long long int, std::nano> duration = end - start;
     std::cout << duration.count() << std::endl;

    return 0;
}

//I used copilot for fixing the code as I wasn't able to pinpoint themistake I made in my earlier code 
//Although I am uploading my code below:

//#include <iostream>

//void printarr(int arr[],int n){
//for(int i=0 ; i<n ; i++){
//    std::cout<< arr[i] << " ";
//}
//}

//void merge(int arr[], int l, int m, int r){
   //firstly we ll mark the indices right(r) and left(l) and mid(m=l+r/2)
   
    //I ll create 2 temporary arrays; call it Arr1 and Arr2
  //  int x = m - l + 1;
    //int y = r - m;
    //int Arr1[x]; int Arr2[y];

    //we ll now fill the arrays

    //for(int i=0;i<x;i++){
    //Arr1[i] = arr[l+i];
    //}
    //for(int i= 0;i<y;i++){
    //Arr2[i] = arr[m+1+i];
    //}

 //Now we ll compare the elements and sort them using while loops   

//int i=0,j=0,k=l;
//while(i<x && j<y){
  //  if(Arr1[i]<=Arr2[j]){
    //    arr[k]=Arr1[i];
      //  i++;
    //}
    //else{
      //  arr[k]=Arr2[j];
        //j++;
    //}
      //  k++;

//} 

//while(i<x){
  //  arr[k]=Arr1[i];
    //i++;
    //k++;
//}

//while(j<y){
  //  arr[k]=Arr2[j];
   // j++;
    //k++;
//}
//The above 2 while while loops ensure that all the elements
//that might be left are also included.
//}

//void mergesort(int arr[],int l,int r){
  //  if(l<r){
    //    int m = (l+r)/2;

      //  mergesort(arr,l,m);
       // mergesort(arr,m+1,r);
        //merge(arr, l, m, r);
    //}
//}

//int main(){
//int arr[] = {8, 10, 9, 5};
//int n= sizeof(arr)/sizeof(arr[0]);

//mergesort(arr,0,n-1);

//printarr(arr,n);

//} 
