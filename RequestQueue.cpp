#include "RequestQueue.h"
#include <stdexcept>

void RequestQueue::enqueue(const Request& request) {
    queue.push(request);
}

Request RequestQueue::dequeue() {
    if (!queue.empty()) {
        Request req = queue.front();
        queue.pop();
        return req;
    }
    throw std::out_of_range("Queue is empty");
}

bool RequestQueue::isEmpty() const { return queue.empty(); }

size_t RequestQueue::size() const { return queue.size(); }