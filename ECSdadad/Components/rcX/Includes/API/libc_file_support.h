/**************************************************************************************
 
   Copyright (c) Hilscher GmbH. All Rights Reserved.
 
 **************************************************************************************
 
   Filename:
    $Workfile: libc_file_support.h $
   Last Modification:
    $Author: MichaelT $
    $Modtime: 1.02.07 17:11 $
    $Revision: 903 $
   
   Targets:
     Win32/ANSI   : yes
     Win32/Unicode: yes (define _UNICODE)
     WinCE        : no
 
   Description:
   libc_file_support.h  Registration of debug output drivers for libc printf, etc.
       
   Changes:
 
     Version   Date        Author   Description
     ----------------------------------------------------------------------------------
      1        07.12.2006  MT       initial version
 
**************************************************************************************/

/*****************************************************************************/
/*! \file libc_file_support.h                                                    
*   Registration of debug output drivers for libc printf, etc.               */
/*****************************************************************************/

#ifndef __LIBC_FILE_SUPPORT__H
#define __LIBC_FILE_SUPPORT__H

#define FILE_HANDLER_STDIN    0
#define FILE_HANDLER_STDOUT   1
#define FILE_HANDLER_STDERR   2
#define FILE_HANDLER_DEFAULT  3

#define READ_NO_DATA    -1

typedef void(*PFN_WRITE)(const void* pvBuffer, unsigned long ulSize, void* pvUser);
typedef int(*PFN_READ)(void* pvBuffer, unsigned long* pulSize, void* pvUser);

void libc_file_init();

void Libc_RegisterStdOutFileHook(int fError, PFN_WRITE pfnWrite, void* pvUser);
void Libc_RegisterStdInFileHook(PFN_READ pfnRead, void* pvUser);


#endif /* __LIBC_FILE_SUPPORT__H */
