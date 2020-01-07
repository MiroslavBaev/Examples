/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: AtomicsGnu.h 903 2012-05-02 12:09:19Z MichaelT $

  Description:
    Atomic operations for GNU

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-24  NC            File created.

******************************************************************************/


#ifndef _atomics_h
#define _atomics_h

/******************************************************************************
 * Lock/Unlock Irq                                                            *
 ******************************************************************************/

#ifdef __thumb__

  #define lock_irq_save(x)    (x = rX_SysLockIrq())
  #define lock_irq_restore(x) if(0 == (x & 0x80)) \
                                rX_SysUnlockIrq()

#else

#define lock_irq_save(x)                                \
        ({                                              \
                register unsigned int cpsr_tmp;         \
                __asm__ __volatile__(                   \
                        "MRS %1, cpsr\n"                \
                        "AND %0, %1, #128\n"            \
                        "ORR %1, %1, #128\n"            \
                        "MSR CPSR_c, %1"                \
                        : "=r" (x), "=&r" (cpsr_tmp)    \
                );                                      \
        })

#define lock_irq_restore(x)                             \
        ({                                              \
                register unsigned int cpsr_tmp;         \
                __asm__ __volatile__(                   \
                        "MRS %0, cpsr\n"                \
                        "EOR %0, %0, #128\n"            \
                        "ORR %0, %0, %1\n"              \
                        "MSR CPSR_c, %0"                \
                        : "=&r" (cpsr_tmp)              \
                        : "r" (x)                       \
                );                                      \
        })

#endif

/******************************************************************************
 * Atomic operations                                                          *
 ******************************************************************************/

#ifdef __thumb__

/* void interlocked_assign((unsigned int*) cell, unsigned int value); */

#define interlocked_assign(cell, value) \
  *(cell) = value

/* void interlocked_uint32_assign((UINT32*) cell, unsigned int value); */

#define interlocked_uint32_assign(cell, value) \
  *(cell) = value

/* void interlocked_pointer_assign((VOID**) cell, void* value); */

#define interlocked_pointer_assign(cell, value) \
  *(cell) = value

/* unsigned int interlocked_get((unsigned int*) cell); */

#define interlocked_get(cell) \
  *(cell)

/* UINT32 interlocked_uint32_get((UINT32*) cell); */

#define interlocked_uint32_get(cell) \
  *(cell)

/* UINT32 interlocked_pointer_get((VOID**) cell); */

#define interlocked_pointer_get(cell) \
  *(cell)

/* void interlocked_exchange(unsigned int* xchange_cell, unsigned int &value); */

#define interlocked_exchange(xchange_cell, value)       \
        ({                                              \
                register unsigned int tmp2;             \
                __asm__ __volatile__(                   \
                        "ADD  %1, PC, #4\n"             \
                        "BX   %1\n"                     \
                        "NOP\n"                         \
                        ".arm\n"                        \
                        "SWP  %0, %3, [%2]\n"           \
                        "ADD  %1, PC, #1\n"             \
                        "BX   %1\n"                     \
                        ".thumb\n"                      \
                        : "=&l" (value), "=&l" (tmp2)    \
                        : "l" (xchange_cell), "l" (value) \
                );                                      \
        })

/* void interlocked_pointer_exchange(void** cell, void* value) */

#define interlocked_pointer_exchange(cell, value)       \
        {                                               \
                register unsigned int tmp2;             \
                __asm__ __volatile__(                   \
                        "ADD    %1, PC, #4\n"           \
                        "BX     %1\n"                   \
                        "NOP\n"                         \
                        ".arm\n"                        \
                        "SWP    %0, %3, [%2]\n"         \
                        "ADD    %1, PC, #1\n"           \
                        "BX     %1\n"                   \
                        ".thumb\n"                      \
                        : "=&l" (value), "=&l" (tmp2)   \
                        : "l" (cell), "l" (value)       \
                );                                      \
        }

/* void interlocked_increment(unsigned int* v_adr); */

#define interlocked_increment(v_adr)                    \
        ({                                              \
                register unsigned int cpsr_tmp;         \
                register unsigned int tmp2;             \
                __asm__ __volatile__(                   \
                        "ADD    %1, PC, #4\n"           \
                        "BX     %1\n"                   \
                        "NOP\n"                         \
                        ".arm\n"                        \
                        "MRS    %0, CPSR\n"             \
                        "ORR    %1, %0, #128\n"         \
                        "MSR    CPSR, %1\n"             \
                        "LDR    %1, [%2]\n"             \
                        "ADD    %1, %1, #1\n"           \
                        "STR    %1, [%2]\n"             \
                        "MSR    CPSR, %0\n"             \
                        "ADD    %1, PC, #1\n"           \
                        "BX     %1\n"                   \
                        ".thumb\n"                      \
                        : "=&r" (cpsr_tmp), "=&r" (tmp2)\
                        : "r" (v_adr)                   \
                );                                      \
              })

