#include "pokemon.h"

string get_ofile() {
    cout << "what is the name of file?" << endl;
    string ofile;
    cin >> ofile;
    return ofile;
}


int file_or_print() {
    cout << "Would you like to output information in a file or in the terminal?" << endl;
    cout << "(press F for file, any other key for terminal)" << endl;
    string ans;
    cin >> ans;
    if (ans == "F") {
        return 1;
    }
    else {
        return 0;
    }
}


void print_poke(pokedex& ur_dex, ofstream& ofile, int num)  {
    cout << endl << "Index Number: " << ur_dex.pokes[num].dex << "       Name: " << ur_dex.pokes[num].name << endl;
    cout << "Type: " << ur_dex.pokes[num].type << "       Number of Moves: " << ur_dex.pokes[num].num_moves << endl;
    cout << "Moves: ";
    for (int m=0; m<ur_dex.pokes[num].num_moves; m++) {
        cout << ur_dex.pokes[num].moves[m];
        cout << "  ";
    }
    cout << endl;
}


void print_poke_file(pokedex& ur_dex, ofstream& ofile, int num) {
    ofile << endl << "Index Number: " << ur_dex.pokes[num].dex << "       Name: " << ur_dex.pokes[num].name << endl;
    ofile << "Type: " << ur_dex.pokes[num].type << "       Number of Moves: " << ur_dex.pokes[num].num_moves << endl;
    ofile << "Moves: ";
    for (int m=0; m<ur_dex.pokes[num].num_moves; m++) {
        ofile << ur_dex.pokes[num].moves[m];
        ofile << "  ";
    }
    ofile << endl;
}