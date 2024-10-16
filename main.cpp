/**
 * @file main.cpp
 * @brief Entry point for the LoadBalancer simulation program.
 */

#include <iostream>
#include "LoadBalancer.h"

/**
 * @brief Main function to run the LoadBalancer simulation.
 * @return Exit status of the program.
 */
int main() {
    int numServers, runtime;
    
    std::cout << "Enter the number of servers: ";
    std::cin >> numServers;
    std::cout << "Enter the number of clock cycles: ";
    std::cin >> runtime;

    LoadBalancer loadBalancer(numServers);

    for (int i = 0; i < numServers * 100; ++i) {
        loadBalancer.addGuaranteedRequest();
    }

    loadBalancer.processRequests(runtime);
    return 0;
}
