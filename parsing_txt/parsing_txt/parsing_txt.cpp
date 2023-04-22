// parsing_txt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    string filename = "stats.txt";
    ifstream input;
    string line;
    int population;

    input.open(filename);
    if (!input.is_open())
    {
        cout << "Could not open file." << endl;
        return 1;
    }

    while (getline(input, line, ':') && input >> population)
    {
        //remove blank line
        //input.get();
        input >> ws;
        cout << line << " -- " << population << endl;
    }

    input.close();

    /*
    while (getline(input, line))
    {
        string delimiter = ":";
        size_t pos = line.find(delimiter);
        if (pos != string::npos)
        {
            string stat_name = line.substr(0, pos);
            string stat_value = line.substr(pos + 1);
            int population = stoi(stat_value);
            cout << stat_name << " -- " << population << endl;
        }
    }
    */
    
    

    input.close();

    return 0;
}
