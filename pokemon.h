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

/* Create_dex_functions.cpp
These functions are what start the program, they are all in the main function, these create and populate the pokedex and the 
pokemons from the input file.
--------------------------------------------------------*/
int main();
void populate_pokemon(ifstream& file, pokedex& ur_dex);
pokemon* create_pokemons(int size);
void populate_pokedex_data(pokedex& ur_dex, ifstream& file);
/*--------------------------------------------------------*/


/* Option_functions.cpp
These functions are what are called when the program is asking for the input of what they want to do. 
It also include the functions that take these answers and are used to do their task*/
void give_options(pokedex& ur_dex);
string get_answer();
void options_2(string ans, pokedex& ur_dex, ofstream& ofile, int output);
void search_by_dex(pokedex& ur_dex, ofstream& ofile, int call);
void search_by_name(pokedex& ur_dex, ofstream& ofile, int call);
void search_by_type(pokedex& ur_dex, ofstream& ofile, int call);
void add_new_pokemon(pokedex& ur_dex, ofstream& ofile);
void new_pokes_info(pokedex& ur_dex);
void create_moves(int num, pokedex& ur_dex);
void delete_info(pokemon* pokes, int size);
/*-----------------------------------------------*/



/*Output_functions.cpp
These functions are used to see if the user wants to output the result in a file, then
it will collect the name of that file and print the output, also will print output in terminal */
string get_ofile();
int file_or_print();
void print_poke(pokedex& ur_dex, ofstream& ofile, int num);
void print_poke_file(pokedex& ur_dex, ofstream& ofile, int num);
/*---------------------------------------------------------------*/