#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int current = 0;
    char inputstr[10], c;
    
    cout << "Enter string: ";
    cin >> inputstr;

    int i = 0;
    
    while (true) {
        c = inputstr[i]; 
        
        switch (current) {
            case 0: 
                if (c == '0') {
                    inputstr[i] = 'X';
                    i++;
                    current = 1;
                }
                else if (c == 'Y') {
                    i++;
                    current = 3;
                }
                else if (c == '\0') {
                    current = 4;
                }
                else {
                    current = -1;
                }
                break;
            
            case 1:
                if (c == '0') {
                    i++;
                    current = 1;
                }
                else if (c == 'Y') {
                    i++;
                    current = 1;
                }
                else if (c == '1') {
                    inputstr[i] = 'Y'; 
                    i--;
                    current = 2;
                }
                else {
                    current = -1;
                }
                break;
            
            case 2:
                if (c == '0') {
                    i--;
                    current = 2;
                }
                else if (c == 'Y') {
                    i--;
                    current = 2;
                }
                else if (c == 'X') {
                    i++;
                    current = 0;
                }
                else {
                    current = -1;
                }
                break;
            
            case 3:
                if (c == 'Y') {
                    i++;
                    current = 3;
                }
                else if (c == '\0') {
                    current = 4; 
                }
                else {
                    current = -1; 
                }
                break;
        }
        
        if (current == 4) {
            cout << "Accepted string" << endl;
            break;
        }
        
        if (current == -1) {
            cout << "Rejected string" << endl;
            break;
        }
    }
    
    return 0;
}