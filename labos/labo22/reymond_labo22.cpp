/**
 * @file    reymond_labo4.cpp
 * @author  Nicolas Reymond (nicolas.reymond@heig-vd.ch)
 * @brief   
 * @version 1.0
 * @date    20-09-2024
 *
 * @copyright Copyright (c) 2024
 *
 */


#include <iostream>
#include <array>
#include <vector>
#include <cstring>

using namespace std;


struct HeureMinute {
    int heure;
    int minute;
    bool operator<(const HeureMinute& other) const {
        if (heure == other.heure) {
            return minute < other.minute;
        }
        return heure < other.heure;
    }
};


template <typename T, typename U>
int count_if_less_than(T start, T end, U val) {
    int count = 0;
    for (auto it = start; it != end; ++it) {
        if (*it < val) {
            ++count;
        }
    }
    return count;
}

template <>
int count_if_less_than(const char **start, const char **end, const char *val)
{
    int count = 0;
    for (auto it = start; it != end; ++it)
    {
        if (strcmp(*it, val) < 0)
        {
            ++count;
        }
    }
    return count;
}

int main(){
    int t[] = {0, 1, 2, 0, 3, 0};
    cout << "Count in t less than 2: " << count_if_less_than(t, end(t), 2) << endl;
    
    array<string, 4> a = {"Paul", "Jacques", "Paul", "Pie"};
    cout << "Count in a less than \"Paul\": " << count_if_less_than(a.cbegin(), a.cend(), "Paul") << endl;
    
    vector<HeureMinute> hm = {{7, 45}, {9, 20}, {12, 0}, {21, 30}};
    cout << "Count in hm less than {10, 0}: " << count_if_less_than(hm.cbegin(), hm.cend(), HeureMinute{10, 0}) << endl;

    const char* c[] = {"Paul", "Jacques", "Paul", "Pie"}; 
    cout << "Count in c less than \"Paul\": " << count_if_less_than(c, c + 4, "Paul") << endl;

    return 0;
}