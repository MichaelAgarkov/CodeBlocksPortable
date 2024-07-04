/*
 *  strqcond.h / structuredquerycondition.h     Structured query condition interfaces
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

#include <rpc.h>
#include <rpcndr.h>
#ifndef COM_NO_WINDOWS_H
    #include <windows.h>
    #include <ole2.h>
#endif

#ifndef __structuredquerycondition_h__
#define __structuredquerycondition_h__

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file;
#endif

#include <oaidl.h>
#include <ocidl.h>
#include <objidl.h>
#include <propidl.h>

/* Condition types */
typedef enum tagCONDITION_TYPE {
    CT_AND_CONDITION    = 0,
    CT_OR_CONDITION     = 1,
    CT_NOT_CONDITION    = 2,
    CT_LEAF_CONDITION   = 3
} CONDITION_TYPE;

/* Condition operations */
typedef enum tagCONDITION_OPERATION {
    COP_IMPLICIT                = 0,
    COP_EQUAL                   = 1,
    COP_NOTEQUAL                = 2,
    COP_LESSTHAN                = 3,
    COP_GREATERTHAN             = 4,
    COP_LESSTHANOREQUAL         = 5,
    COP_GREATERTHANOREQUAL      = 6,
    COP_VALUE_STARTSWITH        = 7,
    COP_VALUE_ENDSWITH          = 8,
    COP_VALUE_CONTAINS          = 9,
    COP_VALUE_NOTCONTAINS       = 10,
    COP_DOSWILDCARDS            = 11,
    COP_WORD_EQUAL              = 12,
    COP_WORD_STARTSWITH         = 13,
    COP_APPLICATION_SPECIFIC    = 14
} CONDITION_OPERATION;

/* GUIDs */
EXTERN_C const IID  IID_IRichChunk;
EXTERN_C const IID  IID_ICondition;
EXTERN_C const IID  IID_ICondition2;

/* IRichChunk interface */
#undef INTERFACE
#define INTERFACE   IRichChunk
DECLARE_INTERFACE_( IRichChunk, IUnknown ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, void ** ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IRichChunk methods */
    STDMETHOD( GetData )( THIS_ ULONG *, ULONG *, LPWSTR *, PROPVARIANT * ) PURE;
};

/* ICondition interface */
#undef INTERFACE
#define INTERFACE   ICondition
DECLARE_INTERFACE_( ICondition, IPersistStream ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, void ** ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;
    
    /* IPersist methods */
    STDMETHOD( GetClassID )( THIS_ CLSID * ) PURE;
    
    /* IPersistStream methods */
    STDMETHOD( IsDirty )( THIS ) PURE;
    STDMETHOD( Load )( THIS_ IStream * ) PURE;
    STDMETHOD( Save )( THIS_ IStream *, BOOL ) PURE;
    STDMETHOD( GetSizeMax )( THIS_ ULARGE_INTEGER * ) PURE;
    
    /* ICondition methods */
    STDMETHOD( GetConditionType )( THIS_ CONDITION_TYPE * ) PURE;
    STDMETHOD( GetSubConditions )( THIS_ REFIID, void ** ) PURE;
    STDMETHOD( GetComparisonInfo )( THIS_ LPWSTR *, CONDITION_OPERATION *, PROPVARIANT * ) PURE;
    STDMETHOD( GetValueType )( THIS_ LPWSTR * ) PURE;
    STDMETHOD( GetValueNormalization )( THIS_ LPWSTR * ) PURE;
    STDMETHOD( GetInputTerms )( THIS_ IRichChunk **, IRichChunk **, IRichChunk ** ) PURE;
    STDMETHOD( Clone )( THIS_ ICondition ** ) PURE;
};

/* ICondition2 interface */
#undef INTERFACE
#define INTERFACE   ICondition2
DECLARE_INTERFACE_( ICondition2, ICondition ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, void ** ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;
    
    /* IPersist methods */
    STDMETHOD( GetClassID )( THIS_ CLSID * ) PURE;
    
    /* IPersistStream methods */
    STDMETHOD( IsDirty )( THIS ) PURE;
    STDMETHOD( Load )( THIS_ IStream * ) PURE;
    STDMETHOD( Save )( THIS_ IStream *, BOOL ) PURE;
    STDMETHOD( GetSizeMax )( THIS_ ULARGE_INTEGER * ) PURE;
    
    /* ICondition methods */
    STDMETHOD( GetConditionType )( THIS_ CONDITION_TYPE * ) PURE;
    STDMETHOD( GetSubConditions )( THIS_ REFIID, void ** ) PURE;
    STDMETHOD( GetComparisonInfo )( THIS_ LPWSTR *, CONDITION_OPERATION *, PROPVARIANT * ) PURE;
    STDMETHOD( GetValueType )( THIS_ LPWSTR * ) PURE;
    STDMETHOD( GetValueNormalization )( THIS_ LPWSTR * ) PURE;
    STDMETHOD( GetInputTerms )( THIS_ IRichChunk **, IRichChunk **, IRichChunk ** ) PURE;
    STDMETHOD( Clone )( THIS_ ICondition ** ) PURE;

    /* ICondition2 methods */
    STDMETHOD( GetLocale )( THIS_ LPWSTR * ) PURE;
    STDMETHOD( GetLeafConditionInfo )( THIS_ PROPERTYKEY *, CONDITION_OPERATION *, PROPVARIANT * ) PURE;
};

