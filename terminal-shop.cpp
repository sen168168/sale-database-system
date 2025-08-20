#include <iostream>
#include <string>
using namespace std;

struct Product {
    string name;
    double price;
    int stock;
};

int main() {
    const int PRODUCT_COUNT = 10; 

    Product products[PRODUCT_COUNT] = {
        {"Apple", 1.5, 50},
        {"Banana", 0.8, 100},
        {"Orange", 1.2, 80},
        {"Milk", 2.0, 40},
        {"Bread", 1.7, 60},
        {"Eggs", 3.5, 30},
        {"Rice", 10.0, 25},
        {"Sugar", 5.0, 20},
        {"Coffee", 4.2, 15},
        {"Tea", 2.5, 35}
    };

    string username, password;

    cout << "=== Sale Database System ===\n";

    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    // --- USER LOGIN ---
    if (username == "user" && password == "1234") {
        int choice;
        do {
            cout << "\n--- User Menu ---\n";
            cout << "1. View Prices\n";
            cout << "2. Buy Products\n";
            cout << "0. Logout\n";
            cout << "Choice: ";
            cin >> choice;

            if (choice == 1) {
                cout << "\nPrice List:\n";
                for (int i = 0; i < PRODUCT_COUNT; i++) {
                    cout << i + 1 << ". " << products[i].name
                         << " - $" << products[i].price << endl;
                }
            }
            else if (choice == 2) {
                double cartTotal = 0;
                char buyMore;

                do {
                    int productID, qty;
                    cout << "\nProducts List:\n";
                    for (int i = 0; i < PRODUCT_COUNT; i++) {
                        cout << i + 1 << ". " << products[i].name << " - $" << products[i].price << endl;
                    }

                    while (true) {
                        cout << "Enter product ID (1-" << PRODUCT_COUNT << "): ";
                        if (cin >> productID) break;
                        cout << "Invalid input. Please enter numbers only.\n";
                        cin.clear();
                        cin.ignore(1000, '\n');
                    }

                    while (true) {
                        cout << "Enter quantity: ";
                        if (cin >> qty) break;
                        cout << "Invalid input. Please enter numbers only.\n";
                        cin.clear();
                        cin.ignore(1000, '\n');
                    }

                    if (productID < 1 || productID > PRODUCT_COUNT) {
                        cout << "Invalid product.\n";
                    }
                    else if (qty > products[productID - 1].stock) {
                        cout << "Not enough stock.\n";
                    }
                    else {
                        double subtotal = products[productID - 1].price * qty;
                        products[productID - 1].stock -= qty;
                        cartTotal += subtotal;
                        cout << "Added to cart. Subtotal: $" << subtotal << endl;
                    }

                    cout << "Do you want to buy another product? (y/n): ";
                    cin >> buyMore;

                } while (buyMore == 'y' || buyMore == 'Y');

                cout << "\n=== Checkout Complete ===\n";
                cout << "Final Total Price: $" << cartTotal << endl;
            }

        } while (choice != 0);
    }

    // --- ADMIN LOGIN ---
    else if (username == "admin" && password == "admin") {
        int choice;
        do {
            cout << "\n--- Admin Menu ---\n";
            cout << "1. View Stocks\n";
            cout << "2. View Prices\n";
            cout << "3. Update Prices\n";
            cout << "4. Update Stocks\n";
            cout << "0. Logout\n";
            cout << "Choice: ";
            cin >> choice;

            if (choice == 1) {
                cout << "\nStock List:\n";
                for (int i = 0; i < PRODUCT_COUNT; i++) {
                    cout << i + 1 << ". " << products[i].name
                         << " - " << products[i].stock << " units\n";  // <-- Fixed here
                }
            } 
            else if (choice == 2){
                cout << "\nPrice List:\n";
                for (int i = 0; i < PRODUCT_COUNT; i++) {
                    cout << i + 1 << ". " << products[i].name << " - $" << products[i].price << endl;
                } 
            } 
            else if (choice == 3) {
                int productID;
                double newPrice;

                cout << "\nCurrent Price List:\n";
                for (int i = 0; i < PRODUCT_COUNT; i++) {
                    cout << i + 1 << ". " << products[i].name << " - $" << products[i].price << endl;
                }

                while (true) {
                    cout << "Enter product ID (1-" << PRODUCT_COUNT << "): ";
                    if (cin >> productID) break;
                    cout << "Invalid input. Please enter numbers only.\n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }

                while (true) {
                    cout << "Enter new price: ";
                    if (cin >> newPrice) break;
                    cout << "Invalid input. Please enter numbers only.\n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }

                if (productID >= 1 && productID <= PRODUCT_COUNT) {
                    products[productID - 1].price = newPrice;
                    cout << "Price updated.\n";
                }
            }
            else if (choice == 4) {
                int productID, newStock;

                cout << "\nCurrent Stock List:\n";
                for (int i = 0; i < PRODUCT_COUNT; i++) {
                    cout << i + 1 << ". " << products[i].name
                         << " - " << products[i].stock << " units\n";  // <-- Fixed here too
                }

                while (true) {
                    cout << "Enter product ID (1-" << PRODUCT_COUNT << "): ";
                    if (cin >> productID) break;
                    cout << "Invalid input. Please enter numbers only.\n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }

                while (true) {
                    cout << "Enter new stock: ";
                    if (cin >> newStock) break;
                    cout << "Invalid input. Please enter numbers only.\n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }

                if (productID >= 1 && productID <= PRODUCT_COUNT) {
                    products[productID - 1].stock = newStock;
                    cout << "Stock updated.\n";
                }
            }

        } while (choice != 0);
    } 
    else {
        cout << "Login failed. Invalid credentials.\n";
    }

    cout << "Logged out. Goodbye!\n";
    return 0;
}
