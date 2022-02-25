#ifndef skill_h
#define skill_h

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
};

#endif // skill_h
