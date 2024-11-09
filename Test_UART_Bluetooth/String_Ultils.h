#ifndef _STRING_ULTILS_H_
#define _STRING_ULTILS_H_

#include "Base_Lib.h"

uint8 _equal_compare(char str1[], char str2[], uint8 cmp_size, uint8 offset){
    uint8 i;
    if(cmp_size < 1 ) return 0;
    REP(i, offset, cmp_size-1){
        if( str1[i] != str2[i] ) return 0;
    }
    return 1;
}

void _string_copy(char dest[], char scr[], uint8 cp_size, uint8 offset){
    uint8 i;
    if(cp_size < 1 ) return;
    REP(i, offset, cp_size-1)
        dest[i] = scr[i];
}

#endif