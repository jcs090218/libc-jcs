#ifndef __JCS_NET_H__
/**
 * $File: jcs_net.h $
 * $Date: 2017-12-06 13:07:41 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright © 2017 by Shen, Jen-Chieh $
 */
#define __JCS_NET_H__

#include <sys/types.h>
#include <stddef.h>


#ifndef SOCKET_ERROR
/**
 * @def SOCKET_ERROR
 * @brief Socket error sign.
 */
#define SOCKET_ERROR -1
#endif


/**
 * @func jcs_is_valid_ip_address
 * @brief Check if the ip address valid format.
 * @param { char } ip_addr : ip address.
 * @return { bool } : true, valid ip address. false, invalid ip address.
 */
bool jcs_is_valid_ip_address(const char *ip_addr);

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
int jcs_create_server(const int port, bool nio, const int max_con);

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
int jcs_create_client(const char* hostname, const int port);

/**
 * @func jcs_accept
 * @brief Simple accept connection.
 * @param { int } serverfd : Server socket descriptor.
 * @return { int } : client socket descriptor.
 */
int jcs_accept(int serverfd);

#endif /* __JCS_NET_H__ */
