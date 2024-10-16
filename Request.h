/**
 * @file Request.h
 * @brief Header file for the Request class.
 */

#ifndef REQUEST_H
#define REQUEST_H

#include <string>

/**
 * @class Request
 * @brief Represents a network request with input and output IP addresses, processing time, and job type.
 */
class Request {
public:
    /**
     * @brief Constructs a Request with specified parameters.
     * @param ipIn The input IP address.
     * @param ipOut The output IP address.
     * @param time The time required to process the request.
     * @param jobType The type of job ('P' for processing, 'S' for storage).
     */
    Request(std::string ipIn, std::string ipOut, int time, char jobType);

    /**
     * @brief Gets the input IP address of the request.
     * @return The input IP address.
     */
    std::string getIpIn() const;

    /**
     * @brief Gets the output IP address of the request.
     * @return The output IP address.
     */
    std::string getIpOut() const;

    /**
     * @brief Gets the time required to process the request.
     * @return The processing time.
     */
    int getTime() const;

    /**
     * @brief Gets the type of job for the request.
     * @return The job type ('P' or 'S').
     */
    char getJobType() const;

private:
    std::string ipIn; ///< The input IP address.
    std::string ipOut; ///< The output IP address.
    int time; ///< The time required to process the request.
    char jobType; ///< The type of job ('P' for processing, 'S' for storage).
};

#endif // REQUEST_H
