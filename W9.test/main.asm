;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler
; Version 4.4.4 #15036 (Linux)
;--------------------------------------------------------
	.module main
	
	.optsdcc -mmcs51 --model-small
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _DEV_CTL_PARM_2
	.globl _led7seg_disp_PARM_2
	.globl _DIGIT_CODE
	.globl _main
	.globl _main_intial
	.globl _sys_time_disp
	.globl _change_mode
	.globl _SHOW_MODE
	.globl _DEV_CTL
	.globl _SET_ON_OFF
	.globl _SET_TIMER
	.globl _YES_NO
	.globl _CODE2NUM
	.globl _External0_Interrupt
	.globl _Timer0_OverFlow_Interrupt
	.globl _IR_Reading_Initial
	.globl _read_extracted_frame
	.globl _new_dataframe
	.globl _Get_BTN_MATRIX_2
	.globl _Get_BTN_MATRIX
	.globl _Col_Read
	.globl _Row_Write
	.globl _Disp8leds7seg
	.globl _led7seg_disp
	.globl _ds1302_initial
	.globl _ds1302_write_time
	.globl _ds1302_read_time
	.globl _time_equal
	.globl _ThreeWiresProtocol_Initial
	.globl _single_byte_read
	.globl _single_byte_write
	.globl _GLOBAL_INT
	.globl _TIMER0_CTL
	.globl _eINT1_CTL
	.globl _eINT0_CTL
	.globl _delay_ms
	.globl _DEV2
	.globl _DEV1
	.globl _DEV0
	.globl _FrameExtracted_LED
	.globl _COL3
	.globl _COL2
	.globl _COL1
	.globl _COL0
	.globl _ROW3
	.globl _ROW2
	.globl _ROW1
	.globl _ROW0
	.globl _GND2
	.globl _GND1
	.globl _GND0
	.globl _IO
	.globl _SCLK
	.globl _CE
	.globl _CY
	.globl _AC
	.globl _F0
	.globl _RS1
	.globl _RS0
	.globl _OV
	.globl _FL
	.globl _P
	.globl _TF2
	.globl _EXF2
	.globl _RCLK
	.globl _TCLK
	.globl _EXEN2
	.globl _TR2
	.globl _C_T2
	.globl _CP_RL2
	.globl _T2CON_7
	.globl _T2CON_6
	.globl _T2CON_5
	.globl _T2CON_4
	.globl _T2CON_3
	.globl _T2CON_2
	.globl _T2CON_1
	.globl _T2CON_0
	.globl _PT2
	.globl _PS
	.globl _PT1
	.globl _PX1
	.globl _PT0
	.globl _PX0
	.globl _RD
	.globl _WR
	.globl _T1
	.globl _T0
	.globl _INT1
	.globl _INT0
	.globl _TXD
	.globl _RXD
	.globl _P3_7
	.globl _P3_6
	.globl _P3_5
	.globl _P3_4
	.globl _P3_3
	.globl _P3_2
	.globl _P3_1
	.globl _P3_0
	.globl _EA
	.globl _ET2
	.globl _ES
	.globl _ET1
	.globl _EX1
	.globl _ET0
	.globl _EX0
	.globl _P2_7
	.globl _P2_6
	.globl _P2_5
	.globl _P2_4
	.globl _P2_3
	.globl _P2_2
	.globl _P2_1
	.globl _P2_0
	.globl _SM0
	.globl _SM1
	.globl _SM2
	.globl _REN
	.globl _TB8
	.globl _RB8
	.globl _TI
	.globl _RI
	.globl _T2EX
	.globl _T2
	.globl _P1_7
	.globl _P1_6
	.globl _P1_5
	.globl _P1_4
	.globl _P1_3
	.globl _P1_2
	.globl _P1_1
	.globl _P1_0
	.globl _TF1
	.globl _TR1
	.globl _TF0
	.globl _TR0
	.globl _IE1
	.globl _IT1
	.globl _IE0
	.globl _IT0
	.globl _P0_7
	.globl _P0_6
	.globl _P0_5
	.globl _P0_4
	.globl _P0_3
	.globl _P0_2
	.globl _P0_1
	.globl _P0_0
	.globl _B
	.globl _A
	.globl _ACC
	.globl _PSW
	.globl _TH2
	.globl _TL2
	.globl _RCAP2H
	.globl _RCAP2L
	.globl _T2MOD
	.globl _T2CON
	.globl _IP
	.globl _P3
	.globl _IE
	.globl _P2
	.globl _SBUF
	.globl _SCON
	.globl _P1
	.globl _TH1
	.globl _TH0
	.globl _TL1
	.globl _TL0
	.globl _TMOD
	.globl _TCON
	.globl _PCON
	.globl _DPH
	.globl _DPL
	.globl _SP
	.globl _P0
	.globl _SET_ON_OFF_PARM_2
	.globl _time_off
	.globl _time_on
	.globl _sys_time
	.globl _DEV_ENABLE
	.globl _MANUAL_MODE
	.globl _CURRENT_MODE
	.globl _negedge_count
	.globl _ms_count
	.globl _buffer
	.globl _data_frame
	.globl _BTN_MATRIX
	.globl _LED
	.globl _ds1302_write_time_PARM_2
	.globl _ds1302_read_time_PARM_2
	.globl _time_equal_PARM_2
	.globl _time_equal_PARM_1
	.globl _single_byte_write_PARM_2
	.globl _READ_T
	.globl _IDLE_T
	.globl _T_PEAK
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_P0	=	0x0080
_SP	=	0x0081
_DPL	=	0x0082
_DPH	=	0x0083
_PCON	=	0x0087
_TCON	=	0x0088
_TMOD	=	0x0089
_TL0	=	0x008a
_TL1	=	0x008b
_TH0	=	0x008c
_TH1	=	0x008d
_P1	=	0x0090
_SCON	=	0x0098
_SBUF	=	0x0099
_P2	=	0x00a0
_IE	=	0x00a8
_P3	=	0x00b0
_IP	=	0x00b8
_T2CON	=	0x00c8
_T2MOD	=	0x00c9
_RCAP2L	=	0x00ca
_RCAP2H	=	0x00cb
_TL2	=	0x00cc
_TH2	=	0x00cd
_PSW	=	0x00d0
_ACC	=	0x00e0
_A	=	0x00e0
_B	=	0x00f0
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_P0_0	=	0x0080
_P0_1	=	0x0081
_P0_2	=	0x0082
_P0_3	=	0x0083
_P0_4	=	0x0084
_P0_5	=	0x0085
_P0_6	=	0x0086
_P0_7	=	0x0087
_IT0	=	0x0088
_IE0	=	0x0089
_IT1	=	0x008a
_IE1	=	0x008b
_TR0	=	0x008c
_TF0	=	0x008d
_TR1	=	0x008e
_TF1	=	0x008f
_P1_0	=	0x0090
_P1_1	=	0x0091
_P1_2	=	0x0092
_P1_3	=	0x0093
_P1_4	=	0x0094
_P1_5	=	0x0095
_P1_6	=	0x0096
_P1_7	=	0x0097
_T2	=	0x0090
_T2EX	=	0x0091
_RI	=	0x0098
_TI	=	0x0099
_RB8	=	0x009a
_TB8	=	0x009b
_REN	=	0x009c
_SM2	=	0x009d
_SM1	=	0x009e
_SM0	=	0x009f
_P2_0	=	0x00a0
_P2_1	=	0x00a1
_P2_2	=	0x00a2
_P2_3	=	0x00a3
_P2_4	=	0x00a4
_P2_5	=	0x00a5
_P2_6	=	0x00a6
_P2_7	=	0x00a7
_EX0	=	0x00a8
_ET0	=	0x00a9
_EX1	=	0x00aa
_ET1	=	0x00ab
_ES	=	0x00ac
_ET2	=	0x00ad
_EA	=	0x00af
_P3_0	=	0x00b0
_P3_1	=	0x00b1
_P3_2	=	0x00b2
_P3_3	=	0x00b3
_P3_4	=	0x00b4
_P3_5	=	0x00b5
_P3_6	=	0x00b6
_P3_7	=	0x00b7
_RXD	=	0x00b0
_TXD	=	0x00b1
_INT0	=	0x00b2
_INT1	=	0x00b3
_T0	=	0x00b4
_T1	=	0x00b5
_WR	=	0x00b6
_RD	=	0x00b7
_PX0	=	0x00b8
_PT0	=	0x00b9
_PX1	=	0x00ba
_PT1	=	0x00bb
_PS	=	0x00bc
_PT2	=	0x00bd
_T2CON_0	=	0x00c8
_T2CON_1	=	0x00c9
_T2CON_2	=	0x00ca
_T2CON_3	=	0x00cb
_T2CON_4	=	0x00cc
_T2CON_5	=	0x00cd
_T2CON_6	=	0x00ce
_T2CON_7	=	0x00cf
_CP_RL2	=	0x00c8
_C_T2	=	0x00c9
_TR2	=	0x00ca
_EXEN2	=	0x00cb
_TCLK	=	0x00cc
_RCLK	=	0x00cd
_EXF2	=	0x00ce
_TF2	=	0x00cf
_P	=	0x00d0
_FL	=	0x00d1
_OV	=	0x00d2
_RS0	=	0x00d3
_RS1	=	0x00d4
_F0	=	0x00d5
_AC	=	0x00d6
_CY	=	0x00d7
_CE	=	0x00b5
_SCLK	=	0x00b6
_IO	=	0x00b4
_GND0	=	0x00a2
_GND1	=	0x00a3
_GND2	=	0x00a4
_ROW0	=	0x0097
_ROW1	=	0x0096
_ROW2	=	0x0095
_ROW3	=	0x0094
_COL0	=	0x0093
_COL1	=	0x0092
_COL2	=	0x0091
_COL3	=	0x0090
_FrameExtracted_LED	=	0x00a0
_DEV0	=	0x0005
_DEV1	=	0x0006
_DEV2	=	0x0007
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; overlayable bit register bank
;--------------------------------------------------------
	.area BIT_BANK	(REL,OVR,DATA)
bits:
	.ds 1
	b0 = bits[0]
	b1 = bits[1]
	b2 = bits[2]
	b3 = bits[3]
	b4 = bits[4]
	b5 = bits[5]
	b6 = bits[6]
	b7 = bits[7]
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
_T_PEAK::
	.ds 1
_IDLE_T::
	.ds 1
_READ_T::
	.ds 1
_single_byte_write_PARM_2:
	.ds 1
_time_equal_PARM_1:
	.ds 7
_time_equal_PARM_2:
	.ds 7
_ds1302_read_time_PARM_2:
	.ds 1
_ds1302_read_time_time_10000_37:
	.ds 3
_ds1302_read_time_AM_PM_10000_38:
	.ds 1
_ds1302_write_time_PARM_2:
	.ds 1
_LED::
	.ds 8
_BTN_MATRIX::
	.ds 2
_data_frame::
	.ds 2
_buffer::
	.ds 2
_ms_count::
	.ds 1
_negedge_count::
	.ds 1
_CURRENT_MODE::
	.ds 1
_MANUAL_MODE::
	.ds 1
_DEV_ENABLE::
	.ds 1
_sys_time::
	.ds 7
_time_on::
	.ds 7
_time_off::
	.ds 7
_SET_TIMER_t_10000_99:
	.ds 3
_SET_TIMER_tmp_10000_100:
	.ds 7
_SET_ON_OFF_PARM_2:
	.ds 1
_SET_ON_OFF_val_10000_104:
	.ds 3
_SET_ON_OFF_sloc0_1_0:
	.ds 2
_change_mode_STATE_10000_115:
	.ds 1
;--------------------------------------------------------
; overlayable items in internal ram
;--------------------------------------------------------
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
_led7seg_disp_PARM_2:
	.ds 1
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
_DEV_CTL_PARM_2:
	.ds 1
;--------------------------------------------------------
; Stack segment in internal ram
;--------------------------------------------------------
	.area SSEG
__start__stack:
	.ds	1