/* void interlocked_uint32_increment(UINT32* v_adr); */

#define interlocked_uint32_increment(v_adr)             \
        ({                                              \
                register unsigned int cpsr_tmp;         \
                register unsigned int tmp2;             \
                __asm__ __volatile__(                   \
                        "ADD    %1, PC, #4\n"           \
                        "BX     %1\n"                   \
                        "NOP\n"                         \
                        ".arm\n"                        \
                        "MRS    %0, CPSR\n"             \
                        "ORR    %1, %0, #128\n"         \
                        "MSR    CPSR, %1\n"             \
                        "LDR    %1, [%2]\n"             \
                        "ADD    %1, %1, #1\n"           \
                        "STR    %1, [%2]\n"             \
                        "MSR    CPSR, %0\n"             \
                        "ADD    %1, PC, #1\n"           \
                        "BX     %1\n"                   \
                        ".thumb\n"                      \
                        : "=&r" (cpsr_tmp), "=&r" (tmp2)\
                        : "r" (v_adr)                   \
                );                                      \
              })

/* void interlocked_decrement(unsigned int* v_adr); */

#define interlocked_decrement(v_adr)                    \
        ({                                              \
                register unsigned int cpsr_tmp;         \
                register unsigned int tmp2;             \
                __asm__ __volatile__(                   \
                        "ADD    %1, PC, #4\n"           \
                        "BX     %1\n"                   \
                        "NOP\n"                         \
                        ".arm\n"                        \
                        "MRS    %0, CPSR\n"             \
                        "ORR    %1, %0, #128\n"         \
                        "MSR    CPSR, %1\n"             \
                        "LDR    %1, [%2]\n"             \
                        "SUB    %1, %1, #1\n"           \
                        "STR    %1, [%2]\n"             \
                        "MSR    CPSR, %0\n"             \
                        "ADD    %1, PC, #1\n"           \
                        "BX     %1\n"                   \
                        ".thumb\n"                      \
                        : "=&r" (cpsr_tmp), "=&r" (tmp2)\
                        : "r" (v_adr)                   \
                );                                      \
              })

/* void interlocked_increment_return (unsigned int* v_adr, unsigned int* oldvalue); */

#define interlocked_increment_return(v_adr, oldvalue)   \
        ({                                              \
                register unsigned int cpsr_tmp;         \
                register unsigned int tmp2;             \
                __asm__ __volatile__(                   \
                        "ADD    %1, PC, #4\n"           \
                        "BX     %1\n"                   \
                        "NOP\n"                         \
                        ".arm\n"                        \
                        "MRS    %0, CPSR\n"             \
                        "ORR    %1, %0, #128\n"         \
                        "MSR    CPSR, %1\n"             \
                        "LDR    %1, [%2]\n"             \
                        "STR    %1, [%3]\n"             \
                        "ADD    %1, %1, #1\n"           \
                        "STR    %1, [%2]\n"             \
                        "MSR    CPSR, %0\n"             \
                        "ADD    %1, PC, #1\n"           \
                        "BX     %1\n"                   \
                        ".thumb\n"                      \
                        : "=&r" (cpsr_tmp), "=&r" (tmp2)\
                        : "r" (v_adr), "r" (oldvalue)   \
                );                                      \
              })

/* void interlocked_decrement_return (unsigned int* v_adr, unsigned int* oldvalue); */

#define interlocked_decrement_return(v_adr, oldvalue)   \
        ({                                              \
                register unsigned int cpsr_tmp;         \
                register unsigned int tmp2;             \
                __asm__ __volatile__(                   \
                        "ADD    %1, PC, #4\n"           \
                        "BX     %1\n"                   \
                        "NOP\n"                         \
                        ".arm\n"                        \
                        "MRS    %0, CPSR\n"             \
                        "ORR    %1, %0, #128\n"         \
                        "MSR    CPSR, %1\n"             \
                        "LDR    %1, [%2]\n"             \
                        "STR    %1, [%3]\n"             \
                        "SUB    %1, %1, #1\n"           \
                        "STR    %1, [%2]\n"             \
                        "MSR    CPSR, %0\n"             \
                        "ADD    %1, PC, #1\n"           \
                        "BX     %1\n"                   \
                        ".thumb\n"                      \
                        : "=&r" (cpsr_tmp), "=&r" (tmp2)\
                        : "r" (v_adr), "r" (oldvalue)   \
                );                                      \
              })

