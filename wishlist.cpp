#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define LIST "list.txt"

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

int main () {
    PrintList(LIST);
}