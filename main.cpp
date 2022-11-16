#include <iostream>
#include <algorithm>
#include <iomanip>
#include "BigInteger.h"
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
#define _for(a) for(int i = 0; i < (a); ++i)
#define _rep(a, b) for(size_t i = (a); i < (b); ++i)
#define  _for_each(my_vec) for(auto x:my_vec)
#define  __for_each(my_vec) for(auto &x:my_vec)
#define my_vec(size) vector<ll>my_vec(size)
#define q1  cin.tie(0)
#define q2 cin.sync_with_stdio(0)
using namespace std;
//Y O U S E F <<<><ÃƒËœÃ‚Â¨ÃƒËœÃ‚Â³Ãƒâ„¢Ã¢â‚¬Â¦ ÃƒËœÃ‚Â§Ãƒâ„¢Ã¢â‚¬Å¾Ãƒâ„¢Ã¢â‚¬Å¾Ãƒâ„¢Ã¢â‚¬Â¡ ÃƒËœÃ‚Â§Ãƒâ„¢Ã¢â‚¬Å¾ÃƒËœÃ‚Â±ÃƒËœÃ‚Â­Ãƒâ„¢Ã¢â‚¬Â¦Ãƒâ„¢Ã¢â‚¬Â  ÃƒËœÃ‚Â§Ãƒâ„¢Ã¢â‚¬Å¾ÃƒËœÃ‚Â±ÃƒËœÃ‚Â­Ãƒâ„¢Ã…Â Ãƒâ„¢Ã¢â‚¬Â¦><ÃƒËœÃ‚Â±ÃƒËœÃ‚Â¨Ãƒâ„¢Ã…Â  Ãƒâ„¢Ã¢â‚¬Â¡ÃƒËœÃ‚Â¨ Ãƒâ„¢Ã¢â‚¬Å¾Ãƒâ„¢Ã…Â  ÃƒËœÃ‚Â¹Ãƒâ„¢Ã¢â‚¬Å¾Ãƒâ„¢Ã¢â‚¬Â¦ÃƒËœÃ‚Â§ Ãƒâ„¢Ã‹â€ ÃƒËœÃ‚Â§Ãƒâ„¢Ã¢â‚¬Å¾ÃƒËœÃ‚Â­Ãƒâ„¢Ã¢â‚¬Å¡Ãƒâ„¢Ã¢â‚¬Â Ãƒâ„¢Ã…Â  ÃƒËœÃ‚Â¨ÃƒËœÃ‚Â§Ãƒâ„¢Ã¢â‚¬Å¾ÃƒËœÃ‚ÂµÃƒËœÃ‚Â§Ãƒâ„¢Ã¢â‚¬Å¾ÃƒËœÃ‚Â­Ãƒâ„¢Ã…Â Ãƒâ„¢Ã¢â‚¬Â >>>
int main() {
    BigDecimalInt num1("123456789012345678901234567890");
    BigDecimalInt num2("+113456789011345678901134567890");
    BigDecimalInt num3("-200000000000000000000000000000");
    BigDecimalInt num4 = num2 + num1;
    BigDecimalInt num5 = num3 - num2;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    cout << "num3 = " << num3 << endl;
    //Next statement will print 236913578023691357802369135780
    cout << "num2 + num1 = " << num4 << endl;
    //Next statement will print -313456789011345678901134567890
    cout << "num3 - num2 = " << num5 << endl;
    cout << (num1 > num2) << endl;
    cout << (num1 < num2) << endl;
    cout << (num1 == num2) << endl;
}
