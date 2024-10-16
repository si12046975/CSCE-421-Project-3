/**
 * @file LoadBalancer.h
 * @brief Header file for the LoadBalancer class.
 */

#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "RequestQueue.h"
#include "WebServer.h"

/**
 * @class LoadBalancer
 * @brief Manages a pool of servers to balance incoming requests.
 */
class LoadBalancer {
public:
    /**
     * @brief Constructs a LoadBalancer with a specified number of initial servers.
     * @param initialServers The number of servers to start with.
     */
    LoadBalancer(int initialServers);

    /**
     * @brief Destructor for LoadBalancer. Cleans up allocated resources.
     */
    ~LoadBalancer();

    /**
     * @brief Adds a request to the load balancer's queue.
     * @param request The request to be added.
     */
    void addRequest(const Request& request);

    /**
     * @brief Processes requests for a specified runtime.
     * @param runtime The total time to run the load balancer.
     */
    void processRequests(int runtime);

    /**
     * @brief Adds a random request to the queue.
     */
    void addRandomRequest();

    /**
     * @brief Adds a guaranteed request to the queue.
     */
    void addGuaranteedRequest();

    /**
     * @brief Gets the ID of the last server that processed a request.
     * @return The ID of the last processed server.
     */
    int getLastProcessedServerId() const;

private:
    std::vector<WebServer*> servers; ///< List of servers managed by the load balancer.
    RequestQueue requestQueue; ///< Queue of incoming requests.
    int currentTime; ///< Current time in the simulation.
    int totalProcessedRequests; ///< Total number of processed requests.
    int lastProcessedServerId; ///< ID of the last server that processed a request.
    std::ofstream logFile; ///< Log file for recording events.
    int minTaskTime; ///< Minimum task time observed.
    int maxTaskTime; ///< Maximum task time observed.

    /**
     * @brief Adjusts the number of servers based on the queue size.
     */
    void adjustServerCount();

    /**
     * @brief Adds a new server to the load balancer.
     */
    void addServer();

    /**
     * @brief Removes a server from the load balancer.
     */
    void removeServer();

    /**
     * @brief Logs the current status of the load balancer.
     */
    void logStatus();

    /**
     * @brief Logs a message to the log file.
     * @param message The message to log.
     */
    void log(const std::string& message);

    /**
     * @brief Logs the final status of the load balancer at the end of the simulation.
     */
    void logFinalStatus();
};

#endif // LOADBALANCER_H
