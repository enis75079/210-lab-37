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
void part_Three(map<int, list<string>>&);

// for lab38
void first_100(const map<int, list<string>>&);
void keySearch();
void keyAdd(map<int, list<string>>&);
void keyRemove(map<int, list<string>>&);
void keyMod(map<int, list<string>>&);

int main() {
    // user input string
    /*string userString = "";
    cout << "Enter a string (no spaces): ";
    cin >> userString;
    cout << "Ascii sum of " << userString << " is: " << sum_ascii(userString) << endl; 
    return 0;*/

    // calls the part two function
    // part_Two();

    // calls the part three function
    // part_Three();

    map<int, list<string>> hash_table;
    part_Three(hash_table);
    int userChoice = 0;
    while (userChoice != 6) {
        cout << "[1] Print the first 100 entries" << endl;
        cout << "[2] Search for key" << endl;
        cout << "[3] Add a key" << endl;
        cout << "[4] Remove key" << endl;
        cout << "[5] Modify a key" << endl;
        cout << "[6] Exit" << endl;
        cout << "Choice: ";
        cin >> userChoice;
        if (userChoice == 1) {
            first_100(hash_table);
        } else if (userChoice == 2) {

        } else if (userChoice == 3) {
            keyAdd(hash_table);
        } else if (userChoice == 4) {
            keyRemove(hash_table);
        } else if (userChoice == 5) {
            keyMod(hash_table);
        } else if (userChoice == 6) {
            break;
        }
    }

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
void part_Three(map<int, list<string>>& userMap) {
    // creates hash table, key is the integer and list string is the value that map to that specific hash index
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
        userMap[dex].push_back(txtLine);
    }
    file.close();

    // display the hash table
    /*for (auto it = userMap.begin(); it != userMap.end(); ++it) {
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
    }*/
}

void first_100(const map<int, list<string>>& userMap) {
    int count = 0;
    for (auto it = userMap.begin(); it != userMap.end(); ++it) {
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
void keySearch();

void keyAdd(map<int, list<string>>& userMap) {
    int newKey = 0;
    string entry = "";
    cout << "Enter new key: ";
    cin >> newKey;
    cout << "\nEnter value for that key: ";
    cin >> entry;

    userMap[newKey].push_back(entry);
    cout << "Added new key." << endl;
}

void keyRemove(map<int, list<string>>& userMap) {
    int removedKey = 0;
    cout << "Enter key to remove: ";
    cin >> removedKey;

    if (userMap.erase(removedKey)) {
        cout << "Key: " << removedKey << " removed." << endl;
    } else {
        cout << "Key: " << removedKey << " does not exist." << endl;
    }
}
void keyMod(map<int, list<string>>& userMap) {
    int modKey = 0;
    string newVal = "";
    cout << "Enter key to modify: ";
    cin >> modKey;

    auto it = userMap.find(modKey);
    if (it != userMap.end()) {
        cout << "enter new value to this key: ";
        cin >> newVal;
        it->second.push_back(newVal);
        cout << "\nModification complete." << endl;
    } else {
        cout << "Key not found" << endl;
    }
}