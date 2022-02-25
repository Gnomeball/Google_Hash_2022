#include "role.hpp"

#include <string>

// Constructor(s) / Destructor(s)

Role::Role(std::string name, int level) : name(name), level(level) {
    this->filled = false;
}

// Member Functions

std::string Role::getName(void) {
    return this->name;
}

int Role::getLevel(void) {
    return this->level;
}

// Utility Functions

bool Role::isFilled(void) {
    return this->filled;
}

void Role::fill(void) {
    this->filled = true;
}

void Role::empty(void) {
    this->filled = false;
}

// Overrides
