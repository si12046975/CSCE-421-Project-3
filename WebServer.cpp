#include "WebServer.h"

WebServer::WebServer(int id) : id(id), available(true), processingTime(0) {}

void WebServer::processRequest(const Request& request) {
    available = false;
    processingTime = request.getTime();
}

void WebServer::decrementProcessingTime() {
    if (processingTime > 0) {
        processingTime--;
    }
}

int WebServer::getProcessingTime() const {
    return processingTime;
}
int WebServer::getId() const { return id; }

bool WebServer::isAvailable() const { return available; }

void WebServer::setAvailable(bool available) { this->available = available; }