/**
 * $File: jcs_net.c $
 * $Date: 2017-12-06 13:07:53 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright © 2017 by Shen, Jen-Chieh $
 */

#include "../libc_jcs.h"


PRIVATE int jcs_create_socket(JCS_PROTOCAL_TYPE type);


/**
 * @func jcs_is_valid_ip_address
 * @brief Check if the ip address valid format.
 * @param { char } ip_addr : ip address.
 * @return { bool } : true, valid ip address. false, invalid ip address.
 */
bool jcs_is_valid_ip_address(const char *ip_addr) {
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ip_addr, &(sa.sin_addr));
    return result != 0;
}

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
int jcs_create_server(const int port,
                      JCS_PROTOCAL_TYPE prot_type,
                      bool nio,
                      const int max_con) {
    struct sockaddr_in dest;

    int sockfd;

    int opt = 1;

    /* Creating socket file descriptor. */
    if ((sockfd = jcs_create_socket(prot_type)) == 0) {
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
 * @func jcs_create_client
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
int jcs_create_client(const char* hostname,
                      const int port,
                      JCS_PROTOCAL_TYPE prot_type) {
    int sockfd;
    struct sockaddr_in dest;

    if ((sockfd = jcs_create_socket(prot_type)) < 0) {
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

/**
 * @func jcs_accept
 * @brief Simple accept connection.
 * @param { int } serverfd : Server socket descriptor.
 * @return { int } : client socket descriptor.
 */
int jcs_accept(int serverfd) {
    int clientfd;
    struct sockaddr_in client_addr;
    int addrlen = sizeof(client_addr);

    clientfd = accept(serverfd,
                      (struct sockaddr*)&client_addr,
                      &addrlen);
    return clientfd;
}


/**
 * @func jcs_create_socket
 * @brief Create a socket depends on protocal type.
 * @param { bool } udp : Is udp?
 * @return { int } : socket descriptor just created.
 */
PRIVATE int jcs_create_socket(JCS_PROTOCAL_TYPE type) {
    if (type == TCP)
        return socket(AF_INET, SOCK_STREAM, 0);
    else if (type == UDP)
        return socket(AF_INET, SOCK_DGRAM, 0);

    /* Return NULL ref. */
    return 0;
}
