/**
 * @file    reymond_labo3.cpp
 * @author  Nicolas Reymond (nicolas.reymond@heig-vd.ch)
 * @brief   Replace all occurrences of a string in a string with two differente and measure the time taken
 * @version 1.0
 * @date    04.11.2024
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;

string replace_all_GPT(string str, const string& from, const string& to) {
    if (from.empty())
        return str;
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}

string &replace_all(string &str, const string &from, const string &to)
{
    string result;
    size_t start_pos = 0;
    size_t found_pos;
    while ((found_pos = str.find(from, start_pos)) != string::npos)
    {
        result.append(str, start_pos, found_pos - start_pos);
        result.append(to);
        start_pos = found_pos + from.length();
    }
    result.append(str, start_pos, str.length() - start_pos);
    str = result;
    return str;
}

void process_file(const string& filename, int k, const string& option) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string str((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    if (k > 0) {
        for (int i = 0; i < k; ++i) {
            str += str;
        }
    } else if (k < 0) {
        str.resize(str.length() / (1 << -k));
    }

    auto t1 = chrono::high_resolution_clock::now();

    if (option == "GPT") {
        str = replace_all_GPT(str, "de ", "xYxYx");
        str = replace_all_GPT(str, "xYxYx", "de ");
    } else {
        replace_all(str, "de ", "xYxYx");
        replace_all(str, "xYxYx", "de ");
    }

    auto t2 = chrono::high_resolution_clock::now();
    chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

    cout << "Length of the string: " << str.length() << endl;
    cout << "Time taken: " << time_span.count() << " seconds" << endl;
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        cerr << "Usage: " << argv[0] << " <filename> <k> <option>" << endl;
        return 1;
    }

    string filename = argv[1];
    int k = stoi(argv[2]);
    string option = argv[3];

    process_file(filename, k, option);

    return 0;
}