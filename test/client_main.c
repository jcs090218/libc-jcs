/**
 * $File: client_main.c $
 * $Date: 2017-12-06 14:28:32 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright © 2017 by Shen, Jen-Chieh $
 */

#include "../libc_jcs.h"


#define HOST_NAME "127.0.0.1"
#define PORT 8085

/**
 * @func main
 * @brief Program Entry Point.
 * @param { int } argc : argument count.
 * @param { char } argv : argument vector.
 * @return { int } : 0, exit success. -1, exit failure.
 */
int main(int argc, char *argv[]) {
    jcs_println("Start the client.");

    int client_fd = jcs_create_client(HOST_NAME, PORT);

    char buffer[128];
    char resp[100] = "clientack hello";

    /* Receive message from the server and print to screen */
    bzero(buffer, 128);
    recv(client_fd, buffer, sizeof(buffer), 0);
    printf("receive from server: %s\n", buffer);
    send(client_fd, resp, sizeof(resp), 0);

    /* --------------- */
    return 0;
}
