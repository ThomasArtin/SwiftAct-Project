/* 
 * File:   7seg.h
 * Author: thomas
 *
 * Created on July 1, 2020, 2:07 PM
 */
#ifndef SEG_H
#define	SEG_H

#define _XTAL_FREQ 20000000 


#define Seg_zero     0b00111111
#define Seg_one      0b00000110
#define Seg_two      0b01011011
#define Seg_three    0b01001111
#define Seg_four     0b01100110
#define Seg_five     0b01101101
#define Seg_six      0b01111101
#define Seg_seven    0b00000111
#define Seg_eight    0b01111111
#define Seg_nine     0b01101111
#define Seg_Dot      0b10000000
#define Seg_NoDot    0b00000000
/*Configure 7seg display controllers and display port*/
#define NumOfDisp 3
#define Seg_Disp2 A3
#define Seg_Disp3 A4
#define Seg_Disp4 A5
#define Seg_Port  DIOPORTD

extern void Seg_Disp2Dig   (uint_16 DispValue);
extern void Seg_DispNumber  (uint_8 Display,uint_8 Number, uint_8 Dot);
extern void Seg_Init        (void);
#endif	/* SEG_H */

