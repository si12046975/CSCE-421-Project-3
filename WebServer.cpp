/**
 * @file WebServer.cpp
 * @brief Implementation of the WebServer class.
 */

#include "WebServer.h"

/**
 * @brief Constructs a WebServer with a specified ID.
 * @param id The ID of the server.
 */
WebServer::WebServer(int id) : id(id), available(true), processingTime(0) {}

/**
 * @brief Processes a request by setting the server to unavailable and setting the processing time.
 * @param request The request to be processed.
 */
void WebServer::processRequest(const Request& request) {
    available = false;
    processingTime = request.getTime();
}

/**
 * @brief Decrements the processing time of the server.
 */
void WebServer::decrementProcessingTime() {
    if (processingTime > 0) {
        processingTime--;
    }
}

/**
 * @brief Gets the current processing time of the server.
 * @return The current processing time.
 */
int WebServer::getProcessingTime() const {
    return processingTime;
}

/**
 * @brief Gets the ID of the server.
 * @return The server ID.
 */
int WebServer::getId() const { return id; }

/**
 * @brief Checks if the server is available.
 * @return True if the server is available, false otherwise.
 */
bool WebServer::isAvailable() const { return available; }

/**
 * @brief Sets the availability status of the server.
 * @param available The availability status to set.
 */
void WebServer::setAvailable(bool available) { this->available = available; }