/* C object macros */
#if (!defined( __cplusplus ) || defined( CINTERFACE )) && defined( COBJMACROS )
    #define IRichChunk_QueryInterface( x, p1, p2 ) \
        (x)->lpVtbl->QueryInterface( x, p1, p2 )
    #define IRichChunk_AddRef( x ) \
        (x)->lpVtbl->AddRef( x )
    #define IRichChunk_Release( x ) \
        (x)->lpVtbl->Release( x )
    #define IRichChunk_GetData( x, p1, p2, p3, p4 ) \
        (x)->lpVtbl->GetData( x, p1, p2, p3, p4 )
    #define ICondition_QueryInterface( x, p1, p2 ) \
        (x)->lpVtbl->QueryInterface( x, p1, p2 )
    #define ICondition_AddRef( x ) \
        (x)->lpVtbl->AddRef( x )
    #define ICondition_Release( x ) \
        (x)->lpVtbl->Release( x )
    #define ICondition_GetClassID( x, p ) \
        (x)->lpVtbl->GetClassID( x, p )
    #define ICondition_IsDirty( x ) \
        (x)->lpVtbl->IsDirty( x )
    #define ICondition_Load( x, p ) \
        (x)->lpVtbl->Load( x, p )
    #define ICondition_Save( x, p1, p2 ) \
        (x)->lpVtbl->Save( x, p1, p2 )
    #define ICondition_GetSizeMax( x, p ) \
        (x)->lpVtbl->GetSizeMax( x, p )
    #define ICondition_GetConditionType( x, p ) \
        (x)->lpVtbl->GetConditionType( x, p )
    #define ICondition_GetSubConditions( x, p1, p2 ) \
        (x)->lpVtbl->GetSubConditions( x, p1, p2 )
    #define ICondition_GetComparisonInfo( x, p1, p2, p3 ) \
        (x)->lpVtbl->GetComparisonInfo( x, p1, p2, p3 )
    #define ICondition_GetValueType( x, p ) \
        (x)->lpVtbl->GetValueType( x, p )
    #define ICondition_GetValueNormalization( x, p ) \
        (x)->lpVtbl->GetValueNormalization( x, p )
    #define ICondition_GetInputTerms( x, p1, p2, p3 ) \
        (x)->lpVtbl->GetInputTerms( x, p1, p2, p3 )
    #define ICondition_Clone( x, p ) \
        (x)->lpVtbl->Clone( x, p )
    #define ICondition2_QueryInterface( x, p1, p2 ) \
        (x)->lpVtbl->QueryInterface( x, p1, p2 )
    #define ICondition2_AddRef( x ) \
        (x)->lpVtbl->AddRef( x )
    #define ICondition2_Release( x ) \
        (x)->lpVtbl->Release( x )
    #define ICondition2_GetClassID( x, p ) \
        (x)->lpVtbl->GetClassID( x, p )
    #define ICondition2_IsDirty( x ) \
        (x)->lpVtbl->IsDirty( x )
    #define ICondition2_Load( x, p ) \
        (x)->lpVtbl->Load( x, p )
    #define ICondition2_Save( x, p1, p2 ) \
        (x)->lpVtbl->Save( x, p1, p2 )
    #define ICondition2_GetSizeMax( x, p ) \
        (x)->lpVtbl->GetSizeMax( x, p )
    #define ICondition2_GetConditionType( x, p ) \
        (x)->lpVtbl->GetConditionType( x, p )
    #define ICondition2_GetSubConditions( x, p1, p2 ) \
        (x)->lpVtbl->GetSubConditions( x, p1, p2 )
    #define ICondition2_GetComparisonInfo( x, p1, p2, p3 ) \
        (x)->lpVtbl->GetComparisonInfo( x, p1, p2, p3 )
    #define ICondition2_GetValueType( x, p ) \
        (x)->lpVtbl->GetValueType( x, p )
    #define ICondition2_GetValueNormalization( x, p ) \
        (x)->lpVtbl->GetValueNormalization( x, p )
    #define ICondition2_GetInputTerms( x, p1, p2, p3 ) \
        (x)->lpVtbl->GetInputTerms( x, p1, p2, p3 )
    #define ICondition2_Clone( x, p ) \
        (x)->lpVtbl->Clone( x, p )
    #define ICondition2_GetLocale( x, p ) \
        (x)->lpVtbl->GetLocale( x, p )
    #define ICondition2_GetLeafConditionInfo( x, p1, p2, p3 ) \
        (x)->lpVtbl->GetLeafConditionInfo( x, p1, p2, p3 )
#endif

#endif /* __structuredquerycondition_h__ */
