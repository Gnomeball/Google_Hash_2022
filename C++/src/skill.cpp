#include "skill.hpp"

#include <string>

// Constructor(s) / Destructor(s)

Skill::Skill(std::string name, int level) : name(name), level(level) {
    // * Empty
}

// Member Functions

std::string Skill::getName(void) {
    return this->name;
}

int Skill::getLevel(void) {
    return this->level;
}

// Utility Functions

void Skill::levelUp(void) {
    this->level += 1;
}

// Overrides