/* void interlocked_set (unsigned int* v_adr, unsigned int mask); */

#define interlocked_set(v_adr, mask)                    \
        ({                                              \
                register unsigned int cpsr_tmp;         \
                register unsigned int tmp2;             \
                __asm__ __volatile__(                   \
                        "ADD    %1, PC, #4\n"           \
                        "BX     %1\n"                   \
                        "NOP\n"                         \
                        ".arm\n"                        \
                        "MRS    %0, CPSR\n"             \
                        "ORR    %1, %0, #128\n"         \
                        "MSR    CPSR, %1\n"             \
                        "LDR    %1, [%2]\n"             \
                        "ORR    %1, %1, %3\n"           \
                        "STR    %1, [%2]\n"             \
                        "MSR    CPSR, %0\n"             \
                        "ADD    %1, PC, #1\n"           \
                        "BX     %1\n"                   \
                        ".thumb\n"                      \
                        : "=&r" (cpsr_tmp), "=&r" (tmp2)\
                        : "r" (v_adr), "r" (mask)       \
                );                                      \
              })

/* void interlocked_clear (unsigned int* v_adr, unsigned int mask); */

#define interlocked_clear(v_adr, mask)                  \
        ({                                              \
                register unsigned int cpsr_tmp;         \
                register unsigned int tmp2;             \
                __asm__ __volatile__(                   \
                        "ADD    %1, PC, #4\n"           \
                        "BX     %1\n"                   \
                        "NOP\n"                         \
                        ".arm\n"                        \
                        "MRS    %0, CPSR\n"             \
                        "ORR    %1, %0, #128\n"         \
                        "MSR    CPSR, %1\n"             \
                        "LDR    %1, [%2]\n"             \
                        "BIC    %1, %1, %3\n"           \
                        "STR    %1, [%2]\n"             \
                        "MSR    CPSR, %0\n"             \
                        "ADD    %1, PC, #1\n"           \
                        "BX     %1\n"                   \
                        ".thumb\n"                      \
                        : "=&r" (cpsr_tmp), "=&r" (tmp2)\
                        : "r" (v_adr), "r" (mask)       \
                );                                      \
              })

/* void interlocked_set_return (unsigned int* v_adr, unsigned int mask, unsigned int* oldvalue); */

#define interlocked_set_return(v_adr, mask, oldvalue)   \
        ({                                              \
                register unsigned int cpsr_tmp;         \
                register unsigned int tmp2;             \
                __asm__ __volatile__(                   \
                        "ADD    %1, PC, #4\n"           \
                        "BX     %1\n"                   \
                        "NOP\n"                         \
                        ".arm\n"                        \
                        "MRS    %0, CPSR\n"             \
                        "ORR    %1, %0, #128\n"         \
                        "MSR    CPSR, %1\n"             \
                        "LDR    %1, [%2]\n"             \
                        "STR    %1, [%4]\n"             \
                        "ORR    %1, %1, %3\n"           \
                        "STR    %1, [%2]\n"             \
                        "MSR    CPSR, %0\n"             \
                        "ADD    %1, PC, #1\n"           \
                        "BX     %1\n"                   \
                        ".thumb\n"                      \
                        : "=&r" (cpsr_tmp), "=&r" (tmp2)\
                        : "r" (v_adr), "r" (mask), "r" (oldvalue) \
                );                                      \
              })

/* void interlocked_clear_return (unsigned int* v_adr, unsigned int mask, unsigned int* oldvalue); */

#define interlocked_clear_return(v_adr, mask, oldvalue) \
        ({                                              \
                register unsigned int cpsr_tmp;         \
                register unsigned int tmp2;             \
                __asm__ __volatile__(                   \
                        "ADD    %1, PC, #4\n"           \
                        "BX     %1\n"                   \
                        "NOP\n"                         \
                        ".arm\n"                        \
                        "MRS    %0, CPSR\n"             \
                        "ORR    %1, %0, #128\n"         \
                        "MSR    CPSR, %1\n"             \
                        "LDR    %1, [%2]\n"             \
                        "STR    %1, [%4]\n"             \
                        "BIC    %1, %1, %3\n"           \
                        "STR    %1, [%2]\n"             \
                        "MSR    CPSR, %0\n"             \
                        "ADD    %1, PC, #1\n"           \
                        "BX     %1\n"                   \
                        ".thumb\n"                      \
                        : "=&r" (cpsr_tmp), "=&r" (tmp2)\
                        : "l" (v_adr), "l" (mask), "l" (oldvalue) \
                );                                      \
              })

