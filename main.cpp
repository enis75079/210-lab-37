/*

lab37: hash table 1
COMSC-210
Naveen Islam

*/
#include <iostream>
#include <string>
using namespace std;

// function prototypes
int sum_ascii(string&);

int main() {
    // user input string
    string userString = "";
    cout << "Enter a string (no spaces): ";
    cin >> userString;
    cout << "Ascii sum of " << userString << " is: " << sum_ascii(userString) << endl; 
    return 0;
}

// sum_ascii function. receives a single string and returns the sum of that string's character's ASCII values
int sum_ascii(string& userInput) {
    int sum;
    // reads every character from the user's string and adds the ascii value to the sum
    for (char x : userInput) {
        sum += static_cast<int>(x);
    }
    return sum;
}