#include <iostream>
#include <iomanip>
using namespace std;

class FashionStore {
private:
    int *id, num;
    string *itemName;
    float *price;
    float totalBill = 0; 

public:
    FashionStore() {
        cout << "==========================================\n";
        cout << "         WELCOME TO WARDROBE COMPANY         \n";
        cout << "==========================================\n\n";
        
        do {
            cout << "How many fashion items do you want to add? ";
            cin >> num;
            if (num <= 0) {
                cout << "Invalid input. Please enter a positive number.\n";
            }
        } while (num <= 0);
        
        cin.ignore();
        id = new int[num];
        itemName = new string[num];
        price = new float[num];
        
        for (int i = 0; i < num; i++) {
            cout << "\nEnter details for item " << i + 1 << ":\n";
            cout << "-----------------------------------\n";
            
            do {
                cout << "Item ID: ";
                cin >> id[i];
                if (id[i] <= 0) {
                    cout << "Invalid ID. Please enter a positive integer.\n";
                }
            } while (id[i] <= 0);
            
            cin.ignore();
            do {
                cout << "Item Name: ";
                getline(cin, itemName[i]);
                if (itemName[i].empty()) {
                    cout << "Item name cannot be empty. Please enter a valid name.\n";
                }
            } while (itemName[i].empty());
            
            do {
                cout << "Price (Rs.): ";
                cin >> price[i];
                if (price[i] <= 0) {
                    cout << "Invalid price. Please enter a positive number.\n";
                }
            } while (price[i] <= 0);
        }
    }
    
    ~FashionStore() {
        delete[] id;
        delete[] itemName;
        delete[] price;
    }
    
    int binarySearch() {
        int idToFind;
        cout << "\n==========================================\n";
        do {
            cout << "Please enter Item ID to search: ";
            cin >> idToFind;
            if (idToFind <= 0) {
                cout << "Invalid ID. Please enter a positive integer.\n";
            }
        } while (idToFind <= 0);
        
        int low = 0, high = num - 1, mid;
        while (low <= high) {
            mid = (low + high) / 2;
            if (id[mid] == idToFind) {
                cout << "\n==========================================\n";
                cout << "        ITEM DETAILS FOUND!           \n";
                cout << "------------------------------------------\n";
                cout << left << setw(15) << "Item Name:" << itemName[mid] << "\n";
                cout << left << setw(15) << "Price:" << "Rs. " << fixed << setprecision(2) << price[mid] << "\n";
                cout << left << setw(15) << "Location:" << "Aisle " << (mid + 1) << "\n";
                cout << "==========================================\n";
                return mid;
            }
            if (id[mid] > idToFind)
                high = mid - 1;
            else
                low = mid + 1;
        }
        cout << "\nItem not found in store.\n";
        return -1;
    }
    
    void purchaseItem() {
        int index = binarySearch();
        if (index != -1) {
            char choice;
            cout << "\nDo you want to buy this item? (y/n): ";
            cin >> choice;
            if (choice == 'y' || choice == 'Y') {
                totalBill += price[index];
                cout << "Item added to cart.\n";
            }
        }
    }
    
    void displayTotalBill() {
        cout << "\n==========================================\n";
        cout << "         PURCHASE SUMMARY           \n";
        cout << "------------------------------------------\n";
        cout << "Total Amount: Rs. " << fixed << setprecision(2) << totalBill << "\n";
        cout << "==========================================\n";
    }
};

int main() {
    FashionStore store;
    char choice;
    do {
        store.purchaseItem();
        cout << "\nDo you want to search and buy another item? (y/n): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
    
    store.displayTotalBill();
    
    cout << "\n==========================================\n";
    cout << "  THANK YOU FOR VISITING WARDROBE COMPANY!  \n";
    cout << "==========================================\n";
    return 0;
}

