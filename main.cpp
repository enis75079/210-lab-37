/*

lab37: hash table 1
COMSC-210
Naveen Islam

*/
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>
using namespace std;

// function prototypes
int gen_hash_index(const string&);
void part_Two();
void part_Three();

int main() {
    // user input string
    /*string userString = "";
    cout << "Enter a string (no spaces): ";
    cin >> userString;
    cout << "Ascii sum of " << userString << " is: " << sum_ascii(userString) << endl; 
    return 0;*/

    // calls the part two function
    // part_Two();

    part_Three();

}

// sum_ascii function. receives a single string and returns the sum of that string's character's ASCII values
int gen_hash_index(const string& userInput) {
    int sum = 0;
    // reads every character from the user's string and adds the ascii value to the sum
    for (char x : userInput) {
        sum += static_cast<int>(x);
    }
    return sum;

}

// part two function. reads the lab-37-data.txt file and totals the ascii value of all the strings
void part_Two() {
    // reads text file
    ifstream file("lab-37-data.txt");
    string txtLine;
    int total = 0;
    if (!file.is_open()) {
        cout << "Could not open file. Please try again." << endl;
        return;
    }

    // reads each line in the text file and calls the sum_ascii function for each line
    while (getline(file, txtLine)) {
        total += gen_hash_index(txtLine);
    }
    file.close();
    cout << "Total of lab-37-data.txt ASCII values: " << total << endl;
}

void part_Three() {
    map<int, list<string>> hash_table;
    ifstream file("lab-37-data.txt");
    string txtLine;
    int dex = 0;
    int count = 0; 
    if (!file.is_open()) {
        cout << "Could not open file. Please try again." << endl;
        return;
    }

    while (getline(file, txtLine)) {
        int dex = gen_hash_index(txtLine);
        hash_table[dex].push_back(txtLine);
    }
    file.close();

    for (const auto& [index, entries] : hash_table) {
        for (const auto& enter : entries) {
            cout << enter << " ";
        }
        cout << endl;
        if 
    }
}