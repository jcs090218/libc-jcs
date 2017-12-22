/**
 * $File: server_main.c $
 * $Date: 2017-12-06 14:29:00 $
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
    jcs_println("Start the server.");

    int server_fd = jcs_create_server(PORT, TCP, false, 20);

    char buffer[20] = "Hi client!";
    char buffer1[100];

    while (true) {
        int clientfd;

        /* Wait and Accept connection */
        clientfd = jcs_accept(server_fd);

        /* Send message */
        send(clientfd, buffer, sizeof(buffer), 0);

        /* receive from client */
        int res = recv(clientfd, buffer1, sizeof(buffer1), 0);
        printf("receive from client: %s, %d bytes\n", buffer1, res);

        /* close(client) */
        close(clientfd);
    }

    close(server_fd);

    /* --------------- */
    return 0;
}
