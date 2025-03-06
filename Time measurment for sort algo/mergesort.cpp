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
    while (getline(inputFile, line)) {
        stringstream ss(line);
        int arr[10001]; 
        int size = 0;
        int num;
        while (ss >> num) {
            arr[size++] = num;
        }
        auto start = high_resolution_clock::now();
        mergeSort(arr, 0, size - 1);
        auto end = high_resolution_clock::now();
        duration<double, milli> duration = end - start;
        outputFile << size << " " << duration.count() << endl;
    }

    inputFile.close();
    outputFile.close();
    return 0;
}
