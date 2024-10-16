/**
 * @file RequestQueue.h
 * @brief Header file for the RequestQueue class.
 */

#ifndef REQUESTQUEUE_H
#define REQUESTQUEUE_H

#include <queue>
#include "Request.h"

/**
 * @class RequestQueue
 * @brief Manages a queue of network requests.
 */
class RequestQueue {
public:
    /**
     * @brief Adds a request to the queue.
     * @param request The request to be added.
     */
    void enqueue(const Request& request);

    /**
     * @brief Removes and returns the request at the front of the queue.
     * @return The request at the front of the queue.
     * @throws std::out_of_range If the queue is empty.
     */
    Request dequeue();

    /**
     * @brief Checks if the queue is empty.
     * @return True if the queue is empty, false otherwise.
     */
    bool isEmpty() const;

    /**
     * @brief Gets the number of requests in the queue.
     * @return The size of the queue.
     */
    size_t size() const;

private:
    std::queue<Request> queue; ///< The underlying queue of requests.
};

#endif // REQUESTQUEUE_H
