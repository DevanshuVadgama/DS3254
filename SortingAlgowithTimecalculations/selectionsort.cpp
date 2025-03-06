#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <string>

using namespace std;
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
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
            selectionSort(tempArr,count);
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
