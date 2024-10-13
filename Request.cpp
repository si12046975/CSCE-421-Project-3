#include "Request.h"

Request::Request(std::string ipIn, std::string ipOut, int time, char jobType)
    : ipIn(ipIn), ipOut(ipOut), time(time), jobType(jobType) {}

std::string Request::getIpIn() const { return ipIn; }
std::string Request::getIpOut() const { return ipOut; }
int Request::getTime() const { return time; }
char Request::getJobType() const { return jobType; }