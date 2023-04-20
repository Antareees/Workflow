#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void shell_sort(vector<vector<int>>& matrix, int col_index, int n) {
    for (int d = n / 2; d > 0; d /= 2) {
        for (int i = d; i < n; i++) {
            for (int j = i - d; j >= 0 && matrix[j][col_index] < matrix[j + d][col_index]; j -= d) {
                swap(matrix[j][col_index], matrix[j + d][col_index]);
            }
        }
    }
}
void shell_sort2(vector<vector<int>>& matrix, int col_index, int n) {
    for (int d = n / 2; d > 0; d /= 2) {
        for (int i = d; i < n; i++) {
            for (int j = i - d; j >= 0 && matrix[j][col_index] > matrix[j + d][col_index]; j -= d) {
                swap(matrix[j][col_index], matrix[j + d][col_index]);
            }
        }
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

    for (int j = 0; j < n; j += 2) {
        shell_sort(matrix, j, n);
    }
    for (int i = n-1; i > 0; i -= 2) {
        shell_sort2(matrix, i, n);
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