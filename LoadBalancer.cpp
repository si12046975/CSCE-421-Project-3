/**
 * @file LoadBalancer.cpp
 * @brief Implementation of the LoadBalancer class.
 */

#include "LoadBalancer.h"
#include <iostream>
#include <algorithm>
#include <numeric>
#include <ctime>
#include <iomanip>

/**
 * @brief Constructs a LoadBalancer with a specified number of initial servers.
 * @param initialServers The number of servers to start with.
 */
LoadBalancer::LoadBalancer(int initialServers) : currentTime(0), totalProcessedRequests(0), lastProcessedServerId(-1) {
    for (int i = 0; i < initialServers; ++i) {
        addServer();
    }
    std::srand(std::time(0));
    log("Starting queue size: " + std::to_string(requestQueue.size()));
    log("Initial number of servers: " + std::to_string(servers.size()));
    // Open log file
    logFile.open("load_balancer_log.txt", std::ios::app);
    if (!logFile.is_open()) {
        std::cerr << "Failed to open log file!" << std::endl;
    }
}

/**
 * @brief Destructor for LoadBalancer. Cleans up allocated resources.
 */
LoadBalancer::~LoadBalancer() {
    for (auto server : servers) {
        delete server;
    }
    if (logFile.is_open()) {
        logFile.close();
    }
}

/**
 * @brief Adds a request to the load balancer's queue.
 * @param request The request to be added.
 */
void LoadBalancer::addRequest(const Request& request) {
    requestQueue.enqueue(request);
}

/**
 * @brief Processes requests for a specified runtime.
 * @param runtime The total time to run the load balancer.
 */
void LoadBalancer::processRequests(int runtime) {
    while (currentTime < runtime) {
        for (auto& server : servers) {
            if (server->isAvailable() && !requestQueue.isEmpty()) {
                Request req = requestQueue.dequeue();
                server->processRequest(req);
                totalProcessedRequests++;
                lastProcessedServerId = server->getId();
                int taskTime = req.getTime();
                minTaskTime = std::min(minTaskTime, taskTime);
                maxTaskTime = std::max(maxTaskTime, taskTime);
                log("Request processed by Server " + std::to_string(lastProcessedServerId));
            }
        }
        for (auto& server : servers) {
            if (!server->isAvailable()) {
                server->decrementProcessingTime();
                if (server->getProcessingTime() == 0) {
                    server->setAvailable(true);
                    log("Server " + std::to_string(server->getId()) + " became available");
                }
            }
        }
        adjustServerCount();
        currentTime++;
        addRandomRequest();
        if (currentTime % 500 == 0) { // Log status every 500 time units
            logStatus();
        }
    }
    logFinalStatus();
}

/**
 * @brief Adds a random request to the queue.
 */
void LoadBalancer::addRandomRequest() {
    if (std::rand() % 2 == 0) {
        std::string ipIn = "192.168.1." + std::to_string(std::rand() % 256);
        std::string ipOut = "192.168.1." + std::to_string(std::rand() % 256);
        int time = std::rand() % 20 + 10;
        char jobType = (std::rand() % 2) ? 'P' : 'S';
        Request newRequest(ipIn, ipOut, time, jobType);
        addRequest(newRequest);
        log("New request added: " + ipIn + " -> " + ipOut + ", type: " + jobType + ", time: " + std::to_string(time));
    }
}

/**
 * @brief Adds a guaranteed request to the queue.
 */
void LoadBalancer::addGuaranteedRequest() {
    std::string ipIn = "192.168.1." + std::to_string(std::rand() % 256);
    std::string ipOut = "192.168.1." + std::to_string(std::rand() % 256);
    int time = std::rand() % 20 + 10;
    char jobType = (std::rand() % 2) ? 'P' : 'S';
    Request newRequest(ipIn, ipOut, time, jobType);
    addRequest(newRequest);
}

/**
 * @brief Gets the ID of the last server that processed a request.
 * @return The ID of the last processed server.
 */
int LoadBalancer::getLastProcessedServerId() const {
    return lastProcessedServerId;
}

/**
 * @brief Adjusts the number of servers based on the queue size.
 */
void LoadBalancer::adjustServerCount() {
    const int QUEUE_THRESHOLD_HIGH = 50;
    const int QUEUE_THRESHOLD_LOW = 10;
    const int MAX_SERVERS = 20;
    const int MIN_SERVERS = 1;
    if (requestQueue.size() > QUEUE_THRESHOLD_HIGH && servers.size() < MAX_SERVERS) {
        addServer();
    } else if (requestQueue.size() < QUEUE_THRESHOLD_LOW && servers.size() > MIN_SERVERS) {
        removeServer();
    }
}

/**
 * @brief Adds a new server to the load balancer.
 */
void LoadBalancer::addServer() {
    int newId = servers.size() + 1;
    servers.push_back(new WebServer(newId));
    log("Server " + std::to_string(newId) + " added. Total servers: " + std::to_string(servers.size()));
}

/**
 * @brief Removes a server from the load balancer.
 */
void LoadBalancer::removeServer() {
    if (!servers.empty()) {
        WebServer* serverToRemove = servers.back();
        servers.pop_back();
        delete serverToRemove;
        log("Server " + std::to_string(serverToRemove->getId()) + " removed. Total servers: " + std::to_string(servers.size()));
    }
}

/**
 * @brief Logs a message to the log file.
 * @param message The message to log.
 */
void LoadBalancer::log(const std::string& message) {
    logFile << "[Time " << currentTime << "] " << message << std::endl;
}

/**
 * @brief Logs the current status of the load balancer.
 */
void LoadBalancer::logStatus() {
    log("Current status:");
    log(" Queue size: " + std::to_string(requestQueue.size()));
    log(" Active servers: " + std::to_string(servers.size()));
    log(" Processed requests: " + std::to_string(totalProcessedRequests));
}

/**
 * @brief Logs the final status of the load balancer at the end of the simulation.
 */
void LoadBalancer::logFinalStatus() {
    log("Simulation ended");
    log("Final status:");
    log(" Remaining requests in queue: " + std::to_string(requestQueue.size()));
    log(" Total processed requests: " + std::to_string(totalProcessedRequests));
    log(" Final number of servers: " + std::to_string(servers.size()));
    int activeServers = 0;
    for (const auto& server : servers) {
        if (!server->isAvailable()) {
            activeServers++;
        }
    }
    log(" Active servers at end: " + std::to_string(activeServers));
    log(" Inactive servers at end: " + std::to_string(servers.size() - activeServers));
}