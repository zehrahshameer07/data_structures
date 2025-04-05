#include <iostream>
#include <iomanip>
using namespace std;

class FashionQueue {
    int front, rear, size;
    string *items, *brands;
    int *quantities;
    float *prices;

public:
    FashionQueue() {
        rear = -1;
        front = -1;
        cout << "--- Welcome to The Wardrobe Company! ---\n";
        cout << "\nEnter the size of the queue: ";
        cin >> size;
        while (cin.fail() || size <= 0) {
            cout << "Invalid input! Enter a positive integer: ";
            cin.clear();
            cin.ignore(100, '\n');
            cin >> size;
        }
        items = new string[size];
        brands = new string[size];
        quantities = new int[size];
        prices = new float[size];
    }

    bool isFull() { return rear == size - 1; }
    bool isEmpty() { return front == -1 || front > rear; }

    void enqueue() {
        if (isFull()) {
            cout << "\nQueue is full! Cannot add more items.\n";
            return;
        }
        if (rear == -1) front = 0;
        rear++;

        cout << "Enter fashion item name: ";
        cin >> ws;
        getline(cin, items[rear]);

        cout << "Enter brand name: ";
        getline(cin, brands[rear]);

        cout << "Enter quantity: ";
        cin >> quantities[rear];

        while (cin.fail() || quantities[rear] <= 0) {
            cout << "Invalid quantity! Enter a positive integer: ";
            cin.clear();
            cin.ignore(100, '\n');
            cin >> quantities[rear];
        }
        
        cout << "Enter price per unit: ";
        cin >> prices[rear];
        while (cin.fail() || prices[rear] <= 0) {
            cout << "Invalid price! Enter a positive number: ";
            cin.clear();
            cin.ignore(100, '\n');
            cin >> prices[rear];
        }

        cout << "Item added successfully!\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "\nQueue is empty! No items to remove.\n";
            return;
        }
        cout << "Removed item: " << items[front] << " | Brand: " << brands[front] << " | Quantity: " << quantities[front] << " | Price: Rs." << prices[front] << "\n";
        front++;
        if (front > rear) front = rear = -1;
    }

    void peek() {
        if (isEmpty()) {
            cout << "\nQueue is empty! No front item.\n";
            return;
        }
        cout << "First Item: " << items[front] << " | Brand: " << brands[front] << " | Quantity: " << quantities[front]  << " | Price: Rs." << prices[front] << "\n";
    }

    void search() {
        if (isEmpty()) {
            cout << "\nQueue is empty! No items to search.\n";
            return;
        }
        string searchItem;
        cout << "Enter item name to search: ";
        cin >> ws;
        getline(cin, searchItem);
        for (int i = front; i <= rear; i++) {
            if (items[i] == searchItem) {
                cout << "Item found: " << items[i] << " | Brand: " << brands[i] << " | Quantity: " << quantities[i]  << " | Price: Rs." << prices[front] << "\n";
                return;
            }
        }
        cout << "Item not found.\n";
    }

     void display() {
        if (isEmpty()) {
            cout << "\nQueue is empty!\n";
            return;
        }
        cout << "\n--- Fashion Store Inventory ---\n";
        cout << left << setw(20) << "Item Name" << setw(20) << "Brand" << setw(10) << "Quantity" << setw(10) << "Price" << "\n";
        cout << "---------------------------------------------------------\n";
        for (int i = front; i <= rear; i++) {
            cout << left << setw(20) << items[i] << setw(20) << brands[i] << setw(10) << quantities[i] << setw(10) << prices[i] << "\n";
        }
    }


    void totalInventory() {
        if (isEmpty()) {
            cout << "\nTotal Inventory: 0 items\n";
            return;
        }
        int total = 0;
        for (int i = front; i <= rear; i++) {
            total += quantities[i];
        }
        cout << "\nTotal Inventory Count: " << total << " items\n";
    }

 void purchase() {
        if (isEmpty()) {
            cout << "\nQueue is empty! No items available for purchase.\n";
            return;
        }
        string buyItem;
        int buyQty;
        cout << "Enter item name to purchase: ";
        cin >> ws;
        getline(cin, buyItem);
        for (int i = front; i <= rear; i++) {
            if (items[i] == buyItem) {
                cout << "Enter quantity to purchase: ";
                cin >> buyQty;
                if (buyQty <= 0 || buyQty > quantities[i]) {
                    cout << "Invalid quantity!\n";
                    return;
                }
                float totalBill = buyQty * prices[i];
                quantities[i] -= buyQty;
                cout << "Purchase successful!\nTotal Bill: Rs." << fixed << setprecision(2) << totalBill << "\n";
                if (quantities[i] == 0) {
                    cout << "Item sold out! Removing from inventory.\n";
                    for (int j = i; j < rear; j++) {
                        items[j] = items[j + 1];
                        brands[j] = brands[j + 1];
                        quantities[j] = quantities[j + 1];
                        prices[j] = prices[j + 1];
                    }
                    rear--;
                    if (rear < front) front = rear = -1;
                }
                return;
            }
        }
        cout << "Item not found.\n";
    }
};


int main() {
    FashionQueue fq;
    int choice;
    while (true) {
        cout << "\n========= Fashion Store Queue =========\n";
        cout << "1. Add Item\n";
        cout << "2. Remove Item\n";
        cout << "3. View First Item\n";
        cout << "4. Search Item\n";
        cout << "5. View Inventory\n";
        cout << "6. Total Inventory Count\n";
        cout << "7. Purchase Item\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        while (cin.fail() || choice < 1 || choice > 8) {
            cout << "Invalid choice! Enter a number between 1-8: ";
            cin.clear();
            cin.ignore(100, '\n');
            cin >> choice;
        }

        switch (choice) {
            case 1: fq.enqueue(); break;
            case 2: fq.dequeue(); break;
            case 3: fq.peek(); break;
            case 4: fq.search(); break;
            case 5: fq.display(); break;
            case 6: fq.totalInventory(); break;
            case 7: fq.purchase(); break;
            case 8: cout << "Exiting...\n"; return 0;
        }
    }
}

