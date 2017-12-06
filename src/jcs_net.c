/**
 * $File: jcs_net.c $
 * $Date: 2017-12-06 13:07:53 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright © 2017 by Shen, Jen-Chieh $
 */

#include "../libc_jcs.h"

/**
 * @func jcs_create_server
 * @brief Build the server socket.
 * @param { int } port : port number.
 * @param { bool } nio : non-blocking IO?
 * @param { int } max_con : maxinum connections.
 * @return { int } : socket descriptor.
 * @attention socket descriptor need to be close after using it.
 *
 * @example
 * @start_code
 * int sockfd = jcs_create_server(PORT, false, 20);
 * close(sockfd);  /\* clsoe it. *\/
 * @end_code
 */
int jcs_create_server(const int port, bool nio, const int max_con) {
    struct sockaddr_in dest;

    int sockfd;

    int opt = 1;

    /* Creating socket file descriptor. */
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        jcs_error("Failed to create socket..");
        return JCS_HAS_ERROR;
    }

    /* Forcefully attaching socket to the port. */
    int err = setsockopt(
        sockfd,
        SOL_SOCKET,
        SO_REUSEADDR /*| SO_REUSEPORT */,
        (char*)&opt,
        sizeof(opt));
    if (err < 0) {
        jcs_error("Failed to set port %d", port);
        return JCS_HAS_ERROR;
    }

    /* Set Non-blocking IO. */
    {
        int flags = fcntl(sockfd, F_GETFL, 0);
        if (nio)
            flags = (flags | O_NONBLOCK);
        else
            flags = (flags & ~O_NONBLOCK);

        int result = fcntl(sockfd, F_SETFL, flags);
        if (result == SOCKET_ERROR) {
            jcs_error("Set NIO failed..");
            return JCS_HAS_ERROR;
        }
    }

    bzero(&dest, sizeof(dest));
    dest.sin_family = AF_INET;
    dest.sin_addr.s_addr = INADDR_ANY;
    dest.sin_port = htons(port);

    /* Assign a port number to socket. */
    int error = bind(sockfd, (struct sockaddr *)&dest, sizeof(dest));
    if (error < 0) {
        jcs_error("Failed to bind the socket.");
        return JCS_HAS_ERROR;
    }

    /* Make it listen to socket with max connections. */
    if (listen(sockfd, max_con) < 0) {
        jcs_error("Failed to listen..");
        return JCS_HAS_ERROR;
    }

    jcs_log("Successfully setup server socket... Port: %d", port);
    return sockfd;
}

/**
 * @func jcs_socket_client
 * @brief Build the server socket.
 * @param { char } hostname : host name / internet protocol.
 * @param { int } port : port number.
 * @return { int } : socket descriptor.
 *
 * @attention socket descriptor need to be close after using it.
 *
 * @example
 * @start_code
 * int sockfd = jcs_create_server(PORT, false, 20);
 * close(sockfd);  /\* clsoe it. *\/
 * @end_code
 */
int jcs_create_client(const char* hostname, const int port) {
    int sockfd;
    struct sockaddr_in dest;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        jcs_error("Failed to create socket..");
        return JCS_HAS_ERROR;
    }

    bzero(&dest, sizeof(dest));
    dest.sin_family = PF_INET;
    dest.sin_port = htons(port);
    dest.sin_addr.s_addr = inet_addr(hostname);
    /*inet_aton(hostname, &dest.sin_addr);*/

    /* Convert IPv4 and IPv6 addresses from text to binary form. */
    if (inet_pton(AF_INET, hostname, &dest.sin_addr) <= 0) {
        jcs_error("Invalid address not supported..");
        return JCS_HAS_ERROR;
    }

    /* Connecting to server */
    if (connect(sockfd, (struct sockaddr*)&dest, sizeof(dest)) < 0) {
        jcs_error("Failed to connect to server..");
        return JCS_HAS_ERROR;
    }

    jcs_log("Make connection.. %s:%d", hostname, port);
    return sockfd;
}