#else

/* void interlocked_assign((unsigned int*) cell, unsigned int value); */

#define interlocked_assign(cell, value) \
  *(cell) = value

/* void interlocked_uint32_assign((UINT32*) cell, unsigned int value); */

#define interlocked_uint32_assign(cell, value) \
  *(cell) = value

/* void interlocked_pointer_assign((VOID**) cell, void* value); */

#define interlocked_pointer_assign(cell, value) \
  *(cell) = value

/* unsigned int interlocked_get((unsigned int*) cell); */

#define interlocked_get(cell) \
  *(cell)

/* UINT32 interlocked_uint32_get((UINT32*) cell); */

#define interlocked_uint32_get(cell) \
  *(cell)

/* void* interlocked_pointer_get((void**) cell); */

#define interlocked_pointer_get(cell) \
  *(cell)

/* void interlocked_exchange (unsigned int* xchange_cell, unsigned int& value); */

#define interlocked_exchange(xchange_cell, value)       \
        ({                                              \
                __asm__ __volatile__(                   \
                        "SWP  %0, %2, [%1]\n"           \
                        : "=&r" (value)                  \
                        : "r" (xchange_cell), "r" (value) \
                );                                      \
        })

/* void interlocked_pointer_exchange(void** cell, void* value) */

#define interlocked_pointer_exchange(cell, value)       \
        {                                               \
                __asm__ __volatile__(                   \
                        "SWP    %0, %2, [%1]\n"         \
                        : "=&r" (value)                 \
                        : "r" (cell), "r" (value)       \
                );                                      \
        }

/* void interlocked_increment (unsigned int* v_adr); */

#define interlocked_increment(v_adr)                    \
        ({                                              \
                register unsigned int cpsr_tmp;         \
                register unsigned int tmp2;             \
                __asm__ __volatile__(                   \
                        "MRS    %0, CPSR\n"             \
                        "ORR    %1, %0, #128\n"         \
                        "MSR    CPSR, %1\n"             \
                        "LDR    %1, [%2]\n"             \
                        "ADD    %1, %1, #1\n"           \
                        "STR    %1, [%2]\n"             \
                        "MSR    CPSR, %0\n"             \
                        : "=&r" (cpsr_tmp), "=&r" (tmp2)\
                        : "r" (v_adr) \
                );                                      \
        })

/* void interlocked_uint32_increment (unsigned int* v_adr); */

#define interlocked_uint32_increment(v_adr)             \
        ({                                              \
                register unsigned int cpsr_tmp;         \
                register unsigned int tmp2;             \
                __asm__ __volatile__(                   \
                        "MRS    %0, CPSR\n"             \
                        "ORR    %1, %0, #128\n"         \
                        "MSR    CPSR, %1\n"             \
                        "LDR    %1, [%2]\n"             \
                        "ADD    %1, %1, #1\n"           \
                        "STR    %1, [%2]\n"             \
                        "MSR    CPSR, %0\n"             \
                        : "=&r" (cpsr_tmp), "=&r" (tmp2)\
                        : "r" (v_adr) \
                );                                      \
        })

/* void interlocked_decrement (unsigned int* v_adr); */

#define interlocked_decrement(v_adr)                    \
        ({                                              \
                register unsigned int cpsr_tmp;         \
                register unsigned int tmp2;             \
                __asm__ __volatile__(                   \
                        "MRS    %0, CPSR\n"             \
                        "ORR    %1, %0, #128\n"         \
                        "MSR    CPSR, %1\n"             \
                        "LDR    %1, [%2]\n"             \
                        "SUB    %1, %1, #1\n"           \
                        "STR    %1, [%2]\n"             \
                        "MSR    CPSR, %0\n"             \
                        : "=&r" (cpsr_tmp), "=&r" (tmp2)\
                        : "r" (v_adr) \
                );                                      \
        })

/* void interlocked_increment_return (unsigned int* v_adr, unsigned int* oldvalue); */

#define interlocked_increment_return(v_adr, oldvalue)   \
        ({                                              \
                register unsigned int cpsr_tmp;         \
                register unsigned int tmp2;             \
                __asm__ __volatile__(                   \
                        "MRS    %0, CPSR\n"             \
                        "ORR    %1, %0, #128\n"         \
                        "MSR    CPSR, %1\n"             \
                        "LDR    %1, [%2]\n"             \
                        "STR    %1, [%3]\n"             \
                        "ADD    %1, %1, #1\n"           \
                        "STR    %1, [%2]\n"             \
                        "MSR    CPSR, %0\n"             \
                        : "=&r" (cpsr_tmp), "=&r" (tmp2)\
                        : "r" (v_adr), "r" (oldvalue)   \
                );                                      \
        })

