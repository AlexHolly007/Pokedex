#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
struct pokemon {
    int num;
    string name;
    int num_moves;
    string *moves;
};

struct pokedex {
    string trainer;
    int num_pokes;
    pokemon* dex;
};


string* create_moves(int size){
    string* p = new string[size];
    return p;
}


void print_pokemon(pokemon& mine, int moves) {
    cout << mine.num << " " << mine.name << " " << mine.num_moves << endl;
    for (int i=0; i<moves; i++) {
        cout << mine.moves[i] << " ";
    }
}


void populate_moves(string* moves, int num) {
    for (int i=0;i<num; i++){
        string name;
        cout << "What is the name of this move? :  " << endl;
        cin >> name;
        moves[i] = name;
    }
}

void test_func(pokedex& alex) {
    alex.dex[0].num = 2;
}


int main() {
    pokedex alex;
    alex.dex = new pokemon[3];
    alex.dex[0].num = 1;
    alex.dex[0].name = "bulbysaur";
    alex.dex[0].num_moves = 2;
    alex.dex[0].moves = create_moves(alex.dex[0].num_moves);
    populate_moves(alex.dex[0].moves, alex.dex[0].num_moves);

    print_pokemon(alex.dex[0], alex.dex[0].num_moves);

    test_func(alex);
    print_pokemon(alex.dex[0], alex.dex[0].num_moves);
    return 1;
}