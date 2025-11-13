#include<iostream>
#include<fstream>
using namespace std;

class shopping
{
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void llist();
    void receipt();
};

void shopping::menu()
{
m:
    int choice;
    string email;
    string password;

    cout << "_________________________" << endl;
    cout << "      Supermarket menu   " << endl;
    cout << "_________________________" << endl;
    cout << "1) Administrator" << endl;
    cout << "2) Buyer" << endl;
    cout << "3) Exit" << endl;
    cout << "Please select!!" << endl;
    cin >> choice;

    switch (choice) {
    case 1: {
        cout << "Please login" << endl;
        cout << "Enter your email(ismail@gmail.com):" << endl;
        cin >> email;
        cout << "Enter your password(ismail123):" << endl;
        cin >> password;
        if (email == "ismail@gmail.com" && password == "ismail123") {
            administrator();
        }
        else {
            cout << "Invalid email/password" << endl;
        }
        break;
    }
    case 2:
        buyer();
        break;
    case 3:
        exit(0);
    default:
        cout << "Please select from the given options" << endl;
    }
    goto m;
}

void shopping::administrator()
{
m:
    int choice;
    cout << "Administrator menu" << endl;
    cout << "1) Add product" << endl;
    cout << "2) Modify the product" << endl;
    cout << "3) Delete the product" << endl;
    cout << "4) Back to main menu" << endl;
    cout << "Please enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        rem();
        break;
    case 4:
        menu();
        break;
    default:
        cout << "Invalid choice" << endl;
    }
    goto m;
}

void shopping::buyer()
{
m:
    int choice;
    cout << "Buyer" << endl;
    cout << "1) Buy product" << endl;
    cout << "2) Go back" << endl;
    cout << "Please enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        receipt();
        break;
    case 2:
        menu();
        break;
    default:
        cout << "Invalid choice" << endl;
    }
    goto m;
}

void shopping::add()
{
m:
    fstream data;
    int c;
    int token = 0;
    float p, d;
    string n;

    cout << "Add new Product" << endl;
    cout << "Product code: ";
    cin >> pcode;
    cout << "Name of the product: ";
    cin >> pname;
    cout << "Price of the product: ";
    cin >> price;
    cout << "Discount on the product: ";
    cin >> dis;

    data.open("database.txt", ios::in);
    if (!data) {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << endl;
        data.close();
    }
    else {
        while (data >> c >> n >> p >> d) {
            if (c == pcode) token++;
        }
        data.close();

        if (token == 1) {
            cout << "Product code already exists! Enter again." << endl;
            goto m;
        }
        else {
            data.open("database.txt", ios::app | ios::out);
            data << " " << pcode << " " << pname << " " << price << " " << dis << endl;
            data.close();
        }
    }
    cout << "Record inserted!" << endl;
}

void shopping::edit()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p, d;
    string n;

    cout << "Modify the record" << endl;
    cout << "Product code: ";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data) {
        cout << "File doesn't exist!" << endl;
        return;
    }

    data1.open("database1.txt", ios::app | ios::out);

    while (data >> pcode >> pname >> price >> dis) {
        if (pcode == pkey) {
            cout << "New product code: ";
            cin >> c;
            cout << "New name: ";
            cin >> n;
            cout << "New price: ";
            cin >> p;
            cout << "New discount: ";
            cin >> d;
            data1 << " " << c << " " << n << " " << p << " " << d << endl;
            cout << "Record edited!" << endl;
            token++;
        }
        else {
            data1 << " " << pcode << " " << pname << " " << price << " " << dis << endl;
        }
    }

    data.close();
    data1.close();

    remove("database.txt");
    rename("database1.txt", "database.txt");

    if (token == 0) cout << "Record not found!" << endl;
}

void shopping::rem()
{
    fstream data, data1;
    int pkey;
    int token = 0;

    cout << "Delete product" << endl;
    cout << "Product code: ";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data) {
        cout << "File doesn't exist" << endl;
        return;
    }

    data1.open("database1.txt", ios::app | ios::out);

    while (data >> pcode >> pname >> price >> dis) {
        if (pcode == pkey) {
            cout << "Product deleted successfully!" << endl;
            token++;
        }
        else {
            data1 << " " << pcode << " " << pname << " " << price << " " << dis << endl;
        }
    }

    data.close();
    data1.close();

    remove("database.txt");
    rename("database1.txt", "database.txt");

    if (token == 0) cout << "Record not found" << endl;
}

void shopping::llist()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\n_______________________________________________" << endl;
    cout << "ProNo\t\tName\t\tPrice" << endl;
    cout << "_______________________________________________\n";

    while (data >> pcode >> pname >> price >> dis) {
        cout << pcode << "\t\t" << pname << "\t\t" << price << endl;
    }

    data.close();
}

void shopping::receipt()
{
    fstream data;
    int arrc[100], arrq[100];
    char choice;
    int c = 0;
    float amount = 0, discountAmount = 0, total = 0;

    cout << "       RECEIPT        " << endl;

    data.open("database.txt", ios::in);
    if (!data) {
        cout << "Empty database!" << endl;
        return;
    }
    data.close();

    llist();
    cout << "\n_______________________________\n";
    cout << "Please place the order" << endl;

    do {
    m:
        cout << "\nEnter Product code: ";
        cin >> arrc[c];
        cout << "Enter quantity: ";
        cin >> arrq[c];

        for (int i = 0; i < c; i++) {
            if (arrc[c] == arrc[i]) {
                cout << "Duplicate product code! Try again." << endl;
                goto m;
            }
        }
        c++;
        cout << "Do you want to buy another product? (y/n): ";
        cin >> choice;
    } while (choice == 'y');

    cout << "\n\t\t\t______RECEIPT______\n";
    cout << "Product No\tProduct Name\tQuantity\tPrice\tAmount\tAmount with discount\n";

    for (int i = 0; i < c; i++) {
        data.open("database.txt", ios::in);
        while (data >> pcode >> pname >> price >> dis) {
            if (pcode == arrc[i]) {
                amount = price * arrq[i];
                discountAmount = amount - (amount * dis / 100);
                total += discountAmount;
                cout << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t" << amount << "\t" << discountAmount << endl;
            }
        }
        data.close();
    }

    cout << "________________________________\n";
    cout << "Total Amount: " << total << endl;
}

int main() {
    shopping s;
    s.menu();
}
