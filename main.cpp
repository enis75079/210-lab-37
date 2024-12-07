/*

lab37: hash table 1
COMSC-210
Naveen Islam

*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// function prototypes
int sum_ascii(const string&);
void part_Two();

int main() {
    // user input string
    /*string userString = "";
    cout << "Enter a string (no spaces): ";
    cin >> userString;
    cout << "Ascii sum of " << userString << " is: " << sum_ascii(userString) << endl; 
    return 0;*/

    // calls the part two function
    part_Two();

}

// sum_ascii function. receives a single string and returns the sum of that string's character's ASCII values
int sum_ascii(const string& userInput) {
    int sum = 0;
    // reads every character from the user's string and adds the ascii value to the sum
    for (char x : userInput) {
        sum += static_cast<int>(x);
    }
    return sum;

}

// part two function. reads the lab-37-data.txt file and totals the ascii value of all the strings
void part_Two() {
    ifstream file("lab-37-data.txt");
    string txtLine;
    long long total = 0;
    if (!file.is_open()) {
        cout << "Could not open file. Please try again." << endl;
        return;
    }

    while (getline(file, txtLine)) {
        total += sum_ascii(txtLine);
    }
    file.close();
    cout << "Total of lab-37-data.txt ASCII values: " << total << endl;
}