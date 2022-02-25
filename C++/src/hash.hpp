#ifndef hash_h
#define hash_h

#include <cstdio>
#include <fstream>
#include <string>
#include <vector>

#include "contributor.hpp"
#include "project.hpp"
#include "role.hpp"
#include "skill.hpp"

inline void readLimits(std::ifstream &input_data, int *n_contributors, int *n_projects) {
    std::string buffer;
    std::getline(input_data, buffer);

    std::string token = buffer.substr(0, buffer.find(" "));
    *n_contributors = std::atoi(token.c_str());
    token = buffer.substr(token.length(), buffer.back());
    *n_projects = std::atoi(token.c_str());
}

inline Contributor readContributor(std::ifstream &input_data) {
    std::string buffer;
    std::getline(input_data, buffer);

    std::string token = buffer.substr(0, buffer.find(" "));
    std::string name = token;
    token = buffer.substr(token.length(), buffer.back());
    int n_skills = std::atoi(token.c_str());

    std::vector<Skill> skills;
    for (int i = 0; i < n_skills; i++) {
        std::getline(input_data, buffer);
        token = buffer.substr(0, buffer.find(" "));
        std::string name = token;
        token = buffer.substr(token.length(), buffer.back());
        int level = std::atoi(token.c_str());
        skills.push_back(Skill(name, level));
    }
    return Contributor(name, skills);
}

inline void readContributors(std::ifstream &input_data, int n_contributors,
                             std::vector<Contributor> &contributors) {
    for (int i = 0; i < n_contributors; i++)
        contributors.push_back(readContributor(input_data));
}

inline Project readProject(std::ifstream &input_data) {
    std::string buffer;
    std::getline(input_data, buffer);

    std::string token = buffer.substr(0, buffer.find(" "));
    std::string name = token;
    buffer = buffer.substr(token.size() + 1, buffer.back()).c_str();
    token = buffer.substr(0, buffer.find(" "));
    int days = std::atoi(token.c_str());
    buffer = buffer.substr(token.size() + 1, buffer.back()).c_str();
    token = buffer.substr(0, buffer.find(" "));
    int score = std::atoi(token.c_str());
    buffer = buffer.substr(token.size() + 1, buffer.back()).c_str();
    token = buffer.substr(0, buffer.find(" "));
    int dueBy = std::atoi(token.c_str());
    buffer = buffer.substr(token.size() + 1, buffer.back()).c_str();
    int n_roles = std::atoi(buffer.c_str());

    std::vector<Role> roles;
    for (int i = 0; i < n_roles; i++) {
        std::getline(input_data, buffer);
        token = buffer.substr(0, buffer.find(" "));
        std::string name = token;
        token = buffer.substr(token.length(), buffer.back());
        int level = std::atoi(token.c_str());
        roles.push_back(Role(name, level));
    }
    return Project(name, days, score, dueBy, roles);
}

inline void readProjects(std::ifstream &input_data, int n_projects,
                         std::vector<Project> &projects) {
    for (int i = 0; i < n_projects; i++)
        projects.push_back(readProject(input_data));
}

#endif // hash_h
