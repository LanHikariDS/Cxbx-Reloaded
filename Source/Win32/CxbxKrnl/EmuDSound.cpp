// ******************************************************************
// *
// *    .,-:::::    .,::      .::::::::.    .,::      .:
// *  ,;;;'````'    `;;;,  .,;;  ;;;'';;'   `;;;,  .,;; 
// *  [[[             '[[,,[['   [[[__[[\.    '[[,,[['  
// *  $$$              Y$$$P     $$""""Y$$     Y$$$P    
// *  `88bo,__,o,    oP"``"Yo,  _88o,,od8P   oP"``"Yo,  
// *    "YUMMMMMP",m"       "Mm,""YUMMMP" ,m"       "Mm,
// *
// *   Cxbx->Win32->CxbxKrnl->EmuDSound.cpp
// *
// *  This file is part of the Cxbx project.
// *
// *  Cxbx and Cxbe are free software; you can redistribute them
// *  and/or modify them under the terms of the GNU General Public
// *  License as published by the Free Software Foundation; either
// *  version 2 of the license, or (at your option) any later version.
// *
// *  This program is distributed in the hope that it will be useful,
// *  but WITHOUT ANY WARRANTY; without even the implied warranty of
// *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// *  GNU General Public License for more details.
// *
// *  You should have recieved a copy of the GNU General Public License
// *  along with this program; see the file COPYING.
// *  If not, write to the Free Software Foundation, Inc.,
// *  59 Temple Place - Suite 330, Bostom, MA 02111-1307, USA.
// *
// *  (c) 2002-2003 Aaron Robinson <caustik@caustik.com>
// *
// *  All rights reserved
// *
// ******************************************************************
#define _CXBXKRNL_INTERNAL
#define _XBOXKRNL_LOCAL_

// ******************************************************************
// * prevent name collisions
// ******************************************************************
namespace xboxkrnl
{
    #include <xboxkrnl/xboxkrnl.h>
};

#include "Emu.h"
#include "EmuFS.h"
#include "EmuKrnl.h"
#include "EmuDInput.h"
#include "EmuShared.h"

// ******************************************************************
// * prevent name collisions
// ******************************************************************
namespace xdirectx
{
    #include "xdirectx.h"
};

// ******************************************************************
// * prevent name collisions
// ******************************************************************
namespace xg
{
    #include "EmuXG.h"
};

#include "EmuD3D8.h"

#include "ResCxbxDll.h"

#include <process.h>
#include <locale.h>

// ******************************************************************
// * Static Variable(s)
// ******************************************************************
static xdirectx::LPDIRECTSOUND8 g_pD3D8 = NULL;

// ******************************************************************
// * func: EmuDirectSoundCreate
// ******************************************************************
HRESULT WINAPI xdirectx::EmuDirectSoundCreate
(
    LPVOID          pguidDeviceId,
    LPDIRECTSOUND8 *ppDirectSound,
    LPUNKNOWN       pUnknown
)
{
    EmuSwapFS();   // Win2k/XP FS

    // ******************************************************************
    // * debug trace
    // ******************************************************************
    #ifdef _DEBUG_TRACE
    {
        printf("EmuDSound (0x%X): EmuDirectSoundCreate\n"
               "(\n"
               "   pguidDeviceId             : 0x%.08X\n"
               "   ppDirectSound             : 0x%.08X\n"
               "   pUnknown                  : 0x%.08X\n"
               ");\n",
               GetCurrentThreadId(), pguidDeviceId, ppDirectSound, pUnknown);
    }
    #endif

    HRESULT hRet = DirectSoundCreate8(NULL, ppDirectSound, NULL);

    EmuSwapFS();   // XBox FS

    return hRet;
}

// ******************************************************************
// * func: EmuIDirectSound8_CreateSoundBuffer
// ******************************************************************
HRESULT WINAPI xdirectx::EmuIDirectSound8_CreateSoundBuffer
(
    LPDIRECTSOUND8          pThis,
    LPCDSBUFFERDESC         pdsbd,
    X_CDirectSoundBuffer  **ppBuffer,
    LPUNKNOWN               pUnkOuter
)
{
    EmuSwapFS();   // Win2k/XP FS

    // ******************************************************************
    // * debug trace
    // ******************************************************************
    #ifdef _DEBUG_TRACE
    {
        printf("EmuDSound (0x%X): EmuIDirectSound8_CreateSoundBuffer\n"
               "(\n"
               "   pdsbd                     : 0x%.08X\n"
               "   ppBuffer                  : 0x%.08X\n"
               "   pUnkOuter                 : 0x%.08X\n"
               ");\n",
               GetCurrentThreadId(), pdsbd, ppBuffer, pUnkOuter);
    }
    #endif

    // Todo: Garbage Collection
    *ppBuffer = new X_CDirectSoundBuffer();

    (*ppBuffer)->EmuDirectSoundBuffer8 = 0;

    // Todo: Translate params, then make the PC DirectSound call
//    HRESULT hRet = pThis->CreateSoundBuffer(pdsbd, ppBuffer, pUnkOuter);

    printf("*Warning* EmuIDirectSound8_CreateSoundBuffer is being ignored\n");

    EmuSwapFS();   // XBox FS

    return STATUS_SUCCESS;
}

