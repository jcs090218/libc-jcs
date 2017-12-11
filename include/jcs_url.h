#ifndef __JCS_URL_H__
/**
 * $File: jcs_url.h $
 * $Date: 2017-12-11 09:39:00 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright © 2017 by Shen, Jen-Chieh $
 */
#define __JCS_URL_H__


/**
 * @func jcs_simple_download_file_from_url
 * @brief Simply download a file using a URL.
 * @param { char } url : URL address.
 * @return { int } : curl code.
 */
int jcs_simple_download_file_from_url(const char *url, const char *output);

#endif /* __JCS_URL_H__ */
