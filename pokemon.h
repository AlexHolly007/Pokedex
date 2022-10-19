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


struct pokedex {
    string trainer;
    int num_pokes;
    pokemon* pokes;
};

void copy_file(ifstream& file, pokedex& ur_dex);
void get_trainer_and_num(pokedex& ur_dex, ifstream& file);
int main();
void populate_moves(int num, pokedex& ur_dex);
void print_poke(pokedex& ur_dex, ofstream& ofile, int num, ifstream& file);
void new_pokes_info(pokedex& ur_dex);
void add_new_pokemon(pokedex& ur_dex, ofstream& ofile, ifstream& file);
void give_options(pokedex& ur_dex, ifstream& file, ofstream& ofile);