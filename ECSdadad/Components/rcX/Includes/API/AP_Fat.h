/******************************************************************************

  Copyright (C) 2010 [Hilscher Gesellschaft für Systemautomation mbH]

  This program can be used by everyone according to the netX Open Source
  Software license. The license agreement can be downloaded from
  http://www.industrialNETworX.com

*******************************************************************************

  Last Modification:
    @version $Id: AP_Fat.h 1705 2014-02-19 08:22:07Z MichaelT $

  Description:
    Standardized definitions of for FAT16/32 File System handling

  Changes:
    Date        Author        Description
  ---------------------------------------------------------------------------
    2010-03-23  NC            File created.

******************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif

#ifndef __AP_FAT_H
  #define __AP_FAT_H

  enum MID_FAT_TYPEtag {
    MID_FAT_TYPE_12,
    MID_FAT_TYPE_16,
    MID_FAT_TYPE_32,
    MID_FAT_TYPE_AUTO
  };
  typedef UINT8 MID_FAT_TYPE;

  #define MID_FAT_TYPE_QUICKFORMAT  (0x80)

  enum MID_FAT_SEEK_TYPEtag {
    MID_FAT_SEEK_TYPE_SET,
    MID_FAT_SEEK_TYPE_CUR,
    MID_FAT_SEEK_TYPE_END
  };
  typedef int MID_FAT_SEEK_TYPE;

  enum MID_FAT_FILEACCESStag {
    MID_FAT_FILEACCESS_NORMAL = 0,
    MID_FAT_FILEACCESS_READONLY = 1,
  };
  typedef int MID_FAT_FILEACCESS;

  #define MID_FAT_FILEATTRIBUTE_STANDARD  0x00
  #define MID_FAT_FILEATTRIBUTE_READONLY  0x01
  #define MID_FAT_FILEATTRIBUTE_HIDDEN    0x02
  #define MID_FAT_FILEATTRIBUTE_SYSTEM    0x04
  #define MID_FAT_FILEATTRIBUTE_VOLUME    0x08
  #define MID_FAT_FILEATTRIBUTE_DIRECTORY 0x10
  #define MID_FAT_FILEATTRIBUTE_ARCHIVE   0x20


  typedef struct DIR_INFORMATION_Ttag {
    UINT8 abNam[8];         /* filename, blank filled if less than 8 */
    UINT8 abExt[3];         /* extension, blank filled if less than 3 */
    UINT8 bFilAttr;         /* file attributes, see definitions */
    UINT8 bCrtHundredth;    /* hundredth of seconds of creation time */
    UINT8 abCrtTim[2];      /* creation time */
    UINT8 abCrtDat[2];      /* creation date */
    UINT8 abAccDat[2];      /* access date */
    UINT8 abModTim[2];      /* last modification time */
    UINT8 abModDat[2];      /* last modification date */
    UINT32 ulFilSiz;        /* size of the file in bytes */
  } DIR_INFORMATION_T;



    RX_RESULT FAR Mid_FatInitialize         (RX_HANDLE                hVol);

    RX_RESULT FAR Mid_FatDeinitialize       (RX_HANDLE                hVol);

    RX_RESULT FAR Mid_FatFindFirst          (RX_HANDLE                hVol,
                                             RX_HANDLE FAR*           phDir,
                                             DIR_INFORMATION_T FAR*   ptDirNfo);

    RX_RESULT FAR Mid_FatFindNext           (RX_HANDLE                hDir,
                                             DIR_INFORMATION_T FAR*   ptDirNfo);

    RX_RESULT FAR Mid_FatFindClose          (RX_HANDLE                hDir);

    RX_RESULT FAR Mid_FatFormat             (RX_HANDLE                hVol,
                                             const STRING FAR*        pszVol,
                                             MID_FAT_TYPE             eFatTyp);

    RX_RESULT FAR Mid_FatFlush              (RX_HANDLE                hVol);

    RX_RESULT FAR Mid_FatCreateFile         (RX_HANDLE                hVol,
                                             const STRING FAR*        pszNam,
                                             UINT                     uAttr,
                                             RX_HANDLE FAR*           phFil);

    RX_RESULT FAR Mid_FatPutFileChar        (RX_HANDLE                hFil,
                                             UINT8                    bChar);

    RX_RESULT FAR Mid_FatWriteFile          (RX_HANDLE                hFil,
                                             const void FAR*          pvBuf,
                                             UINT32 FAR*              pulCnt);

    RX_RESULT FAR Mid_FatGetFileChar        (RX_HANDLE                hFil,
                                             UINT8 FAR*               pbChar);

    RX_RESULT FAR Mid_FatReadFile           (RX_HANDLE                hFil,
                                             void FAR*                pvBuf,
                                             UINT32 FAR*              pulCnt);

    RX_RESULT FAR Mid_FatOpenFile           (RX_HANDLE                hVol,
                                             const STRING FAR*        pszNam,
                                             MID_FAT_FILEACCESS       eAcc,
                                             RX_HANDLE FAR*           phFil);

    RX_RESULT FAR Mid_FatCloseFile          (RX_HANDLE                hFil);

    RX_RESULT FAR Mid_FatGetFileSize        (RX_HANDLE                hFil,
                                             UINT32 FAR*              pulSiz);

    RX_RESULT FAR Mid_FatTellFilePosition   (RX_HANDLE                hFil,
                                             UINT32 FAR*              pulPos);

    RX_RESULT FAR Mid_FatSeekFile           (RX_HANDLE                hFil,
                                             UINT32                   ulOffs,
                                             MID_FAT_SEEK_TYPE        eOrgn);

    RX_RESULT FAR Mid_FatFlushFile          (RX_HANDLE                hFil);

    RX_RESULT FAR Mid_FatMakeDirectory      (RX_HANDLE                hVol,
                                             const STRING FAR*        pszPath);

    RX_RESULT FAR Mid_FatChangeDirectory    (RX_HANDLE                hVol,
                                             const STRING FAR*        pszPath);

    RX_RESULT FAR Mid_FatDelete             (RX_HANDLE                hVol,
                                             STRING FAR*              pszNam);

    RX_RESULT FAR Mid_FatRename             (RX_HANDLE                hVol,
                                             const STRING FAR*        pszOldNam,
                                             const STRING FAR*        pszNewNam);

    RX_RESULT FAR Mid_FatDeleteAll          (RX_HANDLE                hVol);

    void FAR Mid_FatNormalizeFilename       (const STRING FAR*        pszStr);

    RX_RESULT FAR Mid_FatGetDiskFree        (RX_HANDLE                hVol,
                                             UINT32 FAR*              pulDiskFreeInBytes);

    RX_RESULT FAR Mid_FatGetDiskFreeEx      (RX_HANDLE                hVol,
                                             UINT64 FAR*              pullDiskFreeInBytes);

    /* channge into default channel directory, ulInstance is referring to the channel */
    RX_RESULT FAR Mid_FatChangeIntoChannelDirectory(RX_HANDLE         hVol,
                                                    UINT32            ulInstance);

#endif

#ifdef __cplusplus
}
#endif

