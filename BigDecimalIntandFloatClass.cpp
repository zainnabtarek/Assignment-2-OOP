#include "BigDecimalIntandFloatClass.h"
// regex function that checks the validation of the input.
bool BigDecimalInt :: checkValidInput(string input)
{
    regex validInput("[-+]?[0-9]+");//regex for valid input
    return regex_match(input, validInput);
}
// constructor that takes a string as an input.
void BigDecimalInt :: setNumber(string num)
{
    bool validNumber = checkValidInput(num);
    if(validNumber)
    {
        number = num;
        if(number[0] == '+')
        {
            number.erase(0,1);
            sign = '+';
        }
        else if (number[0] == '-')
        {
            number.erase(0,1);
            sign = '-';
        }
        else
        {
            sign = '+';
        }
    }

}

// operator < overloading function.
bool BigDecimalInt :: operator < (const BigDecimalInt& anotherDec)
{
    string comp1 = "", comp2 = "";
    long long len1 = number.length(), len2 = anotherDec.number.length();

    while (len1 < len2){
        comp1 += '0';
        len1++;
    }
    while (len2 < len1){
        comp2 += '0';
        len2++;
    }
    comp1 += number;
    comp2 += anotherDec.number;

    if(sign == '-' && anotherDec.sign == '+')
    {
        return true;
    }
    else if(sign == '+' && anotherDec.sign == '-')
    {
        return false;
    }
    else if(sign == '+' && anotherDec.sign == '+')
    {
        return comp1 < comp2;
    }
    else
    {
        return comp1 > comp2;
    }
}

// operator > overloading function.
bool BigDecimalInt :: operator > (const BigDecimalInt &anotherDec)
{
    string comp1 = "", comp2 = "";
    long long len1 = number.length(), len2 = anotherDec.number.length();

    while (len1 < len2){
        comp1 += '0';
        len1++;
    }
    while (len2 < len1){
        comp2 += '0';
        len2++;
    }
    comp1 += number;
    comp2 += anotherDec.number;

    if(sign == '-' && anotherDec.sign == '+')
    {
        return false;
    }
    else if(sign == '+' && anotherDec.sign == '-')
    {
        return true;
    }
    else if(sign == '+' && anotherDec.sign == '+')
    {
        return comp1 > comp2;
    }
    else
    {
        return comp1 < comp2;
    }
}

// operator == overloading function.
bool BigDecimalInt :: operator == (const BigDecimalInt anotherDec)
{
    if (sign == anotherDec.sign && number == anotherDec.number)
    {
        return true;

    }
    else
    {
        return false;
    }
}
// operator = overloading function.
BigDecimalInt& BigDecimalInt :: operator = (BigDecimalInt &anotherDec)
{
    sign = anotherDec.sign;
    number = anotherDec.number;
    return *this;
}

// // operator + overloading function.
BigDecimalInt BigDecimalInt :: operator + (BigDecimalInt number2)
{
    BigDecimalInt result;
    char signNumber1 = sign, signNumber2 = number2.sign;

    string num1 = number, num2 = number2.number;
    while (num1.length() < num2.length()){
        num1 = '0' + num1;
    }
    while (num2.length() < num1.length()){
        num2 = '0' + num2;
    }
    if (signNumber1 == signNumber2){
        result.sign = signNumber1;
        auto it1 = num1.rbegin();
        auto it2 = num2.rbegin();
        int carry = 0;
        while (it1 != num1.rend()){
            int twoDigitsSum;
            carry = 0;
            twoDigitsSum = ((*it1 - '0') + (*it2 - '0'));
            if(twoDigitsSum >= 10){
                carry = 1;
            }
            result.number = char((twoDigitsSum % 10) + '0') + result.number;
            *(it1 + 1) = char (((*(it1 + 1) - '0') + carry) + '0');
            it1++;
            it2++;
        }
        if(carry){
            result.number = char ((carry) + '0') + result.number;
        }

    }else{
        deque<long long> d;
        string res = "";

        if (num1 < num2)
        {
            swap(num1, num2);
            swap(signNumber1,signNumber2);
        }

        for (long long i = num1.length() - 1; i >= 0; i--)
        {
            if (num1[i] < num2[i])
            {
                num1[i] = char (((num1[i] - '0') + 10) + '0');
                num1[i - 1] = char (((num1[i - 1] - '0') - 1) + '0');
                d.push_front((num1[i] - '0') - (num2[i] - '0'));
            }
            else
            {
                d.push_front((num1[i] - '0') - (num2[i] - '0'));
            }
        }

        bool right = false;
        for (auto i : d)
        {
            res += to_string(i);
        }

        for (long long i = 0; i < res.length(); i++)
        {
            if (res[i] != '0')
            {
                right = true;
            }
            if (!right && res[i] == '0')
            {
                res.erase(i, 1);
                i--;
            }
        }
        if(res.empty())res="0";
        result.sign = signNumber1;
        result.number = res;
    }
    return result;
}

