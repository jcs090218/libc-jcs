#!/bin/bash
# ========================================================================
# $File: tar.sh $
# $Date: 2017-12-17 16:53:19 $
# $Revision: $
# $Creator: Jen-Chieh Shen $
# $Notice: See LICENSE.txt for modification and distribution information
#                   Copyright © 2017 by Shen, Jen-Chieh $
# ========================================================================


function jcs_tar_compress()
{
    PARAM_TAR_DEST=$1;  # output file
    PARAM_TAR_SRC=$2;   # tar this file/folder.

    tar -zcvf $PARAM_TAR_DEST $PARAM_TAR_SRC
}

function jcs_tar_extract()
{
    PARAM_TAR_SRC=$1;   # extract tar file.
    PARAM_TAR_DEST=$2;  # extract to this directory.

    if [ -z "$PARAM_TAR_DEST" ]
    then
        # extract to current directory.
        tar -zxvf $PARAM_TAR_SRC
    else
        # extract with output directory.
        tar -zxvf $PARAM_TAR_SRC -C $PARAM_TAR_DEST
    fi


}
