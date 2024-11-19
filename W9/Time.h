#ifndef _TIME_H_
#define _TIME_H_

#include "Utilities.h"

#ifndef _STRUCT_TIME_
#define _STRUCT_TIME_
    typedef struct TIME{
        uint8 DAY; // mon, tue, wed, thu, ...
        uint8 DATE;
        uint8 MONTH;
        uint8 YEAR;
        uint8 HOUR;
        uint8 MINUTE;
        uint8 SECOND;
    } TIME;
#endif

// uint8 time_copy(TIME* scr, TIME* dest, uint8 mask){
//     if((mask&0x1)!=0) dest->SECOND = scr->SECOND;
//     if((mask&0x2)!=0) dest->MINUTE = scr->MINUTE;
//     if((mask&0x4)!=0) dest->HOUR = scr->HOUR;
//     if((mask&0x8)!=0) dest->DATE = scr->DATE;
//     if((mask&0x10)!=0) dest->MONTH = scr->MONTH;
//     if((mask&0x20)!=0) dest->YEAR  = scr->YEAR;
// }

uint8 time_equal_cmp(TIME a, TIME b, uint8 mask){
    if( ((mask&0x1)!=0) && (a.SECOND!=b.SECOND) ) 
        return false;
    if( ((mask&0x2)!=0) && (a.MINUTE!=b.MINUTE) ) 
        return false;
    if( ((mask&0x4)!=0) && (a.HOUR!=b.HOUR) ) 
        return false;
    if( ((mask&0x8)!=0) && (a.DATE!=b.DATE) ) 
        return false;
    if( ((mask&0x10)!=0) && (a.MONTH!=b.MONTH) ) 
        return false;
    if( ((mask&0x20)!=0) && (a.YEAR!=b.YEAR) ) 
        return false;
    return true;
}


#endif