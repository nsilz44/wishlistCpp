#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define LIST "list.txt"

void PrintOptions();
void PrintList(string filename);

int main () {
    PrintList(LIST);
    PrintOptions();
    string option;
    cin >> option;
    cout << '\n';
    if(option.size() > 1){
        char optionLetter = option[1];
        switch (optionLetter)
        {
        case 'v': case 'V':
            PrintList(LIST);
            break;
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
}