/**
 * @file    reymond_labo3.cpp
 * @author  Nicolas Reymond (nicolas.reymond@heig-vd.ch)
 * @brief   
 * @version 1.0
 * @date    28.10.2024
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string &replace_all(string &str, const string &from, const string &to){
    string result;
    size_t start_pos = 0;
    size_t found_pos;
    while((found_pos = str.find(from, start_pos)) != string::npos){
        result.append(str, start_pos, found_pos - start_pos);
        result.append(to);
        start_pos = found_pos + from.length();
    }
    result.append(str, start_pos, str.length() - start_pos);
    str = result;
    return str;
}

int main() {

    ifstream in_file("la_comedie_humaine.txt");

    if (!in_file){
        cout << "Error opening file" << endl;
        return 1;
    }

    string strInput;
    while (in_file)
    {
        string str;
        getline(in_file, str);
        strInput += str + "\n";
    }

    in_file.close();

    string str = "Hello, World!, I am titi and I am tata. I want to be toto but I am not. And my friend is tititotata.";
    string from = "on";
    // cout << "Enter the string to replace: ";
    // cin >> from;

    string to = "TOTO";
    // cout << "Enter the string to replace with: ";
    // cin >> to;

    cout << "Before: " << strInput << endl;
    replace_all(strInput, from, to);
    cout << "After: " << strInput << endl;

    return 0;
    }