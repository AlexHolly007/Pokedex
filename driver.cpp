#include "pokemon.h"

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