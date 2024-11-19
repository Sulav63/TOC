#include <iostream>
#include <string>
using namespace std;

// Function to check if the string is accepted by the PDA
bool isAccepted(const string& input) {
    int count0 = 0;  // Counter for `0`s
    int count1 = 0;  // Counter for `1`s

    // Process each character in the input string
    for (int i = 0; i < input.length(); i++) {
        char c = input[i];
        if (c == '0') {
            count0++; // Increment the count for `0`
        } else if (c == '1') {
            count1++; // Increment the count for `1`
        } else {
            // Invalid character (not a `0` or `1`)
            return false;
        }
    }

    // Accept if the number of `0`s and `1`s are equal
    return count0 == count1;
}

int main() {
    string input;

    // Get binary string input
    cout << "Enter a binary string: ";
    cin >> input;

    // Validate input contains only `0` or `1`
    for (int i = 0; i < input.length(); i++) {
        if (input[i] != '0' && input[i] != '1') {
            cout << "Invalid input! Only strings with 0s and 1s are allowed." << endl;
            return 0;
        }
    }

    // Check if the string is accepted or rejected
    if (isAccepted(input)) {
        cout << "The string is ACCEPTED (equal number of 0's and 1's)." << endl;
    } else {
        cout << "The string is REJECTED (not equal number of 0's and 1's)." << endl;
    }

    return 0;
}

