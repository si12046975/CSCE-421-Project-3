#ifndef REQUEST_H
#define REQUEST_H
#include <string>

class Request {
public:
    Request(std::string ipIn, std::string ipOut, int time, char jobType);
    std::string getIpIn() const;
    std::string getIpOut() const;
    int getTime() const;
    char getJobType() const;
private:
    std::string ipIn;
    std::string ipOut;
    int time;
    char jobType;
};

#endif // REQUEST_H