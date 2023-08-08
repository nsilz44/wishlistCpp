#include <iostream>
#include <functional>
#include <fstream>
#include <string>

using namespace std;

#define LIST "list.txt"

void PrintOptions();
void PrintList(string filename);
void AddList(string item);
void DeleteList(string item);
string Trim(string line);

const char* whitespace = " \t\n\r\f\v";

int main () {
    PrintOptions();
    string option;
    string addingItem;
    string deleteItem;

    getline(cin, option);
    if(option.size() > 1){
        char optionLetter = option[1];
        switch (optionLetter)
        {
        case 'v': case 'V':
            PrintList(LIST);
            main();
            break;
        case 'a': case 'A':
            addingItem = option.substr(2, option.length());
            addingItem = Trim(addingItem);
            AddList(addingItem);
            PrintList(LIST);
            main();
            break;
        case 'd': case 'D':
            deleteItem = option.substr(2, option.length());
            deleteItem = Trim(deleteItem);
            DeleteList(deleteItem);
            PrintList(LIST);
            main();
            break;
        case 'x': case 'X':
            cout << "list saved and exiting"<< '\n';
            break;
        default:
            break;
        }
    }
    return 0 ;
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
    cout << "To delete item type '-d [ITEM]'" << '\n';
    cout << "To exit type 'exit'" << '\n';
}

string Trim(string line){
    
    line.erase(0, line.find_first_not_of(whitespace));
    line.erase(line.find_last_not_of(whitespace) + 1);
    return line;
}
void AddList(string item){
    ofstream outfile;
    cout << "\nadding " + item + " to the list \n\n";
    outfile.open(LIST, ios_base::app); // append instead of overwrite
    outfile << '\n' << item;
    outfile.close();
}
void DeleteList(string item){
    bool found = false;
    ifstream list(LIST);
    ofstream temp;
    temp.open("temp.txt",ios_base::trunc);
    cout << item << '\n';
    if(list.is_open()){
        string line;
        while (getline(list, line)) {
            // checks delete item is in line and line isnt empty
            if (line != item && !(line.empty())){
                temp << line + '\n';
            }
            else {
                found = true;
            }
        }
        list.close();
    temp.close();
    unlink(LIST);
    rename("temp.txt",LIST);
    }
}