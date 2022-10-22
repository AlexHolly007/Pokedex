#include "pokemon.h"

void give_options(pokedex& ur_dex) {
    cout << endl << "What would you like to do?" << endl << "  (D) Search your pokedex by Pokemon dex number" << endl;
    cout << "  (N) Search your pokedex by name of Pokemon" << endl << "  (T) Search for Pokemon by type in your pokedex" << endl;
    cout << "  (A) Add a new Pokemon to your pokedex" << endl << "  (Q) Quit" << endl;
    string ans; cin >> ans;
    if (ans == "Q")  { }
    int output = file_or_print();
    ofstream ofile;
    if (output == 1){
        string get_outfile = get_ofile(); 
        ofile.open(get_outfile,ios::app);   }

    if (ans == "A") {
        add_new_pokemon(ur_dex, ofile);    }
    if (ans == "D") {
        search_by_dex(ur_dex, ofile, output);     }
    if (ans == "N")  {
        search_by_name(ur_dex, ofile, output);    }
    if (ans == "T")  {
        search_by_type(ur_dex, ofile, output);    } 
}


void search_by_dex(pokedex& ur_dex, ofstream& ofile, int call) {
    cout << "What index number would you like to search for? :  ";
    int dexi;cin >> dexi;
    for (int i=0; i<ur_dex.num_pokes; i++) {
        if (ur_dex.pokes[i].dex == dexi and call == 0) {
            cout << endl << "This pokemon had your searched dex number of " << dexi << endl << endl;
            print_poke(ur_dex, ofile, i);  }
        if (ur_dex.pokes[i].dex == dexi and call == 1)  {
            ofile << endl << "This pokemon has your searched dex number of " << dexi << endl << endl;
            print_poke_file(ur_dex, ofile, i);   }
    }
    if (call == 0) {
        cout << "------------------------------------------" << endl;   }
    else {
        ofile << "------------------------------------------" << endl;   }
    give_options(ur_dex);
}


void search_by_name(pokedex& ur_dex, ofstream& ofile, int call)  {
    cout << "What name of the Pokemon you would like to search for? :  ";
    string name;cin >> name;
    if (call == 0) {
        cout << endl << "Pokemon found by search of name: " << name << endl << endl;   }
    else {
        ofile << endl << "Pokemon found by search of name:" << name << endl << endl;   }
    for (int i=0; i<ur_dex.num_pokes; i++) {
        if (ur_dex.pokes[i].name == name && call == 0) {
            print_poke(ur_dex, ofile, i);   }
        if (ur_dex.pokes[i].name == name && call == 1) {
            print_poke_file(ur_dex, ofile, i);   }
    }
    if (call == 0) {
        cout << "------------------------------------------" << endl;   }
    else {
        ofile << "------------------------------------------" << endl;   }
    give_options(ur_dex);
}


void search_by_type(pokedex& ur_dex, ofstream& ofile, int call) {
    cout << "What is the type of Pokemon you would like to search for? :  ";
    string type; cin >> type;
    if (call == 0) {
        cout << endl << "Pokemon found with type : " << type << endl << endl;   }
    else {
        ofile << endl << "Pokemon found with type : " << type << endl << endl;   }
    for (int i=0; i<ur_dex.num_pokes; i++) {
        if (ur_dex.pokes[i].type == type && call == 0) {
            print_poke(ur_dex, ofile, i); }
        if (ur_dex.pokes[i].type == type && call == 1) {
            print_poke_file(ur_dex, ofile, i); }
    }
    if (call == 0) {
        cout << "------------------------------------------" << endl;   }
    else {
        ofile << "------------------------------------------" << endl;   }
    give_options(ur_dex);
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
    cout << "------------------------------------------" << endl;
    give_options(ur_dex);
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
    create_moves(ur_dex.pokes[ur_dex.num_pokes - 1].num_moves, ur_dex);
}


void create_moves(int num, pokedex& ur_dex) {
    ur_dex.pokes[ur_dex.num_pokes - 1].moves = new string[num];
    for (int i=0;i<num; i++){
        cout << "What is the name of move number " << (i+1) << "? :  ";
        cin >> ur_dex.pokes[ur_dex.num_pokes - 1].moves[i];
        cout << endl;     }
}