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
  
