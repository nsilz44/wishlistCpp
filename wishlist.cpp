#include <iostream>
#include <functional>
#include <fstream>
#include <string>

using namespace std;

#define LIST "list.txt"

void PrintOptions();
void PrintList(string filename);
void AddList(string item);
string Trim(string line);

int main () {
    PrintOptions();
    string option;
    string addingItem;
    ofstream outfile;
    getline(cin, option);
    if(option.size() > 1){
        char optionLetter = option[1];
        switch (optionLetter)
        {
        case 'v': case 'V':
            PrintList(LIST);
            break;
        case 'a': case 'A':
            addingItem = option.substr(2, option.length());
            addingItem = Trim(addingItem);
            cout << "\nadding " + addingItem + " to the list \n\n";
            outfile.open(LIST, std::ios_base::app); // append instead of overwrite
            outfile << '\n' << addingItem;
            outfile.close();
            PrintList(LIST);
            main();
        default:
            break;
        }
    }
}

// prints whole list
void PrintList(string filename){
    ifstream list(filename);
    // code to underline words in terminal
    const string UNDERLINE = "\x1B[4m";
    const string RESET = "\x1B[0m";
    cout << UNDERLINE + "Current wishlist" + RESET << '\n';
    if(list.is_open()){
        string tp;
        while (getline (list, tp)) {
    // Output the text from the file
        cout << tp << '\n';
        }
        cout << '\n';
        list.close();
    }
}

void PrintOptions(){
    cout << "To view current list type '-v'" << '\n';
    cout << "To add item type '-a [ITEM]'" << '\n';
    cout << "To delete item type '-v [ITEM]'" << '\n';
    cout << "To exit type 'exit'" << '\n';
}

string Trim(string line){
    const char* whitespace = " \t\n\r\f\v";
    line.erase(0, line.find_first_not_of(whitespace));
    line.erase(line.find_last_not_of(whitespace) + 1);
    return line;
}