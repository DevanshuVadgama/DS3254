#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
using namespace std;


void InsertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && key<arr[j]){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}

int main() {
    ifstream inputFile("random_numbers.txt");
    if (!inputFile) {
        cerr << "Could not open the file!" << endl;
        return 1;
    }

    ofstream outputFile("output.txt");
    if (!outputFile) {
        cerr << "Could not open the output file!" << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        int arr[7001];
        int size = 0;
        int num;
        while (ss >> num) {
            arr[size++] = num;
        }
        auto start = chrono::high_resolution_clock::now();
        InsertionSort(arr, size);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, std::milli> duration = end - start;
        outputFile << size << " " << duration.count() << endl;
    }

    inputFile.close();
    outputFile.close();
    return 0;
}
