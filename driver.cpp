/* Program-Pokedex Assignment 1
Author-Alex Holly
Date-Oct 23
Description- This program Is like a real pokedex. The user can enter a file in a specific format to bring in pokemon into the
system, then the user can search the system by type, name and dex number to find specific pokemon,
also the user can add pokemon to the pokedex system, these are added to the pokemon that are searched for
inputs- Name, input file with pokemon(more info in README), choices on what to search for/add pokemon, choice for output
outputs- printed text guiding the user. and output file is specified, the name out output can be choosen.
*/


#include "pokemon.h"

/*Description-This function starts the program off by creating the pokedex and pokemon structures. It copies the input
file information into the pokemon struct. Also it collects the users name. Then it sends this information
to the optins functions where the prgram will cycle through until it is told to quit
Inputs: input file, name
Outputs: pokedex, input file
*/
int main() {
    ifstream file;
    string var_file;
    cout << "enter a file to use: ";
    cin >> var_file;
    file.open(var_file); 
    if (!file.is_open()) {
        cout << "uh oh, couldnt open that file" << endl; 
        main();  }

    pokedex ur_dex;
    populate_pokedex_data(ur_dex, file);
    ur_dex.pokes = create_pokemons(ur_dex.num_pokes);
    
    populate_pokemon(file, ur_dex);

    give_options(ur_dex);
}
