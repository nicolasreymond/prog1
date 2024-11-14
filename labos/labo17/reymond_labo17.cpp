/**
 * @file    reymond_labo17.cpp
 * @author  Nicolas Reymond (nicolas.reymond@heig-vd.ch)
 * @brief   Various vector operations and tests
 * @version 1.0
 * @date    20-09-2024
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <numeric>

using namespace std;

// Overloading << operator to display vector<int>
ostream &operator<<(ostream &os, const vector<int> &v) {
    os << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1) os << ", ";
    }
    os << "]";
    return os;
}

// Function to find the longest sequence of identical adjacent elements
pair<int, int> longestIdenticalSequence(const vector<int> &v) {
    if (v.empty()) return {0, -1};

    int maxLength = 1, maxStart = 0, currentLength = 1, currentStart = 0;

    for (size_t i = 1; i < v.size(); ++i) {
        if (v[i] == v[i - 1]) {
            ++currentLength;
            if (currentLength > maxLength) {
                maxLength = currentLength;
                maxStart = currentStart;
            }
        } else {
            currentLength = 1;
            currentStart = i;
        }
    }
    return {maxLength, maxStart};
}

// Function to check if two vectors have the same elements with duplicates
bool areVectorsEqual(const vector<int> &v1, const vector<int> &v2) {
    if (v1.size() != v2.size()) return false;
    vector<int> sortedV1 = v1, sortedV2 = v2;
    sort(sortedV1.begin(), sortedV1.end());
    sort(sortedV2.begin(), sortedV2.end());
    return sortedV1 == sortedV2;
}

// Function to check if two vectors have at least one common element
bool haveCommonElements(const vector<int> &v1, const vector<int> &v2) {
    for (const int &element : v1) {
        if (find(v2.begin(), v2.end(), element) != v2.end()) {
            return true;
        }
    }
    return false;
}

// Overloading + operator to add two vectors as large numbers
vector<int> operator+(const vector<int> &v1, const vector<int> &v2) {
    vector<int> result;
    int carry = 0;
    size_t maxSize = max(v1.size(), v2.size());

    for (size_t i = 0; i < maxSize; ++i) {
        // Get the least significant digit of each number
        int digit1 = (i < v1.size()) ? v1[v1.size() - 1 - i] : 0;
        int digit2 = (i < v2.size()) ? v2[v2.size() - 1 - i] : 0;
        int sum = digit1 + digit2 + carry;
        // Add the least significant digit to the result
        result.push_back(sum % 10);
        // Update the carry
        carry = sum / 10;
    }
    // Add the last carry if any
    if (carry) result.push_back(carry);

    // Reverse the result to get the correct order
    reverse(result.begin(), result.end());
    return result;
}

// Merge function for sorted vectors in linear time
vector<int> mergeSortedVectors(const vector<int> &v1, const vector<int> &v2) {
    vector<int> result;
    size_t i = 0, j = 0;

    while (i < v1.size() && j < v2.size()) {
        if (v1[i] < v2[j]) result.push_back(v1[i++]);
        else result.push_back(v2[j++]);
    }

    while (i < v1.size()) result.push_back(v1[i++]);
    while (j < v2.size()) result.push_back(v2[j++]);

    return result;
}

// Recursive merge sort for vector<int>
void mergeSort(vector<int> &v) {
    if (v.size() < 2) return;

    vector<int> va(v.begin(), v.begin() + v.size() / 2), vb(v.begin() + v.size() / 2, v.end());

    mergeSort(va);
    mergeSort(vb);

    v = mergeSortedVectors(va, vb);
}

// Merge function for sorted vectors in linear time
void tri_fusion(vector<int> &v) {
    if (v.size() < 2) // Déjà trié, on ne fait rien
        return;
    vector<int> va, vb;
    va.insert(va.begin(), v.begin(), v.begin() + v.size() / 2); // début de v
    vb.insert(vb.begin(), v.begin() + v.size() / 2, v.end()); // fin de v
    tri_fusion(va);
    tri_fusion(vb);
    v = mergeSortedVectors(va, vb);
}

// Test all functions and print Fibonacci sequence
void testFunctions() {
    vector<int> v1 = {1, 2, 2, 3, 3, 3, 4}, 
                v2 = {3, 3, 3, 4, 1, 2, 2},     
                largeNumber1 = {9, 9, 5, 9}, 
                largeNumber2 = {1, 4, 5, 6};

    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;

    // Testing longest identical sequence
    auto [length, position] = longestIdenticalSequence(v1);
    cout << "Longest identical sequence in v1: Length = " << length << ", Position = " << position << endl;

    // Testing vector equality
    bool isEqual = areVectorsEqual(v1, v2);
    cout << "Are v1 and v2 equal? " << (isEqual ? "Yes" : "No") << endl;

    cout << "largeNumber1: " << largeNumber1 << endl;
    cout << "largeNumber2: " << largeNumber2 << endl;
    
    // Testing addition of large numbers
    vector<int> sum = largeNumber1 + largeNumber2;
    cout << "Sum of largeNumber1 and largeNumber2: " << sum << endl;

    // Testing merging of sorted vectors
    vector<int> sortedV1 = {1, 3, 5}, sortedV2 = {2, 4, 6}, merged = mergeSortedVectors(sortedV1, sortedV2);
    cout << "Merged sorted vectors: " << merged << endl;

    // Sorting using mergeSort
    vector<int> unsorted = {5, 2, 9, 1, 5, 6};
    cout << "Unsorted vector: " << unsorted << endl;
    tri_fusion(unsorted);
    cout << "Sorted vector using mergeSort: " << unsorted << endl;

    // Calculating Fibonacci numbers
    // Number of Fibonacci numbers
    int n = 10; 
    vector<int> fib = {0, 1};
    for (int i = 2; i <= n; ++i) fib.push_back(fib[i - 1] + fib[i - 2]);
    cout << "First " << n + 1 << " Fibonacci numbers: " << fib << endl;
}

int main() {
    testFunctions();
    return 0;
}
