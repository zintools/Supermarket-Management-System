1. Description of your project
This project is a Supermarket Management System made in C++. It is a program that helps a small supermarket manage products and sales.
The administrator can add, edit, and delete products
The buyer can see products, buy them, and get a receipt with the total price and discount.
The project uses a text file to save all product information so that data is not lost when the program is closed.
2. Related technologies
The project uses:
C++ programming language – to make the program.
File handling – to save product data in database.txt.
Classes and objects – to organize the code using a shopping class.
Loops and conditionals – to make menus and check user input.
3. Overall design and detailed design
Overall Design
The program has two main parts:
Administrator:

Add new products
Edit existing products
Delete products
View all products
Buyer:
See product list
Buy products
Get receipt with total and discount
Detailed design
Class shopping: Stores product information and has all functions for the program.
File database.txt: Saves product code, name, price, and discount.
Menus: The program shows menus to let the user choose actions.
Receipt: Calculates total price with discount and shows the receipt for the buyer.
4. Coding implementation
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
        cout << "Enter your email:" << endl;
        cin >> email;
        cout << "Enter your password:" << endl;
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
int main() {
    shopping s;
    s.menu();
}

5. Main problems and solutions in the practice
Problem: Some product codes were repeated when adding new products.
Solution: The program checks if the product code already exists before adding.
Problem: Cannot edit or delete a product that does not exist.
Solution: The program shows a message if the product is not found.
Problem: Product names with spaces were not saved correctly.
Solution: Used getline() to read the product name with spaces.
 Problem: Opening the file many times in loops.
Solution: The program works but could be faster if we read all data once (improvement for the future).
