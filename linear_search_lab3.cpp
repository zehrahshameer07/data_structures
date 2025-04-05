//Program to implement linear search
#include <iostream>
#include <iomanip>
using namespace std;

class FashionStore
{
    public:
        int itemCode;
        char itemName[50];
        int stock;
        float price;

    public:
        void addItem()
        {
            cout << "Enter Item Code (positive number): ";
            while (!(cin >> itemCode) || itemCode <= 0)
            {
                cout << "Invalid input! Enter a positive number for Item Code: ";
                cin.clear();
                cin.ignore(10000, '\n');
            }

            cout << "Enter Item Name: ";
            cin.ignore();
            cin.getline(itemName, 50);

            cout << "Enter Stock Quantity (positive integer): ";
            while (!(cin >> stock) || stock <= 0)
            {
                cout << "Invalid input! Enter a positive integer for Stock: ";
                cin.clear();
                cin.ignore(10000, '\n');
            }

            cout << "Enter Price (positive value): ";
            while (!(cin >> price) || price <= 0)
            {
                cout << "Invalid input! Enter a positive value for Price: ";
                cin.clear();
                cin.ignore(10000, '\n');
            }

            cout << "Item added successfully!\n";
        }

        void displayItem() const
        {
            cout << left << setw(12) << itemCode
                 << left << setw(20) << itemName
                 << left << setw(10) << stock
                 << left << setw(10) << fixed << setprecision(2) << price << "\n";
        }
};

int main()
{
    FashionStore items[100];
    int choice, itemCount = 0, searchCode;
    bool found;

    cout << "Welcome to the Fashion Store!\n";

    while (true)
    {
        cout << "\nWhat would you like to do today?\n";
        cout << "1. Explore New Arrivals\n";
        cout << "2. View All Items\n";
        cout << "3. Search for an Item\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice)
        {
            case 1:
                if (itemCount < 100)
                {
                    cout << "Adding a new item to the collection:\n";
                    items[itemCount].addItem();
                    itemCount++;
                }
                else
                {
                    cout << "Sorry, our collection is full!\n";
                }
                break;

            case 2:
                if (itemCount == 0)
                {
                    cout << "Our store is currently empty. Check back soon!\n";
                }
                else
                {
                    cout << left << setw(12) << "Item Code"
                         << left << setw(20) << "Item Name"
                         << left << setw(10) << "Stock"
                         << left << setw(10) << "Price" << "\n";
                    cout << string(52, '-') << "\n";

                    for (int i = 0; i < itemCount; i++)
                    {
                        items[i].displayItem();
                    }
                }
                break;

            case 3:
                cout << "Enter the Item Code to search: ";
                cin >> searchCode;
                found = false;

                for (int i = 0; i < itemCount; i++)
                {
                    if (items[i].itemCode == searchCode)
                    {
                        cout << "Item Found:\n";
                        cout << left << setw(12) << "Item Code"
                             << left << setw(20) << "Item Name"
                             << left << setw(10) << "Stock"
                             << left << setw(10) << "Price" << "\n";
                        cout << string(52, '-') << "\n";
                        items[i].displayItem();
                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    cout << "Sorry, we couldn't find an item with code " << searchCode << ".\n";
                }
                break;

            case 4:
                cout << "Thank you for visiting the Fashion Store. Have a great day!\n";
                return 0;

            default:
                cout << "Invalid choice! Please select a valid option.\n";
        }
    }

    return 0;
}

