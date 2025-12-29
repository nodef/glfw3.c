// Core/Common files (always included)
#pragma once

// FIX: Define missing OCR_* constants (@wolfam77)
// For some reason, including windows.h with OEMRESOURCE defined
// does not always define these constants.
#ifdef _GLFW_WIN32
#ifndef OEMRESOURCE
#define OEMRESOURCE
#endif
#include <windows.h>
#ifndef OCR_NORMAL
#define OCR_NORMAL          32512
#define OCR_IBEAM           32513
#define OCR_WAIT            32514
#define OCR_CROSS           32515
#define OCR_UP              32516
#define OCR_SIZE            32640   /* OBSOLETE: use OCR_SIZEALL */
#define OCR_ICON            32641   /* OBSOLETE: use OCR_NORMAL */
#define OCR_SIZENWSE        32642
#define OCR_SIZENESW        32643
#define OCR_SIZEWE          32644
#define OCR_SIZENS          32645
#define OCR_SIZEALL         32646
#define OCR_ICOCUR          32647   /* OBSOLETE: use OIC_WINLOGO */
#define OCR_NO              32648
#endif
#endif

// Auto-link windows libraries (@wolfam77)
#ifdef _GLFW_WIN32
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "opengl32.lib")
#endif

#include "context.c"
#include "egl_context.c"
#include "init.c"
#include "input.c"
#include "monitor.c"
#include "osmesa_context.c"
#include "platform.c"
#include "vulkan.c"
#include "window.c"

// Null platform (for unsupported platforms)
// FIX: Avoid including null platform when not needed (@wolfam77)
#if !defined(_GLFW_WIN32) && !defined(_GLFW_COCOA) && !defined(_GLFW_X11) && !defined(_GLFW_WAYLAND)
#include "null_init.c"
#include "null_joystick.c"
#include "null_monitor.c"
#include "null_window.c"
#endif

// Windows platform
#if defined(_GLFW_WIN32)
#include "win32_platform.h"
#include "wgl_context.c"
#include "win32_init.c"
#include "win32_joystick.h"
#include "win32_joystick.c"
#include "win32_module.c"
#include "win32_monitor.c"
#include "win32_thread.h"
#include "win32_thread.c"
#include "win32_time.h"
#include "win32_time.c"
#include "win32_window.c"
#endif

// macOS platform
#if defined(_GLFW_COCOA)
#include "cocoa_init.m"
#include "cocoa_joystick.m"
#include "cocoa_monitor.m"
#include "cocoa_time.c"
#include "cocoa_window.m"
#include "nsgl_context.m"
#endif

// X11 platform
#if defined(_GLFW_X11)
#include "glx_context.c"
#include "linux_joystick.c"
#include "x11_init.c"
#include "x11_monitor.c"
#include "x11_window.c"
#include "xkb_unicode.c"
#endif

// Wayland platform
#if defined(_GLFW_WAYLAND)
#include "linux_joystick.c"
#include "wl_init.c"
#include "wl_monitor.c"
#include "wl_window.c"
#include "xkb_unicode.c"
#endif

// POSIX threading (used on non-Windows platforms)
#if !defined(_WIN32)
#include "posix_module.c"
#include "posix_thread.c"
#endif

// POSIX time (used on POSIX platforms that aren't macOS)
#if !defined(_WIN32) && !defined(__APPLE__)
#include "posix_time.c"
#endif

// POSIX poll (used on Wayland and X11)
#if defined(_GLFW_WAYLAND) || defined(_GLFW_X11)
#include "posix_poll.c"
#endif
