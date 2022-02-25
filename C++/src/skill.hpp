#ifndef skill_h
#define skill_h

#include <ostream>
#include <string>

class Skill {
    // Fields
    std::string name;
    int level;

public:
    // Constructor(s) / Destructor(s)
    Skill() = default;
    Skill(std::string name, int level);
    ~Skill() = default;

    // Member Functions
    std::string getName(void);
    int getLevel(void);

    // Utility Functions
    void levelUp(void);

    // Overrides
    friend std::ostream &operator<<(std::ostream &os, Skill skill) {
        os << skill.name << " " << skill.level;
        return os;
    }
};

#endif // skill_h
