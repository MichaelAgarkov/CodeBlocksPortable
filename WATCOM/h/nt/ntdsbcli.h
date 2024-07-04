/*
 *  ntdsbcli.h  NT Directory Service backup client functions
 *
 * =========================================================================
 *
 *                          Open Watcom Project
 *
 * Copyright (c) 2004-2010 The Open Watcom Contributors. All Rights Reserved.
 *
 *    This file is automatically generated. Do not edit directly.
 *
 * =========================================================================
 */

#ifndef _NTDSBCLI_H_
#define _NTDSBCLI_H_

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file;
#endif

#include <ntdsbmsg.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Macro to specify backup client functions */
#define NTDSBCLI_API    __declspec(dllimport) __stdcall

/* Backup file type data type */
#ifdef UNICODE
typedef WCHAR   BFT;
#else
typedef CHAR    BFT;
#endif

/* Backup context handle data type */
typedef void    *HBC;

/* Annotation strings */
#define g_wszBackupAnnotation       L"NTDS Backup Interface"
#define g_aszBackupAnnotation       "NTDS Backup Interface"
#define g_wszRestoreAnnotation      L"NTDS Restore Interface"
#define g_aszRestoreAnnotation      "NTDS Restore Interface"
#ifdef UNICODE
    #define g_szBackupAnnotation    g_wszBackupAnnotation
    #define g_szRestoreAnnotation   g_wszRestoreAnnotation
#else
    #define g_szBackupAnnotation    g_aszBackupAnnotation
    #define g_szRestoreAnnotation   g_aszRestoreAnnotation
#endif

/* DsBackupPrepare() flags */
#define BACKUP_TYPE_FULL        0x00000001L
#define BACKUP_TYPE_LOGS_ONLY   0x00000002L
#define BACKUP_TYPE_INCREMENTAL 0x00000004L

/* DsRestorePrepare() flags */
#define RESTORE_TYPE_AUTHORITATIVE  0x00000001L
#define RESTORE_TYPE_ONLINE         0x00000002L
#define RESTORE_TYPE_CATCHUP        0x00000004L

/* Log number special value */
#define BACKUP_DISABLE_INCREMENTAL  0xFFFFFFFFL

/* Backup file type flags */
#define BFT_DIRECTORY           0x80
#define BFT_DATABASE_DIRECTORY  0x40
#define BFT_LOG_DIRECTORY       0x20

/* Predefined backup file type values */
#define BFT_LOG             (BFT)(TEXT( '\x01' ) | BFT_LOG_DIRECTORY)
#define BFT_LOG_DIR         (BFT)(TEXT( '\x02' ) | BFT_DIRECTORY)
#define BFT_CHECKPOINT_DIR  (BFT)(TEXT( '\x03' ) | BFT_DIRECTORY)
#define BFT_NTDS_DATABASE   (BFT)(TEXT( '\x04' ) | BFT_DATABASE_DIRECTORY)
#define BFT_PATCH_FILE      (BFT)(TEXT( '\x05' ) | BFT_LOG_DIRECTORY)
#define BFT_UNKNOWN         (BFT)(TEXT(' \x0F' ))

/* Restore map */
typedef struct tagEDB_RSTMAPA {
    char    *szDatabaseName;
    char    *szNewDatabaseName;
} EDB_RSTMAPA;
typedef EDB_RSTMAPA     *PEDB_RSTMAPA;
typedef struct tagEDB_RSTMAPW {
    WCHAR   *wszDatabaseName;
    WCHAR   *wszNewDatabaseName;
} EDB_RSTMAPW;
typedef EDB_RSTMAPW     *PEDB_RSTMAPW;
#ifdef UNICODE
typedef EDB_RSTMAPW     EDB_RSTMAP;
typedef PEDB_RSTMAPW    PEDB_RSTMAP;
#else
typedef EDB_RSTMAPA     EDB_RSTMAP;
typedef PEDB_RSTMAPA    PEDB_RSTMAP;
#endif

