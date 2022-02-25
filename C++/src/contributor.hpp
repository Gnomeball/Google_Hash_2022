#ifndef contributor_h
#define contributor_h

#include <ostream>
#include <sstream>
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
    friend std::ostream &operator<<(std::ostream &os, Contributor contributor) {
        std::stringstream skills;
        for (auto s : contributor.skills)
            skills << s << ", ";
        os << contributor.name << " [" << skills.str().substr(0, skills.str().size() - 2) << "]";
        return os;
    }
};

#endif // contributor_h
