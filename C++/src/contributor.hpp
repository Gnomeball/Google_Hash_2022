#ifndef contributor_h
#define contributor_h

#include <string>
#include <vector>

#include "skill.hpp"

class Contributor {
    // Fields
    std::string name;
    std::vector<Skill> skills;

public:
    // Constructor(s) / Destructor(s)
    Contributor() = default;
    Contributor(std::string name, std::vector<Skill> skills);
    ~Contributor() = default;

    // Member Functions
    std::string getName(void);
    std::vector<Skill> getSkills(void);

    // Utility Functions

    // Overrides
};

#endif // contributor_h
