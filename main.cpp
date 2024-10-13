#include <iostream>
#include "LoadBalancer.h"

int main() {
    int numServers, runtime;
    
    std::cout << "Enter the number of servers: ";
    std::cin >> numServers;
    std::cout << "Enter the number of clock cycles: ";
    std::cin >> runtime;

    LoadBalancer loadBalancer(numServers);

    for (int i = 0; i < numServers * 100; ++i) {
        loadBalancer.addRandomRequest();
    }

    loadBalancer.processRequests(runtime);

    std::cout << "Last request was processed by Server " << loadBalancer.getLastProcessedServerId() << std::endl;

    return 0;
}