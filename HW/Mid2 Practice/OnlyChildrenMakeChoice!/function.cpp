#include "function.h"
using namespace std;

//Animal
Animal::Animal(Zoo *zoo, string name): belong(zoo), species(name){
    if (this->belong != NULL)
        this->belong->born(this->species);   
};

//Dog
Dog::Dog(Zoo *zoo): Animal::Animal(zoo, "Dog"){};

Dog::~Dog(){};

//Cat
Cat::Cat(Zoo *zoo): Animal::Animal(zoo, "Cat"){};

Cat::~Cat(){};

//Caog
Caog::Caog(Zoo *zoo): Dog::Dog(zoo), Cat::Cat(zoo), Animal::Animal(zoo, "Caog"){};

Caog::~Caog(){};

void Caog::barking(){
    cout << "woof!woof!meow!\n";
}

void Caog::carton(){
    cout << "it looks so happy!\n";
}

void Caog::throwBall(){
    cout << "it looks happy!\n";
}