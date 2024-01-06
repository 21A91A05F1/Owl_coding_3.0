#include <iostream>
using namespace std;

int findMSBPosition(int n) {
    int msbPos = 0;
    while (n > 0) {
        msbPos++;
        n = n >> 1;
    }
    return msbPos;
}

int main() {
    int number = 3;  // Change this number to find its MSB position
    int result = findMSBPosition(number);
    cout << "The position of the most significant set bit in " << number << " is: " << result << endl;
    return 0;
}
