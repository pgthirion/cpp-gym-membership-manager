#include <iostream>
#include <string>
using namespace std;

/*
    =========
    Functions
    =========
*/

/*
    Shows a simple section heading on screen
*/
void showHeader(const string &title) {
    cout << "\n===== " << title << " =====" << endl;
}

/*
    Gets a valid number input from the user

    Returns: a valid integer
*/
int getValidNumber(const string &message, int minValue = INT_MIN) {
    int value;

    while (true) {
        cout << message;
        cin >> value;

        // basic input check
        if (cin.fail()) {
            cout << "Error: please enter a number.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (value < minValue) {
            cout << "Error: value must be " << minValue << " or higher.\n";
            continue;
        }

        return value;
    }
}

/*
    Creates a new gym account
*/
void createAccount(string &name, int &membershipNumber, int &credits) {
    showHeader("CREATE ACCOUNT");

    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);

    membershipNumber = getValidNumber("Enter membership number: ", 1);

    do {
        credits = getValidNumber("Enter starting credits (at least 1): ");
        if (credits < 1)
            cout << "You must start with at least one credit.\n";
    } 
    while (credits < 1);

    cout << "Account created for " << name << "!\n";
}

/*
    Adds more training credits to the account
*/
void addSessionCredits(int &credits) {
    showHeader("ADD CREDITS");

    int add = getValidNumber("How many credits do you want to add? ", 1);
    credits += add;

    cout << add << " credits added. You now have " << credits << " total.\n";
}

/*
    Books a single training session
*/
void bookSession(int &credits) {
    showHeader("BOOK SESSION");

    if (credits > 0) {
        credits -= 1;
        cout << "Session booked. 1 credit used.\n";
    } else {
        cout << "Not enough credits. Please add more first.\n";
    }
}

/*
    Shows how many credits are left
*/
void checkCredits(const int &credits) {
    showHeader("CREDITS LEFT");
    cout << "You have " << credits << " credit(s) remaining.\n";
}

/*
    Shows all account details
*/
void displayAccountDetails(const string &name, const int &membershipNumber, const int &credits) {
    showHeader("ACCOUNT DETAILS");

    if (name.empty() || membershipNumber == 0) {
        cout << "No account found. Please create one first.\n";
        return;
    }

    cout << "Name: " << name << endl;
    cout << "Membership Number: " << membershipNumber << endl;
    cout << "Credits: " << credits << endl;
}

/*
    Displays the menu and asks for a choice
*/
int showMenu() {
    showHeader("FITNESS MEMBERSHIP SYSTEM");

    cout << "1. Create Account\n";
    cout << "2. Add Session Credits\n";
    cout << "3. Book Training Session\n";
    cout << "4. Check Remaining Credits\n";
    cout << "5. Display Account Details\n";
    cout << "6. Exit\n";

    int choice = getValidNumber("Choose an option (1-6): ");

    if (choice < 1 || choice > 6) {
        cout << "Invalid option. Please try again.\n";
        return -1;
    }

    return choice;
}

/*
    Runs the correct function depending on what the user chose
*/
void runChoice(int choice, bool &accountMade, string &name, int &membershipNumber, int &credits) {
    switch (choice) {
        case 1:
            createAccount(name, membershipNumber, credits);
            accountMade = true;
            break;
        case 2:
            if (accountMade) addSessionCredits(credits);
            else cout << "Please make an account first.\n";
            break;
        case 3:
            if (accountMade) bookSession(credits);
            else cout << "Please make an account first.\n";
            break;
        case 4:
            if (accountMade) checkCredits(credits);
            else cout << "Please make an account first.\n";
            break;
        case 5:
            if (accountMade) displayAccountDetails(name, membershipNumber, credits);
            else cout << "Please make an account first.\n";
            break;
        case 6:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid option.\n";
    }
}

/*
    =============
    Main Function
    =============
*/
/*
Logic:
    - Create variables to hold account info
    - Keep showing menu until user exits
    - Validate all inputs
    - Only allow actions after account is made
*/
int main() {
    string name;
    int membershipNumber = 0;
    int credits = 0;
    bool accountMade = false;
    int choice;

    do {
        choice = showMenu();

        if (choice == -1)
            continue;

        runChoice(choice, accountMade, name, membershipNumber, credits);

    } while (choice != 6);

    return 0;
}
