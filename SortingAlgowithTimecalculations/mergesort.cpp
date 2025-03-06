#include <iostream>
#include <fstream>
#include <chrono>
#include <sstream>

using namespace std;
using namespace std::chrono;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    ifstream inputFile("random_numbers.txt");
    if (!inputFile) {
        cerr << "Could not open the input file!" << endl;
        return 1;
    }
    ofstream outputFile("output.txt");
    if (!outputFile) {
        cerr << "Could not open the output file!" << endl;
        return 1;
    }

    string line;
    int count=1;
    while (getline(inputFile, line)) {
        stringstream ss(line); 
        int size = 0;
        int num;
        int *arr = new int[count];
        while (ss >> num) {
            arr[size++] = num;
        }
        chrono::duration<double> total_duration = chrono::seconds(0); // initializing with zero second
        int *tempArr= new int[count];
        for(int i=0;i<100;i++){//same array run multiple times for better time average 
            copy(arr,arr+count,tempArr);//copying the original array data in temp array as same array is to be run multiple times
            auto start=chrono::high_resolution_clock::now();
            mergeSort(tempArr,0,count-1);
            auto stop=chrono::high_resolution_clock::now();
            chrono::duration<double> duration=stop-start;
            total_duration+=duration; // adding to total duration every time the for loop runs
        }
        outputFile << count << " " << total_duration.count()/100 << endl;
        count++;
        delete[] arr;
    }

    inputFile.close();
    outputFile.close();
    return 0;
}
