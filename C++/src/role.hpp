#ifndef role_h
#define role_h

#include <ostream>
#include <string>

class Role {
    // Fields
    std::string name;
    int level;
    bool filled;

public:
    // Constructor(s) / Destructor(s)
    Role() = default;
    Role(std::string name, int level);
    ~Role() = default;

    // Member Functions
    std::string getName(void);
    int getLevel(void);

    // Utility Functions
    bool isFilled(void);
    void fill(void);
    void empty(void);

    // Overrides
    friend std::ostream &operator<<(std::ostream &os, Role role) {
        os << role.name << " " << role.level;
        return os;
    }
};

#endif // role_h