// operator - overloading function.
BigDecimalInt BigDecimalInt :: operator - (BigDecimalInt anotherDec)
{
    BigDecimalInt obj;
    string strmin = "", res = "";
    deque<long long> d;


    if (number.length() > anotherDec.number.length())
    {
        for (long long i = 0; i < number.length() - anotherDec.number.length(); i++)
        {
            strmin += '0';
        }
        strmin += anotherDec.number;
        anotherDec.number = strmin;
    }
    else if (number.length() < anotherDec.number.length())
    {
        for (long long i = 0; i < anotherDec.number.length() - number.length(); i++)
        {
            strmin += '0';
        }
        strmin += number;
        number = strmin;
    }
    bool ok = false;
    if (number < anotherDec.number)
    {
        swap(number, anotherDec.number);
        ok = true;
    }
    bool nv = true;
    if (sign == '-' && anotherDec.sign == '-')
    {
        for (long long i = number.length() - 1; i >= 0; i--)
        {
            if (number[i] < anotherDec.number[i])
            {
                number[i] = char (((number[i] - '0') + 10) + '0');
                number[i - 1] = char (((number[i - 1] - '0') - 1) + '0');
                d.push_front((number[i] - '0') - (anotherDec.number[i] - '0'));
            }
            else
            {
                d.push_front((number[i] - '0') - (anotherDec.number[i] - '0'));
            }
        }
        ok = !ok;
    }
    else if ((sign == '-' || anotherDec.sign == '-'))
    {
        string num1 = number, num2 = anotherDec.number;
        auto it1 = num1.rbegin();
        auto it2 = num2.rbegin();
        int carry = 0;

        while (it1 != num1.rend())
        {
            int twoDigitsSum;
            carry = 0;
            twoDigitsSum = ((*it1 - '0') + (*it2 - '0'));
            if (twoDigitsSum >= 10)
            {
                carry = 1;
            }
            res = char((twoDigitsSum % 10) + '0') + res;
            *(it1 + 1) = char(((*(it1 + 1) - '0') + carry) + '0');
            it1++;
            it2++;
        }

        if (carry)
        {
            res = char((carry) + '0') + res;
        }
        if (sign == '-')
        {
            nv = false;
        }
    }
    else
    {
        for (long long i = number.length() - 1; i >= 0; i--)
        {
            if (number[i] < anotherDec.number[i])
            {
                number[i] = char (((number[i] - '0') + 10) + '0');
                number[i - 1] = char (((number[i - 1] - '0') - 1) + '0');
                d.push_front((number[i] - '0') - (anotherDec.number[i] - '0'));
            }
            else
            {
                d.push_front((number[i] - '0') - (anotherDec.number[i] - '0'));
            }
        }
        nv = true;
    }
    if (!nv || ok) {
        obj.sign = '-';
    }else{
        obj.sign = '+';
    }
    bool right = false;
    for (auto i : d)
    {
        res += to_string(i);
    }
    for (long long i = 0; i < res.length(); i++)
    {
        if (res[i] != '-' && res[i] != '0')
        {
            right = true;
        }
        if (!right && res[i] == '0')
        {
            res.erase(i, 1);
            i--;
        }
    }
    if(res.empty())res="0";
    obj.number = res;
    return obj;
}

// function to return the size of number.
int BigDecimalInt :: size()
{
    return number.size();
}

