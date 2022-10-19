#include "pokemon.h"

void copy_file(ifstream& file, pokedex& ur_dex) {
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


void populate_moves(int num, pokedex& ur_dex) {
    ur_dex.pokes[ur_dex.num_pokes - 1].moves = new string[num];
    for (int i=0;i<num; i++){
        cout << "What is the name of move number " << (i+1) << "? :  ";
        cin >> ur_dex.pokes[ur_dex.num_pokes - 1].moves[i];
        cout << endl;
    }
}


void get_trainer_and_num(pokedex& ur_dex, ifstream& file){
    file >> ur_dex.num_pokes;
    cout << "Welcome trainer, what is your name?:  ";
    string name;
    cin >> name;
    cout << endl;
    ur_dex.trainer = name;

    cout << "Hi " << ur_dex.trainer << "! Those " << ur_dex.num_pokes << " pokemon have been registered to your pokedex!" << endl << endl;
}


void print_poke(pokedex& ur_dex, ofstream& ofile, int num) {
    cout << "Index Number: " << ur_dex.pokes[num].dex << "       Name: " << ur_dex.pokes[num].name << endl;
    cout << "Type: " << ur_dex.pokes[num].type << "       Number of Moves: " << ur_dex.pokes[num].num_moves << endl;
    cout << "Moves: ";
    for (int m=0; m<ur_dex.pokes[num].num_moves; m++) {
        cout << ur_dex.pokes[num].moves[m];
        cout << "  ";
    }
    cout << endl << endl;
    give_options(ur_dex, ofile);
}


void new_pokes_info(pokedex& ur_dex) {
    cout << "What is the index number for this Pokemon? :  ";
    cin >> ur_dex.pokes[ur_dex.num_pokes - 1].dex;
    cout << endl << "What is the name of this Pokemon?:  ";
    cin >> ur_dex.pokes[ur_dex.num_pokes - 1].name;
    cout << endl << "What is the type is this thing?:  ";
    cin >> ur_dex.pokes[ur_dex.num_pokes - 1].type;
    cout << endl << "How many moves does it have?:  ";
    cin >> ur_dex.pokes[ur_dex.num_pokes - 1].num_moves;
    populate_moves(ur_dex.pokes[ur_dex.num_pokes - 1].num_moves, ur_dex);
}


void add_new_pokemon(pokedex& ur_dex, ofstream& ofile)  {
    
    pokemon temp[ur_dex.num_pokes];
    for (int i=0; i<ur_dex.num_pokes; i++) {
        temp[i].dex = ur_dex.pokes[i].dex;
        temp[i].name = ur_dex.pokes[i].name;
        temp[i].type = ur_dex.pokes[i].type;
        temp[i].num_moves = ur_dex.pokes[i].num_moves;
        temp[i].moves = new string[temp[i].num_moves];
        for (int j=0; j<temp[i].num_moves; j++) {
                temp[i].moves[j] = ur_dex.pokes[i].moves[j];
        }
    }
    ur_dex.num_pokes = ur_dex.num_pokes + 1;
    ur_dex.pokes = new pokemon[ur_dex.num_pokes];
    for (int i=0; i<ur_dex.num_pokes-1; i++) {
        ur_dex.pokes[i].dex = temp[i].dex;
        ur_dex.pokes[i].name = temp[i].name;
        ur_dex.pokes[i].type = temp[i].type;
        ur_dex.pokes[i].num_moves = temp[i].num_moves;
        ur_dex.pokes[i].moves = new string[temp[i].num_moves];
        for (int j=0; j<temp[i].num_moves; j++) {
                ur_dex.pokes[i].moves[j] = temp[i].moves[j];
        }
    }
    new_pokes_info(ur_dex);
    cout << "Congrats, " << ur_dex.pokes[ur_dex.num_pokes - 1].name << " has been added to this pokedex!." << endl;
    print_poke(ur_dex, ofile,(ur_dex.num_pokes-1));
}


void search_by_dex(pokedex& ur_dex, ofstream& ofile) {
    cout << "What index number would you like to search for? :  ";
    int dexi;
    cin >> dexi;
    for (int i=0; i<ur_dex.num_pokes; i++) {
        if (ur_dex.pokes[i].dex == dexi) {
            cout << endl << endl << "This pokemon had your searched dex number of " << dexi << endl;
            print_poke(ur_dex, ofile, i);
        }
    }
}


void give_options(pokedex& ur_dex, ofstream& ofile) {
    cout << "What would you like to do?" << endl << "  (D) Search your pokedex by Pokemon dex number" << endl;
    cout << "  (N) Search your pokedex by name of Pokemon" << endl << "  (T) Search for Pokemon by type in your pokedex" << endl;
    cout << "  (A) Add a new Pokemon to your pokedex" << endl << "  (Q) Quit" << endl;
    string ans;
    cin >> ans;
    if (ans == "A") {
        add_new_pokemon(ur_dex, ofile);    }
    if (ans == "Q")  {
        exit; }
    if (ans == "D") {
        search_by_dex(ur_dex, ofile);     }
    if (ans == "N")  {
        
    }
    if (ans == "T")  {

    } 
}

int main() {
    ifstream file;
    string var_file;
    cout << "enter a file to use: ";
    cin >> var_file;
    file.open(var_file); 
    if (!file.is_open()) {
        cout << "uh oh, couldnt open that file" << endl; 
        main();  }
    
    ofstream ofile;
    ofile.open("output.txt",ios::app);

    pokedex ur_dex;

    get_trainer_and_num(ur_dex, file);
    ur_dex.pokes = new pokemon[ur_dex.num_pokes];

    copy_file(file, ur_dex);

    give_options(ur_dex, ofile);
}