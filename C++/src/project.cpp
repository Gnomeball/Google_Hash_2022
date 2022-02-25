#include "project.hpp"

#include <string>
#include <vector>

// Constructor(s) / Destructor(s)

Project::Project(std::string name, int days, int score, int dueBy, std::vector<Role> roles)
    : name(name), days(days), score(score), dueBy(dueBy), roles(roles) {
    this->completed = false;
}

// Member Functions

std::string Project::getName(void) {
    return this->name;
}

int Project::getDays(void) {
    return this->days;
}

int Project::getScore(void) {
    return this->score;
}

int Project::getDueBy(void) {
    return this->dueBy;
}

std::vector<Role> Project::getRoles(void) {
    return this->roles;
}

bool Project::isComplete(void) {
    return this->completed;
}

// Utility Functions

double Project::calculateScoreByDay(void) {
    return double(this->score) / this->days;
}

void Project::setAsCompleted(void) {
    this->completed = true;
}

// Overrides
