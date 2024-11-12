#ifndef _STRING_ULTILS_H_
#define _STRING_ULTILS_H_
#include "Utilities.h"

#define digit2char(x) ((x)+'0')
#define str_len(x) sizeof(x)
#define x1_digit(x) ((x)%10)
#define x10_digit(x) (((x)/10)%10)
#define x100_digit(x) (((x)/100)%10)
#define x1000_digit(x) (((x)/1000)%10)
#define _is_lower_case(x) ('a' <= (x) && (x) <= 'z')
#define _is_upper_case(x) ('A' <= (x) && (x) <= 'Z')
#define _not_digit(x) (!('0' <= (x) && (x) <= '9'))
#define _not_dollar_sign(x) (!((x)!='$'))
#define _not_equal_sign(x) (!((x)!='='))
#define _not_underscore(x) (!((x)=='_'))
#define _is_new_line(x) ((x)=='\n')
#define _is_carriage_return(x) ((x)=='\r')

uint8 _string_equal_compare(char str1[], char str2[], uint8 cmp_size, uint8 str2_offset){
    //Warning: str2_offset+cmp_size < size_of(str2)
    uint8 i;
    if(cmp_size < 1) return 0;
    REP(i, 0, cmp_size-1){
        if( str1[i] != str2[i+str2_offset] ) return 0;
    }
    return 1;
}

// void _string_to_upper_case(char str[], uint8 str_size){
//     if(str_size == 0) return;
//     while(str_size--){
//         if(_is_lower_case(str[str_size])) str[str_size]-= 'a'-'A';
//     }
// }

// void _string_to_lower_case(char str[], uint8 str_size){
//     if(str_size == 0) return;
// 	while(str_size--){
// 		if(_is_upper_case(str[str_size])) str[str_size]+= 'a'-'A';
// 	}
// }

// void _string_copy(char dest[], char scr[], uint8 cp_size, uint8 offset){
//     uint8 i;
//     if(cp_size < 1 ) return;
//     REP(i, offset, cp_size-1)
//         dest[i] = scr[i];
// }

uint8 _string_find_pattern(char pattern[], uint8 pat_size, char text[], uint8 txt_size, uint8 offset){
    // Note: pat_size <= txt_size < 256
    // Note: Return the first found position from range [offset, txt_size) 
    uint8 i;
    if(pat_size>txt_size) return txt_size;
    // This algorithm run with O-complexity: O(pat_size*txt_size)
    REP(i, offset, txt_size-pat_size){
        if( _string_equal_compare(pattern, text+i, pat_size, 0)){
            return i;
        }
    }
    return txt_size;
}

// void _string_num2text(uint32 num, char text[], uint8 text_size){
//     uint8 i;
//     REP(i, 0, text_size-1){
//         text[(text_size-1)-i] = num%10 + '0';
//         num/=10;
//     }
//     text[text_size]='\0';
// }

#endif