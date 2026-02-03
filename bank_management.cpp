#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Bank {
private:
    struct Person {
        string name;
        string id;
        string address;
        long long contact;
        int cash;
    };

    Person persons[100];
    int total;

public:
    Bank() {
        total = 0;
    }

    void menu();
    void createAccount();
    void showAll();
    void updateAccount();
    void searchAccount();
    void transaction();
    void deleteAccount();
};

int main() {
    Bank b;
    b.menu();
    return 0;
}

void Bank::menu() {
    int choice;

    while (true) {
        cout << "\n----- BANK MANAGEMENT SYSTEM -----\n";
        cout << "1. Create new account\n";
        cout << "2. View all customers\n";
        cout << "3. Update account\n";
        cout << "4. Search account\n";
        cout << "5. Transaction\n";
        cout << "6. Delete account\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createAccount(); break;
            case 2: showAll(); break;
            case 3: updateAccount(); break;
            case 4: searchAccount(); break;
            case 5: transaction(); break;
            case 6: deleteAccount(); break;
            case 7: exit(0);
            default: cout << "Invalid choice\n";
        }
    }
}

void Bank::createAccount() {
    if (total >= 100) {
        cout << "Account limit reached\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nEnter details for account " << total + 1 << endl;

    cout << "Name: ";
    getline(cin, persons[total].name);

    cout << "ID: ";
    getline(cin, persons[total].id);

    cout << "Address: ";
    getline(cin, persons[total].address);

    cout << "Contact: ";
    cin >> persons[total].contact;

    cout << "Initial Cash: ";
    cin >> persons[total].cash;

    total++;
    cout << "Account created successfully\n";
}

void Bank::showAll() {
    if (total == 0) {
        cout << "No records found\n";
        return;
    }

    for (int i = 0; i < total; i++) {
        cout << "\nCustomer " << i + 1 << endl;
        cout << "Name: " << persons[i].name << endl;
        cout << "ID: " << persons[i].id << endl;
        cout << "Address: " << persons[i].address << endl;
        cout << "Contact: " << persons[i].contact << endl;
        cout << "Cash: " << persons[i].cash << endl;
    }
}

void Bank::updateAccount() {
    string id;
    cout << "Enter ID to update: ";
    cin >> id;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < total; i++) {
        if (persons[i].id == id) {
            cout << "Enter new name: ";
            getline(cin, persons[i].name);

            cout << "Enter new address: ";
            getline(cin, persons[i].address);

            cout << "Enter new contact: ";
            cin >> persons[i].contact;

            cout << "Enter new cash: ";
            cin >> persons[i].cash;

            cout << "Account updated successfully\n";
            return;
        }
    }
    cout << "Account not found\n";
}

void Bank::searchAccount() {
    string id;
    cout << "Enter ID to search: ";
    cin >> id;

    for (int i = 0; i < total; i++) {
        if (persons[i].id == id) {
            cout << "\nName: " << persons[i].name << endl;
            cout << "Address: " << persons[i].address << endl;
            cout << "Contact: " << persons[i].contact << endl;
            cout << "Cash: " << persons[i].cash << endl;
            return;
        }
    }
    cout << "Account not found\n";
}

void Bank::transaction() {
    string id;
    cout << "Enter ID: ";
    cin >> id;

    for (int i = 0; i < total; i++) {
        if (persons[i].id == id) {
            int choice, amount;

            cout << "1. Deposit\n2. Withdraw\nEnter choice: ";
            cin >> choice;

            if (choice == 1) {
                cout << "Enter amount to deposit: ";
                cin >> amount;
                persons[i].cash += amount;
            }
            else if (choice == 2) {
                cout << "Enter amount to withdraw: ";
                cin >> amount;

                if (amount > persons[i].cash) {
                    cout << "Insufficient balance\n";
                    return;
                }
                persons[i].cash -= amount;
            }
            else {
                cout << "Invalid choice\n";
                return;
            }

            cout << "Transaction successful. Current balance: "
                 << persons[i].cash << endl;
            return;
        }
    }
    cout << "Account not found\n";
}

void Bank::deleteAccount() {
    string id;
    cout << "Enter ID to delete: ";
    cin >> id;

    for (int i = 0; i < total; i++) {
        if (persons[i].id == id) {
            for (int j = i; j < total - 1; j++) {
                persons[j] = persons[j + 1];
            }
            total--;
            cout << "Account deleted successfully\n";
            return;
        }
    }
    cout << "Account not found\n";
}
