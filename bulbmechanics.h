#ifndef BULBMECHANICS_H
#define BULBMECHANICS_H

#include <set>
#include <cstddef>

class Bulb;
struct instruction;

struct lane{
    char* current_letter;
    struct lane *next;
    struct lane *prev;
};

struct lane * addelem(lane *lane_base, char* letter);

class bulbMechanics{
    public:
        bulbMechanics();
};

class Bulb{
    public:
        Bulb();
        ~Bulb();
        char* name;
        instruction* instructions;
        int instructions_count;
    private:
};

class MachineTuring{
    public:
        Bulb* currentBulb;
        std::set<Bulb*> Bulbs;
        struct lane* laneTuring;
        int step();
        MachineTuring();
        ~MachineTuring();
};

#endif // BULBMECHANICS_H
