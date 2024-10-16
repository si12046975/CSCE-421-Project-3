/**
 * @file Request.cpp
 * @brief Implementation of the Request class.
 */

#include "Request.h"

/**
 * @brief Constructs a Request with specified parameters.
 * @param ipIn The input IP address.
 * @param ipOut The output IP address.
 * @param time The time required to process the request.
 * @param jobType The type of job ('P' for processing, 'S' for storage).
 */
Request::Request(std::string ipIn, std::string ipOut, int time, char jobType)
    : ipIn(ipIn), ipOut(ipOut), time(time), jobType(jobType) {}

/**
 * @brief Gets the input IP address of the request.
 * @return The input IP address.
 */
std::string Request::getIpIn() const { return ipIn; }

/**
 * @brief Gets the output IP address of the request.
 * @return The output IP address.
 */
std::string Request::getIpOut() const { return ipOut; }

/**
 * @brief Gets the time required to process the request.
 * @return The processing time.
 */
int Request::getTime() const { return time; }

/**
 * @brief Gets the type of job for the request.
 * @return The job type ('P' or 'S').
 */
char Request::getJobType() const { return jobType; }
