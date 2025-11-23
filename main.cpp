#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream> 
using namespace std;

const string DEFAULT_NAME = "nameHere";
const int DEFAULT_HEALTH = 50;
const int DEFAULT_STRENGTH = 50;

class Creature {
public:
    
    Creature() {

        setCreature(DEFAULT_NAME, DEFAULT_HEALTH, DEFAULT_STRENGTH);

    }
    Creature(string name) {

        setCreature(name, health, strength);

    }
    Creature(int health, int strength) {

        setCreature(name, health, strength);

    }
    Creature(string name, int health, int strength) {

        setCreature(name, health, strength);

    }
    Creature(const Creature& copyFromThisCreature) {

        setCreature(copyFromThisCreature.name, copyFromThisCreature.health, copyFromThisCreature.strength);

    }
    ~Creature() {

        setCreature(DEFAULT_NAME, DEFAULT_HEALTH, DEFAULT_STRENGTH);

    }

    const string getName() {

        return name;

    }
    const int getHealth() {

        return health;

    }
    const int getStrength() {

        return strength;

    }
    virtual const int getDamage() {

        return (rand() % strength) + 1;

    }

    void setCreature(string newName, int newHealth, int newStrength);
    virtual string toString();

private:

    string name = DEFAULT_NAME;
    int health = DEFAULT_HEALTH;
    int strength = DEFAULT_STRENGTH;

};
class CreatureExeption {

public:
    CreatureExeption() {
        message = "UNKNOWN ERROR";
    }
    CreatureExeption(int value) {
        message = value;
    }
    CreatureExeption(string value) {
        message = value;
    }
    string what() {
        return message;
    }
private:

    string message = "";

};

class Elf : public Creature {
public:

    Elf() {

        setCreature(DEFAULT_NAME, DEFAULT_HEALTH, DEFAULT_STRENGTH);

    }
    Elf(string name) {

        setCreature(name, getHealth(), getStrength());

    }
    Elf(int health, int strength) {

        setCreature(getName(), health, strength);

    }
    Elf(string name, int health, int strength) {

        setCreature(name, health, strength);

    }
    Elf(Creature& copyFromThisCreature) {

        setCreature(copyFromThisCreature.getName(), copyFromThisCreature.getHealth(), copyFromThisCreature.getStrength());

    }
    ~Elf() {

        setCreature(DEFAULT_NAME, DEFAULT_HEALTH, DEFAULT_STRENGTH);

    }
    string toString();

    const int getDamage() {

        int damage = Creature::getDamage();
        if ((rand() % 20) == 0) {
            damage = damage * 2;
            cout << "Elve" << endl;
        }
        return damage;

    }

};
class Demon : public Creature{
public:

    Demon() {

        setCreature(DEFAULT_NAME, DEFAULT_HEALTH, DEFAULT_STRENGTH);

    }
    Demon(string name) {

        setCreature(name, getHealth(), getStrength());

    }
    Demon(int health, int strength) {

        setCreature(getName(), health, strength);

    }
    Demon(string name, int health, int strength) {

        setCreature(name, health, strength);

    }
    Demon(Creature& copyFromThisCreature) {

        setCreature(copyFromThisCreature.getName(), copyFromThisCreature.getHealth(), copyFromThisCreature.getStrength());

    }
    ~Demon() {

        setCreature(DEFAULT_NAME, DEFAULT_HEALTH, DEFAULT_STRENGTH);

    }

    string toString();

    const int getDamage() {

        int damage = Creature::getDamage();
        if ((rand() % 100) < 15) {
            damage = damage + 50;
            cout << "Demon" << endl;
        }
        return damage;

    }

};
class Superdemon : public Demon {
public:

    Superdemon() {

        setCreature(DEFAULT_NAME, DEFAULT_HEALTH, DEFAULT_STRENGTH);

    }
    Superdemon(string name) {

        setCreature(name, getHealth(), getStrength());

    }
    Superdemon(int health, int strength) {

        setCreature(getName(), health, strength);

    }
    Superdemon(string name, int health, int strength) {

        setCreature(name, health, strength);

    }
    Superdemon(Creature& copyFromThisCreature) {

        setCreature(copyFromThisCreature.getName(), copyFromThisCreature.getHealth(), copyFromThisCreature.getStrength());

    }
    ~Superdemon() {

        setCreature(DEFAULT_NAME, DEFAULT_HEALTH, DEFAULT_STRENGTH);

    }

