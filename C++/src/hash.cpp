#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "contributor.hpp"
#include "hash.hpp"
#include "project.hpp"

int main(int argc, char *argv[]) {

    // * Parse the args

    if (argc == 1) {
        printf("No file argument supplied, exiting.\n");
        exit(EXIT_FAILURE);
    } else {
        printf("Opening file : %s\n", argv[1]);
    }

    // * Open the file

    std::ifstream input_data;
    input_data.open(argv[1]);

    // * Read the data? please

    int n_contributors;
    int n_projects;
    std::vector<Contributor> contributors;
    std::vector<Project> projects;

    readLimits(input_data, &n_contributors, &n_projects);
    readContributors(input_data, n_contributors, contributors);
    readProjects(input_data, n_projects, projects);

    // * Output data, for reasons of "does it work?"

    std::cout << "n_contributors = " << n_contributors << "\n";
    std::cout << "n_contributors = " << n_projects << "\n";

    for (auto c : contributors)
        std::cout << c.getName() << "\n";

    for (auto p : projects)
        std::cout << p.getName() << "\n";

    // * Close the file

    input_data.close();

    return 0;
}
