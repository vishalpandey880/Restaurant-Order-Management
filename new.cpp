#include <iostream>
#include <vector>
using namespace std;

struct Item {
  int id;
  string name;
  int price;
};

struct Order {
  string name;
  int qty;
  int price;
};

int main() {

  vector<Item> menu = {{1, "Burger", 80},
                       {2, "Pizza", 150},
                       {3, "Pasta", 120},
                       {4, "Salad", 70},
                       {5, "Soda", 40}};

  vector<Order> orders;

  int mainChoice;
  int itemChoice, qty;
  int total = 0;

  do {

    cout << "\n====== RESTAURANT SYSTEM ======\n";
    cout << "1. Show Menu\n";
    cout << "2. Order Food\n";
    cout << "3. View Bill\n";
    cout << "4. Exit\n";

    cout << "Enter choice: ";
    cin >> mainChoice;

    if (mainChoice == 1) {

      cout << "\n----- MENU -----\n";
      cout << "ID\tItem\tPrice\n";

      for (int i = 0; i < menu.size(); i++) {
        cout << menu[i].id << "\t" << menu[i].name << "\t₹" << menu[i].price
             << endl;
      }
    }

    else if (mainChoice == 2) {

      cout << "\nEnter Item ID: ";
      cin >> itemChoice;

      if (itemChoice >= 1 && itemChoice <= 5) {

        cout << "Enter Quantity: ";
        cin >> qty;

        Order o;
        o.name = menu[itemChoice - 1].name;
        o.qty = qty;
        o.price = menu[itemChoice - 1].price;

        orders.push_back(o);

        cout << "Item Added Successfully\n";
      } else {
        cout << "Invalid Item\n";
      }
    }

    else if (mainChoice == 3) {

      cout << "\n======= RECEIPT =======\n";
      cout << "Item\tQty\tPrice\tTotal\n";

      total = 0;

      for (int i = 0; i < orders.size(); i++) {

        int sub = orders[i].qty * orders[i].price;

        cout << orders[i].name << "\t" << orders[i].qty << "\t₹"
             << orders[i].price << "\t₹" << sub << endl;

        total += sub;
      }

      cout << "-----------------------\n";
      cout << "TOTAL BILL = ₹" << total << endl;
    }

  } while (mainChoice != 4);

  cout << "\nThank You! Visit Again\n";

  return 0;
}