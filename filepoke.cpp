#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
using namespace std;

struct pokemon {
    int dex;
    string name;
    string type;
    int num_moves;
    string* moves;
};

void copy_file(ifstream& file, int num_pokes) {
    while (file.is_open()){
        int dex_num;
        string pok_name;
        string pok_type;
        int num_moves;
        file >> dex_num >> pok_name >> pok_type >> num_moves;
        for (int i=0; i<num_moves; i++) {
            string* moves = new string[num_moves];
            file >> moves[i];      }
    }
}

int main() {
    string var_file;
    cout << "enter a file to use: ";
    cin >> var_file;
    ifstream file;
    file.open("text.txt");

    if (!file.is_open()) {
        cout << "uh oh, couldnt open that file";
        }
    // while loop

    int num_pokes;
    file >> num_pokes;

    copy_file(file, num_pokes);

}