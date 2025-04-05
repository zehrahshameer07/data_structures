// Program for Sparse Matrix Representation
#include <iostream>
using namespace std;
int main() {
    int a[100][100], i, j, row, col, zero_count = 0, row_index[100], col_index[100], k = 0;
    cout << "-----Program for Sparse Matrix Representation-----\n\n";
    cout << "Enter number of rows: ";
    cin >> row;
    cout << "Enter number of columns: ";
    cin >> col;
    cout << "\nEnter the elements of the matrix :\n";
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            cin >> a[i][j];
            if (a[i][j] == 0) {
                zero_count++;
            } else {
                row_index[k] = i;
                col_index[k] = j;
                k++;
            }
        }
    }
    cout << "\nResult:\n";
    if (zero_count >= (row * col / 2)) {
        cout << "This is a Sparse Matrix.\n";
    } else {
        cout << "This is a Dense Matrix.\n";
    }
    cout << "\nTriplet Representation of the Matrix:\n";
    cout << "-------------------------------------\n";
    cout << "Row\tColumn\tValue\n";
    cout << "-------------------------------------\n";
    for (i = 0; i < k; i++) {
        cout << row_index[i] << "\t" << col_index[i] << "\t" << a[row_index[i]][col_index[i]] << "\n";
    }
    cout << "-------------------------------------\n";

    return 0;
}

