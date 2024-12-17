// /**
//  * @file    reymond_labo24.cpp
//  * @author  Nicolas Reymond
//  * @brief   Class Unsigned and Setbase for labo 24 and 25 
//  * @version 1.0
//  * @date    12-12-2024
//  */

// #include "reymond_labo24.hpp"
// #include <stdexcept>



// ostream &operator<<(ostream &os, const Setbase &){
//     return os;
// }

// /**
//  * @brief Construct a new Unsigned::Unsigned object
//  */
// Unsigned::Unsigned() : value("0") {}

// /**
//  * @brief Construct a new Unsigned::Unsigned object
//  * 
//  * @param number 
//  */
// Unsigned::Unsigned(uint64_t number){
//     value = "";
//     while (number > 0)
//     {
//         value = char((number % 2) + '0') + value;
//         number /= 2;
//     }
//     if (value.empty())
//     {
//         value = "0";
//     }
// }


// /**
//  * @brief getter
//  * 
//  * @return string
//  */
// string Unsigned::data() const {
//     return value;
// }

// /**
//  * @brief Convert the number to the specified base
//  * 
//  * @param base 
//  * 
//  * @return string
//  */
// string Unsigned::to_base(int base) const
// {
//     if (base == 2)
//     {
//         return value;
//     }

//     uint64_t decimalValue = 0;
//     uint64_t basePower = 1;

//     for (int i = value.size() - 1; i >= 0; --i)
//     {
//         if (value[i] == '1')
//         {
//             decimalValue += basePower;
//         }
//         basePower *= 2;
//     }

//     string result = "";
//     do
//     {
//         int remainder = decimalValue % base;
//         result = char((remainder < 10 ? '0' + remainder : 'a' + remainder - 10)) + result;
//         decimalValue /= base;
//     } while (decimalValue > 0);
//     return result;
// }



// /**
//  * @brief Add two Unsigned objects
//  * 
//  * @param right 
//  * 
//  * @return Unsigned&
//  */
// Unsigned &Unsigned::operator+=(const Unsigned &right){
//     int carry = 0;
//     int leftSize = value.size();
//     int rightSize = right.value.size();
//     string result = "";
//     int i = 0;

//     while (i < leftSize || i < rightSize || carry != 0)
//     {
//         int leftBit = 0;
//         if (i < leftSize)
//         {
//             leftBit = value[leftSize - 1 - i] - '0';
//         }

//         int rightBit = 0;
//         if (i < rightSize)
//         {
//             rightBit = right.value[rightSize - 1 - i] - '0';
//         }

//         int sum = leftBit + rightBit + carry;
//         result = char((sum % 2) + '0') + result;
//         carry = sum / 2;
//         i++;
//     }

//     while (result.size() < max(leftSize, rightSize))
//     {
//         result = '0' + result;
//     }

//     value = result;
//     return *this;
// }


// /**
//  * @brief Add two Unsigned objects
//  * 
//  * @param left 
//  * @param right 
//  * 
//  * @return Unsigned
//  */
// Unsigned operator+(Unsigned left, const Unsigned &right){
//     left += right;
//     return left;
// }


// /**
//  * @brief Subtract two Unsigned objects
//  * 
//  * @param right 
//  * 
//  * @return Unsigned&
//  */
// Unsigned &Unsigned::operator-=(const Unsigned &right){
//     int borrow = 0;
//     int leftSize = value.size();
//     int rightSize = right.value.size();
//     string result = "";
//     int i = 0;

//     while (i < leftSize || i < rightSize || borrow != 0)
//     {
//         int leftBit = 0;
//         if (i < leftSize)
//         {
//             leftBit = value[leftSize - 1 - i] - '0';
//         }

//         int rightBit = 0;
//         if (i < rightSize)
//         {
//             rightBit = right.value[rightSize - 1 - i] - '0';
//         }

//         int diff = leftBit - rightBit - borrow;
//         if (diff < 0)
//         {
//             diff += 2;
//             borrow = 1;
//         }
//         else
//         {
//             borrow = 0;
//         }

//         result = char(diff + '0') + result;
//         i++;
//     }

//     while (result.size() > 1 && result[0] == '0')
//     {
//         result.erase(0, 1);
//     }

//     value = result;
//     return *this;
// }


// /**
//  * @brief Subtract two Unsigned objects
//  * 
//  * @param left 
//  * @param right 
//  * 
//  * @return Unsigned
//  */
// Unsigned operator-(Unsigned left, const Unsigned &right){
//     left -= right;
//     return left;
// }


// /**
//  * @brief Multiply two Unsigned objects
//  * 
//  * @param right 
//  * 
//  * @return Unsigned&
//  */
// Unsigned &Unsigned::operator*=(const Unsigned &right){
//     Unsigned result("0");
//     Unsigned temp = *this;

//     for (int i = right.value.size() - 1; i >= 0; --i)
//     {
//         if (right.value[i] == '1')
//         {
//             result += temp;
//         }
//         temp.value += '0';
//     }

//     value = result.value;
//     return *this;
// }

