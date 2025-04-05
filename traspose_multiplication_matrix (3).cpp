#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
    int a[100][100], b[100][100], c[100][100] = {0};
    int r1, c1, r2 = 0, c2 = 0, i, j, k;
    

    // Input number of schools (rows) and categories (columns)
    cout << "\n========================================\n";
    cout << "    Dance Competition Score Matrix    \n";
    cout << "========================================\n\n";
    cout << "Enter the number of schools (rows) and categories (columns) (max 100): ";
    cin >> r1 >> c1;
    

    // Validate input 
    if (r1 <= 0 || c1 <= 0 || r1 > 100 || c1 > 100)
	{
        cout << "Invalid! Schools and categories must be between 1 and 100.\n";
        return 0; // Exit if invalid input
    }
    
    
    // Input Scores for Matrix A (Schools and Categories)
    cout << "\nEnter the scores for the dance competition:\n";
    cout << "(Each score represents the performance in a specific category for each school)\n";
    for (i = 0; i < r1; i++) 
	{
        for (j = 0; j < c1; j++) 
		{
            cout << "Score for School " << i + 1 << " in Category " << j + 1 << ": ";
            cin >> a[i][j];

            // Check if each score is valid
            if (a[i][j] < 0 || a[i][j] > 100) {
                cout << "Invalid score! Scores must be between 0 and 100.\n";
                return 0; // Exit if invalid score
            }
        }
    }


    // Transpose Matrix A to Matrix B
    for (i = 0; i < c1; i++)
	 {
	 	c2=0;
        for (j = 0; j < r1; j++)
		{
            b[i][j] = a[j][i];
            c2++;
        }
        r2++;  // r2 will be the number of categories, c2 will be the number of schools
    }


    // Print Original Matrix (Scores by School and Category)
    cout << "\n\n========================================\n";
    cout << "        Dance Competition Scores       \n";
    cout << "========================================\n";
    cout << "\nScores for the Dance Competition (Matrix A):\n";
    cout << "----------------------------------------\n";
    cout << "   School \\ Category | ";
    for (j = 0; j < c1; j++) 
	{
        cout << setw(5) << "C" << j + 1;
    }
    cout << "\n----------------------------------------\n";
    for (i = 0; i < r1; i++) 
	{
        cout << "    S" << i + 1 << "              | ";
        for (j = 0; j < c1; j++) 
		{
            cout << setw(5) << a[i][j];
        }
        cout << "\n";
    }


    // Print Transposed Matrix (Scores by Category and School)
    cout << "\n\n\n========================================\n";
    cout << "        Transposed Scores (Matrix B)   \n";
    cout << "========================================\n";
    cout << "\nTransposed Scores (Matrix B):\n";
    cout << "----------------------------------------\n";
    cout << "   Category \\ School | ";
    for (i = 0; i < r1; i++) 
	{
        cout << setw(5) << "S" << i + 1;
    }
    cout << "\n----------------------------------------\n";
    for (i = 0; i < r2; i++) 
	{
        cout << "    C" << i + 1 << "              | ";
        for (j = 0; j < c2; j++) 
		{
            cout << setw(5) << b[i][j];
        }
        cout << "\n";
    }


    // Matrix Multiplication (A * B) to calculate the resultant matrix
    for (i = 0; i < r1; i++) 
	{  
        for (j = 0; j < c2; j++) 
		{  // For each school 
            for (k = 0; k < c1; k++) 
			{  // For each category 
                c[i][j] += a[i][k] * b[k][j];  // Multiply scores from matrix A with transposed B
            }
        }
    }


    // Print Resultant Matrix (C = A * B) (multiplication of original and transposed matrix)
    cout << "\n\n\n========================================\n";
    cout << "Resultant Matrix (C = A * B):\n";
    cout << "----------------------------------------\n";
    cout << "   School \\ School | ";
    for (j = 0; j < c2; j++)
	{
        cout << setw(5) << "S" << j + 1;
    }
    cout << "\n----------------------------------------\n";
    for (i = 0; i < r1; i++) 
	{
        cout << "    S" << i + 1 << "              | ";
        for (j = 0; j < c2; j++) 
		{
            cout << setw(5) << c[i][j];
        }
        cout << "\n";
    }
    

    cout << "\n\n\n========================================\n";
    cout << "                    END             \n";
    cout << "========================================\n";
    

    return 0;
}

