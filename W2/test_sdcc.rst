                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ISO C Compiler
                                      3 ; Version 4.4.2 #14932 (MINGW64)
                                      4 ;--------------------------------------------------------
                                      5 	.module test_sdcc
                                      6 	
                                      7 	.optsdcc -mmcs51 --model-small
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _main
                                     12 	.globl _SANG_DOI_XUNG
                                     13 	.globl _SANG_DICH
                                     14 	.globl _SANG_DAN_TAT_DAN
                                     15 	.globl _delay_ms
                                     16 	.globl _P2_SET
                                     17 	.globl _P5_7
                                     18 	.globl _P5_6
                                     19 	.globl _P5_5
                                     20 	.globl _P5_4
                                     21 	.globl _P5_3
                                     22 	.globl _P5_2
                                     23 	.globl _P5_1
                                     24 	.globl _P5_0
                                     25 	.globl _P4_7
                                     26 	.globl _P4_6
                                     27 	.globl _P4_5
                                     28 	.globl _P4_4
                                     29 	.globl _P4_3
                                     30 	.globl _P4_2
                                     31 	.globl _P4_1
                                     32 	.globl _P4_0
                                     33 	.globl _PX0L
                                     34 	.globl _PT0L
                                     35 	.globl _PX1L
                                     36 	.globl _PT1L
                                     37 	.globl _PSL
                                     38 	.globl _PT2L
                                     39 	.globl _PPCL
                                     40 	.globl _EC
                                     41 	.globl _CCF0
                                     42 	.globl _CCF1
                                     43 	.globl _CCF2
                                     44 	.globl _CCF3
                                     45 	.globl _CCF4
                                     46 	.globl _CR
                                     47 	.globl _CF
                                     48 	.globl _TF2
                                     49 	.globl _EXF2
                                     50 	.globl _RCLK
                                     51 	.globl _TCLK
                                     52 	.globl _EXEN2
                                     53 	.globl _TR2
                                     54 	.globl _C_T2
                                     55 	.globl _CP_RL2
                                     56 	.globl _T2CON_7
                                     57 	.globl _T2CON_6
                                     58 	.globl _T2CON_5
                                     59 	.globl _T2CON_4
                                     60 	.globl _T2CON_3
                                     61 	.globl _T2CON_2
                                     62 	.globl _T2CON_1
                                     63 	.globl _T2CON_0
                                     64 	.globl _PT2
                                     65 	.globl _ET2
                                     66 	.globl _CY
                                     67 	.globl _AC
                                     68 	.globl _F0
                                     69 	.globl _RS1
                                     70 	.globl _RS0
                                     71 	.globl _OV
                                     72 	.globl _F1
                                     73 	.globl _P
                                     74 	.globl _PS
                                     75 	.globl _PT1
                                     76 	.globl _PX1
                                     77 	.globl _PT0
                                     78 	.globl _PX0
                                     79 	.globl _RD
                                     80 	.globl _WR
                                     81 	.globl _T1
                                     82 	.globl _T0
                                     83 	.globl _INT1
                                     84 	.globl _INT0
                                     85 	.globl _TXD
                                     86 	.globl _RXD
                                     87 	.globl _P3_7
                                     88 	.globl _P3_6
                                     89 	.globl _P3_5
                                     90 	.globl _P3_4
                                     91 	.globl _P3_3
                                     92 	.globl _P3_2
                                     93 	.globl _P3_1
                                     94 	.globl _P3_0
                                     95 	.globl _EA
                                     96 	.globl _ES
                                     97 	.globl _ET1
                                     98 	.globl _EX1
                                     99 	.globl _ET0
                                    100 	.globl _EX0
                                    101 	.globl _P2_7
                                    102 	.globl _P2_6
                                    103 	.globl _P2_5
                                    104 	.globl _P2_4
                                    105 	.globl _P2_3
                                    106 	.globl _P2_2
                                    107 	.globl _P2_1
                                    108 	.globl _P2_0
                                    109 	.globl _SM0
                                    110 	.globl _SM1
                                    111 	.globl _SM2
                                    112 	.globl _REN
                                    113 	.globl _TB8
                                    114 	.globl _RB8
                                    115 	.globl _TI
                                    116 	.globl _RI
                                    117 	.globl _P1_7
                                    118 	.globl _P1_6
                                    119 	.globl _P1_5
                                    120 	.globl _P1_4
                                    121 	.globl _P1_3
                                    122 	.globl _P1_2
                                    123 	.globl _P1_1
                                    124 	.globl _P1_0
                                    125 	.globl _TF1
                                    126 	.globl _TR1
                                    127 	.globl _TF0
                                    128 	.globl _TR0
                                    129 	.globl _IE1
                                    130 	.globl _IT1
                                    131 	.globl _IE0
                                    132 	.globl _IT0
                                    133 	.globl _P0_7
                                    134 	.globl _P0_6
                                    135 	.globl _P0_5
                                    136 	.globl _P0_4
                                    137 	.globl _P0_3
                                    138 	.globl _P0_2
                                    139 	.globl _P0_1
                                    140 	.globl _P0_0
                                    141 	.globl _EECON
                                    142 	.globl _KBF
                                    143 	.globl _KBE
                                    144 	.globl _KBLS
                                    145 	.globl _BRL
                                    146 	.globl _BDRCON
                                    147 	.globl _T2MOD
                                    148 	.globl _SPDAT
                                    149 	.globl _SPSTA
                                    150 	.globl _SPCON
                                    151 	.globl _SADEN
                                    152 	.globl _SADDR
                                    153 	.globl _WDTPRG
                                    154 	.globl _WDTRST
                                    155 	.globl _P5
                                    156 	.globl _P4
                                    157 	.globl _IPH1
                                    158 	.globl _IPL1
                                    159 	.globl _IPH0
                                    160 	.globl _IPL0
                                    161 	.globl _IEN1
                                    162 	.globl _IEN0
                                    163 	.globl _CMOD
                                    164 	.globl _CL
                                    165 	.globl _CH
                                    166 	.globl _CCON
                                    167 	.globl _CCAPM4
                                    168 	.globl _CCAPM3
                                    169 	.globl _CCAPM2
                                    170 	.globl _CCAPM1
                                    171 	.globl _CCAPM0
                                    172 	.globl _CCAP4L
                                    173 	.globl _CCAP3L
                                    174 	.globl _CCAP2L
                                    175 	.globl _CCAP1L
                                    176 	.globl _CCAP0L
                                    177 	.globl _CCAP4H
                                    178 	.globl _CCAP3H
                                    179 	.globl _CCAP2H
                                    180 	.globl _CCAP1H
                                    181 	.globl _CCAP0H
                                    182 	.globl _CKCON1
                                    183 	.globl _CKCON0
                                    184 	.globl _CKRL
                                    185 	.globl _AUXR1
                                    186 	.globl _AUXR
                                    187 	.globl _TH2
                                    188 	.globl _TL2
                                    189 	.globl _RCAP2H
                                    190 	.globl _RCAP2L
                                    191 	.globl _T2CON
                                    192 	.globl _B
                                    193 	.globl _ACC
                                    194 	.globl _PSW
                                    195 	.globl _IP
                                    196 	.globl _P3
                                    197 	.globl _IE
                                    198 	.globl _P2
                                    199 	.globl _SBUF
                                    200 	.globl _SCON
                                    201 	.globl _P1
                                    202 	.globl _TH1
                                    203 	.globl _TH0
                                    204 	.globl _TL1
                                    205 	.globl _TL0
                                    206 	.globl _TMOD
                                    207 	.globl _TCON
                                    208 	.globl _PCON
                                    209 	.globl _DPH
                                    210 	.globl _DPL
                                    211 	.globl _SP
                                    212 	.globl _P0
                                    213 ;--------------------------------------------------------
                                    214 ; special function registers
                                    215 ;--------------------------------------------------------
                                    216 	.area RSEG    (ABS,DATA)
      000000                        217 	.org 0x0000
                           000080   218 _P0	=	0x0080
                           000081   219 _SP	=	0x0081
                           000082   220 _DPL	=	0x0082
                           000083   221 _DPH	=	0x0083
                           000087   222 _PCON	=	0x0087
                           000088   223 _TCON	=	0x0088
                           000089   224 _TMOD	=	0x0089
                           00008A   225 _TL0	=	0x008a
                           00008B   226 _TL1	=	0x008b
                           00008C   227 _TH0	=	0x008c
                           00008D   228 _TH1	=	0x008d
                           000090   229 _P1	=	0x0090
                           000098   230 _SCON	=	0x0098
                           000099   231 _SBUF	=	0x0099
                           0000A0   232 _P2	=	0x00a0
                           0000A8   233 _IE	=	0x00a8
                           0000B0   234 _P3	=	0x00b0
                           0000B8   235 _IP	=	0x00b8
                           0000D0   236 _PSW	=	0x00d0
                           0000E0   237 _ACC	=	0x00e0
                           0000F0   238 _B	=	0x00f0
                           0000C8   239 _T2CON	=	0x00c8
                           0000CA   240 _RCAP2L	=	0x00ca
                           0000CB   241 _RCAP2H	=	0x00cb
                           0000CC   242 _TL2	=	0x00cc
                           0000CD   243 _TH2	=	0x00cd
                           00008E   244 _AUXR	=	0x008e
                           0000A2   245 _AUXR1	=	0x00a2
                           000097   246 _CKRL	=	0x0097
                           00008F   247 _CKCON0	=	0x008f
                           0000AF   248 _CKCON1	=	0x00af
                           0000FA   249 _CCAP0H	=	0x00fa
                           0000FB   250 _CCAP1H	=	0x00fb
                           0000FC   251 _CCAP2H	=	0x00fc
                           0000FD   252 _CCAP3H	=	0x00fd
                           0000FE   253 _CCAP4H	=	0x00fe
                           0000EA   254 _CCAP0L	=	0x00ea
                           0000EB   255 _CCAP1L	=	0x00eb
                           0000EC   256 _CCAP2L	=	0x00ec
                           0000ED   257 _CCAP3L	=	0x00ed
                           0000EE   258 _CCAP4L	=	0x00ee
                           0000DA   259 _CCAPM0	=	0x00da
                           0000DB   260 _CCAPM1	=	0x00db
                           0000DC   261 _CCAPM2	=	0x00dc
                           0000DD   262 _CCAPM3	=	0x00dd
                           0000DE   263 _CCAPM4	=	0x00de
                           0000D8   264 _CCON	=	0x00d8
                           0000F9   265 _CH	=	0x00f9
                           0000E9   266 _CL	=	0x00e9
                           0000D9   267 _CMOD	=	0x00d9
                           0000A8   268 _IEN0	=	0x00a8
                           0000B1   269 _IEN1	=	0x00b1
                           0000B8   270 _IPL0	=	0x00b8
                           0000B7   271 _IPH0	=	0x00b7
                           0000B2   272 _IPL1	=	0x00b2
                           0000B3   273 _IPH1	=	0x00b3
                           0000C0   274 _P4	=	0x00c0
                           0000E8   275 _P5	=	0x00e8
                           0000A6   276 _WDTRST	=	0x00a6
                           0000A7   277 _WDTPRG	=	0x00a7
                           0000A9   278 _SADDR	=	0x00a9
                           0000B9   279 _SADEN	=	0x00b9
                           0000C3   280 _SPCON	=	0x00c3
                           0000C4   281 _SPSTA	=	0x00c4
                           0000C5   282 _SPDAT	=	0x00c5
                           0000C9   283 _T2MOD	=	0x00c9
                           00009B   284 _BDRCON	=	0x009b
                           00009A   285 _BRL	=	0x009a
                           00009C   286 _KBLS	=	0x009c
                           00009D   287 _KBE	=	0x009d
                           00009E   288 _KBF	=	0x009e
                           0000D2   289 _EECON	=	0x00d2
                                    290 ;--------------------------------------------------------
                                    291 ; special function bits
                                    292 ;--------------------------------------------------------
                                    293 	.area RSEG    (ABS,DATA)
      000000                        294 	.org 0x0000
                           000080   295 _P0_0	=	0x0080
                           000081   296 _P0_1	=	0x0081
                           000082   297 _P0_2	=	0x0082
                           000083   298 _P0_3	=	0x0083
                           000084   299 _P0_4	=	0x0084
                           000085   300 _P0_5	=	0x0085
                           000086   301 _P0_6	=	0x0086
                           000087   302 _P0_7	=	0x0087
                           000088   303 _IT0	=	0x0088
                           000089   304 _IE0	=	0x0089
                           00008A   305 _IT1	=	0x008a
                           00008B   306 _IE1	=	0x008b
                           00008C   307 _TR0	=	0x008c
                           00008D   308 _TF0	=	0x008d
                           00008E   309 _TR1	=	0x008e
                           00008F   310 _TF1	=	0x008f
                           000090   311 _P1_0	=	0x0090
                           000091   312 _P1_1	=	0x0091
                           000092   313 _P1_2	=	0x0092
                           000093   314 _P1_3	=	0x0093
                           000094   315 _P1_4	=	0x0094
                           000095   316 _P1_5	=	0x0095
                           000096   317 _P1_6	=	0x0096
                           000097   318 _P1_7	=	0x0097
                           000098   319 _RI	=	0x0098
                           000099   320 _TI	=	0x0099
                           00009A   321 _RB8	=	0x009a
                           00009B   322 _TB8	=	0x009b
                           00009C   323 _REN	=	0x009c
                           00009D   324 _SM2	=	0x009d
                           00009E   325 _SM1	=	0x009e
                           00009F   326 _SM0	=	0x009f
                           0000A0   327 _P2_0	=	0x00a0
                           0000A1   328 _P2_1	=	0x00a1
                           0000A2   329 _P2_2	=	0x00a2
                           0000A3   330 _P2_3	=	0x00a3
                           0000A4   331 _P2_4	=	0x00a4
                           0000A5   332 _P2_5	=	0x00a5
                           0000A6   333 _P2_6	=	0x00a6
                           0000A7   334 _P2_7	=	0x00a7
                           0000A8   335 _EX0	=	0x00a8
                           0000A9   336 _ET0	=	0x00a9
                           0000AA   337 _EX1	=	0x00aa
                           0000AB   338 _ET1	=	0x00ab
                           0000AC   339 _ES	=	0x00ac
                           0000AF   340 _EA	=	0x00af
                           0000B0   341 _P3_0	=	0x00b0
                           0000B1   342 _P3_1	=	0x00b1
                           0000B2   343 _P3_2	=	0x00b2
                           0000B3   344 _P3_3	=	0x00b3
                           0000B4   345 _P3_4	=	0x00b4
                           0000B5   346 _P3_5	=	0x00b5
                           0000B6   347 _P3_6	=	0x00b6
                           0000B7   348 _P3_7	=	0x00b7
                           0000B0   349 _RXD	=	0x00b0
                           0000B1   350 _TXD	=	0x00b1
                           0000B2   351 _INT0	=	0x00b2
                           0000B3   352 _INT1	=	0x00b3
                           0000B4   353 _T0	=	0x00b4
                           0000B5   354 _T1	=	0x00b5
                           0000B6   355 _WR	=	0x00b6
                           0000B7   356 _RD	=	0x00b7
                           0000B8   357 _PX0	=	0x00b8
                           0000B9   358 _PT0	=	0x00b9
                           0000BA   359 _PX1	=	0x00ba
                           0000BB   360 _PT1	=	0x00bb
                           0000BC   361 _PS	=	0x00bc
                           0000D0   362 _P	=	0x00d0
                           0000D1   363 _F1	=	0x00d1
                           0000D2   364 _OV	=	0x00d2
                           0000D3   365 _RS0	=	0x00d3
                           0000D4   366 _RS1	=	0x00d4
                           0000D5   367 _F0	=	0x00d5
                           0000D6   368 _AC	=	0x00d6
                           0000D7   369 _CY	=	0x00d7
                           0000AD   370 _ET2	=	0x00ad
                           0000BD   371 _PT2	=	0x00bd
                           0000C8   372 _T2CON_0	=	0x00c8
                           0000C9   373 _T2CON_1	=	0x00c9
                           0000CA   374 _T2CON_2	=	0x00ca
                           0000CB   375 _T2CON_3	=	0x00cb
                           0000CC   376 _T2CON_4	=	0x00cc
                           0000CD   377 _T2CON_5	=	0x00cd
                           0000CE   378 _T2CON_6	=	0x00ce
                           0000CF   379 _T2CON_7	=	0x00cf
                           0000C8   380 _CP_RL2	=	0x00c8
                           0000C9   381 _C_T2	=	0x00c9
                           0000CA   382 _TR2	=	0x00ca
                           0000CB   383 _EXEN2	=	0x00cb
                           0000CC   384 _TCLK	=	0x00cc
                           0000CD   385 _RCLK	=	0x00cd
                           0000CE   386 _EXF2	=	0x00ce
                           0000CF   387 _TF2	=	0x00cf
                           0000DF   388 _CF	=	0x00df
                           0000DE   389 _CR	=	0x00de
                           0000DC   390 _CCF4	=	0x00dc
                           0000DB   391 _CCF3	=	0x00db
                           0000DA   392 _CCF2	=	0x00da
                           0000D9   393 _CCF1	=	0x00d9
                           0000D8   394 _CCF0	=	0x00d8
                           0000AE   395 _EC	=	0x00ae
                           0000BE   396 _PPCL	=	0x00be
                           0000BD   397 _PT2L	=	0x00bd
                           0000BC   398 _PSL	=	0x00bc
                           0000BB   399 _PT1L	=	0x00bb
                           0000BA   400 _PX1L	=	0x00ba
                           0000B9   401 _PT0L	=	0x00b9
                           0000B8   402 _PX0L	=	0x00b8
                           0000C0   403 _P4_0	=	0x00c0
                           0000C1   404 _P4_1	=	0x00c1
                           0000C2   405 _P4_2	=	0x00c2
                           0000C3   406 _P4_3	=	0x00c3
                           0000C4   407 _P4_4	=	0x00c4
                           0000C5   408 _P4_5	=	0x00c5
                           0000C6   409 _P4_6	=	0x00c6
                           0000C7   410 _P4_7	=	0x00c7
                           0000E8   411 _P5_0	=	0x00e8
                           0000E9   412 _P5_1	=	0x00e9
                           0000EA   413 _P5_2	=	0x00ea
                           0000EB   414 _P5_3	=	0x00eb
                           0000EC   415 _P5_4	=	0x00ec
                           0000ED   416 _P5_5	=	0x00ed
                           0000EE   417 _P5_6	=	0x00ee
                           0000EF   418 _P5_7	=	0x00ef
                                    419 ;--------------------------------------------------------
                                    420 ; overlayable register banks
                                    421 ;--------------------------------------------------------
                                    422 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        423 	.ds 8
                                    424 ;--------------------------------------------------------
                                    425 ; internal ram data
                                    426 ;--------------------------------------------------------
                                    427 	.area DSEG    (DATA)
                                    428 ;--------------------------------------------------------
                                    429 ; overlayable items in internal ram
                                    430 ;--------------------------------------------------------
                                    431 	.area	OSEG    (OVR,DATA)
                                    432 ;--------------------------------------------------------
                                    433 ; Stack segment in internal ram
                                    434 ;--------------------------------------------------------
                                    435 	.area SSEG
      00000A                        436 __start__stack:
      00000A                        437 	.ds	1
                                    438 
                                    439 ;--------------------------------------------------------
                                    440 ; indirectly addressable internal ram data
                                    441 ;--------------------------------------------------------
                                    442 	.area ISEG    (DATA)
                                    443 ;--------------------------------------------------------
                                    444 ; absolute internal ram data
                                    445 ;--------------------------------------------------------
                                    446 	.area IABS    (ABS,DATA)
                                    447 	.area IABS    (ABS,DATA)
                                    448 ;--------------------------------------------------------
                                    449 ; bit data
                                    450 ;--------------------------------------------------------
                                    451 	.area BSEG    (BIT)
                                    452 ;--------------------------------------------------------
                                    453 ; paged external ram data
                                    454 ;--------------------------------------------------------
                                    455 	.area PSEG    (PAG,XDATA)
                                    456 ;--------------------------------------------------------
                                    457 ; uninitialized external ram data
                                    458 ;--------------------------------------------------------
                                    459 	.area XSEG    (XDATA)
                                    460 ;--------------------------------------------------------
                                    461 ; absolute external ram data
                                    462 ;--------------------------------------------------------
                                    463 	.area XABS    (ABS,XDATA)
                                    464 ;--------------------------------------------------------
                                    465 ; initialized external ram data
                                    466 ;--------------------------------------------------------
                                    467 	.area XISEG   (XDATA)
                                    468 	.area HOME    (CODE)
                                    469 	.area GSINIT0 (CODE)
                                    470 	.area GSINIT1 (CODE)
                                    471 	.area GSINIT2 (CODE)
                                    472 	.area GSINIT3 (CODE)
                                    473 	.area GSINIT4 (CODE)
                                    474 	.area GSINIT5 (CODE)
                                    475 	.area GSINIT  (CODE)
                                    476 	.area GSFINAL (CODE)
                                    477 	.area CSEG    (CODE)
                                    478 ;--------------------------------------------------------
                                    479 ; interrupt vector
                                    480 ;--------------------------------------------------------
                                    481 	.area HOME    (CODE)
      000000                        482 __interrupt_vect:
      000000 02 00 4C         [24]  483 	ljmp	__sdcc_gsinit_startup
                                    484 ; restartable atomic support routines
      000003                        485 	.ds	5
      000008                        486 sdcc_atomic_exchange_rollback_start::
      000008 00               [12]  487 	nop
      000009 00               [12]  488 	nop
      00000A                        489 sdcc_atomic_exchange_pdata_impl:
      00000A E2               [24]  490 	movx	a, @r0
      00000B FB               [12]  491 	mov	r3, a
      00000C EA               [12]  492 	mov	a, r2
      00000D F2               [24]  493 	movx	@r0, a
      00000E 80 2C            [24]  494 	sjmp	sdcc_atomic_exchange_exit
      000010 00               [12]  495 	nop
      000011 00               [12]  496 	nop
      000012                        497 sdcc_atomic_exchange_xdata_impl:
      000012 E0               [24]  498 	movx	a, @dptr
      000013 FB               [12]  499 	mov	r3, a
      000014 EA               [12]  500 	mov	a, r2
      000015 F0               [24]  501 	movx	@dptr, a
      000016 80 24            [24]  502 	sjmp	sdcc_atomic_exchange_exit
      000018                        503 sdcc_atomic_compare_exchange_idata_impl:
      000018 E6               [12]  504 	mov	a, @r0
      000019 B5 02 02         [24]  505 	cjne	a, ar2, .+#5
      00001C EB               [12]  506 	mov	a, r3
      00001D F6               [12]  507 	mov	@r0, a
      00001E 22               [24]  508 	ret
      00001F 00               [12]  509 	nop
      000020                        510 sdcc_atomic_compare_exchange_pdata_impl:
      000020 E2               [24]  511 	movx	a, @r0
      000021 B5 02 02         [24]  512 	cjne	a, ar2, .+#5
      000024 EB               [12]  513 	mov	a, r3
      000025 F2               [24]  514 	movx	@r0, a
      000026 22               [24]  515 	ret
      000027 00               [12]  516 	nop
      000028                        517 sdcc_atomic_compare_exchange_xdata_impl:
      000028 E0               [24]  518 	movx	a, @dptr
      000029 B5 02 02         [24]  519 	cjne	a, ar2, .+#5
      00002C EB               [12]  520 	mov	a, r3
      00002D F0               [24]  521 	movx	@dptr, a
      00002E 22               [24]  522 	ret
      00002F                        523 sdcc_atomic_exchange_rollback_end::
                                    524 
      00002F                        525 sdcc_atomic_exchange_gptr_impl::
      00002F 30 F6 E0         [24]  526 	jnb	b.6, sdcc_atomic_exchange_xdata_impl
      000032 A8 82            [24]  527 	mov	r0, dpl
      000034 20 F5 D3         [24]  528 	jb	b.5, sdcc_atomic_exchange_pdata_impl
      000037                        529 sdcc_atomic_exchange_idata_impl:
      000037 EA               [12]  530 	mov	a, r2
      000038 C6               [12]  531 	xch	a, @r0
      000039 F5 82            [12]  532 	mov	dpl, a
      00003B 22               [24]  533 	ret
      00003C                        534 sdcc_atomic_exchange_exit:
      00003C 8B 82            [24]  535 	mov	dpl, r3
      00003E 22               [24]  536 	ret
      00003F                        537 sdcc_atomic_compare_exchange_gptr_impl::
      00003F 30 F6 E6         [24]  538 	jnb	b.6, sdcc_atomic_compare_exchange_xdata_impl
      000042 A8 82            [24]  539 	mov	r0, dpl
      000044 20 F5 D9         [24]  540 	jb	b.5, sdcc_atomic_compare_exchange_pdata_impl
      000047 80 CF            [24]  541 	sjmp	sdcc_atomic_compare_exchange_idata_impl
                                    542 ;--------------------------------------------------------
                                    543 ; global & static initialisations
                                    544 ;--------------------------------------------------------
                                    545 	.area HOME    (CODE)
                                    546 	.area GSINIT  (CODE)
                                    547 	.area GSFINAL (CODE)
                                    548 	.area GSINIT  (CODE)
                                    549 	.globl __sdcc_gsinit_startup
                                    550 	.globl __sdcc_program_startup
                                    551 	.globl __start__stack
                                    552 	.globl __mcs51_genXINIT
                                    553 	.globl __mcs51_genXRAMCLEAR
                                    554 	.globl __mcs51_genRAMCLEAR
                                    555 	.area GSFINAL (CODE)
      0000A5 02 00 49         [24]  556 	ljmp	__sdcc_program_startup
                                    557 ;--------------------------------------------------------
                                    558 ; Home
                                    559 ;--------------------------------------------------------
                                    560 	.area HOME    (CODE)
                                    561 	.area HOME    (CODE)
      000049                        562 __sdcc_program_startup:
      000049 02 01 BD         [24]  563 	ljmp	_main
                                    564 ;	return from main will return to caller
                                    565 ;--------------------------------------------------------
                                    566 ; code
                                    567 ;--------------------------------------------------------
                                    568 	.area CSEG    (CODE)
                                    569 ;------------------------------------------------------------
                                    570 ;Allocation info for local variables in function 'P2_SET'
                                    571 ;------------------------------------------------------------
                                    572 ;LED                       Allocated to registers r6 r7 
                                    573 ;------------------------------------------------------------
                                    574 ;	test_sdcc.c:8: void P2_SET(unsigned int LED){
                                    575 ;	-----------------------------------------
                                    576 ;	 function P2_SET
                                    577 ;	-----------------------------------------
      0000A8                        578 _P2_SET:
                           000007   579 	ar7 = 0x07
                           000006   580 	ar6 = 0x06
                           000005   581 	ar5 = 0x05
                           000004   582 	ar4 = 0x04
                           000003   583 	ar3 = 0x03
                           000002   584 	ar2 = 0x02
                           000001   585 	ar1 = 0x01
                           000000   586 	ar0 = 0x00
      0000A8 AE 82            [24]  587 	mov	r6, dpl
                                    588 ;	test_sdcc.c:9: P2 = LED;
      0000AA 8E A0            [24]  589 	mov	_P2,r6
                                    590 ;	test_sdcc.c:10: }
      0000AC 22               [24]  591 	ret
                                    592 ;------------------------------------------------------------
                                    593 ;Allocation info for local variables in function 'delay_ms'
                                    594 ;------------------------------------------------------------
                                    595 ;t                         Allocated to registers 
                                    596 ;i                         Allocated to registers r4 r5 
                                    597 ;------------------------------------------------------------
                                    598 ;	test_sdcc.c:12: void delay_ms(unsigned int t){
                                    599 ;	-----------------------------------------
                                    600 ;	 function delay_ms
                                    601 ;	-----------------------------------------
      0000AD                        602 _delay_ms:
      0000AD 85 82 08         [24]  603 	mov	__mulint_PARM_2,dpl
      0000B0 85 83 09         [24]  604 	mov	(__mulint_PARM_2 + 1),dph
                                    605 ;	test_sdcc.c:14: for(i = 0; i < 12*t; i++);
      0000B3 90 00 0C         [24]  606 	mov	dptr,#0x000c
      0000B6 12 01 C0         [24]  607 	lcall	__mulint
      0000B9 AE 82            [24]  608 	mov	r6, dpl
      0000BB AF 83            [24]  609 	mov	r7, dph
      0000BD 7C 00            [12]  610 	mov	r4,#0x00
      0000BF 7D 00            [12]  611 	mov	r5,#0x00
      0000C1                        612 00103$:
      0000C1 C3               [12]  613 	clr	c
      0000C2 EC               [12]  614 	mov	a,r4
      0000C3 9E               [12]  615 	subb	a,r6
      0000C4 ED               [12]  616 	mov	a,r5
      0000C5 9F               [12]  617 	subb	a,r7
      0000C6 50 07            [24]  618 	jnc	00105$
      0000C8 0C               [12]  619 	inc	r4
      0000C9 BC 00 F5         [24]  620 	cjne	r4,#0x00,00103$
      0000CC 0D               [12]  621 	inc	r5
      0000CD 80 F2            [24]  622 	sjmp	00103$
      0000CF                        623 00105$:
                                    624 ;	test_sdcc.c:15: }
      0000CF 22               [24]  625 	ret
                                    626 ;------------------------------------------------------------
                                    627 ;Allocation info for local variables in function 'SANG_DAN_TAT_DAN'
                                    628 ;------------------------------------------------------------
                                    629 ;LED                       Allocated to registers r6 r7 
                                    630 ;------------------------------------------------------------
                                    631 ;	test_sdcc.c:17: void SANG_DAN_TAT_DAN(){
                                    632 ;	-----------------------------------------
                                    633 ;	 function SANG_DAN_TAT_DAN
                                    634 ;	-----------------------------------------
      0000D0                        635 _SANG_DAN_TAT_DAN:
                                    636 ;	test_sdcc.c:18: unsigned int  LED = 0x0;
      0000D0 7E 00            [12]  637 	mov	r6,#0x00
      0000D2 7F 00            [12]  638 	mov	r7,#0x00
                                    639 ;	test_sdcc.c:19: while (1){
      0000D4                        640 00105$:
                                    641 ;	test_sdcc.c:20: if ( LED & 0x80) 
      0000D4 EE               [12]  642 	mov	a,r6
      0000D5 30 E7 08         [24]  643 	jnb	acc.7,00102$
                                    644 ;	test_sdcc.c:21: LED = (LED<<1);
      0000D8 EE               [12]  645 	mov	a,r6
      0000D9 2E               [12]  646 	add	a,r6
      0000DA FE               [12]  647 	mov	r6,a
      0000DB EF               [12]  648 	mov	a,r7
      0000DC 33               [12]  649 	rlc	a
      0000DD FF               [12]  650 	mov	r7,a
      0000DE 80 0C            [24]  651 	sjmp	00103$
      0000E0                        652 00102$:
                                    653 ;	test_sdcc.c:23: LED = (LED<<1) | 1U;
      0000E0 EE               [12]  654 	mov	a,r6
      0000E1 2E               [12]  655 	add	a,r6
      0000E2 FC               [12]  656 	mov	r4,a
      0000E3 EF               [12]  657 	mov	a,r7
      0000E4 33               [12]  658 	rlc	a
      0000E5 FD               [12]  659 	mov	r5,a
      0000E6 74 01            [12]  660 	mov	a,#0x01
      0000E8 4C               [12]  661 	orl	a,r4
      0000E9 FE               [12]  662 	mov	r6,a
      0000EA 8D 07            [24]  663 	mov	ar7,r5
      0000EC                        664 00103$:
                                    665 ;	test_sdcc.c:24: P2_SET(LED);
      0000EC 8E 82            [24]  666 	mov	dpl, r6
      0000EE 8F 83            [24]  667 	mov	dph, r7
      0000F0 C0 07            [24]  668 	push	ar7
      0000F2 C0 06            [24]  669 	push	ar6
      0000F4 12 00 A8         [24]  670 	lcall	_P2_SET
                                    671 ;	test_sdcc.c:25: delay_ms(100);
      0000F7 90 00 64         [24]  672 	mov	dptr,#0x0064
      0000FA 12 00 AD         [24]  673 	lcall	_delay_ms
      0000FD D0 06            [24]  674 	pop	ar6
      0000FF D0 07            [24]  675 	pop	ar7
                                    676 ;	test_sdcc.c:27: }
      000101 80 D1            [24]  677 	sjmp	00105$
                                    678 ;------------------------------------------------------------
                                    679 ;Allocation info for local variables in function 'SANG_DICH'
                                    680 ;------------------------------------------------------------
                                    681 ;LED                       Allocated to registers r6 r7 
                                    682 ;------------------------------------------------------------
                                    683 ;	test_sdcc.c:29: void SANG_DICH(){
                                    684 ;	-----------------------------------------
                                    685 ;	 function SANG_DICH
                                    686 ;	-----------------------------------------
      000103                        687 _SANG_DICH:
                                    688 ;	test_sdcc.c:30: unsigned int LED = 0x1;
      000103 7E 01            [12]  689 	mov	r6,#0x01
      000105 7F 00            [12]  690 	mov	r7,#0x00
                                    691 ;	test_sdcc.c:31: while (1){
      000107                        692 00105$:
                                    693 ;	test_sdcc.c:32: if (LED == 0x0){
      000107 EE               [12]  694 	mov	a,r6
      000108 4F               [12]  695 	orl	a,r7
                                    696 ;	test_sdcc.c:33: LED = 0x1;
      000109 70 05            [24]  697 	jnz	00102$
      00010B 7E 01            [12]  698 	mov	r6,#0x01
      00010D FF               [12]  699 	mov	r7,a
      00010E 80 06            [24]  700 	sjmp	00103$
      000110                        701 00102$:
                                    702 ;	test_sdcc.c:35: LED = LED << 0x1;
      000110 EE               [12]  703 	mov	a,r6
      000111 2E               [12]  704 	add	a,r6
      000112 FE               [12]  705 	mov	r6,a
      000113 EF               [12]  706 	mov	a,r7
      000114 33               [12]  707 	rlc	a
      000115 FF               [12]  708 	mov	r7,a
      000116                        709 00103$:
                                    710 ;	test_sdcc.c:37: P2_SET(LED);
      000116 8E 82            [24]  711 	mov	dpl, r6
      000118 8F 83            [24]  712 	mov	dph, r7
      00011A C0 07            [24]  713 	push	ar7
      00011C C0 06            [24]  714 	push	ar6
      00011E 12 00 A8         [24]  715 	lcall	_P2_SET
                                    716 ;	test_sdcc.c:38: delay_ms(100);
      000121 90 00 64         [24]  717 	mov	dptr,#0x0064
      000124 12 00 AD         [24]  718 	lcall	_delay_ms
      000127 D0 06            [24]  719 	pop	ar6
      000129 D0 07            [24]  720 	pop	ar7
                                    721 ;	test_sdcc.c:41: }
      00012B 80 DA            [24]  722 	sjmp	00105$
                                    723 ;------------------------------------------------------------
                                    724 ;Allocation info for local variables in function 'SANG_DOI_XUNG'
                                    725 ;------------------------------------------------------------
                                    726 ;SH                        Allocated to registers r7 
                                    727 ;------------------------------------------------------------
                                    728 ;	test_sdcc.c:43: void SANG_DOI_XUNG(){
                                    729 ;	-----------------------------------------
                                    730 ;	 function SANG_DOI_XUNG
                                    731 ;	-----------------------------------------
      00012D                        732 _SANG_DOI_XUNG:
                                    733 ;	test_sdcc.c:44: unsigned int SH = 0;
      00012D 7F 00            [12]  734 	mov	r7,#0x00
                                    735 ;	test_sdcc.c:45: while (1){
      00012F                        736 00105$:
                                    737 ;	test_sdcc.c:46: if (SH & 0x4)
      00012F EF               [12]  738 	mov	a,r7
      000130 30 E2 3C         [24]  739 	jnb	acc.2,00102$
                                    740 ;	test_sdcc.c:47: P2_SET( (0x80>>(SH)) + (0x01<<(SH)));
      000133 8F F0            [24]  741 	mov	b,r7
      000135 05 F0            [12]  742 	inc	b
      000137 7D 80            [12]  743 	mov	r5,#0x80
      000139 E4               [12]  744 	clr	a
      00013A FE               [12]  745 	mov	r6,a
      00013B 33               [12]  746 	rlc	a
      00013C 92 D2            [24]  747 	mov	ov,c
      00013E 80 08            [24]  748 	sjmp	00123$
      000140                        749 00122$:
      000140 A2 D2            [12]  750 	mov	c,ov
      000142 EE               [12]  751 	mov	a,r6
      000143 13               [12]  752 	rrc	a
      000144 FE               [12]  753 	mov	r6,a
      000145 ED               [12]  754 	mov	a,r5
      000146 13               [12]  755 	rrc	a
      000147 FD               [12]  756 	mov	r5,a
      000148                        757 00123$:
      000148 D5 F0 F5         [24]  758 	djnz	b,00122$
      00014B 8F F0            [24]  759 	mov	b,r7
      00014D 05 F0            [12]  760 	inc	b
      00014F 7B 01            [12]  761 	mov	r3,#0x01
      000151 7C 00            [12]  762 	mov	r4,#0x00
      000153 80 06            [24]  763 	sjmp	00125$
      000155                        764 00124$:
      000155 EB               [12]  765 	mov	a,r3
      000156 2B               [12]  766 	add	a,r3
      000157 FB               [12]  767 	mov	r3,a
      000158 EC               [12]  768 	mov	a,r4
      000159 33               [12]  769 	rlc	a
      00015A FC               [12]  770 	mov	r4,a
      00015B                        771 00125$:
      00015B D5 F0 F7         [24]  772 	djnz	b,00124$
      00015E EB               [12]  773 	mov	a,r3
      00015F 2D               [12]  774 	add	a, r5
      000160 F5 82            [12]  775 	mov	dpl,a
      000162 EC               [12]  776 	mov	a,r4
      000163 3E               [12]  777 	addc	a, r6
      000164 F5 83            [12]  778 	mov	dph,a
      000166 C0 07            [24]  779 	push	ar7
      000168 12 00 A8         [24]  780 	lcall	_P2_SET
      00016B D0 07            [24]  781 	pop	ar7
      00016D 80 3A            [24]  782 	sjmp	00103$
      00016F                        783 00102$:
                                    784 ;	test_sdcc.c:49: P2_SET( (0x01<<(SH)) + (0x80>>(SH)));
      00016F 8F F0            [24]  785 	mov	b,r7
      000171 05 F0            [12]  786 	inc	b
      000173 7D 01            [12]  787 	mov	r5,#0x01
      000175 7E 00            [12]  788 	mov	r6,#0x00
      000177 80 06            [24]  789 	sjmp	00127$
      000179                        790 00126$:
      000179 ED               [12]  791 	mov	a,r5
      00017A 2D               [12]  792 	add	a,r5
      00017B FD               [12]  793 	mov	r5,a
      00017C EE               [12]  794 	mov	a,r6
      00017D 33               [12]  795 	rlc	a
      00017E FE               [12]  796 	mov	r6,a
      00017F                        797 00127$:
      00017F D5 F0 F7         [24]  798 	djnz	b,00126$
      000182 8F F0            [24]  799 	mov	b,r7
      000184 05 F0            [12]  800 	inc	b
      000186 7B 80            [12]  801 	mov	r3,#0x80
      000188 E4               [12]  802 	clr	a
      000189 FC               [12]  803 	mov	r4,a
      00018A 33               [12]  804 	rlc	a
      00018B 92 D2            [24]  805 	mov	ov,c
      00018D 80 08            [24]  806 	sjmp	00129$
      00018F                        807 00128$:
      00018F A2 D2            [12]  808 	mov	c,ov
      000191 EC               [12]  809 	mov	a,r4
      000192 13               [12]  810 	rrc	a
      000193 FC               [12]  811 	mov	r4,a
      000194 EB               [12]  812 	mov	a,r3
      000195 13               [12]  813 	rrc	a
      000196 FB               [12]  814 	mov	r3,a
      000197                        815 00129$:
      000197 D5 F0 F5         [24]  816 	djnz	b,00128$
      00019A EB               [12]  817 	mov	a,r3
      00019B 2D               [12]  818 	add	a, r5
      00019C F5 82            [12]  819 	mov	dpl,a
      00019E EC               [12]  820 	mov	a,r4
      00019F 3E               [12]  821 	addc	a, r6
      0001A0 F5 83            [12]  822 	mov	dph,a
      0001A2 C0 07            [24]  823 	push	ar7
      0001A4 12 00 A8         [24]  824 	lcall	_P2_SET
      0001A7 D0 07            [24]  825 	pop	ar7
      0001A9                        826 00103$:
                                    827 ;	test_sdcc.c:50: SH = (SH+0x1) % 8;
      0001A9 8F 06            [24]  828 	mov	ar6,r7
      0001AB EE               [12]  829 	mov	a,r6
      0001AC 04               [12]  830 	inc	a
      0001AD 54 07            [12]  831 	anl	a,#0x07
      0001AF FF               [12]  832 	mov	r7,a
                                    833 ;	test_sdcc.c:51: delay_ms(400);
      0001B0 90 01 90         [24]  834 	mov	dptr,#0x0190
      0001B3 C0 07            [24]  835 	push	ar7
      0001B5 12 00 AD         [24]  836 	lcall	_delay_ms
      0001B8 D0 07            [24]  837 	pop	ar7
                                    838 ;	test_sdcc.c:54: }
      0001BA 02 01 2F         [24]  839 	ljmp	00105$
                                    840 ;------------------------------------------------------------
                                    841 ;Allocation info for local variables in function 'main'
                                    842 ;------------------------------------------------------------
                                    843 ;	test_sdcc.c:58: void main(){
                                    844 ;	-----------------------------------------
                                    845 ;	 function main
                                    846 ;	-----------------------------------------
      0001BD                        847 _main:
                                    848 ;	test_sdcc.c:59: SANG_DOI_XUNG();
                                    849 ;	test_sdcc.c:60: }
      0001BD 02 01 2D         [24]  850 	ljmp	_SANG_DOI_XUNG
                                    851 	.area CSEG    (CODE)
                                    852 	.area CONST   (CODE)
                                    853 	.area XINIT   (CODE)
                                    854 	.area CABS    (ABS,CODE)
