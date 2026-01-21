#include <iostream>

using namespace std;

int main() {
    int num, reversed = 0, remainder, original;

    cout << "Enter an integer: ";
    cin >> num;

    original = num;

    // Reverse the number
    while (num != 0) {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num /= 10;
    }

    // Check if the reversed number is equal to the original number
    if (original == reversed) {
        cout << original << " is a palindrome." << endl;
    } else {
        cout << original << " is not a palindrome." << endl;
    }

    return 0;
}
