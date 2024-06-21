/*----------------------------------------------------------------------------s
	NAME
		Utils.h

	PURPOSE
		Defines for the general-purpose functions for the WinTab demos.

	COPYRIGHT
		This file is Copyright (c) Wacom Company, Ltd. 2024 All Rights Reserved
		with portions copyright 1991-1998 by LCS/Telegraphics.

		The text and information contained in this file may be freely used,
		copied, or distributed without compensation or licensing restrictions.
---------------------------------------------------------------------------- */
#pragma once

#include	<windows.h>
#include	<stdio.h>
#include	<assert.h>
#include	<stdarg.h>

#include	"wintab.h"

//////////////////////////////////////////////////////////////////////////////
#define WACOM_DEBUG

// Ignore warnings about using unsafe string functions.
#pragma warning( disable : 4996 )

//////////////////////////////////////////////////////////////////////////////
// Function pointers to Wintab functions exported from wintab32.dll. 
typedef UINT ( API * WTINFOA ) ( UINT, UINT, LPVOID );
typedef HCTX ( API * WTOPENA )( HWND, LPLOGCONTEXTA, bool );
typedef bool ( API * WTGETA ) ( HCTX, LPLOGCONTEXT );
typedef bool ( API * WTSETA ) ( HCTX, LPLOGCONTEXT );
typedef bool ( API * WTCLOSE ) ( HCTX );
typedef bool ( API * WTENABLE ) ( HCTX, bool );
typedef bool ( API * WTPACKET ) ( HCTX, UINT, LPVOID );
typedef bool ( API * WTOVERLAP ) ( HCTX, bool );
typedef bool ( API * WTSAVE ) ( HCTX, LPVOID );
typedef bool ( API * WTCONFIG ) ( HCTX, HWND );
typedef HCTX ( API * WTRESTORE ) ( HWND, LPVOID, bool );
typedef bool ( API * WTEXTSET ) ( HCTX, UINT, LPVOID );
typedef bool ( API * WTEXTGET ) ( HCTX, UINT, LPVOID );
typedef bool ( API * WTQUEUESIZESET ) ( HCTX, int );
typedef int  ( API * WTDATAPEEK ) ( HCTX, UINT, UINT, int, LPVOID, LPINT);
typedef int  ( API * WTPACKETSGET ) (HCTX, int, LPVOID);
typedef HMGR ( API * WTMGROPEN ) ( HWND, UINT );
typedef bool ( API * WTMGRCLOSE ) ( HMGR );
typedef HCTX ( API * WTMGRDEFCONTEXT ) ( HMGR, bool );
typedef HCTX ( API * WTMGRDEFCONTEXTEX ) ( HMGR, UINT, bool );

// TODO - add more wintab32 function defs as needed

//////////////////////////////////////////////////////////////////////////////
extern char* gpszProgramName;

// Loaded Wintab32 API functions.
extern HINSTANCE ghWintab;

extern WTINFOA gpWTInfoA;
extern WTOPENA gpWTOpenA;
extern WTGETA gpWTGetA;
extern WTSETA gpWTSetA;
extern WTCLOSE gpWTClose;
extern WTPACKET gpWTPacket;
extern WTENABLE gpWTEnable;
extern WTOVERLAP gpWTOverlap;
extern WTSAVE gpWTSave;
extern WTCONFIG gpWTConfig;
extern WTRESTORE gpWTRestore;
extern WTEXTSET gpWTExtSet;
extern WTEXTGET gpWTExtGet;
extern WTQUEUESIZESET gpWTQueueSizeSet;
extern WTDATAPEEK gpWTDataPeek;
extern WTPACKETSGET gpWTPacketsGet;
extern WTMGROPEN gpWTMgrOpen;
extern WTMGRCLOSE gpWTMgrClose;
extern WTMGRDEFCONTEXT gpWTMgrDefContext;
extern WTMGRDEFCONTEXTEX gpWTMgrDefContextEx;

// TODO - add more wintab32 function pointers as needed

//////////////////////////////////////////////////////////////////////////////
bool LoadWintab( void );
void UnloadWintab( void );

void ShowError( char *pszErrorMessage );

//////////////////////////////////////////////////////////////////////////////
#ifdef WACOM_DEBUG

void WacomTrace( char *lpszFormat, ...);

#define WACOM_ASSERT( x ) assert( x )
#define WACOM_TRACE(...)  WacomTrace(__VA_ARGS__)
#else
#define WACOM_TRACE(...)
#define WACOM_ASSERT( x )

#endif // WACOM_DEBUG

