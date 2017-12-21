#!/bin/bash
# ========================================================================
# $File: progress_bar_5p_arrow.sh $
# $Date: 2017-12-14 18:09:33 $
# $Revision: $
# $Creator: Jen-Chieh Shen $
# $Notice: See LICENSE.txt for modification and distribution information
#                   Copyright © 2017 by Shen, Jen-Chieh $
# ========================================================================


#
# Description : print out executing progress
#
CURRENT_PROGRESS=0
function jcs_progress_bar_5p_arrow()
{
    PARAM_PROGRESS=$1;
    PARAM_PHASE=$2;
    PARAM_DELAY=$3;

    if [ -z "$PARAM_DELAY" ]; then
        PARAM_DELAY=0.05;
    fi

    if [ $CURRENT_PROGRESS -le 0 -a $PARAM_PROGRESS -ge 0 ]  ; then echo -ne "[                        ] (0%)  $PARAM_PHASE \r"  ; sleep $PARAM_DELAY; fi;
    if [ $CURRENT_PROGRESS -le 5 -a $PARAM_PROGRESS -ge 5 ]  ; then echo -ne "[>                       ] (5%)  $PARAM_PHASE \r"  ; sleep $PARAM_DELAY; fi;
    if [ $CURRENT_PROGRESS -le 10 -a $PARAM_PROGRESS -ge 10 ]; then echo -ne "[=>                      ] (10%) $PARAM_PHASE \r"  ; sleep $PARAM_DELAY; fi;
    if [ $CURRENT_PROGRESS -le 15 -a $PARAM_PROGRESS -ge 15 ]; then echo -ne "[==>                     ] (15%) $PARAM_PHASE \r"  ; sleep $PARAM_DELAY; fi;
    if [ $CURRENT_PROGRESS -le 20 -a $PARAM_PROGRESS -ge 20 ]; then echo -ne "[===>                    ] (20%) $PARAM_PHASE \r"  ; sleep $PARAM_DELAY; fi;
    if [ $CURRENT_PROGRESS -le 25 -a $PARAM_PROGRESS -ge 25 ]; then echo -ne "[====>                   ] (25%) $PARAM_PHASE \r"  ; sleep $PARAM_DELAY; fi;
    if [ $CURRENT_PROGRESS -le 30 -a $PARAM_PROGRESS -ge 30 ]; then echo -ne "[=====>                  ] (30%) $PARAM_PHASE \r"  ; sleep $PARAM_DELAY; fi;
    if [ $CURRENT_PROGRESS -le 35 -a $PARAM_PROGRESS -ge 35 ]; then echo -ne "[======>                 ] (35%) $PARAM_PHASE \r"  ; sleep $PARAM_DELAY; fi;
    if [ $CURRENT_PROGRESS -le 40 -a $PARAM_PROGRESS -ge 40 ]; then echo -ne "[=======>                ] (40%) $PARAM_PHASE \r"  ; sleep $PARAM_DELAY; fi;
    if [ $CURRENT_PROGRESS -le 45 -a $PARAM_PROGRESS -ge 45 ]; then echo -ne "[========>               ] (45%) $PARAM_PHASE \r"  ; sleep $PARAM_DELAY; fi;
    if [ $CURRENT_PROGRESS -le 50 -a $PARAM_PROGRESS -ge 50 ]; then echo -ne "[=========>              ] (50%) $PARAM_PHASE \r"  ; sleep $PARAM_DELAY; fi;
    if [ $CURRENT_PROGRESS -le 55 -a $PARAM_PROGRESS -ge 55 ]; then echo -ne "[==========>             ] (55%) $PARAM_PHASE \r"  ; sleep $PARAM_DELAY; fi;
    if [ $CURRENT_PROGRESS -le 60 -a $PARAM_PROGRESS -ge 60 ]; then echo -ne "[===========>            ] (60%) $PARAM_PHASE \r"  ; sleep $PARAM_DELAY; fi;
    if [ $CURRENT_PROGRESS -le 65 -a $PARAM_PROGRESS -ge 65 ]; then echo -ne "[============>           ] (65%) $PARAM_PHASE \r"  ; sleep $PARAM_DELAY; fi;
    if [ $CURRENT_PROGRESS -le 70 -a $PARAM_PROGRESS -ge 70 ]; then echo -ne "[==============>         ] (70%) $PARAM_PHASE \r"  ; sleep $PARAM_DELAY; fi;
    if [ $CURRENT_PROGRESS -le 75 -a $PARAM_PROGRESS -ge 75 ]; then echo -ne "[================>       ] (75%) $PARAM_PHASE \r"  ; sleep $PARAM_DELAY; fi;
    if [ $CURRENT_PROGRESS -le 80 -a $PARAM_PROGRESS -ge 80 ]; then echo -ne "[===================>    ] (80%) $PARAM_PHASE \r"  ; sleep $PARAM_DELAY; fi;
    if [ $CURRENT_PROGRESS -le 85 -a $PARAM_PROGRESS -ge 85 ]; then echo -ne "[======================> ] (90%) $PARAM_PHASE \r"  ; sleep $PARAM_DELAY; fi;
    if [ $CURRENT_PROGRESS -le 90 -a $PARAM_PROGRESS -ge 90 ]; then echo -ne "[=======================>] (100%) $PARAM_PHASE \r" ; sleep $PARAM_DELAY; fi;
    if [ $CURRENT_PROGRESS -le 100 -a $PARAM_PROGRESS -ge 100 ];then echo -ne 'Done!                                            \n' ; sleep $PARAM_DELAY; fi;

    CURRENT_PROGRESS=$PARAM_PROGRESS;
}
