#ifndef REQUESTQUEUE_H
#define REQUESTQUEUE_H
#include <queue>
#include "Request.h"

class RequestQueue {
public:
    void enqueue(const Request& request);
    Request dequeue();
    bool isEmpty() const;
    size_t size() const;
private:
    std::queue<Request> queue;
};

#endif // REQUESTQUEUE_H