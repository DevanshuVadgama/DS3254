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
            InsertionSort(tempArr,count);
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
