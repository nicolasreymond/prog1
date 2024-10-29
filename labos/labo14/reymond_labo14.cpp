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
#include <string>

using namespace std;

string &replace_all(string &str, const string &from, const string &to){
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != string::npos){
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}

int main() {

    string str = "Hello, World!, I am titi and I am tata. I want to be toto but I am not. And my friend is tititotata.";
    string from;
    cout << "Enter the string to replace: ";
    cin >> from;

    string to;
    cout << "Enter the string to replace with: ";
    cin >> to;

    cout << "Before: " << str << endl;
    replace_all(str, from, to);
    cout << "After: " << str << endl;

    return 0;

}