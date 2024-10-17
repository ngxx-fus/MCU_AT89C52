                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ISO C Compiler
                                      3 ; Version 4.4.4 #15036 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module main
                                      6 	
                                      7 	.optsdcc -mmcs51 --model-small
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _DEV_CTL_PARM_2
                                     12 	.globl _led7seg_disp_PARM_2
                                     13 	.globl _DIGIT_CODE
                                     14 	.globl _main
                                     15 	.globl _main_intial
                                     16 	.globl _sys_time_disp
                                     17 	.globl _change_mode
                                     18 	.globl _SHOW_MODE
                                     19 	.globl _DEV_CTL
                                     20 	.globl _SET_ON_OFF
                                     21 	.globl _SET_TIMER
                                     22 	.globl _YES_NO
                                     23 	.globl _CODE2NUM
                                     24 	.globl _External0_Interrupt
                                     25 	.globl _Timer0_OverFlow_Interrupt
                                     26 	.globl _IR_Reading_Initial
                                     27 	.globl _read_extracted_frame
                                     28 	.globl _new_dataframe
                                     29 	.globl _Get_BTN_MATRIX_2
                                     30 	.globl _Get_BTN_MATRIX
                                     31 	.globl _Col_Read
                                     32 	.globl _Row_Write
                                     33 	.globl _Disp8leds7seg
                                     34 	.globl _led7seg_disp
                                     35 	.globl _ds1302_initial
                                     36 	.globl _ds1302_write_time
                                     37 	.globl _ds1302_read_time
                                     38 	.globl _time_equal
                                     39 	.globl _ThreeWiresProtocol_Initial
                                     40 	.globl _single_byte_read
                                     41 	.globl _single_byte_write
                                     42 	.globl _GLOBAL_INT
                                     43 	.globl _TIMER0_CTL
                                     44 	.globl _eINT1_CTL
                                     45 	.globl _eINT0_CTL
                                     46 	.globl _delay_ms
                                     47 	.globl _DEV2
                                     48 	.globl _DEV1
                                     49 	.globl _DEV0
                                     50 	.globl _FrameExtracted_LED
                                     51 	.globl _COL3
                                     52 	.globl _COL2
                                     53 	.globl _COL1
                                     54 	.globl _COL0
                                     55 	.globl _ROW3
                                     56 	.globl _ROW2
                                     57 	.globl _ROW1
                                     58 	.globl _ROW0
                                     59 	.globl _GND2
                                     60 	.globl _GND1
                                     61 	.globl _GND0
                                     62 	.globl _IO
                                     63 	.globl _SCLK
                                     64 	.globl _CE
                                     65 	.globl _CY
                                     66 	.globl _AC
                                     67 	.globl _F0
                                     68 	.globl _RS1
                                     69 	.globl _RS0
                                     70 	.globl _OV
                                     71 	.globl _FL
                                     72 	.globl _P
                                     73 	.globl _TF2
                                     74 	.globl _EXF2
                                     75 	.globl _RCLK
                                     76 	.globl _TCLK
                                     77 	.globl _EXEN2
                                     78 	.globl _TR2
                                     79 	.globl _C_T2
                                     80 	.globl _CP_RL2
                                     81 	.globl _T2CON_7
                                     82 	.globl _T2CON_6
                                     83 	.globl _T2CON_5
                                     84 	.globl _T2CON_4
                                     85 	.globl _T2CON_3
                                     86 	.globl _T2CON_2
                                     87 	.globl _T2CON_1
                                     88 	.globl _T2CON_0
                                     89 	.globl _PT2
                                     90 	.globl _PS
                                     91 	.globl _PT1
                                     92 	.globl _PX1
                                     93 	.globl _PT0
                                     94 	.globl _PX0
                                     95 	.globl _RD
                                     96 	.globl _WR
                                     97 	.globl _T1
                                     98 	.globl _T0
                                     99 	.globl _INT1
                                    100 	.globl _INT0
                                    101 	.globl _TXD
                                    102 	.globl _RXD
                                    103 	.globl _P3_7
                                    104 	.globl _P3_6
                                    105 	.globl _P3_5
                                    106 	.globl _P3_4
                                    107 	.globl _P3_3
                                    108 	.globl _P3_2
                                    109 	.globl _P3_1
                                    110 	.globl _P3_0
                                    111 	.globl _EA
                                    112 	.globl _ET2
                                    113 	.globl _ES
                                    114 	.globl _ET1
                                    115 	.globl _EX1
                                    116 	.globl _ET0
                                    117 	.globl _EX0
                                    118 	.globl _P2_7
                                    119 	.globl _P2_6
                                    120 	.globl _P2_5
                                    121 	.globl _P2_4
                                    122 	.globl _P2_3
                                    123 	.globl _P2_2
                                    124 	.globl _P2_1
                                    125 	.globl _P2_0
                                    126 	.globl _SM0
                                    127 	.globl _SM1
                                    128 	.globl _SM2
                                    129 	.globl _REN
                                    130 	.globl _TB8
                                    131 	.globl _RB8
                                    132 	.globl _TI
                                    133 	.globl _RI
                                    134 	.globl _T2EX
                                    135 	.globl _T2
                                    136 	.globl _P1_7
                                    137 	.globl _P1_6
                                    138 	.globl _P1_5
                                    139 	.globl _P1_4
                                    140 	.globl _P1_3
                                    141 	.globl _P1_2
                                    142 	.globl _P1_1
                                    143 	.globl _P1_0
                                    144 	.globl _TF1
                                    145 	.globl _TR1
                                    146 	.globl _TF0
                                    147 	.globl _TR0
                                    148 	.globl _IE1
                                    149 	.globl _IT1
                                    150 	.globl _IE0
                                    151 	.globl _IT0
                                    152 	.globl _P0_7
                                    153 	.globl _P0_6
                                    154 	.globl _P0_5
                                    155 	.globl _P0_4
                                    156 	.globl _P0_3
                                    157 	.globl _P0_2
                                    158 	.globl _P0_1
                                    159 	.globl _P0_0
                                    160 	.globl _B
                                    161 	.globl _A
                                    162 	.globl _ACC
                                    163 	.globl _PSW
                                    164 	.globl _TH2
                                    165 	.globl _TL2
                                    166 	.globl _RCAP2H
                                    167 	.globl _RCAP2L
                                    168 	.globl _T2MOD
                                    169 	.globl _T2CON
                                    170 	.globl _IP
                                    171 	.globl _P3
                                    172 	.globl _IE
                                    173 	.globl _P2
                                    174 	.globl _SBUF
                                    175 	.globl _SCON
                                    176 	.globl _P1
                                    177 	.globl _TH1
                                    178 	.globl _TH0
                                    179 	.globl _TL1
                                    180 	.globl _TL0
                                    181 	.globl _TMOD
                                    182 	.globl _TCON
                                    183 	.globl _PCON
                                    184 	.globl _DPH
                                    185 	.globl _DPL
                                    186 	.globl _SP
                                    187 	.globl _P0
                                    188 	.globl _SET_ON_OFF_PARM_2
                                    189 	.globl _time_off
                                    190 	.globl _time_on
                                    191 	.globl _sys_time
                                    192 	.globl _DEV_ENABLE
                                    193 	.globl _MANUAL_MODE
                                    194 	.globl _CURRENT_MODE
                                    195 	.globl _negedge_count
                                    196 	.globl _ms_count
                                    197 	.globl _buffer
                                    198 	.globl _data_frame
                                    199 	.globl _BTN_MATRIX
                                    200 	.globl _LED
                                    201 	.globl _ds1302_write_time_PARM_2
                                    202 	.globl _ds1302_read_time_PARM_2
                                    203 	.globl _time_equal_PARM_2
                                    204 	.globl _time_equal_PARM_1
                                    205 	.globl _single_byte_write_PARM_2
                                    206 	.globl _READ_T
                                    207 	.globl _IDLE_T
                                    208 	.globl _T_PEAK
                                    209 ;--------------------------------------------------------
                                    210 ; special function registers
                                    211 ;--------------------------------------------------------
                                    212 	.area RSEG    (ABS,DATA)
      000000                        213 	.org 0x0000
                           000080   214 _P0	=	0x0080
                           000081   215 _SP	=	0x0081
                           000082   216 _DPL	=	0x0082
                           000083   217 _DPH	=	0x0083
                           000087   218 _PCON	=	0x0087
                           000088   219 _TCON	=	0x0088
                           000089   220 _TMOD	=	0x0089
                           00008A   221 _TL0	=	0x008a
                           00008B   222 _TL1	=	0x008b
                           00008C   223 _TH0	=	0x008c
                           00008D   224 _TH1	=	0x008d
                           000090   225 _P1	=	0x0090
                           000098   226 _SCON	=	0x0098
                           000099   227 _SBUF	=	0x0099
                           0000A0   228 _P2	=	0x00a0
                           0000A8   229 _IE	=	0x00a8
                           0000B0   230 _P3	=	0x00b0
                           0000B8   231 _IP	=	0x00b8
                           0000C8   232 _T2CON	=	0x00c8
                           0000C9   233 _T2MOD	=	0x00c9
                           0000CA   234 _RCAP2L	=	0x00ca
                           0000CB   235 _RCAP2H	=	0x00cb
                           0000CC   236 _TL2	=	0x00cc
                           0000CD   237 _TH2	=	0x00cd
                           0000D0   238 _PSW	=	0x00d0
                           0000E0   239 _ACC	=	0x00e0
                           0000E0   240 _A	=	0x00e0
                           0000F0   241 _B	=	0x00f0
                                    242 ;--------------------------------------------------------
                                    243 ; special function bits
                                    244 ;--------------------------------------------------------
                                    245 	.area RSEG    (ABS,DATA)
      000000                        246 	.org 0x0000
                           000080   247 _P0_0	=	0x0080
                           000081   248 _P0_1	=	0x0081
                           000082   249 _P0_2	=	0x0082
                           000083   250 _P0_3	=	0x0083
                           000084   251 _P0_4	=	0x0084
                           000085   252 _P0_5	=	0x0085
                           000086   253 _P0_6	=	0x0086
                           000087   254 _P0_7	=	0x0087
                           000088   255 _IT0	=	0x0088
                           000089   256 _IE0	=	0x0089
                           00008A   257 _IT1	=	0x008a
                           00008B   258 _IE1	=	0x008b
                           00008C   259 _TR0	=	0x008c
                           00008D   260 _TF0	=	0x008d
                           00008E   261 _TR1	=	0x008e
                           00008F   262 _TF1	=	0x008f
                           000090   263 _P1_0	=	0x0090
                           000091   264 _P1_1	=	0x0091
                           000092   265 _P1_2	=	0x0092
                           000093   266 _P1_3	=	0x0093
                           000094   267 _P1_4	=	0x0094
                           000095   268 _P1_5	=	0x0095
                           000096   269 _P1_6	=	0x0096
                           000097   270 _P1_7	=	0x0097
                           000090   271 _T2	=	0x0090
                           000091   272 _T2EX	=	0x0091
                           000098   273 _RI	=	0x0098
                           000099   274 _TI	=	0x0099
                           00009A   275 _RB8	=	0x009a
                           00009B   276 _TB8	=	0x009b
                           00009C   277 _REN	=	0x009c
                           00009D   278 _SM2	=	0x009d
                           00009E   279 _SM1	=	0x009e
                           00009F   280 _SM0	=	0x009f
                           0000A0   281 _P2_0	=	0x00a0
                           0000A1   282 _P2_1	=	0x00a1
                           0000A2   283 _P2_2	=	0x00a2
                           0000A3   284 _P2_3	=	0x00a3
                           0000A4   285 _P2_4	=	0x00a4
                           0000A5   286 _P2_5	=	0x00a5
                           0000A6   287 _P2_6	=	0x00a6
                           0000A7   288 _P2_7	=	0x00a7
                           0000A8   289 _EX0	=	0x00a8
                           0000A9   290 _ET0	=	0x00a9
                           0000AA   291 _EX1	=	0x00aa
                           0000AB   292 _ET1	=	0x00ab
                           0000AC   293 _ES	=	0x00ac
                           0000AD   294 _ET2	=	0x00ad
                           0000AF   295 _EA	=	0x00af
                           0000B0   296 _P3_0	=	0x00b0
                           0000B1   297 _P3_1	=	0x00b1
                           0000B2   298 _P3_2	=	0x00b2
                           0000B3   299 _P3_3	=	0x00b3
                           0000B4   300 _P3_4	=	0x00b4
                           0000B5   301 _P3_5	=	0x00b5
                           0000B6   302 _P3_6	=	0x00b6
                           0000B7   303 _P3_7	=	0x00b7
                           0000B0   304 _RXD	=	0x00b0
                           0000B1   305 _TXD	=	0x00b1
                           0000B2   306 _INT0	=	0x00b2
                           0000B3   307 _INT1	=	0x00b3
                           0000B4   308 _T0	=	0x00b4
                           0000B5   309 _T1	=	0x00b5
                           0000B6   310 _WR	=	0x00b6
                           0000B7   311 _RD	=	0x00b7
                           0000B8   312 _PX0	=	0x00b8
                           0000B9   313 _PT0	=	0x00b9
                           0000BA   314 _PX1	=	0x00ba
                           0000BB   315 _PT1	=	0x00bb
                           0000BC   316 _PS	=	0x00bc
                           0000BD   317 _PT2	=	0x00bd
                           0000C8   318 _T2CON_0	=	0x00c8
                           0000C9   319 _T2CON_1	=	0x00c9
                           0000CA   320 _T2CON_2	=	0x00ca
                           0000CB   321 _T2CON_3	=	0x00cb
                           0000CC   322 _T2CON_4	=	0x00cc
                           0000CD   323 _T2CON_5	=	0x00cd
                           0000CE   324 _T2CON_6	=	0x00ce
                           0000CF   325 _T2CON_7	=	0x00cf
                           0000C8   326 _CP_RL2	=	0x00c8
                           0000C9   327 _C_T2	=	0x00c9
                           0000CA   328 _TR2	=	0x00ca
                           0000CB   329 _EXEN2	=	0x00cb
                           0000CC   330 _TCLK	=	0x00cc
                           0000CD   331 _RCLK	=	0x00cd
                           0000CE   332 _EXF2	=	0x00ce
                           0000CF   333 _TF2	=	0x00cf
                           0000D0   334 _P	=	0x00d0
                           0000D1   335 _FL	=	0x00d1
                           0000D2   336 _OV	=	0x00d2
                           0000D3   337 _RS0	=	0x00d3
                           0000D4   338 _RS1	=	0x00d4
                           0000D5   339 _F0	=	0x00d5
                           0000D6   340 _AC	=	0x00d6
                           0000D7   341 _CY	=	0x00d7
                           0000B5   342 _CE	=	0x00b5
                           0000B6   343 _SCLK	=	0x00b6
                           0000B4   344 _IO	=	0x00b4
                           0000A2   345 _GND0	=	0x00a2
                           0000A3   346 _GND1	=	0x00a3
                           0000A4   347 _GND2	=	0x00a4
                           000097   348 _ROW0	=	0x0097
                           000096   349 _ROW1	=	0x0096
                           000095   350 _ROW2	=	0x0095
                           000094   351 _ROW3	=	0x0094
                           000093   352 _COL0	=	0x0093
                           000092   353 _COL1	=	0x0092
                           000091   354 _COL2	=	0x0091
                           000090   355 _COL3	=	0x0090
                           0000A0   356 _FrameExtracted_LED	=	0x00a0
                           000005   357 _DEV0	=	0x0005
                           000006   358 _DEV1	=	0x0006
                           000007   359 _DEV2	=	0x0007
                                    360 ;--------------------------------------------------------
                                    361 ; overlayable register banks
                                    362 ;--------------------------------------------------------
                                    363 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        364 	.ds 8
                                    365 ;--------------------------------------------------------
                                    366 ; overlayable bit register bank
                                    367 ;--------------------------------------------------------
                                    368 	.area BIT_BANK	(REL,OVR,DATA)
      000021                        369 bits:
      000021                        370 	.ds 1
                           008000   371 	b0 = bits[0]
                           008100   372 	b1 = bits[1]
                           008200   373 	b2 = bits[2]
                           008300   374 	b3 = bits[3]
                           008400   375 	b4 = bits[4]
                           008500   376 	b5 = bits[5]
                           008600   377 	b6 = bits[6]
                           008700   378 	b7 = bits[7]
                                    379 ;--------------------------------------------------------
                                    380 ; internal ram data
                                    381 ;--------------------------------------------------------
                                    382 	.area DSEG    (DATA)
      000022                        383 _T_PEAK::
      000022                        384 	.ds 1
      000023                        385 _IDLE_T::
      000023                        386 	.ds 1
      000024                        387 _READ_T::
      000024                        388 	.ds 1
      000025                        389 _single_byte_write_PARM_2:
      000025                        390 	.ds 1
      000026                        391 _time_equal_PARM_1:
      000026                        392 	.ds 7
      00002D                        393 _time_equal_PARM_2:
      00002D                        394 	.ds 7
      000034                        395 _ds1302_read_time_PARM_2:
      000034                        396 	.ds 1
      000035                        397 _ds1302_read_time_time_10000_37:
      000035                        398 	.ds 3
      000038                        399 _ds1302_read_time_AM_PM_10000_38:
      000038                        400 	.ds 1
      000039                        401 _ds1302_write_time_PARM_2:
      000039                        402 	.ds 1
      00003A                        403 _LED::
      00003A                        404 	.ds 8
      000042                        405 _BTN_MATRIX::
      000042                        406 	.ds 2
      000044                        407 _data_frame::
      000044                        408 	.ds 2
      000046                        409 _buffer::
      000046                        410 	.ds 2
      000048                        411 _ms_count::
      000048                        412 	.ds 1
      000049                        413 _negedge_count::
      000049                        414 	.ds 1
      00004A                        415 _CURRENT_MODE::
      00004A                        416 	.ds 1
      00004B                        417 _MANUAL_MODE::
      00004B                        418 	.ds 1
      00004C                        419 _DEV_ENABLE::
      00004C                        420 	.ds 1
      00004D                        421 _sys_time::
      00004D                        422 	.ds 7
      000054                        423 _time_on::
      000054                        424 	.ds 7
      00005B                        425 _time_off::
      00005B                        426 	.ds 7
      000062                        427 _SET_TIMER_t_10000_99:
      000062                        428 	.ds 3
      000065                        429 _SET_TIMER_tmp_10000_100:
      000065                        430 	.ds 7
      00006C                        431 _SET_ON_OFF_PARM_2:
      00006C                        432 	.ds 1
      00006D                        433 _SET_ON_OFF_val_10000_104:
      00006D                        434 	.ds 3
      000070                        435 _SET_ON_OFF_sloc0_1_0:
      000070                        436 	.ds 2
      000072                        437 _change_mode_STATE_10000_115:
      000072                        438 	.ds 1
                                    439 ;--------------------------------------------------------
                                    440 ; overlayable items in internal ram
                                    441 ;--------------------------------------------------------
                                    442 	.area	OSEG    (OVR,DATA)
                                    443 	.area	OSEG    (OVR,DATA)
                                    444 	.area	OSEG    (OVR,DATA)
                                    445 	.area	OSEG    (OVR,DATA)
                                    446 	.area	OSEG    (OVR,DATA)
                                    447 	.area	OSEG    (OVR,DATA)
      000008                        448 _led7seg_disp_PARM_2:
      000008                        449 	.ds 1
                                    450 	.area	OSEG    (OVR,DATA)
                                    451 	.area	OSEG    (OVR,DATA)
                                    452 	.area	OSEG    (OVR,DATA)
                                    453 	.area	OSEG    (OVR,DATA)
                                    454 	.area	OSEG    (OVR,DATA)
      000008                        455 _DEV_CTL_PARM_2:
      000008                        456 	.ds 1
                                    457 ;--------------------------------------------------------
                                    458 ; Stack segment in internal ram
                                    459 ;--------------------------------------------------------
                                    460 	.area SSEG
      000073                        461 __start__stack:
      000073                        462 	.ds	1
                                    463 
                                    464 ;--------------------------------------------------------
                                    465 ; indirectly addressable internal ram data
                                    466 ;--------------------------------------------------------
                                    467 	.area ISEG    (DATA)
                                    468 ;--------------------------------------------------------
                                    469 ; absolute internal ram data
                                    470 ;--------------------------------------------------------
                                    471 	.area IABS    (ABS,DATA)
                                    472 	.area IABS    (ABS,DATA)
                                    473 ;--------------------------------------------------------
                                    474 ; bit data
                                    475 ;--------------------------------------------------------
                                    476 	.area BSEG    (BIT)
      000000                        477 _time_equal_sloc0_1_0:
      000000                        478 	.ds 1
                                    479 ;--------------------------------------------------------
                                    480 ; paged external ram data
                                    481 ;--------------------------------------------------------
                                    482 	.area PSEG    (PAG,XDATA)
                                    483 ;--------------------------------------------------------
                                    484 ; uninitialized external ram data
                                    485 ;--------------------------------------------------------
                                    486 	.area XSEG    (XDATA)
                                    487 ;--------------------------------------------------------
                                    488 ; absolute external ram data
                                    489 ;--------------------------------------------------------
                                    490 	.area XABS    (ABS,XDATA)
                                    491 ;--------------------------------------------------------
                                    492 ; initialized external ram data
                                    493 ;--------------------------------------------------------
                                    494 	.area XISEG   (XDATA)
                                    495 	.area HOME    (CODE)
                                    496 	.area GSINIT0 (CODE)
                                    497 	.area GSINIT1 (CODE)
                                    498 	.area GSINIT2 (CODE)
                                    499 	.area GSINIT3 (CODE)
                                    500 	.area GSINIT4 (CODE)
                                    501 	.area GSINIT5 (CODE)
                                    502 	.area GSINIT  (CODE)
                                    503 	.area GSFINAL (CODE)
                                    504 	.area CSEG    (CODE)
                                    505 ;--------------------------------------------------------
                                    506 ; interrupt vector
                                    507 ;--------------------------------------------------------
                                    508 	.area HOME    (CODE)
      000000                        509 __interrupt_vect:
      000000 02 00 7E         [24]  510 	ljmp	__sdcc_gsinit_startup
      000003 02 0A 01         [24]  511 	ljmp	_External0_Interrupt
      000006                        512 	.ds	5
      00000B 02 09 B4         [24]  513 	ljmp	_Timer0_OverFlow_Interrupt
                                    514 ; restartable atomic support routines
      00000E                        515 	.ds	2
      000010                        516 sdcc_atomic_exchange_rollback_start::
      000010 00               [12]  517 	nop
      000011 00               [12]  518 	nop
      000012                        519 sdcc_atomic_exchange_pdata_impl:
      000012 E2               [24]  520 	movx	a, @r0
      000013 FB               [12]  521 	mov	r3, a
      000014 EA               [12]  522 	mov	a, r2
      000015 F2               [24]  523 	movx	@r0, a
      000016 80 2C            [24]  524 	sjmp	sdcc_atomic_exchange_exit
      000018 00               [12]  525 	nop
      000019 00               [12]  526 	nop
      00001A                        527 sdcc_atomic_exchange_xdata_impl:
      00001A E0               [24]  528 	movx	a, @dptr
      00001B FB               [12]  529 	mov	r3, a
      00001C EA               [12]  530 	mov	a, r2
      00001D F0               [24]  531 	movx	@dptr, a
      00001E 80 24            [24]  532 	sjmp	sdcc_atomic_exchange_exit
      000020                        533 sdcc_atomic_compare_exchange_idata_impl:
      000020 E6               [12]  534 	mov	a, @r0
      000021 B5 02 02         [24]  535 	cjne	a, ar2, .+#5
      000024 EB               [12]  536 	mov	a, r3
      000025 F6               [12]  537 	mov	@r0, a
      000026 22               [24]  538 	ret
      000027 00               [12]  539 	nop
      000028                        540 sdcc_atomic_compare_exchange_pdata_impl:
      000028 E2               [24]  541 	movx	a, @r0
      000029 B5 02 02         [24]  542 	cjne	a, ar2, .+#5
      00002C EB               [12]  543 	mov	a, r3
      00002D F2               [24]  544 	movx	@r0, a
      00002E 22               [24]  545 	ret
      00002F 00               [12]  546 	nop
      000030                        547 sdcc_atomic_compare_exchange_xdata_impl:
      000030 E0               [24]  548 	movx	a, @dptr
      000031 B5 02 02         [24]  549 	cjne	a, ar2, .+#5
      000034 EB               [12]  550 	mov	a, r3
      000035 F0               [24]  551 	movx	@dptr, a
      000036 22               [24]  552 	ret
      000037                        553 sdcc_atomic_exchange_rollback_end::
                                    554 
      000037                        555 sdcc_atomic_exchange_gptr_impl::
      000037 30 F6 E0         [24]  556 	jnb	b.6, sdcc_atomic_exchange_xdata_impl
      00003A A8 82            [24]  557 	mov	r0, dpl
      00003C 20 F5 D3         [24]  558 	jb	b.5, sdcc_atomic_exchange_pdata_impl
      00003F                        559 sdcc_atomic_exchange_idata_impl:
      00003F EA               [12]  560 	mov	a, r2
      000040 C6               [12]  561 	xch	a, @r0
      000041 F5 82            [12]  562 	mov	dpl, a
      000043 22               [24]  563 	ret
      000044                        564 sdcc_atomic_exchange_exit:
      000044 8B 82            [24]  565 	mov	dpl, r3
      000046 22               [24]  566 	ret
      000047                        567 sdcc_atomic_compare_exchange_gptr_impl::
      000047 30 F6 E6         [24]  568 	jnb	b.6, sdcc_atomic_compare_exchange_xdata_impl
      00004A A8 82            [24]  569 	mov	r0, dpl
      00004C 20 F5 D9         [24]  570 	jb	b.5, sdcc_atomic_compare_exchange_pdata_impl
      00004F 80 CF            [24]  571 	sjmp	sdcc_atomic_compare_exchange_idata_impl
                                    572 ;--------------------------------------------------------
                                    573 ; global & static initialisations
                                    574 ;--------------------------------------------------------
                                    575 	.area HOME    (CODE)
                                    576 	.area GSINIT  (CODE)
                                    577 	.area GSFINAL (CODE)
                                    578 	.area GSINIT  (CODE)
                                    579 	.globl __sdcc_gsinit_startup
                                    580 	.globl __sdcc_program_startup
                                    581 	.globl __start__stack
                                    582 	.globl __mcs51_genXINIT
                                    583 	.globl __mcs51_genXRAMCLEAR
                                    584 	.globl __mcs51_genRAMCLEAR
                                    585 ;	ThreeWiresProtocol.h:23: uint8 T_PEAK = 0;
      0000D7 75 22 00         [24]  586 	mov	_T_PEAK,#0x00
                                    587 ;	ThreeWiresProtocol.h:24: uint8 IDLE_T = 0;
      0000DA 75 23 00         [24]  588 	mov	_IDLE_T,#0x00
                                    589 ;	ThreeWiresProtocol.h:25: uint8 READ_T = 0;
      0000DD 75 24 00         [24]  590 	mov	_READ_T,#0x00
                                    591 ;	LED7Seg_OnKit.h:26: uint8 LED[8] = {0, 0, 0, 0, 0, 0, 0, 0};
      0000E0 75 3A 00         [24]  592 	mov	_LED,#0x00
      0000E3 75 3B 00         [24]  593 	mov	(_LED + 0x0001),#0x00
      0000E6 75 3C 00         [24]  594 	mov	(_LED + 0x0002),#0x00
      0000E9 75 3D 00         [24]  595 	mov	(_LED + 0x0003),#0x00
      0000EC 75 3E 00         [24]  596 	mov	(_LED + 0x0004),#0x00
      0000EF 75 3F 00         [24]  597 	mov	(_LED + 0x0005),#0x00
      0000F2 75 40 00         [24]  598 	mov	(_LED + 0x0006),#0x00
      0000F5 75 41 00         [24]  599 	mov	(_LED + 0x0007),#0x00
                                    600 ;	Matrix_Button.h:22: uint32 BTN_MATRIX = 0;
      0000F8 E4               [12]  601 	clr	a
      0000F9 F5 42            [12]  602 	mov	_BTN_MATRIX,a
      0000FB F5 43            [12]  603 	mov	(_BTN_MATRIX + 1),a
                                    604 ;	IR_Reading.h:55: uint32 data_frame = 0;
      0000FD F5 44            [12]  605 	mov	_data_frame,a
      0000FF F5 45            [12]  606 	mov	(_data_frame + 1),a
                                    607 ;	IR_Reading.h:57: uint32 buffer = 0;
      000101 F5 46            [12]  608 	mov	_buffer,a
      000103 F5 47            [12]  609 	mov	(_buffer + 1),a
                                    610 ;	IR_Reading.h:59: uint8 ms_count = 0;
      000105 F5 48            [12]  611 	mov	_ms_count,a
                                    612 ;	IR_Reading.h:61: int8 negedge_count = 0;
      000107 F5 49            [12]  613 	mov	_negedge_count,a
                                    614 ;	main.h:21: uint8 CURRENT_MODE = DEV_0_CTL;
      000109 75 4A 02         [24]  615 	mov	_CURRENT_MODE,#0x02
                                    616 ;	main.h:23: uint8 MANUAL_MODE = 0;
      00010C F5 4B            [12]  617 	mov	_MANUAL_MODE,a
                                    618 ;	main.h:30: uint8 DEV_ENABLE = 0;
      00010E F5 4C            [12]  619 	mov	_DEV_ENABLE,a
                                    620 ;	main.h:32: TIME sys_time = {0, 0, 0, 0, 0, 0, 0};
      000110 F5 4D            [12]  621 	mov	_sys_time,a
      000112 F5 4E            [12]  622 	mov	(_sys_time + 0x0001),a
      000114 F5 4F            [12]  623 	mov	(_sys_time + 0x0002),a
      000116 F5 50            [12]  624 	mov	(_sys_time + 0x0003),a
      000118 F5 51            [12]  625 	mov	(_sys_time + 0x0004),a
      00011A F5 52            [12]  626 	mov	(_sys_time + 0x0005),a
      00011C F5 53            [12]  627 	mov	(_sys_time + 0x0006),a
                                    628 ;	main.h:33: TIME time_on = {0, 0, 0, 0, 0, 0, 0};
      00011E F5 54            [12]  629 	mov	_time_on,a
      000120 F5 55            [12]  630 	mov	(_time_on + 0x0001),a
      000122 F5 56            [12]  631 	mov	(_time_on + 0x0002),a
      000124 F5 57            [12]  632 	mov	(_time_on + 0x0003),a
      000126 F5 58            [12]  633 	mov	(_time_on + 0x0004),a
      000128 F5 59            [12]  634 	mov	(_time_on + 0x0005),a
      00012A F5 5A            [12]  635 	mov	(_time_on + 0x0006),a
                                    636 ;	main.h:34: TIME time_off = {0, 0, 0, 0, 0, 0, 0};
      00012C F5 5B            [12]  637 	mov	_time_off,a
      00012E F5 5C            [12]  638 	mov	(_time_off + 0x0001),a
      000130 F5 5D            [12]  639 	mov	(_time_off + 0x0002),a
      000132 F5 5E            [12]  640 	mov	(_time_off + 0x0003),a
      000134 F5 5F            [12]  641 	mov	(_time_off + 0x0004),a
      000136 F5 60            [12]  642 	mov	(_time_off + 0x0005),a
      000138 F5 61            [12]  643 	mov	(_time_off + 0x0006),a
                                    644 	.area GSFINAL (CODE)
      00013A 02 00 51         [24]  645 	ljmp	__sdcc_program_startup
                                    646 ;--------------------------------------------------------
                                    647 ; Home
                                    648 ;--------------------------------------------------------
                                    649 	.area HOME    (CODE)
                                    650 	.area HOME    (CODE)
      000051                        651 __sdcc_program_startup:
      000051 02 10 04         [24]  652 	ljmp	_main
                                    653 ;	return from main will return to caller
                                    654 ;--------------------------------------------------------
                                    655 ; code
                                    656 ;--------------------------------------------------------
                                    657 	.area CSEG    (CODE)
                                    658 ;------------------------------------------------------------
                                    659 ;Allocation info for local variables in function 'delay_us'
                                    660 ;------------------------------------------------------------
                                    661 ;us            Allocated to registers r6 r7 
                                    662 ;i             Allocated to registers r4 r5 
                                    663 ;------------------------------------------------------------
                                    664 ;	Base_Lib.h:60: static void delay_us(uint32 us){
                                    665 ;	-----------------------------------------
                                    666 ;	 function delay_us
                                    667 ;	-----------------------------------------
      00013D                        668 _delay_us:
                           000007   669 	ar7 = 0x07
                           000006   670 	ar6 = 0x06
                           000005   671 	ar5 = 0x05
                           000004   672 	ar4 = 0x04
                           000003   673 	ar3 = 0x03
                           000002   674 	ar2 = 0x02
                           000001   675 	ar1 = 0x01
                           000000   676 	ar0 = 0x00
      00013D AE 82            [24]  677 	mov	r6, dpl
      00013F AF 83            [24]  678 	mov	r7, dph
                                    679 ;	Base_Lib.h:62: for(i = 0; i < us; i = i + 1){
      000141 7C 00            [12]  680 	mov	r4,#0x00
      000143 7D 00            [12]  681 	mov	r5,#0x00
      000145                        682 00103$:
      000145 C3               [12]  683 	clr	c
      000146 EC               [12]  684 	mov	a,r4
      000147 9E               [12]  685 	subb	a,r6
      000148 ED               [12]  686 	mov	a,r5
      000149 9F               [12]  687 	subb	a,r7
      00014A 50 07            [24]  688 	jnc	00105$
      00014C 0C               [12]  689 	inc	r4
      00014D BC 00 F5         [24]  690 	cjne	r4,#0x00,00103$
      000150 0D               [12]  691 	inc	r5
      000151 80 F2            [24]  692 	sjmp	00103$
      000153                        693 00105$:
                                    694 ;	Base_Lib.h:65: }
      000153 22               [24]  695 	ret
                                    696 ;------------------------------------------------------------
                                    697 ;Allocation info for local variables in function 'delay_ms'
                                    698 ;------------------------------------------------------------
                                    699 ;ms            Allocated to registers 
                                    700 ;i             Allocated to registers r4 r5 
                                    701 ;------------------------------------------------------------
                                    702 ;	Base_Lib.h:67: void delay_ms(uint32 ms){
                                    703 ;	-----------------------------------------
                                    704 ;	 function delay_ms
                                    705 ;	-----------------------------------------
      000154                        706 _delay_ms:
      000154 85 82 08         [24]  707 	mov	__mulint_PARM_2,dpl
      000157 85 83 09         [24]  708 	mov	(__mulint_PARM_2 + 1),dph
                                    709 ;	Base_Lib.h:69: for(i = 0; i < ms*12; i = i + 1){
      00015A 90 00 0C         [24]  710 	mov	dptr,#0x000c
      00015D 12 11 0D         [24]  711 	lcall	__mulint
      000160 AE 82            [24]  712 	mov	r6, dpl
      000162 AF 83            [24]  713 	mov	r7, dph
      000164 7C 00            [12]  714 	mov	r4,#0x00
      000166 7D 00            [12]  715 	mov	r5,#0x00
      000168                        716 00103$:
      000168 C3               [12]  717 	clr	c
      000169 EC               [12]  718 	mov	a,r4
      00016A 9E               [12]  719 	subb	a,r6
      00016B ED               [12]  720 	mov	a,r5
      00016C 9F               [12]  721 	subb	a,r7
      00016D 50 07            [24]  722 	jnc	00105$
      00016F 0C               [12]  723 	inc	r4
      000170 BC 00 F5         [24]  724 	cjne	r4,#0x00,00103$
      000173 0D               [12]  725 	inc	r5
      000174 80 F2            [24]  726 	sjmp	00103$
      000176                        727 00105$:
                                    728 ;	Base_Lib.h:72: }
      000176 22               [24]  729 	ret
                                    730 ;------------------------------------------------------------
                                    731 ;Allocation info for local variables in function 'eINT0_CTL'
                                    732 ;------------------------------------------------------------
                                    733 ;CONFIG        Allocated to registers r7 
                                    734 ;------------------------------------------------------------
                                    735 ;	Base_Lib.h:74: void eINT0_CTL(uint8 CONFIG){
                                    736 ;	-----------------------------------------
                                    737 ;	 function eINT0_CTL
                                    738 ;	-----------------------------------------
      000177                        739 _eINT0_CTL:
      000177 AF 82            [24]  740 	mov	r7, dpl
                                    741 ;	Base_Lib.h:75: if( CONFIG == ENABLE){
      000179 BF 01 04         [24]  742 	cjne	r7,#0x01,00102$
                                    743 ;	Base_Lib.h:76: EX0 = 1;
                                    744 ;	assignBit
      00017C D2 A8            [12]  745 	setb	_EX0
                                    746 ;	Base_Lib.h:77: IT0 = 1;
                                    747 ;	assignBit
      00017E D2 88            [12]  748 	setb	_IT0
      000180                        749 00102$:
                                    750 ;	Base_Lib.h:79: if( CONFIG == DISABLE){
      000180 EF               [12]  751 	mov	a,r7
      000181 70 04            [24]  752 	jnz	00105$
                                    753 ;	Base_Lib.h:80: EX0 = 0;
                                    754 ;	assignBit
      000183 C2 A8            [12]  755 	clr	_EX0
                                    756 ;	Base_Lib.h:81: IT0 = 0;
                                    757 ;	assignBit
      000185 C2 88            [12]  758 	clr	_IT0
      000187                        759 00105$:
                                    760 ;	Base_Lib.h:83: }
      000187 22               [24]  761 	ret
                                    762 ;------------------------------------------------------------
                                    763 ;Allocation info for local variables in function 'eINT1_CTL'
                                    764 ;------------------------------------------------------------
                                    765 ;CONFIG        Allocated to registers r7 
                                    766 ;------------------------------------------------------------
                                    767 ;	Base_Lib.h:85: void eINT1_CTL(uint8 CONFIG){
                                    768 ;	-----------------------------------------
                                    769 ;	 function eINT1_CTL
                                    770 ;	-----------------------------------------
      000188                        771 _eINT1_CTL:
      000188 AF 82            [24]  772 	mov	r7, dpl
                                    773 ;	Base_Lib.h:86: if( CONFIG == ENABLE){
      00018A BF 01 04         [24]  774 	cjne	r7,#0x01,00102$
                                    775 ;	Base_Lib.h:88: IT1 = 1;   
                                    776 ;	assignBit
      00018D D2 8A            [12]  777 	setb	_IT1
                                    778 ;	Base_Lib.h:90: EX1 = 1;
                                    779 ;	assignBit
      00018F D2 AA            [12]  780 	setb	_EX1
      000191                        781 00102$:
                                    782 ;	Base_Lib.h:92: if( CONFIG == DISABLE){
      000191 EF               [12]  783 	mov	a,r7
      000192 70 04            [24]  784 	jnz	00105$
                                    785 ;	Base_Lib.h:94: IT1 = 0;   
                                    786 ;	assignBit
      000194 C2 8A            [12]  787 	clr	_IT1
                                    788 ;	Base_Lib.h:96: EX1 = 0;
                                    789 ;	assignBit
      000196 C2 AA            [12]  790 	clr	_EX1
      000198                        791 00105$:
                                    792 ;	Base_Lib.h:98: }
      000198 22               [24]  793 	ret
                                    794 ;------------------------------------------------------------
                                    795 ;Allocation info for local variables in function 'TIMER0_CTL'
                                    796 ;------------------------------------------------------------
                                    797 ;CONFIG        Allocated to registers r7 
                                    798 ;------------------------------------------------------------
                                    799 ;	Base_Lib.h:102: void TIMER0_CTL(uint8 CONFIG){
                                    800 ;	-----------------------------------------
                                    801 ;	 function TIMER0_CTL
                                    802 ;	-----------------------------------------
      000199                        803 _TIMER0_CTL:
                                    804 ;	Base_Lib.h:103: switch (CONFIG) {
      000199 E5 82            [12]  805 	mov	a,dpl
      00019B FF               [12]  806 	mov	r7,a
      00019C 24 FA            [12]  807 	add	a,#0xff - 0x05
      00019E 40 28            [24]  808 	jc	00108$
      0001A0 EF               [12]  809 	mov	a,r7
      0001A1 2F               [12]  810 	add	a,r7
                                    811 ;	Base_Lib.h:104: case ENABLE:
      0001A2 90 01 A6         [24]  812 	mov	dptr,#00117$
      0001A5 73               [24]  813 	jmp	@a+dptr
      0001A6                        814 00117$:
      0001A6 80 0D            [24]  815 	sjmp	00102$
      0001A8 80 08            [24]  816 	sjmp	00101$
      0001AA 80 13            [24]  817 	sjmp	00104$
      0001AC 80 14            [24]  818 	sjmp	00105$
      0001AE 80 15            [24]  819 	sjmp	00106$
      0001B0 80 06            [24]  820 	sjmp	00103$
      0001B2                        821 00101$:
                                    822 ;	Base_Lib.h:105: ET0 = 1;            return;
                                    823 ;	assignBit
      0001B2 D2 A9            [12]  824 	setb	_ET0
                                    825 ;	Base_Lib.h:106: case DISABLE:
      0001B4 22               [24]  826 	ret
      0001B5                        827 00102$:
                                    828 ;	Base_Lib.h:107: ET0 = 0;            return;
                                    829 ;	assignBit
      0001B5 C2 A9            [12]  830 	clr	_ET0
                                    831 ;	Base_Lib.h:108: case RESET:
      0001B7 22               [24]  832 	ret
      0001B8                        833 00103$:
                                    834 ;	Base_Lib.h:109: TL0 = RESET_TL;
      0001B8 75 8A 67         [24]  835 	mov	_TL0,#0x67
                                    836 ;	Base_Lib.h:110: TH0 = RESET_TH;     return;
      0001BB 75 8C FC         [24]  837 	mov	_TH0,#0xfc
                                    838 ;	Base_Lib.h:111: case START:
      0001BE 22               [24]  839 	ret
      0001BF                        840 00104$:
                                    841 ;	Base_Lib.h:112: TR0 = 1;            return;
                                    842 ;	assignBit
      0001BF D2 8C            [12]  843 	setb	_TR0
                                    844 ;	Base_Lib.h:113: case STOP:
      0001C1 22               [24]  845 	ret
      0001C2                        846 00105$:
                                    847 ;	Base_Lib.h:114: TR0 = 0;            return;
                                    848 ;	assignBit
      0001C2 C2 8C            [12]  849 	clr	_TR0
                                    850 ;	Base_Lib.h:115: case MODE_16BIT:
      0001C4 22               [24]  851 	ret
      0001C5                        852 00106$:
                                    853 ;	Base_Lib.h:116: TMOD = TMOD|0x01;   return;
      0001C5 43 89 01         [24]  854 	orl	_TMOD,#0x01
                                    855 ;	Base_Lib.h:117: }
      0001C8                        856 00108$:
                                    857 ;	Base_Lib.h:118: }
      0001C8 22               [24]  858 	ret
                                    859 ;------------------------------------------------------------
                                    860 ;Allocation info for local variables in function 'GLOBAL_INT'
                                    861 ;------------------------------------------------------------
                                    862 ;CONFIG        Allocated to registers r7 
                                    863 ;------------------------------------------------------------
                                    864 ;	Base_Lib.h:121: void GLOBAL_INT(uint8 CONFIG){
                                    865 ;	-----------------------------------------
                                    866 ;	 function GLOBAL_INT
                                    867 ;	-----------------------------------------
      0001C9                        868 _GLOBAL_INT:
      0001C9 AF 82            [24]  869 	mov	r7, dpl
                                    870 ;	Base_Lib.h:122: EA=(CONFIG==ENABLE)?(1):(0);
      0001CB BF 01 03         [24]  871 	cjne	r7,#0x01,00103$
      0001CE EF               [12]  872 	mov	a,r7
      0001CF 80 01            [24]  873 	sjmp	00104$
      0001D1                        874 00103$:
      0001D1 E4               [12]  875 	clr	a
      0001D2                        876 00104$:
                                    877 ;	assignBit
      0001D2 24 FF            [12]  878 	add	a,#0xff
      0001D4 92 AF            [24]  879 	mov	_EA,c
                                    880 ;	Base_Lib.h:123: }
      0001D6 22               [24]  881 	ret
                                    882 ;------------------------------------------------------------
                                    883 ;Allocation info for local variables in function 'single_byte_write'
                                    884 ;------------------------------------------------------------
                                    885 ;byte_data     Allocated with name '_single_byte_write_PARM_2'
                                    886 ;cmd           Allocated to registers r7 
                                    887 ;nCLK          Allocated to registers r6 
                                    888 ;------------------------------------------------------------
                                    889 ;	ThreeWiresProtocol.h:30: void single_byte_write(uint8 cmd, uint8 byte_data){
                                    890 ;	-----------------------------------------
                                    891 ;	 function single_byte_write
                                    892 ;	-----------------------------------------
      0001D7                        893 _single_byte_write:
      0001D7 AF 82            [24]  894 	mov	r7, dpl
                                    895 ;	ThreeWiresProtocol.h:33: delay_us(IDLE_T);
      0001D9 AD 23            [24]  896 	mov	r5,_IDLE_T
      0001DB 7E 00            [12]  897 	mov	r6,#0x00
      0001DD 8D 82            [24]  898 	mov	dpl, r5
      0001DF 8E 83            [24]  899 	mov	dph, r6
      0001E1 C0 07            [24]  900 	push	ar7
      0001E3 12 01 3D         [24]  901 	lcall	_delay_us
                                    902 ;	ThreeWiresProtocol.h:35: CE = HIGH; SCLK = LOW;
                                    903 ;	assignBit
      0001E6 D2 B5            [12]  904 	setb	_CE
                                    905 ;	assignBit
      0001E8 C2 B6            [12]  906 	clr	_SCLK
                                    907 ;	ThreeWiresProtocol.h:37: delay_us(T_PEAK);
      0001EA AD 22            [24]  908 	mov	r5,_T_PEAK
      0001EC 7E 00            [12]  909 	mov	r6,#0x00
      0001EE 8D 82            [24]  910 	mov	dpl, r5
      0001F0 8E 83            [24]  911 	mov	dph, r6
      0001F2 12 01 3D         [24]  912 	lcall	_delay_us
      0001F5 D0 07            [24]  913 	pop	ar7
                                    914 ;	ThreeWiresProtocol.h:39: for(nCLK = 1; nCLK <= 8; nCLK++){
      0001F7 7E 01            [12]  915 	mov	r6,#0x01
      0001F9                        916 00103$:
                                    917 ;	ThreeWiresProtocol.h:40: IO = (cmd&0x1);
      0001F9 EF               [12]  918 	mov	a,r7
      0001FA 54 01            [12]  919 	anl	a,#0x01
                                    920 ;	assignBit
      0001FC 24 FF            [12]  921 	add	a,#0xff
      0001FE 92 B4            [24]  922 	mov	_IO,c
                                    923 ;	ThreeWiresProtocol.h:41: HL_MONO_PULSE(SCLK);
                                    924 ;	assignBit
      000200 D2 B6            [12]  925 	setb	_SCLK
      000202 AC 22            [24]  926 	mov	r4,_T_PEAK
      000204 7D 00            [12]  927 	mov	r5,#0x00
      000206 8C 82            [24]  928 	mov	dpl, r4
      000208 8D 83            [24]  929 	mov	dph, r5
      00020A C0 07            [24]  930 	push	ar7
      00020C C0 06            [24]  931 	push	ar6
      00020E 12 01 3D         [24]  932 	lcall	_delay_us
                                    933 ;	assignBit
      000211 C2 B6            [12]  934 	clr	_SCLK
      000213 AC 22            [24]  935 	mov	r4,_T_PEAK
      000215 7D 00            [12]  936 	mov	r5,#0x00
      000217 8C 82            [24]  937 	mov	dpl, r4
      000219 8D 83            [24]  938 	mov	dph, r5
      00021B 12 01 3D         [24]  939 	lcall	_delay_us
      00021E D0 06            [24]  940 	pop	ar6
      000220 D0 07            [24]  941 	pop	ar7
                                    942 ;	ThreeWiresProtocol.h:42: cmd = (cmd>>1);
      000222 EF               [12]  943 	mov	a,r7
      000223 C3               [12]  944 	clr	c
      000224 13               [12]  945 	rrc	a
      000225 FF               [12]  946 	mov	r7,a
                                    947 ;	ThreeWiresProtocol.h:39: for(nCLK = 1; nCLK <= 8; nCLK++){
      000226 0E               [12]  948 	inc	r6
      000227 EE               [12]  949 	mov	a,r6
      000228 24 F7            [12]  950 	add	a,#0xff - 0x08
      00022A 50 CD            [24]  951 	jnc	00103$
                                    952 ;	ThreeWiresProtocol.h:45: for(nCLK = 1; nCLK <= 8; nCLK++){
      00022C 7F 01            [12]  953 	mov	r7,#0x01
      00022E                        954 00105$:
                                    955 ;	ThreeWiresProtocol.h:46: IO = (byte_data&0x1);
      00022E E5 25            [12]  956 	mov	a,_single_byte_write_PARM_2
      000230 54 01            [12]  957 	anl	a,#0x01
                                    958 ;	assignBit
      000232 24 FF            [12]  959 	add	a,#0xff
      000234 92 B4            [24]  960 	mov	_IO,c
                                    961 ;	ThreeWiresProtocol.h:47: HL_MONO_PULSE(SCLK);
                                    962 ;	assignBit
      000236 D2 B6            [12]  963 	setb	_SCLK
      000238 AD 22            [24]  964 	mov	r5,_T_PEAK
      00023A 7E 00            [12]  965 	mov	r6,#0x00
      00023C 8D 82            [24]  966 	mov	dpl, r5
      00023E 8E 83            [24]  967 	mov	dph, r6
      000240 C0 07            [24]  968 	push	ar7
      000242 12 01 3D         [24]  969 	lcall	_delay_us
                                    970 ;	assignBit
      000245 C2 B6            [12]  971 	clr	_SCLK
      000247 AD 22            [24]  972 	mov	r5,_T_PEAK
      000249 7E 00            [12]  973 	mov	r6,#0x00
      00024B 8D 82            [24]  974 	mov	dpl, r5
      00024D 8E 83            [24]  975 	mov	dph, r6
      00024F 12 01 3D         [24]  976 	lcall	_delay_us
      000252 D0 07            [24]  977 	pop	ar7
                                    978 ;	ThreeWiresProtocol.h:48: byte_data >>= 1;
      000254 E5 25            [12]  979 	mov	a,_single_byte_write_PARM_2
      000256 C3               [12]  980 	clr	c
      000257 13               [12]  981 	rrc	a
      000258 F5 25            [12]  982 	mov	_single_byte_write_PARM_2,a
                                    983 ;	ThreeWiresProtocol.h:45: for(nCLK = 1; nCLK <= 8; nCLK++){
      00025A 0F               [12]  984 	inc	r7
      00025B EF               [12]  985 	mov	a,r7
      00025C 24 F7            [12]  986 	add	a,#0xff - 0x08
      00025E 50 CE            [24]  987 	jnc	00105$
                                    988 ;	ThreeWiresProtocol.h:52: CE = LOW; 
                                    989 ;	assignBit
      000260 C2 B5            [12]  990 	clr	_CE
                                    991 ;	ThreeWiresProtocol.h:53: }
      000262 22               [24]  992 	ret
                                    993 ;------------------------------------------------------------
                                    994 ;Allocation info for local variables in function 'single_byte_read'
                                    995 ;------------------------------------------------------------
                                    996 ;cmd           Allocated to registers r7 
                                    997 ;nCLK          Allocated to registers r5 
                                    998 ;byte_data     Allocated to registers r6 
                                    999 ;bit_data      Allocated to registers 
                                   1000 ;------------------------------------------------------------
                                   1001 ;	ThreeWiresProtocol.h:55: uint8 single_byte_read(uint8 cmd){
                                   1002 ;	-----------------------------------------
                                   1003 ;	 function single_byte_read
                                   1004 ;	-----------------------------------------
      000263                       1005 _single_byte_read:
      000263 AF 82            [24] 1006 	mov	r7, dpl
                                   1007 ;	ThreeWiresProtocol.h:57: uint8 byte_data = 0, bit_data = 0;
      000265 7E 00            [12] 1008 	mov	r6,#0x00
                                   1009 ;	ThreeWiresProtocol.h:59: delay_us(IDLE_T);
      000267 AC 23            [24] 1010 	mov	r4,_IDLE_T
      000269 7D 00            [12] 1011 	mov	r5,#0x00
      00026B 8C 82            [24] 1012 	mov	dpl, r4
      00026D 8D 83            [24] 1013 	mov	dph, r5
      00026F C0 07            [24] 1014 	push	ar7
      000271 C0 06            [24] 1015 	push	ar6
      000273 12 01 3D         [24] 1016 	lcall	_delay_us
                                   1017 ;	ThreeWiresProtocol.h:61: CE = HIGH;SCLK = LOW;
                                   1018 ;	assignBit
      000276 D2 B5            [12] 1019 	setb	_CE
                                   1020 ;	assignBit
      000278 C2 B6            [12] 1021 	clr	_SCLK
                                   1022 ;	ThreeWiresProtocol.h:62: delay_us(T_PEAK);
      00027A AC 22            [24] 1023 	mov	r4,_T_PEAK
      00027C 7D 00            [12] 1024 	mov	r5,#0x00
      00027E 8C 82            [24] 1025 	mov	dpl, r4
      000280 8D 83            [24] 1026 	mov	dph, r5
      000282 12 01 3D         [24] 1027 	lcall	_delay_us
      000285 D0 06            [24] 1028 	pop	ar6
      000287 D0 07            [24] 1029 	pop	ar7
                                   1030 ;	ThreeWiresProtocol.h:64: for(nCLK = 1; nCLK <= 7; nCLK++){
      000289 7D 01            [12] 1031 	mov	r5,#0x01
      00028B                       1032 00103$:
                                   1033 ;	ThreeWiresProtocol.h:65: IO = (cmd&0x1);
      00028B EF               [12] 1034 	mov	a,r7
      00028C 54 01            [12] 1035 	anl	a,#0x01
                                   1036 ;	assignBit
      00028E 24 FF            [12] 1037 	add	a,#0xff
      000290 92 B4            [24] 1038 	mov	_IO,c
                                   1039 ;	ThreeWiresProtocol.h:66: HL_MONO_PULSE(SCLK);
                                   1040 ;	assignBit
      000292 D2 B6            [12] 1041 	setb	_SCLK
      000294 AB 22            [24] 1042 	mov	r3,_T_PEAK
      000296 7C 00            [12] 1043 	mov	r4,#0x00
      000298 8B 82            [24] 1044 	mov	dpl, r3
      00029A 8C 83            [24] 1045 	mov	dph, r4
      00029C C0 07            [24] 1046 	push	ar7
      00029E C0 06            [24] 1047 	push	ar6
      0002A0 C0 05            [24] 1048 	push	ar5
      0002A2 12 01 3D         [24] 1049 	lcall	_delay_us
                                   1050 ;	assignBit
      0002A5 C2 B6            [12] 1051 	clr	_SCLK
      0002A7 AB 22            [24] 1052 	mov	r3,_T_PEAK
      0002A9 7C 00            [12] 1053 	mov	r4,#0x00
      0002AB 8B 82            [24] 1054 	mov	dpl, r3
      0002AD 8C 83            [24] 1055 	mov	dph, r4
      0002AF 12 01 3D         [24] 1056 	lcall	_delay_us
      0002B2 D0 05            [24] 1057 	pop	ar5
      0002B4 D0 06            [24] 1058 	pop	ar6
      0002B6 D0 07            [24] 1059 	pop	ar7
                                   1060 ;	ThreeWiresProtocol.h:67: cmd = (cmd>>1);
      0002B8 EF               [12] 1061 	mov	a,r7
      0002B9 C3               [12] 1062 	clr	c
      0002BA 13               [12] 1063 	rrc	a
      0002BB FF               [12] 1064 	mov	r7,a
                                   1065 ;	ThreeWiresProtocol.h:64: for(nCLK = 1; nCLK <= 7; nCLK++){
      0002BC 0D               [12] 1066 	inc	r5
      0002BD ED               [12] 1067 	mov	a,r5
      0002BE 24 F8            [12] 1068 	add	a,#0xff - 0x07
      0002C0 50 C9            [24] 1069 	jnc	00103$
                                   1070 ;	ThreeWiresProtocol.h:70: IO = (cmd&0x1);
      0002C2 EF               [12] 1071 	mov	a,r7
      0002C3 54 01            [12] 1072 	anl	a,#0x01
                                   1073 ;	assignBit
      0002C5 24 FF            [12] 1074 	add	a,#0xff
      0002C7 92 B4            [24] 1075 	mov	_IO,c
                                   1076 ;	ThreeWiresProtocol.h:71: SCLK = HIGH; delay_us(T_PEAK);
                                   1077 ;	assignBit
      0002C9 D2 B6            [12] 1078 	setb	_SCLK
      0002CB AD 22            [24] 1079 	mov	r5,_T_PEAK
      0002CD 7F 00            [12] 1080 	mov	r7,#0x00
      0002CF 8D 82            [24] 1081 	mov	dpl, r5
      0002D1 8F 83            [24] 1082 	mov	dph, r7
      0002D3 C0 06            [24] 1083 	push	ar6
      0002D5 12 01 3D         [24] 1084 	lcall	_delay_us
      0002D8 D0 06            [24] 1085 	pop	ar6
                                   1086 ;	ThreeWiresProtocol.h:73: for(nCLK = 0; nCLK <= 7; nCLK++){
      0002DA 7F 00            [12] 1087 	mov	r7,#0x00
      0002DC                       1088 00105$:
                                   1089 ;	ThreeWiresProtocol.h:74: SCLK = LOW;  delay_us(READ_T);
                                   1090 ;	assignBit
      0002DC C2 B6            [12] 1091 	clr	_SCLK
      0002DE AC 24            [24] 1092 	mov	r4,_READ_T
      0002E0 7D 00            [12] 1093 	mov	r5,#0x00
      0002E2 8C 82            [24] 1094 	mov	dpl, r4
      0002E4 8D 83            [24] 1095 	mov	dph, r5
      0002E6 C0 07            [24] 1096 	push	ar7
      0002E8 C0 06            [24] 1097 	push	ar6
      0002EA 12 01 3D         [24] 1098 	lcall	_delay_us
      0002ED D0 06            [24] 1099 	pop	ar6
      0002EF D0 07            [24] 1100 	pop	ar7
                                   1101 ;	ThreeWiresProtocol.h:75: bit_data = IO;
      0002F1 A2 B4            [12] 1102 	mov	c,_IO
      0002F3 E4               [12] 1103 	clr	a
      0002F4 33               [12] 1104 	rlc	a
      0002F5 FD               [12] 1105 	mov	r5,a
                                   1106 ;	ThreeWiresProtocol.h:76: byte_data = byte_data|((bit_data&0x1)<<nCLK);
      0002F6 74 01            [12] 1107 	mov	a,#0x01
      0002F8 5D               [12] 1108 	anl	a,r5
      0002F9 8F F0            [24] 1109 	mov	b,r7
      0002FB 05 F0            [12] 1110 	inc	b
      0002FD 80 02            [24] 1111 	sjmp	00137$
      0002FF                       1112 00136$:
      0002FF 25 E0            [12] 1113 	add	a,acc
      000301                       1114 00137$:
      000301 D5 F0 FB         [24] 1115 	djnz	b,00136$
      000304 42 06            [12] 1116 	orl	ar6,a
                                   1117 ;	ThreeWiresProtocol.h:77: delay_us(T_PEAK-READ_T);
      000306 AC 22            [24] 1118 	mov	r4,_T_PEAK
      000308 7D 00            [12] 1119 	mov	r5,#0x00
      00030A AA 24            [24] 1120 	mov	r2,_READ_T
      00030C 7B 00            [12] 1121 	mov	r3,#0x00
      00030E EC               [12] 1122 	mov	a,r4
      00030F C3               [12] 1123 	clr	c
      000310 9A               [12] 1124 	subb	a,r2
      000311 F5 82            [12] 1125 	mov	dpl,a
      000313 ED               [12] 1126 	mov	a,r5
      000314 9B               [12] 1127 	subb	a,r3
      000315 F5 83            [12] 1128 	mov	dph,a
      000317 C0 07            [24] 1129 	push	ar7
      000319 C0 06            [24] 1130 	push	ar6
      00031B 12 01 3D         [24] 1131 	lcall	_delay_us
                                   1132 ;	ThreeWiresProtocol.h:78: SCLK = HIGH; delay_us(T_PEAK);
                                   1133 ;	assignBit
      00031E D2 B6            [12] 1134 	setb	_SCLK
      000320 AC 22            [24] 1135 	mov	r4,_T_PEAK
      000322 7D 00            [12] 1136 	mov	r5,#0x00
      000324 8C 82            [24] 1137 	mov	dpl, r4
      000326 8D 83            [24] 1138 	mov	dph, r5
      000328 12 01 3D         [24] 1139 	lcall	_delay_us
      00032B D0 06            [24] 1140 	pop	ar6
      00032D D0 07            [24] 1141 	pop	ar7
                                   1142 ;	ThreeWiresProtocol.h:73: for(nCLK = 0; nCLK <= 7; nCLK++){
      00032F 0F               [12] 1143 	inc	r7
      000330 EF               [12] 1144 	mov	a,r7
      000331 24 F8            [12] 1145 	add	a,#0xff - 0x07
      000333 50 A7            [24] 1146 	jnc	00105$
                                   1147 ;	ThreeWiresProtocol.h:82: CE = LOW; 
                                   1148 ;	assignBit
      000335 C2 B5            [12] 1149 	clr	_CE
                                   1150 ;	ThreeWiresProtocol.h:83: return byte_data;
      000337 8E 82            [24] 1151 	mov	dpl, r6
                                   1152 ;	ThreeWiresProtocol.h:84: }
      000339 22               [24] 1153 	ret
                                   1154 ;------------------------------------------------------------
                                   1155 ;Allocation info for local variables in function 'ThreeWiresProtocol_Initial'
                                   1156 ;------------------------------------------------------------
                                   1157 ;	ThreeWiresProtocol.h:86: void ThreeWiresProtocol_Initial(){
                                   1158 ;	-----------------------------------------
                                   1159 ;	 function ThreeWiresProtocol_Initial
                                   1160 ;	-----------------------------------------
      00033A                       1161 _ThreeWiresProtocol_Initial:
                                   1162 ;	ThreeWiresProtocol.h:87: IO = LOW;
                                   1163 ;	assignBit
      00033A C2 B4            [12] 1164 	clr	_IO
                                   1165 ;	ThreeWiresProtocol.h:88: SCLK = LOW;
                                   1166 ;	assignBit
      00033C C2 B6            [12] 1167 	clr	_SCLK
                                   1168 ;	ThreeWiresProtocol.h:89: CE = LOW;
                                   1169 ;	assignBit
      00033E C2 B5            [12] 1170 	clr	_CE
                                   1171 ;	ThreeWiresProtocol.h:90: }
      000340 22               [24] 1172 	ret
                                   1173 ;------------------------------------------------------------
                                   1174 ;Allocation info for local variables in function 'time_equal'
                                   1175 ;------------------------------------------------------------
                                   1176 ;A             Allocated with name '_time_equal_PARM_1'
                                   1177 ;B             Allocated with name '_time_equal_PARM_2'
                                   1178 ;MASK          Allocated to registers 
                                   1179 ;------------------------------------------------------------
                                   1180 ;	DS1302.h:38: uint8 time_equal(TIME A, TIME B, uint32 MASK){
                                   1181 ;	-----------------------------------------
                                   1182 ;	 function time_equal
                                   1183 ;	-----------------------------------------
      000341                       1184 _time_equal:
                                   1185 ;	DS1302.h:39: return (A.MINUTE == B.MINUTE) && (A.HOUR == B.HOUR);
      000341 E5 32            [12] 1186 	mov	a,(_time_equal_PARM_2 + 0x0005)
      000343 B5 2B 07         [24] 1187 	cjne	a,(_time_equal_PARM_1 + 0x0005),00103$
      000346 E5 31            [12] 1188 	mov	a,(_time_equal_PARM_2 + 0x0004)
      000348 B5 2A 02         [24] 1189 	cjne	a,(_time_equal_PARM_1 + 0x0004),00114$
      00034B 80 04            [24] 1190 	sjmp	00104$
      00034D                       1191 00114$:
      00034D                       1192 00103$:
                                   1193 ;	assignBit
      00034D C2 00            [12] 1194 	clr	_time_equal_sloc0_1_0
      00034F 80 02            [24] 1195 	sjmp	00105$
      000351                       1196 00104$:
                                   1197 ;	assignBit
      000351 D2 00            [12] 1198 	setb	_time_equal_sloc0_1_0
      000353                       1199 00105$:
      000353 A2 00            [12] 1200 	mov	c,_time_equal_sloc0_1_0
      000355 E4               [12] 1201 	clr	a
      000356 33               [12] 1202 	rlc	a
      000357 F5 82            [12] 1203 	mov	dpl,a
                                   1204 ;	DS1302.h:51: }
      000359 22               [24] 1205 	ret
                                   1206 ;------------------------------------------------------------
                                   1207 ;Allocation info for local variables in function 'ds1302_read_time'
                                   1208 ;------------------------------------------------------------
                                   1209 ;SEL           Allocated with name '_ds1302_read_time_PARM_2'
                                   1210 ;time          Allocated with name '_ds1302_read_time_time_10000_37'
                                   1211 ;x10           Allocated to registers r5 
                                   1212 ;x1            Allocated to registers r7 
                                   1213 ;byte_data     Allocated to registers r7 
                                   1214 ;AM_PM         Allocated with name '_ds1302_read_time_AM_PM_10000_38'
                                   1215 ;x10           Allocated to registers r5 
                                   1216 ;x1            Allocated to registers r7 
                                   1217 ;------------------------------------------------------------
                                   1218 ;	DS1302.h:61: void ds1302_read_time(TIME* time, uint8 SEL){
                                   1219 ;	-----------------------------------------
                                   1220 ;	 function ds1302_read_time
                                   1221 ;	-----------------------------------------
      00035A                       1222 _ds1302_read_time:
      00035A 85 82 35         [24] 1223 	mov	_ds1302_read_time_time_10000_37,dpl
      00035D 85 83 36         [24] 1224 	mov	(_ds1302_read_time_time_10000_37 + 1),dph
      000360 85 F0 37         [24] 1225 	mov	(_ds1302_read_time_time_10000_37 + 2),b
                                   1226 ;	DS1302.h:64: if(SEL&0x1){
      000363 E5 34            [12] 1227 	mov	a,_ds1302_read_time_PARM_2
      000365 FC               [12] 1228 	mov	r4,a
      000366 30 E0 4A         [24] 1229 	jnb	acc.0,00102$
                                   1230 ;	DS1302.h:65: ds1302_unlock_reg();
      000369 75 25 00         [24] 1231 	mov	_single_byte_write_PARM_2,#0x00
      00036C 75 82 8E         [24] 1232 	mov	dpl, #0x8e
      00036F C0 04            [24] 1233 	push	ar4
      000371 12 01 D7         [24] 1234 	lcall	_single_byte_write
                                   1235 ;	DS1302.h:66: byte_data = single_byte_read(0x81);
      000374 75 82 81         [24] 1236 	mov	dpl, #0x81
      000377 12 02 63         [24] 1237 	lcall	_single_byte_read
      00037A AB 82            [24] 1238 	mov	r3, dpl
      00037C D0 04            [24] 1239 	pop	ar4
                                   1240 ;	DS1302.h:67: x10 = ((byte_data & 0x70) >> 4)*10;
      00037E 8B 01            [24] 1241 	mov	ar1,r3
      000380 53 01 70         [24] 1242 	anl	ar1,#0x70
      000383 E4               [12] 1243 	clr	a
      000384 C9               [12] 1244 	xch	a,r1
      000385 C4               [12] 1245 	swap	a
      000386 54 0F            [12] 1246 	anl	a,#0x0f
      000388 69               [12] 1247 	xrl	a,r1
      000389 C9               [12] 1248 	xch	a,r1
      00038A 54 0F            [12] 1249 	anl	a,#0x0f
      00038C C9               [12] 1250 	xch	a,r1
      00038D 69               [12] 1251 	xrl	a,r1
      00038E C9               [12] 1252 	xch	a,r1
      00038F 30 E3 02         [24] 1253 	jnb	acc.3,00168$
      000392 44 F0            [12] 1254 	orl	a,#0xfffffff0
      000394                       1255 00168$:
      000394 E9               [12] 1256 	mov	a,r1
      000395 75 F0 0A         [24] 1257 	mov	b,#0x0a
      000398 A4               [48] 1258 	mul	ab
      000399 F9               [12] 1259 	mov	r1,a
                                   1260 ;	DS1302.h:68: x1  = (byte_data & 0x0F);
      00039A 53 03 0F         [24] 1261 	anl	ar3,#0x0f
                                   1262 ;	DS1302.h:69: time->SECOND = x1 + x10;
      00039D 74 06            [12] 1263 	mov	a,#0x06
      00039F 25 35            [12] 1264 	add	a, _ds1302_read_time_time_10000_37
      0003A1 F8               [12] 1265 	mov	r0,a
      0003A2 E4               [12] 1266 	clr	a
      0003A3 35 36            [12] 1267 	addc	a, (_ds1302_read_time_time_10000_37 + 1)
      0003A5 FA               [12] 1268 	mov	r2,a
      0003A6 AF 37            [24] 1269 	mov	r7,(_ds1302_read_time_time_10000_37 + 2)
      0003A8 E9               [12] 1270 	mov	a,r1
      0003A9 2B               [12] 1271 	add	a, r3
      0003AA 88 82            [24] 1272 	mov	dpl,r0
      0003AC 8A 83            [24] 1273 	mov	dph,r2
      0003AE 8F F0            [24] 1274 	mov	b,r7
      0003B0 12 10 F2         [24] 1275 	lcall	__gptrput
      0003B3                       1276 00102$:
                                   1277 ;	DS1302.h:72: if(SEL&0x2){
      0003B3 EC               [12] 1278 	mov	a,r4
      0003B4 30 E1 4A         [24] 1279 	jnb	acc.1,00104$
                                   1280 ;	DS1302.h:73: ds1302_unlock_reg();
      0003B7 75 25 00         [24] 1281 	mov	_single_byte_write_PARM_2,#0x00
      0003BA 75 82 8E         [24] 1282 	mov	dpl, #0x8e
      0003BD C0 04            [24] 1283 	push	ar4
      0003BF 12 01 D7         [24] 1284 	lcall	_single_byte_write
                                   1285 ;	DS1302.h:74: byte_data = single_byte_read(0x83);
      0003C2 75 82 83         [24] 1286 	mov	dpl, #0x83
      0003C5 12 02 63         [24] 1287 	lcall	_single_byte_read
      0003C8 AF 82            [24] 1288 	mov	r7, dpl
      0003CA D0 04            [24] 1289 	pop	ar4
                                   1290 ;	DS1302.h:75: x10 = ((byte_data & 0x70) >> 4)*10;
      0003CC 8F 05            [24] 1291 	mov	ar5,r7
      0003CE 53 05 70         [24] 1292 	anl	ar5,#0x70
      0003D1 E4               [12] 1293 	clr	a
      0003D2 CD               [12] 1294 	xch	a,r5
      0003D3 C4               [12] 1295 	swap	a
      0003D4 54 0F            [12] 1296 	anl	a,#0x0f
      0003D6 6D               [12] 1297 	xrl	a,r5
      0003D7 CD               [12] 1298 	xch	a,r5
      0003D8 54 0F            [12] 1299 	anl	a,#0x0f
      0003DA CD               [12] 1300 	xch	a,r5
      0003DB 6D               [12] 1301 	xrl	a,r5
      0003DC CD               [12] 1302 	xch	a,r5
      0003DD 30 E3 02         [24] 1303 	jnb	acc.3,00170$
      0003E0 44 F0            [12] 1304 	orl	a,#0xfffffff0
      0003E2                       1305 00170$:
      0003E2 ED               [12] 1306 	mov	a,r5
      0003E3 75 F0 0A         [24] 1307 	mov	b,#0x0a
      0003E6 A4               [48] 1308 	mul	ab
      0003E7 FD               [12] 1309 	mov	r5,a
                                   1310 ;	DS1302.h:76: x1  = (byte_data & 0x0F);
      0003E8 53 07 0F         [24] 1311 	anl	ar7,#0x0f
                                   1312 ;	DS1302.h:77: time->MINUTE = x10 + x1;
      0003EB 74 05            [12] 1313 	mov	a,#0x05
      0003ED 25 35            [12] 1314 	add	a, _ds1302_read_time_time_10000_37
      0003EF FA               [12] 1315 	mov	r2,a
      0003F0 E4               [12] 1316 	clr	a
      0003F1 35 36            [12] 1317 	addc	a, (_ds1302_read_time_time_10000_37 + 1)
      0003F3 FB               [12] 1318 	mov	r3,a
      0003F4 AE 37            [24] 1319 	mov	r6,(_ds1302_read_time_time_10000_37 + 2)
      0003F6 EF               [12] 1320 	mov	a,r7
      0003F7 2D               [12] 1321 	add	a, r5
      0003F8 8A 82            [24] 1322 	mov	dpl,r2
      0003FA 8B 83            [24] 1323 	mov	dph,r3
      0003FC 8E F0            [24] 1324 	mov	b,r6
      0003FE 12 10 F2         [24] 1325 	lcall	__gptrput
      000401                       1326 00104$:
                                   1327 ;	DS1302.h:80: if(SEL&0x4){
      000401 EC               [12] 1328 	mov	a,r4
      000402 20 E2 03         [24] 1329 	jb	acc.2,00171$
      000405 02 04 BA         [24] 1330 	ljmp	00109$
      000408                       1331 00171$:
                                   1332 ;	DS1302.h:81: ds1302_unlock_reg();
      000408 75 25 00         [24] 1333 	mov	_single_byte_write_PARM_2,#0x00
      00040B 75 82 8E         [24] 1334 	mov	dpl, #0x8e
      00040E C0 04            [24] 1335 	push	ar4
      000410 12 01 D7         [24] 1336 	lcall	_single_byte_write
                                   1337 ;	DS1302.h:82: byte_data = single_byte_read(0x85);
      000413 75 82 85         [24] 1338 	mov	dpl, #0x85
      000416 12 02 63         [24] 1339 	lcall	_single_byte_read
      000419 AF 82            [24] 1340 	mov	r7, dpl
      00041B D0 04            [24] 1341 	pop	ar4
                                   1342 ;	DS1302.h:83: if( (byte_data & 0x80) == HIGH){
      00041D 8F 05            [24] 1343 	mov	ar5,r7
      00041F 74 80            [12] 1344 	mov	a,#0x80
      000421 5D               [12] 1345 	anl	a,r5
      000422 FA               [12] 1346 	mov	r2,a
      000423 7B 00            [12] 1347 	mov	r3,#0x00
      000425 BA 01 5F         [24] 1348 	cjne	r2,#0x01,00106$
      000428 BB 00 5C         [24] 1349 	cjne	r3,#0x00,00106$
                                   1350 ;	DS1302.h:85: x10 = ((byte_data & 0x10)>>4)*10;
      00042B C0 04            [24] 1351 	push	ar4
      00042D 74 10            [12] 1352 	mov	a,#0x10
      00042F 5D               [12] 1353 	anl	a,r5
      000430 FA               [12] 1354 	mov	r2,a
      000431 E4               [12] 1355 	clr	a
      000432 CA               [12] 1356 	xch	a,r2
      000433 C4               [12] 1357 	swap	a
      000434 54 0F            [12] 1358 	anl	a,#0x0f
      000436 6A               [12] 1359 	xrl	a,r2
      000437 CA               [12] 1360 	xch	a,r2
      000438 54 0F            [12] 1361 	anl	a,#0x0f
      00043A CA               [12] 1362 	xch	a,r2
      00043B 6A               [12] 1363 	xrl	a,r2
      00043C CA               [12] 1364 	xch	a,r2
      00043D 30 E3 02         [24] 1365 	jnb	acc.3,00174$
      000440 44 F0            [12] 1366 	orl	a,#0xfffffff0
      000442                       1367 00174$:
      000442 EA               [12] 1368 	mov	a,r2
      000443 75 F0 0A         [24] 1369 	mov	b,#0x0a
      000446 A4               [48] 1370 	mul	ab
      000447 FA               [12] 1371 	mov	r2,a
                                   1372 ;	DS1302.h:86: x1  = (byte_data & 0x0F);
      000448 74 0F            [12] 1373 	mov	a,#0x0f
      00044A 5F               [12] 1374 	anl	a,r7
      00044B FB               [12] 1375 	mov	r3,a
                                   1376 ;	DS1302.h:87: AM_PM = (byte_data&0x20)>>5;
      00044C 74 20            [12] 1377 	mov	a,#0x20
      00044E 5D               [12] 1378 	anl	a,r5
      00044F F8               [12] 1379 	mov	r0,a
      000450 E4               [12] 1380 	clr	a
      000451 03               [12] 1381 	rr	a
      000452 C8               [12] 1382 	xch	a,r0
      000453 C4               [12] 1383 	swap	a
      000454 03               [12] 1384 	rr	a
      000455 54 07            [12] 1385 	anl	a,#0x07
      000457 68               [12] 1386 	xrl	a,r0
      000458 C8               [12] 1387 	xch	a,r0
      000459 54 07            [12] 1388 	anl	a,#0x07
      00045B C8               [12] 1389 	xch	a,r0
      00045C 68               [12] 1390 	xrl	a,r0
      00045D C8               [12] 1391 	xch	a,r0
      00045E 30 E2 02         [24] 1392 	jnb	acc.2,00175$
      000461 44 F8            [12] 1393 	orl	a,#0xfffffff8
      000463                       1394 00175$:
      000463 88 38            [24] 1395 	mov	_ds1302_read_time_AM_PM_10000_38,r0
                                   1396 ;	DS1302.h:88: time->HOUR = x10 + x1 + AM_PM * 12;
      000465 74 04            [12] 1397 	mov	a,#0x04
      000467 25 35            [12] 1398 	add	a, _ds1302_read_time_time_10000_37
      000469 F8               [12] 1399 	mov	r0,a
      00046A E4               [12] 1400 	clr	a
      00046B 35 36            [12] 1401 	addc	a, (_ds1302_read_time_time_10000_37 + 1)
      00046D F9               [12] 1402 	mov	r1,a
      00046E AC 37            [24] 1403 	mov	r4,(_ds1302_read_time_time_10000_37 + 2)
      000470 EB               [12] 1404 	mov	a,r3
      000471 2A               [12] 1405 	add	a, r2
      000472 FA               [12] 1406 	mov	r2,a
      000473 E5 38            [12] 1407 	mov	a,_ds1302_read_time_AM_PM_10000_38
      000475 75 F0 0C         [24] 1408 	mov	b,#0x0c
      000478 A4               [48] 1409 	mul	ab
      000479 2A               [12] 1410 	add	a,r2
      00047A 88 82            [24] 1411 	mov	dpl,r0
      00047C 89 83            [24] 1412 	mov	dph,r1
      00047E 8C F0            [24] 1413 	mov	b,r4
      000480 12 10 F2         [24] 1414 	lcall	__gptrput
      000483 D0 04            [24] 1415 	pop	ar4
      000485 80 33            [24] 1416 	sjmp	00109$
      000487                       1417 00106$:
                                   1418 ;	DS1302.h:91: uint8 x10 = ((byte_data & 0x30)>>4)*10;
      000487 53 05 30         [24] 1419 	anl	ar5,#0x30
      00048A E4               [12] 1420 	clr	a
      00048B CD               [12] 1421 	xch	a,r5
      00048C C4               [12] 1422 	swap	a
      00048D 54 0F            [12] 1423 	anl	a,#0x0f
      00048F 6D               [12] 1424 	xrl	a,r5
      000490 CD               [12] 1425 	xch	a,r5
      000491 54 0F            [12] 1426 	anl	a,#0x0f
      000493 CD               [12] 1427 	xch	a,r5
      000494 6D               [12] 1428 	xrl	a,r5
      000495 CD               [12] 1429 	xch	a,r5
      000496 30 E3 02         [24] 1430 	jnb	acc.3,00176$
      000499 44 F0            [12] 1431 	orl	a,#0xfffffff0
      00049B                       1432 00176$:
      00049B ED               [12] 1433 	mov	a,r5
      00049C 75 F0 0A         [24] 1434 	mov	b,#0x0a
      00049F A4               [48] 1435 	mul	ab
      0004A0 FD               [12] 1436 	mov	r5,a
                                   1437 ;	DS1302.h:92: uint8 x1  = (byte_data & 0x0F);
      0004A1 53 07 0F         [24] 1438 	anl	ar7,#0x0f
                                   1439 ;	DS1302.h:93: time->HOUR = x10 + x1;
      0004A4 74 04            [12] 1440 	mov	a,#0x04
      0004A6 25 35            [12] 1441 	add	a, _ds1302_read_time_time_10000_37
      0004A8 FA               [12] 1442 	mov	r2,a
      0004A9 E4               [12] 1443 	clr	a
      0004AA 35 36            [12] 1444 	addc	a, (_ds1302_read_time_time_10000_37 + 1)
      0004AC FB               [12] 1445 	mov	r3,a
      0004AD AE 37            [24] 1446 	mov	r6,(_ds1302_read_time_time_10000_37 + 2)
      0004AF EF               [12] 1447 	mov	a,r7
      0004B0 2D               [12] 1448 	add	a, r5
      0004B1 8A 82            [24] 1449 	mov	dpl,r2
      0004B3 8B 83            [24] 1450 	mov	dph,r3
      0004B5 8E F0            [24] 1451 	mov	b,r6
      0004B7 12 10 F2         [24] 1452 	lcall	__gptrput
      0004BA                       1453 00109$:
                                   1454 ;	DS1302.h:97: if(SEL&0x10){
      0004BA EC               [12] 1455 	mov	a,r4
      0004BB 30 E4 4A         [24] 1456 	jnb	acc.4,00111$
                                   1457 ;	DS1302.h:98: ds1302_unlock_reg();
      0004BE 75 25 00         [24] 1458 	mov	_single_byte_write_PARM_2,#0x00
      0004C1 75 82 8E         [24] 1459 	mov	dpl, #0x8e
      0004C4 C0 04            [24] 1460 	push	ar4
      0004C6 12 01 D7         [24] 1461 	lcall	_single_byte_write
                                   1462 ;	DS1302.h:99: byte_data = single_byte_read(0x87);
      0004C9 75 82 87         [24] 1463 	mov	dpl, #0x87
      0004CC 12 02 63         [24] 1464 	lcall	_single_byte_read
      0004CF AF 82            [24] 1465 	mov	r7, dpl
      0004D1 D0 04            [24] 1466 	pop	ar4
                                   1467 ;	DS1302.h:100: x10 = ((byte_data&0x30)>>4)*10;
      0004D3 8F 05            [24] 1468 	mov	ar5,r7
      0004D5 53 05 30         [24] 1469 	anl	ar5,#0x30
      0004D8 E4               [12] 1470 	clr	a
      0004D9 CD               [12] 1471 	xch	a,r5
      0004DA C4               [12] 1472 	swap	a
      0004DB 54 0F            [12] 1473 	anl	a,#0x0f
      0004DD 6D               [12] 1474 	xrl	a,r5
      0004DE CD               [12] 1475 	xch	a,r5
      0004DF 54 0F            [12] 1476 	anl	a,#0x0f
      0004E1 CD               [12] 1477 	xch	a,r5
      0004E2 6D               [12] 1478 	xrl	a,r5
      0004E3 CD               [12] 1479 	xch	a,r5
      0004E4 30 E3 02         [24] 1480 	jnb	acc.3,00178$
      0004E7 44 F0            [12] 1481 	orl	a,#0xfffffff0
      0004E9                       1482 00178$:
      0004E9 ED               [12] 1483 	mov	a,r5
      0004EA 75 F0 0A         [24] 1484 	mov	b,#0x0a
      0004ED A4               [48] 1485 	mul	ab
      0004EE FD               [12] 1486 	mov	r5,a
                                   1487 ;	DS1302.h:101: x1  = (byte_data&0x0F);
      0004EF 53 07 0F         [24] 1488 	anl	ar7,#0x0f
                                   1489 ;	DS1302.h:102: time->DATE = x10 + x1;
      0004F2 74 01            [12] 1490 	mov	a,#0x01
      0004F4 25 35            [12] 1491 	add	a, _ds1302_read_time_time_10000_37
      0004F6 FA               [12] 1492 	mov	r2,a
      0004F7 E4               [12] 1493 	clr	a
      0004F8 35 36            [12] 1494 	addc	a, (_ds1302_read_time_time_10000_37 + 1)
      0004FA FB               [12] 1495 	mov	r3,a
      0004FB AE 37            [24] 1496 	mov	r6,(_ds1302_read_time_time_10000_37 + 2)
      0004FD EF               [12] 1497 	mov	a,r7
      0004FE 2D               [12] 1498 	add	a, r5
      0004FF 8A 82            [24] 1499 	mov	dpl,r2
      000501 8B 83            [24] 1500 	mov	dph,r3
      000503 8E F0            [24] 1501 	mov	b,r6
      000505 12 10 F2         [24] 1502 	lcall	__gptrput
      000508                       1503 00111$:
                                   1504 ;	DS1302.h:105: if(SEL&0x20){
      000508 EC               [12] 1505 	mov	a,r4
      000509 30 E5 4A         [24] 1506 	jnb	acc.5,00113$
                                   1507 ;	DS1302.h:106: ds1302_unlock_reg();
      00050C 75 25 00         [24] 1508 	mov	_single_byte_write_PARM_2,#0x00
      00050F 75 82 8E         [24] 1509 	mov	dpl, #0x8e
      000512 C0 04            [24] 1510 	push	ar4
      000514 12 01 D7         [24] 1511 	lcall	_single_byte_write
                                   1512 ;	DS1302.h:107: byte_data = single_byte_read(0x89);
      000517 75 82 89         [24] 1513 	mov	dpl, #0x89
      00051A 12 02 63         [24] 1514 	lcall	_single_byte_read
      00051D AF 82            [24] 1515 	mov	r7, dpl
      00051F D0 04            [24] 1516 	pop	ar4
                                   1517 ;	DS1302.h:108: x10 = ((byte_data&0x10)>>4)*10;
      000521 8F 05            [24] 1518 	mov	ar5,r7
      000523 53 05 10         [24] 1519 	anl	ar5,#0x10
      000526 E4               [12] 1520 	clr	a
      000527 CD               [12] 1521 	xch	a,r5
      000528 C4               [12] 1522 	swap	a
      000529 54 0F            [12] 1523 	anl	a,#0x0f
      00052B 6D               [12] 1524 	xrl	a,r5
      00052C CD               [12] 1525 	xch	a,r5
      00052D 54 0F            [12] 1526 	anl	a,#0x0f
      00052F CD               [12] 1527 	xch	a,r5
      000530 6D               [12] 1528 	xrl	a,r5
      000531 CD               [12] 1529 	xch	a,r5
      000532 30 E3 02         [24] 1530 	jnb	acc.3,00180$
      000535 44 F0            [12] 1531 	orl	a,#0xfffffff0
      000537                       1532 00180$:
      000537 ED               [12] 1533 	mov	a,r5
      000538 75 F0 0A         [24] 1534 	mov	b,#0x0a
      00053B A4               [48] 1535 	mul	ab
      00053C FD               [12] 1536 	mov	r5,a
                                   1537 ;	DS1302.h:109: x1  = (byte_data&0x0F);
      00053D 53 07 0F         [24] 1538 	anl	ar7,#0x0f
                                   1539 ;	DS1302.h:110: time->MONTH = x10 + x1;
      000540 74 02            [12] 1540 	mov	a,#0x02
      000542 25 35            [12] 1541 	add	a, _ds1302_read_time_time_10000_37
      000544 FA               [12] 1542 	mov	r2,a
      000545 E4               [12] 1543 	clr	a
      000546 35 36            [12] 1544 	addc	a, (_ds1302_read_time_time_10000_37 + 1)
      000548 FB               [12] 1545 	mov	r3,a
      000549 AE 37            [24] 1546 	mov	r6,(_ds1302_read_time_time_10000_37 + 2)
      00054B EF               [12] 1547 	mov	a,r7
      00054C 2D               [12] 1548 	add	a, r5
      00054D 8A 82            [24] 1549 	mov	dpl,r2
      00054F 8B 83            [24] 1550 	mov	dph,r3
      000551 8E F0            [24] 1551 	mov	b,r6
      000553 12 10 F2         [24] 1552 	lcall	__gptrput
      000556                       1553 00113$:
                                   1554 ;	DS1302.h:113: if(SEL&0x40){
      000556 EC               [12] 1555 	mov	a,r4
      000557 30 E6 46         [24] 1556 	jnb	acc.6,00116$
                                   1557 ;	DS1302.h:114: ds1302_unlock_reg();
      00055A 75 25 00         [24] 1558 	mov	_single_byte_write_PARM_2,#0x00
      00055D 75 82 8E         [24] 1559 	mov	dpl, #0x8e
      000560 12 01 D7         [24] 1560 	lcall	_single_byte_write
                                   1561 ;	DS1302.h:115: byte_data = single_byte_read(0x87);
      000563 75 82 87         [24] 1562 	mov	dpl, #0x87
      000566 12 02 63         [24] 1563 	lcall	_single_byte_read
      000569 AF 82            [24] 1564 	mov	r7, dpl
                                   1565 ;	DS1302.h:116: x10 = ((byte_data&0xF0)>>4)*10;
      00056B 8F 05            [24] 1566 	mov	ar5,r7
      00056D 53 05 F0         [24] 1567 	anl	ar5,#0xf0
      000570 E4               [12] 1568 	clr	a
      000571 CD               [12] 1569 	xch	a,r5
      000572 C4               [12] 1570 	swap	a
      000573 54 0F            [12] 1571 	anl	a,#0x0f
      000575 6D               [12] 1572 	xrl	a,r5
      000576 CD               [12] 1573 	xch	a,r5
      000577 54 0F            [12] 1574 	anl	a,#0x0f
      000579 CD               [12] 1575 	xch	a,r5
      00057A 6D               [12] 1576 	xrl	a,r5
      00057B CD               [12] 1577 	xch	a,r5
      00057C 30 E3 02         [24] 1578 	jnb	acc.3,00182$
      00057F 44 F0            [12] 1579 	orl	a,#0xfffffff0
      000581                       1580 00182$:
      000581 ED               [12] 1581 	mov	a,r5
      000582 75 F0 0A         [24] 1582 	mov	b,#0x0a
      000585 A4               [48] 1583 	mul	ab
      000586 FD               [12] 1584 	mov	r5,a
                                   1585 ;	DS1302.h:117: x1  = (byte_data&0x0F);
      000587 53 07 0F         [24] 1586 	anl	ar7,#0x0f
                                   1587 ;	DS1302.h:118: time->YEAR = x10 + x1;
      00058A 74 03            [12] 1588 	mov	a,#0x03
      00058C 25 35            [12] 1589 	add	a, _ds1302_read_time_time_10000_37
      00058E FB               [12] 1590 	mov	r3,a
      00058F E4               [12] 1591 	clr	a
      000590 35 36            [12] 1592 	addc	a, (_ds1302_read_time_time_10000_37 + 1)
      000592 FC               [12] 1593 	mov	r4,a
      000593 AE 37            [24] 1594 	mov	r6,(_ds1302_read_time_time_10000_37 + 2)
      000595 EF               [12] 1595 	mov	a,r7
      000596 2D               [12] 1596 	add	a, r5
      000597 8B 82            [24] 1597 	mov	dpl,r3
      000599 8C 83            [24] 1598 	mov	dph,r4
      00059B 8E F0            [24] 1599 	mov	b,r6
                                   1600 ;	DS1302.h:120: }
      00059D 02 10 F2         [24] 1601 	ljmp	__gptrput
      0005A0                       1602 00116$:
      0005A0 22               [24] 1603 	ret
                                   1604 ;------------------------------------------------------------
                                   1605 ;Allocation info for local variables in function 'ds1302_write_time'
                                   1606 ;------------------------------------------------------------
                                   1607 ;SEL           Allocated with name '_ds1302_write_time_PARM_2'
                                   1608 ;time          Allocated to registers r5 r6 r7 
                                   1609 ;x10           Allocated to registers r3 
                                   1610 ;x1            Allocated to registers r1 
                                   1611 ;byte_data     Allocated to registers r1 
                                   1612 ;------------------------------------------------------------
                                   1613 ;	DS1302.h:122: void ds1302_write_time(TIME* const time, uint8 SEL){
                                   1614 ;	-----------------------------------------
                                   1615 ;	 function ds1302_write_time
                                   1616 ;	-----------------------------------------
      0005A1                       1617 _ds1302_write_time:
      0005A1 AD 82            [24] 1618 	mov	r5, dpl
      0005A3 AE 83            [24] 1619 	mov	r6, dph
      0005A5 AF F0            [24] 1620 	mov	r7, b
                                   1621 ;	DS1302.h:125: if(SEL&0x1){
      0005A7 E5 39            [12] 1622 	mov	a,_ds1302_write_time_PARM_2
      0005A9 FC               [12] 1623 	mov	r4,a
      0005AA 30 E0 4F         [24] 1624 	jnb	acc.0,00102$
                                   1625 ;	DS1302.h:126: x10 = (((*time).SECOND)/10)%10;
      0005AD 74 06            [12] 1626 	mov	a,#0x06
      0005AF 2D               [12] 1627 	add	a, r5
      0005B0 F9               [12] 1628 	mov	r1,a
      0005B1 E4               [12] 1629 	clr	a
      0005B2 3E               [12] 1630 	addc	a, r6
      0005B3 FA               [12] 1631 	mov	r2,a
      0005B4 8F 03            [24] 1632 	mov	ar3,r7
      0005B6 89 82            [24] 1633 	mov	dpl,r1
      0005B8 8A 83            [24] 1634 	mov	dph,r2
      0005BA 8B F0            [24] 1635 	mov	b,r3
      0005BC 12 11 77         [24] 1636 	lcall	__gptrget
      0005BF F9               [12] 1637 	mov	r1,a
      0005C0 75 F0 0A         [24] 1638 	mov	b,#0x0a
      0005C3 84               [48] 1639 	div	ab
      0005C4 75 F0 0A         [24] 1640 	mov	b,#0x0a
      0005C7 84               [48] 1641 	div	ab
      0005C8 AB F0            [24] 1642 	mov	r3,b
                                   1643 ;	DS1302.h:127: x1  = ((*time).SECOND)%10;
      0005CA 75 F0 0A         [24] 1644 	mov	b,#0x0a
      0005CD E9               [12] 1645 	mov	a,r1
      0005CE 84               [48] 1646 	div	ab
      0005CF A9 F0            [24] 1647 	mov	r1,b
                                   1648 ;	DS1302.h:128: byte_data = (x10<<4) + x1;
      0005D1 EB               [12] 1649 	mov	a,r3
      0005D2 C4               [12] 1650 	swap	a
      0005D3 54 F0            [12] 1651 	anl	a,#0xf0
      0005D5 29               [12] 1652 	add	a,r1
      0005D6 FB               [12] 1653 	mov	r3,a
                                   1654 ;	DS1302.h:129: ds1302_unlock_reg();
      0005D7 75 25 00         [24] 1655 	mov	_single_byte_write_PARM_2,#0x00
      0005DA 75 82 8E         [24] 1656 	mov	dpl, #0x8e
      0005DD C0 07            [24] 1657 	push	ar7
      0005DF C0 06            [24] 1658 	push	ar6
      0005E1 C0 05            [24] 1659 	push	ar5
      0005E3 C0 04            [24] 1660 	push	ar4
      0005E5 C0 03            [24] 1661 	push	ar3
      0005E7 12 01 D7         [24] 1662 	lcall	_single_byte_write
      0005EA D0 03            [24] 1663 	pop	ar3
                                   1664 ;	DS1302.h:130: single_byte_write(0x80, byte_data);
      0005EC 8B 25            [24] 1665 	mov	_single_byte_write_PARM_2,r3
      0005EE 75 82 80         [24] 1666 	mov	dpl, #0x80
      0005F1 12 01 D7         [24] 1667 	lcall	_single_byte_write
      0005F4 D0 04            [24] 1668 	pop	ar4
      0005F6 D0 05            [24] 1669 	pop	ar5
      0005F8 D0 06            [24] 1670 	pop	ar6
      0005FA D0 07            [24] 1671 	pop	ar7
      0005FC                       1672 00102$:
                                   1673 ;	DS1302.h:133: if(SEL&0x2){
      0005FC EC               [12] 1674 	mov	a,r4
      0005FD 30 E1 4F         [24] 1675 	jnb	acc.1,00104$
                                   1676 ;	DS1302.h:134: x10 = ((time->MINUTE)/10)%10;
      000600 74 05            [12] 1677 	mov	a,#0x05
      000602 2D               [12] 1678 	add	a, r5
      000603 F9               [12] 1679 	mov	r1,a
      000604 E4               [12] 1680 	clr	a
      000605 3E               [12] 1681 	addc	a, r6
      000606 FA               [12] 1682 	mov	r2,a
      000607 8F 03            [24] 1683 	mov	ar3,r7
      000609 89 82            [24] 1684 	mov	dpl,r1
      00060B 8A 83            [24] 1685 	mov	dph,r2
      00060D 8B F0            [24] 1686 	mov	b,r3
      00060F 12 11 77         [24] 1687 	lcall	__gptrget
      000612 F9               [12] 1688 	mov	r1,a
      000613 75 F0 0A         [24] 1689 	mov	b,#0x0a
      000616 84               [48] 1690 	div	ab
      000617 75 F0 0A         [24] 1691 	mov	b,#0x0a
      00061A 84               [48] 1692 	div	ab
      00061B AB F0            [24] 1693 	mov	r3,b
                                   1694 ;	DS1302.h:135: x1  = (time->MINUTE)%10;
      00061D 75 F0 0A         [24] 1695 	mov	b,#0x0a
      000620 E9               [12] 1696 	mov	a,r1
      000621 84               [48] 1697 	div	ab
      000622 A9 F0            [24] 1698 	mov	r1,b
                                   1699 ;	DS1302.h:136: byte_data = (x10<<4) + x1;
      000624 EB               [12] 1700 	mov	a,r3
      000625 C4               [12] 1701 	swap	a
      000626 54 F0            [12] 1702 	anl	a,#0xf0
      000628 29               [12] 1703 	add	a,r1
      000629 FB               [12] 1704 	mov	r3,a
                                   1705 ;	DS1302.h:137: ds1302_unlock_reg();
      00062A 75 25 00         [24] 1706 	mov	_single_byte_write_PARM_2,#0x00
      00062D 75 82 8E         [24] 1707 	mov	dpl, #0x8e
      000630 C0 07            [24] 1708 	push	ar7
      000632 C0 06            [24] 1709 	push	ar6
      000634 C0 05            [24] 1710 	push	ar5
      000636 C0 04            [24] 1711 	push	ar4
      000638 C0 03            [24] 1712 	push	ar3
      00063A 12 01 D7         [24] 1713 	lcall	_single_byte_write
      00063D D0 03            [24] 1714 	pop	ar3
                                   1715 ;	DS1302.h:138: single_byte_write(0x82, byte_data);
      00063F 8B 25            [24] 1716 	mov	_single_byte_write_PARM_2,r3
      000641 75 82 82         [24] 1717 	mov	dpl, #0x82
      000644 12 01 D7         [24] 1718 	lcall	_single_byte_write
      000647 D0 04            [24] 1719 	pop	ar4
      000649 D0 05            [24] 1720 	pop	ar5
      00064B D0 06            [24] 1721 	pop	ar6
      00064D D0 07            [24] 1722 	pop	ar7
      00064F                       1723 00104$:
                                   1724 ;	DS1302.h:141: if(SEL&0x4){
      00064F EC               [12] 1725 	mov	a,r4
      000650 30 E2 4F         [24] 1726 	jnb	acc.2,00106$
                                   1727 ;	DS1302.h:142: x10 = ((time->HOUR)/10)%10;
      000653 74 04            [12] 1728 	mov	a,#0x04
      000655 2D               [12] 1729 	add	a, r5
      000656 F9               [12] 1730 	mov	r1,a
      000657 E4               [12] 1731 	clr	a
      000658 3E               [12] 1732 	addc	a, r6
      000659 FA               [12] 1733 	mov	r2,a
      00065A 8F 03            [24] 1734 	mov	ar3,r7
      00065C 89 82            [24] 1735 	mov	dpl,r1
      00065E 8A 83            [24] 1736 	mov	dph,r2
      000660 8B F0            [24] 1737 	mov	b,r3
      000662 12 11 77         [24] 1738 	lcall	__gptrget
      000665 F9               [12] 1739 	mov	r1,a
      000666 75 F0 0A         [24] 1740 	mov	b,#0x0a
      000669 84               [48] 1741 	div	ab
      00066A 75 F0 0A         [24] 1742 	mov	b,#0x0a
      00066D 84               [48] 1743 	div	ab
      00066E AB F0            [24] 1744 	mov	r3,b
                                   1745 ;	DS1302.h:143: x1  = (time->HOUR)%10;
      000670 75 F0 0A         [24] 1746 	mov	b,#0x0a
      000673 E9               [12] 1747 	mov	a,r1
      000674 84               [48] 1748 	div	ab
      000675 A9 F0            [24] 1749 	mov	r1,b
                                   1750 ;	DS1302.h:144: byte_data = (x10<<4) + x1;
      000677 EB               [12] 1751 	mov	a,r3
      000678 C4               [12] 1752 	swap	a
      000679 54 F0            [12] 1753 	anl	a,#0xf0
      00067B 29               [12] 1754 	add	a,r1
      00067C FB               [12] 1755 	mov	r3,a
                                   1756 ;	DS1302.h:145: ds1302_unlock_reg();
      00067D 75 25 00         [24] 1757 	mov	_single_byte_write_PARM_2,#0x00
      000680 75 82 8E         [24] 1758 	mov	dpl, #0x8e
      000683 C0 07            [24] 1759 	push	ar7
      000685 C0 06            [24] 1760 	push	ar6
      000687 C0 05            [24] 1761 	push	ar5
      000689 C0 04            [24] 1762 	push	ar4
      00068B C0 03            [24] 1763 	push	ar3
      00068D 12 01 D7         [24] 1764 	lcall	_single_byte_write
      000690 D0 03            [24] 1765 	pop	ar3
                                   1766 ;	DS1302.h:146: single_byte_write(0x84, byte_data);
      000692 8B 25            [24] 1767 	mov	_single_byte_write_PARM_2,r3
      000694 75 82 84         [24] 1768 	mov	dpl, #0x84
      000697 12 01 D7         [24] 1769 	lcall	_single_byte_write
      00069A D0 04            [24] 1770 	pop	ar4
      00069C D0 05            [24] 1771 	pop	ar5
      00069E D0 06            [24] 1772 	pop	ar6
      0006A0 D0 07            [24] 1773 	pop	ar7
      0006A2                       1774 00106$:
                                   1775 ;	DS1302.h:149: if(SEL&0x8){
      0006A2 EC               [12] 1776 	mov	a,r4
      0006A3 30 E3 4F         [24] 1777 	jnb	acc.3,00108$
                                   1778 ;	DS1302.h:150: x10 = ((time->DATE)/10)%10;
      0006A6 74 01            [12] 1779 	mov	a,#0x01
      0006A8 2D               [12] 1780 	add	a, r5
      0006A9 F9               [12] 1781 	mov	r1,a
      0006AA E4               [12] 1782 	clr	a
      0006AB 3E               [12] 1783 	addc	a, r6
      0006AC FA               [12] 1784 	mov	r2,a
      0006AD 8F 03            [24] 1785 	mov	ar3,r7
      0006AF 89 82            [24] 1786 	mov	dpl,r1
      0006B1 8A 83            [24] 1787 	mov	dph,r2
      0006B3 8B F0            [24] 1788 	mov	b,r3
      0006B5 12 11 77         [24] 1789 	lcall	__gptrget
      0006B8 F9               [12] 1790 	mov	r1,a
      0006B9 75 F0 0A         [24] 1791 	mov	b,#0x0a
      0006BC 84               [48] 1792 	div	ab
      0006BD 75 F0 0A         [24] 1793 	mov	b,#0x0a
      0006C0 84               [48] 1794 	div	ab
      0006C1 AB F0            [24] 1795 	mov	r3,b
                                   1796 ;	DS1302.h:151: x1  = (time->DATE)%10;
      0006C3 75 F0 0A         [24] 1797 	mov	b,#0x0a
      0006C6 E9               [12] 1798 	mov	a,r1
      0006C7 84               [48] 1799 	div	ab
      0006C8 A9 F0            [24] 1800 	mov	r1,b
                                   1801 ;	DS1302.h:152: byte_data = (x10<<4) + x1;
      0006CA EB               [12] 1802 	mov	a,r3
      0006CB C4               [12] 1803 	swap	a
      0006CC 54 F0            [12] 1804 	anl	a,#0xf0
      0006CE 29               [12] 1805 	add	a,r1
      0006CF F9               [12] 1806 	mov	r1,a
                                   1807 ;	DS1302.h:153: ds1302_unlock_reg();
      0006D0 75 25 00         [24] 1808 	mov	_single_byte_write_PARM_2,#0x00
      0006D3 75 82 8E         [24] 1809 	mov	dpl, #0x8e
      0006D6 C0 07            [24] 1810 	push	ar7
      0006D8 C0 06            [24] 1811 	push	ar6
      0006DA C0 05            [24] 1812 	push	ar5
      0006DC C0 04            [24] 1813 	push	ar4
      0006DE C0 01            [24] 1814 	push	ar1
      0006E0 12 01 D7         [24] 1815 	lcall	_single_byte_write
      0006E3 D0 01            [24] 1816 	pop	ar1
                                   1817 ;	DS1302.h:154: single_byte_write(0x86, byte_data);
      0006E5 89 25            [24] 1818 	mov	_single_byte_write_PARM_2,r1
      0006E7 75 82 86         [24] 1819 	mov	dpl, #0x86
      0006EA 12 01 D7         [24] 1820 	lcall	_single_byte_write
      0006ED D0 04            [24] 1821 	pop	ar4
      0006EF D0 05            [24] 1822 	pop	ar5
      0006F1 D0 06            [24] 1823 	pop	ar6
      0006F3 D0 07            [24] 1824 	pop	ar7
      0006F5                       1825 00108$:
                                   1826 ;	DS1302.h:157: if(SEL&0x10){
      0006F5 EC               [12] 1827 	mov	a,r4
      0006F6 30 E4 4F         [24] 1828 	jnb	acc.4,00110$
                                   1829 ;	DS1302.h:158: x10 = ((time->MONTH)/10)%10;
      0006F9 74 02            [12] 1830 	mov	a,#0x02
      0006FB 2D               [12] 1831 	add	a, r5
      0006FC F9               [12] 1832 	mov	r1,a
      0006FD E4               [12] 1833 	clr	a
      0006FE 3E               [12] 1834 	addc	a, r6
      0006FF FA               [12] 1835 	mov	r2,a
      000700 8F 03            [24] 1836 	mov	ar3,r7
      000702 89 82            [24] 1837 	mov	dpl,r1
      000704 8A 83            [24] 1838 	mov	dph,r2
      000706 8B F0            [24] 1839 	mov	b,r3
      000708 12 11 77         [24] 1840 	lcall	__gptrget
      00070B F9               [12] 1841 	mov	r1,a
      00070C 75 F0 0A         [24] 1842 	mov	b,#0x0a
      00070F 84               [48] 1843 	div	ab
      000710 75 F0 0A         [24] 1844 	mov	b,#0x0a
      000713 84               [48] 1845 	div	ab
      000714 AB F0            [24] 1846 	mov	r3,b
                                   1847 ;	DS1302.h:159: x1  = (time->MONTH)%10;
      000716 75 F0 0A         [24] 1848 	mov	b,#0x0a
      000719 E9               [12] 1849 	mov	a,r1
      00071A 84               [48] 1850 	div	ab
      00071B A9 F0            [24] 1851 	mov	r1,b
                                   1852 ;	DS1302.h:160: byte_data = (x10<<4) + x1;
      00071D EB               [12] 1853 	mov	a,r3
      00071E C4               [12] 1854 	swap	a
      00071F 54 F0            [12] 1855 	anl	a,#0xf0
      000721 29               [12] 1856 	add	a,r1
      000722 FB               [12] 1857 	mov	r3,a
                                   1858 ;	DS1302.h:161: ds1302_unlock_reg();
      000723 75 25 00         [24] 1859 	mov	_single_byte_write_PARM_2,#0x00
      000726 75 82 8E         [24] 1860 	mov	dpl, #0x8e
      000729 C0 07            [24] 1861 	push	ar7
      00072B C0 06            [24] 1862 	push	ar6
      00072D C0 05            [24] 1863 	push	ar5
      00072F C0 04            [24] 1864 	push	ar4
      000731 C0 03            [24] 1865 	push	ar3
      000733 12 01 D7         [24] 1866 	lcall	_single_byte_write
      000736 D0 03            [24] 1867 	pop	ar3
                                   1868 ;	DS1302.h:162: single_byte_write(0x88, byte_data);
      000738 8B 25            [24] 1869 	mov	_single_byte_write_PARM_2,r3
      00073A 75 82 88         [24] 1870 	mov	dpl, #0x88
      00073D 12 01 D7         [24] 1871 	lcall	_single_byte_write
      000740 D0 04            [24] 1872 	pop	ar4
      000742 D0 05            [24] 1873 	pop	ar5
      000744 D0 06            [24] 1874 	pop	ar6
      000746 D0 07            [24] 1875 	pop	ar7
      000748                       1876 00110$:
                                   1877 ;	DS1302.h:165: if(SEL&0x20){
      000748 EC               [12] 1878 	mov	a,r4
      000749 30 E5 4F         [24] 1879 	jnb	acc.5,00112$
                                   1880 ;	DS1302.h:166: x10 = ((time->YEAR)/10)%10;
      00074C 74 03            [12] 1881 	mov	a,#0x03
      00074E 2D               [12] 1882 	add	a, r5
      00074F F9               [12] 1883 	mov	r1,a
      000750 E4               [12] 1884 	clr	a
      000751 3E               [12] 1885 	addc	a, r6
      000752 FA               [12] 1886 	mov	r2,a
      000753 8F 03            [24] 1887 	mov	ar3,r7
      000755 89 82            [24] 1888 	mov	dpl,r1
      000757 8A 83            [24] 1889 	mov	dph,r2
      000759 8B F0            [24] 1890 	mov	b,r3
      00075B 12 11 77         [24] 1891 	lcall	__gptrget
      00075E F9               [12] 1892 	mov	r1,a
      00075F 75 F0 0A         [24] 1893 	mov	b,#0x0a
      000762 84               [48] 1894 	div	ab
      000763 75 F0 0A         [24] 1895 	mov	b,#0x0a
      000766 84               [48] 1896 	div	ab
      000767 AB F0            [24] 1897 	mov	r3,b
                                   1898 ;	DS1302.h:167: x1  = (time->YEAR)%10;
      000769 75 F0 0A         [24] 1899 	mov	b,#0x0a
      00076C E9               [12] 1900 	mov	a,r1
      00076D 84               [48] 1901 	div	ab
      00076E A9 F0            [24] 1902 	mov	r1,b
                                   1903 ;	DS1302.h:168: byte_data = (x10<<4) + x1;
      000770 EB               [12] 1904 	mov	a,r3
      000771 C4               [12] 1905 	swap	a
      000772 54 F0            [12] 1906 	anl	a,#0xf0
      000774 29               [12] 1907 	add	a,r1
      000775 FB               [12] 1908 	mov	r3,a
                                   1909 ;	DS1302.h:169: ds1302_unlock_reg();
      000776 75 25 00         [24] 1910 	mov	_single_byte_write_PARM_2,#0x00
      000779 75 82 8E         [24] 1911 	mov	dpl, #0x8e
      00077C C0 07            [24] 1912 	push	ar7
      00077E C0 06            [24] 1913 	push	ar6
      000780 C0 05            [24] 1914 	push	ar5
      000782 C0 04            [24] 1915 	push	ar4
      000784 C0 03            [24] 1916 	push	ar3
      000786 12 01 D7         [24] 1917 	lcall	_single_byte_write
      000789 D0 03            [24] 1918 	pop	ar3
                                   1919 ;	DS1302.h:170: single_byte_write(0x9C, byte_data);
      00078B 8B 25            [24] 1920 	mov	_single_byte_write_PARM_2,r3
      00078D 75 82 9C         [24] 1921 	mov	dpl, #0x9c
      000790 12 01 D7         [24] 1922 	lcall	_single_byte_write
      000793 D0 04            [24] 1923 	pop	ar4
      000795 D0 05            [24] 1924 	pop	ar5
      000797 D0 06            [24] 1925 	pop	ar6
      000799 D0 07            [24] 1926 	pop	ar7
      00079B                       1927 00112$:
                                   1928 ;	DS1302.h:173: if(SEL&0x40){
      00079B EC               [12] 1929 	mov	a,r4
      00079C 30 E6 24         [24] 1930 	jnb	acc.6,00115$
                                   1931 ;	DS1302.h:174: x1  = (time->DAY)%10;
      00079F 8D 82            [24] 1932 	mov	dpl,r5
      0007A1 8E 83            [24] 1933 	mov	dph,r6
      0007A3 8F F0            [24] 1934 	mov	b,r7
      0007A5 12 11 77         [24] 1935 	lcall	__gptrget
      0007A8 75 F0 0A         [24] 1936 	mov	b,#0x0a
      0007AB 84               [48] 1937 	div	ab
      0007AC AD F0            [24] 1938 	mov	r5,b
                                   1939 ;	DS1302.h:175: ds1302_unlock_reg();
      0007AE 75 25 00         [24] 1940 	mov	_single_byte_write_PARM_2,#0x00
      0007B1 75 82 8E         [24] 1941 	mov	dpl, #0x8e
      0007B4 C0 05            [24] 1942 	push	ar5
      0007B6 12 01 D7         [24] 1943 	lcall	_single_byte_write
      0007B9 D0 05            [24] 1944 	pop	ar5
                                   1945 ;	DS1302.h:176: single_byte_write(0x9A, x1);
      0007BB 8D 25            [24] 1946 	mov	_single_byte_write_PARM_2,r5
      0007BD 75 82 9A         [24] 1947 	mov	dpl, #0x9a
                                   1948 ;	DS1302.h:178: }
      0007C0 02 01 D7         [24] 1949 	ljmp	_single_byte_write
      0007C3                       1950 00115$:
      0007C3 22               [24] 1951 	ret
                                   1952 ;------------------------------------------------------------
                                   1953 ;Allocation info for local variables in function 'ds1302_initial'
                                   1954 ;------------------------------------------------------------
                                   1955 ;	DS1302.h:180: void ds1302_initial(){
                                   1956 ;	-----------------------------------------
                                   1957 ;	 function ds1302_initial
                                   1958 ;	-----------------------------------------
      0007C4                       1959 _ds1302_initial:
                                   1960 ;	DS1302.h:181: ThreeWiresProtocol_Initial();
                                   1961 ;	DS1302.h:182: }
      0007C4 02 03 3A         [24] 1962 	ljmp	_ThreeWiresProtocol_Initial
                                   1963 ;------------------------------------------------------------
                                   1964 ;Allocation info for local variables in function 'led7seg_disp'
                                   1965 ;------------------------------------------------------------
                                   1966 ;CODE          Allocated with name '_led7seg_disp_PARM_2'
                                   1967 ;POS           Allocated to registers r7 
                                   1968 ;------------------------------------------------------------
                                   1969 ;	LED7Seg_OnKit.h:36: void led7seg_disp(uint8  POS, uint8  CODE){
                                   1970 ;	-----------------------------------------
                                   1971 ;	 function led7seg_disp
                                   1972 ;	-----------------------------------------
      0007C7                       1973 _led7seg_disp:
                                   1974 ;	LED7Seg_OnKit.h:37: switch (POS) {
      0007C7 E5 82            [12] 1975 	mov	a,dpl
      0007C9 FF               [12] 1976 	mov	r7,a
      0007CA 24 F7            [12] 1977 	add	a,#0xff - 0x08
      0007CC 50 03            [24] 1978 	jnc	00119$
      0007CE 02 08 41         [24] 1979 	ljmp	00109$
      0007D1                       1980 00119$:
      0007D1 EF               [12] 1981 	mov	a,r7
      0007D2 24 0A            [12] 1982 	add	a,#(00120$-3-.)
      0007D4 83               [24] 1983 	movc	a,@a+pc
      0007D5 F5 82            [12] 1984 	mov	dpl,a
      0007D7 EF               [12] 1985 	mov	a,r7
      0007D8 24 0D            [12] 1986 	add	a,#(00121$-3-.)
      0007DA 83               [24] 1987 	movc	a,@a+pc
      0007DB F5 83            [12] 1988 	mov	dph,a
      0007DD E4               [12] 1989 	clr	a
      0007DE 73               [24] 1990 	jmp	@a+dptr
      0007DF                       1991 00120$:
      0007DF 41                    1992 	.db	00109$
      0007E0 F1                    1993 	.db	00101$
      0007E1 FB                    1994 	.db	00102$
      0007E2 05                    1995 	.db	00103$
      0007E3 0F                    1996 	.db	00104$
      0007E4 19                    1997 	.db	00105$
      0007E5 23                    1998 	.db	00106$
      0007E6 2D                    1999 	.db	00107$
      0007E7 37                    2000 	.db	00108$
      0007E8                       2001 00121$:
      0007E8 08                    2002 	.db	00109$>>8
      0007E9 07                    2003 	.db	00101$>>8
      0007EA 07                    2004 	.db	00102$>>8
      0007EB 08                    2005 	.db	00103$>>8
      0007EC 08                    2006 	.db	00104$>>8
      0007ED 08                    2007 	.db	00105$>>8
      0007EE 08                    2008 	.db	00106$>>8
      0007EF 08                    2009 	.db	00107$>>8
      0007F0 08                    2010 	.db	00108$>>8
                                   2011 ;	LED7Seg_OnKit.h:38: case 0x1:
      0007F1                       2012 00101$:
                                   2013 ;	LED7Seg_OnKit.h:39: { GND0 = 0; GND1 = 0; GND2 = 0; LED_7SEG = CODE; return;}
                                   2014 ;	assignBit
      0007F1 C2 A2            [12] 2015 	clr	_GND0
                                   2016 ;	assignBit
      0007F3 C2 A3            [12] 2017 	clr	_GND1
                                   2018 ;	assignBit
      0007F5 C2 A4            [12] 2019 	clr	_GND2
      0007F7 85 08 80         [24] 2020 	mov	_P0,_led7seg_disp_PARM_2
                                   2021 ;	LED7Seg_OnKit.h:40: case 0x2:
      0007FA 22               [24] 2022 	ret
      0007FB                       2023 00102$:
                                   2024 ;	LED7Seg_OnKit.h:41: { GND0 = 1; GND1 = 0; GND2 = 0; LED_7SEG = CODE; return;}
                                   2025 ;	assignBit
      0007FB D2 A2            [12] 2026 	setb	_GND0
                                   2027 ;	assignBit
      0007FD C2 A3            [12] 2028 	clr	_GND1
                                   2029 ;	assignBit
      0007FF C2 A4            [12] 2030 	clr	_GND2
      000801 85 08 80         [24] 2031 	mov	_P0,_led7seg_disp_PARM_2
                                   2032 ;	LED7Seg_OnKit.h:42: case 0x3:
      000804 22               [24] 2033 	ret
      000805                       2034 00103$:
                                   2035 ;	LED7Seg_OnKit.h:43: { GND0 = 0; GND1 = 1; GND2 = 0; LED_7SEG = CODE; return;}
                                   2036 ;	assignBit
      000805 C2 A2            [12] 2037 	clr	_GND0
                                   2038 ;	assignBit
      000807 D2 A3            [12] 2039 	setb	_GND1
                                   2040 ;	assignBit
      000809 C2 A4            [12] 2041 	clr	_GND2
      00080B 85 08 80         [24] 2042 	mov	_P0,_led7seg_disp_PARM_2
                                   2043 ;	LED7Seg_OnKit.h:44: case 0x4:
      00080E 22               [24] 2044 	ret
      00080F                       2045 00104$:
                                   2046 ;	LED7Seg_OnKit.h:45: { GND0 = 1; GND1 = 1; GND2 = 0; LED_7SEG = CODE; return;}
                                   2047 ;	assignBit
      00080F D2 A2            [12] 2048 	setb	_GND0
                                   2049 ;	assignBit
      000811 D2 A3            [12] 2050 	setb	_GND1
                                   2051 ;	assignBit
      000813 C2 A4            [12] 2052 	clr	_GND2
      000815 85 08 80         [24] 2053 	mov	_P0,_led7seg_disp_PARM_2
                                   2054 ;	LED7Seg_OnKit.h:46: case 0x5:
      000818 22               [24] 2055 	ret
      000819                       2056 00105$:
                                   2057 ;	LED7Seg_OnKit.h:47: { GND0 = 0; GND1 = 0; GND2 = 1; LED_7SEG = CODE; return;}
                                   2058 ;	assignBit
      000819 C2 A2            [12] 2059 	clr	_GND0
                                   2060 ;	assignBit
      00081B C2 A3            [12] 2061 	clr	_GND1
                                   2062 ;	assignBit
      00081D D2 A4            [12] 2063 	setb	_GND2
      00081F 85 08 80         [24] 2064 	mov	_P0,_led7seg_disp_PARM_2
                                   2065 ;	LED7Seg_OnKit.h:48: case 0x6:
      000822 22               [24] 2066 	ret
      000823                       2067 00106$:
                                   2068 ;	LED7Seg_OnKit.h:49: { GND0 = 1; GND1 = 0; GND2 = 1; LED_7SEG = CODE; return;}
                                   2069 ;	assignBit
      000823 D2 A2            [12] 2070 	setb	_GND0
                                   2071 ;	assignBit
      000825 C2 A3            [12] 2072 	clr	_GND1
                                   2073 ;	assignBit
      000827 D2 A4            [12] 2074 	setb	_GND2
      000829 85 08 80         [24] 2075 	mov	_P0,_led7seg_disp_PARM_2
                                   2076 ;	LED7Seg_OnKit.h:50: case 0x7:
      00082C 22               [24] 2077 	ret
      00082D                       2078 00107$:
                                   2079 ;	LED7Seg_OnKit.h:51: { GND0 = 0; GND1 = 1; GND2 = 1; LED_7SEG = CODE; return;}
                                   2080 ;	assignBit
      00082D C2 A2            [12] 2081 	clr	_GND0
                                   2082 ;	assignBit
      00082F D2 A3            [12] 2083 	setb	_GND1
                                   2084 ;	assignBit
      000831 D2 A4            [12] 2085 	setb	_GND2
      000833 85 08 80         [24] 2086 	mov	_P0,_led7seg_disp_PARM_2
                                   2087 ;	LED7Seg_OnKit.h:52: case 0x8:
      000836 22               [24] 2088 	ret
      000837                       2089 00108$:
                                   2090 ;	LED7Seg_OnKit.h:53: { GND0 = 1; GND1 = 1; GND2 = 1; LED_7SEG = CODE; return;}
                                   2091 ;	assignBit
      000837 D2 A2            [12] 2092 	setb	_GND0
                                   2093 ;	assignBit
      000839 D2 A3            [12] 2094 	setb	_GND1
                                   2095 ;	assignBit
      00083B D2 A4            [12] 2096 	setb	_GND2
      00083D 85 08 80         [24] 2097 	mov	_P0,_led7seg_disp_PARM_2
                                   2098 ;	LED7Seg_OnKit.h:54: default:
      000840 22               [24] 2099 	ret
      000841                       2100 00109$:
                                   2101 ;	LED7Seg_OnKit.h:55: LED_7SEG = 0x0;
      000841 75 80 00         [24] 2102 	mov	_P0,#0x00
                                   2103 ;	LED7Seg_OnKit.h:56: }
                                   2104 ;	LED7Seg_OnKit.h:57: }
      000844 22               [24] 2105 	ret
                                   2106 ;------------------------------------------------------------
                                   2107 ;Allocation info for local variables in function 'Disp8leds7seg'
                                   2108 ;------------------------------------------------------------
                                   2109 ;ms_disp_t     Allocated to registers r6 r7 
                                   2110 ;i             Allocated to registers r3 
                                   2111 ;j             Allocated to registers r4 r5 
                                   2112 ;------------------------------------------------------------
                                   2113 ;	LED7Seg_OnKit.h:70: void Disp8leds7seg(uint32 ms_disp_t){
                                   2114 ;	-----------------------------------------
                                   2115 ;	 function Disp8leds7seg
                                   2116 ;	-----------------------------------------
      000845                       2117 _Disp8leds7seg:
      000845 AE 82            [24] 2118 	mov	r6, dpl
      000847 AF 83            [24] 2119 	mov	r7, dph
                                   2120 ;	LED7Seg_OnKit.h:73: REP(j, 1, ms_disp_t)
      000849 7C 01            [12] 2121 	mov	r4,#0x01
      00084B 7D 00            [12] 2122 	mov	r5,#0x00
      00084D                       2123 00106$:
      00084D C3               [12] 2124 	clr	c
      00084E EE               [12] 2125 	mov	a,r6
      00084F 9C               [12] 2126 	subb	a,r4
      000850 EF               [12] 2127 	mov	a,r7
      000851 9D               [12] 2128 	subb	a,r5
      000852 40 3B            [24] 2129 	jc	00108$
                                   2130 ;	LED7Seg_OnKit.h:74: REP(i, 0, 7){
      000854 7B 00            [12] 2131 	mov	r3,#0x00
      000856                       2132 00103$:
                                   2133 ;	LED7Seg_OnKit.h:75: led7seg_disp(i+1, LED[i]);
      000856 8B 02            [24] 2134 	mov	ar2,r3
      000858 EA               [12] 2135 	mov	a,r2
      000859 04               [12] 2136 	inc	a
      00085A F5 82            [12] 2137 	mov	dpl,a
      00085C EB               [12] 2138 	mov	a,r3
      00085D 24 3A            [12] 2139 	add	a, #_LED
      00085F F9               [12] 2140 	mov	r1,a
      000860 87 08            [24] 2141 	mov	_led7seg_disp_PARM_2,@r1
      000862 C0 07            [24] 2142 	push	ar7
      000864 C0 06            [24] 2143 	push	ar6
      000866 C0 05            [24] 2144 	push	ar5
      000868 C0 04            [24] 2145 	push	ar4
      00086A C0 03            [24] 2146 	push	ar3
      00086C 12 07 C7         [24] 2147 	lcall	_led7seg_disp
                                   2148 ;	LED7Seg_OnKit.h:76: delay_us(5);
      00086F 90 00 05         [24] 2149 	mov	dptr,#0x0005
      000872 12 01 3D         [24] 2150 	lcall	_delay_us
      000875 D0 03            [24] 2151 	pop	ar3
      000877 D0 04            [24] 2152 	pop	ar4
      000879 D0 05            [24] 2153 	pop	ar5
      00087B D0 06            [24] 2154 	pop	ar6
      00087D D0 07            [24] 2155 	pop	ar7
                                   2156 ;	LED7Seg_OnKit.h:77: LED_7SEG = 0x0;
      00087F 75 80 00         [24] 2157 	mov	_P0,#0x00
                                   2158 ;	LED7Seg_OnKit.h:74: REP(i, 0, 7){
      000882 0B               [12] 2159 	inc	r3
      000883 EB               [12] 2160 	mov	a,r3
      000884 24 F8            [12] 2161 	add	a,#0xff - 0x07
      000886 50 CE            [24] 2162 	jnc	00103$
                                   2163 ;	LED7Seg_OnKit.h:73: REP(j, 1, ms_disp_t)
      000888 0C               [12] 2164 	inc	r4
      000889 BC 00 C1         [24] 2165 	cjne	r4,#0x00,00106$
      00088C 0D               [12] 2166 	inc	r5
      00088D 80 BE            [24] 2167 	sjmp	00106$
      00088F                       2168 00108$:
                                   2169 ;	LED7Seg_OnKit.h:79: }
      00088F 22               [24] 2170 	ret
                                   2171 ;------------------------------------------------------------
                                   2172 ;Allocation info for local variables in function 'Row_Write'
                                   2173 ;------------------------------------------------------------
                                   2174 ;I             Allocated to registers r7 
                                   2175 ;------------------------------------------------------------
                                   2176 ;	Matrix_Button.h:24: void Row_Write(uint8 I){
                                   2177 ;	-----------------------------------------
                                   2178 ;	 function Row_Write
                                   2179 ;	-----------------------------------------
      000890                       2180 _Row_Write:
                                   2181 ;	Matrix_Button.h:25: switch (I){
      000890 E5 82            [12] 2182 	mov	a,dpl
      000892 FF               [12] 2183 	mov	r7,a
      000893 24 FC            [12] 2184 	add	a,#0xff - 0x03
      000895 40 31            [24] 2185 	jc	00106$
      000897 EF               [12] 2186 	mov	a,r7
      000898 2F               [12] 2187 	add	a,r7
                                   2188 ;	Matrix_Button.h:26: case 0:
      000899 90 08 9D         [24] 2189 	mov	dptr,#00115$
      00089C 73               [24] 2190 	jmp	@a+dptr
      00089D                       2191 00115$:
      00089D 80 06            [24] 2192 	sjmp	00101$
      00089F 80 0D            [24] 2193 	sjmp	00102$
      0008A1 80 14            [24] 2194 	sjmp	00103$
      0008A3 80 1B            [24] 2195 	sjmp	00104$
      0008A5                       2196 00101$:
                                   2197 ;	Matrix_Button.h:27: ROW0 = 0; ROW1 = 1; ROW2 = 1; ROW3 = 1;
                                   2198 ;	assignBit
      0008A5 C2 97            [12] 2199 	clr	_ROW0
                                   2200 ;	assignBit
      0008A7 D2 96            [12] 2201 	setb	_ROW1
                                   2202 ;	assignBit
      0008A9 D2 95            [12] 2203 	setb	_ROW2
                                   2204 ;	assignBit
      0008AB D2 94            [12] 2205 	setb	_ROW3
                                   2206 ;	Matrix_Button.h:28: break;
                                   2207 ;	Matrix_Button.h:29: case 1:
      0008AD 22               [24] 2208 	ret
      0008AE                       2209 00102$:
                                   2210 ;	Matrix_Button.h:30: ROW0 = 1; ROW1 = 0; ROW2 = 1; ROW3 = 1;
                                   2211 ;	assignBit
      0008AE D2 97            [12] 2212 	setb	_ROW0
                                   2213 ;	assignBit
      0008B0 C2 96            [12] 2214 	clr	_ROW1
                                   2215 ;	assignBit
      0008B2 D2 95            [12] 2216 	setb	_ROW2
                                   2217 ;	assignBit
      0008B4 D2 94            [12] 2218 	setb	_ROW3
                                   2219 ;	Matrix_Button.h:31: break;
                                   2220 ;	Matrix_Button.h:32: case 2:
      0008B6 22               [24] 2221 	ret
      0008B7                       2222 00103$:
                                   2223 ;	Matrix_Button.h:33: ROW0 = 1;  ROW1 = 1; ROW2 = 0; ROW3 = 1;
                                   2224 ;	assignBit
      0008B7 D2 97            [12] 2225 	setb	_ROW0
                                   2226 ;	assignBit
      0008B9 D2 96            [12] 2227 	setb	_ROW1
                                   2228 ;	assignBit
      0008BB C2 95            [12] 2229 	clr	_ROW2
                                   2230 ;	assignBit
      0008BD D2 94            [12] 2231 	setb	_ROW3
                                   2232 ;	Matrix_Button.h:34: break;
                                   2233 ;	Matrix_Button.h:35: case 3:
      0008BF 22               [24] 2234 	ret
      0008C0                       2235 00104$:
                                   2236 ;	Matrix_Button.h:36: ROW0 = 1;  ROW1 = 1; ROW2 = 1; ROW3 = 0;
                                   2237 ;	assignBit
      0008C0 D2 97            [12] 2238 	setb	_ROW0
                                   2239 ;	assignBit
      0008C2 D2 96            [12] 2240 	setb	_ROW1
                                   2241 ;	assignBit
      0008C4 D2 95            [12] 2242 	setb	_ROW2
                                   2243 ;	assignBit
      0008C6 C2 94            [12] 2244 	clr	_ROW3
                                   2245 ;	Matrix_Button.h:38: }
      0008C8                       2246 00106$:
                                   2247 ;	Matrix_Button.h:39: }
      0008C8 22               [24] 2248 	ret
                                   2249 ;------------------------------------------------------------
                                   2250 ;Allocation info for local variables in function 'Col_Read'
                                   2251 ;------------------------------------------------------------
                                   2252 ;COL           Allocated to registers r6 r7 
                                   2253 ;------------------------------------------------------------
                                   2254 ;	Matrix_Button.h:41: uint32 Col_Read(){
                                   2255 ;	-----------------------------------------
                                   2256 ;	 function Col_Read
                                   2257 ;	-----------------------------------------
      0008C9                       2258 _Col_Read:
                                   2259 ;	Matrix_Button.h:42: uint32 COL = 0;
      0008C9 7E 00            [12] 2260 	mov	r6,#0x00
      0008CB 7F 00            [12] 2261 	mov	r7,#0x00
                                   2262 ;	Matrix_Button.h:43: if(COL0 == 0) COL += 1;
      0008CD 20 93 04         [24] 2263 	jb	_COL0,00102$
      0008D0 7E 01            [12] 2264 	mov	r6,#0x01
      0008D2 7F 00            [12] 2265 	mov	r7,#0x00
      0008D4                       2266 00102$:
                                   2267 ;	Matrix_Button.h:44: if(COL1 == 0) COL += 2;
      0008D4 20 92 07         [24] 2268 	jb	_COL1,00104$
      0008D7 74 02            [12] 2269 	mov	a,#0x02
      0008D9 2E               [12] 2270 	add	a, r6
      0008DA FE               [12] 2271 	mov	r6,a
      0008DB E4               [12] 2272 	clr	a
      0008DC 3F               [12] 2273 	addc	a, r7
      0008DD FF               [12] 2274 	mov	r7,a
      0008DE                       2275 00104$:
                                   2276 ;	Matrix_Button.h:45: if(COL2 == 0) COL += 4;
      0008DE 20 91 07         [24] 2277 	jb	_COL2,00106$
      0008E1 74 04            [12] 2278 	mov	a,#0x04
      0008E3 2E               [12] 2279 	add	a, r6
      0008E4 FE               [12] 2280 	mov	r6,a
      0008E5 E4               [12] 2281 	clr	a
      0008E6 3F               [12] 2282 	addc	a, r7
      0008E7 FF               [12] 2283 	mov	r7,a
      0008E8                       2284 00106$:
                                   2285 ;	Matrix_Button.h:46: if(COL3 == 0) COL += 8;
      0008E8 20 90 06         [24] 2286 	jb	_COL3,00108$
      0008EB 74 08            [12] 2287 	mov	a,#0x08
      0008ED 2E               [12] 2288 	add	a, r6
      0008EE FE               [12] 2289 	mov	r6,a
      0008EF E4               [12] 2290 	clr	a
      0008F0 3F               [12] 2291 	addc	a, r7
      0008F1                       2292 00108$:
                                   2293 ;	Matrix_Button.h:47: return COL&0x0F;
      0008F1 74 0F            [12] 2294 	mov	a,#0x0f
      0008F3 5E               [12] 2295 	anl	a,r6
      0008F4 F5 82            [12] 2296 	mov	dpl,a
      0008F6 75 83 00         [24] 2297 	mov	dph,#0x00
                                   2298 ;	Matrix_Button.h:48: }
      0008F9 22               [24] 2299 	ret
                                   2300 ;------------------------------------------------------------
                                   2301 ;Allocation info for local variables in function 'Get_BTN_MATRIX'
                                   2302 ;------------------------------------------------------------
                                   2303 ;i             Allocated to registers r7 
                                   2304 ;------------------------------------------------------------
                                   2305 ;	Matrix_Button.h:50: uint32 Get_BTN_MATRIX(){
                                   2306 ;	-----------------------------------------
                                   2307 ;	 function Get_BTN_MATRIX
                                   2308 ;	-----------------------------------------
      0008FA                       2309 _Get_BTN_MATRIX:
                                   2310 ;	Matrix_Button.h:52: BTN_MATRIX = 0;
      0008FA E4               [12] 2311 	clr	a
      0008FB F5 42            [12] 2312 	mov	_BTN_MATRIX,a
      0008FD F5 43            [12] 2313 	mov	(_BTN_MATRIX + 1),a
                                   2314 ;	Matrix_Button.h:53: for(i = 0; i < 4; ++i){
      0008FF FF               [12] 2315 	mov	r7,a
      000900                       2316 00102$:
                                   2317 ;	Matrix_Button.h:54: Row_Write(i);
      000900 8F 06            [24] 2318 	mov	ar6,r7
      000902 8E 82            [24] 2319 	mov	dpl, r6
      000904 C0 07            [24] 2320 	push	ar7
      000906 C0 06            [24] 2321 	push	ar6
      000908 12 08 90         [24] 2322 	lcall	_Row_Write
                                   2323 ;	Matrix_Button.h:56: BTN_MATRIX |= (Col_Read()<<(4*i));
      00090B 12 08 C9         [24] 2324 	lcall	_Col_Read
      00090E AC 82            [24] 2325 	mov	r4, dpl
      000910 AD 83            [24] 2326 	mov	r5, dph
      000912 D0 06            [24] 2327 	pop	ar6
      000914 D0 07            [24] 2328 	pop	ar7
      000916 EE               [12] 2329 	mov	a,r6
      000917 2E               [12] 2330 	add	a,r6
      000918 25 E0            [12] 2331 	add	a,acc
      00091A F5 F0            [12] 2332 	mov	b, a
      00091C 05 F0            [12] 2333 	inc	b
      00091E 80 06            [24] 2334 	sjmp	00120$
      000920                       2335 00119$:
      000920 EC               [12] 2336 	mov	a,r4
      000921 2C               [12] 2337 	add	a,r4
      000922 FC               [12] 2338 	mov	r4,a
      000923 ED               [12] 2339 	mov	a,r5
      000924 33               [12] 2340 	rlc	a
      000925 FD               [12] 2341 	mov	r5,a
      000926                       2342 00120$:
      000926 D5 F0 F7         [24] 2343 	djnz	b,00119$
      000929 EC               [12] 2344 	mov	a,r4
      00092A 42 42            [12] 2345 	orl	_BTN_MATRIX,a
      00092C ED               [12] 2346 	mov	a,r5
      00092D 42 43            [12] 2347 	orl	(_BTN_MATRIX + 1),a
                                   2348 ;	Matrix_Button.h:53: for(i = 0; i < 4; ++i){
      00092F 0F               [12] 2349 	inc	r7
      000930 BF 04 00         [24] 2350 	cjne	r7,#0x04,00121$
      000933                       2351 00121$:
      000933 40 CB            [24] 2352 	jc	00102$
                                   2353 ;	Matrix_Button.h:58: return BTN_MATRIX;
      000935 85 42 82         [24] 2354 	mov	dpl, _BTN_MATRIX
      000938 85 43 83         [24] 2355 	mov	dph, (_BTN_MATRIX + 1)
                                   2356 ;	Matrix_Button.h:59: }
      00093B 22               [24] 2357 	ret
                                   2358 ;------------------------------------------------------------
                                   2359 ;Allocation info for local variables in function 'Get_BTN_MATRIX_2'
                                   2360 ;------------------------------------------------------------
                                   2361 ;current_btn_matrix Allocated to registers r6 r7 
                                   2362 ;------------------------------------------------------------
                                   2363 ;	Matrix_Button.h:62: uint32 Get_BTN_MATRIX_2(){
                                   2364 ;	-----------------------------------------
                                   2365 ;	 function Get_BTN_MATRIX_2
                                   2366 ;	-----------------------------------------
      00093C                       2367 _Get_BTN_MATRIX_2:
                                   2368 ;	Matrix_Button.h:63: uint32 current_btn_matrix = Get_BTN_MATRIX();
      00093C 12 08 FA         [24] 2369 	lcall	_Get_BTN_MATRIX
      00093F AE 82            [24] 2370 	mov	r6, dpl
      000941 AF 83            [24] 2371 	mov	r7, dph
                                   2372 ;	Matrix_Button.h:64: while( current_btn_matrix == Get_BTN_MATRIX()){
      000943                       2373 00101$:
      000943 C0 07            [24] 2374 	push	ar7
      000945 C0 06            [24] 2375 	push	ar6
      000947 12 08 FA         [24] 2376 	lcall	_Get_BTN_MATRIX
      00094A AC 82            [24] 2377 	mov	r4, dpl
      00094C AD 83            [24] 2378 	mov	r5, dph
      00094E D0 06            [24] 2379 	pop	ar6
      000950 D0 07            [24] 2380 	pop	ar7
      000952 EE               [12] 2381 	mov	a,r6
      000953 B5 04 0D         [24] 2382 	cjne	a,ar4,00103$
      000956 EF               [12] 2383 	mov	a,r7
      000957 B5 05 09         [24] 2384 	cjne	a,ar5,00103$
                                   2385 ;	Matrix_Button.h:65: current_btn_matrix = Get_BTN_MATRIX();
      00095A 12 08 FA         [24] 2386 	lcall	_Get_BTN_MATRIX
      00095D AE 82            [24] 2387 	mov	r6, dpl
      00095F AF 83            [24] 2388 	mov	r7, dph
      000961 80 E0            [24] 2389 	sjmp	00101$
      000963                       2390 00103$:
                                   2391 ;	Matrix_Button.h:67: return BTN_MATRIX;
      000963 85 42 82         [24] 2392 	mov	dpl, _BTN_MATRIX
      000966 85 43 83         [24] 2393 	mov	dph, (_BTN_MATRIX + 1)
                                   2394 ;	Matrix_Button.h:68: }
      000969 22               [24] 2395 	ret
                                   2396 ;------------------------------------------------------------
                                   2397 ;Allocation info for local variables in function 'new_dataframe'
                                   2398 ;------------------------------------------------------------
                                   2399 ;	IR_Reading.h:64: uint8 new_dataframe(){
                                   2400 ;	-----------------------------------------
                                   2401 ;	 function new_dataframe
                                   2402 ;	-----------------------------------------
      00096A                       2403 _new_dataframe:
                                   2404 ;	IR_Reading.h:65: return (data_frame!=0)?1:0;
      00096A E5 44            [12] 2405 	mov	a,_data_frame
      00096C 45 45            [12] 2406 	orl	a,(_data_frame + 1)
      00096E 60 04            [24] 2407 	jz	00103$
      000970 7F 01            [12] 2408 	mov	r7,#0x01
      000972 80 02            [24] 2409 	sjmp	00104$
      000974                       2410 00103$:
      000974 7F 00            [12] 2411 	mov	r7,#0x00
      000976                       2412 00104$:
      000976 8F 82            [24] 2413 	mov	dpl,r7
                                   2414 ;	IR_Reading.h:66: }
      000978 22               [24] 2415 	ret
                                   2416 ;------------------------------------------------------------
                                   2417 ;Allocation info for local variables in function 'read_extracted_frame'
                                   2418 ;------------------------------------------------------------
                                   2419 ;frame         Allocated to registers 
                                   2420 ;------------------------------------------------------------
                                   2421 ;	IR_Reading.h:69: uint32 read_extracted_frame(){
                                   2422 ;	-----------------------------------------
                                   2423 ;	 function read_extracted_frame
                                   2424 ;	-----------------------------------------
      000979                       2425 _read_extracted_frame:
                                   2426 ;	IR_Reading.h:70: uint32 frame = data_frame;
      000979 85 44 82         [24] 2427 	mov	dpl,_data_frame
      00097C 85 45 83         [24] 2428 	mov	dph,(_data_frame + 1)
                                   2429 ;	IR_Reading.h:71: data_frame = 0;
      00097F E4               [12] 2430 	clr	a
      000980 F5 44            [12] 2431 	mov	_data_frame,a
      000982 F5 45            [12] 2432 	mov	(_data_frame + 1),a
                                   2433 ;	IR_Reading.h:72: return frame;
                                   2434 ;	IR_Reading.h:73: }
      000984 22               [24] 2435 	ret
                                   2436 ;------------------------------------------------------------
                                   2437 ;Allocation info for local variables in function 'IR_Reading_Initial'
                                   2438 ;------------------------------------------------------------
                                   2439 ;	IR_Reading.h:75: void IR_Reading_Initial(){
                                   2440 ;	-----------------------------------------
                                   2441 ;	 function IR_Reading_Initial
                                   2442 ;	-----------------------------------------
      000985                       2443 _IR_Reading_Initial:
                                   2444 ;	IR_Reading.h:78: buffer = 0;
      000985 E4               [12] 2445 	clr	a
      000986 F5 46            [12] 2446 	mov	_buffer,a
      000988 F5 47            [12] 2447 	mov	(_buffer + 1),a
                                   2448 ;	IR_Reading.h:79: data_frame = 0;
      00098A F5 44            [12] 2449 	mov	_data_frame,a
      00098C F5 45            [12] 2450 	mov	(_data_frame + 1),a
                                   2451 ;	IR_Reading.h:80: negedge_count = 0;
      00098E F5 49            [12] 2452 	mov	_negedge_count,a
                                   2453 ;	IR_Reading.h:81: GLOBAL_INT(ENABLE);
      000990 75 82 01         [24] 2454 	mov	dpl, #0x01
      000993 12 01 C9         [24] 2455 	lcall	_GLOBAL_INT
                                   2456 ;	IR_Reading.h:82: eINT0_CTL(ENABLE);
      000996 75 82 01         [24] 2457 	mov	dpl, #0x01
      000999 12 01 77         [24] 2458 	lcall	_eINT0_CTL
                                   2459 ;	IR_Reading.h:83: TIMER0_CTL(ENABLE);
      00099C 75 82 01         [24] 2460 	mov	dpl, #0x01
      00099F 12 01 99         [24] 2461 	lcall	_TIMER0_CTL
                                   2462 ;	IR_Reading.h:84: TIMER0_CTL(MODE_16BIT);
      0009A2 75 82 04         [24] 2463 	mov	dpl, #0x04
      0009A5 12 01 99         [24] 2464 	lcall	_TIMER0_CTL
                                   2465 ;	IR_Reading.h:85: TIMER0_CTL(START);
      0009A8 75 82 02         [24] 2466 	mov	dpl, #0x02
      0009AB 12 01 99         [24] 2467 	lcall	_TIMER0_CTL
                                   2468 ;	IR_Reading.h:86: TIMER0_CTL(RESET);
      0009AE 75 82 05         [24] 2469 	mov	dpl, #0x05
                                   2470 ;	IR_Reading.h:87: }
      0009B1 02 01 99         [24] 2471 	ljmp	_TIMER0_CTL
                                   2472 ;------------------------------------------------------------
                                   2473 ;Allocation info for local variables in function 'Timer0_OverFlow_Interrupt'
                                   2474 ;------------------------------------------------------------
                                   2475 ;	IR_Reading.h:89: void Timer0_OverFlow_Interrupt() __interrupt(1) {
                                   2476 ;	-----------------------------------------
                                   2477 ;	 function Timer0_OverFlow_Interrupt
                                   2478 ;	-----------------------------------------
      0009B4                       2479 _Timer0_OverFlow_Interrupt:
      0009B4 C0 21            [24] 2480 	push	bits
      0009B6 C0 E0            [24] 2481 	push	acc
      0009B8 C0 F0            [24] 2482 	push	b
      0009BA C0 82            [24] 2483 	push	dpl
      0009BC C0 83            [24] 2484 	push	dph
      0009BE C0 07            [24] 2485 	push	(0+7)
      0009C0 C0 06            [24] 2486 	push	(0+6)
      0009C2 C0 05            [24] 2487 	push	(0+5)
      0009C4 C0 04            [24] 2488 	push	(0+4)
      0009C6 C0 03            [24] 2489 	push	(0+3)
      0009C8 C0 02            [24] 2490 	push	(0+2)
      0009CA C0 01            [24] 2491 	push	(0+1)
      0009CC C0 00            [24] 2492 	push	(0+0)
      0009CE C0 D0            [24] 2493 	push	psw
      0009D0 75 D0 00         [24] 2494 	mov	psw,#0x00
                                   2495 ;	IR_Reading.h:91: TIMER0_CTL(RESET);
      0009D3 75 82 05         [24] 2496 	mov	dpl, #0x05
      0009D6 12 01 99         [24] 2497 	lcall	_TIMER0_CTL
                                   2498 ;	IR_Reading.h:93: if(ms_count<67) ms_count = ms_count + 1;
      0009D9 74 BD            [12] 2499 	mov	a,#0x100 - 0x43
      0009DB 25 48            [12] 2500 	add	a,_ms_count
      0009DD 40 05            [24] 2501 	jc	00103$
      0009DF E5 48            [12] 2502 	mov	a,_ms_count
      0009E1 04               [12] 2503 	inc	a
      0009E2 F5 48            [12] 2504 	mov	_ms_count,a
      0009E4                       2505 00103$:
                                   2506 ;	IR_Reading.h:94: }
      0009E4 D0 D0            [24] 2507 	pop	psw
      0009E6 D0 00            [24] 2508 	pop	(0+0)
      0009E8 D0 01            [24] 2509 	pop	(0+1)
      0009EA D0 02            [24] 2510 	pop	(0+2)
      0009EC D0 03            [24] 2511 	pop	(0+3)
      0009EE D0 04            [24] 2512 	pop	(0+4)
      0009F0 D0 05            [24] 2513 	pop	(0+5)
      0009F2 D0 06            [24] 2514 	pop	(0+6)
      0009F4 D0 07            [24] 2515 	pop	(0+7)
      0009F6 D0 83            [24] 2516 	pop	dph
      0009F8 D0 82            [24] 2517 	pop	dpl
      0009FA D0 F0            [24] 2518 	pop	b
      0009FC D0 E0            [24] 2519 	pop	acc
      0009FE D0 21            [24] 2520 	pop	bits
      000A00 32               [24] 2521 	reti
                                   2522 ;------------------------------------------------------------
                                   2523 ;Allocation info for local variables in function 'External0_Interrupt'
                                   2524 ;------------------------------------------------------------
                                   2525 ;current_mscount Allocated to registers r7 
                                   2526 ;------------------------------------------------------------
                                   2527 ;	IR_Reading.h:96: void External0_Interrupt() __interrupt(0) {
                                   2528 ;	-----------------------------------------
                                   2529 ;	 function External0_Interrupt
                                   2530 ;	-----------------------------------------
      000A01                       2531 _External0_Interrupt:
      000A01 C0 21            [24] 2532 	push	bits
      000A03 C0 E0            [24] 2533 	push	acc
      000A05 C0 F0            [24] 2534 	push	b
      000A07 C0 82            [24] 2535 	push	dpl
      000A09 C0 83            [24] 2536 	push	dph
      000A0B C0 07            [24] 2537 	push	(0+7)
      000A0D C0 06            [24] 2538 	push	(0+6)
      000A0F C0 05            [24] 2539 	push	(0+5)
      000A11 C0 04            [24] 2540 	push	(0+4)
      000A13 C0 03            [24] 2541 	push	(0+3)
      000A15 C0 02            [24] 2542 	push	(0+2)
      000A17 C0 01            [24] 2543 	push	(0+1)
      000A19 C0 00            [24] 2544 	push	(0+0)
      000A1B C0 D0            [24] 2545 	push	psw
      000A1D 75 D0 00         [24] 2546 	mov	psw,#0x00
                                   2547 ;	IR_Reading.h:99: current_mscount = ms_count;
      000A20 AF 48            [24] 2548 	mov	r7,_ms_count
                                   2549 ;	IR_Reading.h:100: TIMER0_CTL(RESET);
      000A22 75 82 05         [24] 2550 	mov	dpl, #0x05
      000A25 C0 07            [24] 2551 	push	ar7
      000A27 12 01 99         [24] 2552 	lcall	_TIMER0_CTL
      000A2A D0 07            [24] 2553 	pop	ar7
                                   2554 ;	IR_Reading.h:101: ms_count=0;
      000A2C 75 48 00         [24] 2555 	mov	_ms_count,#0x00
                                   2556 ;	IR_Reading.h:102: negedge_count +=1;
      000A2F E5 49            [12] 2557 	mov	a,_negedge_count
      000A31 FE               [12] 2558 	mov	r6,a
      000A32 04               [12] 2559 	inc	a
      000A33 F5 49            [12] 2560 	mov	_negedge_count,a
                                   2561 ;	IR_Reading.h:105: if(current_mscount >= 67){
      000A35 BF 43 00         [24] 2562 	cjne	r7,#0x43,00139$
      000A38                       2563 00139$:
      000A38 40 0A            [24] 2564 	jc	00109$
                                   2565 ;	IR_Reading.h:106: negedge_count = -2;
      000A3A 75 49 FE         [24] 2566 	mov	_negedge_count,#0xfe
                                   2567 ;	IR_Reading.h:107: RESET_BUFFER();
      000A3D E4               [12] 2568 	clr	a
      000A3E F5 46            [12] 2569 	mov	_buffer,a
      000A40 F5 47            [12] 2570 	mov	(_buffer + 1),a
                                   2571 ;	IR_Reading.h:111: if(0 <= negedge_count && negedge_count <= 31){
      000A42 80 48            [24] 2572 	sjmp	00113$
      000A44                       2573 00109$:
      000A44 E5 49            [12] 2574 	mov	a,_negedge_count
      000A46 24 E0            [12] 2575 	add	a,#0xff - 0x1f
      000A48 40 25            [24] 2576 	jc	00107$
                                   2577 ;	IR_Reading.h:112: if( current_mscount >= 2){
      000A4A BF 02 00         [24] 2578 	cjne	r7,#0x02,00142$
      000A4D                       2579 00142$:
      000A4D 40 3D            [24] 2580 	jc	00113$
                                   2581 ;	IR_Reading.h:113: PUSH_BIT_1();
      000A4F 74 1F            [12] 2582 	mov	a,#0x1f
      000A51 C3               [12] 2583 	clr	c
      000A52 95 49            [12] 2584 	subb	a,_negedge_count
      000A54 F5 F0            [12] 2585 	mov	b, a
      000A56 05 F0            [12] 2586 	inc	b
      000A58 7F 01            [12] 2587 	mov	r7,#0x01
      000A5A 7E 00            [12] 2588 	mov	r6,#0x00
      000A5C 80 06            [24] 2589 	sjmp	00145$
      000A5E                       2590 00144$:
      000A5E EF               [12] 2591 	mov	a,r7
      000A5F 2F               [12] 2592 	add	a,r7
      000A60 FF               [12] 2593 	mov	r7,a
      000A61 EE               [12] 2594 	mov	a,r6
      000A62 33               [12] 2595 	rlc	a
      000A63 FE               [12] 2596 	mov	r6,a
      000A64                       2597 00145$:
      000A64 D5 F0 F7         [24] 2598 	djnz	b,00144$
      000A67 EF               [12] 2599 	mov	a,r7
      000A68 42 46            [12] 2600 	orl	_buffer,a
      000A6A EE               [12] 2601 	mov	a,r6
      000A6B 42 47            [12] 2602 	orl	(_buffer + 1),a
                                   2603 ;	IR_Reading.h:115: PUSH_BIT_0();
      000A6D 80 1D            [24] 2604 	sjmp	00113$
      000A6F                       2605 00107$:
                                   2606 ;	IR_Reading.h:117: }else if(negedge_count >= 32){
      000A6F 74 E0            [12] 2607 	mov	a,#0x100 - 0x20
      000A71 25 49            [12] 2608 	add	a,_negedge_count
      000A73 50 17            [24] 2609 	jnc	00113$
                                   2610 ;	IR_Reading.h:118: EXTRACT_FRAME();
      000A75 85 46 44         [24] 2611 	mov	_data_frame,_buffer
      000A78 85 47 45         [24] 2612 	mov	(_data_frame + 1),(_buffer + 1)
      000A7B E4               [12] 2613 	clr	a
      000A7C F5 46            [12] 2614 	mov	_buffer,a
      000A7E F5 47            [12] 2615 	mov	(_buffer + 1),a
      000A80 F5 49            [12] 2616 	mov	_negedge_count,a
                                   2617 ;	IR_Reading.h:119: FrameExtracted_LED=0;
                                   2618 ;	assignBit
      000A82 C2 A0            [12] 2619 	clr	_FrameExtracted_LED
                                   2620 ;	IR_Reading.h:120: delay_ms(1);
      000A84 90 00 01         [24] 2621 	mov	dptr,#0x0001
      000A87 12 01 54         [24] 2622 	lcall	_delay_ms
                                   2623 ;	IR_Reading.h:121: FrameExtracted_LED=1;
                                   2624 ;	assignBit
      000A8A D2 A0            [12] 2625 	setb	_FrameExtracted_LED
      000A8C                       2626 00113$:
                                   2627 ;	IR_Reading.h:124: }
      000A8C D0 D0            [24] 2628 	pop	psw
      000A8E D0 00            [24] 2629 	pop	(0+0)
      000A90 D0 01            [24] 2630 	pop	(0+1)
      000A92 D0 02            [24] 2631 	pop	(0+2)
      000A94 D0 03            [24] 2632 	pop	(0+3)
      000A96 D0 04            [24] 2633 	pop	(0+4)
      000A98 D0 05            [24] 2634 	pop	(0+5)
      000A9A D0 06            [24] 2635 	pop	(0+6)
      000A9C D0 07            [24] 2636 	pop	(0+7)
      000A9E D0 83            [24] 2637 	pop	dph
      000AA0 D0 82            [24] 2638 	pop	dpl
      000AA2 D0 F0            [24] 2639 	pop	b
      000AA4 D0 E0            [24] 2640 	pop	acc
      000AA6 D0 21            [24] 2641 	pop	bits
      000AA8 02 00 54         [24] 2642 	ljmp	sdcc_atomic_maybe_rollback
                                   2643 ;------------------------------------------------------------
                                   2644 ;Allocation info for local variables in function 'CODE2NUM'
                                   2645 ;------------------------------------------------------------
                                   2646 ;CODE          Allocated to registers 
                                   2647 ;------------------------------------------------------------
                                   2648 ;	main.h:36: uint8 CODE2NUM(uint32 CODE){
                                   2649 ;	-----------------------------------------
                                   2650 ;	 function CODE2NUM
                                   2651 ;	-----------------------------------------
      000AAB                       2652 _CODE2NUM:
                                   2653 ;	main.h:49: return 0;
      000AAB 75 82 00         [24] 2654 	mov	dpl, #0x00
                                   2655 ;	main.h:50: }
      000AAE 22               [24] 2656 	ret
                                   2657 ;------------------------------------------------------------
                                   2658 ;Allocation info for local variables in function 'YES_NO'
                                   2659 ;------------------------------------------------------------
                                   2660 ;CODE          Allocated to registers r6 r7 
                                   2661 ;------------------------------------------------------------
                                   2662 ;	main.h:52: uint8 YES_NO(){
                                   2663 ;	-----------------------------------------
                                   2664 ;	 function YES_NO
                                   2665 ;	-----------------------------------------
      000AAF                       2666 _YES_NO:
                                   2667 ;	main.h:54: LED[5] = 0; LED[4] = 0;
      000AAF 75 3F 00         [24] 2668 	mov	(_LED + 0x0005),#0x00
      000AB2 75 3E 00         [24] 2669 	mov	(_LED + 0x0004),#0x00
                                   2670 ;	main.h:55: LED[3] = 0; LED[2] = 0;
      000AB5 75 3D 00         [24] 2671 	mov	(_LED + 0x0003),#0x00
      000AB8 75 3C 00         [24] 2672 	mov	(_LED + 0x0002),#0x00
                                   2673 ;	main.h:56: LED[1] = 0; LED[0] = 0;
      000ABB 75 3B 00         [24] 2674 	mov	(_LED + 0x0001),#0x00
      000ABE 75 3A 00         [24] 2675 	mov	_LED,#0x00
                                   2676 ;	main.h:57: while(0x1){
      000AC1                       2677 00106$:
                                   2678 ;	main.h:58: CODE = read_extracted_frame();
      000AC1 12 09 79         [24] 2679 	lcall	_read_extracted_frame
      000AC4 AE 82            [24] 2680 	mov	r6, dpl
      000AC6 AF 83            [24] 2681 	mov	r7, dph
                                   2682 ;	main.h:59: LED[7] = 0x6E; LED[6] = 0x37;
      000AC8 75 41 6E         [24] 2683 	mov	(_LED + 0x0007),#0x6e
      000ACB 75 40 37         [24] 2684 	mov	(_LED + 0x0006),#0x37
                                   2685 ;	main.h:60: Disp8leds7seg(1);
      000ACE 90 00 01         [24] 2686 	mov	dptr,#0x0001
      000AD1 C0 07            [24] 2687 	push	ar7
      000AD3 C0 06            [24] 2688 	push	ar6
      000AD5 12 08 45         [24] 2689 	lcall	_Disp8leds7seg
      000AD8 D0 06            [24] 2690 	pop	ar6
      000ADA D0 07            [24] 2691 	pop	ar7
                                   2692 ;	main.h:61: switch (CODE) {
      000ADC BE DD 05         [24] 2693 	cjne	r6,#0xdd,00134$
      000ADF BF 22 02         [24] 2694 	cjne	r7,#0x22,00134$
      000AE2 80 10            [24] 2695 	sjmp	00101$
      000AE4                       2696 00134$:
      000AE4 BE 9D 05         [24] 2697 	cjne	r6,#0x9d,00135$
      000AE7 BF 62 02         [24] 2698 	cjne	r7,#0x62,00135$
      000AEA 80 0C            [24] 2699 	sjmp	00102$
      000AEC                       2700 00135$:
                                   2701 ;	main.h:63: case PLAY_PAUSE: return 1;
      000AEC BE 5D D2         [24] 2702 	cjne	r6,#0x5d,00106$
      000AEF BF A2 CF         [24] 2703 	cjne	r7,#0xa2,00106$
      000AF2 80 08            [24] 2704 	sjmp	00103$
      000AF4                       2705 00101$:
      000AF4 75 82 01         [24] 2706 	mov	dpl, #0x01
                                   2707 ;	main.h:64: case MODE: return 0;
      000AF7 22               [24] 2708 	ret
      000AF8                       2709 00102$:
      000AF8 75 82 00         [24] 2710 	mov	dpl, #0x00
                                   2711 ;	main.h:65: case ON_OFF: return 0;
      000AFB 22               [24] 2712 	ret
      000AFC                       2713 00103$:
      000AFC 75 82 00         [24] 2714 	mov	dpl, #0x00
                                   2715 ;	main.h:68: return 0;
                                   2716 ;	main.h:69: }
      000AFF 22               [24] 2717 	ret
                                   2718 ;------------------------------------------------------------
                                   2719 ;Allocation info for local variables in function 'SET_TIMER'
                                   2720 ;------------------------------------------------------------
                                   2721 ;t             Allocated with name '_SET_TIMER_t_10000_99'
                                   2722 ;POS           Allocated to registers r4 
                                   2723 ;CODE          Allocated to registers r2 r3 
                                   2724 ;tmp           Allocated with name '_SET_TIMER_tmp_10000_100'
                                   2725 ;------------------------------------------------------------
                                   2726 ;	main.h:71: uint8 SET_TIMER(TIME* t){
                                   2727 ;	-----------------------------------------
                                   2728 ;	 function SET_TIMER
                                   2729 ;	-----------------------------------------
      000B00                       2730 _SET_TIMER:
      000B00 85 82 62         [24] 2731 	mov	_SET_TIMER_t_10000_99,dpl
      000B03 85 83 63         [24] 2732 	mov	(_SET_TIMER_t_10000_99 + 1),dph
      000B06 85 F0 64         [24] 2733 	mov	(_SET_TIMER_t_10000_99 + 2),b
                                   2734 ;	main.h:72: uint8 POS = 0;
      000B09 7C 00            [12] 2735 	mov	r4,#0x00
                                   2736 ;	main.h:81: ds1302_read_time(&tmp, 0x7);
      000B0B 75 34 07         [24] 2737 	mov	_ds1302_read_time_PARM_2,#0x07
      000B0E 90 00 65         [24] 2738 	mov	dptr,#_SET_TIMER_tmp_10000_100
      000B11 75 F0 40         [24] 2739 	mov	b, #0x40
      000B14 C0 04            [24] 2740 	push	ar4
      000B16 12 03 5A         [24] 2741 	lcall	_ds1302_read_time
      000B19 D0 04            [24] 2742 	pop	ar4
                                   2743 ;	main.h:82: while(0x1){
      000B1B                       2744 00115$:
                                   2745 ;	main.h:83: CODE = read_extracted_frame();
      000B1B C0 04            [24] 2746 	push	ar4
      000B1D 12 09 79         [24] 2747 	lcall	_read_extracted_frame
      000B20 AA 82            [24] 2748 	mov	r2, dpl
      000B22 AB 83            [24] 2749 	mov	r3, dph
      000B24 D0 04            [24] 2750 	pop	ar4
                                   2751 ;	main.h:84: if(CODE == PLAY_PAUSE) break;
      000B26 BA DD 06         [24] 2752 	cjne	r2,#0xdd,00191$
      000B29 BB 22 03         [24] 2753 	cjne	r3,#0x22,00191$
      000B2C 02 0C 23         [24] 2754 	ljmp	00116$
      000B2F                       2755 00191$:
                                   2756 ;	main.h:85: if(CODE == PREV) POS = (POS+1 + 2)%2;
      000B2F BA FD 0B         [24] 2757 	cjne	r2,#0xfd,00104$
      000B32 BB 02 08         [24] 2758 	cjne	r3,#0x02,00104$
      000B35 8C 07            [24] 2759 	mov	ar7,r4
      000B37 74 03            [12] 2760 	mov	a,#0x03
      000B39 2F               [12] 2761 	add	a, r7
      000B3A 54 01            [12] 2762 	anl	a,#0x01
      000B3C FC               [12] 2763 	mov	r4,a
      000B3D                       2764 00104$:
                                   2765 ;	main.h:86: if(CODE == NEXT) POS = (POS-1 + 2)%2;
      000B3D BA 3D 0A         [24] 2766 	cjne	r2,#0x3d,00106$
      000B40 BB C2 07         [24] 2767 	cjne	r3,#0xc2,00106$
      000B43 8C 07            [24] 2768 	mov	ar7,r4
      000B45 EF               [12] 2769 	mov	a,r7
      000B46 04               [12] 2770 	inc	a
      000B47 54 01            [12] 2771 	anl	a,#0x01
      000B49 FC               [12] 2772 	mov	r4,a
      000B4A                       2773 00106$:
                                   2774 ;	main.h:87: if(CODE == ON_OFF) return 0;
      000B4A BA 5D 07         [24] 2775 	cjne	r2,#0x5d,00108$
      000B4D BB A2 04         [24] 2776 	cjne	r3,#0xa2,00108$
      000B50 75 82 00         [24] 2777 	mov	dpl, #0x00
      000B53 22               [24] 2778 	ret
      000B54                       2779 00108$:
                                   2780 ;	main.h:88: if(CODE == MODE) return 0;
      000B54 BA 9D 07         [24] 2781 	cjne	r2,#0x9d,00110$
      000B57 BB 62 04         [24] 2782 	cjne	r3,#0x62,00110$
      000B5A 75 82 00         [24] 2783 	mov	dpl, #0x00
      000B5D 22               [24] 2784 	ret
      000B5E                       2785 00110$:
                                   2786 ;	main.h:89: switch (POS) {
      000B5E BC 00 02         [24] 2787 	cjne	r4,#0x00,00200$
      000B61 80 05            [24] 2788 	sjmp	00111$
      000B63                       2789 00200$:
                                   2790 ;	main.h:90: case 0:
      000B63 BC 01 4D         [24] 2791 	cjne	r4,#0x01,00113$
      000B66 80 2A            [24] 2792 	sjmp	00112$
      000B68                       2793 00111$:
                                   2794 ;	main.h:91: tmp.MINUTE += CODE2NUM(CODE)%10; tmp.MINUTE%=60; break;
      000B68 AF 6A            [24] 2795 	mov	r7,(_SET_TIMER_tmp_10000_100 + 0x0005)
      000B6A 8A 82            [24] 2796 	mov	dpl, r2
      000B6C 8B 83            [24] 2797 	mov	dph, r3
      000B6E C0 07            [24] 2798 	push	ar7
      000B70 C0 04            [24] 2799 	push	ar4
      000B72 12 0A AB         [24] 2800 	lcall	_CODE2NUM
      000B75 AE 82            [24] 2801 	mov	r6, dpl
      000B77 D0 04            [24] 2802 	pop	ar4
      000B79 D0 07            [24] 2803 	pop	ar7
      000B7B 75 F0 0A         [24] 2804 	mov	b,#0x0a
      000B7E EE               [12] 2805 	mov	a,r6
      000B7F 84               [48] 2806 	div	ab
      000B80 E5 F0            [12] 2807 	mov	a,b
      000B82 2F               [12] 2808 	add	a, r7
      000B83 F5 6A            [12] 2809 	mov	(_SET_TIMER_tmp_10000_100 + 0x0005),a
      000B85 AF 6A            [24] 2810 	mov	r7,(_SET_TIMER_tmp_10000_100 + 0x0005)
      000B87 75 F0 3C         [24] 2811 	mov	b,#0x3c
      000B8A EF               [12] 2812 	mov	a,r7
      000B8B 84               [48] 2813 	div	ab
      000B8C AF F0            [24] 2814 	mov	r7,b
      000B8E 8F 6A            [24] 2815 	mov	(_SET_TIMER_tmp_10000_100 + 0x0005),r7
                                   2816 ;	main.h:92: case 1:
      000B90 80 21            [24] 2817 	sjmp	00113$
      000B92                       2818 00112$:
                                   2819 ;	main.h:93: tmp.HOUR   += CODE2NUM(CODE); tmp.HOUR%=24; break;
      000B92 AF 69            [24] 2820 	mov	r7,(_SET_TIMER_tmp_10000_100 + 0x0004)
      000B94 8A 82            [24] 2821 	mov	dpl, r2
      000B96 8B 83            [24] 2822 	mov	dph, r3
      000B98 C0 07            [24] 2823 	push	ar7
      000B9A C0 04            [24] 2824 	push	ar4
      000B9C 12 0A AB         [24] 2825 	lcall	_CODE2NUM
      000B9F AE 82            [24] 2826 	mov	r6, dpl
      000BA1 D0 04            [24] 2827 	pop	ar4
      000BA3 D0 07            [24] 2828 	pop	ar7
      000BA5 EE               [12] 2829 	mov	a,r6
      000BA6 2F               [12] 2830 	add	a, r7
      000BA7 FF               [12] 2831 	mov	r7,a
      000BA8 8F 69            [24] 2832 	mov	(_SET_TIMER_tmp_10000_100 + 0x0004),r7
      000BAA 75 F0 18         [24] 2833 	mov	b,#0x18
      000BAD EF               [12] 2834 	mov	a,r7
      000BAE 84               [48] 2835 	div	ab
      000BAF AF F0            [24] 2836 	mov	r7,b
      000BB1 8F 69            [24] 2837 	mov	(_SET_TIMER_tmp_10000_100 + 0x0004),r7
                                   2838 ;	main.h:94: }
      000BB3                       2839 00113$:
                                   2840 ;	main.h:95: LED[0] = DIGIT_CODE[tmp.MINUTE%10] + ((POS==0)?(0x80):(0));
      000BB3 AF 6A            [24] 2841 	mov	r7,(_SET_TIMER_tmp_10000_100 + 0x0005)
      000BB5 75 F0 0A         [24] 2842 	mov	b,#0x0a
      000BB8 EF               [12] 2843 	mov	a,r7
      000BB9 84               [48] 2844 	div	ab
      000BBA AF F0            [24] 2845 	mov	r7,b
      000BBC 7E 00            [12] 2846 	mov	r6,#0x00
      000BBE EF               [12] 2847 	mov	a,r7
      000BBF 24 CD            [12] 2848 	add	a, #_DIGIT_CODE
      000BC1 F5 82            [12] 2849 	mov	dpl,a
      000BC3 EE               [12] 2850 	mov	a,r6
      000BC4 34 11            [12] 2851 	addc	a, #(_DIGIT_CODE >> 8)
      000BC6 F5 83            [12] 2852 	mov	dph,a
      000BC8 E4               [12] 2853 	clr	a
      000BC9 93               [24] 2854 	movc	a,@a+dptr
      000BCA FF               [12] 2855 	mov	r7,a
      000BCB EC               [12] 2856 	mov	a,r4
      000BCC 70 04            [24] 2857 	jnz	00121$
      000BCE 7E 80            [12] 2858 	mov	r6,#0x80
      000BD0 80 02            [24] 2859 	sjmp	00122$
      000BD2                       2860 00121$:
      000BD2 7E 00            [12] 2861 	mov	r6,#0x00
      000BD4                       2862 00122$:
      000BD4 EE               [12] 2863 	mov	a,r6
      000BD5 2F               [12] 2864 	add	a, r7
      000BD6 F5 3A            [12] 2865 	mov	_LED,a
                                   2866 ;	main.h:96: LED[1] = DIGIT_CODE[tmp.MINUTE/10];
      000BD8 AF 6A            [24] 2867 	mov	r7,(_SET_TIMER_tmp_10000_100 + 0x0005)
      000BDA 75 F0 0A         [24] 2868 	mov	b,#0x0a
      000BDD EF               [12] 2869 	mov	a,r7
      000BDE 84               [48] 2870 	div	ab
      000BDF 7E 00            [12] 2871 	mov	r6,#0x00
      000BE1 90 11 CD         [24] 2872 	mov	dptr,#_DIGIT_CODE
      000BE4 93               [24] 2873 	movc	a,@a+dptr
      000BE5 F5 3B            [12] 2874 	mov	(_LED + 0x0001), a
                                   2875 ;	main.h:97: LED[2] = DIGIT_CODE[tmp.HOUR%10]   + ((POS==1)?(0x80):(0));
      000BE7 AF 69            [24] 2876 	mov	r7,(_SET_TIMER_tmp_10000_100 + 0x0004)
      000BE9 75 F0 0A         [24] 2877 	mov	b,#0x0a
      000BEC EF               [12] 2878 	mov	a,r7
      000BED 84               [48] 2879 	div	ab
      000BEE E5 F0            [12] 2880 	mov	a,b
      000BF0 24 CD            [12] 2881 	add	a, #_DIGIT_CODE
      000BF2 F5 82            [12] 2882 	mov	dpl,a
      000BF4 EE               [12] 2883 	mov	a,r6
      000BF5 34 11            [12] 2884 	addc	a, #(_DIGIT_CODE >> 8)
      000BF7 F5 83            [12] 2885 	mov	dph,a
      000BF9 E4               [12] 2886 	clr	a
      000BFA 93               [24] 2887 	movc	a,@a+dptr
      000BFB FF               [12] 2888 	mov	r7,a
      000BFC BC 01 04         [24] 2889 	cjne	r4,#0x01,00123$
      000BFF 7E 80            [12] 2890 	mov	r6,#0x80
      000C01 80 02            [24] 2891 	sjmp	00124$
      000C03                       2892 00123$:
      000C03 7E 00            [12] 2893 	mov	r6,#0x00
      000C05                       2894 00124$:
      000C05 EE               [12] 2895 	mov	a,r6
      000C06 2F               [12] 2896 	add	a, r7
      000C07 F5 3C            [12] 2897 	mov	(_LED + 0x0002),a
                                   2898 ;	main.h:98: LED[3] = DIGIT_CODE[tmp.HOUR/10];
      000C09 AF 69            [24] 2899 	mov	r7,(_SET_TIMER_tmp_10000_100 + 0x0004)
      000C0B 75 F0 0A         [24] 2900 	mov	b,#0x0a
      000C0E EF               [12] 2901 	mov	a,r7
      000C0F 84               [48] 2902 	div	ab
      000C10 90 11 CD         [24] 2903 	mov	dptr,#_DIGIT_CODE
      000C13 93               [24] 2904 	movc	a,@a+dptr
      000C14 F5 3D            [12] 2905 	mov	(_LED + 0x0003), a
                                   2906 ;	main.h:99: Disp8leds7seg(50);
      000C16 90 00 32         [24] 2907 	mov	dptr,#0x0032
      000C19 C0 04            [24] 2908 	push	ar4
      000C1B 12 08 45         [24] 2909 	lcall	_Disp8leds7seg
      000C1E D0 04            [24] 2910 	pop	ar4
      000C20 02 0B 1B         [24] 2911 	ljmp	00115$
      000C23                       2912 00116$:
                                   2913 ;	main.h:101: if(YES_NO()){
      000C23 12 0A AF         [24] 2914 	lcall	_YES_NO
      000C26 E5 82            [12] 2915 	mov	a, dpl
      000C28 60 22            [24] 2916 	jz	00118$
                                   2917 ;	main.h:102: *t = tmp;
      000C2A AD 62            [24] 2918 	mov	r5,_SET_TIMER_t_10000_99
      000C2C AE 63            [24] 2919 	mov	r6,(_SET_TIMER_t_10000_99 + 1)
      000C2E AF 64            [24] 2920 	mov	r7,(_SET_TIMER_t_10000_99 + 2)
      000C30 75 08 65         [24] 2921 	mov	___memcpy_PARM_2,#_SET_TIMER_tmp_10000_100
      000C33 75 09 00         [24] 2922 	mov	(___memcpy_PARM_2 + 1),#0x00
      000C36 75 0A 40         [24] 2923 	mov	(___memcpy_PARM_2 + 2),#0x40
      000C39 75 0B 07         [24] 2924 	mov	___memcpy_PARM_3,#0x07
      000C3C 75 0C 00         [24] 2925 	mov	(___memcpy_PARM_3 + 1),#0x00
      000C3F 8D 82            [24] 2926 	mov	dpl, r5
      000C41 8E 83            [24] 2927 	mov	dph, r6
      000C43 8F F0            [24] 2928 	mov	b, r7
      000C45 12 10 9D         [24] 2929 	lcall	___memcpy
                                   2930 ;	main.h:103: return 1;
      000C48 75 82 01         [24] 2931 	mov	dpl, #0x01
      000C4B 22               [24] 2932 	ret
      000C4C                       2933 00118$:
                                   2934 ;	main.h:105: return 0;
      000C4C 75 82 00         [24] 2935 	mov	dpl, #0x00
                                   2936 ;	main.h:106: }
      000C4F 22               [24] 2937 	ret
                                   2938 ;------------------------------------------------------------
                                   2939 ;Allocation info for local variables in function 'SET_ON_OFF'
                                   2940 ;------------------------------------------------------------
                                   2941 ;dev           Allocated with name '_SET_ON_OFF_PARM_2'
                                   2942 ;val           Allocated with name '_SET_ON_OFF_val_10000_104'
                                   2943 ;tmp           Allocated to registers r4 
                                   2944 ;CODE          Allocated to registers r6 r7 
                                   2945 ;sloc0         Allocated with name '_SET_ON_OFF_sloc0_1_0'
                                   2946 ;------------------------------------------------------------
                                   2947 ;	main.h:108: uint8 SET_ON_OFF(uint8 *val, uint8 dev){
                                   2948 ;	-----------------------------------------
                                   2949 ;	 function SET_ON_OFF
                                   2950 ;	-----------------------------------------
      000C50                       2951 _SET_ON_OFF:
      000C50 85 82 6D         [24] 2952 	mov	_SET_ON_OFF_val_10000_104,dpl
      000C53 85 83 6E         [24] 2953 	mov	(_SET_ON_OFF_val_10000_104 + 1),dph
      000C56 85 F0 6F         [24] 2954 	mov	(_SET_ON_OFF_val_10000_104 + 2),b
                                   2955 ;	main.h:109: uint8 tmp = 0;
      000C59 7C 00            [12] 2956 	mov	r4,#0x00
                                   2957 ;	main.h:111: while(0x1){
      000C5B E5 6C            [12] 2958 	mov	a,_SET_ON_OFF_PARM_2
      000C5D 24 CD            [12] 2959 	add	a, #_DIGIT_CODE
      000C5F FA               [12] 2960 	mov	r2,a
      000C60 E4               [12] 2961 	clr	a
      000C61 34 11            [12] 2962 	addc	a, #(_DIGIT_CODE >> 8)
      000C63 FB               [12] 2963 	mov	r3,a
      000C64 8A 70            [24] 2964 	mov	_SET_ON_OFF_sloc0_1_0,r2
      000C66 8B 71            [24] 2965 	mov	(_SET_ON_OFF_sloc0_1_0 + 1),r3
      000C68                       2966 00115$:
                                   2967 ;	main.h:112: CODE = read_extracted_frame();
      000C68 C0 04            [24] 2968 	push	ar4
      000C6A C0 03            [24] 2969 	push	ar3
      000C6C C0 02            [24] 2970 	push	ar2
      000C6E 12 09 79         [24] 2971 	lcall	_read_extracted_frame
      000C71 AE 82            [24] 2972 	mov	r6, dpl
      000C73 AF 83            [24] 2973 	mov	r7, dph
      000C75 D0 02            [24] 2974 	pop	ar2
      000C77 D0 03            [24] 2975 	pop	ar3
      000C79 D0 04            [24] 2976 	pop	ar4
                                   2977 ;	main.h:113: if(CODE == PLAY_PAUSE) break;
      000C7B BE DD 06         [24] 2978 	cjne	r6,#0xdd,00175$
      000C7E BF 22 03         [24] 2979 	cjne	r7,#0x22,00175$
      000C81 02 0D 28         [24] 2980 	ljmp	00116$
      000C84                       2981 00175$:
                                   2982 ;	main.h:114: if(CODE == PREV) tmp = (tmp+1 + 2)%2;
      000C84 BE FD 0B         [24] 2983 	cjne	r6,#0xfd,00104$
      000C87 BF 02 08         [24] 2984 	cjne	r7,#0x02,00104$
      000C8A 8C 05            [24] 2985 	mov	ar5,r4
      000C8C 74 03            [12] 2986 	mov	a,#0x03
      000C8E 2D               [12] 2987 	add	a, r5
      000C8F 54 01            [12] 2988 	anl	a,#0x01
      000C91 FC               [12] 2989 	mov	r4,a
      000C92                       2990 00104$:
                                   2991 ;	main.h:115: if(CODE == NEXT) tmp = (tmp-1 + 2)%2;
      000C92 BE 3D 0A         [24] 2992 	cjne	r6,#0x3d,00106$
      000C95 BF C2 07         [24] 2993 	cjne	r7,#0xc2,00106$
      000C98 8C 05            [24] 2994 	mov	ar5,r4
      000C9A ED               [12] 2995 	mov	a,r5
      000C9B 04               [12] 2996 	inc	a
      000C9C 54 01            [12] 2997 	anl	a,#0x01
      000C9E FC               [12] 2998 	mov	r4,a
      000C9F                       2999 00106$:
                                   3000 ;	main.h:116: if(CODE == ON_OFF) return 0;
      000C9F BE 5D 07         [24] 3001 	cjne	r6,#0x5d,00108$
      000CA2 BF A2 04         [24] 3002 	cjne	r7,#0xa2,00108$
      000CA5 75 82 00         [24] 3003 	mov	dpl, #0x00
      000CA8 22               [24] 3004 	ret
      000CA9                       3005 00108$:
                                   3006 ;	main.h:117: if(CODE == MODE) return 0;
      000CA9 BE 9D 07         [24] 3007 	cjne	r6,#0x9d,00110$
      000CAC BF 62 04         [24] 3008 	cjne	r7,#0x62,00110$
      000CAF 75 82 00         [24] 3009 	mov	dpl, #0x00
      000CB2 22               [24] 3010 	ret
      000CB3                       3011 00110$:
                                   3012 ;	main.h:118: switch (tmp) {
      000CB3 BC 00 02         [24] 3013 	cjne	r4,#0x00,00184$
      000CB6 80 05            [24] 3014 	sjmp	00111$
      000CB8                       3015 00184$:
                                   3016 ;	main.h:119: case 0:
      000CB8 BC 01 58         [24] 3017 	cjne	r4,#0x01,00113$
      000CBB 80 29            [24] 3018 	sjmp	00112$
      000CBD                       3019 00111$:
                                   3020 ;	main.h:120: LED[7] = DIGIT_CODE[13]; 
      000CBD 90 11 DA         [24] 3021 	mov	dptr,#(_DIGIT_CODE + 0x000d)
      000CC0 E4               [12] 3022 	clr	a
      000CC1 93               [24] 3023 	movc	a,@a+dptr
      000CC2 F5 41            [12] 3024 	mov	(_LED + 0x0007), a
                                   3025 ;	main.h:121: LED[6] = DIGIT_CODE[dev]; 
      000CC4 85 70 82         [24] 3026 	mov	dpl,_SET_ON_OFF_sloc0_1_0
      000CC7 85 71 83         [24] 3027 	mov	dph,(_SET_ON_OFF_sloc0_1_0 + 1)
      000CCA E4               [12] 3028 	clr	a
      000CCB 93               [24] 3029 	movc	a,@a+dptr
      000CCC F5 40            [12] 3030 	mov	(_LED + 0x0006), a
                                   3031 ;	main.h:122: LED[5] = 0; 
      000CCE 75 3F 00         [24] 3032 	mov	(_LED + 0x0005),#0x00
                                   3033 ;	main.h:123: LED[4] = 0;
      000CD1 75 3E 00         [24] 3034 	mov	(_LED + 0x0004),#0x00
                                   3035 ;	main.h:124: LED[3] = DIGIT_CODE[0]; 
      000CD4 90 11 CD         [24] 3036 	mov	dptr,#_DIGIT_CODE
      000CD7 E4               [12] 3037 	clr	a
      000CD8 93               [24] 3038 	movc	a,@a+dptr
      000CD9 F5 3D            [12] 3039 	mov	(_LED + 0x0003), a
                                   3040 ;	main.h:125: LED[2] = 0x37;
      000CDB 75 3C 37         [24] 3041 	mov	(_LED + 0x0002),#0x37
                                   3042 ;	main.h:126: LED[1] = 0x0; 
      000CDE 75 3B 00         [24] 3043 	mov	(_LED + 0x0001),#0x00
                                   3044 ;	main.h:127: LED[0] = 0x0;
      000CE1 75 3A 00         [24] 3045 	mov	_LED,#0x00
                                   3046 ;	main.h:128: break;
                                   3047 ;	main.h:129: case 1:
      000CE4 80 2D            [24] 3048 	sjmp	00113$
      000CE6                       3049 00112$:
                                   3050 ;	main.h:130: LED[7] = DIGIT_CODE[13]; 
      000CE6 90 11 DA         [24] 3051 	mov	dptr,#(_DIGIT_CODE + 0x000d)
      000CE9 E4               [12] 3052 	clr	a
      000CEA 93               [24] 3053 	movc	a,@a+dptr
      000CEB F5 41            [12] 3054 	mov	(_LED + 0x0007), a
                                   3055 ;	main.h:131: LED[6] = DIGIT_CODE[dev]; 
      000CED 8A 82            [24] 3056 	mov	dpl,r2
      000CEF 8B 83            [24] 3057 	mov	dph,r3
      000CF1 E4               [12] 3058 	clr	a
      000CF2 93               [24] 3059 	movc	a,@a+dptr
      000CF3 F5 40            [12] 3060 	mov	(_LED + 0x0006), a
                                   3061 ;	main.h:132: LED[5] = 0; 
      000CF5 75 3F 00         [24] 3062 	mov	(_LED + 0x0005),#0x00
                                   3063 ;	main.h:133: LED[4] = 0;
      000CF8 75 3E 00         [24] 3064 	mov	(_LED + 0x0004),#0x00
                                   3065 ;	main.h:134: LED[3] = DIGIT_CODE[0]; 
      000CFB 90 11 CD         [24] 3066 	mov	dptr,#_DIGIT_CODE
      000CFE E4               [12] 3067 	clr	a
      000CFF 93               [24] 3068 	movc	a,@a+dptr
      000D00 F5 3D            [12] 3069 	mov	(_LED + 0x0003), a
                                   3070 ;	main.h:135: LED[2] = DIGIT_CODE[15]; 
      000D02 90 11 DC         [24] 3071 	mov	dptr,#(_DIGIT_CODE + 0x000f)
      000D05 E4               [12] 3072 	clr	a
      000D06 93               [24] 3073 	movc	a,@a+dptr
      000D07 F5 3C            [12] 3074 	mov	(_LED + 0x0002), a
                                   3075 ;	main.h:136: LED[1] = DIGIT_CODE[15]; 
      000D09 90 11 DC         [24] 3076 	mov	dptr,#(_DIGIT_CODE + 0x000f)
      000D0C E4               [12] 3077 	clr	a
      000D0D 93               [24] 3078 	movc	a,@a+dptr
      000D0E F5 3B            [12] 3079 	mov	(_LED + 0x0001), a
                                   3080 ;	main.h:137: LED[0] = 0;
      000D10 75 3A 00         [24] 3081 	mov	_LED,#0x00
                                   3082 ;	main.h:139: }
      000D13                       3083 00113$:
                                   3084 ;	main.h:140: Disp8leds7seg(50);
      000D13 90 00 32         [24] 3085 	mov	dptr,#0x0032
      000D16 C0 04            [24] 3086 	push	ar4
      000D18 C0 03            [24] 3087 	push	ar3
      000D1A C0 02            [24] 3088 	push	ar2
      000D1C 12 08 45         [24] 3089 	lcall	_Disp8leds7seg
      000D1F D0 02            [24] 3090 	pop	ar2
      000D21 D0 03            [24] 3091 	pop	ar3
      000D23 D0 04            [24] 3092 	pop	ar4
      000D25 02 0C 68         [24] 3093 	ljmp	00115$
      000D28                       3094 00116$:
                                   3095 ;	main.h:142: if(YES_NO()){
      000D28 C0 04            [24] 3096 	push	ar4
      000D2A 12 0A AF         [24] 3097 	lcall	_YES_NO
      000D2D E5 82            [12] 3098 	mov	a, dpl
      000D2F D0 04            [24] 3099 	pop	ar4
      000D31 60 11            [24] 3100 	jz	00118$
                                   3101 ;	main.h:143: *val = tmp;
      000D33 85 6D 82         [24] 3102 	mov	dpl,_SET_ON_OFF_val_10000_104
      000D36 85 6E 83         [24] 3103 	mov	dph,(_SET_ON_OFF_val_10000_104 + 1)
      000D39 85 6F F0         [24] 3104 	mov	b,(_SET_ON_OFF_val_10000_104 + 2)
      000D3C EC               [12] 3105 	mov	a,r4
      000D3D 12 10 F2         [24] 3106 	lcall	__gptrput
                                   3107 ;	main.h:144: return 1;
      000D40 75 82 01         [24] 3108 	mov	dpl, #0x01
      000D43 22               [24] 3109 	ret
      000D44                       3110 00118$:
                                   3111 ;	main.h:146: return 0;
      000D44 75 82 00         [24] 3112 	mov	dpl, #0x00
                                   3113 ;	main.h:147: }
      000D47 22               [24] 3114 	ret
                                   3115 ;------------------------------------------------------------
                                   3116 ;Allocation info for local variables in function 'DEV_CTL'
                                   3117 ;------------------------------------------------------------
                                   3118 ;STATE         Allocated with name '_DEV_CTL_PARM_2'
                                   3119 ;DEV           Allocated to registers r7 
                                   3120 ;------------------------------------------------------------
                                   3121 ;	main.h:149: void DEV_CTL(uint8 DEV, uint8 STATE){
                                   3122 ;	-----------------------------------------
                                   3123 ;	 function DEV_CTL
                                   3124 ;	-----------------------------------------
      000D48                       3125 _DEV_CTL:
      000D48 AF 82            [24] 3126 	mov	r7, dpl
                                   3127 ;	main.h:150: switch (DEV) {
      000D4A BF 00 02         [24] 3128 	cjne	r7,#0x00,00125$
      000D4D 80 0A            [24] 3129 	sjmp	00101$
      000D4F                       3130 00125$:
      000D4F BF 01 02         [24] 3131 	cjne	r7,#0x01,00126$
      000D52 80 0C            [24] 3132 	sjmp	00102$
      000D54                       3133 00126$:
                                   3134 ;	main.h:151: case 0: DEV0 = (STATE)?(HIGH):(LOW); break;
      000D54 BF 02 16         [24] 3135 	cjne	r7,#0x02,00105$
      000D57 80 0E            [24] 3136 	sjmp	00103$
      000D59                       3137 00101$:
                                   3138 ;	assignBit
      000D59 E5 08            [12] 3139 	mov	a,_DEV_CTL_PARM_2
      000D5B 24 FF            [12] 3140 	add	a,#0xff
      000D5D 92 05            [24] 3141 	mov	_DEV0,c
                                   3142 ;	main.h:152: case 1: DEV1 = (STATE)?(HIGH):(LOW); break;
      000D5F 22               [24] 3143 	ret
      000D60                       3144 00102$:
                                   3145 ;	assignBit
      000D60 E5 08            [12] 3146 	mov	a,_DEV_CTL_PARM_2
      000D62 24 FF            [12] 3147 	add	a,#0xff
      000D64 92 06            [24] 3148 	mov	_DEV1,c
                                   3149 ;	main.h:153: case 2: DEV2 = (STATE)?(HIGH):(LOW); break;
      000D66 22               [24] 3150 	ret
      000D67                       3151 00103$:
                                   3152 ;	assignBit
      000D67 E5 08            [12] 3153 	mov	a,_DEV_CTL_PARM_2
      000D69 24 FF            [12] 3154 	add	a,#0xff
      000D6B 92 07            [24] 3155 	mov	_DEV2,c
                                   3156 ;	main.h:154: }
      000D6D                       3157 00105$:
                                   3158 ;	main.h:155: }
      000D6D 22               [24] 3159 	ret
                                   3160 ;------------------------------------------------------------
                                   3161 ;Allocation info for local variables in function 'SHOW_MODE'
                                   3162 ;------------------------------------------------------------
                                   3163 ;M             Allocated to registers r7 
                                   3164 ;------------------------------------------------------------
                                   3165 ;	main.h:157: void SHOW_MODE(uint8 M){
                                   3166 ;	-----------------------------------------
                                   3167 ;	 function SHOW_MODE
                                   3168 ;	-----------------------------------------
      000D6E                       3169 _SHOW_MODE:
      000D6E AF 82            [24] 3170 	mov	r7, dpl
                                   3171 ;	main.h:158: LED[7] = 0x39; LED[5] = 0xF, LED[6] = DIGIT_CODE[M];
      000D70 75 41 39         [24] 3172 	mov	(_LED + 0x0007),#0x39
      000D73 75 3F 0F         [24] 3173 	mov	(_LED + 0x0005),#0x0f
      000D76 EF               [12] 3174 	mov	a,r7
      000D77 90 11 CD         [24] 3175 	mov	dptr,#_DIGIT_CODE
      000D7A 93               [24] 3176 	movc	a,@a+dptr
      000D7B F5 40            [12] 3177 	mov	(_LED + 0x0006), a
                                   3178 ;	main.h:159: Disp8leds7seg(1);
      000D7D 90 00 01         [24] 3179 	mov	dptr,#0x0001
                                   3180 ;	main.h:160: }
      000D80 02 08 45         [24] 3181 	ljmp	_Disp8leds7seg
                                   3182 ;------------------------------------------------------------
                                   3183 ;Allocation info for local variables in function 'change_mode'
                                   3184 ;------------------------------------------------------------
                                   3185 ;CODE          Allocated to registers r6 r7 
                                   3186 ;STATE         Allocated with name '_change_mode_STATE_10000_115'
                                   3187 ;------------------------------------------------------------
                                   3188 ;	main.h:162: void change_mode(uint32 CODE){
                                   3189 ;	-----------------------------------------
                                   3190 ;	 function change_mode
                                   3191 ;	-----------------------------------------
      000D83                       3192 _change_mode:
      000D83 AE 82            [24] 3193 	mov	r6, dpl
      000D85 AF 83            [24] 3194 	mov	r7, dph
                                   3195 ;	main.h:163: uint8 STATE = 0;
      000D87 75 72 00         [24] 3196 	mov	_change_mode_STATE_10000_115,#0x00
                                   3197 ;	main.h:165: switch (CODE) {
      000D8A BE FD 05         [24] 3198 	cjne	r6,#0xfd,00202$
      000D8D BF 02 02         [24] 3199 	cjne	r7,#0x02,00202$
      000D90 80 1D            [24] 3200 	sjmp	00102$
      000D92                       3201 00202$:
      000D92 BE 9D 05         [24] 3202 	cjne	r6,#0x9d,00203$
      000D95 BF 62 02         [24] 3203 	cjne	r7,#0x62,00203$
      000D98 80 5B            [24] 3204 	sjmp	00104$
      000D9A                       3205 00203$:
      000D9A BE 5D 05         [24] 3206 	cjne	r6,#0x5d,00204$
      000D9D BF A2 02         [24] 3207 	cjne	r7,#0xa2,00204$
      000DA0 80 08            [24] 3208 	sjmp	00101$
      000DA2                       3209 00204$:
                                   3210 ;	main.h:166: case ON_OFF: CURRENT_MODE = REMOTE; break;
      000DA2 BE 3D 6F         [24] 3211 	cjne	r6,#0x3d,00105$
      000DA5 BF C2 6C         [24] 3212 	cjne	r7,#0xc2,00105$
      000DA8 80 2A            [24] 3213 	sjmp	00103$
      000DAA                       3214 00101$:
      000DAA 75 4A 00         [24] 3215 	mov	_CURRENT_MODE,#0x00
                                   3216 ;	main.h:167: case PREV: CURRENT_MODE = (CURRENT_MODE-1+8)%8; break;
      000DAD 80 65            [24] 3217 	sjmp	00105$
      000DAF                       3218 00102$:
      000DAF AC 4A            [24] 3219 	mov	r4,_CURRENT_MODE
      000DB1 7D 00            [12] 3220 	mov	r5,#0x00
      000DB3 74 07            [12] 3221 	mov	a,#0x07
      000DB5 2C               [12] 3222 	add	a, r4
      000DB6 F5 82            [12] 3223 	mov	dpl,a
      000DB8 E4               [12] 3224 	clr	a
      000DB9 3D               [12] 3225 	addc	a, r5
      000DBA F5 83            [12] 3226 	mov	dph,a
      000DBC 75 08 08         [24] 3227 	mov	__modsint_PARM_2,#0x08
      000DBF 8D 09            [24] 3228 	mov	(__modsint_PARM_2 + 1),r5
      000DC1 C0 07            [24] 3229 	push	ar7
      000DC3 C0 06            [24] 3230 	push	ar6
      000DC5 12 11 93         [24] 3231 	lcall	__modsint
      000DC8 AC 82            [24] 3232 	mov	r4, dpl
      000DCA AD 83            [24] 3233 	mov	r5, dph
      000DCC D0 06            [24] 3234 	pop	ar6
      000DCE D0 07            [24] 3235 	pop	ar7
      000DD0 8C 4A            [24] 3236 	mov	_CURRENT_MODE,r4
                                   3237 ;	main.h:168: case NEXT: CURRENT_MODE = (CURRENT_MODE+1)%8; break;
      000DD2 80 40            [24] 3238 	sjmp	00105$
      000DD4                       3239 00103$:
      000DD4 AC 4A            [24] 3240 	mov	r4,_CURRENT_MODE
      000DD6 7D 00            [12] 3241 	mov	r5,#0x00
      000DD8 8C 82            [24] 3242 	mov	dpl,r4
      000DDA 8D 83            [24] 3243 	mov	dph,r5
      000DDC A3               [24] 3244 	inc	dptr
      000DDD 75 08 08         [24] 3245 	mov	__modsint_PARM_2,#0x08
      000DE0 8D 09            [24] 3246 	mov	(__modsint_PARM_2 + 1),r5
      000DE2 C0 07            [24] 3247 	push	ar7
      000DE4 C0 06            [24] 3248 	push	ar6
      000DE6 12 11 93         [24] 3249 	lcall	__modsint
      000DE9 AC 82            [24] 3250 	mov	r4, dpl
      000DEB AD 83            [24] 3251 	mov	r5, dph
      000DED D0 06            [24] 3252 	pop	ar6
      000DEF D0 07            [24] 3253 	pop	ar7
      000DF1 8C 4A            [24] 3254 	mov	_CURRENT_MODE,r4
                                   3255 ;	main.h:169: case MODE: CURRENT_MODE = (CURRENT_MODE+1)%8; break;
      000DF3 80 1F            [24] 3256 	sjmp	00105$
      000DF5                       3257 00104$:
      000DF5 AC 4A            [24] 3258 	mov	r4,_CURRENT_MODE
      000DF7 7D 00            [12] 3259 	mov	r5,#0x00
      000DF9 8C 82            [24] 3260 	mov	dpl,r4
      000DFB 8D 83            [24] 3261 	mov	dph,r5
      000DFD A3               [24] 3262 	inc	dptr
      000DFE 75 08 08         [24] 3263 	mov	__modsint_PARM_2,#0x08
      000E01 8D 09            [24] 3264 	mov	(__modsint_PARM_2 + 1),r5
      000E03 C0 07            [24] 3265 	push	ar7
      000E05 C0 06            [24] 3266 	push	ar6
      000E07 12 11 93         [24] 3267 	lcall	__modsint
      000E0A AC 82            [24] 3268 	mov	r4, dpl
      000E0C AD 83            [24] 3269 	mov	r5, dph
      000E0E D0 06            [24] 3270 	pop	ar6
      000E10 D0 07            [24] 3271 	pop	ar7
      000E12 8C 4A            [24] 3272 	mov	_CURRENT_MODE,r4
                                   3273 ;	main.h:170: }
      000E14                       3274 00105$:
                                   3275 ;	main.h:172: switch (CURRENT_MODE) {
      000E14 E5 4A            [12] 3276 	mov	a,_CURRENT_MODE
      000E16 24 F8            [12] 3277 	add	a,#0xff - 0x07
      000E18 50 01            [24] 3278 	jnc	00206$
      000E1A 22               [24] 3279 	ret
      000E1B                       3280 00206$:
      000E1B E5 4A            [12] 3281 	mov	a,_CURRENT_MODE
      000E1D 24 0B            [12] 3282 	add	a,#(00207$-3-.)
      000E1F 83               [24] 3283 	movc	a,@a+pc
      000E20 F5 82            [12] 3284 	mov	dpl,a
      000E22 E5 4A            [12] 3285 	mov	a,_CURRENT_MODE
      000E24 24 0C            [12] 3286 	add	a,#(00208$-3-.)
      000E26 83               [24] 3287 	movc	a,@a+pc
      000E27 F5 83            [12] 3288 	mov	dph,a
      000E29 E4               [12] 3289 	clr	a
      000E2A 73               [24] 3290 	jmp	@a+dptr
      000E2B                       3291 00207$:
      000E2B 3B                    3292 	.db	00106$
      000E2C 41                    3293 	.db	00107$
      000E2D 47                    3294 	.db	00108$
      000E2E 76                    3295 	.db	00111$
      000E2F A5                    3296 	.db	00114$
      000E30 D4                    3297 	.db	00117$
      000E31 04                    3298 	.db	00120$
      000E32 3C                    3299 	.db	00123$
      000E33                       3300 00208$:
      000E33 0E                    3301 	.db	00106$>>8
      000E34 0E                    3302 	.db	00107$>>8
      000E35 0E                    3303 	.db	00108$>>8
      000E36 0E                    3304 	.db	00111$>>8
      000E37 0E                    3305 	.db	00114$>>8
      000E38 0E                    3306 	.db	00117$>>8
      000E39 0F                    3307 	.db	00120$>>8
      000E3A 0F                    3308 	.db	00123$>>8
                                   3309 ;	main.h:173: case REMOTE:
      000E3B                       3310 00106$:
                                   3311 ;	main.h:174: SHOW_MODE(1);
      000E3B 75 82 01         [24] 3312 	mov	dpl, #0x01
                                   3313 ;	main.h:175: return;
      000E3E 02 0D 6E         [24] 3314 	ljmp	_SHOW_MODE
                                   3315 ;	main.h:177: case SET_DEV_ENABLE:
      000E41                       3316 00107$:
                                   3317 ;	main.h:178: SHOW_MODE(2);
      000E41 75 82 02         [24] 3318 	mov	dpl, #0x02
                                   3319 ;	main.h:179: return;
      000E44 02 0D 6E         [24] 3320 	ljmp	_SHOW_MODE
                                   3321 ;	main.h:181: case DEV_0_CTL:
      000E47                       3322 00108$:
                                   3323 ;	main.h:182: SHOW_MODE(3);
      000E47 75 82 03         [24] 3324 	mov	dpl, #0x03
      000E4A C0 07            [24] 3325 	push	ar7
      000E4C C0 06            [24] 3326 	push	ar6
      000E4E 12 0D 6E         [24] 3327 	lcall	_SHOW_MODE
      000E51 D0 06            [24] 3328 	pop	ar6
      000E53 D0 07            [24] 3329 	pop	ar7
                                   3330 ;	main.h:183: if(CODE == PLAY_PAUSE){
      000E55 BE DD 18         [24] 3331 	cjne	r6,#0xdd,00110$
      000E58 BF 22 15         [24] 3332 	cjne	r7,#0x22,00110$
                                   3333 ;	main.h:184: SET_ON_OFF(&STATE, 0x0);
      000E5B 75 6C 00         [24] 3334 	mov	_SET_ON_OFF_PARM_2,#0x00
      000E5E 90 00 72         [24] 3335 	mov	dptr,#_change_mode_STATE_10000_115
      000E61 75 F0 40         [24] 3336 	mov	b, #0x40
      000E64 12 0C 50         [24] 3337 	lcall	_SET_ON_OFF
                                   3338 ;	main.h:185: DEV_CTL(0x0, STATE);
      000E67 85 72 08         [24] 3339 	mov	_DEV_CTL_PARM_2,_change_mode_STATE_10000_115
      000E6A 75 82 00         [24] 3340 	mov	dpl, #0x00
      000E6D 12 0D 48         [24] 3341 	lcall	_DEV_CTL
      000E70                       3342 00110$:
                                   3343 ;	main.h:187: SHOW_MODE(3);
      000E70 75 82 03         [24] 3344 	mov	dpl, #0x03
                                   3345 ;	main.h:188: return;
      000E73 02 0D 6E         [24] 3346 	ljmp	_SHOW_MODE
                                   3347 ;	main.h:190: case DEV_1_CTL:
      000E76                       3348 00111$:
                                   3349 ;	main.h:191: SHOW_MODE(4);
      000E76 75 82 04         [24] 3350 	mov	dpl, #0x04
      000E79 C0 07            [24] 3351 	push	ar7
      000E7B C0 06            [24] 3352 	push	ar6
      000E7D 12 0D 6E         [24] 3353 	lcall	_SHOW_MODE
      000E80 D0 06            [24] 3354 	pop	ar6
      000E82 D0 07            [24] 3355 	pop	ar7
                                   3356 ;	main.h:192: if(CODE == PLAY_PAUSE){
      000E84 BE DD 18         [24] 3357 	cjne	r6,#0xdd,00113$
      000E87 BF 22 15         [24] 3358 	cjne	r7,#0x22,00113$
                                   3359 ;	main.h:193: SET_ON_OFF(&STATE, 0x1);
      000E8A 75 6C 01         [24] 3360 	mov	_SET_ON_OFF_PARM_2,#0x01
      000E8D 90 00 72         [24] 3361 	mov	dptr,#_change_mode_STATE_10000_115
      000E90 75 F0 40         [24] 3362 	mov	b, #0x40
      000E93 12 0C 50         [24] 3363 	lcall	_SET_ON_OFF
                                   3364 ;	main.h:194: DEV_CTL(0x1, STATE);
      000E96 85 72 08         [24] 3365 	mov	_DEV_CTL_PARM_2,_change_mode_STATE_10000_115
      000E99 75 82 01         [24] 3366 	mov	dpl, #0x01
      000E9C 12 0D 48         [24] 3367 	lcall	_DEV_CTL
      000E9F                       3368 00113$:
                                   3369 ;	main.h:196: SHOW_MODE(4);
      000E9F 75 82 04         [24] 3370 	mov	dpl, #0x04
                                   3371 ;	main.h:197: return;
      000EA2 02 0D 6E         [24] 3372 	ljmp	_SHOW_MODE
                                   3373 ;	main.h:199: case DEV_2_CTL:
      000EA5                       3374 00114$:
                                   3375 ;	main.h:200: SHOW_MODE(5);
      000EA5 75 82 05         [24] 3376 	mov	dpl, #0x05
      000EA8 C0 07            [24] 3377 	push	ar7
      000EAA C0 06            [24] 3378 	push	ar6
      000EAC 12 0D 6E         [24] 3379 	lcall	_SHOW_MODE
      000EAF D0 06            [24] 3380 	pop	ar6
      000EB1 D0 07            [24] 3381 	pop	ar7
                                   3382 ;	main.h:201: if(CODE == PLAY_PAUSE){
      000EB3 BE DD 18         [24] 3383 	cjne	r6,#0xdd,00116$
      000EB6 BF 22 15         [24] 3384 	cjne	r7,#0x22,00116$
                                   3385 ;	main.h:202: SET_ON_OFF(&STATE, 0x2);
      000EB9 75 6C 02         [24] 3386 	mov	_SET_ON_OFF_PARM_2,#0x02
      000EBC 90 00 72         [24] 3387 	mov	dptr,#_change_mode_STATE_10000_115
      000EBF 75 F0 40         [24] 3388 	mov	b, #0x40
      000EC2 12 0C 50         [24] 3389 	lcall	_SET_ON_OFF
                                   3390 ;	main.h:203: DEV_CTL(0x2, STATE);
      000EC5 85 72 08         [24] 3391 	mov	_DEV_CTL_PARM_2,_change_mode_STATE_10000_115
      000EC8 75 82 02         [24] 3392 	mov	dpl, #0x02
      000ECB 12 0D 48         [24] 3393 	lcall	_DEV_CTL
      000ECE                       3394 00116$:
                                   3395 ;	main.h:205: SHOW_MODE(5);
      000ECE 75 82 05         [24] 3396 	mov	dpl, #0x05
                                   3397 ;	main.h:206: return;
      000ED1 02 0D 6E         [24] 3398 	ljmp	_SHOW_MODE
                                   3399 ;	main.h:208: case DEV_2_SET_ON_TIMER:
      000ED4                       3400 00117$:
                                   3401 ;	main.h:209: SHOW_MODE(6);
      000ED4 75 82 06         [24] 3402 	mov	dpl, #0x06
      000ED7 C0 07            [24] 3403 	push	ar7
      000ED9 C0 06            [24] 3404 	push	ar6
      000EDB 12 0D 6E         [24] 3405 	lcall	_SHOW_MODE
      000EDE D0 06            [24] 3406 	pop	ar6
      000EE0 D0 07            [24] 3407 	pop	ar7
                                   3408 ;	main.h:210: if(CODE == PLAY_PAUSE) {
      000EE2 BE DD 19         [24] 3409 	cjne	r6,#0xdd,00119$
      000EE5 BF 22 16         [24] 3410 	cjne	r7,#0x22,00119$
                                   3411 ;	main.h:211: LED[7] = DIGIT_CODE[0]; LED[6] = 0x37;
      000EE8 90 11 CD         [24] 3412 	mov	dptr,#_DIGIT_CODE
      000EEB E4               [12] 3413 	clr	a
      000EEC 93               [24] 3414 	movc	a,@a+dptr
      000EED F5 41            [12] 3415 	mov	(_LED + 0x0007), a
      000EEF 75 40 37         [24] 3416 	mov	(_LED + 0x0006),#0x37
                                   3417 ;	main.h:212: LED[5] = 0x0;
      000EF2 75 3F 00         [24] 3418 	mov	(_LED + 0x0005),#0x00
                                   3419 ;	main.h:213: SET_TIMER(&time_on);
      000EF5 90 00 54         [24] 3420 	mov	dptr,#_time_on
      000EF8 75 F0 40         [24] 3421 	mov	b, #0x40
      000EFB 12 0B 00         [24] 3422 	lcall	_SET_TIMER
      000EFE                       3423 00119$:
                                   3424 ;	main.h:215: SHOW_MODE(6);
      000EFE 75 82 06         [24] 3425 	mov	dpl, #0x06
                                   3426 ;	main.h:216: return;
      000F01 02 0D 6E         [24] 3427 	ljmp	_SHOW_MODE
                                   3428 ;	main.h:218: case DEV_2_SET_OFF_TIMER:
      000F04                       3429 00120$:
                                   3430 ;	main.h:219: SHOW_MODE(7);
      000F04 75 82 07         [24] 3431 	mov	dpl, #0x07
      000F07 C0 07            [24] 3432 	push	ar7
      000F09 C0 06            [24] 3433 	push	ar6
      000F0B 12 0D 6E         [24] 3434 	lcall	_SHOW_MODE
      000F0E D0 06            [24] 3435 	pop	ar6
      000F10 D0 07            [24] 3436 	pop	ar7
                                   3437 ;	main.h:220: if(CODE == PLAY_PAUSE){
      000F12 BE DD 21         [24] 3438 	cjne	r6,#0xdd,00122$
      000F15 BF 22 1E         [24] 3439 	cjne	r7,#0x22,00122$
                                   3440 ;	main.h:221: SET_TIMER(&time_off);
      000F18 90 00 5B         [24] 3441 	mov	dptr,#_time_off
      000F1B 75 F0 40         [24] 3442 	mov	b, #0x40
      000F1E 12 0B 00         [24] 3443 	lcall	_SET_TIMER
                                   3444 ;	main.h:222: LED[7] = DIGIT_CODE[0]; LED[6] = DIGIT_CODE[15]; 
      000F21 90 11 CD         [24] 3445 	mov	dptr,#_DIGIT_CODE
      000F24 E4               [12] 3446 	clr	a
      000F25 93               [24] 3447 	movc	a,@a+dptr
      000F26 F5 41            [12] 3448 	mov	(_LED + 0x0007), a
      000F28 90 11 DC         [24] 3449 	mov	dptr,#(_DIGIT_CODE + 0x000f)
      000F2B E4               [12] 3450 	clr	a
      000F2C 93               [24] 3451 	movc	a,@a+dptr
      000F2D F5 40            [12] 3452 	mov	(_LED + 0x0006), a
                                   3453 ;	main.h:223: LED[5] = DIGIT_CODE[15];
      000F2F 90 11 DC         [24] 3454 	mov	dptr,#(_DIGIT_CODE + 0x000f)
      000F32 E4               [12] 3455 	clr	a
      000F33 93               [24] 3456 	movc	a,@a+dptr
      000F34 F5 3F            [12] 3457 	mov	(_LED + 0x0005), a
      000F36                       3458 00122$:
                                   3459 ;	main.h:225: SHOW_MODE(7);
      000F36 75 82 07         [24] 3460 	mov	dpl, #0x07
                                   3461 ;	main.h:226: return;
                                   3462 ;	main.h:228: case SETUP_SYS_TIME:
      000F39 02 0D 6E         [24] 3463 	ljmp	_SHOW_MODE
      000F3C                       3464 00123$:
                                   3465 ;	main.h:229: SHOW_MODE(8);
      000F3C 75 82 08         [24] 3466 	mov	dpl, #0x08
      000F3F C0 07            [24] 3467 	push	ar7
      000F41 C0 06            [24] 3468 	push	ar6
      000F43 12 0D 6E         [24] 3469 	lcall	_SHOW_MODE
      000F46 D0 06            [24] 3470 	pop	ar6
      000F48 D0 07            [24] 3471 	pop	ar7
                                   3472 ;	main.h:230: if( CODE == PLAY_PAUSE && SET_TIMER(&sys_time) ){
      000F4A BE DD 2D         [24] 3473 	cjne	r6,#0xdd,00125$
      000F4D BF 22 2A         [24] 3474 	cjne	r7,#0x22,00125$
      000F50 90 00 4D         [24] 3475 	mov	dptr,#_sys_time
      000F53 75 F0 40         [24] 3476 	mov	b, #0x40
      000F56 12 0B 00         [24] 3477 	lcall	_SET_TIMER
      000F59 E5 82            [12] 3478 	mov	a, dpl
      000F5B 60 1D            [24] 3479 	jz	00125$
                                   3480 ;	main.h:231: LED[7] = DIGIT_CODE[5]; LED[6] = 0x72; LED[5] = DIGIT_CODE[5];
      000F5D 90 11 D2         [24] 3481 	mov	dptr,#(_DIGIT_CODE + 0x0005)
      000F60 E4               [12] 3482 	clr	a
      000F61 93               [24] 3483 	movc	a,@a+dptr
      000F62 F5 41            [12] 3484 	mov	(_LED + 0x0007), a
      000F64 75 40 72         [24] 3485 	mov	(_LED + 0x0006),#0x72
      000F67 90 11 D2         [24] 3486 	mov	dptr,#(_DIGIT_CODE + 0x0005)
      000F6A E4               [12] 3487 	clr	a
      000F6B 93               [24] 3488 	movc	a,@a+dptr
      000F6C F5 3F            [12] 3489 	mov	(_LED + 0x0005), a
                                   3490 ;	main.h:232: ds1302_write_time(&sys_time, 0x3F);
      000F6E 75 39 3F         [24] 3491 	mov	_ds1302_write_time_PARM_2,#0x3f
      000F71 90 00 4D         [24] 3492 	mov	dptr,#_sys_time
      000F74 75 F0 40         [24] 3493 	mov	b, #0x40
      000F77 12 05 A1         [24] 3494 	lcall	_ds1302_write_time
      000F7A                       3495 00125$:
                                   3496 ;	main.h:234: SHOW_MODE(8);
      000F7A 75 82 08         [24] 3497 	mov	dpl, #0x08
                                   3498 ;	main.h:235: return;
                                   3499 ;	main.h:236: }
                                   3500 ;	main.h:237: }
      000F7D 02 0D 6E         [24] 3501 	ljmp	_SHOW_MODE
                                   3502 ;------------------------------------------------------------
                                   3503 ;Allocation info for local variables in function 'sys_time_disp'
                                   3504 ;------------------------------------------------------------
                                   3505 ;mili_sec      Allocated to registers r6 r7 
                                   3506 ;------------------------------------------------------------
                                   3507 ;	main.h:239: void sys_time_disp(uint32 mili_sec){
                                   3508 ;	-----------------------------------------
                                   3509 ;	 function sys_time_disp
                                   3510 ;	-----------------------------------------
      000F80                       3511 _sys_time_disp:
      000F80 AE 82            [24] 3512 	mov	r6, dpl
      000F82 AF 83            [24] 3513 	mov	r7, dph
                                   3514 ;	main.h:240: LED[3] = DIGIT_CODE[sys_time.HOUR/10];
      000F84 AD 51            [24] 3515 	mov	r5,(_sys_time + 0x0004)
      000F86 75 F0 0A         [24] 3516 	mov	b,#0x0a
      000F89 ED               [12] 3517 	mov	a,r5
      000F8A 84               [48] 3518 	div	ab
      000F8B 7C 00            [12] 3519 	mov	r4,#0x00
      000F8D 90 11 CD         [24] 3520 	mov	dptr,#_DIGIT_CODE
      000F90 93               [24] 3521 	movc	a,@a+dptr
      000F91 F5 3D            [12] 3522 	mov	(_LED + 0x0003), a
                                   3523 ;	main.h:241: LED[2] = DIGIT_CODE[sys_time.HOUR%10];
      000F93 AD 51            [24] 3524 	mov	r5,(_sys_time + 0x0004)
      000F95 75 F0 0A         [24] 3525 	mov	b,#0x0a
      000F98 ED               [12] 3526 	mov	a,r5
      000F99 84               [48] 3527 	div	ab
      000F9A E5 F0            [12] 3528 	mov	a,b
      000F9C 24 CD            [12] 3529 	add	a, #_DIGIT_CODE
      000F9E F5 82            [12] 3530 	mov	dpl,a
      000FA0 EC               [12] 3531 	mov	a,r4
      000FA1 34 11            [12] 3532 	addc	a, #(_DIGIT_CODE >> 8)
      000FA3 F5 83            [12] 3533 	mov	dph,a
      000FA5 E4               [12] 3534 	clr	a
      000FA6 93               [24] 3535 	movc	a,@a+dptr
      000FA7 F5 3C            [12] 3536 	mov	(_LED + 0x0002), a
                                   3537 ;	main.h:242: LED[1] = DIGIT_CODE[sys_time.MINUTE/10];
      000FA9 AD 52            [24] 3538 	mov	r5,(_sys_time + 0x0005)
      000FAB 75 F0 0A         [24] 3539 	mov	b,#0x0a
      000FAE ED               [12] 3540 	mov	a,r5
      000FAF 84               [48] 3541 	div	ab
      000FB0 24 CD            [12] 3542 	add	a, #_DIGIT_CODE
      000FB2 F5 82            [12] 3543 	mov	dpl,a
      000FB4 EC               [12] 3544 	mov	a,r4
      000FB5 34 11            [12] 3545 	addc	a, #(_DIGIT_CODE >> 8)
      000FB7 F5 83            [12] 3546 	mov	dph,a
      000FB9 E4               [12] 3547 	clr	a
      000FBA 93               [24] 3548 	movc	a,@a+dptr
      000FBB F5 3B            [12] 3549 	mov	(_LED + 0x0001), a
                                   3550 ;	main.h:243: LED[0] = DIGIT_CODE[sys_time.MINUTE%10];
      000FBD AD 52            [24] 3551 	mov	r5,(_sys_time + 0x0005)
      000FBF 75 F0 0A         [24] 3552 	mov	b,#0x0a
      000FC2 ED               [12] 3553 	mov	a,r5
      000FC3 84               [48] 3554 	div	ab
      000FC4 E5 F0            [12] 3555 	mov	a,b
      000FC6 24 CD            [12] 3556 	add	a, #_DIGIT_CODE
      000FC8 F5 82            [12] 3557 	mov	dpl,a
      000FCA EC               [12] 3558 	mov	a,r4
      000FCB 34 11            [12] 3559 	addc	a, #(_DIGIT_CODE >> 8)
      000FCD F5 83            [12] 3560 	mov	dph,a
      000FCF E4               [12] 3561 	clr	a
      000FD0 93               [24] 3562 	movc	a,@a+dptr
      000FD1 F5 3A            [12] 3563 	mov	_LED, a
                                   3564 ;	main.h:244: Disp8leds7seg(mili_sec);
      000FD3 8E 82            [24] 3565 	mov	dpl, r6
      000FD5 8F 83            [24] 3566 	mov	dph, r7
                                   3567 ;	main.h:245: }
      000FD7 02 08 45         [24] 3568 	ljmp	_Disp8leds7seg
                                   3569 ;------------------------------------------------------------
                                   3570 ;Allocation info for local variables in function 'main_intial'
                                   3571 ;------------------------------------------------------------
                                   3572 ;	main.h:247: void main_intial(){
                                   3573 ;	-----------------------------------------
                                   3574 ;	 function main_intial
                                   3575 ;	-----------------------------------------
      000FDA                       3576 _main_intial:
                                   3577 ;	main.h:248: ds1302_initial();
      000FDA 12 07 C4         [24] 3578 	lcall	_ds1302_initial
                                   3579 ;	main.h:249: IR_Reading_Initial();
      000FDD 12 09 85         [24] 3580 	lcall	_IR_Reading_Initial
                                   3581 ;	main.h:250: LED_7SEG = 0x0;
      000FE0 75 80 00         [24] 3582 	mov	_P0,#0x00
                                   3583 ;	main.h:251: sys_time.HOUR = 0;
      000FE3 75 51 00         [24] 3584 	mov	(_sys_time + 0x0004),#0x00
                                   3585 ;	main.h:252: sys_time.MINUTE = 0;
      000FE6 75 52 00         [24] 3586 	mov	(_sys_time + 0x0005),#0x00
                                   3587 ;	main.h:253: sys_time.SECOND = 0;
      000FE9 75 53 00         [24] 3588 	mov	(_sys_time + 0x0006),#0x00
                                   3589 ;	main.h:254: sys_time.DATE = 0;
      000FEC 75 4E 00         [24] 3590 	mov	(_sys_time + 0x0001),#0x00
                                   3591 ;	main.h:255: sys_time.DAY = 0;
      000FEF 75 4D 00         [24] 3592 	mov	_sys_time,#0x00
                                   3593 ;	main.h:256: sys_time.MONTH = 0;
      000FF2 75 4F 00         [24] 3594 	mov	(_sys_time + 0x0002),#0x00
                                   3595 ;	main.h:257: sys_time.YEAR = 0;
      000FF5 75 50 00         [24] 3596 	mov	(_sys_time + 0x0003),#0x00
                                   3597 ;	main.h:258: ds1302_write_time(&sys_time, 0x7F);
      000FF8 75 39 7F         [24] 3598 	mov	_ds1302_write_time_PARM_2,#0x7f
      000FFB 90 00 4D         [24] 3599 	mov	dptr,#_sys_time
      000FFE 75 F0 40         [24] 3600 	mov	b, #0x40
                                   3601 ;	main.h:259: }
      001001 02 05 A1         [24] 3602 	ljmp	_ds1302_write_time
                                   3603 ;------------------------------------------------------------
                                   3604 ;Allocation info for local variables in function 'main'
                                   3605 ;------------------------------------------------------------
                                   3606 ;C             Allocated to registers r6 r7 
                                   3607 ;------------------------------------------------------------
                                   3608 ;	main.c:3: int main(){
                                   3609 ;	-----------------------------------------
                                   3610 ;	 function main
                                   3611 ;	-----------------------------------------
      001004                       3612 _main:
                                   3613 ;	main.c:4: main_intial();
      001004 12 0F DA         [24] 3614 	lcall	_main_intial
                                   3615 ;	main.c:5: change_mode(REMOTE);
      001007 90 00 00         [24] 3616 	mov	dptr,#0x0000
      00100A 12 0D 83         [24] 3617 	lcall	_change_mode
                                   3618 ;	main.c:7: while(0x1){
      00100D                       3619 00102$:
                                   3620 ;	main.c:8: ds1302_read_time(&sys_time, 0x7);
      00100D 75 34 07         [24] 3621 	mov	_ds1302_read_time_PARM_2,#0x07
      001010 90 00 4D         [24] 3622 	mov	dptr,#_sys_time
      001013 75 F0 40         [24] 3623 	mov	b, #0x40
      001016 12 03 5A         [24] 3624 	lcall	_ds1302_read_time
                                   3625 ;	main.c:12: C = read_extracted_frame();
      001019 12 09 79         [24] 3626 	lcall	_read_extracted_frame
      00101C AE 82            [24] 3627 	mov	r6, dpl
      00101E AF 83            [24] 3628 	mov	r7, dph
                                   3629 ;	main.c:13: LED[7]= DIGIT_CODE[ (C) & 0xF];
      001020 74 0F            [12] 3630 	mov	a,#0x0f
      001022 5E               [12] 3631 	anl	a,r6
      001023 90 11 CD         [24] 3632 	mov	dptr,#_DIGIT_CODE
      001026 93               [24] 3633 	movc	a,@a+dptr
      001027 F5 41            [12] 3634 	mov	(_LED + 0x0007), a
                                   3635 ;	main.c:14: LED[6]= DIGIT_CODE[ (C>>4) & 0xF];
      001029 8E 04            [24] 3636 	mov	ar4,r6
      00102B EF               [12] 3637 	mov	a,r7
      00102C C4               [12] 3638 	swap	a
      00102D CC               [12] 3639 	xch	a,r4
      00102E C4               [12] 3640 	swap	a
      00102F 54 0F            [12] 3641 	anl	a,#0x0f
      001031 6C               [12] 3642 	xrl	a,r4
      001032 CC               [12] 3643 	xch	a,r4
      001033 54 0F            [12] 3644 	anl	a,#0x0f
      001035 CC               [12] 3645 	xch	a,r4
      001036 6C               [12] 3646 	xrl	a,r4
      001037 CC               [12] 3647 	xch	a,r4
      001038 53 04 0F         [24] 3648 	anl	ar4,#0x0f
      00103B 7D 00            [12] 3649 	mov	r5,#0x00
      00103D EC               [12] 3650 	mov	a,r4
      00103E 24 CD            [12] 3651 	add	a, #_DIGIT_CODE
      001040 F5 82            [12] 3652 	mov	dpl,a
      001042 ED               [12] 3653 	mov	a,r5
      001043 34 11            [12] 3654 	addc	a, #(_DIGIT_CODE >> 8)
      001045 F5 83            [12] 3655 	mov	dph,a
      001047 E4               [12] 3656 	clr	a
      001048 93               [24] 3657 	movc	a,@a+dptr
      001049 F5 40            [12] 3658 	mov	(_LED + 0x0006), a
                                   3659 ;	main.c:15: LED[5]= DIGIT_CODE[ (C>>8) & 0xF];
      00104B 8F 05            [24] 3660 	mov	ar5,r7
      00104D 53 05 0F         [24] 3661 	anl	ar5,#0x0f
      001050 7C 00            [12] 3662 	mov	r4,#0x00
      001052 ED               [12] 3663 	mov	a,r5
      001053 24 CD            [12] 3664 	add	a, #_DIGIT_CODE
      001055 F5 82            [12] 3665 	mov	dpl,a
      001057 EC               [12] 3666 	mov	a,r4
      001058 34 11            [12] 3667 	addc	a, #(_DIGIT_CODE >> 8)
      00105A F5 83            [12] 3668 	mov	dph,a
      00105C E4               [12] 3669 	clr	a
      00105D 93               [24] 3670 	movc	a,@a+dptr
      00105E F5 3F            [12] 3671 	mov	(_LED + 0x0005), a
                                   3672 ;	main.c:16: LED[4]= DIGIT_CODE[ (C>>12) & 0xF];
      001060 EF               [12] 3673 	mov	a,r7
      001061 C4               [12] 3674 	swap	a
      001062 54 0F            [12] 3675 	anl	a,#0x0f
      001064 FE               [12] 3676 	mov	r6,a
      001065 53 06 0F         [24] 3677 	anl	ar6,#0x0f
      001068 7F 00            [12] 3678 	mov	r7,#0x00
      00106A EE               [12] 3679 	mov	a,r6
      00106B 24 CD            [12] 3680 	add	a, #_DIGIT_CODE
      00106D F5 82            [12] 3681 	mov	dpl,a
      00106F EF               [12] 3682 	mov	a,r7
      001070 34 11            [12] 3683 	addc	a, #(_DIGIT_CODE >> 8)
      001072 F5 83            [12] 3684 	mov	dph,a
      001074 E4               [12] 3685 	clr	a
      001075 93               [24] 3686 	movc	a,@a+dptr
      001076 F5 3E            [12] 3687 	mov	(_LED + 0x0004), a
                                   3688 ;	main.c:17: LED[3]= DIGIT_CODE[ (C>>16) & 0xF];
      001078 90 11 CD         [24] 3689 	mov	dptr,#_DIGIT_CODE
      00107B E4               [12] 3690 	clr	a
      00107C 93               [24] 3691 	movc	a,@a+dptr
      00107D F5 3D            [12] 3692 	mov	(_LED + 0x0003), a
                                   3693 ;	main.c:18: LED[2]= DIGIT_CODE[ (C>>20) & 0xF];
      00107F 90 11 CD         [24] 3694 	mov	dptr,#_DIGIT_CODE
      001082 E4               [12] 3695 	clr	a
      001083 93               [24] 3696 	movc	a,@a+dptr
      001084 F5 3C            [12] 3697 	mov	(_LED + 0x0002), a
                                   3698 ;	main.c:19: LED[1]= DIGIT_CODE[ (C>>24) & 0xF];
      001086 90 11 CD         [24] 3699 	mov	dptr,#_DIGIT_CODE
      001089 E4               [12] 3700 	clr	a
      00108A 93               [24] 3701 	movc	a,@a+dptr
      00108B F5 3B            [12] 3702 	mov	(_LED + 0x0001), a
                                   3703 ;	main.c:20: LED[0]= DIGIT_CODE[ (C>>28) & 0xF];
      00108D 90 11 CD         [24] 3704 	mov	dptr,#_DIGIT_CODE
      001090 E4               [12] 3705 	clr	a
      001091 93               [24] 3706 	movc	a,@a+dptr
      001092 F5 3A            [12] 3707 	mov	_LED, a
                                   3708 ;	main.c:21: Disp8leds7seg(1000);
      001094 90 03 E8         [24] 3709 	mov	dptr,#0x03e8
      001097 12 08 45         [24] 3710 	lcall	_Disp8leds7seg
                                   3711 ;	main.c:24: return 0;
                                   3712 ;	main.c:25: }
      00109A 02 10 0D         [24] 3713 	ljmp	00102$
                                   3714 	.area CSEG    (CODE)
                                   3715 	.area CONST   (CODE)
                                   3716 	.area CONST   (CODE)
      0011CD                       3717 _DIGIT_CODE:
      0011CD 3F                    3718 	.db #0x3f	; 63
      0011CE 06                    3719 	.db #0x06	; 6
      0011CF 5B                    3720 	.db #0x5b	; 91
      0011D0 4F                    3721 	.db #0x4f	; 79	'O'
      0011D1 66                    3722 	.db #0x66	; 102	'f'
      0011D2 6D                    3723 	.db #0x6d	; 109	'm'
      0011D3 7D                    3724 	.db #0x7d	; 125
      0011D4 07                    3725 	.db #0x07	; 7
      0011D5 7F                    3726 	.db #0x7f	; 127
      0011D6 6F                    3727 	.db #0x6f	; 111	'o'
      0011D7 77                    3728 	.db #0x77	; 119	'w'
      0011D8 7C                    3729 	.db #0x7c	; 124
      0011D9 58                    3730 	.db #0x58	; 88	'X'
      0011DA 5E                    3731 	.db #0x5e	; 94
      0011DB 79                    3732 	.db #0x79	; 121	'y'
      0011DC 71                    3733 	.db #0x71	; 113	'q'
                                   3734 	.area CSEG    (CODE)
                                   3735 	.area XINIT   (CODE)
                                   3736 	.area CABS    (ABS,CODE)