int BigDecimalInt :: Sign()
{
    if (sign == '+')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// operator << overloading function.
ostream &operator << (ostream &out, BigDecimalInt num)
{
    if(num.sign == '+')
    {
        out << num.number << endl;
    }
    else
    {
        if (num.number != "0")
        {
            out << num.sign << num.number << endl;
        }
        else
        {
            out << num.number << endl;
        }
    }
    return out;
}
istream&operator >> (istream &in, BigDecimalInt &num)//operator >> overloading function.
{
    in >> num.number;
    if (num.number[0] == '-')
    {
        num.sign = '-';
        num.number.erase(0, 1);
    }
    else
    {
        num.sign = '+';
    }
    return in;
}
ostream &operator << (ostream &out, BigReal num)//
{//operator << overloading function.

      if(num.sign == '+')
    {
        out << num.number << endl;
    }
    else
    {
        out << num.sign << num.number << endl;
    }
    return out;
}
istream &operator >> (istream &in, BigReal &num)
{//operator >> overloading function.
    in >> num.number;
    if (num.number[0] == '-')
    {
        num.sign = '-';
        num.number.erase(0, 1);
    }
    else
    {
        num.sign = '+';
    }
    return in;
}
BigReal::BigReal(double realNumber) {//constructor to convert double to BigReal.
    string str = to_string(realNumber);
    if (str[0] == '-')
    {
        sign = '-';
        str.erase(0, 1);
    }
    else
    {
        sign = '+';
    }
    number = str;
}
BigReal::BigReal(BigDecimalInt bigDecimalInt) {//constructor to convert BigDecimalInt to BigReal.
    if (bigDecimalInt.sign == '-')
    {
        sign = '-';
    }
    else
    {
        sign = '+';
    }
    number = bigDecimalInt.number+'.'+'0';
    string num1="\0";
    bool tmp= false;
    for (int i=0;i<number.size();i++){
        if (number[i]=='0' && !tmp){
            continue;
        }
        else{
            tmp = true;
            num1+=number[i];
        }
    }
    number = num1;
    if (number[0]=='.'){
        number = '0'+number;
    }
}
BigReal::BigReal (const BigReal& other){//copy constructor.
    number = other.number;
    sign = other.sign;
}
BigReal ::BigReal(BigReal &&other) {//move constructor.
    number = other.number;
    sign = other.sign;
    other.number = "";
    other.sign = '+';
}
BigReal& BigReal:: operator= (BigReal& other){//copy assignment operator.
    number = other.number;
    sign = other.sign;
    return *this;
}
BigReal& BigReal:: operator= (BigReal&& other){//move assignment operator.
    number = other.number;
    sign = other.sign;
    other.number = "";
    other.sign = '+';
    return *this;
}

BigReal BigReal::operator+(BigReal &other) {
    //operator + overloading function.
    BigReal obj;
    string num1 = number;
    string num2 = other.number;
    string res = "";
    // Before proceeding further, make sure sign
    int number1_be = 0, number2_be = 0;
    int number1_af = 0, number2_af = 0;
    bool findDot1 = false;
    // Find the position of dot in first number
    for (int i = 0; i < num1.size(); i++) {
        if (num1[i] == '.') {
            findDot1 = true;
            continue;
        }
        if (!findDot1) {
            number1_be++;
        } else {
            number1_af++;
        }
    }
    bool findDot2 = false;
    // Find the position of dot in second number
    for (int i = 0; i < num2.size(); i++) {
        if (num2[i] == '.') {
            findDot2 = true;
            continue;
        }
        if (!findDot2) {
            number2_be++;
        } else {
            number2_af++;
        }
    }
    // Find the maximum of lengths of two numbers
    if (number1_af > number2_af) {
        for (int i = 0; i < number1_af - number2_af; i++) {
            num2 += '0';
        }
    } else {
        for (int i = 0; i < number2_af - number1_af; i++) {
            num1 += '0';
        }
    }
    if (number1_be > number2_be) {
        for (int i = 0; i < number1_be - number2_be; i++) {
            num2 = '0' + num2;
        }
    } else {
        for (int i = 0; i < number2_be - number1_be; i++) {
            num1 = '0' + num1;
        }
    }
    if (sign == other.sign) {//if both numbers have the same sign.
        obj.sign = sign;
        int carry = 0;
        for (int i = num1.size() - 1; i >= 0; i--) {//loop to add the numbers.
            if (num1[i] == '.') {
                res = '.' + res;
                continue;
            }
            int tmp = (num1[i] - '0') + (num2[i] - '0') + carry;
            carry = tmp / 10;
            tmp = tmp % 10;
            res = to_string(tmp) + res;
        }
        if (carry != 0) {
            res = to_string(carry) + res;
        }
    } else {//if both numbers have different signs.
        if (number1_be>number2_be){
            obj.sign = sign;
        }
        else if (number1_be<number2_be){
            obj.sign = other.sign;
        }
        else{
            for (int i=0;i<num1.size();i++){
                if (num1[i]>num2[i]){
                    obj.sign = sign;
                    break;
                }
                else if (num1[i]<num2[i]){
                    obj.sign = other.sign;
                    break;
                }
            }
        }
        if (sign =='-') {//if the first number is negative.
            BigReal tmp = num1;
            BigReal tmp2 = num2;
            BigReal obj1 =tmp2-tmp;//call the operator - function.
            res=obj1.number;//get the result.
        }
        else{
            BigReal tmp = num1;//if the second number is negative.
            BigReal tmp2 = num2;
            //call the operator - function.
            BigReal obj1 =tmp-tmp2;
            res=obj1.number;//get the result.
        }
    }
    string num3="\0";//remove the zeros before the number.
    bool tmp= false;
    for (int i=0;i<res.size();i++){
        if (res[i]=='0' && !tmp){
            continue;
        }
        else{
            tmp = true;
            num3+=res[i];
        }
    }
    res = num3;
    if (res[0]=='.'){
        res = '0'+res;
    }
    obj.number = res;
    return obj;//return the result.
}
BigReal BigReal::operator-(BigReal &other){
    BigReal obj;//operator - overloading function.
    string num1 = number;
    string num2 = other.number;
    string res = "";
    int number1_be = 0, number2_be = 0;
    int number1_af = 0, number2_af = 0;
    bool findDot1 = false;
    for (int i = 0; i < num1.size(); i++) {// Find the position of dot in first number
        if (num1[i] == '.') {
            findDot1 = true;
            continue;
        }
        if (!findDot1) {
            number1_be++;
        } else {
            number1_af++;
        }
    }
    bool findDot2 = false;
    for (int i = 0; i < num2.size(); i++) {// Find the position of dot in second number
        if (num2[i] == '.') {
            findDot2 = true;
            continue;
        }
        if (!findDot2) {
            number2_be++;
        } else {
            number2_af++;
        }
    }
    if (number1_af > number2_af) {// Find the maximum of lengths of two numbers
        for (int i = 0; i < number1_af - number2_af; i++) {
            num2 += '0';
        }
    } else {
        for (int i = 0; i < number2_af - number1_af; i++) {
            num1 += '0';
        }
    }
    if (number1_be > number2_be) {
        for (int i = 0; i < number1_be - number2_be; i++) {
            num2 = '0' + num2;
        }
    } else {
        for (int i = 0; i < number2_be - number1_be; i++) {
            num1 = '0' + num1;
        }
    }
    if (sign!=other.sign){
        //if both numbers have different signs.
      if (sign =='-'){
          obj.sign = '-';
      }
        else {
          obj.sign = '+';
      }
        if (sign =='-') {//if the first number is negative.
            BigReal tmp = num1;
            BigReal tmp2 = num2;
            BigReal obj1 =tmp2+tmp;//call the operator + function.
            res=obj1.number;
        }
        else{
            //if the second number is negative.
            BigReal tmp = num1;
            BigReal tmp2 = num2;
            BigReal obj1 =tmp+tmp2;//call the operator + function.
            res=obj1.number;
        }
    }
    else{
        bool makeswap=false;//if both numbers have the same sign.
        if (number1_be>number2_be){
            obj.sign = '+';
        }
        else if (number1_be<number2_be){//find the bigger number.
            obj.sign = '-';
            makeswap=true;
        }
        else{
            for (int i=0;i<num1.size();i++){
                if (num1[i]>num2[i]){
                    obj.sign = '+';
                    break;
                }
                else if (num1[i]<num2[i]){
                    obj.sign = '-';
                    makeswap=true;
                    break;
                }
            }
        }
        if (makeswap==true){//swap the numbers.
            swap(num1,num2);
        }
        int carry = 0;
        for (int i = num1.size() - 1; i >= 0; i--) {
            //loop to subtract the numbers.
            if (num1[i] == '.') {
                res = '.' + res;
                continue;
            }
            int tmp = (num1[i] - '0') - (num2[i] - '0') - carry;
            if (tmp < 0) {
                tmp += 10;
                carry = 1;
            } else {
                carry = 0;
            }
            res = to_string(tmp) + res;
        }
        if (carry != 0) {
            res = to_string(carry) + res;
        }
    }
    string num3="\0";//remove the zeros before the number.
    bool tmp= false;
    for (int i=0;i<res.size();i++){
        if (res[i]=='0' && !tmp){
            continue;
        }
        else{
            tmp = true;
            num3+=res[i];
        }
    }
    res = num3;
    if (res[0]=='.'){
        res = '0'+res;
    }
    obj.number = res;
    return obj;//return the result.
}
bool BigReal::operator<(BigReal anotherReal) {
    if (sign == '-' && anotherReal.sign == '+')//if the first number is negative.
    {
        return true;
    }
    else if (sign == '+' && anotherReal.sign == '-')
    {
        return false;
    }
    else if (sign == '+' && anotherReal.sign == '+')
    {
        if (number.size() < anotherReal.number.size())
        {
            return true;
        }
        else if (number.size() > anotherReal.number.size())
        {
            return false;
        }
        else
        {
            for (int i = 0; i < number.size(); i++)
            {
                if (number[i] < anotherReal.number[i])
                {
                    return true;
                }
                else if (number[i] > anotherReal.number[i])
                {
                    return false;
                }
            }
        }
    }
    else if (sign == '-' && anotherReal.sign == '-')
    {
        if (number.size() > anotherReal.number.size())
        {
            return true;
        }
        else if (number.size() < anotherReal.number.size())
        {
            return false;
        }
        else
        {
            for (int i = 0; i < number.size(); i++)
            {
                if (number[i] > anotherReal.number[i])
                {
                    return true;
                }
                else if (number[i] < anotherReal.number[i])
                {
                    return false;
                }
            }
        }
    }
    return false;//return the result.
}

bool BigReal::operator>(BigReal anotherReal) {//check if the first number is bigger than the second number.
    if (sign == '-' && anotherReal.sign == '+')
    {
        return false;
    }
    else if (sign == '+' && anotherReal.sign == '-')
    {
        return true;
    }
    else if (sign == '+' && anotherReal.sign == '+')
    {
        if (number.size() > anotherReal.number.size())
        {
            return true;
        }
        else if (number.size() < anotherReal.number.size())
        {
            return false;
        }
        else
        {
            for (int i = 0; i < number.size(); i++)
            {
                if (number[i] > anotherReal.number[i])
                {
                    return true;
                }
                else if (number[i] < anotherReal.number[i])
                {
                    return false;
                }
            }
        }
    }
    else if (sign == '-' && anotherReal.sign == '-')
    {
        if (number.size() < anotherReal.number.size())
        {
            return true;
        }
        else if (number.size() > anotherReal.number.size())
        {
            return false;
        }
        else
        {
            for (int i = 0; i < number.size(); i++)
            {
                if (number[i] < anotherReal.number[i])
                {
                    return true;
                }
                else if (number[i] > anotherReal.number[i])
                {
                    return false;
                }
            }
        }
    }
    return false;
}
bool BigReal::operator==(BigReal anotherReal) {
    //check if the numbers are equal.
    if (sign == anotherReal.sign && number == anotherReal.number)
    {
        return true;
    }
    return false;
}
int BigReal::size() {
    //return the size of the number.
  return number.size();
}
int BigReal::Sign() {
    //return the sign of the number.
  if (sign == '+')
    return 1;
  else
    return 0;
}
bool BigReal::RcheckValidInput(string input) {
    //check if the input is valid.
    regex validInput("[+-]?([0-9]+([.][0-9]*)?|[.][0-9]+)");
    return regex_match(input, validInput);
}
void BigReal::RsetNumber(string num) {
    //set the number.
    bool validnumber=RcheckValidInput(num);
    if(validnumber)
    {
        number = num;
        if(number[0] == '+')
        {
            number.erase(0,1);
            sign = '+';
        }
        else if (number[0] == '-')
        {
            number.erase(0,1);
            sign = '-';
        }
        else
        {
            sign = '+';
        }
    }
    else
    {
        cout<<"Invalid Input"<<endl;
    }
    if (number=="0.0") {
        return;
    }
    string num1;
    bool tmp= false;
    for (int i=0;i<number.size();i++){
        if (number[i]=='0' && !tmp){
            continue;
        }
        else{
            tmp = true;
            num1+=number[i];
        }
    }
    tmp= false;
    number = num1;
    if (number[0]=='.'){
        number = '0'+number;
    }
    if (number.find('.')==string::npos){
        number+=".0";
        return;
    }
    num1="\0";
    for (int i=number.size()-1;i>=0;i--){
        if (number[i]=='0' && !tmp){
            continue;
        }
        else{
            tmp = true;
            num1+=number[i];
        }
    }
    number = num1;
    reverse(number.begin(),number.end());
    if (number[number.size()-1]=='.'){
        number = number+'0';
    }
}
