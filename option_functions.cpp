#include "pokemon.h"
/*this is the function that is looped through after the completion of a task. After a result is printed to 
its output, it calls this function to reget an asnwer for another prompt. Insiide the function, it asks for
the answer of what the user wants to do, then it asks if they want to output in a file or terminal. A file is collected if
the user wants. This information is sent to the next function to call each task
inputs- the answer of the user, the file to be outputted to
outputs, file, the dex, answer of what to do*/
void give_options(pokedex& ur_dex) {
    cout << endl << "What would you like to do?" << endl << "  (D) Search your pokedex by Pokemon dex number" << endl;
    cout << "  (N) Search your pokedex by name of Pokemon" << endl << "  (T) Search for Pokemon by type in your pokedex" << endl;
    cout << "  (A) Add a new Pokemon to your pokedex" << endl << "  (Q) Quit" << endl;
    string ans = get_answer();
    if (ans == "Q")  {
        delete_info(ur_dex.pokes, ur_dex.num_pokes);
    }
    int output = 0;
    if (ans != "Q" || ans != "A") {
    output = file_or_print(); }
    ofstream ofile;
    if (output == 1){
        string get_outfile = get_ofile(); 
        ofile.open(get_outfile,ios::app);   }
    options_2(ans, ur_dex, ofile, output);
}

/* Description, this function send the information from the function above to the respective task individually*/
void options_2(string ans, pokedex& ur_dex, ofstream& ofile, int output)  {
    if (ans == "A") {
        add_new_pokemon(ur_dex, ofile);    }
    if (ans == "D") {
        search_by_dex(ur_dex, ofile, output);     }
    if (ans == "N")  {
        search_by_name(ur_dex, ofile, output);    }
    if (ans == "T")  {
        search_by_type(ur_dex, ofile, output);    } 
}

/* while loop that grabs the answer, if its not a valid answer, is restarted
inputs- answer
outputs- answer*/
string get_answer() {
    int check = 0;
    while (check == 0) {
        string ans;
        cin >> ans;
        if (ans == "Q" || ans == "A" || ans == "T" || ans == "D" || ans == "N"){ 
            check = 1;
            return ans;
        }
        cout << "That was not a valid answer, please enter another answer:  ";
    }
}

/* Description- ask for the index number to search for. The structure is searched through for a pokemon that matches
the same number, this pokemon is sent to the print function*/
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

/* Description- Inputs the name that is being searched for, after checking the pokedex, the pokemon is printed out 
into the file or terminal.*/
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

/*Description- same as two functions above with type*/
void search_by_type(pokedex& ur_dex, ofstream& ofile, int call) {
    cout << "What is the type of Pokemon you would like to search for? :  ";
    string type; cin >> type;
    if (call == 0) {
        cout << endl << "Pokemon found with type : " << type << endl;   }
    else {
        ofile << endl << "Pokemon found with type : " << type << endl;   }
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

/* This function adds a new pokemon, This is done by saving the old pokedex pokemon inforamtion to
a temporary pokemon structure. Then a new array in the pokedex in created one size larger. The temporary pokemons information
in transfered to this new array with 1 extra slot. A function is called to fill this new slots information

This needs to be extra lines because the temporary pokemon structure cannot be sent through the function.
 */
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
    delete_info(ur_dex.pokes, ur_dex.num_pokes);
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
        delete [] temp[i].moves;
        }
    }
    new_pokes_info(ur_dex);
    cout << "Congrats, " << ur_dex.pokes[ur_dex.num_pokes - 1].name << " has been added to this pokedex!." << endl;
    print_poke(ur_dex, ofile,(ur_dex.num_pokes-1));
    cout << "------------------------------------------" << endl;
    give_options(ur_dex);
}


/* This function takes the input of the user for all the information and fills in the last spot
within the pokedex pokemon structure.*/
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

/* This is used to create the moves for new pokes information in the function above*/
void create_moves(int num, pokedex& ur_dex) {
    ur_dex.pokes[ur_dex.num_pokes - 1].moves = new string[num];
    for (int i=0;i<num; i++){
        cout << "What is the name of move number " << (i+1) << "? :  ";
        cin >> ur_dex.pokes[ur_dex.num_pokes - 1].moves[i];
        cout << endl;     }
}

/* this deletes the heap memory that was created*/
void delete_info(pokemon* pokes, int size)  {
    for (int i=0; i<size; i++) {
        delete [] pokes[i].moves;
        pokes[i].moves = NULL;
    }
    delete [] pokes;
    pokes = NULL;
}
