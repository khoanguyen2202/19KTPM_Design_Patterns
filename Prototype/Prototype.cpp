// Prototype.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Marine {
private:
    string m_name;
public: 
    Marine(string name) {
        m_name = name;
    }
    virtual Marine* clone() const = 0;
     
    Marine(const Marine &copy) {
        m_name = copy.m_name;
    }
    void PrintName() {
        cout << m_name << '\n';
    }
};

class Octopus : public Marine {
public:
    Octopus() : Marine("octopus") {
    }
    Octopus(const Octopus& copy) : Marine(copy) {
    }
    Marine* clone() const override {
        return new Octopus(*this);
    }
};

class Dog : public Marine {
public:
    Dog() : Marine("Dog") {
        cout << "dog";
    }
    Dog(const Dog& copy) : Marine(copy) {
    }
    Marine* clone() const override {
        return new Dog(*this);
    }
};

int main()
{
    Octopus* marine = new Octopus();

    vector<Marine*> v;

    v.push_back(marine->clone());
    v.push_back((new Dog())->clone());

    for (Marine* i : v) {
        i->PrintName();
    }

    delete marine;
}

