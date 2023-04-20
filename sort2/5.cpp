#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void heapify(vector<int> &arr, int N, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < N && arr[l] > arr[largest])
        largest = l;

    if (r < N && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, N, largest);
    }
}

void heap_sort(vector<int> &arr, int N) {
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    for (int i = N - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    string input_file = "input.txt";
    string output_file = "output.txt";

    ifstream input(input_file);

    input >> n;
    vector<vector<int>> matrix(n, vector<int>(n));  

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            input >> matrix[i][j];
        }
    }
    
    input.close();

    for (int col = 0; col < n; col++) {
        vector<int> tmp_arr(n);

        for (int j = 0; j < n; j++) {
            tmp_arr[j] = (matrix[j][col]);
        }

        heap_sort(tmp_arr, n);

        for (int j = 0; j < n; j++) {
            matrix[j][col] = tmp_arr[j];
        }
    }

    ofstream output(output_file);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            output << matrix[i][j] << " ";
        }
        output << endl;
    }

    output.close();

    return 0;
}