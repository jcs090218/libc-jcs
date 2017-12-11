#ifndef __LIBC_JCS_H__
/**
 * $File: libc_jcs.h $
 * $Date: 2017-12-04 08:07:37 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright © 2017 by Shen, Jen-Chieh $
 */
#define __LIBC_JCS_H__

/* Sys */
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Network */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

/* URL */
#include <curl/curl.h>

/* Database */
#include <netdb.h>

/* Standard */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
#include <signal.h>
#include <stddef.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>

/* Others */
#include <dirent.h>


/* Core */
#include "./include/jcs_defines.h"
#include "./include/jcs_color.h"
#include "./include/jcs_print.h"
#include "./include/jcs_debug.h"
#include "./include/jcs_dir.h"
#include "./include/jcs_string.h"
#include "./include/jcs_file.h"
#include "./include/jcs_net.h"
#include "./include/jcs_url.h"
#include "./include/jcs_util.h"

#endif /* __LIBC_JCS_H__ */
