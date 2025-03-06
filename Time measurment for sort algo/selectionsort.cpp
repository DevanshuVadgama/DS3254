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
        selectionSort(arr, size);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, std::milli> duration = end - start;
        outputFile << size << " " << duration.count() << endl;
    }

    inputFile.close();
    outputFile.close();
    return 0;
}
