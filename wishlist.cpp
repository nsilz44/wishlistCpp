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
}

// prints whole list
void PrintList(string filename){
    ifstream list(filename);
    if(list.is_open()){
        string tp;
        cout << tp << "\n";
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