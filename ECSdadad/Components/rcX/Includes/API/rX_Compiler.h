/*******************************************************************************

   Copyright (c) Hilscher GmbH. All Rights Reserved.

 *******************************************************************************

   Filename:
    $Id: rX_Compiler.h 903 2012-05-02 12:09:19Z MichaelT $
   Last Modification:
    $Author: MichaelT $
    $Date: 2012-05-02 14:09:19 +0200 (Wed, 02 May 2012) $
    $Revision: 903 $

   Targets:
     rcX      : yes

   Description:
      rcX definitions for custom compilers (packed / far, etc.)

  Functions:

   Changes:

     Version   Date        Author   Description
     ---------------------------------------------------------------------------
      1       20.05.2011   MT       ported from rcX V2

*******************************************************************************/

#ifndef __RX_COMPILER_H
#define __RX_COMPILER_H

#ifdef INLINE
  #undef INLINE
#endif

#ifdef EXTERN
  #undef EXTERN
#endif

#ifdef CALLBACK
  #undef CALLBACK
#endif

#ifdef INTERRUPT
  #undef INTERRUPT
#endif


/* Definitions for backward compatibility only !!! */
#define EXTERN extern
#define STATIC static
#define CONST const
#define STRLEN strlen
#define STRUPR strupr
#define STRCPY strcpy
#define STRNCPY strncpy
#define STRNCMP strncmp
#define STRCMP strcmp
#define MEMCPY memcpy
#define MEMMOVE memmove
#define MEMCMP memcmp
#define MEMSET memset  
/* Definitions for backward compatibility only !!! */


#if defined(__ADS__) || defined (__REALVIEW__)
  /* ARM Realview compiler */
  #define HUGE
  #define FAR
  #define NEAR
  #define INTERRUPT __irq
  #define CALLBACK
  #define __PACKED_PRE __packed
  #define __PACKED_POST
  #define __ALIGN4_PRE  __align(4)
  #define __ALIGN4_POST
  #define PRAGMA_PACK_1(label)
  #define PRAGMA_UNPACK_1(label)
  #define INLINE __inline

#elif defined(_CONSOLE_16_)
  #define HUGE huge
  #define FAR
  #define NEAR   near
  #define INTERRUPT __interrupt
  #define CALLBACK
  #define __PACKED_PRE
  #define __PACKED_POST
  #define __ALIGN4_PRE
  #define __ALIGN4_POST
  #define PRAGMA_PACK_1(label)
  #define PRAGMA_UNPACK_1(label)

#elif defined(_CONSOLE)
  /* PC-Console and compatibles */
  #include <windows.h>

  #define PRAGMA_PACK_ENABLE
  #ifndef CALLBACK
    #define CALLBACK _stdcall
  #endif
  #ifndef _WINNT_
    #define FAR
  #endif
  #define HUGE
  #define INTERRUPT
  #define __PACKED_PRE
  #define __PACKED_POST
  #define __ALIGN4_PRE
  #define __ALIGN4_POST
  #define PRAGMA_PACK_1(label) pack(push, label, 1)
  #define PRAGMA_UNPACK_1(label) pack(pop, label)
  #define INLINE __inline

#elif defined(__GNUC__)
  /* GNU GCC and compatibles */
  #define HUGE
  #define FAR
  #define NEAR
  #define INTERRUPT     __attribute__ ((interrupt ("IRQ")))
  #define INTERRUPT_FIQ __attribute__ ((interrupt ("FIQ")))
  #define CALLBACK
  #define __PACKED_PRE
  #define __PACKED_POST __attribute__ ((__packed__))
  #define __ALIGN4_PRE
  #define __ALIGN4_POST __attribute__ ((aligned(4)))
  #define PRAGMA_PACK_1(label)
  #define PRAGMA_UNPACK_1(label)
  #define INLINE static inline

#endif

#endif /* __RX_COMPILER_H */
