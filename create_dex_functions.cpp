#include "pokemon.h"

void populate_pokemon(ifstream& file, pokedex& ur_dex) {
    for (int po=0; po<ur_dex.num_pokes; po++) {
        int dex_num;
        string pok_name;
        string pok_type;
        int num_moves;
        file >> dex_num >> pok_name >> pok_type >> num_moves;
        ur_dex.pokes[po].dex = dex_num;
        ur_dex.pokes[po].name = pok_name;
        ur_dex.pokes[po].type = pok_type;
        ur_dex.pokes[po].num_moves = num_moves;
        ur_dex.pokes[po].moves = new string[num_moves];
        for (int i=0; i<num_moves; i++) { 
            file >> ur_dex.pokes[po].moves[i];      }
    }

}


void populate_pokedex_data(pokedex& ur_dex, ifstream& file){
    file >> ur_dex.num_pokes;
    cout << "Welcome trainer, what is your name?:  ";
    string name;
    cin >> name;
    cout << endl;
    ur_dex.trainer = name;
    cout << "Hi " << ur_dex.trainer << "! Those " << ur_dex.num_pokes << " pokemon have been registered to your pokedex!" << endl << endl;
    
}


pokemon* create_pokemons(int size) {
    return new pokemon[size];
}