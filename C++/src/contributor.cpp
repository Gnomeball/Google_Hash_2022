#include "contributor.hpp"

#include <string>
#include <vector>

// Constructor(s) / Destructor(s)

Contributor::Contributor(std::string name, std::vector<Skill> skills) : name(name), skills(skills) {
    // * Empty
}

// Member Functions

std::string Contributor::getName(void) {
    return this->name;
}

std::vector<Skill> Contributor::getSkills(void) {
    return this->skills;
}

// Utility Functions



// Overrides
