/**
 * @file RequestQueue.cpp
 * @brief Implementation of the RequestQueue class.
 */

#include "RequestQueue.h"
#include <stdexcept>

/**
 * @brief Adds a request to the queue.
 * @param request The request to be added.
 */
void RequestQueue::enqueue(const Request& request) {
    queue.push(request);
}

/**
 * @brief Removes and returns the request at the front of the queue.
 * @return The request at the front of the queue.
 * @throws std::out_of_range If the queue is empty.
 */
Request RequestQueue::dequeue() {
    if (!queue.empty()) {
        Request req = queue.front();
        queue.pop();
        return req;
    }
    throw std::out_of_range("Queue is empty");
}

/**
 * @brief Checks if the queue is empty.
 * @return True if the queue is empty, false otherwise.
 */
bool RequestQueue::isEmpty() const { return queue.empty(); }

/**
 * @brief Gets the number of requests in the queue.
 * @return The size of the queue.
 */
size_t RequestQueue::size() const { return queue.size(); }
