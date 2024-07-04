/*
 *  il21dec.h   Line 21 Decoder interfaces
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

#ifndef __IL21DEC__
#define __IL21DEC__

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file;
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* ActiveMovie Line 21 levels */
typedef enum _AM_LINE21_CCLEVEL {
    AM_L21_CCLEVEL_TC2  = 0
} AM_LINE21_CCLEVEL;
typedef AM_LINE21_CCLEVEL   *PAM_LINE21_CCLEVEL;

/* ActiveMovie Line 21 services */
typedef enum _AM_LINE21_CCSERVICE {
    AM_L21_CCSERVICE_None       = 0,
    AM_L21_CCSERVICE_Caption1   = 1,
    AM_L21_CCSERVICE_Caption2   = 2,
    AM_L21_CCSERVICE_Text1      = 3,
    AM_L21_CCSERVICE_Text2      = 4,
    AM_L21_CCSERVICE_XDS        = 5,
    AM_L21_CCSERVICE_DefChannel = 10,
    AM_L21_CCSERVICE_Invalid    = 11
} AM_LINE21_CCSERVICE;
typedef AM_LINE21_CCSERVICE *PAM_LINE21_CCSERVICE;

/* ActiveMovie Line 21 states */
typedef enum _AM_LINE21_CCSTATE {
    AM_L21_CCSTATE_Off  = 0,
    AM_L21_CCSTATE_On   = 1
} AM_LINE21_CCSTATE;
typedef AM_LINE21_CCSTATE   *PAM_LINE21_CCSTATE;

/* ActiveMovie Line 21 styles */
typedef enum _AM_LINE21_CCSTYLE {
    AM_L21_CCSTYLE_None     = 0,
    AM_L21_CCSTYLE_PopOn    = 1,
    AM_L21_CCSTYLE_PaintOn  = 2,
    AM_L21_CCSTYLE_RollUp   = 3
} AM_LINE21_CCSTYLE;
typedef AM_LINE21_CCSTYLE   *PAM_LINE21_CCSTYLE;

/* ActiveMovie Line 21 draw background modes */
typedef enum _AM_LINE21_DRAWBGMODE {
    AM_L21_DRAWBGMODE_Opaque        = 0,
    AM_L21_DRAWBGMODE_Transparent   = 1
} AM_LINE21_DRAWBGMODE;
typedef AM_LINE21_DRAWBGMODE    *PAM_LINE21_DRAWBGMODE;

/* IAMLine21Decoder interface */
#undef INTERFACE
#define INTERFACE   IAMLine21Decoder
DECLARE_INTERFACE_( IAMLine21Decoder, IUnknown ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, void ** ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IAMLine21Decoder methods */
    STDMETHOD( GetDecoderLevel )( THIS_ AM_LINE21_CCLEVEL * ) PURE;
    STDMETHOD( GetCurrentService )( THIS_ AM_LINE21_CCSERVICE * ) PURE;
    STDMETHOD( SetCurrentService )( THIS_ AM_LINE21_CCSERVICE ) PURE;
    STDMETHOD( GetServiceState )( THIS_ AM_LINE21_CCSTATE * ) PURE;
    STDMETHOD( SetServiceState )( THIS_ AM_LINE21_CCSTATE ) PURE;
    STDMETHOD( GetOutputFormat )( THIS_ LPBITMAPINFOHEADER ) PURE;
    STDMETHOD( SetOutputFormat )( THIS_ LPBITMAPINFO ) PURE;
    STDMETHOD( GetBackgroundColor )( THIS_ DWORD * ) PURE;
    STDMETHOD( SetBackgroundColor )( THIS_ DWORD ) PURE;
    STDMETHOD( GetRedrawAlways )( THIS_ LPBOOL ) PURE;
    STDMETHOD( SetRedrawAlways )( THIS_ BOOL ) PURE;
    STDMETHOD( GetDrawBackgroundMode )( THIS_ AM_LINE21_DRAWBGMODE * ) PURE;
    STDMETHOD( SetDrawBackgroundMode )( THIS_ AM_LINE21_DRAWBGMODE ) PURE;
};

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __IL21DEC__ */