    string toString();

    const int getDamage() {

        int damage = Creature::getDamage();
        damage = damage * 2;
        cout << "SuperDemon" << endl;
        return damage;

    }

};

class Army {
public:

    Army() {

        pCreature = { nullptr };

    }
    Army(int newSize);

    void printList();
    Creature** getList() {

        return pCreature;

    }

private:

    Creature** pCreature = nullptr;
    int size = 0;

};

void defaultMenuOption();
void deAllocateMemory(Creature** array);
void listfunction();

int main()
{

    int userInput = 0;
    enum {

        DEMO = 1,
        QUIT

    };

    while (userInput != QUIT) {

        cout << "\n\nMenu:\n"
            << "1. Print table based off input\n"
            << "2. Exit\n"
            << "\nInput: ";

        cin >> userInput;

        switch (userInput) {
        case DEMO:
            listfunction();
            break;
        case QUIT:
            break;
        default:
            defaultMenuOption();
            break;
        }
    }

    return 0;
}

void Creature::setCreature(string newName, int newHealth, int newStrength) {

    int index = 0;
    int nameSize = 0;
    try {

        while (newName[index] != '@' && index < newName.size()) {

            if ((newName[index] >= '0' && newName[index] <= '9') || (newName[index] >= 'A' && newName[index] <= 'Z') || (newName[index] >= 'a' && newName[index] <= 'z')) {

                nameSize++;
            }
            index++;
        }

        if (nameSize < 3) {

            throw CreatureExeption(newName);

        }

        if (newHealth < 0) {

            throw CreatureExeption(newHealth);

        }

        if (newStrength < 0) {

            throw CreatureExeption(newStrength);

        }

        name = newName;
        health = newHealth;
        strength = newStrength;

    }
    catch (CreatureExeption ex) {

        cout << ex.what() << endl;

    }
    catch (...) {

        cout << "UNKNOWN ERROR..." << endl;

    }

};
string Creature::toString() {

    stringstream ss;
    ss << left << setw(10) << name << right << setw(10) << setfill('_') << health << setw(12) << strength;
    return ss.str();

}

string Elf::toString() {

    stringstream ss;
    ss << left << setw(40) << setfill('_') << Creature::toString() << setw(15) << setfill('_') << "Elf";
    return ss.str();

}
string Demon::toString() {

    stringstream ss;
    ss << left << setw(40) << setfill('_') << Creature::toString() << setw(15) << setfill('_') << "Demon";
    return ss.str();

}
string Superdemon::toString() {

    stringstream ss;
    ss << left << setw(40) << setfill('_') << Creature::toString() << setw(15) << setfill('_') << "Superdemon";
    return ss.str();

}

Army::Army(int newSize) {

    size = newSize;
    int creature = 0;
    int health = 0;
    int strength = 0;
    pCreature = new Creature * [size] {nullptr};
    
    for (int i = 0; i < size; ++i) {

        creature = rand() % 3;
        health = 30 + (rand() % (90 - 30 + 1));
        strength = 30 + (rand() % (90 - 30 + 1));

        if (creature == 0) {

            pCreature[i] = new Elf("Creature" + to_string(i + 1), health, strength);

        }
        else if (creature == 1) {

            pCreature[i] = new Demon("Creature" + to_string(i + 1), health, strength);

        }
        else if (creature == 2) {

            pCreature[i] = new Superdemon("Creature" + to_string(i + 1), health, strength);

        }
    
    }

};
void Army::printList() {

    cout << left << setw(14) 
        << "Name" << setw(10) 
        << "Health" << setw(16) 
        << "Strength" << setw(15) 
        << "Type" << setw(1) << setfill('_') << "\n"
        << "" << right << setw(55) << setfill('=') << "" << endl;

    for (int i = 0; i < size; ++i) {

        cout << pCreature[i]->toString() << endl;

    }

    cout << "" << right << setw(55) << setfill('=') << "" << endl;

}

void defaultMenuOption() {

    cout << "Invalid choice, try again\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

}
void deAllocateMemory(Creature** array) {

    if (array != nullptr)
    {
        delete[] array;
        array = nullptr;
    }

}
void listfunction() {

    int sizeInput;

    cout << "Input list size: ";
    cin >> sizeInput;

    Army creatureArmy(sizeInput);
    creatureArmy.printList();
    deAllocateMemory(creatureArmy.getList());

}
