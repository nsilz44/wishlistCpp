#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define LIST "list.txt"

void PrintOptions();
void PrintList(string filename);
void AddList(string item);

int main () {
    PrintList(LIST);
    PrintOptions();
    string option;
    string optionP;
    cin >> option;
    cout << '\n';
    //optionP = &option;
    if(option.size() > 1){
        char optionLetter = option[1];
        switch (optionLetter)
        {
        case 'v': case 'V':
            PrintList(LIST);
            break;
        case 'a': case 'A':
            optionP = option.substr(2, option.length());
            cout << optionP << '\n';
        default:
            break;
        }
    }
}

// prints whole list
void PrintList(string filename){
    ifstream list(filename);
    cout << "current wishlist" << '\n';
    if(list.is_open()){
        string tp;
        while (getline (list, tp)) {
    // Output the text from the file
        cout << tp << '\n';
  }
        list.close();
    }
}

void PrintOptions(){
    cout << "To view current list type '-v'" << '\n';
    cout << "To add item type '-a [ITEM]'" << '\n';
    cout << "To delete item type '-v [ITEM]'" << '\n';
    cout << "To exit type 'exit'" << '\n';
}