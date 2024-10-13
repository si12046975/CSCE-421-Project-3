#ifndef WEBSERVER_H
#define WEBSERVER_H
#include <iostream>
#include "Request.h"

class WebServer {
public:
    WebServer(int id);
    bool isAvailable() const;
    void processRequest(const Request& request);
    void setAvailable(bool available);
    int getId() const;
    void decrementProcessingTime();
    int getProcessingTime() const;

private:
    int id;
    bool available;
    int processingTime;
};

#endif // WEBSERVER_H