/* Functions in NTDSBCLI.DLL */
HRESULT NTDSBCLI_API    DsBackupClose( HBC );
HRESULT NTDSBCLI_API    DsBackupEnd( HBC );
VOID NTDSBCLI_API       DsBackupFree( PVOID );
HRESULT NTDSBCLI_API    DsBackupGetBackupLogsA( HBC, LPSTR *, LPDWORD );
HRESULT NTDSBCLI_API    DsBackupGetBackupLogsW( HBC, LPWSTR *, LPDWORD );
HRESULT NTDSBCLI_API    DsBackupGetDatabaseNamesA( HBC, LPSTR *, LPDWORD );
HRESULT NTDSBCLI_API    DsBackupGetDatabaseNamesW( HBC, LPWSTR *, LPDWORD );
HRESULT NTDSBCLI_API    DsBackupOpenFileA( HBC, LPCSTR, DWORD, LARGE_INTEGER * );
HRESULT NTDSBCLI_API    DsBackupOpenFileW( HBC, LPCWSTR, DWORD, LARGE_INTEGER * );
HRESULT NTDSBCLI_API    DsBackupPrepareA( LPCSTR, ULONG, ULONG, PVOID *, LPDWORD, HBC * );
HRESULT NTDSBCLI_API    DsBackupPrepareW( LPCWSTR, ULONG, ULONG, PVOID *, LPDWORD, HBC * );
HRESULT NTDSBCLI_API    DsBackupRead( HBC, PVOID, DWORD, PDWORD );
HRESULT NTDSBCLI_API    DsBackupTruncateLogs( HBC );
HRESULT NTDSBCLI_API    DsIsNTDSOnlineA( LPCSTR, BOOL * );
HRESULT NTDSBCLI_API    DsIsNTDSOnlineW( LPCWSTR, BOOL * );
HRESULT NTDSBCLI_API    DsRestoreEnd( HBC );
HRESULT NTDSBCLI_API    DsRestoreGetDatabaseLocationsA( HBC, LPSTR *, LPDWORD );
HRESULT NTDSBCLI_API    DsRestoreGetDatabaseLocationsW( HBC, LPWSTR *, LPDWORD );
HRESULT NTDSBCLI_API    DsRestorePrepareA( LPCSTR, ULONG, PVOID, DWORD, HBC * );
HRESULT NTDSBCLI_API    DsRestorePrepareW( LPCWSTR, ULONG, PVOID, DWORD, HBC * );
HRESULT NTDSBCLI_API    DsRestoreRegisterA( HBC, LPCSTR, LPCSTR, EDB_RSTMAPA [], LONG, LPCSTR, ULONG, ULONG );
HRESULT NTDSBCLI_API    DsRestoreRegisterComplete( HBC, HRESULT );
HRESULT NTDSBCLI_API    DsRestoreRegisterW( HBC, LPCWSTR, LPCWSTR, EDB_RSTMAPW [], LONG, LPCWSTR, ULONG, ULONG );
HRESULT NTDSBCLI_API    DsSetAuthIdentityA( LPCSTR, LPCSTR, LPCSTR );
HRESULT NTDSBCLI_API    DsSetAuthIdentityW( LPCWSTR, LPCWSTR, LPCWSTR );
HRESULT NTDSBCLI_API    DsSetCurrentBackupLogA( LPCSTR, DWORD );
HRESULT NTDSBCLI_API    DsSetCurrentBackupLogW( LPCWSTR, DWORD );

/* Map generic function names to the appropriate ANSI or Unicode version. */
#ifdef UNICODE
    #define DsBackupGetBackupLogs           DsBackupGetBackupLogsW
    #define DsBackupGetDatabaseNames        DsBackupGetDatabaseNamesW
    #define DsBackupOpenFile                DsBackupOpenFileW
    #define DsBackupPrepare                 DsBackupPrepareW
    #define DsIsNTDSOnline                  DsIsNTDSOnlineW
    #define DsRestoreGetDatabaseLocations   DsRestoreGetDatabaseLocationsW
    #define DsRestorePrepare                DsRestorePrepareW
    #define DsRestoreRegister               DsRestoreRegisterW
    #define DsSetAuthIdentity               DsSetAuthIdentityW
    #define DsSetCurrentBackupLog           DsSetCurrentBackupLogW
#else
    #define DsBackupGetBackupLogs           DsBackupGetBackupLogsA
    #define DsBackupGetDatabaseNames        DsBackupGetDatabaseNamesA
    #define DsBackupOpenFile                DsBackupOpenFileA
    #define DsBackupPrepare                 DsBackupPrepareA
    #define DsIsNTDSOnline                  DsIsNTDSOnlineA
    #define DsRestoreGetDatabaseLocations   DsRestoreGetDatabaseLocationsA
    #define DsRestorePrepare                DsRestorePrepareA
    #define DsRestoreRegister               DsRestoreRegisterA
    #define DsSetAuthIdentity               DsSetAuthIdentityA
    #define DsSetCurrentBackupLog           DsSetCurrentBackupLogA
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _NTDSBCLI_H_ */
