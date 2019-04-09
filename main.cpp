#include <iomanip>
#include <iostream>
#include <string>
// setprecision(int n)
using std::cout;
using std::cin;
using std::setprecision;
using std::string;
using std::endl;

double credit{};
int nickels{}, dimes{}, quarters{}, pennies{};
int twix{ 0 }, skittles{ 5 }, crunch{ 5 }, milky_way{ 5 }, reese{ 5 };
const double twix_cost{ 1.50 }, crunch_cost{ 1.50 };
const double skittles_cost{ 1.25 }, milky_cost{ 1.25 };
const double reese_cost{ 1.75 };
bool enough_credit{ false };

bool check_credit(const double& cost);
void vend(string selection);
void vend(double cost);
void insert_money();
void change_return();

void display_menu()
{
    setprecision(2);
    int selection{};
    while(selection != 6) {
        cout << "Credit: $" << credit << "\n" << endl;
        cout << "0 - Insert Credit" << endl;
        cout << "1 - Twix ($1.50)" << endl;
        cout << "2 - Skittles ($1.25)" << endl;
        cout << "3 - Crunch ($1.50)" << endl;
        cout << "4 - Milky Way ($1.25)" << endl;
        cout << "5 - Reese's ($1.75)" << endl;
        cout << "6 - Exit" << endl;
        cout << "\nWelcome! Please make a selection: ";
        cin >> selection;

        switch(selection) {
        case 0:
            insert_money();
            break;
        case 1:
            enough_credit = check_credit(twix_cost);
            if(enough_credit && twix > 0) {
                vend(twix_cost);
            } else if(!enough_credit) {
                cout << "\nPlease insert more credit.\n" << endl;
            } else {
                vend("Twix");
            }
            break;
        case 2:
            enough_credit = check_credit(skittles_cost);
            if(enough_credit && skittles > 0) {
                vend(skittles_cost);
            } else if(!enough_credit) {
                cout << "\nPlease insert more credit.\n" << endl;
            } else {
                vend("Skittles");
            }
            break;
        case 3:
            enough_credit = check_credit(crunch_cost);
            if(enough_credit && crunch > 0) {
                vend(crunch_cost);
            } else if(!enough_credit) {
                cout << "\nPlease insert more credit.\n" << endl;
            } else {
                vend("Crunch");
            }
            break;
        case 4:
            enough_credit = check_credit(milky_cost);
            if(enough_credit && milky_way > 0) {
                vend(milky_cost);
            } else if(!enough_credit) {
                cout << "\nPlease insert more credit.\n" << endl;
            } else {
                vend("Milky Way");
            }
            break;
        case 5:
            enough_credit = check_credit(reese_cost);
            if(enough_credit && reese > 0) {
                vend(reese_cost);
            } else if(!enough_credit) {
                cout << "\nPlease insert more credit.\n" << endl;
            } else {
                vend("Reese's");
            }
            break;
        case 6:
            if(credit == 0) {
                break;
            } else {
                change_return();
            }
            break; // needs to return change
        }
    }
}
bool check_credit(const double& cost)
{
    bool is_enough = (credit >= cost) ? true : false;
    return is_enough;
}
void vend(string selection)
{ // This method takes the selection and prints that it's sold out
    cout << "\nSorry, " << selection << " is sold out.\n" << endl;
}
void vend(double cost)
{ // decrements the credit the customer has in the machine
    cout << "\nVending... Enjoy your snack!\n" << endl;
    credit -= cost;
}
void insert_money()
{
    setprecision(2);
    int coin_select{};
    while(coin_select != 5) {
        cout << "\nCredit: $" << credit << "\n" << endl;
        cout << "0 - Dollar" << endl;
        cout << "1 - Quarter" << endl;
        cout << "2 - Dime" << endl;
        cout << "3 - Nickel" << endl;
        cout << "4 - Penny" << endl;
        cout << "5 - Return" << endl;
        cout << "\nInsert coin: ";
        cin >> coin_select;

        switch(coin_select) {
        case 0:
            credit += 1.00;
            break;
        case 1:
            credit += 0.25;
            break;
        case 2:
            credit += 0.10;
            break;
        case 3:
            credit += 0.05;
            break;
        case 4:
            credit += 0.01;
            break;
        case 5:
            break;
        }
    }
}
void change_return()
{
    int dollars{}, quarters{}, dimes{}, nickels{}, pennies{};

    if(credit >= 1.00) {
        while(credit >= 1.00) {
            credit -= 1.00;
            dollars++;
        }
    }
    if(credit >= .25) {
        while(credit >= .25) {
            credit -= .25;
            quarters++;
        }
    }
    if(credit >= .10) {
        while(credit >= .10) {
            credit -= .10;
            dimes++;
        }
    }
    if(credit >= .05) {
        while(credit >= .05) {
            credit -= .05;
            nickels++;
        }
    }
    if(credit >= .01) {
        while(credit >= .01) {
            credit -= .01;
            pennies++;
        }
    }
    cout << "\nPlease take your change.\n" << endl;
    cout << "Dollars: " << dollars << endl;
    cout << "Quarters: " << quarters << endl;
    cout << "Dimes: " << dimes << endl;
    cout << "Nickels: " << nickels << endl;
    cout << "Pennies: " << pennies << "\n" << endl;
}
int main()
{
    display_menu();
    cout << "Thank you! Have a nice day." << endl;
    return 0;
}