// ******************************************************************
// * func: EmuIDirectSoundBuffer8_SetBufferData
// ******************************************************************
HRESULT WINAPI xdirectx::EmuIDirectSoundBuffer8_SetBufferData
(
    X_CDirectSoundBuffer   *pThis,
    LPVOID                  pvBufferData,
    DWORD                   dwBufferBytes
)
{
    EmuSwapFS();   // Win2k/XP FS

    // ******************************************************************
    // * debug trace
    // ******************************************************************
    #ifdef _DEBUG_TRACE
    {
        printf("EmuDSound (0x%X): EmuIDirectSoundBuffer8_SetBufferData\n"
               "(\n"
               "   pThis                     : 0x%.08X\n"
               "   pvBufferData              : 0x%.08X\n"
               "   dwBufferBytes             : 0x%.08X\n"
               ");\n",
               GetCurrentThreadId(), pThis, pvBufferData, dwBufferBytes);
    }
    #endif

    // Todo: Translate params, then make the PC DirectSound call
    printf("*Warning* EmuIDirectSoundBuffer8_SetBufferData is being ignored\n");

    EmuSwapFS();   // XBox FS

    return STATUS_SUCCESS;
}

// ******************************************************************
// * func: EmuIDirectSoundBuffer8_SetPlayRegion
// ******************************************************************
HRESULT WINAPI xdirectx::EmuIDirectSoundBuffer8_SetPlayRegion
(
    X_CDirectSoundBuffer   *pThis,
    DWORD                   dwPlayStart,
    DWORD                   dwPlayLength
)
{
    EmuSwapFS();   // Win2k/XP FS

    // ******************************************************************
    // * debug trace
    // ******************************************************************
    #ifdef _DEBUG_TRACE
    {
        printf("EmuDSound (0x%X): EmuIDirectSoundBuffer8_SetPlayRegion\n"
               "(\n"
               "   pThis                     : 0x%.08X\n"
               "   dwPlayStart               : 0x%.08X\n"
               "   dwPlayLength              : 0x%.08X\n"
               ");\n",
               GetCurrentThreadId(), pThis, dwPlayStart, dwPlayLength);
    }
    #endif

    // Todo: Translate params, then make the PC DirectSound call
    printf("*Warning* EmuIDirectSoundBuffer8_SetPlayRegion is being ignored\n");

    EmuSwapFS();   // XBox FS

    return STATUS_SUCCESS;
}

// ******************************************************************
// * func: EmuIDirectSoundBuffer8_SetLoopRegion
// ******************************************************************
HRESULT WINAPI xdirectx::EmuIDirectSoundBuffer8_SetLoopRegion
(
    X_CDirectSoundBuffer   *pThis,
    DWORD                   dwLoopStart,
    DWORD                   dwLoopLength
)
{
    EmuSwapFS();   // Win2k/XP FS

    // ******************************************************************
    // * debug trace
    // ******************************************************************
    #ifdef _DEBUG_TRACE
    {
        printf("EmuDSound (0x%X): EmuIDirectSoundBuffer8_SetLoopRegion\n"
               "(\n"
               "   pThis                     : 0x%.08X\n"
               "   dwLoopStart               : 0x%.08X\n"
               "   dwLoopLength              : 0x%.08X\n"
               ");\n",
               GetCurrentThreadId(), pThis, dwLoopStart, dwLoopLength);
    }
    #endif

    // Todo: Translate params, then make the PC DirectSound call
    printf("*Warning* EmuIDirectSoundBuffer8_SetLoopRegion is being ignored\n");

    EmuSwapFS();   // XBox FS

    return STATUS_SUCCESS;
}

// ******************************************************************
// * func: EmuIDirectSoundBuffer8_SetVolume
// ******************************************************************
HRESULT WINAPI xdirectx::EmuIDirectSoundBuffer8_SetVolume
(
    X_CDirectSoundBuffer   *pThis,
    LONG                    lVolume
)
{
    EmuSwapFS();   // Win2k/XP FS

    // ******************************************************************
    // * debug trace
    // ******************************************************************
    #ifdef _DEBUG_TRACE
    {
        printf("EmuDSound (0x%X): EmuIDirectSoundBuffer8_SetVolume\n"
               "(\n"
               "   pThis                     : 0x%.08X\n"
               "   lVolume                   : 0x%.08X\n"
               ");\n",
               GetCurrentThreadId(), pThis, lVolume);
    }
    #endif

    // Todo: Translate params, then make the PC DirectSound call
    printf("*Warning* EmuIDirectSoundBuffer8_SetVolume is being ignored\n");

    EmuSwapFS();   // XBox FS

    return STATUS_SUCCESS;
}

// ******************************************************************
// * func: EmuIDirectSoundBuffer8_SetCurrentPosition
// ******************************************************************
HRESULT WINAPI xdirectx::EmuIDirectSoundBuffer8_SetCurrentPosition
(
    DWORD                   dwNewPosition
)
{
    EmuSwapFS();   // Win2k/XP FS

    // ******************************************************************
    // * debug trace
    // ******************************************************************
    #ifdef _DEBUG_TRACE
    {
        printf("EmuDSound (0x%X): EmuIDirectSoundBuffer8_SetCurrentPosition\n"
               "(\n"
               "   dwNewPosition             : 0x%.08X\n"
               ");\n",
               GetCurrentThreadId(), dwNewPosition);
    }
    #endif

    // Todo: Translate params, then make the PC DirectSound call
    printf("*Warning* EmuIDirectSoundBuffer8_SetCurrentPosition is being ignored\n");

    EmuSwapFS();   // XBox FS

    return STATUS_SUCCESS;
}