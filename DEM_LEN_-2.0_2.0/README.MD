## NOTE:
Count from -2.0 to 2.0, step = 0.1.
### <1>
To simplify the steps, the range is multiplied to 10 (zoom x10).
The the range from -2.0 -> 2.0 (step=0.1) now is -20 to 20 (step=1).
### <2>
To disp play -2.0, we need at least 3 LED 7seg (with DP). One for "-" (CC code: 0x40), One for "2." "1." "0." and the last one for "0", "1", ..., "9".
### <3>
To disp play -2.0, we display sequence each 7-seg LED, and repeat for at least 24 time in sec to make sure moothly.The disp time for each LED calc by 1/(Freq*no.LEDs).
<br>
EX:<br>
Freq = 24Hz, no.LEDs is 3 then disp_time = 1/(24*3) = 0.0138888889 sec = 14 mili-sec.
