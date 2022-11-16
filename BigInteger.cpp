#include "BigInteger.h"
#include <algorithm>
#include <string>
using namespace std;
int BigDecimalInt::value_checker(string str1, string str2) {
    int counter;
    if (str1.size() > str2.size())
        return 1;
    else if (str1.size() < str2.size())
        return -1;
    else {
        for (size_t i = 1; i < str1.size(); ++i) {
            if (str1[i] > str2[i])
                return 1;
            else if (str1[i] < str2[i])
                return -1;
            else {
                ++counter;
                continue;
            }
        }
    }
    if (counter == str1.size())
        return 0;
}

BigDecimalInt::BigDecimalInt(string decStr) {
    while (true) {// To protect from enter errors
        bool find_plus = true, find_min = true, find_space = true;//find+,find-
        if (isdigit(decStr[0]) == 1 &&
            decStr[0] != '0') { // in case if the user entered a number without sign i put + to it
            reverse(decStr.begin(), decStr.end());
            decStr.push_back('+');
            reverse(decStr.begin(), decStr.end());
        }
        for (int i = 0; i < decStr.size(); i++) {
            if (decStr[i] == ' ' && find_space) {//To know the number does it contain a space
                find_space = false;
            }
            else if (decStr[i] == '+' && find_plus) {//To know the number does it contain a +
                find_plus = false;
            }
            else if (decStr[i] == '-' && find_min) {//To know the number does it contain a -
                find_min = false;
            }
        }
        if (decStr.empty() || decStr == " " || find_space == false ||
            (find_plus == false && find_min == false))//Error handling and correct entry
        {
            cout << "Error" << endl;
            cout << "please enter the valid number==>" << endl;
            cin >> decStr;
            bool find_plus = true, find_min = true, find_space = true;//find+,find-
            for (int i = 0; i < decStr.size(); i++) {
                if (decStr[i] == ' ' && find_space) {//To know the number does it contain a space
                    find_space = false;
                }
                else if (decStr[i] == '+' && find_plus) {//To know the number does it contain a +
                    find_plus = false;
                }
                else if (decStr[i] == '-' && find_min) {//To know the number does it contain a -
                    find_min = false;
                }
            }
        }
        else {
            break;
        }
    }
    BigInteger = decStr; //this->BigInteger=decStr this is pointer Indicates his object
//cout << BigInteger << endl;
}
BigDecimalInt::BigDecimalInt(int decInt) {
    BigInteger = to_string(decInt);//converting the input to string in case the user entered the number as integer
}
BigDecimalInt BigDecimalInt::operator+ (BigDecimalInt anotherDec) {
    string result;
    if (BigInteger[0] == '-' && anotherDec.BigInteger[0] == '-' || BigInteger[0] == '+' && anotherDec.BigInteger[0] == '+')// in case the two numbers have the same sign
    {
        if (BigInteger[0] == '+' && anotherDec.BigInteger[0] == '+')//pushing + sign cause in addition if the two numbers has the same sign the result will have the same sign
            result.push_back('+');
        if (BigInteger[0] == '-' && anotherDec.BigInteger[0] == '-')//pushing - sign cause in addition if the two numbers has the same sign the result will have the same sign
            result.push_back('-');
        bool swapp = false;
        if (BigInteger.size() > anotherDec.BigInteger.size()) {
            swap(BigInteger, anotherDec.BigInteger);//swapping the values of the two numbers if the first is bigger
            swapp = true;
        }
        reverse(anotherDec.BigInteger.begin(), anotherDec.BigInteger.end());
        reverse(BigInteger.begin(), BigInteger.end());
        int s_n1 = BigInteger.length() - 1, s_n2 = anotherDec.BigInteger.length() - 1;
        int carry = 0;
        //doing addition process
        for (int i = 0; i < s_n1; i++) {
            int sum = ((BigInteger[i] - '0') + (anotherDec.BigInteger[i] - '0') + carry);
            result.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        for (int i = s_n1; i < s_n2; i++) {//loopping on the rest of the bigger number
            int sum = ((anotherDec.BigInteger[i] - '0') + carry);
            result.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        if (carry != 0) {
            result.push_back(carry % 10 + '0');
        }
        if (swapp == true) {
            swap(BigInteger, anotherDec.BigInteger);
        }
        reverse(anotherDec.BigInteger.begin(), anotherDec.BigInteger.end());
        reverse(BigInteger.begin(), BigInteger.end());
        reverse(result.begin() + 1, result.end());
        return result;
    }
    else if (BigInteger[0] == '+' && anotherDec.BigInteger[0] == '-' || BigInteger[0] == '-' && anotherDec.BigInteger[0] == '+')// in case the two numbers have different signs
    {
        bool swapp = 0;
        int carry = 0, sub, length = 0;
        char sign1, sign2;
        length = value_checker(BigInteger, anotherDec.BigInteger);//checking which number is bigger or are they equal
        sign1 = BigInteger[0];//containg the sign of the number
        sign2 = anotherDec.BigInteger[0];//containg the sign of the number
        BigInteger.erase(BigInteger.begin());//erasing the sign of the number
        anotherDec.BigInteger.erase(anotherDec.BigInteger.begin());//erasing the sign of the number
        if (value_checker(BigInteger, anotherDec.BigInteger) == -1) {
            swap(BigInteger, anotherDec.BigInteger);//swapping the values of the two numbers in case the second number is bigger
            swapp = 1;
        }
        if (value_checker(BigInteger, anotherDec.BigInteger) == 0)
        {
            result = "0";//returning 0 in case the two numbers are equal
            return result;
        }
        reverse(BigInteger.begin(), BigInteger.end());
        reverse(anotherDec.BigInteger.begin(), anotherDec.BigInteger.end());
        //doing subtraction process
        for (size_t i = 0; i < anotherDec.BigInteger.size(); ++i)
        {
            sub = BigInteger[i] - anotherDec.BigInteger[i] - carry;
            if (sub < 0)
            {
                sub += 10;
                carry = 1;
            }
            else
                carry = 0;
            result.push_back(sub + '0');
        }
        for (size_t i = anotherDec.BigInteger.size(); i < BigInteger.size(); ++i)//loopping on the rest of the bigger number
        {
            sub = BigInteger[i] - '0' - carry;
            if (sub < 0)
            {
                sub += 10;
                carry = 1;
            }
            else
                carry = 0;
            result.push_back(sub + '0');
        }
        if ((sign1 == '+' && sign2 == '-' && length == -1) || (sign1 == '-' && sign2 == '+' && length == 1))
        {
            result.push_back('-');//pussing - to the result in case the bigger number is negative
        }
        else {
            result.push_back('+');
        }
        if (swapp == true) {
            swap(BigInteger, anotherDec.BigInteger);//swapping the values of the two numbers in case the second number is bigger
        }
        BigInteger.push_back(sign1);
        reverse(BigInteger.begin(), BigInteger.end());
        anotherDec.BigInteger.push_back(sign2);
        reverse(anotherDec.BigInteger.begin(), anotherDec.BigInteger.end());
        reverse(result.begin(), result.end());
        return result;
    }
}
BigDecimalInt BigDecimalInt::operator- (BigDecimalInt anotherDec) {
    string result;
    if (BigInteger[0] == '-' && anotherDec.BigInteger[0] == '-' ||
        BigInteger[0] == '+' && anotherDec.BigInteger[0] == '+')// in case the two numbers have the same sign
    {
        bool swapp = false;
        int carry = 0, sub, length = 0;
        char sign1, sign2;
        length = value_checker(BigInteger, anotherDec.BigInteger);//checking which number is bigger or are they equal
        sign1 = BigInteger[0];//containg the sign of the number
        sign2 = anotherDec.BigInteger[0];//containg the sign of the number
        BigInteger.erase(BigInteger.begin());//erasing the sign of the number;
        anotherDec.BigInteger.erase(anotherDec.BigInteger.begin());//erasing the sign of the number
        if (value_checker(BigInteger, anotherDec.BigInteger) == -1) {
            swap(BigInteger,
                anotherDec.BigInteger);//swapping the values of the two numbers in case the second number is bigger
            swapp = 1;
        }
        if (value_checker(BigInteger, anotherDec.BigInteger) == 0) {
            result = "0";
            return result;//returning 0 in case the two numbers are equal
        }
        reverse(BigInteger.begin(), BigInteger.end());
        reverse(anotherDec.BigInteger.begin(), anotherDec.BigInteger.end());
        //doing subtraction process
        for (size_t i = 0; i < anotherDec.BigInteger.size(); ++i) {
            sub = BigInteger[i] - anotherDec.BigInteger[i] - carry;
            if (sub < 0) {
                sub += 10;
                carry = 1;
            }
            else
                carry = 0;
            result.push_back(sub + '0');
        }
        for (size_t i = anotherDec.BigInteger.size();
            i < BigInteger.size(); ++i)//loopping on the rest of the bigger number
        {
            sub = BigInteger[i] - '0' - carry;
            if (sub < 0) {
                sub += 10;
                carry = 1;
            }
            else
                carry = 0;
            result.push_back(sub + '0');
        }
        if ((sign1 == '+' && sign2 == '+' && length == -1) || (sign1 == '-' && sign2 == '-' && length ==
            1))//pussing - to the result in case the bigger number is negative
        {
            result.push_back('-');
        }
        else {
            result.push_back('+');
        }
        if (swapp == true) {
            swap(BigInteger,
                anotherDec.BigInteger);//swapping the values of the two numbers in case the second number is bigger
        }
        BigInteger.push_back(sign1);
        reverse(BigInteger.begin(), BigInteger.end());
        anotherDec.BigInteger.push_back(sign2);
        reverse(anotherDec.BigInteger.begin(), anotherDec.BigInteger.end());
        reverse(result.begin(), result.end());
        return result;
    }
    else if (BigInteger[0] == '-' && anotherDec.BigInteger[0] == '+' ||
        BigInteger[0] == '+' && anotherDec.BigInteger[0] == '-')// in case the two numbers have different signs
    {
        {
            bool swapp = false;
            char sign1, sign2;
            if (BigInteger.size() > anotherDec.BigInteger.size()) {
                swap(BigInteger, anotherDec.BigInteger);//swapping the values of the two numbers if the first is bigger
                swapp = true;
            }
            reverse(anotherDec.BigInteger.begin(), anotherDec.BigInteger.end());
            reverse(BigInteger.begin(), BigInteger.end());
            int s_n1 = BigInteger.length() - 1, s_n2 = anotherDec.BigInteger.length() - 1;
            int carry = 0;
            //doing addition process
            for (int i = 0; i < s_n1; i++) {
                int sum = ((BigInteger[i] - '0') + (anotherDec.BigInteger[i] - '0') + carry);
                result.push_back(sum % 10 + '0');
                carry = sum / 10;
            }
            //loopping on the rest of the bigger number
            for (int i = s_n1; i < s_n2; i++) {
                int sum = ((anotherDec.BigInteger[i] - '0') + carry);
                result.push_back(sum % 10 + '0');
                carry = sum / 10;
            }
            if (carry != 0) {
                result.push_back(carry % 10 + '0');
            }
            if (swapp == true) {
                swap(BigInteger, anotherDec.BigInteger);
            }
            reverse(BigInteger.begin(), BigInteger.end());
            reverse(anotherDec.BigInteger.begin(), anotherDec.BigInteger.end());
            if (BigInteger[0] == '+' && BigInteger[0] == '-') {//pussing - or + to the result
                result.push_back('+');
            }
            else {
                result.push_back('-');
            }
            reverse(result.begin(), result.end());
            return result;
        }
    }
}
bool BigDecimalInt::operator<(BigDecimalInt anotherDec) {
    if (BigInteger.size() < anotherDec.BigInteger.size() && BigInteger[0] != '-' &&
        anotherDec.BigInteger[0] != '-') {
        return true;//ex: 10<101?
    }
    else if (BigInteger.size() > anotherDec.BigInteger.size() && BigInteger[0] != '-' &&
        anotherDec.BigInteger[0] != '-') {
        return false;//ex:101<10?
    }
    else if (BigInteger.size() < anotherDec.BigInteger.size() && BigInteger[0] == '-' &&
        anotherDec.BigInteger[0] == '-') {
        return false;//ex  -101>-10?
    }
    else if (BigInteger.size() > anotherDec.BigInteger.size() && BigInteger[0] == '-' &&
        anotherDec.BigInteger[0] == '-') {
        return true;//ex:  -101<10?
    }
    else if (BigInteger[0] == '-' && anotherDec.BigInteger[0] != '-') {
        return true; //ex: -101<10?
    }
    else if (BigInteger[0] != '-' && anotherDec.BigInteger[0] == '-') {
        return false;//ex: -101>10?
    }
    else if (BigInteger[0] == '-' && anotherDec.BigInteger[0] == '-') {
        for (int i = 0; i < BigInteger.size(); i++) {
            if (BigInteger[i] > anotherDec.BigInteger[i]) {//Fulfill the condition and return 1
                return true;
            }
            else if (BigInteger[i] < anotherDec.BigInteger[i]) {//Failure to fulfill the condition and return 0
                return false;
            }
            else {//If the two numbers are equal
                continue;
            }
        }
    }
    else {
        for (int i = 0; i < BigInteger.size(); i++) {
            if (BigInteger[i] < anotherDec.BigInteger[i]) {//Fulfill the condition and return 1
                return true;
            }
            else if (BigInteger[i] > anotherDec.BigInteger[i]) {//Failure to fulfill the condition and return 0
                return false;
            }
            else {
                continue;//If the two numbers are equal
            }
        }
    }
}
bool BigDecimalInt::operator>(BigDecimalInt anotherDec) {
    if (BigInteger.size() > anotherDec.BigInteger.size() && BigInteger[0] != '-' &&
        anotherDec.BigInteger[0] != '-') {
        return true;//ex: 101>10?
    }
    else if (BigInteger.size() < anotherDec.BigInteger.size() && BigInteger[0] != '-' &&
        anotherDec.BigInteger[0] != '-') {
        return false;//ex:10<101?
    }
    else if (BigInteger.size() > anotherDec.BigInteger.size() && BigInteger[0] == '-' &&
        anotherDec.BigInteger[0] == '-') {
        return false;//ex: -101>-10?
    }
    else if (BigInteger.size() < anotherDec.BigInteger.size() && BigInteger[0] == '-' &&
        anotherDec.BigInteger[0] == '-') {
        return true;//ex: -101<-10?
    }
    else if (BigInteger[0] != '-' && anotherDec.BigInteger[0] == '-') {
        return true;//ex: 101>-10?
    }
    else if (BigInteger[0] == '-' && anotherDec.BigInteger[0] != '-') {
        return false;//ex: 101>-10?
    }
    else if (BigInteger[0] == '-' && anotherDec.BigInteger[0] == '-') {
        for (int i = 0; i < BigInteger.size(); i++) {
            if (BigInteger[i] < anotherDec.BigInteger[i]) {//Fulfill the condition and return 1
                return true;
            }
            else if (BigInteger[i] > anotherDec.BigInteger[i]) {//Failure to fulfill the condition and return 0
                return false;
            }
            else {
                continue;//If the two numbers are equal
            }
        }
    }
    else {
        for (int i = 0; i < BigInteger.size(); i++) {
            if (BigInteger[i] > anotherDec.BigInteger[i]) {//Fulfill the condition and return 1
                return true;
            }
            else if (BigInteger[i] < anotherDec.BigInteger[i]) {//Failure to fulfill the condition and return 0
                return false;
            }
            else {
                continue;//If the two numbers are equal
            }
        }
    }
}
BigDecimalInt BigDecimalInt::operator=(BigDecimalInt anotherDec) {
    BigInteger = anotherDec.BigInteger;
    return *this; //return the same pointer after editing.
}
bool BigDecimalInt::operator==(BigDecimalInt anotherDec) {
    if (BigInteger.size() > anotherDec.BigInteger.size() ||
        BigInteger.size() < anotherDec.BigInteger.size()) {//They must be the same size
        return false;
    }
    else {
        bool ans = true;
        for (int i = 0; i < BigInteger.size(); i++) {
            if (BigInteger[i] != anotherDec.BigInteger[i]) {// against the rules
                ans = false;
                break;
            }
        }
        if (ans)// return value
        {
            return true;
        }
        else {
            return false;
        }
    }
};

int BigDecimalInt::size() {
    //return size of num
    return BigInteger.size();
};
int BigDecimalInt::sign() {
    //return 1 if sign is + ,,, 0 if sign is -
    if (BigInteger[0] == '-') {
        return false;
    }
    else {
        return true;
    }
}
ostream& operator<<(ostream& out, BigDecimalInt b) {
    //o allow us to use the attributes of the object
    out << b.BigInteger << endl;
    return out;
}
