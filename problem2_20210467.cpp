//Name : Yousef Hussien Awad
//ID:20210467
//Section: s8
//Faculty Of Computer And Artificial Intelligence Cairo University
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
//Y O U S E F <<<><><>>>
//<<<<<<<<< رب هب لي علما والحقني بالصالحين >>>>>>>>>
class LabelGenerator {//my class
protected:
    string series_of_names;//the series of names
    int series_of_numbers;//the series of numbers
public:
    LabelGenerator(string series_of_names, int series_of_numbers) {
        //parameterized constructor to initialize the series of names and the series of numbers
        this->series_of_names = series_of_names;
        this->series_of_numbers = series_of_numbers;
    }
    virtual string nextLabel() {
        //virtual function to return the next label
        return series_of_names + to_string(series_of_numbers++);
    }
};
class FileLabelGenerator :public LabelGenerator {//my class
private:
    string filename;//the name of the file
    string data;//the data in the file

public:
    FileLabelGenerator(string series_of_names, int series_of_numbers, string filename) : LabelGenerator(series_of_names, series_of_numbers)
    {//parameterized constructor to initialize the series of names and the series of numbers and the name of the file
        this->filename = filename;
    };
    string nextLabel() {//function to return the next label
        ifstream file(filename);
        if (file.is_open())//if the file is open
        {
            int i = 1;
            while (getline(file, data))
            {
                if (i == series_of_numbers)
                {
                    return series_of_names + to_string(series_of_numbers++) + ' ' + data;
                }
                i++;
            }
            file.close();//close the file
        }
        else //if the file is not open
            cout << "Unable to open file";
    }
};
int main()
{
    LabelGenerator figureNumbers("Figure ", 1);//object of the class LabelGenerator
    LabelGenerator pointNumbers("P", 0);//object of the class LabelGenerator
    cout << "Figure numbers: ";
    for (int i = 0; i < 3; i++) {//loop to print the next label
        cout << figureNumbers.nextLabel() << ", ";
    }
    cout << endl << "Point numbers: ";
    for (int i = 0; i < 5; i++) {
        cout << pointNumbers.nextLabel() << ", ";//loop to print the next label
    }
    cout << endl << "More figures: ";
    for (int i = 0; i < 3; i++) {
        cout << figureNumbers.nextLabel() << ", ";//loop to print the next label
    }
    cout << endl;
    FileLabelGenerator figureLabels("Figure ", 1, "labels.txt");//object of the class FileLabelGenerator
    cout << "Figure labels: \n";
    for (int i = 0; i < 3; i++) {//loop to print the next label
        cout << figureLabels.nextLabel() << endl;
    }
    return 0;//end of the program
}
