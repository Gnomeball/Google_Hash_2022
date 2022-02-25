#ifndef project_h
#define project_h

#include <string>
#include <vector>

#include "role.hpp"

class Project {
    // Fields
    std::string name;
    int days;
    int score;
    int dueBy;
    std::vector<Role> roles;
    bool completed;

public:
    // Constructor(s) / Destructor(s)
    Project() = default;
    Project(std::string name, int days, int score, int dueBy, std::vector<Role> roles);
    ~Project() = default;

    // Member Functions
    std::string getName(void);
    int getDays(void);
    int getScore(void);
    int getDueBy(void);
    std::vector<Role> getRoles(void);
    bool isComplete(void);

    // Utility Functions
    double calculateScoreByDay(void);
    void setAsCompleted(void);

    // Overrides
};

#endif // project_h
