#include "pokemon.h"


/* This function takes the file that was inputed and the pokedex. It goes through the file and
copies the pokemon information if the structure, the completed structure is returned*/
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

/* this function takes the empty pokedex and collects the users name. Also it takes the file first number, and inputs
this into the dex as the number of pokes*/
void populate_pokedex_data(pokedex& ur_dex, ifstream& file){
    file >> ur_dex.num_pokes;
    cout << "Welcome trainer, what is your name?:  ";
    string name;
    cin >> name;
    cout << endl;
    ur_dex.trainer = name;
    cout << "Hi " << ur_dex.trainer << "! Those " << ur_dex.num_pokes << " pokemon have been registered to your pokedex!" << endl << endl;
    
}

/*creates pokemon structure array size of inputed number from the file.*/
pokemon* create_pokemons(int size) {
    return new pokemon[size];
}