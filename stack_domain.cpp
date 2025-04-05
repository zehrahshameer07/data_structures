// Program to implement a Stack using ADT 
#include <iostream>
#include <iomanip>
using namespace std;

class FashionStack {
    int top, size;
    string *itemName, *brand;

public:
    FashionStack();  
    void push();     
    void pop();      
    void peek();    
    void search();  
    void display();  
};


FashionStack::FashionStack() {
    top = -1;
    cout << "---Welcome to the Wardrobe Company!----\n";
    cout << "\nEnter the size of the stack: ";
    cin >> size;
    itemName = new string[size];
    brand = new string[size];
}

// Push operation
void FashionStack::push() {
    if (top == size - 1) {
        cout << "Stack is full! Cannot add more items.\n";
        return;
    }
    top++;
    cout << "Enter fashion item name: ";
    cin >> ws;
    getline(cin, itemName[top]);
    cout << "Enter brand: ";
    getline(cin, brand[top]);
    cout << "Item added successfully!\n";
}

// Pop operation
void FashionStack::pop() {
    if (top == -1) {
        cout << "Stack is empty! Nothing to remove.\n";
        return;
    }
    cout << "Removed: " << itemName[top] << " by " << brand[top] << "\n";
    top--;
}

// Peek operation
void FashionStack::peek() {
    if (top == -1) {
        cout << "Stack is empty! No top item.\n";
        return;
    }
    cout << "Top Item: " << itemName[top] << " by " << brand[top] << "\n";
}

// Search operation
void FashionStack::search() {
    if (top == -1) {
        cout << "Stack is empty! No items to search.\n";
        return;
    }
    string query;
    cout << "Enter item name to search: ";
    cin >> ws;
    getline(cin, query);
    for (int i = 0; i <= top; i++) {
        if (itemName[i] == query) {
            cout << "Found: " << itemName[i] << " by " << brand[i] << "\n";
            return;
        }
    }
    cout << "Item not found.\n";
}

// Display operation
void FashionStack::display() {
    if (top == -1) {
        cout << "Stack is empty!\n";
        return;
    }
    cout << "\nFashion Store Inventory:\n";
    cout << left << setw(20) << "Item Name" << setw(20) << "Brand" << "\n";
    cout << "----------------------------------------\n";
    for (int i = top; i >= 0; i--) {
        cout << left << setw(20) << itemName[i] << setw(20) << brand[i] << "\n";
    }
}


int main() {
    FashionStack s;
    int choice;
    while (true) {
        cout << "\n1. Add Item\n2. Remove Item\n3. Peek Top Item\n4. Search Item\n5. Display Inventory\n6. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: s.push(); break;
            case 2: s.pop(); break;
            case 3: s.peek(); break;
            case 4: s.search(); break;
            case 5: s.display(); break;
            case 6: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice! Try again.\n";
        }
    }
}

