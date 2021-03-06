#ifndef __PL111_H
#define __PL111_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "device.h"

/* The ARM PrimeCell ColorLCD Controller (PL111) is documented at
 *
 * http://infocenter.arm.com/help/topic/com.arm.doc.ddi0293c/index.html
 *
 * In particular, Section 3 explains the programmer's model, i.e., how to
 * interact with it: this includes
 *
 * - Section 3.2, which summarises the device register layout in Table 3.1
 *   (including an offset from the device base address, in the memory map,
 *   for each register), and
 * - Section 3.3, which summarises the internal structure of each device
 *   register.
 *
 * Note that the field identifiers used here follow the documentation in a
 * general sense, but with a some minor alterations to improve clarity and
 * consistency.
 */

typedef struct {
          RW uint32_t LCDTiming0;           // 0x0000          : horizontal axis
          RW uint32_t LCDTiming1;           // 0x0004          : vertical   axis
          RW uint32_t LCDTiming2;           // 0x0008          : clock and signal polarity
          RW uint32_t LCDTiming3;           // 0x000C          : line end
          RW uint32_t LCDUPBASE;            // 0x0010          : upper panel base    address
          RW uint32_t LCDLPBASE;            // 0x0014          : lower panel base    address
          RW uint32_t LCDControl;           // 0x0018          : control
          RW uint32_t LCDIMSC;              // 0x001C          :               interrupt mask
          RO uint32_t LCDRIS;               // 0x0020          :        raw    interrupt status
          RO uint32_t LCDMIS;               // 0x0024          :        masked interrupt status
          WO uint32_t LCDICR;               // 0x0028          :               interrupt clear
          RO uint32_t LCDUPCURR;            // 0x002C          : upper panel current address
          RO uint32_t LCDLPCURR;            // 0x0030          : lower panel current address
          RO RSVD( 0, 0x0034, 0x01FC );     // 0x0034...0x01FC : reserved
          RW uint16_t LCDPalette[ 256 ];    // 0x0200...0x03FC : color palette
          RO RSVD( 1, 0x0400, 0x07FC );     // 0x0400...0x07FC : reserved
          RW uint32_t ClcdCrsrImage[ 256 ]; // 0x0800...0x0BFC : cursor image
          RW uint32_t ClcdCrsrCtrl;         // 0x0C00          : cursor control
          RW uint32_t ClcdCrsrConfig;       // 0x0C04          : cursor configuration
          RW uint32_t ClcdCrsrPalette0;     // 0x0C08...0x0C0C : cursor palette
          RW uint32_t ClcdCrsrPalette1;     // 0x0C08...0x0C0C : cursor palette
          RW uint32_t ClcdCrsrXY;           // 0x0C10          : cursor      position
          RW uint32_t ClcdCrsrClip;         // 0x0C14          : cursor clip position
          RO RSVD( 2, 0x0C18, 0x0C1C );     // 0x0C18...0x0C1C : reserved
          RW uint32_t ClcdCrsrIMSC;         // 0x0C20          : cursor        interrupt mask
          WO uint32_t ClcdCrsrICR;          // 0x0C24          : cursor        interrupt clear
          RO uint32_t ClcdCrsrRIS;          // 0x0C28          : cursor raw    interrupt status
          RO uint32_t ClcdCrsrMIS;          // 0x0C2C          : cursor masked interrupt status
          RO RSVD( 3, 0x0C30, 0x0DFC );     // 0x0C30...0x0DFC : reserved
          RO RSVD( 4, 0x0F00, 0x0F08 );     // 0x0F00...0x0F08 : reserved
          RO RSVD( 5, 0x0F0C, 0x0FDC );     // 0x0F0C...0x0FDC : reserved
          RO uint32_t PeriphID0;            // 0x0FE0          : peripheral ID
          RO uint32_t PeriphID1;            // 0x0FE4          : peripheral ID
          RO uint32_t PeriphID2;            // 0x0FE8          : peripheral ID
          RO uint32_t PeriphID3;            // 0x0FEC          : peripheral ID
          RO uint32_t  PCellID0;            // 0x0FF0          : PrimeCell  ID
          RO uint32_t  PCellID1;            // 0x0FF4          : PrimeCell  ID
          RO uint32_t  PCellID2;            // 0x0FF8          : PrimeCell  ID
          RO uint32_t  PCellID3;            // 0x0FFC          : PrimeCell  ID
} PL111_t;

/* Per Table 4.2 (for example: the information is in several places) of
 *
 * http://infocenter.arm.com/help/topic/com.arm.doc.dui0417d/index.html
 *
 * we know the registers are mapped to fixed addresses in memory, so we
 * can just define a (structured) pointer to each one to support access.
 */

extern PL111_t* LCD;

#endif
