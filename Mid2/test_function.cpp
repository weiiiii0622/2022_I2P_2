#include "function.h"
using namespace std;

Animal::Animal(string n, string s){
    name = n;
    species = s;
}

Animal::~Animal(){
    cout << name << "dead\n";
}

Animal::Animal(string n, string s, int hp){
    name = n;
    species = s;
    HP = hp;
}

int Animal::get_HP(){
    return HP;
}

void Animal::update_HP(int x){
    HP += x;
    return;
}

void Animal::turn_HP_into_zero(){
    HP = 0;
}

//Cat
Cat::Cat(string n): Animal(n, "cat"){
    HP = 10;
    cout << n << ' ' << "birth\n";
}
Cat::Cat(string n, int hp): Animal(n, "cat", hp){
    cout << n << ' ' << "birth\n";
}

void Cat::Talk(){
    cout << "Meow";
}

void Cat::Eat(Animal *animal){
    if(animal->name=="fish")
        update_HP(animal->get_HP());
}

void Cat::Eaten(Animal *animal){
    if(animal->name=="human")
}

void Cat::Killed(Animal *animal){
    
}
