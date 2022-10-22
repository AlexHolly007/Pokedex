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

int main();
void populate_pokemon(ifstream& file, pokedex& ur_dex);
pokemon* create_pokemons(int size);
void populate_pokedex_data(pokedex& ur_dex, ifstream& file);

void give_options(pokedex& ur_dex);
void search_by_dex(pokedex& ur_dex, ofstream& ofile, int call);
void search_by_name(pokedex& ur_dex, ofstream& ofile, int call);
void search_by_type(pokedex& ur_dex, ofstream& ofile, int call);
void add_new_pokemon(pokedex& ur_dex, ofstream& ofile);
void new_pokes_info(pokedex& ur_dex);
void create_moves(int num, pokedex& ur_dex);

string get_ofile();
int file_or_print();
void print_poke(pokedex& ur_dex, ofstream& ofile, int num);
void print_poke_file(pokedex& ur_dex, ofstream& ofile, int num);