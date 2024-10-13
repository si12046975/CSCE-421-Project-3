#include "LoadBalancer.h"
#include <algorithm>

LoadBalancer::LoadBalancer(int numServers) : currentTime(0), totalProcessedRequests(0), lastProcessedServerId(-1) {
    servers.resize(numServers);
    for (int i = 0; i < numServers; ++i) {
        servers[i] = new WebServer(i + 1);  // Assign ID starting from 1
    }
    std::srand(std::time(0));
}

LoadBalancer::~LoadBalancer() {
    for (auto server : servers) {
        delete server;
    }
}

void LoadBalancer::addRequest(const Request& request) {
    requestQueue.enqueue(request);
}

void LoadBalancer::processRequests(int runtime) {
    while (currentTime < runtime) {
        // Process requests on all available servers
        for (auto& server : servers) {
            if (server->isAvailable() && !requestQueue.isEmpty()) {
                Request req = requestQueue.dequeue();
                server->processRequest(req);
                totalProcessedRequests++;
                lastProcessedServerId = server->getId();
                std::cout << "Time " << currentTime<< ": Server " << lastProcessedServerId << " processed request from " << req.getIpIn() << " to " << req.getIpOut() << " of type " << req.getJobType() <<  " (Processing time: " << req.getTime() << "s)" << std::endl;
            }
        }

        // Simulate time passing and servers finishing their work
        for (auto& server : servers) {
            if (!server->isAvailable()) {
                server->decrementProcessingTime();
                if (server->getProcessingTime() == 0) {
                    server->setAvailable(true);
                    std::cout << "Time " << currentTime << ": Server " << server->getId() << " is now available" << std::endl;
                }
            }
        }

        currentTime++;
        addRandomRequest();
    }
    std::cout << "Total processed requests: " << totalProcessedRequests << std::endl;
}

void LoadBalancer::addRandomRequest() {
    if (std::rand() % 100 < 80) {  // 80% chance to add a new request each second
        std::string ipIn = "192.168.1." + std::to_string(std::rand() % 256);
        std::string ipOut = "192.168.1." + std::to_string(std::rand() % 256);
        int time = std::rand() % 20 + 10;  // Processing time between 10 and 20 seconds
        char jobType = (std::rand() % 2) ? 'P' : 'S';
        Request newRequest(ipIn, ipOut, time, jobType);
        addRequest(newRequest);
        std::cout << "Time " << currentTime << ": New request added (Processing time: " << time << "s)" << std::endl;
    }
}

int LoadBalancer::getLastProcessedServerId() const {
    return lastProcessedServerId;
}