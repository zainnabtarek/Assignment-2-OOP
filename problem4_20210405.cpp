//Name: Mennatallh Mahmoud
//ID: 20210405
//Sheet 2 (problem 4)
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;
ifstream taskList("tasklist.txt");
bool sorting(string str1, string str2); 
vector <string> programs;
vector <string> pid;
vector <string> usage;
vector <string> name;
class TaskManager
{
    string programData, imageName, PID, memUsage, noSImageName, noSPID, noSMemUsage, function;
    int k = 0, l = 0;
    public:
        TaskManager()
        {
            cout << "Hi user if u wanna" << endl << "1- print the unsorted content ==> call the function(print) and pass(nonsorted)" << endl 
            << "2- print the content sorted by memory usage ==> call the function(print) and pass(usage)" << endl 
            << "3- print the content sorted by PID ==> call the function(print) and pass (PID)" << endl
            << "4- print the content sorted by name ==> call the function(print) and pass(name)" << endl << endl;
            
        }
        void print(string func)
        {
            function = func;
            while(getline(taskList,programData))
            {
                //deviding the data of the program to (imageName,PID,memUsage)
                imageName = programData.substr(0,25);
                PID = programData.substr(26,8);
                memUsage = programData.substr(64,12);
                //removing spaces
                for(size_t i = 0; i < 25; ++i)
                {
                    if(imageName[i] != ' ')
                        noSImageName += imageName[i];
                    else
                        continue;
                }
                for(size_t i = 0; i < 8; ++i)
                {
                    if(PID[i] != ' ')
                        noSPID += PID[i];
                    else
                        continue;
                }
                for(size_t i = 0; i < 12; ++i)
                {
                    if(memUsage[i] != ' ')
                        noSMemUsage += memUsage[i];
                    else
                        continue;
                }
                //saving the data on a vector
                programs.push_back(noSImageName);
                programs.push_back(noSPID);
                programs.push_back(noSMemUsage);
                //erasing data in the containers(strings)
                imageName = "";
                PID = "";
                memUsage = "";
                noSImageName = "";
                noSPID = "";
                noSMemUsage = "";
            }
            if (function == "nonsorted")
            {
                k = 0;
                l = 2;
                cout << left << setw(30) << "Program"<< setw(30) << "PID" << setw(30) << "Usage" << endl;
                //print the vector of the programs
                for(auto program : programs)
                {
                    if(k != l)
                        cout << left << setw(30) << program;
                    else
                    {
                        cout  <<  left << setw(30) <<  program << endl;
                        l += 3;
                    }
                    ++k;    
                }
            }
            else if (function == "usage")
            {
                //putting all the memUsage in one vector  
                for(size_t i = 2; i < programs.size(); i+=3)
                {
                    usage.push_back(programs[i]);
                }
                //sorting the memUsage
                sort(usage.begin(),usage.end(),sorting);
                cout << left << setw(30) << "Program"<< setw(30) << "PID" << setw(30) << "Usage" << endl;
                //printing the vector sorted by memUsage
                for(size_t i = 0; i < programs.size(); ++i)
                {
                    for(size_t j = 2; j < programs.size(); j+=3)
                    {
                        if (usage[i] == programs[j])
                            cout << left << setw(30) << programs[j-2] << setw(30) <<  programs[j-1] << setw(30) << programs[j] << endl;
                        else
                            continue;
                    }
                }
            }
            else if (function == "PID")
            {
                //putting all the PID in one vector 
                for(size_t i = 1; i < programs.size(); i+=3)
                {
                    pid.push_back(programs[i]);
                }
                //sorting the PID
                sort(pid.begin(),pid.end(),sorting);
                cout << left << setw(30) << "Program"<< setw(30) << "PID" << setw(30) << "Usage" << endl;
                //printing the vector sorted by PID
                for(size_t i = 0; i < programs.size(); ++i)
                {
                    for(size_t j = 1; j < programs.size(); j+=3)
                    {
                        if (pid[i] == programs[j])
                            cout << left << setw(30) << programs[j-1] << setw(30) << programs[j] << setw(30) << programs[j+1] << endl;
                        else
                            continue;
                    }
                }
            }
            else if (function == "name")
            {
                //putting all the imageName in one vector 
                for(size_t i = 0; i < programs.size(); i+=3)
                {
                    name.push_back(programs[i]);
                }
                //sorting the name
                sort(name.begin(),name.end(),sorting);
                cout << left << setw(30) << "Program"<< setw(30) << "PID" << setw(30) << "Usage" << endl;
                //printing the vector sorted by imageName
                for(size_t i = 0; i < programs.size(); ++i)
                {
                    for(size_t j = 0; j < programs.size(); j+=3)
                    {
                        if (name[i] == programs[j])
                            cout << left << setw(30) << programs[j] << setw(30) << programs[j+1] << setw(30) << programs[j+2] << endl;
                        else
                            continue;
                    }
                }
            }
            else
                cout << "wrong input";
        }
};


int main() 
{
    TaskManager pro;
    pro.print("usage");
    return 0;
}


bool sorting(string s1, string s2) 
{
    if(s1.size() == s2.size())
        return s1 < s2;
    else 
        return s1.size() < s2.size();
}