;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	.area IABS    (ABS,DATA)
	.area IABS    (ABS,DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
_time_equal_sloc0_1_0:
	.ds 1
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
;--------------------------------------------------------
; uninitialized external ram data
;--------------------------------------------------------
	.area XSEG    (XDATA)
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; initialized external ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
	.area HOME    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT1 (CODE)
	.area GSINIT2 (CODE)
	.area GSINIT3 (CODE)
	.area GSINIT4 (CODE)
	.area GSINIT5 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area CSEG    (CODE)
;--------------------------------------------------------
; interrupt vector
;--------------------------------------------------------
	.area HOME    (CODE)
__interrupt_vect:
	ljmp	__sdcc_gsinit_startup
	ljmp	_External0_Interrupt
	.ds	5
	ljmp	_Timer0_OverFlow_Interrupt
; restartable atomic support routines
	.ds	2
sdcc_atomic_exchange_rollback_start::
	nop
	nop
sdcc_atomic_exchange_pdata_impl:
	movx	a, @r0
	mov	r3, a
	mov	a, r2
	movx	@r0, a
	sjmp	sdcc_atomic_exchange_exit
	nop
	nop
sdcc_atomic_exchange_xdata_impl:
	movx	a, @dptr
	mov	r3, a
	mov	a, r2
	movx	@dptr, a
	sjmp	sdcc_atomic_exchange_exit
sdcc_atomic_compare_exchange_idata_impl:
	mov	a, @r0
	cjne	a, ar2, .+#5
	mov	a, r3
	mov	@r0, a
	ret
	nop
sdcc_atomic_compare_exchange_pdata_impl:
	movx	a, @r0
	cjne	a, ar2, .+#5
	mov	a, r3
	movx	@r0, a
	ret
	nop
sdcc_atomic_compare_exchange_xdata_impl:
	movx	a, @dptr
	cjne	a, ar2, .+#5
	mov	a, r3
	movx	@dptr, a
	ret
sdcc_atomic_exchange_rollback_end::

sdcc_atomic_exchange_gptr_impl::
	jnb	b.6, sdcc_atomic_exchange_xdata_impl
	mov	r0, dpl
	jb	b.5, sdcc_atomic_exchange_pdata_impl
sdcc_atomic_exchange_idata_impl:
	mov	a, r2
	xch	a, @r0
	mov	dpl, a
	ret
sdcc_atomic_exchange_exit:
	mov	dpl, r3
	ret
sdcc_atomic_compare_exchange_gptr_impl::
	jnb	b.6, sdcc_atomic_compare_exchange_xdata_impl
	mov	r0, dpl
	jb	b.5, sdcc_atomic_compare_exchange_pdata_impl
	sjmp	sdcc_atomic_compare_exchange_idata_impl
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
	.globl __sdcc_gsinit_startup
	.globl __sdcc_program_startup
	.globl __start__stack
	.globl __mcs51_genXINIT
	.globl __mcs51_genXRAMCLEAR
	.globl __mcs51_genRAMCLEAR
;	ThreeWiresProtocol.h:23: uint8 T_PEAK = 0;
	mov	_T_PEAK,#0x00
;	ThreeWiresProtocol.h:24: uint8 IDLE_T = 0;
	mov	_IDLE_T,#0x00
;	ThreeWiresProtocol.h:25: uint8 READ_T = 0;
	mov	_READ_T,#0x00
;	LED7Seg_OnKit.h:26: uint8 LED[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	mov	_LED,#0x00
	mov	(_LED + 0x0001),#0x00
	mov	(_LED + 0x0002),#0x00
	mov	(_LED + 0x0003),#0x00
	mov	(_LED + 0x0004),#0x00
	mov	(_LED + 0x0005),#0x00
	mov	(_LED + 0x0006),#0x00
	mov	(_LED + 0x0007),#0x00
;	Matrix_Button.h:22: uint32 BTN_MATRIX = 0;
	clr	a
	mov	_BTN_MATRIX,a
	mov	(_BTN_MATRIX + 1),a
;	IR_Reading.h:55: uint32 data_frame = 0;
	mov	_data_frame,a
	mov	(_data_frame + 1),a
;	IR_Reading.h:57: uint32 buffer = 0;
	mov	_buffer,a
	mov	(_buffer + 1),a
;	IR_Reading.h:59: uint8 ms_count = 0;
	mov	_ms_count,a
;	IR_Reading.h:61: int8 negedge_count = 0;
	mov	_negedge_count,a
;	main.h:21: uint8 CURRENT_MODE = DEV_0_CTL;
	mov	_CURRENT_MODE,#0x02
;	main.h:23: uint8 MANUAL_MODE = 0;
	mov	_MANUAL_MODE,a
;	main.h:30: uint8 DEV_ENABLE = 0;
	mov	_DEV_ENABLE,a
;	main.h:32: TIME sys_time = {0, 0, 0, 0, 0, 0, 0};
	mov	_sys_time,a
	mov	(_sys_time + 0x0001),a
	mov	(_sys_time + 0x0002),a
	mov	(_sys_time + 0x0003),a
	mov	(_sys_time + 0x0004),a
	mov	(_sys_time + 0x0005),a
	mov	(_sys_time + 0x0006),a
;	main.h:33: TIME time_on = {0, 0, 0, 0, 0, 0, 0};
	mov	_time_on,a
	mov	(_time_on + 0x0001),a
	mov	(_time_on + 0x0002),a
	mov	(_time_on + 0x0003),a
	mov	(_time_on + 0x0004),a
	mov	(_time_on + 0x0005),a
	mov	(_time_on + 0x0006),a
;	main.h:34: TIME time_off = {0, 0, 0, 0, 0, 0, 0};
	mov	_time_off,a
	mov	(_time_off + 0x0001),a
	mov	(_time_off + 0x0002),a
	mov	(_time_off + 0x0003),a
	mov	(_time_off + 0x0004),a
	mov	(_time_off + 0x0005),a
	mov	(_time_off + 0x0006),a
	.area GSFINAL (CODE)
	ljmp	__sdcc_program_startup
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
__sdcc_program_startup:
	ljmp	_main
;	return from main will return to caller
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'delay_us'
;------------------------------------------------------------
;us            Allocated to registers r6 r7 
;i             Allocated to registers r4 r5 
;------------------------------------------------------------
;	Base_Lib.h:60: static void delay_us(uint32 us){
;	-----------------------------------------
;	 function delay_us
;	-----------------------------------------
_delay_us:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	mov	r6, dpl
	mov	r7, dph
;	Base_Lib.h:62: for(i = 0; i < us; i = i + 1){
	mov	r4,#0x00
	mov	r5,#0x00
00103$:
	clr	c
	mov	a,r4
	subb	a,r6
	mov	a,r5
	subb	a,r7
	jnc	00105$
	inc	r4
	cjne	r4,#0x00,00103$
	inc	r5
	sjmp	00103$
00105$:
;	Base_Lib.h:65: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'delay_ms'
;------------------------------------------------------------
;ms            Allocated to registers 
;i             Allocated to registers r4 r5 
;------------------------------------------------------------
;	Base_Lib.h:67: void delay_ms(uint32 ms){
;	-----------------------------------------
;	 function delay_ms
;	-----------------------------------------
_delay_ms:
	mov	__mulint_PARM_2,dpl
	mov	(__mulint_PARM_2 + 1),dph
;	Base_Lib.h:69: for(i = 0; i < ms*12; i = i + 1){
	mov	dptr,#0x000c
	lcall	__mulint
	mov	r6, dpl
	mov	r7, dph
	mov	r4,#0x00
	mov	r5,#0x00
00103$:
	clr	c
	mov	a,r4
	subb	a,r6
	mov	a,r5
	subb	a,r7
	jnc	00105$
	inc	r4
	cjne	r4,#0x00,00103$
	inc	r5
	sjmp	00103$
00105$:
;	Base_Lib.h:72: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'eINT0_CTL'
;------------------------------------------------------------
;CONFIG        Allocated to registers r7 
;------------------------------------------------------------
;	Base_Lib.h:74: void eINT0_CTL(uint8 CONFIG){
;	-----------------------------------------
;	 function eINT0_CTL
;	-----------------------------------------
_eINT0_CTL:
	mov	r7, dpl
;	Base_Lib.h:75: if( CONFIG == ENABLE){
	cjne	r7,#0x01,00102$
;	Base_Lib.h:76: EX0 = 1;
;	assignBit
	setb	_EX0
;	Base_Lib.h:77: IT0 = 1;
;	assignBit
	setb	_IT0
00102$:
;	Base_Lib.h:79: if( CONFIG == DISABLE){
	mov	a,r7
	jnz	00105$
;	Base_Lib.h:80: EX0 = 0;
;	assignBit
	clr	_EX0
;	Base_Lib.h:81: IT0 = 0;
;	assignBit
	clr	_IT0
00105$:
;	Base_Lib.h:83: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'eINT1_CTL'
;------------------------------------------------------------
;CONFIG        Allocated to registers r7 
;------------------------------------------------------------
;	Base_Lib.h:85: void eINT1_CTL(uint8 CONFIG){
;	-----------------------------------------
;	 function eINT1_CTL
;	-----------------------------------------
_eINT1_CTL:
	mov	r7, dpl
;	Base_Lib.h:86: if( CONFIG == ENABLE){
	cjne	r7,#0x01,00102$
;	Base_Lib.h:88: IT1 = 1;   
;	assignBit
	setb	_IT1
;	Base_Lib.h:90: EX1 = 1;
;	assignBit
	setb	_EX1
00102$:
;	Base_Lib.h:92: if( CONFIG == DISABLE){
	mov	a,r7
	jnz	00105$
;	Base_Lib.h:94: IT1 = 0;   
;	assignBit
	clr	_IT1
;	Base_Lib.h:96: EX1 = 0;
;	assignBit
	clr	_EX1
00105$:
;	Base_Lib.h:98: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'TIMER0_CTL'
;------------------------------------------------------------
;CONFIG        Allocated to registers r7 
;------------------------------------------------------------
;	Base_Lib.h:102: void TIMER0_CTL(uint8 CONFIG){
;	-----------------------------------------
;	 function TIMER0_CTL
;	-----------------------------------------
_TIMER0_CTL:
;	Base_Lib.h:103: switch (CONFIG) {
	mov	a,dpl
	mov	r7,a
	add	a,#0xff - 0x05
	jc	00108$
	mov	a,r7
	add	a,r7
;	Base_Lib.h:104: case ENABLE:
	mov	dptr,#00117$
	jmp	@a+dptr
00117$:
	sjmp	00102$
	sjmp	00101$
	sjmp	00104$
	sjmp	00105$
	sjmp	00106$
	sjmp	00103$
00101$:
;	Base_Lib.h:105: ET0 = 1;            return;
;	assignBit
	setb	_ET0
;	Base_Lib.h:106: case DISABLE:
	ret
00102$:
;	Base_Lib.h:107: ET0 = 0;            return;
;	assignBit
	clr	_ET0
;	Base_Lib.h:108: case RESET:
	ret
00103$:
;	Base_Lib.h:109: TL0 = RESET_TL;
	mov	_TL0,#0x67
;	Base_Lib.h:110: TH0 = RESET_TH;     return;
	mov	_TH0,#0xfc
;	Base_Lib.h:111: case START:
	ret
00104$:
;	Base_Lib.h:112: TR0 = 1;            return;
;	assignBit
	setb	_TR0
;	Base_Lib.h:113: case STOP:
	ret
00105$:
;	Base_Lib.h:114: TR0 = 0;            return;
;	assignBit
	clr	_TR0
;	Base_Lib.h:115: case MODE_16BIT:
	ret
00106$:
;	Base_Lib.h:116: TMOD = TMOD|0x01;   return;
	orl	_TMOD,#0x01
;	Base_Lib.h:117: }
00108$:
;	Base_Lib.h:118: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'GLOBAL_INT'
;------------------------------------------------------------
;CONFIG        Allocated to registers r7 
;------------------------------------------------------------
;	Base_Lib.h:121: void GLOBAL_INT(uint8 CONFIG){
;	-----------------------------------------
;	 function GLOBAL_INT
;	-----------------------------------------
_GLOBAL_INT:
	mov	r7, dpl
;	Base_Lib.h:122: EA=(CONFIG==ENABLE)?(1):(0);
	cjne	r7,#0x01,00103$
	mov	a,r7
	sjmp	00104$
00103$:
	clr	a
00104$:
;	assignBit
	add	a,#0xff
	mov	_EA,c
;	Base_Lib.h:123: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'single_byte_write'
;------------------------------------------------------------
;byte_data     Allocated with name '_single_byte_write_PARM_2'
;cmd           Allocated to registers r7 
;nCLK          Allocated to registers r6 
;------------------------------------------------------------
;	ThreeWiresProtocol.h:30: void single_byte_write(uint8 cmd, uint8 byte_data){
;	-----------------------------------------
;	 function single_byte_write
;	-----------------------------------------
_single_byte_write:
	mov	r7, dpl
;	ThreeWiresProtocol.h:33: delay_us(IDLE_T);
	mov	r5,_IDLE_T
	mov	r6,#0x00
	mov	dpl, r5
	mov	dph, r6
	push	ar7
	lcall	_delay_us
;	ThreeWiresProtocol.h:35: CE = HIGH; SCLK = LOW;
;	assignBit
	setb	_CE
;	assignBit
	clr	_SCLK
;	ThreeWiresProtocol.h:37: delay_us(T_PEAK);
	mov	r5,_T_PEAK
	mov	r6,#0x00
	mov	dpl, r5
	mov	dph, r6
	lcall	_delay_us
	pop	ar7
;	ThreeWiresProtocol.h:39: for(nCLK = 1; nCLK <= 8; nCLK++){
	mov	r6,#0x01
00103$:
;	ThreeWiresProtocol.h:40: IO = (cmd&0x1);
	mov	a,r7
	anl	a,#0x01
;	assignBit
	add	a,#0xff
	mov	_IO,c
;	ThreeWiresProtocol.h:41: HL_MONO_PULSE(SCLK);
;	assignBit
	setb	_SCLK
	mov	r4,_T_PEAK
	mov	r5,#0x00
	mov	dpl, r4
	mov	dph, r5
	push	ar7
	push	ar6
	lcall	_delay_us
;	assignBit
	clr	_SCLK
	mov	r4,_T_PEAK
	mov	r5,#0x00
	mov	dpl, r4
	mov	dph, r5
	lcall	_delay_us
	pop	ar6
	pop	ar7
;	ThreeWiresProtocol.h:42: cmd = (cmd>>1);
	mov	a,r7
	clr	c
	rrc	a
	mov	r7,a
;	ThreeWiresProtocol.h:39: for(nCLK = 1; nCLK <= 8; nCLK++){
	inc	r6
	mov	a,r6
	add	a,#0xff - 0x08
	jnc	00103$
;	ThreeWiresProtocol.h:45: for(nCLK = 1; nCLK <= 8; nCLK++){
	mov	r7,#0x01
00105$:
;	ThreeWiresProtocol.h:46: IO = (byte_data&0x1);
	mov	a,_single_byte_write_PARM_2
	anl	a,#0x01
;	assignBit
	add	a,#0xff
	mov	_IO,c
;	ThreeWiresProtocol.h:47: HL_MONO_PULSE(SCLK);
;	assignBit
	setb	_SCLK
	mov	r5,_T_PEAK
	mov	r6,#0x00
	mov	dpl, r5
	mov	dph, r6
	push	ar7
	lcall	_delay_us
;	assignBit
	clr	_SCLK
	mov	r5,_T_PEAK
	mov	r6,#0x00
	mov	dpl, r5
	mov	dph, r6
	lcall	_delay_us
	pop	ar7
;	ThreeWiresProtocol.h:48: byte_data >>= 1;
	mov	a,_single_byte_write_PARM_2
	clr	c
	rrc	a
	mov	_single_byte_write_PARM_2,a
;	ThreeWiresProtocol.h:45: for(nCLK = 1; nCLK <= 8; nCLK++){
	inc	r7
	mov	a,r7
	add	a,#0xff - 0x08
	jnc	00105$
;	ThreeWiresProtocol.h:52: CE = LOW; 
;	assignBit
	clr	_CE
;	ThreeWiresProtocol.h:53: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'single_byte_read'
;------------------------------------------------------------
;cmd           Allocated to registers r7 
;nCLK          Allocated to registers r5 
;byte_data     Allocated to registers r6 
;bit_data      Allocated to registers 
;------------------------------------------------------------
;	ThreeWiresProtocol.h:55: uint8 single_byte_read(uint8 cmd){
;	-----------------------------------------
;	 function single_byte_read
;	-----------------------------------------
_single_byte_read:
	mov	r7, dpl
;	ThreeWiresProtocol.h:57: uint8 byte_data = 0, bit_data = 0;
	mov	r6,#0x00
;	ThreeWiresProtocol.h:59: delay_us(IDLE_T);
	mov	r4,_IDLE_T
	mov	r5,#0x00
	mov	dpl, r4
	mov	dph, r5
	push	ar7
	push	ar6
	lcall	_delay_us
;	ThreeWiresProtocol.h:61: CE = HIGH;SCLK = LOW;
;	assignBit
	setb	_CE
;	assignBit
	clr	_SCLK
;	ThreeWiresProtocol.h:62: delay_us(T_PEAK);
	mov	r4,_T_PEAK
	mov	r5,#0x00
	mov	dpl, r4
	mov	dph, r5
	lcall	_delay_us
	pop	ar6
	pop	ar7
;	ThreeWiresProtocol.h:64: for(nCLK = 1; nCLK <= 7; nCLK++){
	mov	r5,#0x01
00103$:
;	ThreeWiresProtocol.h:65: IO = (cmd&0x1);
	mov	a,r7
	anl	a,#0x01
;	assignBit
	add	a,#0xff
	mov	_IO,c
;	ThreeWiresProtocol.h:66: HL_MONO_PULSE(SCLK);
;	assignBit
	setb	_SCLK
	mov	r3,_T_PEAK
	mov	r4,#0x00
	mov	dpl, r3
	mov	dph, r4
	push	ar7
	push	ar6
	push	ar5
	lcall	_delay_us
;	assignBit
	clr	_SCLK
	mov	r3,_T_PEAK
	mov	r4,#0x00
	mov	dpl, r3
	mov	dph, r4
	lcall	_delay_us
	pop	ar5
	pop	ar6
	pop	ar7
;	ThreeWiresProtocol.h:67: cmd = (cmd>>1);
	mov	a,r7
	clr	c
	rrc	a
	mov	r7,a
;	ThreeWiresProtocol.h:64: for(nCLK = 1; nCLK <= 7; nCLK++){
	inc	r5
	mov	a,r5
	add	a,#0xff - 0x07
	jnc	00103$
;	ThreeWiresProtocol.h:70: IO = (cmd&0x1);
	mov	a,r7
	anl	a,#0x01
;	assignBit
	add	a,#0xff
	mov	_IO,c
;	ThreeWiresProtocol.h:71: SCLK = HIGH; delay_us(T_PEAK);
;	assignBit
	setb	_SCLK
	mov	r5,_T_PEAK
	mov	r7,#0x00
	mov	dpl, r5
	mov	dph, r7
	push	ar6
	lcall	_delay_us
	pop	ar6
;	ThreeWiresProtocol.h:73: for(nCLK = 0; nCLK <= 7; nCLK++){
	mov	r7,#0x00
00105$:
;	ThreeWiresProtocol.h:74: SCLK = LOW;  delay_us(READ_T);
;	assignBit
	clr	_SCLK
	mov	r4,_READ_T
	mov	r5,#0x00
	mov	dpl, r4
	mov	dph, r5
	push	ar7
	push	ar6
	lcall	_delay_us
	pop	ar6
	pop	ar7
;	ThreeWiresProtocol.h:75: bit_data = IO;
	mov	c,_IO
	clr	a
	rlc	a
	mov	r5,a
;	ThreeWiresProtocol.h:76: byte_data = byte_data|((bit_data&0x1)<<nCLK);
	mov	a,#0x01
	anl	a,r5
	mov	b,r7
	inc	b
	sjmp	00137$
00136$:
	add	a,acc
00137$:
	djnz	b,00136$
	orl	ar6,a
;	ThreeWiresProtocol.h:77: delay_us(T_PEAK-READ_T);
	mov	r4,_T_PEAK
	mov	r5,#0x00
	mov	r2,_READ_T
	mov	r3,#0x00
	mov	a,r4
	clr	c
	subb	a,r2
	mov	dpl,a
	mov	a,r5
	subb	a,r3
	mov	dph,a
	push	ar7
	push	ar6
	lcall	_delay_us
;	ThreeWiresProtocol.h:78: SCLK = HIGH; delay_us(T_PEAK);
;	assignBit
	setb	_SCLK
	mov	r4,_T_PEAK
	mov	r5,#0x00
	mov	dpl, r4
	mov	dph, r5
	lcall	_delay_us
	pop	ar6
	pop	ar7
;	ThreeWiresProtocol.h:73: for(nCLK = 0; nCLK <= 7; nCLK++){
	inc	r7
	mov	a,r7
	add	a,#0xff - 0x07
	jnc	00105$
;	ThreeWiresProtocol.h:82: CE = LOW; 
;	assignBit
	clr	_CE
;	ThreeWiresProtocol.h:83: return byte_data;
	mov	dpl, r6
;	ThreeWiresProtocol.h:84: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'ThreeWiresProtocol_Initial'
;------------------------------------------------------------
;	ThreeWiresProtocol.h:86: void ThreeWiresProtocol_Initial(){
;	-----------------------------------------
;	 function ThreeWiresProtocol_Initial
;	-----------------------------------------
_ThreeWiresProtocol_Initial:
;	ThreeWiresProtocol.h:87: IO = LOW;
;	assignBit
	clr	_IO
;	ThreeWiresProtocol.h:88: SCLK = LOW;
;	assignBit
	clr	_SCLK
;	ThreeWiresProtocol.h:89: CE = LOW;
;	assignBit
	clr	_CE
;	ThreeWiresProtocol.h:90: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'time_equal'
;------------------------------------------------------------
;A             Allocated with name '_time_equal_PARM_1'
;B             Allocated with name '_time_equal_PARM_2'
;MASK          Allocated to registers 
;------------------------------------------------------------
;	DS1302.h:38: uint8 time_equal(TIME A, TIME B, uint32 MASK){
;	-----------------------------------------
;	 function time_equal
;	-----------------------------------------
_time_equal:
;	DS1302.h:39: return (A.MINUTE == B.MINUTE) && (A.HOUR == B.HOUR);
	mov	a,(_time_equal_PARM_2 + 0x0005)
	cjne	a,(_time_equal_PARM_1 + 0x0005),00103$
	mov	a,(_time_equal_PARM_2 + 0x0004)
	cjne	a,(_time_equal_PARM_1 + 0x0004),00114$
	sjmp	00104$
00114$:
00103$:
;	assignBit
	clr	_time_equal_sloc0_1_0
	sjmp	00105$
00104$:
;	assignBit
	setb	_time_equal_sloc0_1_0
00105$:
	mov	c,_time_equal_sloc0_1_0
	clr	a
	rlc	a
	mov	dpl,a
;	DS1302.h:51: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'ds1302_read_time'
;------------------------------------------------------------
;SEL           Allocated with name '_ds1302_read_time_PARM_2'
;time          Allocated with name '_ds1302_read_time_time_10000_37'
;x10           Allocated to registers r5 
;x1            Allocated to registers r7 
;byte_data     Allocated to registers r7 
;AM_PM         Allocated with name '_ds1302_read_time_AM_PM_10000_38'
;x10           Allocated to registers r5 
;x1            Allocated to registers r7 
;------------------------------------------------------------
;	DS1302.h:61: void ds1302_read_time(TIME* time, uint8 SEL){
;	-----------------------------------------
;	 function ds1302_read_time
;	-----------------------------------------
_ds1302_read_time:
	mov	_ds1302_read_time_time_10000_37,dpl
	mov	(_ds1302_read_time_time_10000_37 + 1),dph
	mov	(_ds1302_read_time_time_10000_37 + 2),b
;	DS1302.h:64: if(SEL&0x1){
	mov	a,_ds1302_read_time_PARM_2
	mov	r4,a
	jnb	acc.0,00102$
;	DS1302.h:65: ds1302_unlock_reg();
	mov	_single_byte_write_PARM_2,#0x00
	mov	dpl, #0x8e
	push	ar4
	lcall	_single_byte_write
;	DS1302.h:66: byte_data = single_byte_read(0x81);
	mov	dpl, #0x81
	lcall	_single_byte_read
	mov	r3, dpl
	pop	ar4
;	DS1302.h:67: x10 = ((byte_data & 0x70) >> 4)*10;
	mov	ar1,r3
	anl	ar1,#0x70
	clr	a
	xch	a,r1
	swap	a
	anl	a,#0x0f
	xrl	a,r1
	xch	a,r1
	anl	a,#0x0f
	xch	a,r1
	xrl	a,r1
	xch	a,r1
	jnb	acc.3,00168$
	orl	a,#0xfffffff0
00168$:
	mov	a,r1
	mov	b,#0x0a
	mul	ab
	mov	r1,a
;	DS1302.h:68: x1  = (byte_data & 0x0F);
	anl	ar3,#0x0f
;	DS1302.h:69: time->SECOND = x1 + x10;
	mov	a,#0x06
	add	a, _ds1302_read_time_time_10000_37
	mov	r0,a
	clr	a
	addc	a, (_ds1302_read_time_time_10000_37 + 1)
	mov	r2,a
	mov	r7,(_ds1302_read_time_time_10000_37 + 2)
	mov	a,r1
	add	a, r3
	mov	dpl,r0
	mov	dph,r2
	mov	b,r7
	lcall	__gptrput
00102$:
;	DS1302.h:72: if(SEL&0x2){
	mov	a,r4
	jnb	acc.1,00104$
;	DS1302.h:73: ds1302_unlock_reg();
	mov	_single_byte_write_PARM_2,#0x00
	mov	dpl, #0x8e
	push	ar4
	lcall	_single_byte_write
;	DS1302.h:74: byte_data = single_byte_read(0x83);
	mov	dpl, #0x83
	lcall	_single_byte_read
	mov	r7, dpl
	pop	ar4
;	DS1302.h:75: x10 = ((byte_data & 0x70) >> 4)*10;
	mov	ar5,r7
	anl	ar5,#0x70
	clr	a
	xch	a,r5
	swap	a
	anl	a,#0x0f
	xrl	a,r5
	xch	a,r5
	anl	a,#0x0f
	xch	a,r5
	xrl	a,r5
	xch	a,r5
	jnb	acc.3,00170$
	orl	a,#0xfffffff0
00170$:
	mov	a,r5
	mov	b,#0x0a
	mul	ab
	mov	r5,a
;	DS1302.h:76: x1  = (byte_data & 0x0F);
	anl	ar7,#0x0f
;	DS1302.h:77: time->MINUTE = x10 + x1;
	mov	a,#0x05
	add	a, _ds1302_read_time_time_10000_37
	mov	r2,a
	clr	a
	addc	a, (_ds1302_read_time_time_10000_37 + 1)
	mov	r3,a
	mov	r6,(_ds1302_read_time_time_10000_37 + 2)
	mov	a,r7
	add	a, r5
	mov	dpl,r2
	mov	dph,r3
	mov	b,r6
	lcall	__gptrput
00104$:
;	DS1302.h:80: if(SEL&0x4){
	mov	a,r4
	jb	acc.2,00171$
	ljmp	00109$
00171$:
;	DS1302.h:81: ds1302_unlock_reg();
	mov	_single_byte_write_PARM_2,#0x00
	mov	dpl, #0x8e
	push	ar4
	lcall	_single_byte_write
;	DS1302.h:82: byte_data = single_byte_read(0x85);
	mov	dpl, #0x85
	lcall	_single_byte_read
	mov	r7, dpl
	pop	ar4
;	DS1302.h:83: if( (byte_data & 0x80) == HIGH){
	mov	ar5,r7
	mov	a,#0x80
	anl	a,r5
	mov	r2,a
	mov	r3,#0x00
	cjne	r2,#0x01,00106$
	cjne	r3,#0x00,00106$
;	DS1302.h:85: x10 = ((byte_data & 0x10)>>4)*10;
	push	ar4
	mov	a,#0x10
	anl	a,r5
	mov	r2,a
	clr	a
	xch	a,r2
	swap	a
	anl	a,#0x0f
	xrl	a,r2
	xch	a,r2
	anl	a,#0x0f
	xch	a,r2
	xrl	a,r2
	xch	a,r2
	jnb	acc.3,00174$
	orl	a,#0xfffffff0
00174$:
	mov	a,r2
	mov	b,#0x0a
	mul	ab
	mov	r2,a
;	DS1302.h:86: x1  = (byte_data & 0x0F);
	mov	a,#0x0f
	anl	a,r7
	mov	r3,a
;	DS1302.h:87: AM_PM = (byte_data&0x20)>>5;
	mov	a,#0x20
	anl	a,r5
	mov	r0,a
	clr	a
	rr	a
	xch	a,r0
	swap	a
	rr	a
	anl	a,#0x07
	xrl	a,r0
	xch	a,r0
	anl	a,#0x07
	xch	a,r0
	xrl	a,r0
	xch	a,r0
	jnb	acc.2,00175$
	orl	a,#0xfffffff8
00175$:
	mov	_ds1302_read_time_AM_PM_10000_38,r0
;	DS1302.h:88: time->HOUR = x10 + x1 + AM_PM * 12;
	mov	a,#0x04
	add	a, _ds1302_read_time_time_10000_37
	mov	r0,a
	clr	a
	addc	a, (_ds1302_read_time_time_10000_37 + 1)
	mov	r1,a
	mov	r4,(_ds1302_read_time_time_10000_37 + 2)
	mov	a,r3
	add	a, r2
	mov	r2,a
	mov	a,_ds1302_read_time_AM_PM_10000_38
	mov	b,#0x0c
	mul	ab
	add	a,r2
	mov	dpl,r0
	mov	dph,r1
	mov	b,r4
	lcall	__gptrput
	pop	ar4
	sjmp	00109$
00106$:
;	DS1302.h:91: uint8 x10 = ((byte_data & 0x30)>>4)*10;
	anl	ar5,#0x30
	clr	a
	xch	a,r5
	swap	a
	anl	a,#0x0f
	xrl	a,r5
	xch	a,r5
	anl	a,#0x0f
	xch	a,r5
	xrl	a,r5
	xch	a,r5
	jnb	acc.3,00176$
	orl	a,#0xfffffff0
00176$:
	mov	a,r5
	mov	b,#0x0a
	mul	ab
	mov	r5,a
;	DS1302.h:92: uint8 x1  = (byte_data & 0x0F);
	anl	ar7,#0x0f
;	DS1302.h:93: time->HOUR = x10 + x1;
	mov	a,#0x04
	add	a, _ds1302_read_time_time_10000_37
	mov	r2,a
	clr	a
	addc	a, (_ds1302_read_time_time_10000_37 + 1)
	mov	r3,a
	mov	r6,(_ds1302_read_time_time_10000_37 + 2)
	mov	a,r7
	add	a, r5
	mov	dpl,r2
	mov	dph,r3
	mov	b,r6
	lcall	__gptrput
00109$:
;	DS1302.h:97: if(SEL&0x10){
	mov	a,r4
	jnb	acc.4,00111$
;	DS1302.h:98: ds1302_unlock_reg();
	mov	_single_byte_write_PARM_2,#0x00
	mov	dpl, #0x8e
	push	ar4
	lcall	_single_byte_write
;	DS1302.h:99: byte_data = single_byte_read(0x87);
	mov	dpl, #0x87
	lcall	_single_byte_read
	mov	r7, dpl
	pop	ar4
;	DS1302.h:100: x10 = ((byte_data&0x30)>>4)*10;
	mov	ar5,r7
	anl	ar5,#0x30
	clr	a
	xch	a,r5
	swap	a
	anl	a,#0x0f
	xrl	a,r5
	xch	a,r5
	anl	a,#0x0f
	xch	a,r5
	xrl	a,r5
	xch	a,r5
	jnb	acc.3,00178$
	orl	a,#0xfffffff0
00178$:
	mov	a,r5
	mov	b,#0x0a
	mul	ab
	mov	r5,a
;	DS1302.h:101: x1  = (byte_data&0x0F);
	anl	ar7,#0x0f
;	DS1302.h:102: time->DATE = x10 + x1;
	mov	a,#0x01
	add	a, _ds1302_read_time_time_10000_37
	mov	r2,a
	clr	a
	addc	a, (_ds1302_read_time_time_10000_37 + 1)
	mov	r3,a
	mov	r6,(_ds1302_read_time_time_10000_37 + 2)
	mov	a,r7
	add	a, r5
	mov	dpl,r2
	mov	dph,r3
	mov	b,r6
	lcall	__gptrput
00111$:
;	DS1302.h:105: if(SEL&0x20){
	mov	a,r4
	jnb	acc.5,00113$
;	DS1302.h:106: ds1302_unlock_reg();
	mov	_single_byte_write_PARM_2,#0x00
	mov	dpl, #0x8e
	push	ar4
	lcall	_single_byte_write
;	DS1302.h:107: byte_data = single_byte_read(0x89);
	mov	dpl, #0x89
	lcall	_single_byte_read
	mov	r7, dpl
	pop	ar4
;	DS1302.h:108: x10 = ((byte_data&0x10)>>4)*10;
	mov	ar5,r7
	anl	ar5,#0x10
	clr	a
	xch	a,r5
	swap	a
	anl	a,#0x0f
	xrl	a,r5
	xch	a,r5
	anl	a,#0x0f
	xch	a,r5
	xrl	a,r5
	xch	a,r5
	jnb	acc.3,00180$
	orl	a,#0xfffffff0
00180$:
	mov	a,r5
	mov	b,#0x0a
	mul	ab
	mov	r5,a
;	DS1302.h:109: x1  = (byte_data&0x0F);
	anl	ar7,#0x0f
;	DS1302.h:110: time->MONTH = x10 + x1;
	mov	a,#0x02
	add	a, _ds1302_read_time_time_10000_37
	mov	r2,a
	clr	a
	addc	a, (_ds1302_read_time_time_10000_37 + 1)
	mov	r3,a
	mov	r6,(_ds1302_read_time_time_10000_37 + 2)
	mov	a,r7
	add	a, r5
	mov	dpl,r2
	mov	dph,r3
	mov	b,r6
	lcall	__gptrput
00113$:
;	DS1302.h:113: if(SEL&0x40){
	mov	a,r4
	jnb	acc.6,00116$
;	DS1302.h:114: ds1302_unlock_reg();
	mov	_single_byte_write_PARM_2,#0x00
	mov	dpl, #0x8e
	lcall	_single_byte_write
;	DS1302.h:115: byte_data = single_byte_read(0x87);
	mov	dpl, #0x87
	lcall	_single_byte_read
	mov	r7, dpl
;	DS1302.h:116: x10 = ((byte_data&0xF0)>>4)*10;
	mov	ar5,r7
	anl	ar5,#0xf0
	clr	a
	xch	a,r5
	swap	a
	anl	a,#0x0f
	xrl	a,r5
	xch	a,r5
	anl	a,#0x0f
	xch	a,r5
	xrl	a,r5
	xch	a,r5
	jnb	acc.3,00182$
	orl	a,#0xfffffff0
00182$:
	mov	a,r5
	mov	b,#0x0a
	mul	ab
	mov	r5,a
;	DS1302.h:117: x1  = (byte_data&0x0F);
	anl	ar7,#0x0f
;	DS1302.h:118: time->YEAR = x10 + x1;
	mov	a,#0x03
	add	a, _ds1302_read_time_time_10000_37
	mov	r3,a
	clr	a
	addc	a, (_ds1302_read_time_time_10000_37 + 1)
	mov	r4,a
	mov	r6,(_ds1302_read_time_time_10000_37 + 2)
	mov	a,r7
	add	a, r5
	mov	dpl,r3
	mov	dph,r4
	mov	b,r6
;	DS1302.h:120: }
	ljmp	__gptrput
00116$:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'ds1302_write_time'
;------------------------------------------------------------
;SEL           Allocated with name '_ds1302_write_time_PARM_2'
;time          Allocated to registers r5 r6 r7 
;x10           Allocated to registers r3 
;x1            Allocated to registers r1 
;byte_data     Allocated to registers r1 
;------------------------------------------------------------
;	DS1302.h:122: void ds1302_write_time(TIME* const time, uint8 SEL){
;	-----------------------------------------
;	 function ds1302_write_time
;	-----------------------------------------
_ds1302_write_time:
	mov	r5, dpl
	mov	r6, dph
	mov	r7, b
;	DS1302.h:125: if(SEL&0x1){
	mov	a,_ds1302_write_time_PARM_2
	mov	r4,a
	jnb	acc.0,00102$
;	DS1302.h:126: x10 = (((*time).SECOND)/10)%10;
	mov	a,#0x06
	add	a, r5
	mov	r1,a
	clr	a
	addc	a, r6
	mov	r2,a
	mov	ar3,r7
	mov	dpl,r1
	mov	dph,r2
	mov	b,r3
	lcall	__gptrget
	mov	r1,a
	mov	b,#0x0a
	div	ab
	mov	b,#0x0a
	div	ab
	mov	r3,b
;	DS1302.h:127: x1  = ((*time).SECOND)%10;
	mov	b,#0x0a
	mov	a,r1
	div	ab
	mov	r1,b
;	DS1302.h:128: byte_data = (x10<<4) + x1;
	mov	a,r3
	swap	a
	anl	a,#0xf0
	add	a,r1
	mov	r3,a
;	DS1302.h:129: ds1302_unlock_reg();
	mov	_single_byte_write_PARM_2,#0x00
	mov	dpl, #0x8e
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar3
	lcall	_single_byte_write
	pop	ar3
;	DS1302.h:130: single_byte_write(0x80, byte_data);
	mov	_single_byte_write_PARM_2,r3
	mov	dpl, #0x80
	lcall	_single_byte_write
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
00102$:
;	DS1302.h:133: if(SEL&0x2){
	mov	a,r4
	jnb	acc.1,00104$
;	DS1302.h:134: x10 = ((time->MINUTE)/10)%10;
	mov	a,#0x05
	add	a, r5
	mov	r1,a
	clr	a
	addc	a, r6
	mov	r2,a
	mov	ar3,r7
	mov	dpl,r1
	mov	dph,r2
	mov	b,r3
	lcall	__gptrget
	mov	r1,a
	mov	b,#0x0a
	div	ab
	mov	b,#0x0a
	div	ab
	mov	r3,b
;	DS1302.h:135: x1  = (time->MINUTE)%10;
	mov	b,#0x0a
	mov	a,r1
	div	ab
	mov	r1,b
;	DS1302.h:136: byte_data = (x10<<4) + x1;
	mov	a,r3
	swap	a
	anl	a,#0xf0
	add	a,r1
	mov	r3,a
;	DS1302.h:137: ds1302_unlock_reg();
	mov	_single_byte_write_PARM_2,#0x00
	mov	dpl, #0x8e
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar3
	lcall	_single_byte_write
	pop	ar3
;	DS1302.h:138: single_byte_write(0x82, byte_data);
	mov	_single_byte_write_PARM_2,r3
	mov	dpl, #0x82
	lcall	_single_byte_write
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
00104$:
;	DS1302.h:141: if(SEL&0x4){
	mov	a,r4
	jnb	acc.2,00106$
;	DS1302.h:142: x10 = ((time->HOUR)/10)%10;
	mov	a,#0x04
	add	a, r5
	mov	r1,a
	clr	a
	addc	a, r6
	mov	r2,a
	mov	ar3,r7
	mov	dpl,r1
	mov	dph,r2
	mov	b,r3
	lcall	__gptrget
	mov	r1,a
	mov	b,#0x0a
	div	ab
	mov	b,#0x0a
	div	ab
	mov	r3,b
;	DS1302.h:143: x1  = (time->HOUR)%10;
	mov	b,#0x0a
	mov	a,r1
	div	ab
	mov	r1,b
;	DS1302.h:144: byte_data = (x10<<4) + x1;
	mov	a,r3
	swap	a
	anl	a,#0xf0
	add	a,r1
	mov	r3,a
;	DS1302.h:145: ds1302_unlock_reg();
	mov	_single_byte_write_PARM_2,#0x00
	mov	dpl, #0x8e
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar3
	lcall	_single_byte_write
	pop	ar3
;	DS1302.h:146: single_byte_write(0x84, byte_data);
	mov	_single_byte_write_PARM_2,r3
	mov	dpl, #0x84
	lcall	_single_byte_write
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
00106$:
;	DS1302.h:149: if(SEL&0x8){
	mov	a,r4
	jnb	acc.3,00108$
;	DS1302.h:150: x10 = ((time->DATE)/10)%10;
	mov	a,#0x01
	add	a, r5
	mov	r1,a
	clr	a
	addc	a, r6
	mov	r2,a
	mov	ar3,r7
	mov	dpl,r1
	mov	dph,r2
	mov	b,r3
	lcall	__gptrget
	mov	r1,a
	mov	b,#0x0a
	div	ab
	mov	b,#0x0a
	div	ab
	mov	r3,b
;	DS1302.h:151: x1  = (time->DATE)%10;
	mov	b,#0x0a
	mov	a,r1
	div	ab
	mov	r1,b
;	DS1302.h:152: byte_data = (x10<<4) + x1;
	mov	a,r3
	swap	a
	anl	a,#0xf0
	add	a,r1
	mov	r1,a
;	DS1302.h:153: ds1302_unlock_reg();
	mov	_single_byte_write_PARM_2,#0x00
	mov	dpl, #0x8e
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar1
	lcall	_single_byte_write
	pop	ar1
;	DS1302.h:154: single_byte_write(0x86, byte_data);
	mov	_single_byte_write_PARM_2,r1
	mov	dpl, #0x86
	lcall	_single_byte_write
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
00108$:
;	DS1302.h:157: if(SEL&0x10){
	mov	a,r4
	jnb	acc.4,00110$
;	DS1302.h:158: x10 = ((time->MONTH)/10)%10;
	mov	a,#0x02
	add	a, r5
	mov	r1,a
	clr	a
	addc	a, r6
	mov	r2,a
	mov	ar3,r7
	mov	dpl,r1
	mov	dph,r2
	mov	b,r3
	lcall	__gptrget
	mov	r1,a
	mov	b,#0x0a
	div	ab
	mov	b,#0x0a
	div	ab
	mov	r3,b
;	DS1302.h:159: x1  = (time->MONTH)%10;
	mov	b,#0x0a
	mov	a,r1
	div	ab
	mov	r1,b
;	DS1302.h:160: byte_data = (x10<<4) + x1;
	mov	a,r3
	swap	a
	anl	a,#0xf0
	add	a,r1
	mov	r3,a
;	DS1302.h:161: ds1302_unlock_reg();
	mov	_single_byte_write_PARM_2,#0x00
	mov	dpl, #0x8e
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar3
	lcall	_single_byte_write
	pop	ar3
;	DS1302.h:162: single_byte_write(0x88, byte_data);
	mov	_single_byte_write_PARM_2,r3
	mov	dpl, #0x88
	lcall	_single_byte_write
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
00110$:
;	DS1302.h:165: if(SEL&0x20){
	mov	a,r4
	jnb	acc.5,00112$
;	DS1302.h:166: x10 = ((time->YEAR)/10)%10;
	mov	a,#0x03
	add	a, r5
	mov	r1,a
	clr	a
	addc	a, r6
	mov	r2,a
	mov	ar3,r7
	mov	dpl,r1
	mov	dph,r2
	mov	b,r3
	lcall	__gptrget
	mov	r1,a
	mov	b,#0x0a
	div	ab
	mov	b,#0x0a
	div	ab
	mov	r3,b
;	DS1302.h:167: x1  = (time->YEAR)%10;
	mov	b,#0x0a
	mov	a,r1
	div	ab
	mov	r1,b
;	DS1302.h:168: byte_data = (x10<<4) + x1;
	mov	a,r3
	swap	a
	anl	a,#0xf0
	add	a,r1
	mov	r3,a
;	DS1302.h:169: ds1302_unlock_reg();
	mov	_single_byte_write_PARM_2,#0x00
	mov	dpl, #0x8e
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar3
	lcall	_single_byte_write
	pop	ar3
;	DS1302.h:170: single_byte_write(0x9C, byte_data);
	mov	_single_byte_write_PARM_2,r3
	mov	dpl, #0x9c
	lcall	_single_byte_write
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
00112$:
;	DS1302.h:173: if(SEL&0x40){
	mov	a,r4
	jnb	acc.6,00115$
;	DS1302.h:174: x1  = (time->DAY)%10;
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	b,#0x0a
	div	ab
	mov	r5,b
;	DS1302.h:175: ds1302_unlock_reg();
	mov	_single_byte_write_PARM_2,#0x00
	mov	dpl, #0x8e
	push	ar5
	lcall	_single_byte_write
	pop	ar5
;	DS1302.h:176: single_byte_write(0x9A, x1);
	mov	_single_byte_write_PARM_2,r5
	mov	dpl, #0x9a
;	DS1302.h:178: }
	ljmp	_single_byte_write
00115$:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'ds1302_initial'
;------------------------------------------------------------
;	DS1302.h:180: void ds1302_initial(){
;	-----------------------------------------
;	 function ds1302_initial
;	-----------------------------------------
_ds1302_initial:
;	DS1302.h:181: ThreeWiresProtocol_Initial();
;	DS1302.h:182: }
	ljmp	_ThreeWiresProtocol_Initial
;------------------------------------------------------------
;Allocation info for local variables in function 'led7seg_disp'
;------------------------------------------------------------
;CODE          Allocated with name '_led7seg_disp_PARM_2'
;POS           Allocated to registers r7 
;------------------------------------------------------------
;	LED7Seg_OnKit.h:36: void led7seg_disp(uint8  POS, uint8  CODE){
;	-----------------------------------------
;	 function led7seg_disp
;	-----------------------------------------
_led7seg_disp:
;	LED7Seg_OnKit.h:37: switch (POS) {
	mov	a,dpl
	mov	r7,a
	add	a,#0xff - 0x08
	jnc	00119$
	ljmp	00109$
00119$:
	mov	a,r7
	add	a,#(00120$-3-.)
	movc	a,@a+pc
	mov	dpl,a
	mov	a,r7
	add	a,#(00121$-3-.)
	movc	a,@a+pc
	mov	dph,a
	clr	a
	jmp	@a+dptr
00120$:
	.db	00109$
	.db	00101$
	.db	00102$
	.db	00103$
	.db	00104$
	.db	00105$
	.db	00106$
	.db	00107$
	.db	00108$
00121$:
	.db	00109$>>8
	.db	00101$>>8
	.db	00102$>>8
	.db	00103$>>8
	.db	00104$>>8
	.db	00105$>>8
	.db	00106$>>8
	.db	00107$>>8
	.db	00108$>>8
;	LED7Seg_OnKit.h:38: case 0x1:
00101$:
;	LED7Seg_OnKit.h:39: { GND0 = 0; GND1 = 0; GND2 = 0; LED_7SEG = CODE; return;}
;	assignBit
	clr	_GND0
;	assignBit
	clr	_GND1
;	assignBit
	clr	_GND2
	mov	_P0,_led7seg_disp_PARM_2
;	LED7Seg_OnKit.h:40: case 0x2:
	ret
00102$:
;	LED7Seg_OnKit.h:41: { GND0 = 1; GND1 = 0; GND2 = 0; LED_7SEG = CODE; return;}
;	assignBit
	setb	_GND0
;	assignBit
	clr	_GND1
;	assignBit
	clr	_GND2
	mov	_P0,_led7seg_disp_PARM_2
;	LED7Seg_OnKit.h:42: case 0x3:
	ret
00103$:
;	LED7Seg_OnKit.h:43: { GND0 = 0; GND1 = 1; GND2 = 0; LED_7SEG = CODE; return;}
;	assignBit
	clr	_GND0
;	assignBit
	setb	_GND1
;	assignBit
	clr	_GND2
	mov	_P0,_led7seg_disp_PARM_2
;	LED7Seg_OnKit.h:44: case 0x4:
	ret
00104$:
;	LED7Seg_OnKit.h:45: { GND0 = 1; GND1 = 1; GND2 = 0; LED_7SEG = CODE; return;}
;	assignBit
	setb	_GND0
;	assignBit
	setb	_GND1
;	assignBit
	clr	_GND2
	mov	_P0,_led7seg_disp_PARM_2
;	LED7Seg_OnKit.h:46: case 0x5:
	ret
00105$:
;	LED7Seg_OnKit.h:47: { GND0 = 0; GND1 = 0; GND2 = 1; LED_7SEG = CODE; return;}
;	assignBit
	clr	_GND0
;	assignBit
	clr	_GND1
;	assignBit
	setb	_GND2
	mov	_P0,_led7seg_disp_PARM_2
;	LED7Seg_OnKit.h:48: case 0x6:
	ret
00106$:
;	LED7Seg_OnKit.h:49: { GND0 = 1; GND1 = 0; GND2 = 1; LED_7SEG = CODE; return;}
;	assignBit
	setb	_GND0
;	assignBit
	clr	_GND1
;	assignBit
	setb	_GND2
	mov	_P0,_led7seg_disp_PARM_2
;	LED7Seg_OnKit.h:50: case 0x7:
	ret
00107$:
;	LED7Seg_OnKit.h:51: { GND0 = 0; GND1 = 1; GND2 = 1; LED_7SEG = CODE; return;}
;	assignBit
	clr	_GND0
;	assignBit
	setb	_GND1
;	assignBit
	setb	_GND2
	mov	_P0,_led7seg_disp_PARM_2
;	LED7Seg_OnKit.h:52: case 0x8:
	ret
00108$:
;	LED7Seg_OnKit.h:53: { GND0 = 1; GND1 = 1; GND2 = 1; LED_7SEG = CODE; return;}
;	assignBit
	setb	_GND0
;	assignBit
	setb	_GND1
;	assignBit
	setb	_GND2
	mov	_P0,_led7seg_disp_PARM_2
;	LED7Seg_OnKit.h:54: default:
	ret
00109$:
;	LED7Seg_OnKit.h:55: LED_7SEG = 0x0;
	mov	_P0,#0x00
;	LED7Seg_OnKit.h:56: }
;	LED7Seg_OnKit.h:57: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'Disp8leds7seg'
;------------------------------------------------------------
;ms_disp_t     Allocated to registers r6 r7 
;i             Allocated to registers r3 
;j             Allocated to registers r4 r5 
;------------------------------------------------------------
;	LED7Seg_OnKit.h:70: void Disp8leds7seg(uint32 ms_disp_t){
;	-----------------------------------------
;	 function Disp8leds7seg
;	-----------------------------------------
_Disp8leds7seg:
	mov	r6, dpl
	mov	r7, dph
;	LED7Seg_OnKit.h:73: REP(j, 1, ms_disp_t)
	mov	r4,#0x01
	mov	r5,#0x00
00106$:
	clr	c
	mov	a,r6
	subb	a,r4
	mov	a,r7
	subb	a,r5
	jc	00108$
;	LED7Seg_OnKit.h:74: REP(i, 0, 7){
	mov	r3,#0x00
00103$:
;	LED7Seg_OnKit.h:75: led7seg_disp(i+1, LED[i]);
	mov	ar2,r3
	mov	a,r2
	inc	a
	mov	dpl,a
	mov	a,r3
	add	a, #_LED
	mov	r1,a
	mov	_led7seg_disp_PARM_2,@r1
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	push	ar3
	lcall	_led7seg_disp
;	LED7Seg_OnKit.h:76: delay_us(5);
	mov	dptr,#0x0005
	lcall	_delay_us
	pop	ar3
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
;	LED7Seg_OnKit.h:77: LED_7SEG = 0x0;
	mov	_P0,#0x00
;	LED7Seg_OnKit.h:74: REP(i, 0, 7){
	inc	r3
	mov	a,r3
	add	a,#0xff - 0x07
	jnc	00103$
;	LED7Seg_OnKit.h:73: REP(j, 1, ms_disp_t)
	inc	r4
	cjne	r4,#0x00,00106$
	inc	r5
	sjmp	00106$
00108$:
;	LED7Seg_OnKit.h:79: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'Row_Write'
;------------------------------------------------------------
;I             Allocated to registers r7 
;------------------------------------------------------------
;	Matrix_Button.h:24: void Row_Write(uint8 I){
;	-----------------------------------------
;	 function Row_Write
;	-----------------------------------------
_Row_Write:
;	Matrix_Button.h:25: switch (I){
	mov	a,dpl
	mov	r7,a
	add	a,#0xff - 0x03
	jc	00106$
	mov	a,r7
	add	a,r7
;	Matrix_Button.h:26: case 0:
	mov	dptr,#00115$
	jmp	@a+dptr
00115$:
	sjmp	00101$
	sjmp	00102$
	sjmp	00103$
	sjmp	00104$
00101$:
;	Matrix_Button.h:27: ROW0 = 0; ROW1 = 1; ROW2 = 1; ROW3 = 1;
;	assignBit
	clr	_ROW0
;	assignBit
	setb	_ROW1
;	assignBit
	setb	_ROW2
;	assignBit
	setb	_ROW3
;	Matrix_Button.h:28: break;
;	Matrix_Button.h:29: case 1:
	ret
00102$:
;	Matrix_Button.h:30: ROW0 = 1; ROW1 = 0; ROW2 = 1; ROW3 = 1;
;	assignBit
	setb	_ROW0
;	assignBit
	clr	_ROW1
;	assignBit
	setb	_ROW2
;	assignBit
	setb	_ROW3
;	Matrix_Button.h:31: break;
;	Matrix_Button.h:32: case 2:
	ret
00103$:
;	Matrix_Button.h:33: ROW0 = 1;  ROW1 = 1; ROW2 = 0; ROW3 = 1;
;	assignBit
	setb	_ROW0
;	assignBit
	setb	_ROW1
;	assignBit
	clr	_ROW2
;	assignBit
	setb	_ROW3
;	Matrix_Button.h:34: break;
;	Matrix_Button.h:35: case 3:
	ret
00104$:
;	Matrix_Button.h:36: ROW0 = 1;  ROW1 = 1; ROW2 = 1; ROW3 = 0;
;	assignBit
	setb	_ROW0
;	assignBit
	setb	_ROW1
;	assignBit
	setb	_ROW2
;	assignBit
	clr	_ROW3
;	Matrix_Button.h:38: }
00106$:
;	Matrix_Button.h:39: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'Col_Read'
;------------------------------------------------------------
;COL           Allocated to registers r6 r7 
;------------------------------------------------------------
;	Matrix_Button.h:41: uint32 Col_Read(){
;	-----------------------------------------
;	 function Col_Read
;	-----------------------------------------
_Col_Read:
;	Matrix_Button.h:42: uint32 COL = 0;
	mov	r6,#0x00
	mov	r7,#0x00
;	Matrix_Button.h:43: if(COL0 == 0) COL += 1;
	jb	_COL0,00102$
	mov	r6,#0x01
	mov	r7,#0x00
00102$:
;	Matrix_Button.h:44: if(COL1 == 0) COL += 2;
	jb	_COL1,00104$
	mov	a,#0x02
	add	a, r6
	mov	r6,a
	clr	a
	addc	a, r7
	mov	r7,a
00104$:
;	Matrix_Button.h:45: if(COL2 == 0) COL += 4;
	jb	_COL2,00106$
	mov	a,#0x04
	add	a, r6
	mov	r6,a
	clr	a
	addc	a, r7
	mov	r7,a
00106$:
;	Matrix_Button.h:46: if(COL3 == 0) COL += 8;
	jb	_COL3,00108$
	mov	a,#0x08
	add	a, r6
	mov	r6,a
	clr	a
	addc	a, r7
00108$:
;	Matrix_Button.h:47: return COL&0x0F;
	mov	a,#0x0f
	anl	a,r6
	mov	dpl,a
	mov	dph,#0x00
;	Matrix_Button.h:48: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'Get_BTN_MATRIX'
;------------------------------------------------------------
;i             Allocated to registers r7 
;------------------------------------------------------------
;	Matrix_Button.h:50: uint32 Get_BTN_MATRIX(){
;	-----------------------------------------
;	 function Get_BTN_MATRIX
;	-----------------------------------------
_Get_BTN_MATRIX:
;	Matrix_Button.h:52: BTN_MATRIX = 0;
	clr	a
	mov	_BTN_MATRIX,a
	mov	(_BTN_MATRIX + 1),a
;	Matrix_Button.h:53: for(i = 0; i < 4; ++i){
	mov	r7,a
00102$:
;	Matrix_Button.h:54: Row_Write(i);
	mov	ar6,r7
	mov	dpl, r6
	push	ar7
	push	ar6
	lcall	_Row_Write
;	Matrix_Button.h:56: BTN_MATRIX |= (Col_Read()<<(4*i));
	lcall	_Col_Read
	mov	r4, dpl
	mov	r5, dph
	pop	ar6
	pop	ar7
	mov	a,r6
	add	a,r6
	add	a,acc
	mov	b, a
	inc	b
	sjmp	00120$
00119$:
	mov	a,r4
	add	a,r4
	mov	r4,a
	mov	a,r5
	rlc	a
	mov	r5,a
00120$:
	djnz	b,00119$
	mov	a,r4
	orl	_BTN_MATRIX,a
	mov	a,r5
	orl	(_BTN_MATRIX + 1),a
;	Matrix_Button.h:53: for(i = 0; i < 4; ++i){
	inc	r7
	cjne	r7,#0x04,00121$
00121$:
	jc	00102$
;	Matrix_Button.h:58: return BTN_MATRIX;
	mov	dpl, _BTN_MATRIX
	mov	dph, (_BTN_MATRIX + 1)
;	Matrix_Button.h:59: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'Get_BTN_MATRIX_2'
;------------------------------------------------------------
;current_btn_matrix Allocated to registers r6 r7 
;------------------------------------------------------------
;	Matrix_Button.h:62: uint32 Get_BTN_MATRIX_2(){
;	-----------------------------------------
;	 function Get_BTN_MATRIX_2
;	-----------------------------------------
_Get_BTN_MATRIX_2:
;	Matrix_Button.h:63: uint32 current_btn_matrix = Get_BTN_MATRIX();
	lcall	_Get_BTN_MATRIX
	mov	r6, dpl
	mov	r7, dph
;	Matrix_Button.h:64: while( current_btn_matrix == Get_BTN_MATRIX()){
00101$:
	push	ar7
	push	ar6
	lcall	_Get_BTN_MATRIX
	mov	r4, dpl
	mov	r5, dph
	pop	ar6
	pop	ar7
	mov	a,r6
	cjne	a,ar4,00103$
	mov	a,r7
	cjne	a,ar5,00103$
;	Matrix_Button.h:65: current_btn_matrix = Get_BTN_MATRIX();
	lcall	_Get_BTN_MATRIX
	mov	r6, dpl
	mov	r7, dph
	sjmp	00101$
00103$:
;	Matrix_Button.h:67: return BTN_MATRIX;
	mov	dpl, _BTN_MATRIX
	mov	dph, (_BTN_MATRIX + 1)
;	Matrix_Button.h:68: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'new_dataframe'
;------------------------------------------------------------
;	IR_Reading.h:64: uint8 new_dataframe(){
;	-----------------------------------------
;	 function new_dataframe
;	-----------------------------------------
_new_dataframe:
;	IR_Reading.h:65: return (data_frame!=0)?1:0;
	mov	a,_data_frame
	orl	a,(_data_frame + 1)
	jz	00103$
	mov	r7,#0x01
	sjmp	00104$
00103$:
	mov	r7,#0x00
00104$:
	mov	dpl,r7
;	IR_Reading.h:66: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'read_extracted_frame'
;------------------------------------------------------------
;frame         Allocated to registers 
;------------------------------------------------------------
;	IR_Reading.h:69: uint32 read_extracted_frame(){
;	-----------------------------------------
;	 function read_extracted_frame
;	-----------------------------------------
_read_extracted_frame:
;	IR_Reading.h:70: uint32 frame = data_frame;
	mov	dpl,_data_frame
	mov	dph,(_data_frame + 1)
;	IR_Reading.h:71: data_frame = 0;
	clr	a
	mov	_data_frame,a
	mov	(_data_frame + 1),a
;	IR_Reading.h:72: return frame;
;	IR_Reading.h:73: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'IR_Reading_Initial'
;------------------------------------------------------------
;	IR_Reading.h:75: void IR_Reading_Initial(){
;	-----------------------------------------
;	 function IR_Reading_Initial
;	-----------------------------------------
_IR_Reading_Initial:
;	IR_Reading.h:78: buffer = 0;
	clr	a
	mov	_buffer,a
	mov	(_buffer + 1),a
;	IR_Reading.h:79: data_frame = 0;
	mov	_data_frame,a
	mov	(_data_frame + 1),a
;	IR_Reading.h:80: negedge_count = 0;
	mov	_negedge_count,a
;	IR_Reading.h:81: GLOBAL_INT(ENABLE);
	mov	dpl, #0x01
	lcall	_GLOBAL_INT
;	IR_Reading.h:82: eINT0_CTL(ENABLE);
	mov	dpl, #0x01
	lcall	_eINT0_CTL
;	IR_Reading.h:83: TIMER0_CTL(ENABLE);
	mov	dpl, #0x01
	lcall	_TIMER0_CTL
;	IR_Reading.h:84: TIMER0_CTL(MODE_16BIT);
	mov	dpl, #0x04
	lcall	_TIMER0_CTL
;	IR_Reading.h:85: TIMER0_CTL(START);
	mov	dpl, #0x02
	lcall	_TIMER0_CTL
;	IR_Reading.h:86: TIMER0_CTL(RESET);
	mov	dpl, #0x05
;	IR_Reading.h:87: }
	ljmp	_TIMER0_CTL
;------------------------------------------------------------
;Allocation info for local variables in function 'Timer0_OverFlow_Interrupt'
;------------------------------------------------------------
;	IR_Reading.h:89: void Timer0_OverFlow_Interrupt() __interrupt(1) {
;	-----------------------------------------
;	 function Timer0_OverFlow_Interrupt
;	-----------------------------------------
_Timer0_OverFlow_Interrupt:
	push	bits
	push	acc
	push	b
	push	dpl
	push	dph
	push	(0+7)
	push	(0+6)
	push	(0+5)
	push	(0+4)
	push	(0+3)
	push	(0+2)
	push	(0+1)
	push	(0+0)
	push	psw
	mov	psw,#0x00
;	IR_Reading.h:91: TIMER0_CTL(RESET);
	mov	dpl, #0x05
	lcall	_TIMER0_CTL
;	IR_Reading.h:93: if(ms_count<67) ms_count = ms_count + 1;
	mov	a,#0x100 - 0x43
	add	a,_ms_count
	jc	00103$
	mov	a,_ms_count
	inc	a
	mov	_ms_count,a
00103$:
;	IR_Reading.h:94: }
	pop	psw
	pop	(0+0)
	pop	(0+1)
	pop	(0+2)
	pop	(0+3)
	pop	(0+4)
	pop	(0+5)
	pop	(0+6)
	pop	(0+7)
	pop	dph
	pop	dpl
	pop	b
	pop	acc
	pop	bits
	reti
;------------------------------------------------------------
;Allocation info for local variables in function 'External0_Interrupt'
;------------------------------------------------------------
;current_mscount Allocated to registers r7 
;------------------------------------------------------------
;	IR_Reading.h:96: void External0_Interrupt() __interrupt(0) {
;	-----------------------------------------
;	 function External0_Interrupt
;	-----------------------------------------
_External0_Interrupt:
	push	bits
	push	acc
	push	b
	push	dpl
	push	dph
	push	(0+7)
	push	(0+6)
	push	(0+5)
	push	(0+4)
	push	(0+3)
	push	(0+2)
	push	(0+1)
	push	(0+0)
	push	psw
	mov	psw,#0x00
;	IR_Reading.h:99: current_mscount = ms_count;
	mov	r7,_ms_count
;	IR_Reading.h:100: TIMER0_CTL(RESET);
	mov	dpl, #0x05
	push	ar7
	lcall	_TIMER0_CTL
	pop	ar7
;	IR_Reading.h:101: ms_count=0;
	mov	_ms_count,#0x00
;	IR_Reading.h:102: negedge_count +=1;
	mov	a,_negedge_count
	mov	r6,a
	inc	a
	mov	_negedge_count,a
;	IR_Reading.h:105: if(current_mscount >= 67){
	cjne	r7,#0x43,00139$
00139$:
	jc	00109$
;	IR_Reading.h:106: negedge_count = -2;
	mov	_negedge_count,#0xfe
;	IR_Reading.h:107: RESET_BUFFER();
	clr	a
	mov	_buffer,a
	mov	(_buffer + 1),a
;	IR_Reading.h:111: if(0 <= negedge_count && negedge_count <= 31){
	sjmp	00113$
00109$:
	mov	a,_negedge_count
	add	a,#0xff - 0x1f
	jc	00107$
;	IR_Reading.h:112: if( current_mscount >= 2){
	cjne	r7,#0x02,00142$
00142$:
	jc	00113$
;	IR_Reading.h:113: PUSH_BIT_1();
	mov	a,#0x1f
	clr	c
	subb	a,_negedge_count
	mov	b, a
	inc	b
	mov	r7,#0x01
	mov	r6,#0x00
	sjmp	00145$
00144$:
	mov	a,r7
	add	a,r7
	mov	r7,a
	mov	a,r6
	rlc	a
	mov	r6,a
00145$:
	djnz	b,00144$
	mov	a,r7
	orl	_buffer,a
	mov	a,r6
	orl	(_buffer + 1),a
;	IR_Reading.h:115: PUSH_BIT_0();
	sjmp	00113$
00107$:
;	IR_Reading.h:117: }else if(negedge_count >= 32){
	mov	a,#0x100 - 0x20
	add	a,_negedge_count
	jnc	00113$
;	IR_Reading.h:118: EXTRACT_FRAME();
	mov	_data_frame,_buffer
	mov	(_data_frame + 1),(_buffer + 1)
	clr	a
	mov	_buffer,a
	mov	(_buffer + 1),a
	mov	_negedge_count,a
;	IR_Reading.h:119: FrameExtracted_LED=0;
;	assignBit
	clr	_FrameExtracted_LED
;	IR_Reading.h:120: delay_ms(1);
	mov	dptr,#0x0001
	lcall	_delay_ms
;	IR_Reading.h:121: FrameExtracted_LED=1;
;	assignBit
	setb	_FrameExtracted_LED
00113$:
;	IR_Reading.h:124: }
	pop	psw
	pop	(0+0)
	pop	(0+1)
	pop	(0+2)
	pop	(0+3)
	pop	(0+4)
	pop	(0+5)
	pop	(0+6)
	pop	(0+7)
	pop	dph
	pop	dpl
	pop	b
	pop	acc
	pop	bits
	ljmp	sdcc_atomic_maybe_rollback
;------------------------------------------------------------
;Allocation info for local variables in function 'CODE2NUM'
;------------------------------------------------------------
;CODE          Allocated to registers 
;------------------------------------------------------------
;	main.h:36: uint8 CODE2NUM(uint32 CODE){
;	-----------------------------------------
;	 function CODE2NUM
;	-----------------------------------------
_CODE2NUM:
;	main.h:49: return 0;
	mov	dpl, #0x00
;	main.h:50: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'YES_NO'
;------------------------------------------------------------
;CODE          Allocated to registers r6 r7 
;------------------------------------------------------------
;	main.h:52: uint8 YES_NO(){
;	-----------------------------------------
;	 function YES_NO
;	-----------------------------------------
_YES_NO:
;	main.h:54: LED[5] = 0; LED[4] = 0;
	mov	(_LED + 0x0005),#0x00
	mov	(_LED + 0x0004),#0x00
;	main.h:55: LED[3] = 0; LED[2] = 0;
	mov	(_LED + 0x0003),#0x00
	mov	(_LED + 0x0002),#0x00
;	main.h:56: LED[1] = 0; LED[0] = 0;
	mov	(_LED + 0x0001),#0x00
	mov	_LED,#0x00
;	main.h:57: while(0x1){
00106$:
;	main.h:58: CODE = read_extracted_frame();
	lcall	_read_extracted_frame
	mov	r6, dpl
	mov	r7, dph
;	main.h:59: LED[7] = 0x6E; LED[6] = 0x37;
	mov	(_LED + 0x0007),#0x6e
	mov	(_LED + 0x0006),#0x37
;	main.h:60: Disp8leds7seg(1);
	mov	dptr,#0x0001
	push	ar7
	push	ar6
	lcall	_Disp8leds7seg
	pop	ar6
	pop	ar7
;	main.h:61: switch (CODE) {
	cjne	r6,#0xdd,00134$
	cjne	r7,#0x22,00134$
	sjmp	00101$
00134$:
	cjne	r6,#0x9d,00135$
	cjne	r7,#0x62,00135$
	sjmp	00102$
00135$:
;	main.h:63: case PLAY_PAUSE: return 1;
	cjne	r6,#0x5d,00106$
	cjne	r7,#0xa2,00106$
	sjmp	00103$
00101$:
	mov	dpl, #0x01
;	main.h:64: case MODE: return 0;
	ret
00102$:
	mov	dpl, #0x00
;	main.h:65: case ON_OFF: return 0;
	ret
00103$:
	mov	dpl, #0x00
;	main.h:68: return 0;
;	main.h:69: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'SET_TIMER'
;------------------------------------------------------------
;t             Allocated with name '_SET_TIMER_t_10000_99'
;POS           Allocated to registers r4 
;CODE          Allocated to registers r2 r3 
;tmp           Allocated with name '_SET_TIMER_tmp_10000_100'
;------------------------------------------------------------
;	main.h:71: uint8 SET_TIMER(TIME* t){
;	-----------------------------------------
;	 function SET_TIMER
;	-----------------------------------------
_SET_TIMER:
	mov	_SET_TIMER_t_10000_99,dpl
	mov	(_SET_TIMER_t_10000_99 + 1),dph
	mov	(_SET_TIMER_t_10000_99 + 2),b
;	main.h:72: uint8 POS = 0;
	mov	r4,#0x00
;	main.h:81: ds1302_read_time(&tmp, 0x7);
	mov	_ds1302_read_time_PARM_2,#0x07
	mov	dptr,#_SET_TIMER_tmp_10000_100
	mov	b, #0x40
	push	ar4
	lcall	_ds1302_read_time
	pop	ar4
;	main.h:82: while(0x1){
00115$:
;	main.h:83: CODE = read_extracted_frame();
	push	ar4
	lcall	_read_extracted_frame
	mov	r2, dpl
	mov	r3, dph
	pop	ar4
;	main.h:84: if(CODE == PLAY_PAUSE) break;
	cjne	r2,#0xdd,00191$
	cjne	r3,#0x22,00191$
	ljmp	00116$
00191$:
;	main.h:85: if(CODE == PREV) POS = (POS+1 + 2)%2;
	cjne	r2,#0xfd,00104$
	cjne	r3,#0x02,00104$
	mov	ar7,r4
	mov	a,#0x03
	add	a, r7
	anl	a,#0x01
	mov	r4,a
00104$:
;	main.h:86: if(CODE == NEXT) POS = (POS-1 + 2)%2;
	cjne	r2,#0x3d,00106$
	cjne	r3,#0xc2,00106$
	mov	ar7,r4
	mov	a,r7
	inc	a
	anl	a,#0x01
	mov	r4,a
00106$:
;	main.h:87: if(CODE == ON_OFF) return 0;
	cjne	r2,#0x5d,00108$
	cjne	r3,#0xa2,00108$
	mov	dpl, #0x00
	ret
00108$:
;	main.h:88: if(CODE == MODE) return 0;
	cjne	r2,#0x9d,00110$
	cjne	r3,#0x62,00110$
	mov	dpl, #0x00
	ret
00110$:
;	main.h:89: switch (POS) {
	cjne	r4,#0x00,00200$
	sjmp	00111$
00200$:
;	main.h:90: case 0:
	cjne	r4,#0x01,00113$
	sjmp	00112$
00111$:
;	main.h:91: tmp.MINUTE += CODE2NUM(CODE)%10; tmp.MINUTE%=60; break;
	mov	r7,(_SET_TIMER_tmp_10000_100 + 0x0005)
	mov	dpl, r2
	mov	dph, r3
	push	ar7
	push	ar4
	lcall	_CODE2NUM
	mov	r6, dpl
	pop	ar4
	pop	ar7
	mov	b,#0x0a
	mov	a,r6
	div	ab
	mov	a,b
	add	a, r7
	mov	(_SET_TIMER_tmp_10000_100 + 0x0005),a
	mov	r7,(_SET_TIMER_tmp_10000_100 + 0x0005)
	mov	b,#0x3c
	mov	a,r7
	div	ab
	mov	r7,b
	mov	(_SET_TIMER_tmp_10000_100 + 0x0005),r7
;	main.h:92: case 1:
	sjmp	00113$
00112$:
;	main.h:93: tmp.HOUR   += CODE2NUM(CODE); tmp.HOUR%=24; break;
	mov	r7,(_SET_TIMER_tmp_10000_100 + 0x0004)
	mov	dpl, r2
	mov	dph, r3
	push	ar7
	push	ar4
	lcall	_CODE2NUM
	mov	r6, dpl
	pop	ar4
	pop	ar7
	mov	a,r6
	add	a, r7
	mov	r7,a
	mov	(_SET_TIMER_tmp_10000_100 + 0x0004),r7
	mov	b,#0x18
	mov	a,r7
	div	ab
	mov	r7,b
	mov	(_SET_TIMER_tmp_10000_100 + 0x0004),r7
;	main.h:94: }
00113$:
;	main.h:95: LED[0] = DIGIT_CODE[tmp.MINUTE%10] + ((POS==0)?(0x80):(0));
	mov	r7,(_SET_TIMER_tmp_10000_100 + 0x0005)
	mov	b,#0x0a
	mov	a,r7
	div	ab
	mov	r7,b
	mov	r6,#0x00
	mov	a,r7
	add	a, #_DIGIT_CODE
	mov	dpl,a
	mov	a,r6
	addc	a, #(_DIGIT_CODE >> 8)
	mov	dph,a
	clr	a
	movc	a,@a+dptr
	mov	r7,a
	mov	a,r4
	jnz	00121$
	mov	r6,#0x80
	sjmp	00122$
00121$:
	mov	r6,#0x00
00122$:
	mov	a,r6
	add	a, r7
	mov	_LED,a
;	main.h:96: LED[1] = DIGIT_CODE[tmp.MINUTE/10];
	mov	r7,(_SET_TIMER_tmp_10000_100 + 0x0005)
	mov	b,#0x0a
	mov	a,r7
	div	ab
	mov	r6,#0x00
	mov	dptr,#_DIGIT_CODE
	movc	a,@a+dptr
	mov	(_LED + 0x0001), a
;	main.h:97: LED[2] = DIGIT_CODE[tmp.HOUR%10]   + ((POS==1)?(0x80):(0));
	mov	r7,(_SET_TIMER_tmp_10000_100 + 0x0004)
	mov	b,#0x0a
	mov	a,r7
	div	ab
	mov	a,b
	add	a, #_DIGIT_CODE
	mov	dpl,a
	mov	a,r6
	addc	a, #(_DIGIT_CODE >> 8)
	mov	dph,a
	clr	a
	movc	a,@a+dptr
	mov	r7,a
	cjne	r4,#0x01,00123$
	mov	r6,#0x80
	sjmp	00124$
00123$:
	mov	r6,#0x00
00124$:
	mov	a,r6
	add	a, r7
	mov	(_LED + 0x0002),a
;	main.h:98: LED[3] = DIGIT_CODE[tmp.HOUR/10];
	mov	r7,(_SET_TIMER_tmp_10000_100 + 0x0004)
	mov	b,#0x0a
	mov	a,r7
	div	ab
	mov	dptr,#_DIGIT_CODE
	movc	a,@a+dptr
	mov	(_LED + 0x0003), a
;	main.h:99: Disp8leds7seg(50);
	mov	dptr,#0x0032
	push	ar4
	lcall	_Disp8leds7seg
	pop	ar4
	ljmp	00115$
00116$:
;	main.h:101: if(YES_NO()){
	lcall	_YES_NO
	mov	a, dpl
	jz	00118$
;	main.h:102: *t = tmp;
	mov	r5,_SET_TIMER_t_10000_99
	mov	r6,(_SET_TIMER_t_10000_99 + 1)
	mov	r7,(_SET_TIMER_t_10000_99 + 2)
	mov	___memcpy_PARM_2,#_SET_TIMER_tmp_10000_100
	mov	(___memcpy_PARM_2 + 1),#0x00
	mov	(___memcpy_PARM_2 + 2),#0x40
	mov	___memcpy_PARM_3,#0x07
	mov	(___memcpy_PARM_3 + 1),#0x00
	mov	dpl, r5
	mov	dph, r6
	mov	b, r7
	lcall	___memcpy
;	main.h:103: return 1;
	mov	dpl, #0x01
	ret
00118$:
;	main.h:105: return 0;
	mov	dpl, #0x00
;	main.h:106: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'SET_ON_OFF'
;------------------------------------------------------------
;dev           Allocated with name '_SET_ON_OFF_PARM_2'
;val           Allocated with name '_SET_ON_OFF_val_10000_104'
;tmp           Allocated to registers r4 
;CODE          Allocated to registers r6 r7 
;sloc0         Allocated with name '_SET_ON_OFF_sloc0_1_0'
;------------------------------------------------------------
;	main.h:108: uint8 SET_ON_OFF(uint8 *val, uint8 dev){
;	-----------------------------------------
;	 function SET_ON_OFF
;	-----------------------------------------
_SET_ON_OFF:
	mov	_SET_ON_OFF_val_10000_104,dpl
	mov	(_SET_ON_OFF_val_10000_104 + 1),dph
	mov	(_SET_ON_OFF_val_10000_104 + 2),b
;	main.h:109: uint8 tmp = 0;
	mov	r4,#0x00
;	main.h:111: while(0x1){
	mov	a,_SET_ON_OFF_PARM_2
	add	a, #_DIGIT_CODE
	mov	r2,a
	clr	a
	addc	a, #(_DIGIT_CODE >> 8)
	mov	r3,a
	mov	_SET_ON_OFF_sloc0_1_0,r2
	mov	(_SET_ON_OFF_sloc0_1_0 + 1),r3
00115$:
;	main.h:112: CODE = read_extracted_frame();
	push	ar4
	push	ar3
	push	ar2
	lcall	_read_extracted_frame
	mov	r6, dpl
	mov	r7, dph
	pop	ar2
	pop	ar3
	pop	ar4
;	main.h:113: if(CODE == PLAY_PAUSE) break;
	cjne	r6,#0xdd,00175$
	cjne	r7,#0x22,00175$
	ljmp	00116$
00175$:
;	main.h:114: if(CODE == PREV) tmp = (tmp+1 + 2)%2;
	cjne	r6,#0xfd,00104$
	cjne	r7,#0x02,00104$
	mov	ar5,r4
	mov	a,#0x03
	add	a, r5
	anl	a,#0x01
	mov	r4,a
00104$:
;	main.h:115: if(CODE == NEXT) tmp = (tmp-1 + 2)%2;
	cjne	r6,#0x3d,00106$
	cjne	r7,#0xc2,00106$
	mov	ar5,r4
	mov	a,r5
	inc	a
	anl	a,#0x01
	mov	r4,a
00106$:
;	main.h:116: if(CODE == ON_OFF) return 0;
	cjne	r6,#0x5d,00108$
	cjne	r7,#0xa2,00108$
	mov	dpl, #0x00
	ret
00108$:
;	main.h:117: if(CODE == MODE) return 0;
	cjne	r6,#0x9d,00110$
	cjne	r7,#0x62,00110$
	mov	dpl, #0x00
	ret
00110$:
;	main.h:118: switch (tmp) {
	cjne	r4,#0x00,00184$
	sjmp	00111$
00184$:
;	main.h:119: case 0:
	cjne	r4,#0x01,00113$
	sjmp	00112$
00111$:
;	main.h:120: LED[7] = DIGIT_CODE[13]; 
	mov	dptr,#(_DIGIT_CODE + 0x000d)
	clr	a
	movc	a,@a+dptr
	mov	(_LED + 0x0007), a
;	main.h:121: LED[6] = DIGIT_CODE[dev]; 
	mov	dpl,_SET_ON_OFF_sloc0_1_0
	mov	dph,(_SET_ON_OFF_sloc0_1_0 + 1)
	clr	a
	movc	a,@a+dptr
	mov	(_LED + 0x0006), a
;	main.h:122: LED[5] = 0; 
	mov	(_LED + 0x0005),#0x00
;	main.h:123: LED[4] = 0;
	mov	(_LED + 0x0004),#0x00
;	main.h:124: LED[3] = DIGIT_CODE[0]; 
	mov	dptr,#_DIGIT_CODE
	clr	a
	movc	a,@a+dptr
	mov	(_LED + 0x0003), a
;	main.h:125: LED[2] = 0x37;
	mov	(_LED + 0x0002),#0x37
;	main.h:126: LED[1] = 0x0; 
	mov	(_LED + 0x0001),#0x00
;	main.h:127: LED[0] = 0x0;
	mov	_LED,#0x00
;	main.h:128: break;
;	main.h:129: case 1:
	sjmp	00113$
00112$:
;	main.h:130: LED[7] = DIGIT_CODE[13]; 
	mov	dptr,#(_DIGIT_CODE + 0x000d)
	clr	a
	movc	a,@a+dptr
	mov	(_LED + 0x0007), a
;	main.h:131: LED[6] = DIGIT_CODE[dev]; 
	mov	dpl,r2
	mov	dph,r3
	clr	a
	movc	a,@a+dptr
	mov	(_LED + 0x0006), a
;	main.h:132: LED[5] = 0; 
	mov	(_LED + 0x0005),#0x00
;	main.h:133: LED[4] = 0;
	mov	(_LED + 0x0004),#0x00
;	main.h:134: LED[3] = DIGIT_CODE[0]; 
	mov	dptr,#_DIGIT_CODE
	clr	a
	movc	a,@a+dptr
	mov	(_LED + 0x0003), a
;	main.h:135: LED[2] = DIGIT_CODE[15]; 
	mov	dptr,#(_DIGIT_CODE + 0x000f)
	clr	a
	movc	a,@a+dptr
	mov	(_LED + 0x0002), a
;	main.h:136: LED[1] = DIGIT_CODE[15]; 
	mov	dptr,#(_DIGIT_CODE + 0x000f)
	clr	a
	movc	a,@a+dptr
	mov	(_LED + 0x0001), a
;	main.h:137: LED[0] = 0;
	mov	_LED,#0x00
;	main.h:139: }
00113$:
;	main.h:140: Disp8leds7seg(50);
	mov	dptr,#0x0032
	push	ar4
	push	ar3
	push	ar2
	lcall	_Disp8leds7seg
	pop	ar2
	pop	ar3
	pop	ar4
	ljmp	00115$
00116$:
;	main.h:142: if(YES_NO()){
	push	ar4
	lcall	_YES_NO
	mov	a, dpl
	pop	ar4
	jz	00118$
;	main.h:143: *val = tmp;
	mov	dpl,_SET_ON_OFF_val_10000_104
	mov	dph,(_SET_ON_OFF_val_10000_104 + 1)
	mov	b,(_SET_ON_OFF_val_10000_104 + 2)
	mov	a,r4
	lcall	__gptrput
;	main.h:144: return 1;
	mov	dpl, #0x01
	ret
00118$:
;	main.h:146: return 0;
	mov	dpl, #0x00
;	main.h:147: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'DEV_CTL'
;------------------------------------------------------------
;STATE         Allocated with name '_DEV_CTL_PARM_2'
;DEV           Allocated to registers r7 
;------------------------------------------------------------
;	main.h:149: void DEV_CTL(uint8 DEV, uint8 STATE){
;	-----------------------------------------
;	 function DEV_CTL
;	-----------------------------------------
_DEV_CTL:
	mov	r7, dpl
;	main.h:150: switch (DEV) {
	cjne	r7,#0x00,00125$
	sjmp	00101$
00125$:
	cjne	r7,#0x01,00126$
	sjmp	00102$
00126$:
;	main.h:151: case 0: DEV0 = (STATE)?(HIGH):(LOW); break;
	cjne	r7,#0x02,00105$
	sjmp	00103$
00101$:
;	assignBit
	mov	a,_DEV_CTL_PARM_2
	add	a,#0xff
	mov	_DEV0,c
;	main.h:152: case 1: DEV1 = (STATE)?(HIGH):(LOW); break;
	ret
00102$:
;	assignBit
	mov	a,_DEV_CTL_PARM_2
	add	a,#0xff
	mov	_DEV1,c
;	main.h:153: case 2: DEV2 = (STATE)?(HIGH):(LOW); break;
	ret
00103$:
;	assignBit
	mov	a,_DEV_CTL_PARM_2
	add	a,#0xff
	mov	_DEV2,c
;	main.h:154: }
00105$:
;	main.h:155: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'SHOW_MODE'
;------------------------------------------------------------
;M             Allocated to registers r7 
;------------------------------------------------------------
;	main.h:157: void SHOW_MODE(uint8 M){
;	-----------------------------------------
;	 function SHOW_MODE
;	-----------------------------------------
_SHOW_MODE:
	mov	r7, dpl
;	main.h:158: LED[7] = 0x39; LED[5] = 0xF, LED[6] = DIGIT_CODE[M];
	mov	(_LED + 0x0007),#0x39
	mov	(_LED + 0x0005),#0x0f
	mov	a,r7
	mov	dptr,#_DIGIT_CODE
	movc	a,@a+dptr
	mov	(_LED + 0x0006), a
;	main.h:159: Disp8leds7seg(1);
	mov	dptr,#0x0001
;	main.h:160: }
	ljmp	_Disp8leds7seg
;------------------------------------------------------------
;Allocation info for local variables in function 'change_mode'
;------------------------------------------------------------
;CODE          Allocated to registers r6 r7 
;STATE         Allocated with name '_change_mode_STATE_10000_115'
;------------------------------------------------------------
;	main.h:162: void change_mode(uint32 CODE){
;	-----------------------------------------
;	 function change_mode
;	-----------------------------------------
_change_mode:
	mov	r6, dpl
	mov	r7, dph
;	main.h:163: uint8 STATE = 0;
	mov	_change_mode_STATE_10000_115,#0x00
;	main.h:165: switch (CODE) {
	cjne	r6,#0xfd,00202$
	cjne	r7,#0x02,00202$
	sjmp	00102$
00202$:
	cjne	r6,#0x9d,00203$
	cjne	r7,#0x62,00203$
	sjmp	00104$
00203$:
	cjne	r6,#0x5d,00204$
	cjne	r7,#0xa2,00204$
	sjmp	00101$
00204$:
;	main.h:166: case ON_OFF: CURRENT_MODE = REMOTE; break;
	cjne	r6,#0x3d,00105$
	cjne	r7,#0xc2,00105$
	sjmp	00103$
00101$:
	mov	_CURRENT_MODE,#0x00
;	main.h:167: case PREV: CURRENT_MODE = (CURRENT_MODE-1+8)%8; break;
	sjmp	00105$
00102$:
	mov	r4,_CURRENT_MODE
	mov	r5,#0x00
	mov	a,#0x07
	add	a, r4
	mov	dpl,a
	clr	a
	addc	a, r5
	mov	dph,a
	mov	__modsint_PARM_2,#0x08
	mov	(__modsint_PARM_2 + 1),r5
	push	ar7
	push	ar6
	lcall	__modsint
	mov	r4, dpl
	mov	r5, dph
	pop	ar6
	pop	ar7
	mov	_CURRENT_MODE,r4
;	main.h:168: case NEXT: CURRENT_MODE = (CURRENT_MODE+1)%8; break;
	sjmp	00105$
00103$:
	mov	r4,_CURRENT_MODE
	mov	r5,#0x00
	mov	dpl,r4
	mov	dph,r5
	inc	dptr
	mov	__modsint_PARM_2,#0x08
	mov	(__modsint_PARM_2 + 1),r5
	push	ar7
	push	ar6
	lcall	__modsint
	mov	r4, dpl
	mov	r5, dph
	pop	ar6
	pop	ar7
	mov	_CURRENT_MODE,r4
;	main.h:169: case MODE: CURRENT_MODE = (CURRENT_MODE+1)%8; break;
	sjmp	00105$
00104$:
	mov	r4,_CURRENT_MODE
	mov	r5,#0x00
	mov	dpl,r4
	mov	dph,r5
	inc	dptr
	mov	__modsint_PARM_2,#0x08
	mov	(__modsint_PARM_2 + 1),r5
	push	ar7
	push	ar6
	lcall	__modsint
	mov	r4, dpl
	mov	r5, dph
	pop	ar6
	pop	ar7
	mov	_CURRENT_MODE,r4
;	main.h:170: }
00105$:
;	main.h:172: switch (CURRENT_MODE) {
	mov	a,_CURRENT_MODE
	add	a,#0xff - 0x07
	jnc	00206$
	ret
00206$:
	mov	a,_CURRENT_MODE
	add	a,#(00207$-3-.)
	movc	a,@a+pc
	mov	dpl,a
	mov	a,_CURRENT_MODE
	add	a,#(00208$-3-.)
	movc	a,@a+pc
	mov	dph,a
	clr	a
	jmp	@a+dptr
00207$:
	.db	00106$
	.db	00107$
	.db	00108$
	.db	00111$
	.db	00114$
	.db	00117$
	.db	00120$
	.db	00123$
00208$:
	.db	00106$>>8
	.db	00107$>>8
	.db	00108$>>8
	.db	00111$>>8
	.db	00114$>>8
	.db	00117$>>8
	.db	00120$>>8
	.db	00123$>>8
;	main.h:173: case REMOTE:
00106$:
;	main.h:174: SHOW_MODE(1);
	mov	dpl, #0x01
;	main.h:175: return;
	ljmp	_SHOW_MODE
;	main.h:177: case SET_DEV_ENABLE:
00107$:
;	main.h:178: SHOW_MODE(2);
	mov	dpl, #0x02
;	main.h:179: return;
	ljmp	_SHOW_MODE
;	main.h:181: case DEV_0_CTL:
00108$:
;	main.h:182: SHOW_MODE(3);
	mov	dpl, #0x03
	push	ar7
	push	ar6
	lcall	_SHOW_MODE
	pop	ar6
	pop	ar7
;	main.h:183: if(CODE == PLAY_PAUSE){
	cjne	r6,#0xdd,00110$
	cjne	r7,#0x22,00110$
;	main.h:184: SET_ON_OFF(&STATE, 0x0);
	mov	_SET_ON_OFF_PARM_2,#0x00
	mov	dptr,#_change_mode_STATE_10000_115
	mov	b, #0x40
	lcall	_SET_ON_OFF
;	main.h:185: DEV_CTL(0x0, STATE);
	mov	_DEV_CTL_PARM_2,_change_mode_STATE_10000_115
	mov	dpl, #0x00
	lcall	_DEV_CTL
00110$:
;	main.h:187: SHOW_MODE(3);
	mov	dpl, #0x03
;	main.h:188: return;
	ljmp	_SHOW_MODE
;	main.h:190: case DEV_1_CTL:
00111$:
;	main.h:191: SHOW_MODE(4);
	mov	dpl, #0x04
	push	ar7
	push	ar6
	lcall	_SHOW_MODE
	pop	ar6
	pop	ar7
;	main.h:192: if(CODE == PLAY_PAUSE){
	cjne	r6,#0xdd,00113$
	cjne	r7,#0x22,00113$
;	main.h:193: SET_ON_OFF(&STATE, 0x1);
	mov	_SET_ON_OFF_PARM_2,#0x01
	mov	dptr,#_change_mode_STATE_10000_115
	mov	b, #0x40
	lcall	_SET_ON_OFF
;	main.h:194: DEV_CTL(0x1, STATE);
	mov	_DEV_CTL_PARM_2,_change_mode_STATE_10000_115
	mov	dpl, #0x01
	lcall	_DEV_CTL
00113$:
;	main.h:196: SHOW_MODE(4);
	mov	dpl, #0x04
;	main.h:197: return;
	ljmp	_SHOW_MODE
;	main.h:199: case DEV_2_CTL:
00114$:
;	main.h:200: SHOW_MODE(5);
	mov	dpl, #0x05
	push	ar7
	push	ar6
	lcall	_SHOW_MODE
	pop	ar6
	pop	ar7
;	main.h:201: if(CODE == PLAY_PAUSE){
	cjne	r6,#0xdd,00116$
	cjne	r7,#0x22,00116$
;	main.h:202: SET_ON_OFF(&STATE, 0x2);
	mov	_SET_ON_OFF_PARM_2,#0x02
	mov	dptr,#_change_mode_STATE_10000_115
	mov	b, #0x40
	lcall	_SET_ON_OFF
;	main.h:203: DEV_CTL(0x2, STATE);
	mov	_DEV_CTL_PARM_2,_change_mode_STATE_10000_115
	mov	dpl, #0x02
	lcall	_DEV_CTL
00116$:
;	main.h:205: SHOW_MODE(5);
	mov	dpl, #0x05
;	main.h:206: return;
	ljmp	_SHOW_MODE
;	main.h:208: case DEV_2_SET_ON_TIMER:
00117$:
;	main.h:209: SHOW_MODE(6);
	mov	dpl, #0x06
	push	ar7
	push	ar6
	lcall	_SHOW_MODE
	pop	ar6
	pop	ar7
;	main.h:210: if(CODE == PLAY_PAUSE) {
	cjne	r6,#0xdd,00119$
	cjne	r7,#0x22,00119$
;	main.h:211: LED[7] = DIGIT_CODE[0]; LED[6] = 0x37;
	mov	dptr,#_DIGIT_CODE
	clr	a
	movc	a,@a+dptr
	mov	(_LED + 0x0007), a
	mov	(_LED + 0x0006),#0x37
;	main.h:212: LED[5] = 0x0;
	mov	(_LED + 0x0005),#0x00
;	main.h:213: SET_TIMER(&time_on);
	mov	dptr,#_time_on
	mov	b, #0x40
	lcall	_SET_TIMER
00119$:
;	main.h:215: SHOW_MODE(6);
	mov	dpl, #0x06
;	main.h:216: return;
	ljmp	_SHOW_MODE
;	main.h:218: case DEV_2_SET_OFF_TIMER:
00120$:
;	main.h:219: SHOW_MODE(7);
	mov	dpl, #0x07
	push	ar7
	push	ar6
	lcall	_SHOW_MODE
	pop	ar6
	pop	ar7
;	main.h:220: if(CODE == PLAY_PAUSE){
	cjne	r6,#0xdd,00122$
	cjne	r7,#0x22,00122$
;	main.h:221: SET_TIMER(&time_off);
	mov	dptr,#_time_off
	mov	b, #0x40
	lcall	_SET_TIMER
;	main.h:222: LED[7] = DIGIT_CODE[0]; LED[6] = DIGIT_CODE[15]; 
	mov	dptr,#_DIGIT_CODE
	clr	a
	movc	a,@a+dptr
	mov	(_LED + 0x0007), a
	mov	dptr,#(_DIGIT_CODE + 0x000f)
	clr	a
	movc	a,@a+dptr
	mov	(_LED + 0x0006), a
;	main.h:223: LED[5] = DIGIT_CODE[15];
	mov	dptr,#(_DIGIT_CODE + 0x000f)
	clr	a
	movc	a,@a+dptr
	mov	(_LED + 0x0005), a
00122$:
;	main.h:225: SHOW_MODE(7);
	mov	dpl, #0x07
;	main.h:226: return;
;	main.h:228: case SETUP_SYS_TIME:
	ljmp	_SHOW_MODE
00123$:
;	main.h:229: SHOW_MODE(8);
	mov	dpl, #0x08
	push	ar7
	push	ar6
	lcall	_SHOW_MODE
	pop	ar6
	pop	ar7
;	main.h:230: if( CODE == PLAY_PAUSE && SET_TIMER(&sys_time) ){
	cjne	r6,#0xdd,00125$
	cjne	r7,#0x22,00125$
	mov	dptr,#_sys_time
	mov	b, #0x40
	lcall	_SET_TIMER
	mov	a, dpl
	jz	00125$
;	main.h:231: LED[7] = DIGIT_CODE[5]; LED[6] = 0x72; LED[5] = DIGIT_CODE[5];
	mov	dptr,#(_DIGIT_CODE + 0x0005)
	clr	a
	movc	a,@a+dptr
	mov	(_LED + 0x0007), a
	mov	(_LED + 0x0006),#0x72
	mov	dptr,#(_DIGIT_CODE + 0x0005)
	clr	a
	movc	a,@a+dptr
	mov	(_LED + 0x0005), a
;	main.h:232: ds1302_write_time(&sys_time, 0x3F);
	mov	_ds1302_write_time_PARM_2,#0x3f
	mov	dptr,#_sys_time
	mov	b, #0x40
	lcall	_ds1302_write_time
00125$:
;	main.h:234: SHOW_MODE(8);
	mov	dpl, #0x08
;	main.h:235: return;
;	main.h:236: }
;	main.h:237: }
	ljmp	_SHOW_MODE
;------------------------------------------------------------
;Allocation info for local variables in function 'sys_time_disp'
;------------------------------------------------------------
;mili_sec      Allocated to registers r6 r7 
;------------------------------------------------------------
;	main.h:239: void sys_time_disp(uint32 mili_sec){
;	-----------------------------------------
;	 function sys_time_disp
;	-----------------------------------------
_sys_time_disp:
	mov	r6, dpl
	mov	r7, dph
;	main.h:240: LED[3] = DIGIT_CODE[sys_time.HOUR/10];
	mov	r5,(_sys_time + 0x0004)
	mov	b,#0x0a
	mov	a,r5
	div	ab
	mov	r4,#0x00
	mov	dptr,#_DIGIT_CODE
	movc	a,@a+dptr
	mov	(_LED + 0x0003), a
;	main.h:241: LED[2] = DIGIT_CODE[sys_time.HOUR%10];
	mov	r5,(_sys_time + 0x0004)
	mov	b,#0x0a
	mov	a,r5
	div	ab
	mov	a,b
	add	a, #_DIGIT_CODE
	mov	dpl,a
	mov	a,r4
	addc	a, #(_DIGIT_CODE >> 8)
	mov	dph,a
	clr	a
	movc	a,@a+dptr
	mov	(_LED + 0x0002), a
;	main.h:242: LED[1] = DIGIT_CODE[sys_time.MINUTE/10];
	mov	r5,(_sys_time + 0x0005)
	mov	b,#0x0a
	mov	a,r5
	div	ab
	add	a, #_DIGIT_CODE
	mov	dpl,a
	mov	a,r4
	addc	a, #(_DIGIT_CODE >> 8)
	mov	dph,a
	clr	a
	movc	a,@a+dptr
	mov	(_LED + 0x0001), a
;	main.h:243: LED[0] = DIGIT_CODE[sys_time.MINUTE%10];
	mov	r5,(_sys_time + 0x0005)
	mov	b,#0x0a
	mov	a,r5
	div	ab
	mov	a,b
	add	a, #_DIGIT_CODE
	mov	dpl,a
	mov	a,r4
	addc	a, #(_DIGIT_CODE >> 8)
	mov	dph,a
	clr	a
	movc	a,@a+dptr
	mov	_LED, a
;	main.h:244: Disp8leds7seg(mili_sec);
	mov	dpl, r6
	mov	dph, r7
;	main.h:245: }
	ljmp	_Disp8leds7seg
;------------------------------------------------------------
;Allocation info for local variables in function 'main_intial'
;------------------------------------------------------------
;	main.h:247: void main_intial(){
;	-----------------------------------------
;	 function main_intial
;	-----------------------------------------
_main_intial:
;	main.h:248: ds1302_initial();
	lcall	_ds1302_initial
;	main.h:249: IR_Reading_Initial();
	lcall	_IR_Reading_Initial
;	main.h:250: LED_7SEG = 0x0;
	mov	_P0,#0x00
;	main.h:251: sys_time.HOUR = 0;
	mov	(_sys_time + 0x0004),#0x00
;	main.h:252: sys_time.MINUTE = 0;
	mov	(_sys_time + 0x0005),#0x00
;	main.h:253: sys_time.SECOND = 0;
	mov	(_sys_time + 0x0006),#0x00
;	main.h:254: sys_time.DATE = 0;
	mov	(_sys_time + 0x0001),#0x00
;	main.h:255: sys_time.DAY = 0;
	mov	_sys_time,#0x00
;	main.h:256: sys_time.MONTH = 0;
	mov	(_sys_time + 0x0002),#0x00
;	main.h:257: sys_time.YEAR = 0;
	mov	(_sys_time + 0x0003),#0x00
;	main.h:258: ds1302_write_time(&sys_time, 0x7F);
	mov	_ds1302_write_time_PARM_2,#0x7f
	mov	dptr,#_sys_time
	mov	b, #0x40
;	main.h:259: }
	ljmp	_ds1302_write_time
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;C             Allocated to registers r6 r7 
;------------------------------------------------------------
;	main.c:3: int main(){
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
;	main.c:4: main_intial();
	lcall	_main_intial
;	main.c:5: change_mode(REMOTE);
	mov	dptr,#0x0000
	lcall	_change_mode
;	main.c:7: while(0x1){
00102$:
;	main.c:8: ds1302_read_time(&sys_time, 0x7);
	mov	_ds1302_read_time_PARM_2,#0x07
	mov	dptr,#_sys_time
	mov	b, #0x40
	lcall	_ds1302_read_time
;	main.c:12: C = read_extracted_frame();
	lcall	_read_extracted_frame
	mov	r6, dpl
	mov	r7, dph
;	main.c:13: LED[7]= DIGIT_CODE[ (C) & 0xF];
	mov	a,#0x0f
	anl	a,r6
	mov	dptr,#_DIGIT_CODE
	movc	a,@a+dptr
	mov	(_LED + 0x0007), a
;	main.c:14: LED[6]= DIGIT_CODE[ (C>>4) & 0xF];
	mov	ar4,r6
	mov	a,r7
	swap	a
	xch	a,r4
	swap	a
	anl	a,#0x0f
	xrl	a,r4
	xch	a,r4
	anl	a,#0x0f
	xch	a,r4
	xrl	a,r4
	xch	a,r4
	anl	ar4,#0x0f
	mov	r5,#0x00
	mov	a,r4
	add	a, #_DIGIT_CODE
	mov	dpl,a
	mov	a,r5
	addc	a, #(_DIGIT_CODE >> 8)
	mov	dph,a
	clr	a
	movc	a,@a+dptr
	mov	(_LED + 0x0006), a
;	main.c:15: LED[5]= DIGIT_CODE[ (C>>8) & 0xF];
	mov	ar5,r7
	anl	ar5,#0x0f
	mov	r4,#0x00
	mov	a,r5
	add	a, #_DIGIT_CODE
	mov	dpl,a
	mov	a,r4
	addc	a, #(_DIGIT_CODE >> 8)
	mov	dph,a
	clr	a
	movc	a,@a+dptr
	mov	(_LED + 0x0005), a
;	main.c:16: LED[4]= DIGIT_CODE[ (C>>12) & 0xF];
	mov	a,r7
	swap	a
	anl	a,#0x0f
	mov	r6,a
	anl	ar6,#0x0f
	mov	r7,#0x00
	mov	a,r6
	add	a, #_DIGIT_CODE
	mov	dpl,a
	mov	a,r7
	addc	a, #(_DIGIT_CODE >> 8)
	mov	dph,a
	clr	a
	movc	a,@a+dptr
	mov	(_LED + 0x0004), a
;	main.c:17: LED[3]= DIGIT_CODE[ (C>>16) & 0xF];
	mov	dptr,#_DIGIT_CODE
	clr	a
	movc	a,@a+dptr
	mov	(_LED + 0x0003), a
;	main.c:18: LED[2]= DIGIT_CODE[ (C>>20) & 0xF];
	mov	dptr,#_DIGIT_CODE
	clr	a
	movc	a,@a+dptr
	mov	(_LED + 0x0002), a
;	main.c:19: LED[1]= DIGIT_CODE[ (C>>24) & 0xF];
	mov	dptr,#_DIGIT_CODE
	clr	a
	movc	a,@a+dptr
	mov	(_LED + 0x0001), a
;	main.c:20: LED[0]= DIGIT_CODE[ (C>>28) & 0xF];
	mov	dptr,#_DIGIT_CODE
	clr	a
	movc	a,@a+dptr
	mov	_LED, a
;	main.c:21: Disp8leds7seg(1000);
	mov	dptr,#0x03e8
	lcall	_Disp8leds7seg
;	main.c:24: return 0;
;	main.c:25: }
	ljmp	00102$
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area CONST   (CODE)
_DIGIT_CODE:
	.db #0x3f	; 63
	.db #0x06	; 6
	.db #0x5b	; 91
	.db #0x4f	; 79	'O'
	.db #0x66	; 102	'f'
	.db #0x6d	; 109	'm'
	.db #0x7d	; 125
	.db #0x07	; 7
	.db #0x7f	; 127
	.db #0x6f	; 111	'o'
	.db #0x77	; 119	'w'
	.db #0x7c	; 124
	.db #0x58	; 88	'X'
	.db #0x5e	; 94
	.db #0x79	; 121	'y'
	.db #0x71	; 113	'q'
	.area CSEG    (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
