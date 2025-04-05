//Program to implement doubly list ADT
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Product {
    int productId;
    string productName;
    float price;
    string category;
    Product *next;
    Product *prev;
} *head, *tail;

class FashionStore {
public:
    int count = 0;

    FashionStore() {
        head = NULL;
        tail = head;
    }
    
    //function to insert an item
    void insert() {
        Product *newProduct = new Product;
        cout << "\nEnter Product ID: ";
        cin >> newProduct->productId;
        cout << "Enter Product Name: ";
		cin >> newProduct->productName;
		cout << "Enter Product Price: ";
		cin >> newProduct->price;
		cout << "Enter Product Category: ";
		cin >> newProduct->category;

        newProduct->next = NULL;
        newProduct->prev = NULL;
        count++;

        if (head == NULL) {
            cout << "The product list is empty. Adding at the beginning.\n";
            head = newProduct;
            tail = head;
            return;
        }

        int choice;
        cout << "\nWhere do you want to insert?\n";
        cout << "1. At the Beginning\n";
        cout << "2. At a Specific Position\n";
        cout << "3. At the End\n";
        cout << "Enter your choice: ";
        cin >> choice;

        Product *current = head;

        switch (choice) {
        case 1:
            newProduct->next = head;
            head->prev = newProduct;
            head = newProduct;
            cout << "Product added successfully at the beginning.\n";
            break;

        case 2: {
            int position;
            cout << "Enter the position to insert: ";
            cin >> position;
            if (position <= 1) {
                cout << "Invalid position.\n";
                return;
            }

            int i = 1;
            while (current != NULL && i < position - 1) {
                current = current->next;
                i++;
            }

            if (current == NULL) {
                cout << "Position out of bounds.\n";
                return;
            }

            newProduct->next = current->next;
            if (current->next != NULL)
                current->next->prev = newProduct;
            newProduct->prev = current;
            current->next = newProduct;

            if (newProduct->next == NULL)
                tail = newProduct;

            cout << "Product added successfully at position " << position << ".\n";
            break;
        }

        case 3:
            tail->next = newProduct;
            newProduct->prev = tail;
            tail = newProduct;
            cout << "Product added successfully at the end.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }
    }

    //function to delete an item   
    void del() {
        if (head == NULL) {
            cout << "The product list is empty.\n";
            return;
        }

        int choice;
        cout << "\nWhere do you want to delete?\n";
        cout << "1. From the Beginning\n";
        cout << "2. From a Specific Position\n";
        cout << "3. From the End\n";
        cout << "Enter your choice: ";
        cin >> choice;

        Product *current = head;

        switch (choice) {
        case 1:
            head = head->next;
            if (head != NULL)
                head->prev = NULL;
            else
                tail = NULL;
            delete current;
            count--;
            cout << "Product deleted from the beginning.\n";
            break;

        case 2: {
            int position;
            cout << "Enter the position to delete: ";
            cin >> position;
            if (position <= 0 || position > count) {
                cout << "Invalid position.\n";
                return;
            }

            for (int i = 1; i < position; i++)
                current = current->next;

            if (current->prev != NULL)
                current->prev->next = current->next;
            if (current->next != NULL)
                current->next->prev = current->prev;

            if (current == head)
                head = current->next;
            if (current == tail)
                tail = current->prev;

            delete current;
            count--;
            cout << "Product deleted from position " << position << ".\n";
            break;
        }

        case 3:
            current = tail;
            if (tail->prev != NULL)
                tail->prev->next = NULL;
            tail = tail->prev;

            if (tail == NULL)
                head = NULL;

            delete current;
            count--;
            cout << "Product deleted from the end.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }
    }
   
   //function to search for an item
    void search() {
        if (head == NULL) {
            cout << "The product list is empty.\n";
            return;
        }

        int choice;
        cout << "\nChoose search criteria:\n";
        cout << "1. Search by Product ID\n";
        cout << "2. Search by Product Name\n";
        cout << "Enter your choice: ";
        cin >> choice;

        Product *current = head;
        switch (choice) {
        case 1: {
            int id;
            cout << "Enter Product ID to search: ";
            cin >> id;

            while (current != NULL) {
                if (current->productId == id) {
                    cout << "Product found: " << current->productName << "\n";
                    return;
                }
                current = current->next;
            }
            cout << "Product with ID " << id << " not found.\n";
            break;
        }

        case 2: {
            string name;
            cout << "Enter Product Name to search: ";
            cin >> ws;
            getline(cin, name);

            while (current != NULL) {
                if (current->productName == name) {
                    cout << "Product found: ID " << current->productId << "\n";
                    return;
                }
                current = current->next;
            }
            cout << "Product with name " << name << " not found.\n";
            break;
        }

        default:
            cout << "Invalid choice.\n";
        }
    }

    //function to display the number of products in the list
    void displayCount() {
        cout << "\nTotal number of products: " << count << "\n";
    }

    //function to display the items from head to tail
    void forwardDisplay() {
        Product *current = head;
        if (current == NULL) {
            cout << "The product list is empty.\n";
            return;
        }

        cout << "\nProducts in the List(head to tail):\n";
        cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(10) << "Price" << "Category\n";
        cout << string(50, '-') << "\n";
        while (current != NULL) {
            cout << left << setw(10) << current->productId << setw(20) << current->productName << setw(10) << current->price << current->category << "\n";
            current = current->next;
        }
    }

    //function to display the items from tail to head
    void backwardDisplay() {
        Product *current = tail;
        if (current == NULL) {
            cout << "The product list is empty.\n";
            return;
        }

        cout << "\nProducts in the List(tail to head):\n";
        cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(10) << "Price" << "Category\n";
        cout << string(50, '-') << "\n";
        while (current != NULL) {
            cout << left << setw(10) << current->productId << setw(20) << current->productName << setw(10) << current->price << current->category << "\n";
            current = current->prev;
        }
    }
};

int main() {
    FashionStore store;
    int choice;

    cout << "\nWelcome to the Wardrobe Company!\n";
    cout << "---------------------------------\n";

    while (true) {
        cout << "\nFashion Store Menu:\n";
        cout << "1. Insert a Product\n";
        cout << "2. Delete a Product\n";
        cout << "3. Search for a Product\n";
        cout << "4. Display Product Count\n";
        cout << "5. Display Products Forward\n";
        cout << "6. Display Products Backward\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            store.insert();
            break;
        case 2:
            store.del();
            break;
        case 3:
            store.search();
            break;
        case 4:
            store.displayCount();
            break;
        case 5:
            store.forwardDisplay();
            break;
        case 6:
            store.backwardDisplay();
            break;
        case 7:
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}