/* void interlocked_decrement_return (unsigned int* v_adr, unsigned int* oldvalue); */

#define interlocked_decrement_return(v_adr, oldvalue)   \
        ({                                              \
                register unsigned int cpsr_tmp;         \
                register unsigned int tmp2;             \
                __asm__ __volatile__(                   \
                        "MRS    %0, CPSR\n"             \
                        "ORR    %1, %0, #128\n"         \
                        "MSR    CPSR, %1\n"             \
                        "LDR    %1, [%2]\n"             \
                        "STR    %1, [%3]\n"             \
                        "SUB    %1, %1, #1\n"           \
                        "STR    %1, [%2]\n"             \
                        "MSR    CPSR, %0\n"             \
                        : "=&r" (cpsr_tmp), "=&r" (tmp2)\
                        : "r" (v_adr), "r" (oldvalue)   \
                );                                      \
        })

/* void interlocked_set (unsigned int* v_adr, unsigned int mask); */

#define interlocked_set(v_adr, mask)                    \
        ({                                              \
                register unsigned int cpsr_tmp;         \
                register unsigned int tmp2;             \
                __asm__ __volatile__(                   \
                        "MRS    %0, CPSR\n"             \
                        "ORR    %1, %0, #128\n"         \
                        "MSR    CPSR, %1\n"             \
                        "LDR    %1, [%2]\n"             \
                        "ORR    %1, %1, %3\n"           \
                        "STR    %1, [%2]\n"             \
                        "MSR    CPSR, %0\n"             \
                        : "=&r" (cpsr_tmp), "=&r" (tmp2)\
                        : "r" (v_adr), "r" (mask)       \
                );                                      \
        })

/* void interlocked_clear (unsigned int* v_adr, unsigned int mask); */

#define interlocked_clear(v_adr, mask)                  \
        ({                                              \
                register unsigned int cpsr_tmp;         \
                register unsigned int tmp2;             \
                __asm__ __volatile__(                   \
                        "MRS    %0, CPSR\n"             \
                        "ORR    %1, %0, #128\n"         \
                        "MSR    CPSR, %1\n"             \
                        "LDR    %1, [%2]\n"             \
                        "BIC    %1, %1, %3\n"           \
                        "STR    %1, [%2]\n"             \
                        "MSR    CPSR, %0\n"             \
                        : "=&r" (cpsr_tmp), "=&r" (tmp2)\
                        : "r" (v_adr), "r" (mask)       \
                );                                      \
        })

/* void interlocked_set_return (unsigned int* v_adr, unsigned int mask, unsigned int* oldvalue); */

#define interlocked_set_return(v_adr, mask, oldvalue)   \
        ({                                              \
                register unsigned int cpsr_tmp;         \
                register unsigned int tmp2;             \
                __asm__ __volatile__(                   \
                        "MRS    %0, CPSR\n"             \
                        "ORR    %1, %0, #128\n"         \
                        "MSR    CPSR, %1\n"             \
                        "LDR    %1, [%2]\n"             \
                        "STR    %1, [%4]\n"             \
                        "ORR    %1, %1, %3\n"           \
                        "STR    %1, [%2]\n"             \
                        "MSR    CPSR, %0\n"             \
                        : "=&r" (cpsr_tmp), "=&r" (tmp2)\
                        : "r" (v_adr), "r" (mask), "r" (oldvalue) \
                );                                      \
        })

/* void interlocked_clear_return (unsigned int* v_adr, unsigned int mask, unsigned int* oldvalue); */

#define interlocked_clear_return(v_adr, mask, oldvalue) \
        ({                                              \
                register unsigned int cpsr_tmp;         \
                register unsigned int tmp2;             \
                __asm__ __volatile__(                   \
                        "MRS    %0, CPSR\n"             \
                        "ORR    %1, %0, #128\n"         \
                        "MSR    CPSR, %1\n"             \
                        "LDR    %1, [%2]\n"             \
                        "STR    %1, [%4]\n"             \
                        "BIC    %1, %1, %3\n"           \
                        "STR    %1, [%2]\n"             \
                        "MSR    CPSR, %0\n"             \
                        : "=&r" (cpsr_tmp), "=&r" (tmp2)\
                        : "r" (v_adr), "r" (mask), "r" (oldvalue) \
                );                                      \
        })

#endif

#endif
