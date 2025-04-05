#include <iostream>
#include <iomanip> 
using namespace std;

class FashionStore {
private:
    struct FashionItem {
        string name;
        double price;
    };

    FashionItem* items;
    int n;
    int comparisons, swaps; 

    void swap(FashionItem &a, FashionItem &b) {
        FashionItem temp = a;
        a = b;
        b = temp;
        swaps++;
    }

    int partition(int low, int high) {
        double pivot = items[low].price; 
        int i = low + 1, j = high;

        while (i <= j) {
            while (i <= j && items[i].price <= pivot) { i++; comparisons++; }
            while (i <= j && items[j].price >= pivot) { j--; comparisons++; }

            if (i < j) {
                swap(items[i], items[j]);
                i++; j--;
            }
        }
        swap(items[low], items[j]); 
        return j;
    }

    void quickSort(int low, int high) {
        if (low < high) {
            int pos = partition(low, high);
            quickSort(low, pos - 1);
            quickSort(pos + 1, high);
        }
    }

public:
    FashionStore(int size) {
        n = size;
        items = new FashionItem[n];
        comparisons = swaps = 0; 
    }

    void inputItems() {
        cin.ignore(); 
        for (int i = 0; i < n; i++) {
            cout << "Enter name of item " << i + 1 << ": ";
            getline(cin, items[i].name);

            while (true) {
                cout << "Enter price of " << items[i].name << ": Rs";
                cin >> items[i].price;
                if (items[i].price >= 0) break;
                cout << "Invalid price! Must be non-negative. Try again.\n";
            }
            cin.ignore();
        }
    }

    void displayItems() {
        cout << "\n---------------------------------------\n";
        cout << setw(20) << left << "Item Name" << setw(10) << "Price (Rs)\n";
        cout << "---------------------------------------\n";
        for (int i = 0; i < n; i++) {
            cout << setw(20) << left << items[i].name << "Rs" 
                 << fixed << setprecision(2) << items[i].price << "\n";
        }
        cout << "---------------------------------------\n";
    }

    double calculateTotalPrice() {
        double total = 0;
        for (int i = 0; i < n; i++) {
            total += items[i].price;
        }
        return total;
    }

    void sortAndAnalyze() {
        cout << "\nFashion Items Before Sorting:";
        displayItems();

        quickSort(0, n - 1);

        cout << "\nFashion Items After Sorting (by Price):";
        displayItems();

        cout << "\nTotal Amount of All Fashion Items: Rs" 
             << fixed << setprecision(2) << calculateTotalPrice() << "\n";

        cout << "\nTotal Comparisons: " << comparisons;
        cout << "\nTotal Swaps: " << swaps;

        cout << "\n\nTime Complexity of Quick Sort:\n";
        cout << "Best Case: O(n log n)\n";
        cout << "Average Case: O(n log n)\n";
        cout << "Worst Case : O(n^2)\n";
    }

    ~FashionStore() {
        delete[] items;
    }
};

int main() {
    cout << "\n========================================\n";
    cout << "   Welcome to The Wardrobe Company!   \n";
    cout << "========================================\n";

    int n;
    cout << "Enter number of fashion items: ";
    cin >> n;

    FashionStore store(n);
    store.inputItems();
    store.sortAndAnalyze();

    return 0;
}

