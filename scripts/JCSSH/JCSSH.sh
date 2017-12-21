#!/bin/sh
# ========================================================================
# $File: JCSSH.sh $
# $Date: 2017-12-15 20:29:55 $
# $Revision: $
# $Creator: Jen-Chieh Shen $
# $Notice: See LICENSE.txt for modification and distribution information
#                   Copyright © 2017 by Shen, Jen-Chieh $
# ========================================================================


# Include all JCSSH files.
DIR="${BASH_SOURCE%/*}"
if [[ ! -d "$DIR" ]]; then DIR="$PWD"; fi
# compress
. "$DIR/src/compress/tar.sh"
# progress_bar
. "$DIR/src/progress_bar/progress_bar_1p.sh"
. "$DIR/src/progress_bar/progress_bar_5p.sh"
. "$DIR/src/progress_bar/progress_bar_1p_arrow.sh"
. "$DIR/src/progress_bar/progress_bar_5p_arrow.sh"
