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
    return sum % 100;

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

// part_Three function. creates a hash table data structure. Displays the first 100 map entries from the text file
void part_Three() {
    // creates hash table, key is the integer and list string is the value that map to that specific hash index
    map<int, list<string>> hash_table;
    ifstream file("lab-37-data.txt");
    string txtLine;
    int dex = 0;
    int count = 0; 
    if (!file.is_open()) {
        cout << "Could not open file. Please try again." << endl;
        return;
    }

    // reads each line from the text file
    while (getline(file, txtLine)) {
        // assings the hash index for the current line from the text file and inserts the respective string into the hash table
        dex = gen_hash_index(txtLine);
        hash_table[dex].push_back(txtLine);
    }
    file.close();

    // display the hash table
    for (auto it = hash_table.begin(); it != hash_table.end(); ++it) {
        cout << "Index: " << it->first << endl;
        cout << "Entries: ";
        // displays all the strings that are associated with the current index
        for (const auto& entries : it->second) {
            cout << entries << " ";
        }
        cout << endl;
        count++;
        // max 100 entries
        if (count >= 100) {
            break;
        }
    }
}