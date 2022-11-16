#include "BigDecimalIntandFloatClass.h"
#include <iostream>
#include <string>
#include <regex>
#include <deque>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
    int choice = 1;
    cout << "Enter 1 for BigDecimalInt and 2 for BigReal 0 To Exist: ";
    cin >> choice;
    while (choice != 0) {
        if (choice == 1) {
            BigDecimalInt num1("50001"), num2("80505");
            cout << "num1 + num2 = " << num1 + num2 << endl;
            cout << "num1 - num2 = " << num1 - num2 << endl;
            if (num1 > num2)
                cout << "num1 > num2" << endl;
            else if (num1 < num2)
                cout << "num1 < num2" << endl;
            else
                cout << "num1 = num2" << endl;
        } else if (choice == 2) {
            BigReal num1("-500"), num2("405");
            cout << "num1 + num2 = " << num1 + num2 << endl;
            cout << "num1 - num2 = " << num1 - num2 << endl;
            if (num1 > num2)
                cout << "num1 > num2" << endl;
            else if (num1 < num2)
                cout << "num1 < num2" << endl;
            else
                cout << "num1 = num2" << endl;
            cout <<"---------------------------------------------------------------------"<<endl;
            BigReal n1 ("11.9000000000000000000000000000000001");
            BigReal n2 ("2333333333339.1134322222222292");
            BigReal n3 = n1 + n2;
            BigReal n4 (0.9);
            cout << n3;
            n3 = n3 + n4;
            cout << n3;
        } else if (choice == 0) {
            cout << "Goodbye!" << endl;
            cout << "THANK YOU FOR USING OUR PROGRAM" << endl;
        } else {
            cout << "Invalid choice!" << endl;
        }
        cin>>choice;
        cout << "Enter 1 for BigDecimalInt and 2 for BigReal 0 To Exist: ";
    }
}

