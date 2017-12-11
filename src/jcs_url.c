/**
 * $File: jcs_url.c $
 * $Date: 2017-12-11 09:40:34 $
 * $Revision: $
 * $Creator: Jen-Chieh Shen $
 * $Notice: See LICENSE.txt for modification and distribution information
 *                   Copyright © 2017 by Shen, Jen-Chieh $
 */

#include "../libc_jcs.h"


/**
 * @func jcs_simple_download_filr_from_url
 * @brief Simply download a file from using a URL.
 * @param { char } url : URL address.
 * @return { int } : curl code.
 */
int jcs_simple_download_file_from_url(const char *url, const char *output) {
    CURL *curl;
    FILE *fp;
    CURLcode res;
    curl = curl_easy_init();

    if (curl) {
        fp = fopen(output, "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, jcs_write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);

        /* always cleanup */
        curl_easy_cleanup(curl);
        fclose(fp);
    }

    return (int)res;
}
