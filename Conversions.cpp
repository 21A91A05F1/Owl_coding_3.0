                                                    Binary to Decimal
======================================================================================================================================
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int binaryToDecimal(string binary) {
    int decimal = 0;
    int power = 0;
    for (int i = binary.length() - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }
    return decimal;
}

                                                              2. Decimal to Binary
======================================================================================================================================
    #include <iostream>
#include <string>
using namespace std;

string decimalToBinary(int decimal) {
    string binary = "";
    while (decimal > 0) {
        binary = to_string(decimal % 2) + binary;
        decimal /= 2;
    }
    return binary;
}

Input: 11 (decimal)
Process: Repeatedly divide the decimal number by 2 and prepend the remainder (0 or 1) to the result string.
11 % 2 = 1, quotient = 5
5 % 2 = 1, quotient = 2
2 % 2 = 0, quotient = 1
1 % 2 = 1, quotient = 0

=================================================3. Binary to Octal===============================================================
  
Step1:Binary to decimal
Step2:Decimal to octal

int binaryToDecimal(string binary) {
    int decimal = 0;
    int power = 0;
    for (int i = binary.length() - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }
    return decimal;
}

string decimalToOctal(int decimal) {
    string octal = "";
    while (decimal > 0) {
        octal = to_string(decimal % 8) + octal;
        decimal /= 8;
    }
    return decimal;
}
============================================================4.Octal to binary=========================================================
Convert each octal digit to its binary equivalent using direct mapping.
Concatenate the binary equivalents to form the final binary string.

  string octalToBinary(const string& octal) {
    string binary = "";
    const string binaryTable[] = {"000", "001", "010", "011", "100", "101", "110", "111"};
    
    for (char digit : octal) {
        // Append the corresponding binary string for each octal digit
        binary += binaryTable[digit - '0'];
    }
    return binary;
}
====================================================5.Binary to Hexadecimal===============================================