// /**
//  * @brief Multiply two Unsigned objects
//  * 
//  * @param left 
//  * @param right 
//  * 
//  * @return Unsigned
//  */
// Unsigned operator*(Unsigned left, const Unsigned &right){
//     left *= right;
//     return left;
// }


// /**
//  * @brief Divide two Unsigned objects
//  * 
//  * @param right 
//  * 
//  * @return Unsigned&
//  */
// Unsigned &Unsigned::operator/=(const Unsigned &right){
//     if (right.value == "0")
//     {
//         throw std::invalid_argument("Division by zero");
//     }

//     Unsigned result("0");
//     Unsigned temp("0");

//     for (char bit : value)
//     {
//         temp.value += bit;
//         if (temp.value[0] == '0')
//         {
//             temp.value.erase(0, 1);
//         }
//         result.value += '0';
//         while (temp.value.size() > right.value.size() ||
//                (temp.value.size() == right.value.size() && temp.value >= right.value))
//         {
//             temp -= right;
//             result.value.back() = '1';
//         }
//     }

//     while (result.value.size() > 1 && result.value[0] == '0')
//     {
//         result.value.erase(0, 1);
//     }

//     value = result.value;
//     return *this;
// }


// /**
//  * @brief Divide two Unsigned objects
//  * 
//  * @param left 
//  * @param right 
//  * 
//  * @return Unsigned
//  */
// Unsigned operator/(Unsigned left, const Unsigned &right){
//     return left /= right;
// }


// /**
//  * @brief Compare two Unsigned objects
//  * 
//  * @param right 
//  * 
//  * @return true 
//  * @return false
//  */
// bool Unsigned::operator<(const Unsigned &right) const
// {
//     if (value.size() != right.value.size())
//     {
//         return value.size() < right.value.size();
//     }
//     return value < right.value;
// }


// /**
//  * @brief Compare two Unsigned objects
//  * 
//  * @param right 
//  * 
//  * @return true 
//  * @return false
//  */
// bool Unsigned::operator<=(const Unsigned &right) const
// {
//     return !(right < *this);
// }


// /**
//  * @brief Compare two Unsigned objects
//  * 
//  * @param right 
//  * 
//  * @return true 
//  * @return false
//  */
// bool Unsigned::operator>(const Unsigned &right) const
// {
//     return right < *this;
// }


// /**
//  * @brief Compare two Unsigned objects
//  * 
//  * @param right 
//  * 
//  * @return true 
//  * @return false
//  */
// bool Unsigned::operator>=(const Unsigned &right) const
// {
//     return !(*this < right);
// }


// /**
//  * @brief Compare two Unsigned objects
//  * 
//  * @param right
//  * 
//  * @return true
//  * @return false
//  */
// bool Unsigned::operator!= (const Unsigned &right) const{
//     return value != right.value;
// }

// /**
//  * @brief Compare two Unsigned objects
//  * 
//  * @param right
//  * 
//  * @return true
//  * @return false
//  */
// bool Unsigned::operator== (const Unsigned &right) const{
//     return value == right.value;
// }

// /**
//  * @brief Modulo two Unsigned objects
//  * 
//  * @param right 
//  * 
//  * @return Unsigned&
//  */
// Unsigned &Unsigned::operator%=(const Unsigned &right){
//     Unsigned temp("0");

//     for (char bit : value)
//     {
//         temp.value += bit;
//         while (temp.value.size() > right.value.size() ||
//                (temp.value.size() == right.value.size() && temp.value >= right.value))
//         {
//             temp -= right;
//         }
//     }

//     value = temp.value;
//     return *this;
// }


// /**
//  * @brief Modulo two Unsigned objects
//  * 
//  * @param left 
//  * @param right 
//  * 
//  * @return Unsigned
//  */
// Unsigned operator%(Unsigned left, const Unsigned &right){
//     return left %= right;
// }


// /**
//  * @brief Output stream operator
//  * 
//  * @param os 
//  * @param number 
//  * 
//  * @return ostream&
//  */
// ostream &operator<<(ostream &os, const Unsigned &number){
//     os << number.to_base(Setbase::base);
//     return os;
// }


// /**
//  * @brief Increment the Unsigned object
//  * 
//  * @return Unsigned&
//  */
// Unsigned &Unsigned::operator++() {
//     *this += Unsigned("1");
//     return *this;
// }

// /**
//  * @brief Increment the Unsigned object
//  * 
//  * @param int
//  * 
//  * @return Unsigned
//  */
// Unsigned Unsigned::operator++(int) {
//     Unsigned temp = *this;
//     ++(*this);
//     return temp;
// }


// /**
//  * @brief Decrement the Unsigned object
//  * 
//  * @return Unsigned&
//  */
// Unsigned &Unsigned::operator--() {
//     *this -= Unsigned("1");
//     return *this;
// }


// /**
//  * @brief Decrement the Unsigned object
//  * 
//  * @param int
//  * 
//  * @return Unsigned
//  */
// Unsigned Unsigned::operator--(int) {
//     Unsigned temp = *this;
//     --(*this);
//     return temp;
// }