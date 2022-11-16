#include <iostream>
#include <algorithm>
#include <iomanip>
#include <array>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <set>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#define INF (ll)1e18
#define  N 200005
#define PI 3.14159265358979383246
#define ll long long
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define f first
#define s second
#define End '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define repit(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define perit(it, a) for (auto it = a.rbegin(); it != a.rend(); it++)
#define repd(i, a, b, d) for (int i = a; i < b; i += d)
#define q1  cin.tie(0)
#define q2 cin.sync_with_stdio(0)
using namespace std;
class client;
//forward declaration
class Bankapplication;
class savingsaccount;
class bankaccount;
class client {//client class
protected:
    string name;//name of client
    string address;//address of client
    string phone;// phone of client
public:
    client() {//default constructor of client to initialize data members
        name = "";
        address = "";
        phone = "";
    }
    client(string name, string address, string phone) {//constructor of client to initialize data members
        this->name = name;
        this->address = address;
        this->phone = phone;
    }
    void set_name(string name) {//set name of client
        this->name = name;
    }
    void set_address(string address) {//set address of client
        this->address = address;
    }
    void set_phone(string phone) {//set phone of client
        this->phone = phone;
    }
    string get_name() {//get name of client
        return name;
    }
    string get_address() {//get address of client
        return address;
    }
    string get_phone() {//get phone of client
        return phone;
    }
};
class bankaccount : public client {//bank account class
protected:
    string accountID;//account id of bank account
    string accountType;//account type of bank account
    double balance;//   balance of bank account
public:
    bankaccount()//default constructor of bank account to initialize data members
    {
        accountID = "";
        accountType = "";
        balance = 0;
    }
    bankaccount(string accountID, double balance, string accountType) {
        //constructor of bank account to initialize data members from parameters
        this->accountID = accountID;
        this->balance = balance;
        this->accountType = accountType;
    }
    bankaccount(string name, string address, string phone, string accountID, string accountType, double balance) : client(name, address, phone) {
        //constructor of bank account to initialize data members from parameters
        this->accountID = accountID;
        this->balance = balance;
        this->accountType = accountType;
    }
    void set_accountID(string accountID) {
        //set account id of bank account
        this->accountID = accountID;
    }
    void set_balance(double balance) {
        //set balance of bank account
        this->balance = balance;
    }
    void set_accountType(string accountType) {
        //set account type of bank account
        this->accountType = accountType;
    }
    string get_accountID() {
        //get account id of bank account
        return accountID;
    }
    double get_balance() {
        //get balance of bank account
        return balance;
    }
    string get_accountType() {
        //get account type of bank account
        return accountType;
    }
    virtual bool  deposit(double amount) {
        //deposit money to bank account
        cout << "fdgdgfdgdf";
        balance += amount;
        return 1;
    }
    virtual bool withdraw(double amount) {
        //withdraw money from bank account
        if (balance >= amount) {
            balance -= amount;
            return 1;
        }
        else {
            cout << "Not enough balance" << '\n';
            return 0;
        }
    }
};
class savingsaccount :public bankaccount {//savings account class
private:
    double minimumbalance;//minimum balance of savings account
public:
    savingsaccount() {//default constructor of savings account to initialize data members
        minimumbalance = 1000;
    }
    savingsaccount(string accountID, double balance, string accountType) : bankaccount(accountID, balance, accountType) {
        //constructor of savings account to initialize data members from parameters
        minimumbalance = 1000;
    }
    savingsaccount(string name, string address, string phone, string accountID, string accountType, double balance) : bankaccount(name, address, phone, accountID, accountType, balance) {
        //constructor of savings account to initialize data members from parameters
        minimumbalance = 1000;
    }
    void set_minimumbalance(double minimumbalance) {
        //set minimum balance of savings account
        this->minimumbalance = minimumbalance;
    }
    double get_minimumbalance() {
        //get minimum balance of savings account
        return minimumbalance;
    }
    bool withdraw(double amount) {
        //withdraw money from savings account
        if (balance - amount >= minimumbalance) {
            //if balance after withdraw is greater than minimum balance
            balance -= amount;
            return 1;
        }
        else {
            cout << "Not enough balance" << '\n';
            return 0;
        }
    }
    bool deposit(double amount) {
        //deposit money to savings account
        if (amount >= 100) {
            balance += amount;
            return 1;
        }
        else {
            //if amount is less than 100
            cout << "You must deposit at least 100" << '\n';
            return 0;
        }
    }
};
class Bankapplication {//bank application class
private:
    vector<bankaccount> accounts;//vector of bank accounts
public:
    static int count;//count of bank accounts
    void addclient() {
        cout << fixed << setprecision(5);
        //add client to bank application
        string name, address, phone, accountID, accountTybe;
        double balance;
        cout << "Please Enter Client Name =========>";
        cin.ignore();
        getline(cin, name);
        cout << "Please Enter Client Address =========>";
        cin.ignore();
        getline(cin, address);
        cout << "Please Enter Client Phone =========>";
        cin.ignore();
        getline(cin, phone);
        cout << "What Type of Account Do You Like? (1) Basic (2) Saving – Type 1 or 2 =========>";
        cin >> accountTybe;
        cout << "Please Enter the Starting Balance =========>";
        cin >> balance;
        accountID = "FCAI-00" + to_string(++count);
        cout << "An account was created with ID " << accountID << " and Starting Balance " << balance << " L.E." << '\n';
        bankaccount* obb;
        if (accountTybe == "1") {
            obb = new bankaccount(name, address, phone, accountID, "1", balance);
        }
        else {
            obb = new savingsaccount(name, address, phone, accountID, "2", balance);
        }
        accounts.push_back(*obb);
    }
    void deposit() {
        //deposit money to bank account
        string accountID;
        cout << "Please Enter Account ID (e.g., FCAI-015)=========>";
        cin >> accountID;
        for (int i = 0; i < accounts.size(); i++) {
            if (accounts[i].get_accountID() == accountID) {
                double amount;
                cout << "Please Enter Amount =========>";
                cin >> amount;
                if (accounts[i].get_accountType() == "1") {
                    accounts[i].deposit(amount);
                    cout << "The new balance is " << accounts[i].get_balance() << " L.E." << '\n';
                    return;
                }
                else {
                    savingsaccount obb;
                    obb.set_balance(accounts[i].get_balance());
                    while (!obb.deposit(amount)) {
                        cout << "Please Enter Correct Amount =========>";
                        cin >> amount;
                    }
                    accounts[i].set_balance(obb.get_balance());
                    cout << "The new balance is " << accounts[i].get_balance() << " L.E." << '\n';
                    return;
                }
            }
        }
        cout << "Account not found" << '\n';
    }
    void withdraw() {
        //withdraw money from bank account
        string accountID;
        cout << "Please Enter Account ID (e.g., FCAI-015)=========>";
        cin >> accountID;
        for (int i = 0; i < accounts.size(); i++) {
            if (accounts[i].get_accountID() == accountID) {
                double amount;
                cout << "Please Enter Amount =========>";
                cin >> amount;
                if (accounts[i].get_accountType() == "1") {
                    accounts[i].deposit(amount);
                    cout << "The new balance is " << accounts[i].get_balance() << " L.E." << '\n';
                    return;
                }
                else {
                    savingsaccount obb;
                    obb.set_balance(accounts[i].get_balance());
                    while (!obb.withdraw(amount)) {
                        cout << "Please Enter Correct Amount =========>";
                        cin >> amount;
                    }
                    accounts[i].set_balance(obb.get_balance());
                    cout << "The new balance is " << accounts[i].get_balance() << " L.E." << '\n';
                    return;
                }
            }
        }
        cout << "Account not found" << '\n';
    }
    void display() {
        //display bank account
        for (int i = 0; i < accounts.size();i++) {
            cout << "Name: " << accounts[i].get_name() << '\n';
            cout << "Address: " << accounts[i].get_address() << '\n';
            cout << "Phone: " << accounts[i].get_phone() << '\n';
            cout << "Account ID: " << accounts[i].get_accountID() << '\n';
            cout << "Account Type: " << accounts[i].get_accountType() << '\n';
            cout << fixed << setprecision(5);
            cout << "Balance: " << accounts[i].get_balance() << '\n';
        }
    }
};
int Bankapplication::count = 0;//initialize count of bank accounts
int main() {
    int choice = 1;//choice of user
    Bankapplication obb;//object of bank application
    while (choice != 0) {//while user not exit
        cout << "Welcome to FCAI Banking Application\n"
            "0. Exit\n"
            "1. Create a New Account\n"
            "2. List Clients and Accounts\n"
            "3. Withdraw Money\n"
            "4. Deposit Money\n"
            "Please Enter Choice =========> ";
        cin >> choice;
        if (choice == 1) {//if user want to add client
            obb.addclient();
        }
        else if (choice == 2) {//  if user want to display bank accounts
            obb.display();
        }
        else if (choice == 3) {//if user want to withdraw money
            obb.withdraw();
        }
        else if (choice == 4) {//if user want to deposit money
            obb.deposit();
        }
        else if (choice == 0) {//if user want to exit
            cout << "Thank you for using FCAI Banking Application :)";
            return 0;
        }
        else {//if user enter wrong choice
            cout << "Invalid Choice\n";
        }
    }
}
/*
1
Ahmed Ali Salem
5 Batn Elzeer St., Giza
0120130140
 1
1500
 1
yousef Ali Salem
haram St., Giza
01063005573
2
1500
2
3
FCAI-001
500
4
FCAI-002
500
 */
