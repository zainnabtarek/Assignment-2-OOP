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
//#define s second
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
//<<<<<<<<< رب هب لي علما والحقني بالصالحين >>>>>>>>
class Universe { //my class
    int row, column;// deminsion of the universe
    vector<vector<int>>universe;// the 2d vector that will contain the universe
public:
    Universe() {//default constructor to initialize the universe
        row = 0;//initialize the row by 0
        column = 0;//initialize the column by 0
        vector<vector<int>>universe = { {0,0} };//initialize 2d vector by 0
    }
    Universe(int row, int column, vector<vector<int>>universe) {
        //constructor to initialize the universe from user
        this->row = row;//initialize the row
        this->column = column;//initialize the column
        this->universe = universe;//initialize the universe
    }
    int number_of_neighbours(int i, int j) {
        //function to calculate the number of neighbours of a cell
        int count = 0;//initialize the count by 0
        if (i - 1 >= 0 && j - 1 >= 0 && universe[i - 1][j - 1] == 1)count++;  //check if the cell is alive
        if (i - 1 >= 0 && universe[i - 1][j] == 1)count++;
        if (i - 1 >= 0 && j + 1 < column && universe[i - 1][j + 1] == 1)count++;
        if (j - 1 >= 0 && universe[i][j - 1] == 1)count++;
        if (j + 1 < column && universe[i][j + 1] == 1)count++;
        if (i + 1 < row && j - 1 >= 0 && universe[i + 1][j - 1] == 1)count++;
        if (i + 1 < row && universe[i + 1][j] == 1)count++;
        if (i + 1 < row && j + 1 < column && universe[i + 1][j + 1] == 1)count++;
        return count;
    }
    void next_generation() {
        vector<vector<int>>temp = universe;//create a temp vector to store the next generation
        for (int i = 0;i < row;i++) {
            for (int j = 0;j < column;j++) {
                int count = number_of_neighbours(i, j);//calculate the number of neighbours
                if (universe[i][j] == 1) {//if the cell is alive
                    if (count < 2 || count>3)temp[i][j] = 0;
                }
                else {//if the cell is dead
                    if (count == 3)temp[i][j] = 1;
                }
            }
        }
        universe = temp;//update the universe
    }
    void Display() {//function to display the 2d vector
        for (int i = 0;i < row;i++) {
            for (int j = 0;j < column;j++) {
                cout << universe[i][j] << " | ";
            }
            cout << endl;
        }
        cout << endl;
    }
    void Run(int n) {
        //function to run the universe for n generations
        cout << "2 D vector after the next generation==>" << endl;
        for (int i = 0;i < n;i++) {
            next_generation();//call the next generation function
            Display();//display the universe
        }
    }

};
int main() {
    int row, column, n;//deminsion of the 2d vector
    cout << "Enter the number of rows and columns of the universe==>";
    cin >> row >> column;//take the deminsion of the 2d vector
    vector<vector<int>>universe(row, vector<int>(column));  //2d vector
    cout << "Enter the 2d vector==>";
    for (int i = 0;i < row;i++) {
        for (int j = 0;j < column;j++) {
            cin >> universe[i][j];//take the 2d vector from user
        }
    }
    Universe u(row, column, universe);//create an object from the class
    cout << "2 D vector before the next generation==>" << endl;
    u.Display();//display the before generation
    cout << "Enter the number of generations you want to run==>";
    cin >> n;//take the number of generations from user
    u.Run(n);//run the universe for n generation
    return 0;//end of the program
}
/*
test case:
 1 1 0 0
 1 0 0 0
 0 0 1 1
 1 1 1 1
 1 0 1 0
 number of run : 1 
 1 1 0 0
 1 0 1 0
 1 0 0 1
 1 0 0 0
 1 0 1 1
 */