/**
 * @file WebServer.h
 * @brief Header file for the WebServer class.
 */

#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <iostream>
#include "Request.h"

/**
 * @class WebServer
 * @brief Represents a web server that processes network requests.
 */
class WebServer {
public:
    /**
     * @brief Constructs a WebServer with a specified ID.
     * @param id The ID of the server.
     */
    WebServer(int id);

    /**
     * @brief Checks if the server is available.
     * @return True if the server is available, false otherwise.
     */
    bool isAvailable() const;

    /**
     * @brief Processes a request by setting the server to unavailable and setting the processing time.
     * @param request The request to be processed.
     */
    void processRequest(const Request& request);

    /**
     * @brief Sets the availability status of the server.
     * @param available The availability status to set.
     */
    void setAvailable(bool available);

    /**
     * @brief Gets the ID of the server.
     * @return The server ID.
     */
    int getId() const;

    /**
     * @brief Decrements the processing time of the server.
     */
    void decrementProcessingTime();

    /**
     * @brief Gets the current processing time of the server.
     * @return The current processing time.
     */
    int getProcessingTime() const;

private:
    int id; ///< The ID of the server.
    bool available; ///< The availability status of the server.
    int processingTime; ///< The current processing time of the server.
};

#endif // WEBSERVER_H
