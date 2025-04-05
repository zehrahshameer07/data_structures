#include <iostream>
using namespace std;

class Product {
public:
    string name;
    int price;

    void inputProduct() {
        cout << "Product name: ";
        cin.ignore();
        getline(cin, name);
        while (true) {
            cout << "Product price: ";
            cin >> price;
            if (cin.fail() || price <= 0) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid price! Please enter a positive integer." << endl;
            } else {
                break;
            }
        }
    }
};

class WardrobeCompany {
public:
    void bubbleSortByName(Product products[], int n);
    void selectionSortByName(Product products[], int n);
    void bubbleSortByPrice(Product products[], int n);
    void selectionSortByPrice(Product products[], int n);
    void display(Product products[], int n);
     void generateBill(Product products[], int n);
};

void WardrobeCompany::bubbleSortByName(Product products[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (products[j].name > products[j + 1].name) {
                swap(products[j], products[j + 1]);
            }
        }
    }
    cout << "Time Complexity: O(n^2) (Worst and Average Case), O(n) (Best Case - already sorted)" << endl;
}

void WardrobeCompany::selectionSortByName(Product products[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (products[j].name < products[minIndex].name) {
                minIndex = j;
            }
        }
        swap(products[minIndex], products[i]);
    }
    cout << "Time Complexity: O(n^2) (Worst, Average, and Best Case)" << endl;
}

void WardrobeCompany::bubbleSortByPrice(Product products[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (products[j].price > products[j + 1].price) {
                swap(products[j], products[j + 1]);
            }
        }
    }
    cout << "Time Complexity: O(n^2) (Worst and Average Case), O(n) (Best Case - already sorted)" << endl;
}

void WardrobeCompany::selectionSortByPrice(Product products[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (products[j].price < products[minIndex].price) {
                minIndex = j;
            }
        }
        swap(products[minIndex], products[i]);
    }
    cout << "Time Complexity: O(n^2) (Worst, Average, and Best Case)" << endl;
}

void WardrobeCompany::display(Product products[], int n) {
    cout << "\n-------------------------------------------" << endl;
    cout << "Product Name           Price (Rs.)" << endl;
    cout << "-------------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        cout << products[i].name << "                 Rs." << products[i].price << endl;
    }
    cout << "-------------------------------------------" << endl;
}

void WardrobeCompany::generateBill(Product products[], int n) {
    int total = 0;
    cout << "\n========= BILL =========" << endl;
    cout << "Product Name           Price (Rs.)" << endl;
    cout << "------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        cout << products[i].name << "                 Rs." << products[i].price << endl;
        total += products[i].price;
    }
    cout << "------------------------------" << endl;
    cout << "Total Price: Rs." << total << endl;
    
    float discount = 0;
    if (total > 2000) {
        discount = total * 0.1;
    } else if (total > 1000) {
        discount = total * 0.05;
    }
    
    cout << "Discount: Rs." << discount << endl;
    cout << "Final Price after Discount: Rs." << total - discount << endl;
    cout << "=============================" << endl;
}

int main() {
    cout << "\n===========================================" << endl;
    cout << "   WELCOME TO THE WARDROBE COMPANY   " << endl;
    cout << "===========================================" << endl;
    int n;
    while (true) {
        cout << "Enter number of products: ";
        cin >> n;
        if (cin.fail() || n <= 0) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter a positive integer." << endl;
        } else {
            break;
        }
    }

    Product products[n];
    cout << "Enter product names and prices: " << endl;
    for (int i = 0; i < n; i++) {
        products[i].inputProduct();
    }

    WardrobeCompany wc;
    int choice;
    do {
        cout << "\n===========================================" << endl;
        cout << "                SORTING MENU               " << endl;
        cout << "===========================================" << endl;
        cout << "1. Sort by Name (Bubble Sort)" << endl;
        cout << "2. Sort by Name (Selection Sort)" << endl;
        cout << "3. Sort by Price (Bubble Sort)" << endl;
        cout << "4. Sort by Price (Selection Sort)" << endl;
        cout << "5. Generate Bill" << endl;
        cout << "6. Exit" << endl;
        cout << "===========================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            choice = 0;
        }
        switch (choice) {
            case 1:
                wc.bubbleSortByName(products, n);
                cout << "\nProducts sorted by Name using Bubble Sort:" << endl;
                wc.display(products, n);
                break;
            case 2:
                wc.selectionSortByName(products, n);
                cout << "\nProducts sorted by Name using Selection Sort:" << endl;
                wc.display(products, n);
                break;
            case 3:
                wc.bubbleSortByPrice(products, n);
                cout << "\nProducts sorted by Price using Bubble Sort:" << endl;
                wc.display(products, n);
                break;
            case 4:
                wc.selectionSortByPrice(products, n);
                cout << "\nProducts sorted by Price using Selection Sort:" << endl;
                wc.display(products, n);
                break;
            case 5:
                wc.generateBill(products, n);
                break;
            case 6:
                cout << "Thank you for visiting The Wardrobe Company! Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please select again." << endl;
        }
    } while (choice != 6);
    return 0;
}

