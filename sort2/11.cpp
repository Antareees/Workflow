#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

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
    int k = 1;
    for (int i = 0; i < n/2+1; ++i)
    {
        for (int j = 0; j < n - k - 1; ++j)
        {
            for (int l = 0; l < n - k - 1 - j ; ++l)
            {
                if (matrix[l][n - l - 1 - k] > matrix[l+1][n - l - 2 - k])
                    swap(matrix[l][n - l - 1 - k], matrix[l+1][n - l - 2 - k]);
            }

        }
        for (int j = 0; j < n - k - 1; ++j)
        {
            for (int l = 0; l < n - k - 1 - j; ++l)
            {
                if (matrix[l + k][n - l - 1] > matrix[l + k + 1][n - l - 2])
                    swap(matrix[l + k][n - l - 1], matrix[l + k + 1][n - l - 2]);
            }
        }
        k++;
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