//Program to implement singly list ADT
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Node {
    int productID;        
    string productName;   
    float price;          
    string category;      
    Node *next;           
} *head, *temp;

class SLL {
public:
    int count = 0; // to keep track of the number of nodes in the list

    SLL() {
        head = NULL;
        temp = head;
    }

    void insert() {
        Node *newnode = new Node;
        cout << "\nEnter Product ID: ";
        cin >> newnode->productID;
        cout << "Enter Product Name: ";
		cin >> newnode->productName;
		cout << "Enter Product Price: ";
		cin >> newnode->price;
		cout << "Enter Product Category: ";
		cin >> newnode->category;

        // Validate input
        if (newnode->productID <= 0 || newnode->price <= 0) {
            cout << "Invalid input! Product ID and Price must be positive.\n";
            delete newnode;
            return;
        }

        newnode->next = NULL; 
        count++;

        if (head == NULL) {
            cout << "\nYour List is empty. Inserting at the beginning.\n";
            head = newnode;
            cout << "\nProduct inserted successfully!\n";
            return;
        }

        int ch;
        cout << "\nWhere do you want to Insert?";
        cout << "\n1. Insert at Beginning";
        cout << "\n2. Insert at Middle";
        cout << "\n3. Insert at Last\n";
        cin >> ch;

        Node *curr = head;
        Node *prev = NULL;
        switch (ch) {
        case 1:
            newnode->next = head;
            head = newnode;
            cout << "\nProduct inserted at the beginning successfully!\n";
            break;

        case 2: {
            int pos;
            cout << "\nWhich position do you want to insert? ";
            cin >> pos;
            if (pos <= 0 || pos > count) {
                cout << "\nInvalid position!\n";
                return;
            }

            int i = 1;
            while (curr != NULL) {
                if (i == pos) {
                    prev->next = newnode;
                    newnode->next = curr;
                    cout << "\nProduct inserted at position " << pos << " successfully!\n";
                    return;
                }
                prev = curr;
                curr = curr->next;
                i++;
            }
            break;
        }

        case 3:
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = newnode;
            cout << "\nProduct inserted at the end successfully!\n";
            break;

        default:
            cout << "\nInvalid choice!\n";
        }
    }

    // Function to display the entire list
    void display() {
        Node *cur = head;
        if (head == NULL) {
            cout << "\nList is Empty\n";
            return;
        }

        cout << "\nProducts in the List:\n";
        cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(10) << "Price" << "Category\n";
        cout << string(50, '-') << "\n";
        while (cur != NULL) {
            cout << left << setw(10) << cur->productID << setw(20) << cur->productName << setw(10) << cur->price << cur->category << "\n";
            cur = cur->next;
        }
        cout << "\nNumber of products in the list: " << count << "\n";
    }
    
    // Function to delete a product from the list
    void del() {
        if (head == NULL) {
            cout << "\nList is empty\n";
            return;
        }

        int ch;
        cout << "\nWhere do you want to Delete?";
        cout << "\n1. Delete at Beginning";
        cout << "\n2. Delete by Product Name";
        cout << "\n3. Delete at Last\n";
        cin >> ch;

        Node *curr = head;
        Node *prev = NULL;

        switch (ch) {
        case 1:
            head = head->next;
            delete curr;
            count--;
            cout << "\nProduct deleted from the beginning successfully!\n";
            break;

        case 2: {
            string prodName;
            cout << "\nEnter the product name to delete: ";
            cin >> prodName;
            while (curr != NULL) {
                if (curr->productName == prodName) {
                    if (prev == NULL) {
                        head = curr->next;
                    } else {
                        prev->next = curr->next;
                    }
                    delete curr;
                    count--;
                    cout << "\nProduct " << prodName << " deleted successfully!\n";
                    return;
                }
                prev = curr;
                curr = curr->next;
            }
            cout << "\nProduct not found!\n";
            break;
        }

        case 3:
            while (curr->next != NULL) {
                prev = curr;
                curr = curr->next;
            }
            if (prev != NULL) {
                prev->next = NULL;
            } else {
                head = NULL;
            }
            delete curr;
            count--;
            cout << "\nProduct deleted from the end successfully!\n";
            break;

        default:
            cout << "\nInvalid choice!\n";
        }
    }

    // Function to search for a product in the list
    void search() {
        if (head == NULL) {
            cout << "\nList is empty!\n";
            return;
        }

        int choice;
        cout << "\nSearch by: \n1. Product ID\n2. Position\n";
        cin >> choice;

        if (choice == 1) {
            int id;
            cout << "\nEnter Product ID: ";
            cin >> id;
            Node *curr = head;
            while (curr != NULL) {
                if (curr->productID == id) {
                    cout << "\nProduct Found: " << curr->productName << "\n";
                    return;
                }
                curr = curr->next;
            }
            cout << "\nProduct not found!\n";
        } else if (choice == 2) {
            int pos;
            cout << "\nEnter Position: ";
            cin >> pos;
            if (pos <= 0 || pos > count) {
                cout << "\nInvalid position!\n";
                return;
            }
            Node *curr = head;
            for (int i = 1; i < pos; i++) {
                curr = curr->next;
            }
            cout << "\nProduct Found: " << curr->productName << "\n";
        } else {
            cout << "\nInvalid choice!\n";
        }
    }

    // Function to count the total number of products in the list
    void countNodes() {
        cout << "\nTotal number of products: " << count << "\n";
    }
};

int main() {
    SLL obj;
    int ch;

    cout << "\nWelcome to the Wardrobe Company!\n";
    cout << "---------------------------------\n";

    do {
        cout << "\nEnter Choice:\n";
        cout << "1. Insert Item\n2. Display Item\n3. Delete Item\n4. Search Item\n5. Count Items\n6. Exit\n";
        cin >> ch;
        switch (ch) {
        case 1:
            obj.insert();
            break;
        case 2:
            obj.display();
            break;
        case 3:
            obj.del();
            break;
        case 4:
            obj.search();
            break;
        case 5:
            obj.countNodes();
            break;
        case 6:
            cout << "\nThank you for visiting the Fashion Store. Exiting...\n";
            break;
        default:
            cout << "\nInvalid choice!";
        }
    } while (ch != 6);

    return 0;
}

