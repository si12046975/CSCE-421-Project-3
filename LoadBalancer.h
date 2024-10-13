#ifndef LOADBALANCER_H
#define LOADBALANCER_H
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "RequestQueue.h"
#include "WebServer.h"

class LoadBalancer {
public:
    LoadBalancer(int numServers);
    ~LoadBalancer();
    void addRequest(const Request& request);
    void processRequests(int runtime);
    void addRandomRequest();
    int getLastProcessedServerId() const;
private:
    std::vector<WebServer*> servers;
    RequestQueue requestQueue;
    int currentTime;
    int totalProcessedRequests;
    int lastProcessedServerId;
};

#endif // LOADBALANCER_H