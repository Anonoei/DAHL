/////////////////////////////////////////////////////////////////
//  Author: Devon Adams (https://github.com/devonadams)
//  License : GPLv3
//  Language: C++
//  This file serves a cross-platform library for Logging, Asserts, Printing colored text(16-bit color!),
//    keyboard/mouse input, etc!
//  This was made to allow transition to DAGGer more easy for ASCII apps
//    with a few added bonuses
//----=============================================================================----//
//----=------------------------------  verison 0.4.3  ----------------------------=----//
//----=============================================================================----//
/////////////////////////////
//  Additionally, some defines will modify what is included
//    #define DAHL_ALL.........Enable all libraries
//    #define DAHL_PRINT.......Include cross-platform color printing library
//    #define DAHL_INPUT.......Include cross-platform input library
//    #define DAHL_PROFILE.....Include function profiling library
//    #define DAHL_TIME........Include timestep library
//    #define DAHL_UUID........Include UUID library
//
/////////////////////////////
//  Defines to disable things
//    #define NO_DAHL_LOG       -   This disables DALog
//    #define NO_DAHL_ASSERT    -   This disables DAAsserts
//
/////////////////////////////
//  To be nice, this is how the above defines work:
//    #define DAHL_ALL
//    #include <DAHL.h>
/////////////////////////////
//           Thanks for checking out my library!
////////////////////////////////////////////////////////////////////
#pragma once

#ifndef DAHL_H_HEADER_GUARD	//	DAHL #include guards
	#define DAHL_H_HEADER_GUARD
	#define DAHLVER   "0.4.3a"

//  Check for user define overrides
#ifdef DAHL_ALL
	#define DAHL_USE_CLEAR 1
	#define DAHL_USE_LOG 1
	#define DAHL_USE_ASSERT 1

	#define DAHL_USE_PRINT 1
	#define DAHL_USE_INPUT 1
	#define DAHL_USE_PROFILE 1
	#define DAHL_USE_TIME 1
	#define DAHL_USE_UUID 1
#else
	#define DAHL_USE_CLEAR 1		//	Enable cross-platform clear screen

	#ifdef NO_DAHL_LOG
		#define DAHL_USE_LOG 0
	#else
		#define DAHL_USE_LOG 1		//	Enable logging
	#endif

	#ifdef NO_DAHL_ASSERT
		#define DAHL_USE_ASSERT 0
	#else
		#define DAHL_USE_ASSERT 1		//	Enable Asserts
	#endif


	//	These are disabled by default
	#ifdef DAHL_PRINT
		#define DAHL_USE_PRINT 1	//	Enable DAPrint
	#else
		#define DAHL_USE_PRINT 0
	#endif

	#ifdef DAHL_INPUT
		#define DAHL_USE_INPUT 1	//	Enable DAInput
	#else
		#define DAHL_USE_INPUT 0
	#endif

	#ifdef DAHL_PROFILE
		#define DAHL_USE_PROFILE 1	//	Enable DAProfile
	#else
		#define DAHL_USE_PROFILE 0
	#endif

	#ifdef DAHL_TIME
		#define DAHL_USE_TIME 1	//	Enable DATime
	#else
		#define DAHL_USE_TIME 0
	#endif

	#ifdef DAHL_UUID
		#define DAHL_USE_UUID 1	//	Enable DAUUID
	#else
		#define DAHL_USE_UUID 0
	#endif
#endif

////////////////////////////////////////////////////////////////////
//  -                    Platform Detection                    -  //
////////////////////////////////////////////////////////////////////
#ifdef _WIN32	//	Win32
	#include <Windows.h>
	#ifdef _WIN64	//	Win64
			#define DAHL_PLATFORM_WINDOWS
	#else
			#define DAHL_PLATFORM_WINDOWS
	#endif
#elif defined(__APPLE__) || defined(__MACH__)   //  Apple Platforms
	#include <TargetConditionals.h>
	#if TARGET_IPHONE_SIMULATOR == 1
		#define DAHL_PLATFORM_IOS_SIMULATOR
	#elif TARGET_OS_IPHONE == 1
		#define DAHL_PLATFORM_IOS     //  iOS
	#elif TARGET_OS_MAC == 1           //  MacOS
		#define DAHL_PLATFORM_MACOS
	#else
		#error "Unknown Apple platform!"
	#endif
//  Android is based off the linux kernel, so __ANDROID__ must be checked first
#elif defined(__ANDROID__)              //  Android
	#define DAHL_PLATFORM_ANDROID
#elif defined(__linux__)            //  Linux
	#define DAHL_PLATFORM_LINUX
#else	//  Unknown compiler/platform   //
	#error "Unknown platform!"
#endif  //    END platform detection

////////////////////////////////////////////////////////////////////
//  -    User defines - These are the defines you would use    -  //
////////////////////////////////////////////////////////////////////
#define dahlInit()           ::DAHL::Internal::daInit();	//	Initalize DAHL Colors
#define dahlResetColors()    ::DAHL::Internal::daReset();	//	Reset DAHL Colors
//	These are the defines used within functions
#define fgBlack              ::DAHL::Internal::Foreground::DACOLOR::daColorBlack			//	(0)  Foreground Black
#define fgRed                ::DAHL::Internal::Foreground::DACOLOR::daColorRed				//	(1)  Foreground Red
#define fgGreen              ::DAHL::Internal::Foreground::DACOLOR::daColorGreen			//	(2)  Foreground Green
#define fgYellow             ::DAHL::Internal::Foreground::DACOLOR::daColorYellow			//	(3)  Foreground Yellow
#define fgBlue               ::DAHL::Internal::Foreground::DACOLOR::daColorBlue				//	(4)  Foreground Blue
#define fgMagenta            ::DAHL::Internal::Foreground::DACOLOR::daColorMagenta			//	(5)  Foreground Magenta
#define fgCyan               ::DAHL::Internal::Foreground::DACOLOR::daColorCyan				//	(6)  Foreground Cyan
#define fgWhite              ::DAHL::Internal::Foreground::DACOLOR::daColorWhite			//	(7)  Foreground White
#define fgBrightBlack        ::DAHL::Internal::Foreground::DACOLOR::daColorBrightBlack		//	(8)  Foreground Black
#define fgBrightRed          ::DAHL::Internal::Foreground::DACOLOR::daColorBrightRed		//	(9)  Foreground Bright Red
#define fgBrightGreen        ::DAHL::Internal::Foreground::DACOLOR::daColorBrightGreen		//	(10) Foreground Bright Green
#define fgBrightYellow       ::DAHL::Internal::Foreground::DACOLOR::daColorBrightYellow		//	(11) Foreground Bright Yellow
#define fgBrightBlue         ::DAHL::Internal::Foreground::DACOLOR::daColorBrightBlue		//	(12) Foreground Bright Blue
#define fgBrightMagenta      ::DAHL::Internal::Foreground::DACOLOR::daColorBrightMagenta	//	(13) Foreground Bright Magenta
#define fgBrightCyan         ::DAHL::Internal::Foreground::DACOLOR::daColorBrightCyan		//	(14) Foreground Bright Cyan
#define fgBrightWhite        ::DAHL::Internal::Foreground::DACOLOR::daColorBrightWhite		//	(15) Foreground Bright White
#define fgUndefined          ::DAHL::Internal::Foreground::DACOLOR::daColorUndefined		//	(16) Foreground Undefined

#define bgBlack              ::DAHL::Internal::Background::DACOLOR::daColorBlack			//	(0)  Background Black
#define bgRed                ::DAHL::Internal::Background::DACOLOR::daColorRed				//	(1)  Background Red
#define bgGreen              ::DAHL::Internal::Background::DACOLOR::daColorGreen			//	(2)  Background Green
#define bgYellow             ::DAHL::Internal::Background::DACOLOR::daColorYellow			//	(3)  Background Yellow
#define bgBlue               ::DAHL::Internal::Background::DACOLOR::daColorBlue				//	(4)  Background Blue
#define bgMagenta            ::DAHL::Internal::Background::DACOLOR::daColorMagenta			//	(5)  Background Magenta
#define bgCyan               ::DAHL::Internal::Background::DACOLOR::daColorCyan				//	(6)  Background Cyan
#define bgWhite              ::DAHL::Internal::Background::DACOLOR::daColorWhite			//	(7)  Background White
#define bgBrightBlack        ::DAHL::Internal::Background::DACOLOR::daColorBrightBlack		//	(8)  Background Bright Black
#define bgBrightRed          ::DAHL::Internal::Background::DACOLOR::daColorBrightRed		//	(9)  Background Bright Red
#define bgBrightGreen        ::DAHL::Internal::Background::DACOLOR::daColorBrightGreen		//	(10) Background Bright Green
#define bgBrightYellow       ::DAHL::Internal::Background::DACOLOR::daColorBrightYellow		//	(11) Background Bright Yellow
#define bgBrightBlue         ::DAHL::Internal::Background::DACOLOR::daColorBrightBlue		//	(12) Background Bright Blue
#define bgBrightMagenta      ::DAHL::Internal::Background::DACOLOR::daColorBrightMagenta	//	(13) Background Bright Magenta
#define bgBrightCyan         ::DAHL::Internal::Background::DACOLOR::daColorBrightCyan		//	(14) Background Bright Cyan
#define bgBrightWhite        ::DAHL::Internal::Background::DACOLOR::daColorBrightWhite		//	(15) Background Bright White
#define bgUndefined          ::DAHL::Internal::Background::DACOLOR::daColorUndefined		//	(16) Background Undefined

#define FGColor              ::DAHL::Internal::Foreground::DACOLOR	//	typedef enum for foreground colors
#define BGColor              ::DAHL::Internal::Background::DACOLOR	//	typedef enum for background colors

#define FGdef                ::DAHL::Internal::daFGColors	//	Array that stores the platform-specific implementation of foreground colors
#define BGdef                ::DAHL::Internal::daBGColors	//	Array that stores the platform-specific implementation of background colors

//	These are just index values used in the daFG/BGColors array and shouldn't be used
constexpr int daBlack         = 0;	//	Black
constexpr int daRed           = 1;	//	Red
constexpr int daGreen         = 2;	//	Green
constexpr int daYellow        = 3;	//	Yellow
constexpr int daBlue          = 4;	//	Blue
constexpr int daMagenta       = 5;	//	Magenta
constexpr int daCyan          = 6;	//	Cyan
constexpr int daWhite         = 7;	//	White
constexpr int daBrightBlack   = 8;	//	Bright Black
constexpr int daBrightRed     = 9;	//	Bright Red
constexpr int daBrightGreen   = 10;	//	Bright Green
constexpr int daBrightYellow  = 11;	//	Bright Yellow
constexpr int daBrightBlue    = 12;	//	Bright Blue
constexpr int daBrightMagenta = 13;	//	Bright Magenta
constexpr int daBrightCyan    = 14;	//	Bright Cyan
constexpr int daBrightWhite   = 15;	//	Bright White
constexpr int daUndefined     = 16;	//	Undefined

#if DAHL_USE_LOG == 1	//  Log defines  //
	#define dahlLOG(severity, message)           ::DAHL::Log(severity,        message)	//	Log with log level
	#define dahlLOG_CRITICAL(message)            ::DAHL::Log(Level::Critical, message)	//	Log critical message
	#define dahlLOG_ERROR(message)               ::DAHL::Log(Level::Error,    message)	//	Log error message
	#define dahlLOG_WARN(message)                ::DAHL::Log(Level::Warn,     message)	//	Log warning message
	#define dahlLOG_INFO(message)                ::DAHL::Log(Level::Info,     message)	//	Log information
	#define dahlLOG_TRACE(message)               ::DAHL::Log(Level::Trace,    message)	//	Basically printing
#else	//	DALog isn't used - do nothing
	#define dahlLOG(severity, message)
	#define dahlLOG_CRITICAL(message)
	#define dahlLOG_ERROR(message)
	#define dahlLOG_WARN(message)
	#define dahlLOG_INFO(message)
	#define dahlLOG_TRACE(message)
#endif
#if DAHL_USE_ASSERT == 1	//  Assert defines  //
	#define dahlAssert(x, ...)               ::DAHL::daASSERT(x, __VA_ARGS__)
#else	//	DAAssert isn't used - do nothing
	#define dahlAssert(x, ...)
#endif
#if DAHL_USE_CLEAR == 1		//  Clear defines  //
	#define dahlClearScreen()                ::DAHL::ClearScreen()	//	Cross-platform clear screen
#endif
#if DAHL_USE_PRINT == 1		//  Print defines  //
	#define dahlPrint                        ::DAHL::Print::Print			//	std::cout w/color 
	#define dahlPrintl                       ::DAHL::Print::Printl		//	std::cout w/color and std::endl
	#define dahlPrintChar                    ::DAHL::Print::PrintChar		//	std::cout w/color only for specified section
	#define dahlSetDefaultColor              ::DAHL::Print::SetDefaults	//	Set the default printing color
	#ifdef DAHL_PLATFORM_WINDOWS
		#define dahlPrintRBG                 ::DAHL::Print::PrintRGB		//	Prints RBG value (Windows ONLY!)
	#endif
#endif
#if DAHL_USE_INPUT == 1		//  Input defines  //
	#define dahlEvent               ::DAHL::Input::Event
	#define dahlEventDispatcher     ::DAHL::Input::EventDispatcher
	//	Key defines
	#define dahlKey                 ::DAHL::Input::KeyCode				//	The KeyCode enum class
	#define dahlKeyEvent            ::DAHL::Input::KeyEvent				//	A generic KeyEvent (shouldn't be used)
	#define dahlKeyPressedEvent     ::DAHL::Input::KeyPressedEvent		//	When a key is pressed down (also contain's repeat count)
	#define dahlKeyReleasedEvent    ::DAHL::Input::KeyReleasedEvent		//	When a key is released
	#define dahlKeyTypedEvent       ::DAHL::Input::KeyTypedEvent			//	When a key is typed (modifiers applied differently)
	//	Mouse defines
	#define dahlMouseCode                ::DAHL::Input::MouseCode					//	The MouseCode enum class
	#define dahlMouseMovedEvent          ::DAHL::Input::MouseMovedEvent			//	When the mouse has moved
	#define dahlMouseScrolledEvent       ::DAHL::Input::MouseScrolledEvent		//	When the mouse is scrolled
	#define dahlMouseButtonEvent         ::DAHL::Input::MouseButtonEvent			//	A generic MouseButtonEvent (shouldn't be used)
	#define dahlMouseButtonPressedEvent  ::DAHL::Input::MouseButtonPressedEvent	//	When a mouse button is pressed
	#define dahlMouseButtonReleasedEvent ::DAHL::Input::MouseButtonReleasedEvent	//	When a mouse button is released

	#define DAHL_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }
#endif
#if DAHL_USE_PROFILE == 1	//  Profile defines  //
	// Resolve which function signature macro will be used. Note that this only
	// is resolved when the (pre)compiler starts, so the syntax highlighting
	// could mark the wrong one in your editor!
	#if defined(__GNUC__) || (defined(__MWERKS__) && (__MWERKS__ >= 0x3000)) || (defined(__ICC) && (__ICC >= 600)) || defined(__ghs__)
		#define DAHL_FUNC_SIG __PRETTY_FUNCTION__
	#elif defined(__DMC__) && (__DMC__ >= 0x810)
		#define DAHL_FUNC_SIG __PRETTY_FUNCTION__
	#elif (defined(__FUNCSIG__) || (_MSC_VER))
		#define DAHL_FUNC_SIG __FUNCSIG__
	#elif (defined(__INTEL_COMPILER) && (__INTEL_COMPILER >= 600)) || (defined(__IBMCPP__) && (__IBMCPP__ >= 500))
		#define DAHL_FUNC_SIG __FUNCTION__
	#elif defined(__BORLANDC__) && (__BORLANDC__ >= 0x550)
		#define DAHL_FUNC_SIG __FUNC__
	#elif defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901)
		#define DAHL_FUNC_SIG __func__
	#elif defined(__cplusplus) && (__cplusplus >= 201103)
		#define DAHL_FUNC_SIG __func__
	#else
		#define DAHL_FUNC_SIG "Dr_FUNC_SIG unknown!"
	#endif

	#define dahlPROFILE_BEGIN_SESSION(name, filepath) ::DAHL::Profile::daInstrumentor::Get().BeginSession(name, filepath)
	#define dahlPROFILE_END_SESSION() ::DAHL::Profile::daInstrumentor::Get().EndSession()
	#define dahlPROFILE_SCOPE(name) constexpr auto fixedName = ::DAHL::Profile::daInstrumentorUtils::CleanupOutputString(name, "__cdecl ");\
																			::DAHL::Profile::daInstrumentationTimer timer##__LINE__(fixedName.Data)
	#define dahlPROFILE_FUNCTION() dahlPROFILE_SCOPE(DAHL_FUNC_SIG)

#else	//	not using DAProfile - do nothing
	#define dahlPROFILE_BEGIN_SESSION(name, filepath)
	#define dahlPROFILE_END_SESSION()
	#define dahlPROFILE_SCOPE(name)
	#define dahlPROFILE_FUNCTION()
#endif
#if DAHL_USE_TIME == 1	//  Time defines  //
	#define dahlTimer          ::DAHL::Time::Timer
	#define dahlTimestep       ::DAHL::Time::Timestep
#endif

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                           //
//                                            BEGIN DEFINITIONS                                              //
//                                                                                                           //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <stdio.h>

#if DAHL_USE_PROFILE == 1
	#include <sstream>
	#include <algorithm>
	#include <chrono>
	#include <fstream>
	#include <iomanip>
	#include <thread>
	#include <mutex>
#else
	#ifdef DAHL_USE_TIME
		#include <chrono>
	#endif
#endif
#if DAHL_USE_INPUT == 1
	#include <ostream>
#endif

#if DAHL_USE_UUID == 1
	#include <random>
#endif

////////////////////////////////////////////////////////////////////////////////
//  --------------------------------  DAHL  -------------------------------  //
////////////////////////////////////////////////////////////////////////////////
namespace DAHL::Internal
{
	namespace Foreground
	{
		typedef enum class DACOLOR
		{
			daColorBlack         = 0,	//	Foreground Black
			daColorRed           = 1,	//	Foreground Red
			daColorGreen         = 2,	//	Foreground Green
			daColorYellow        = 3,	//	Foreground Yellow
			daColorBlue          = 4,	//	Foreground Blue
			daColorMagenta       = 5,	//	Foreground Magenta
			daColorCyan          = 6,	//	Foreground Cyan
			daColorWhite         = 7,	//	Foreground White

			daColorBrightBlack   = 8,	//	Foreground Bright Black
			daColorBrightRed     = 9,	//	Foreground Bright Red
			daColorBrightGreen   = 10,	//	Foreground Bright Green
			daColorBrightYellow  = 11,	//	Foreground Bright Yellow
			daColorBrightBlue    = 12,	//	Foreground Bright Blue
			daColorBrightMagenta = 13,	//	Foreground Bright Magenta
			daColorBrightCyan    = 14,	//	Foreground Bright Cyan
			daColorBrightWhite   = 15,	//	Foreground Bright White
			daColorUndefined     = 16	//	Foreground Undefined Color
		} daColor;
	}	//	END namespace Foreground

	namespace Background
	{
		typedef enum class DACOLOR
		{
			daColorBlack         = 0,	//	Background Black
			daColorRed           = 1,	//	Background Red
			daColorGreen         = 2,	//	Background Green
			daColorYellow        = 3,	//	Background Yellow
			daColorBlue          = 4,	//	Background Blue
			daColorMagenta       = 5,	//	Background Magenta
			daColorCyan          = 6,	//	Background Cyan
			daColorWhite         = 7,	//	Background White
			
			daColorBrightBlack   = 8,	//	Background Bright Black
			daColorBrightRed     = 9,	//	Background Bright Red
			daColorBrightGreen   = 10,	//	Background Bright Green
			daColorBrightYellow  = 11,	//	Background Bright Yellow
			daColorBrightBlue    = 12,	//	Background Bright Blue
			daColorBrightMagenta = 13,	//	Background Bright Magenta
			daColorBrightCyan    = 14,	//	Background Bright Cyan
			daColorBrightWhite   = 15,	//	Background Bright White
			daColorUndefined     = 16	//	Background Undefined Color
		} daColor;
	}	//	END namespace Background

	typedef struct DAATTRIBUTES	//	Possibly un-needed
	{
		#ifdef DAHL_PLATFORM_WINDOWS
			WORD Foreground;
			WORD Background;
		#else
			const char* Foreground;
			const char* Background;
		#endif
	} daAttributes;

	//	These are user-end functions
	void daShowCursor(bool enable);

		//  These shouldn't be called by the user  //
	// For printing functionality, please #define DAHL_PRINT
	void Set(FGColor fgColor, BGColor bgColor);
	//	Print
	void Print(FGColor fgColor, BGColor bgColor, const char* message);
	//	Print line
	void Printl(FGColor fgColor, BGColor bgColor, const char* message);
	//	Print characters
	void PrintChar(FGColor fgColor, BGColor bgColor, const char* character);

	void daReset();
	void End();


}	//	END namespace DAHL::Internal

////////////////////////////////////////////////////////////////////////////////
//  --------------------------------  DALog  -------------------------------  //
////////////////////////////////////////////////////////////////////////////////
#if DAHL_USE_LOG == 1
		//	Enum Class for determining Log levels
	enum class Level
	{
		Trace    = 0,	//	Trace:		Unimportant, but worth logging?
		Info     = 1,	//	Info:		Log info to console
		Warn     = 2,	//	Warn:		A warning, something isn't quite right
		Error    = 3,	//	Error:		An error, something is wrong
		Critical = 4	//	Critical:	Critical, exit program
	};

	namespace DAHL
	{
		void Log(Level severity, const char* message);

		//  Overloads
		void Log(Level severity);
		void Log(Level severity, std::string& message);

	}  //  END namespace DAHL

#endif	//	DALog

////////////////////////////////////////////////////////////////////////////////
//  -----------------------------  DAAssert  -------------------------------  //
////////////////////////////////////////////////////////////////////////////////
#if DAHL_USE_ASSERT == 1
	namespace DAHL
	{
		#ifdef DAHL_USE_LOG
			#define daASSERT(x, ...) { if(!(x)) { daLOG(Level::Error, "Assertion Failed: " + std::to_string(__VA_ARGS__)); } }
		#else
			#define daASSERT(x, ...) { if(!(x)) { std::cout << "Assertion Failed: " << std::to_string(__VA_ARGS__)) << std::endl; } }
		#endif
	}	//	END namespace DAHL

#endif	//	DAAssert

////////////////////////////////////////////////////////////////////////////////
//  ------------------------------  DAClear  -------------------------------  //
////////////////////////////////////////////////////////////////////////////////
#if DAHL_USE_CLEAR == 1
	namespace DAHL
	{
		void ClearScreen();
	}	//	END namespace DAHL
#endif	//	DAClear

////////////////////////////////////////////////////////////////////////////////
//  ------------------------------  DAPrint  -------------------------------  //
////////////////////////////////////////////////////////////////////////////////
#if DAHL_USE_PRINT == 1
	namespace DAHL::Print
	{
		//	Print to screen
		void Print(const char* message);	//	This uses the user default colors
		void Print(FGColor fgColor, const char* message);
		void Print(BGColor bgColor, const char* message);
		void Print(FGColor fgColor, BGColor bgColor, const char* message);

		//	Print a single line to screen
		void Printl(const char* message);	//	This uses the user default colors
		void Printl(FGColor fgColor, const char* message);
		void Printl(BGColor bgColor, const char* message);
		void Printl(FGColor fgColor, BGColor bgColor, const char* message);

		//	Print colored characters to screen then resets
		void PrintChar(const char* character);	//	This uses the user's default colors
		void PrintChar(FGColor fgColor, const char* character);
		void PrintChar(BGColor bgColor, const char* character);
		void PrintChar(FGColor fgColor, BGColor bgColor, const char* character);

		void SetDefaults(FGColor fgColor, BGColor bgColor);
		inline void SetDefaults(FGColor fgColor) { SetDefaults(fgColor, bgUndefined); }
		inline void SetDefaults(BGColor bgColor) { SetDefaults(fgWhite, bgColor); }

		#ifdef DAHL_PLATFORM_WINDOWS
			void PrintRGB(COLORREF rbgValue);
		#endif

		int daGetFGvalue(FGColor fgColor);
		int daGetBGvalue(BGColor bgColor);
	}	//	END namespace DAHL::Print

#endif	//	DAPrint

////////////////////////////////////////////////////////////////////////////////
//  ------------------------------  DAInput  -------------------------------  //
////////////////////////////////////////////////////////////////////////////////
#if DAHL_USE_INPUT == 1
	namespace DAHL::Input
	{
		//	Defines keycodes
		typedef enum class KeyCode : uint16_t
		{
		#ifdef DAHL_PLATFORM_WINDOWS
			Space        = VK_SPACE,
			Apostrophe   = NULL,
			Comma        = NULL,
			Minus        = NULL,
			Period       = NULL,
			Slash        = NULL,

			D0           = 0x30,
			D1           = 0x31,
			D2           = 0x32,
			D3           = 0x33,
			D4           = 0x34,
			D5           = 0x35,
			D6           = 0x36,
			D7           = 0x37,
			D8           = 0x38,
			D9           = 0x39,

			Semicolon    = NULL,
			Equal        = NULL,

			A            = 0x41,
			B            = 0x42,
			C            = 0x43,
			D            = 0x44,
			E            = 0x45,
			F            = 0x46,
			G            = 0x47,
			H            = 0x48,
			I            = 0x49,
			J            = 0x4A,
			K            = 0x4B,
			L            = 0x4C,
			M            = 0x4D,
			N            = 0x4E,
			O            = 0x4F,
			P            = 0x50,
			Q            = 0x51,
			R            = 0x52,
			S            = 0x53,
			T            = 0x54,
			U            = 0x55,
			V            = 0x56,
			W            = 0x57,
			X            = 0x58,
			Y            = 0x59,
			Z            = 0x5A,

			LeftBracket  = NULL,
			BackSlash    = NULL,
			RightBracket = NULL,
			GraveAccent  = NULL,

			World1       = NULL,
			World2       = NULL,

			//  Function Keys  //	= 
			Escape       = VK_ESCAPE,
			Enter        = VK_RETURN,
			Tab          = VK_TAB,
			Backspace    = VK_BACK,
			Insert       = VK_INSERT,
			Delete       = VK_DELETE,
			Right        = VK_RIGHT,
			Left         = VK_LEFT,
			Down         = VK_DOWN,
			Up           = VK_UP,
			PageUp       = VK_PRIOR,
			PageDown     = VK_NEXT,
			Home         = VK_HOME,
			End          = VK_END,
			CapsLock     = VK_CAPITAL,
			ScrollLock   = VK_SCROLL,
			NumLock      = VK_NUMLOCK,
			PrintScreen  = VK_SNAPSHOT,
			Pause        = VK_PAUSE,
			F1           = VK_F1,
			F2           = VK_F2,
			F3           = VK_F3,
			F4           = VK_F4,
			F5           = VK_F5,
			F6           = VK_F6,
			F7           = VK_F7,
			F8           = VK_F8,
			F9           = VK_F9,
			F10          = VK_F10,
			F11          = VK_F11,
			F12          = VK_F12,
			F13          = VK_F13,
			F14          = VK_F14,
			F15          = VK_F15,
			F16          = VK_F16,
			F17          = VK_F17,
			F18          = VK_F18,
			F19          = VK_F19,
			F20          = VK_F20,
			F21          = VK_F21,
			F22          = VK_F22,
			F23          = VK_F23,
			F24          = VK_F24,
			F25          = NULL,

			//  Keypad //
			KP0          = VK_NUMPAD0,
			KP1          = VK_NUMPAD1,
			KP2          = VK_NUMPAD2,
			KP3          = VK_NUMPAD3,
			KP4          = VK_NUMPAD4,
			KP5          = VK_NUMPAD5,
			KP6          = VK_NUMPAD6,
			KP7          = VK_NUMPAD7,
			KP8          = VK_NUMPAD8,
			KP9          = VK_NUMPAD9,
			KPDecimal    = VK_DECIMAL,
			KPDivide     = VK_DIVIDE,
			KPMultiply   = VK_MULTIPLY,
			KPSubtract   = VK_SUBTRACT,
			KPAdd        = VK_ADD,
			KPEnter      = VK_RETURN,
			KPEqual      = NULL,

			LeftShift    = VK_LSHIFT,
			LeftControl  = VK_LCONTROL,
			LeftAlt      = VK_LMENU,
			LeftSuper    = VK_LWIN,
			RightShift   = VK_RSHIFT,
			RightControl = VK_RCONTROL,
			RightAlt     = VK_RMENU,
			RightSuper   = VK_RWIN,
			Menu         = VK_MENU
#else
			Space        = "SPCE",
			Apostrophe   = "AC11",
			Comma        = "AB08",
			Minus        = "AE11",
			Period       = "AB09",
			Slash        = "AB10",

			D0           = "AE10",
			D1           = "AE01",
			D2           = "AE02",
			D3           = "AE03",
			D4           = "AE04",
			D5           = "AE05",
			D6           = "AE06",
			D7           = "AE07",
			D8           = "AE08",
			D9           = "AE09",

			Semicolon    = "AC10",
			Equal        = "AE12",

			A            = "AC01",
			B            = "AB05",
			C            = "AB03",
			D            = "AC03",
			E            = "AD03",
			F            = "AC04",
			G            = "AC05",
			H            = "AC06",
			I            = "AD08",
			J            = "AC07",
			K            = "AC08",
			L            = "AC09",
			M            = "AB07",
			N            = "AB06",
			O            = "AD09",
			P            = "AD10",
			Q            = "AD01",
			R            = "AD04",
			S            = "AC02",
			T            = "AD05",
			U            = "AD07",
			V            = "AB04",
			W            = "AD02",
			X            = "AB02",
			Y            = "AD06",
			Z            = "AB01",

			LeftBracket  = "AD11",
			BackSlash    = "BKSL",
			RightBracket = "AD12",
			GraveAccent  = "TLDE",

			World1       = "LSGT",
			World2       = "",

			//  Function Keys  //	= 
			Escape       = "ESC",
			Enter        = "RTRN",
			Tab          = "TAB",
			Backspace    = "BKSP",
			Insert       = "INS",
			Delete       = "DELE",
			Right        = "RGHT",
			Left         = "LEFT",
			Down         = "DOWN",
			Up           = "UP",
			PageUp       = "PGUP",
			PageDown     = "PGDN",
			Home         = "HOME",
			End          = "END",
			CapsLock     = "CAPS",
			ScrollLock   = "SCLK",
			NumLock      = "NMLK",
			PrintScreen  = "PRSC",
			Pause        = "PAUS",
			F1           = "FK01",
			F2           = "FK02",
			F3           = "FK03",
			F4           = "FK04",
			F5           = "FK05",
			F6           = "FK06",
			F7           = "FK07",
			F8           = "FK08",
			F9           = "FK09",
			F10          = "FK10",
			F11          = "FK11",
			F12          = "FK12",
			F13          = "FK13",
			F14          = "FK14",
			F15          = "FK15",
			F16          = "FK16",
			F17          = "FK17",
			F18          = "FK18",
			F19          = "FK19",
			F20          = "FK20",
			F21          = "FK21",
			F22          = "FK22",
			F23          = "FK23",
			F24          = "FK24",
			F25          = "FK25",

			//  Keypad //
			KP0          = "KP0",
			KP1          = "KP1",
			KP2          = "KP2",
			KP3          = "KP3",
			KP4          = "KP4",
			KP5          = "KP5",
			KP6          = "KP6",
			KP7          = "KP7",
			KP8          = "KP8",
			KP9          = "KP9",
			KPDecimal    = "KPDL",
			KPDivide     = "KPDV",
			KPMultiply   = "KPMU",
			KPSubtract   = "KPSU",
			KPAdd        = "KPAD",
			KPEnter      = "KPEN",
			KPEqual      = "KPEQ",

			LeftShift    = "LFSH",
			LeftControl  = "LCTL",
			LeftAlt      = "LALT",
			LeftSuper    = "LWIN",
			RightShift   = "RTSH",
			RightControl = "RCTL",
			RightAlt     = "RALT",
			RightSuper   = "RWIN",
			Menu         = "MENU"
		#endif
		} Key;

		inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
		{
			os << static_cast<int32_t>(keyCode);
			return os;
		}

		//	Abstracted Key defines
	#define DAHL_KEY_SPACE           ::DAHL::Input::daKey::Space
	#define DAHL_KEY_APOSTROPHE      ::DAHL::Input::daKey::Apostrophe    /* ' */
	#define DAHL_KEY_COMMA           ::DAHL::Input::daKey::Comma         /* , */
	#define DAHL_KEY_MINUS           ::DAHL::Input::daKey::Minus         /* - */
	#define DAHL_KEY_PERIOD          ::DAHL::Input::daKey::Period        /* . */
	#define DAHL_KEY_SLASH           ::DAHL::Input::daKey::Slash         /* / */
	#define DAHL_KEY_0               ::DAHL::Input::daKey::D0
	#define DAHL_KEY_1               ::DAHL::Input::daKey::D1
	#define DAHL_KEY_2               ::DAHL::Input::daKey::D2
	#define DAHL_KEY_3               ::DAHL::Input::daKey::D3
	#define DAHL_KEY_4               ::DAHL::Input::daKey::D4
	#define DAHL_KEY_5               ::DAHL::Input::daKey::D5
	#define DAHL_KEY_6               ::DAHL::Input::daKey::D6
	#define DAHL_KEY_7               ::DAHL::Input::daKey::D7
	#define DAHL_KEY_8               ::DAHL::Input::daKey::D8
	#define DAHL_KEY_9               ::DAHL::Input::daKey::D9
	#define DAHL_KEY_SEMICOLON       ::DAHL::Input::daKey::Semicolon     /* ; */
	#define DAHL_KEY_EQUAL           ::DAHL::Input::daKey::Equal         /* = */
	#define DAHL_KEY_A               ::DAHL::Input::daKey::A
	#define DAHL_KEY_B               ::DAHL::Input::daKey::B
	#define DAHL_KEY_C               ::DAHL::Input::daKey::C
	#define DAHL_KEY_D               ::DAHL::Input::daKey::D
	#define DAHL_KEY_E               ::DAHL::Input::daKey::E
	#define DAHL_KEY_F               ::DAHL::Input::daKey::F
	#define DAHL_KEY_G               ::DAHL::Input::daKey::G
	#define DAHL_KEY_H               ::DAHL::Input::daKey::H
	#define DAHL_KEY_I               ::DAHL::Input::daKey::I
	#define DAHL_KEY_J               ::DAHL::Input::daKey::J
	#define DAHL_KEY_K               ::DAHL::Input::daKey::K
	#define DAHL_KEY_L               ::DAHL::Input::daKey::L
	#define DAHL_KEY_M               ::DAHL::Input::daKey::M
	#define DAHL_KEY_N               ::DAHL::Input::daKey::N
	#define DAHL_KEY_O               ::DAHL::Input::daKey::O
	#define DAHL_KEY_P               ::DAHL::Input::daKey::P
	#define DAHL_KEY_Q               ::DAHL::Input::daKey::Q
	#define DAHL_KEY_R               ::DAHL::Input::daKey::R
	#define DAHL_KEY_S               ::DAHL::Input::daKey::S
	#define DAHL_KEY_T               ::DAHL::Input::daKey::T
	#define DAHL_KEY_U               ::DAHL::Input::daKey::U
	#define DAHL_KEY_V               ::DAHL::Input::daKey::V
	#define DAHL_KEY_W               ::DAHL::Input::daKey::W
	#define DAHL_KEY_X               ::DAHL::Input::daKey::X
	#define DAHL_KEY_Y               ::DAHL::Input::daKey::Y
	#define DAHL_KEY_Z               ::DAHL::Input::daKey::Z
	#define DAHL_KEY_LEFT_BRACKET    ::DAHL::Input::daKey::LeftBracket   /* [ */
	#define DAHL_KEY_BACKSLASH       ::DAHL::Input::daKey::BackSlash     /* \ */
	#define DAHL_KEY_RIGHT_BRACKET   ::DAHL::Input::daKey::RightBracket  /* ] */
	#define DAHL_KEY_GRAVE_ACCENT    ::DAHL::Input::daKey::GraveAccent   /* ` */
	#define DAHL_KEY_WORLD_1         ::DAHL::Input::daKey::World1        /* non-US #1 */
	#define DAHL_KEY_WORLD_2         ::DAHL::Input::daKey::World2        /* non-US #2 */

			/* Function keys */
	#define DAHL_KEY_ESCAPE          ::DAHL::Input::daKey::Escape
	#define DAHL_KEY_ENTER           ::DAHL::Input::daKey::Enter
	#define DAHL_KEY_TAB             ::DAHL::Input::daKey::Tab
	#define DAHL_KEY_BACKSPACE       ::DAHL::Input::daKey::Backspace
	#define DAHL_KEY_INSERT          ::DAHL::Input::daKey::Insert
	#define DAHL_KEY_DELETE          ::DAHL::Input::daKey::Delete
	#define DAHL_KEY_RIGHT           ::DAHL::Input::daKey::Right
	#define DAHL_KEY_LEFT            ::DAHL::Input::daKey::Left
	#define DAHL_KEY_DOWN            ::DAHL::Input::daKey::Down
	#define DAHL_KEY_UP              ::DAHL::Input::daKey::Up
	#define DAHL_KEY_PAGE_UP         ::DAHL::Input::daKey::PageUp
	#define DAHL_KEY_PAGE_DOWN       ::DAHL::Input::daKey::PageDown
	#define DAHL_KEY_HOME            ::DAHL::Input::daKey::Home
	#define DAHL_KEY_END             ::DAHL::Input::daKey::End
	#define DAHL_KEY_CAPS_LOCK       ::DAHL::Input::daKey::CapsLock
	#define DAHL_KEY_SCROLL_LOCK     ::DAHL::Input::daKey::ScrollLock
	#define DAHL_KEY_NUM_LOCK        ::DAHL::Input::daKey::NumLock
	#define DAHL_KEY_PRINT_SCREEN    ::DAHL::Input::daKey::PrintScreen
	#define DAHL_KEY_PAUSE           ::DAHL::Input::daKey::Pause
	#define DAHL_KEY_F1              ::DAHL::Input::daKey::F1
	#define DAHL_KEY_F2              ::DAHL::Input::daKey::F2
	#define DAHL_KEY_F3              ::DAHL::Input::daKey::F3
	#define DAHL_KEY_F4              ::DAHL::Input::daKey::F4
	#define DAHL_KEY_F5              ::DAHL::Input::daKey::F5
	#define DAHL_KEY_F6              ::DAHL::Input::daKey::F6
	#define DAHL_KEY_F7              ::DAHL::Input::daKey::F7
	#define DAHL_KEY_F8              ::DAHL::Input::daKey::F8
	#define DAHL_KEY_F9              ::DAHL::Input::daKey::F9
	#define DAHL_KEY_F10             ::DAHL::Input::daKey::F10
	#define DAHL_KEY_F11             ::DAHL::Input::daKey::F11
	#define DAHL_KEY_F12             ::DAHL::Input::daKey::F12
	#define DAHL_KEY_F13             ::DAHL::Input::daKey::F13
	#define DAHL_KEY_F14             ::DAHL::Input::daKey::F14
	#define DAHL_KEY_F15             ::DAHL::Input::daKey::F15
	#define DAHL_KEY_F16             ::DAHL::Input::daKey::F16
	#define DAHL_KEY_F17             ::DAHL::Input::daKey::F17
	#define DAHL_KEY_F18             ::DAHL::Input::daKey::F18
	#define DAHL_KEY_F19             ::DAHL::Input::daKey::F19
	#define DAHL_KEY_F20             ::DAHL::Input::daKey::F20
	#define DAHL_KEY_F21             ::DAHL::Input::daKey::F21
	#define DAHL_KEY_F22             ::DAHL::Input::daKey::F22
	#define DAHL_KEY_F23             ::DAHL::Input::daKey::F23
	#define DAHL_KEY_F24             ::DAHL::Input::daKey::F24
	#define DAHL_KEY_F25             ::DAHL::Input::daKey::F25

	/* Keypad */
	#define DAHL_KEY_KP_0            ::DAHL::Input::daKey::KP0
	#define DAHL_KEY_KP_1            ::DAHL::Input::daKey::KP1
	#define DAHL_KEY_KP_2            ::DAHL::Input::daKey::KP2
	#define DAHL_KEY_KP_3            ::DAHL::Input::daKey::KP3
	#define DAHL_KEY_KP_4            ::DAHL::Input::daKey::KP4
	#define DAHL_KEY_KP_5            ::DAHL::Input::daKey::KP5
	#define DAHL_KEY_KP_6            ::DAHL::Input::daKey::KP6
	#define DAHL_KEY_KP_7            ::DAHL::Input::daKey::KP7
	#define DAHL_KEY_KP_8            ::DAHL::Input::daKey::KP8
	#define DAHL_KEY_KP_9            ::DAHL::Input::daKey::KP9
	#define DAHL_KEY_KP_DECIMAL      ::DAHL::Input::daKey::KPDecimal
	#define DAHL_KEY_KP_DIVIDE       ::DAHL::Input::daKey::KPDivide
	#define DAHL_KEY_KP_MULTIPLY     ::DAHL::Input::daKey::KPMultiply
	#define DAHL_KEY_KP_SUBTRACT     ::DAHL::Input::daKey::KPSubtract
	#define DAHL_KEY_KP_ADD          ::DAHL::Input::daKey::KPAdd
	#define DAHL_KEY_KP_ENTER        ::DAHL::Input::daKey::KPEnter
	#define DAHL_KEY_KP_EQUAL        ::DAHL::Input::daKey::KPEqual

	#define DAHL_KEY_LEFT_SHIFT      ::DAHL::Input::daKey::LeftShift
	#define DAHL_KEY_LEFT_CONTROL    ::DAHL::Input::daKey::LeftControl
	#define DAHL_KEY_LEFT_ALT        ::DAHL::Input::daKey::LeftAlt
	#define DAHL_KEY_LEFT_SUPER      ::DAHL::Input::daKey::LeftSuper
	#define DAHL_KEY_RIGHT_SHIFT     ::DAHL::Input::daKey::RightShift
	#define DAHL_KEY_RIGHT_CONTROL   ::DAHL::Input::daKey::RightControl
	#define DAHL_KEY_RIGHT_ALT       ::DAHL::Input::daKey::RightAlt
	#define DAHL_KEY_RIGHT_SUPER     ::DAHL::Input::daKey::RightSuper
	#define DAHL_KEY_MENU            ::DAHL::Input::daKey::Menu

		//	Defines MouseCodes
		typedef enum class MouseCode : uint16_t
		{
			Button0 = 0,
			Button1 = 1,
			Button2 = 2,
			Button3 = 3,
			Button4 = 4,
			Button5 = 5,
			Button6 = 6,
			Button7 = 7,

			ButtonLast = Button7,
			ButtonLeft = Button0,
			ButtonRight = Button1,
			ButtonMiddle = Button2
		} Mouse;

		inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
		{
			os << static_cast<int32_t>(mouseCode);
			return os;
		}

	#define DAHL_MOUSE_BUTTON_0		::DAHL::Input::daMouse::Button0
	#define DAHL_MOUSE_BUTTON_1		::DAHL::Input::daMouse::Button1
	#define DAHL_MOUSE_BUTTON_2		::DAHL::Input::daMouse::Button2
	#define DAHL_MOUSE_BUTTON_3		::DAHL::Input::daMouse::Button3
	#define DAHL_MOUSE_BUTTON_4		::DAHL::Input::daMouse::Button4
	#define DAHL_MOUSE_BUTTON_5		::DAHL::Input::daMouse::Button5
	#define DAHL_MOUSE_BUTTON_6		::DAHL::Input::daMouse::Button6
	#define DAHL_MOUSE_BUTTON_7		::DAHL::Input::daMouse::Button7
	#define DAHL_MOUSE_BUTTON_LAST	::DAHL::Input::daMouse::ButtonLast
	#define DAHL_MOUSE_BUTTON_LEFT	::DAHL::Input::daMouse::ButtonLeft
	#define DAHL_MOUSE_BUTTON_RIGHT	::DAHL::Input::daMouse::ButtonRight
	#define DAHL_MOUSE_BUTTON_MIDDLE	::DAHL::Input::daMouse::ButtonMiddle

		enum class EventType
		{
			None = 0,
			KeyPressed, KeyReleased, KeyTyped,
			MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
		};

		enum EventCategory
		{
			None = 0,
			EventCategoryInput = 0x00,
			EventCategoryKeyboard = 0x01,
			EventCategoryMouse = 0x02,
			EventCategoryMouseButton = 0x03
		};

	#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
																virtual EventType GetEventType() const override { return GetStaticType(); }\
																virtual const char* GetName() const override { return #type; }

	#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

		// Events
		class Event
		{
		public:
			virtual ~Event() = default;

			bool Handled = false;

			virtual EventType GetEventType() const = 0;
			virtual const char* GetName() const = 0;
			virtual int GetCategoryFlags() const = 0;
			virtual std::string ToString() const { return GetName(); }

			inline bool IsInCategory(EventCategory category)
			{
				return GetCategoryFlags() & category;
			}
		};

		class EventDispatcher
		{
		public:
			inline EventDispatcher(Event& event)
				: m_Event(event)
			{}

			//	F is deduced by compiler
			template<typename T, typename F>
			inline bool Dispatch(const F& func)
			{
				if (m_Event.GetEventType() == T::GetStaticType())
				{
					m_Event.Handled |= func(static_cast<T&>(m_Event));
					return true;
				}
				return false;
			}
		private:
			Event& m_Event;
		};

		inline std::ostream& operator<<(std::ostream& os, const Event& e)
		{
			return os << e.ToString();
		}

		// Input
		class Input
		{
		public:
			static bool IsKeyPressed(KeyCode key);

			static bool IsMouseButtonPressed(MouseCode button);
			static std::pair<float, float> GetMousePosition();
			static float GetMouseX();
			static float GetMouseY();
		};

		// KeyEvents
		class KeyEvent : public Event
		{
		public:
			inline KeyCode GetKeyCode() const { return m_KeyCode; }

			EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
		protected:
			inline KeyEvent(KeyCode keycode)
				: m_KeyCode(keycode) {}

			KeyCode m_KeyCode;
		};

		class KeyPressedEvent : public KeyEvent
		{
		public:
			inline KeyPressedEvent(KeyCode keycode, int repeatCount)
				: KeyEvent(keycode), m_RepeatCount(repeatCount) {}

			inline int GetRepeatCount() const { return m_RepeatCount; }

			inline std::string ToString() const override
			{
				std::stringstream ss;
				ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
				return ss.str();
			}

			EVENT_CLASS_TYPE(KeyPressed)
		private:
			int m_RepeatCount;
		};

		class KeyReleasedEvent : public KeyEvent
		{
			inline KeyReleasedEvent(KeyCode keycode)
				: KeyEvent(keycode) {}

			inline std::string ToString() const override
			{
				std::stringstream ss;
				ss << "KeyReleasedEvent: " << m_KeyCode;
				return ss.str();
			}

			EVENT_CLASS_TYPE(KeyReleased)
		};

		class KeyTypedEvent : public KeyEvent
		{
		public:
			inline KeyTypedEvent(KeyCode keycode)
				: KeyEvent(keycode) {}

			std::string ToString() const override
			{
				std::stringstream ss;
				ss << "KeyTypedEvent: " << m_KeyCode;
				return ss.str();
			}

			EVENT_CLASS_TYPE(KeyTyped)
		};


		//	MouseEvent 

		class MouseMovedEvent : public Event
		{
			inline MouseMovedEvent(float x, float y)
				: m_MouseX(x), m_MouseY(y) {}

			inline float GetX() const { return m_MouseX; }
			inline float GetY() const { return m_MouseY; }

			inline std::string ToString() const override
			{
				std::stringstream ss;
				ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
				return ss.str();
			}

			EVENT_CLASS_TYPE(MouseMoved)
				EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput | EventCategoryMouseButton)
		private:
			float m_MouseX, m_MouseY;
		};

		class MouseScrolledEvent : public Event
		{
		public:
			inline MouseScrolledEvent(float xOffset, float yOffset)
				: m_XOffset(xOffset), m_YOffset(yOffset) {}

			inline float GetXOffset() const { return m_XOffset; }
			inline float GetYOffset() const { return m_YOffset; }

			inline std::string ToString() const override
			{
				std::stringstream ss;
				ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
				return ss.str();
			}

			EVENT_CLASS_TYPE(MouseScrolled)
				EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
		private:
			float m_XOffset, m_YOffset;
		};

		class MouseButtonEvent : public Event
		{
		public:
			inline MouseCode GetMouseButton() const { return m_Button; }

			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
		protected:
			MouseButtonEvent(MouseCode button)
				: m_Button(button) {}

			MouseCode m_Button;
		};

		class MouseButtonPressedEvent : public MouseButtonEvent
		{
		public:
			inline MouseButtonPressedEvent(MouseCode button)
				: MouseButtonEvent(button) {}

			inline std::string ToString() const override
			{
				std::stringstream ss;
				ss << "MouseButtonPressedEvent: " << m_Button;
				return ss.str();
			}

			EVENT_CLASS_TYPE(MouseButtonPressed)
		};

		class MouseButtonReleasedEvent : public MouseButtonEvent
		{
		public:
			inline MouseButtonReleasedEvent(MouseCode button)
				: MouseButtonEvent(button) {}

			inline std::string ToString() const override
			{
				std::stringstream ss;
				ss << "MouseButtonReleasedEvent: " << m_Button;
				return ss.str();
			}

			EVENT_CLASS_TYPE(MouseButtonReleased)
		};

	}	//	END namespace DAHL::Input
#endif	//	DAInput

////////////////////////////////////////////////////////////////////////////////
//  -----------------------------  DAProfile  ------------------------------  //
////////////////////////////////////////////////////////////////////////////////
#if DAHL_USE_PROFILE == 1
	namespace DAHL::Profile
	{
		using daFloatingPointMicroseconds = std::chrono::duration<double, std::micro>;

		struct daProfileResult
		{
			std::string Name;

			daFloatingPointMicroseconds Start;
			std::chrono::microseconds ElapsedTime;
			std::thread::id ThreadID;
		};

		struct daInstrumentationSession
		{
			std::string Name;
		};

		class daInstrumentor
		{
		private:
			std::mutex m_Mutex;
			daInstrumentationSession* m_CurrentSession;
			std::ofstream m_OutputStream;
		public:
			inline daInstrumentor()
				: m_CurrentSession(nullptr)
			{
			}

			void BeginSession(const std::string& name, const std::string& filepath = "results.json");
			void EndSession();
			_Acquires_lock_(m_Mutex) void WriteProfile(const daProfileResult& result);
			inline static daInstrumentor& Get()
			{
				static daInstrumentor instance;
				return instance;
			}
		private:
			void WriteHeader();
			void WriteFooter();
			void InternalEndSession();
		};

		class daInstrumentationTimer
		{
		public:
			inline daInstrumentationTimer(const char* name)
				: m_Name(name), m_Stopped(false)
			{
				m_StartTimepoint = std::chrono::steady_clock::now();
			}

			inline ~daInstrumentationTimer()
			{
				if (!m_Stopped)
					Stop();
			}

			void Stop();
		private:
			const char* m_Name;
			std::chrono::time_point<std::chrono::steady_clock> m_StartTimepoint;
			bool m_Stopped;

		};

		namespace daInstrumentorUtils
		{
			template <size_t N>
			struct ChangeResult
			{
				char Data[N];
			};

			template <size_t N, size_t K>
			inline constexpr auto CleanupOutputString(const char(&expr)[N], const char(&remove)[K])
			{
				ChangeResult<N> result = {};

				size_t srcIndex = 0;
				size_t dstIndex = 0;
				while (srcIndex < N)
				{
					size_t matchIndex = 0;
					while ((matchIndex < K - 1) && (srcIndex + matchIndex < N - 1) && (expr[srcIndex + matchIndex] == remove[matchIndex]))
						matchIndex++;
					if (matchIndex == K - 1)
						srcIndex += matchIndex;
					result.Data[dstIndex++] = expr[srcIndex] == '"' ? '\'' : expr[srcIndex];
					srcIndex++;
				}
				return result;
			}

		}	//	END namespace daInstrumentorUtils

	}	//	END namespace DAHL::Profile
#endif	//	DAHL_PROFILE

////////////////////////////////////////////////////////////////////////////////
//  -------------------------------  DATime  -------------------------------  //
////////////////////////////////////////////////////////////////////////////////
#if DAHL_USE_TIME == 1
	namespace DAHL::Time
	{
		class Timestep
		{
		public:
			inline Timestep(float time = 0.0f)
				: m_Time(time)
			{}

			inline operator float() const { return m_Time; }

			inline float GetSeconds() const { return m_Time; }
			inline float GetMilliseconds() const { return m_Time * 1000.0f; }
		private:
			float m_Time;
		};

		class Timer
		{
		public:
			inline Timer()
			{
				Reset();
			}

			inline void Timer::Reset()
			{
				m_Start = std::chrono::high_resolution_clock::now();
			}

			inline float Timer::Elapsed()
			{
				return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - m_Start).count() * 0.001f * 0.001f * 0.001f;
			}

			inline float Timer::ElapsedMillis()
			{
				return Elapsed() * 1000.0f;
			}
		private:
			std::chrono::time_point<std::chrono::high_resolution_clock> m_Start;
		};
	}	//	END namespace DAHL::Time
#endif

////////////////////////////////////////////////////////////////////////////////
//  -------------------------------  DAUUID  -------------------------------  //
////////////////////////////////////////////////////////////////////////////////
#if DAHL_USE_UUID == 1
	namespace DAHL
	{
		class UUID
		{
		public:
			inline UUID();
			inline UUID(uint64_t uuid);
			inline UUID(const UUID& other);

			inline operator uint64_t () { return m_UUID; }
			inline operator const uint64_t() const { return m_UUID; }
		private:
			uint64_t m_UUID;
		};
	}
	namespace std
	{
		template<>
		struct hash<DAHL::UUID>
		{
			inline std::size_t operator()(const DAHL::UUID& uuid) const
			{
				return hash<uint64_t>()((uint64_t)uuid);
			}
		};
	}
#endif
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                           //
//                                          BEGIN IMPLEMENTATION                                             //
//                                                                                                           //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//  --------------------------------  DAHL  -------------------------------  //
////////////////////////////////////////////////////////////////////////////////
namespace DAHL::Internal
{
	#ifdef DAHL_PLATFORM_WINDOWS
		static short int daFGColors[17];
		static short int daBGColors[17];
	#else
		static const char* BreakSeq = "\033[";
		static const char* daFGColors[17];
		static const char* daBGColors[17];
	#endif
	static void daInitColors()
	{
		#ifdef DAHL_PLATFORM_WINDOWS
			//	These are organized in order of value for Windows
			daFGColors[daBlack]         = 0;																			// 0	0x00
			daFGColors[daBlue]          = FOREGROUND_BLUE;																// 1	0x01
			daFGColors[daGreen]         = FOREGROUND_GREEN;																// 2	0x02
			daFGColors[daCyan]          = FOREGROUND_BLUE | FOREGROUND_GREEN;											// 3	0x03
			daFGColors[daRed]           = FOREGROUND_RED;																// 4	0x04
			daFGColors[daMagenta]       = FOREGROUND_BLUE | FOREGROUND_RED;												// 5	0x05
			daFGColors[daYellow]        = FOREGROUND_RED | FOREGROUND_GREEN;											// 6	0x06
			daFGColors[daWhite]         = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;							// 7	0x07
			daFGColors[daBrightBlack]   = FOREGROUND_INTENSITY;															// 8	0x08
			daFGColors[daBrightBlue]    = FOREGROUND_INTENSITY | FOREGROUND_BLUE;										// 9	0x09
			daFGColors[daBrightGreen]   = FOREGROUND_INTENSITY | FOREGROUND_GREEN;										// 10	0x0A
			daFGColors[daBrightCyan]    = FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN;					// 11	0x0B
			daFGColors[daBrightRed]     = FOREGROUND_INTENSITY | FOREGROUND_RED;										// 12	0x0C
			daFGColors[daBrightMagenta] = FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED;						// 13	0x0D
			daFGColors[daBrightYellow]  = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE;						// 14	0x0E
			daFGColors[daBrightWhite]   = FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;	// 15	0x0F
			daFGColors[daUndefined]     = 0;

			daBGColors[daBlack]         = 0;																			// 0	0x00
			daBGColors[daBlue]          = BACKGROUND_BLUE;																// 16	0x10
			daBGColors[daGreen]         = BACKGROUND_GREEN;																// 32	0x20
			daBGColors[daCyan]          = BACKGROUND_BLUE | BACKGROUND_GREEN;											// 48	0x30
			daBGColors[daRed]           = BACKGROUND_RED;																// 64	0x40
			daBGColors[daMagenta]       = BACKGROUND_BLUE | BACKGROUND_RED;												// 80	0x50
			daBGColors[daYellow]        = BACKGROUND_RED | BACKGROUND_GREEN;											// 96	0x60
			daBGColors[daWhite]         = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;							// 112	0x70
			daBGColors[daBrightBlack]   = BACKGROUND_INTENSITY;															// 128	0x80
			daBGColors[daBrightBlue]    = BACKGROUND_INTENSITY | BACKGROUND_BLUE;										// 144	0x90
			daBGColors[daBrightGreen]   = BACKGROUND_INTENSITY | BACKGROUND_GREEN;										// 160	0xA0
			daBGColors[daBrightCyan]    = BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN;					// 176	0xB0
			daBGColors[daBrightRed]     = BACKGROUND_INTENSITY | BACKGROUND_RED;										// 192	0xC0
			daBGColors[daBrightMagenta] = BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_RED;						// 208	0xD0
			daBGColors[daBrightYellow]  = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN;						// 224	0xE0
			daBGColors[daBrightWhite]   = BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;	// 240	0xF0
			daBGColors[daUndefined]     = 0;
		#else
			daFGColors[daBlack]         = "\033[30m";
			daFGColors[daRed]           = "\033[31m";
			daFGColors[daGreen]         = "\033[32m";
			daFGColors[daYellow]        = "\033[33m";
			daFGColors[daBlue]          = "\033[34m";
			daFGColors[daMagenta]       = "\033[35m";
			daFGColors[daCyan]          = "\033[36m";
			daFGColors[daWhite]         = "\033[37m";
			daFGColors[daBrightBlack]   = "\033[90m";
			daFGColors[daBrightRed]     = "\033[91m";
			daFGColors[daBrightGreen]   = "\033[92m";
			daFGColors[daBrightYellow]  = "\033[93m";
			daFGColors[daBrightBlue]    = "\033[94m";
			daFGColors[daBrightMagenta] = "\033[95m";
			daFGColors[daBrightCyan]    = "\033[96m";
			daFGColors[daBrightWhite]   = "\033[97m";
			daFGColors[daUndefined]     = "\033[30m";

			daBGColors[daBlack]         = "\033[40m";
			daBGColors[daRed]           = "\033[41m";
			daBGColors[daGreen]         = "\033[42m";
			daBGColors[daYellow]        = "\033[43m";
			daBGColors[daBlue]          = "\033[44m";
			daBGColors[daMagenta]       = "\033[45m";
			daBGColors[daCyan]          = "\033[46m";
			daBGColors[daWhite]         = "\033[47m";
			daBGColors[daBrightBlack]   = "\033[100m";
			daBGColors[daBrightRed]     = "\033[101m";
			daBGColors[daBrightGreen]   = "\033[102m";
			daBGColors[daBrightYellow]  = "\033[103m";
			daBGColors[daBrightBlue]    = "\033[104m";
			daBGColors[daBrightMagenta] = "\033[105m";
			daBGColors[daBrightCyan]    = "\033[106m";
			daBGColors[daBrightWhite]   = "\033[107m";
			daBGColors[daUndefined]     = "\033[40m";
		#endif
	}

	static daAttributes DAlibAttrib;
	static bool DAHLActive = false;

	static inline void daInit()
	{
		if (!DAHLActive)
		{
			daInitColors();

			DAlibAttrib.Foreground = daFGColors[daWhite];
			DAlibAttrib.Background = daBGColors[daBlack];
			DAHLActive = true;
		}
		return;
	}
	inline void DAHL::Internal::daReset()
	{
		#ifdef DAHL_PLATFORM_WINDOWS
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, DAlibAttrib.Foreground);
		#else
			std::cout << "\033[0m";
		#endif
	}
	inline void DAHL::Internal::daShowCursor(bool enable)
	{
		#ifdef DAHL_PLATFORM_WINDOWS
			CONSOLE_CURSOR_INFO info;

			info.dwSize = 10;
			info.bVisible = (BOOL)enable;
			SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
		#else
			printf("%s?25%c", BreakSeq, enable ? 'h' : '1');
		#endif
	}

	inline void DAHL::Internal::Set(FGColor fgColor, BGColor bgColor)
	{
	#ifdef DAHL_PLATFORM_WINDOWS
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		if (fgColor == fgBlack)
			SetConsoleTextAttribute(hConsole, FGdef[daBlack]);
		else if (fgColor == fgRed)
			SetConsoleTextAttribute(hConsole, FGdef[daRed]);
		else if (fgColor == fgGreen)
			SetConsoleTextAttribute(hConsole, FGdef[daGreen]);
		else if (fgColor == fgYellow)
			SetConsoleTextAttribute(hConsole, FGdef[daYellow]);
		else if (fgColor == fgBlue)
			SetConsoleTextAttribute(hConsole, FGdef[daBlue]);
		else if (fgColor == fgMagenta)
			SetConsoleTextAttribute(hConsole, FGdef[daMagenta]);
		else if (fgColor == fgCyan)
			SetConsoleTextAttribute(hConsole, FGdef[daCyan]);
		else if (fgColor == fgWhite)
			SetConsoleTextAttribute(hConsole, FGdef[daWhite]);
		else if (fgColor == fgBrightBlack)
			SetConsoleTextAttribute(hConsole, FGdef[daBrightBlack]);
		else if (fgColor == fgBrightRed)
			SetConsoleTextAttribute(hConsole, FGdef[daBrightRed]);
		else if (fgColor == fgBrightGreen)
			SetConsoleTextAttribute(hConsole, FGdef[daBrightGreen]);
		else if (fgColor == fgBrightYellow)
			SetConsoleTextAttribute(hConsole, FGdef[daBrightYellow]);
		else if (fgColor == fgBrightBlue)
			SetConsoleTextAttribute(hConsole, FGdef[daBrightBlue]);
		else if (fgColor == fgBrightMagenta)
			SetConsoleTextAttribute(hConsole, FGdef[daBrightMagenta]);
		else if (fgColor == fgBrightCyan)
			SetConsoleTextAttribute(hConsole, FGdef[daBrightCyan]);
		else if (fgColor == fgBrightWhite)
			SetConsoleTextAttribute(hConsole, FGdef[daWhite]);
		else
			SetConsoleTextAttribute(hConsole, DAlibAttrib.Foreground);
		if (bgColor != bgUndefined)
		{
			if (bgColor == bgBlack)
				SetConsoleTextAttribute(hConsole, BGdef[daBlack]);
			else if (bgColor == bgRed)
				SetConsoleTextAttribute(hConsole, BGdef[daRed]);
			else if (bgColor == bgGreen)
				SetConsoleTextAttribute(hConsole, BGdef[daGreen]);
			else if (bgColor == bgYellow)
				SetConsoleTextAttribute(hConsole, BGdef[daYellow]);
			else if (bgColor == bgBlue)
				SetConsoleTextAttribute(hConsole, BGdef[daBlue]);
			else if (bgColor == bgMagenta)
				SetConsoleTextAttribute(hConsole, BGdef[daMagenta]);
			else if (bgColor == bgCyan)
				SetConsoleTextAttribute(hConsole, BGdef[daCyan]);
			else if (bgColor == bgWhite)
				SetConsoleTextAttribute(hConsole, BGdef[daWhite]);
			else if (bgColor == bgBrightBlack)
				SetConsoleTextAttribute(hConsole, BGdef[daBrightBlack]);
			else if (bgColor == bgBrightRed)
				SetConsoleTextAttribute(hConsole, BGdef[daBrightRed]);
			else if (bgColor == bgBrightGreen)
				SetConsoleTextAttribute(hConsole, BGdef[daBrightGreen]);
			else if (bgColor == bgBrightYellow)
				SetConsoleTextAttribute(hConsole, BGdef[daBrightYellow]);
			else if (bgColor == bgBrightBlue)
				SetConsoleTextAttribute(hConsole, BGdef[daBrightBlue]);
			else if (bgColor == bgBrightMagenta)
				SetConsoleTextAttribute(hConsole, BGdef[daBrightMagenta]);
			else if (bgColor == bgBrightCyan)
				SetConsoleTextAttribute(hConsole, BGdef[daBrightCyan]);
			else if (bgColor == bgBrightWhite)
				SetConsoleTextAttribute(hConsole, BGdef[daBrightWhite]);
		}
	#else
		if (fgColor == fgBlack)
			std::cout << FGdef[daBlack];
		else if (fgColor == fgRed)
			std::cout << FGdef[daRed];
		else if (fgColor == fgGreen)
			std::cout << FGdef[daGreen];
		else if (fgColor == fgYellow)
			std::cout << FGdef[daYellow];
		else if (fgColor == fgBlue)
			std::cout << FGdef[daBlue];
		else if (fgColor == fgMagenta)
			std::cout << FGdef[daMagenta];
		else if (fgColor == fgCyan)
			std::cout << FGdef[daCyan];
		else if (fgColor == fgWhite)
			std::cout << FGdef[daWhite];
		else if (fgColor == fgBrightBlack)
			std::cout << FGdef[daBrightBlack];
		else if (fgColor == fgBrightRed)
			std::cout << FGdef[daBrightRed];
		else if (fgColor == fgBrightGreen)
			std::cout << FGdef[daBrightGreen];
		else if (fgColor == fgBrightYellow)
			std::cout << FGdef[daBrightYellow];
		else if (fgColor == fgBrightBlue)
			std::cout << FGdef[daBrightBlue];
		else if (fgColor == fgBrightMagenta)
			std::cout << FGdef[daBrightMagenta];
		else if (fgColor == fgBrightCyan)
			std::cout << FGdef[daBrightCyan];
		else if (fgColor == fgWhite)
			std::cout << FGdef[daBrightWhite];
		else
			std::cout << FGdef[fgUndefined];
		if (bgColor != bgUndefined)
		{
			if (bgColor == bgBlack)
				std::cout << BGdef[daBlack];
			else if (bgColor == bgRed)
				std::cout << BGdef[daRed];
			else if (bgColor == bgGreen)
				std::cout << BGdef[daGreen];
			else if (bgColor == bgYellow)
				std::cout << BGdef[daYellow];
			else if (bgColor == bgBlue)
				std::cout << BGdef[daBlue];
			else if (bgColor == bgMagenta)
				std::cout << BGdef[daMagenta];
			else if (bgColor == bgCyan)
				std::cout << BGdef[daCyan];
			else if (bgColor == bgWhite)
				std::cout << BGdef[daWhite];
			else if (bgColor == bgBrightBlack)
				std::cout << BGdef[daBrightBlack];
			else if (bgColor == bgBrightRed)
				std::cout << BGdef[daBrightRed];
			else if (bgColor == bgBrightGreen)
				std::cout << BGdef[daBrightGreen];
			else if (bgColor == bgBrightYellow)
				std::cout << BGdef[daBrightYellow];
			else if (bgColor == bgBrightBlue)
				std::cout << BGdef[daBrightBlue];
			else if (bgColor == bgBrightMagenta)
				std::cout << BGdef[daBrightMagenta];
			else if (bgColor == bgBrightCyan)
				std::cout << BGdef[daBrightCyan];
			else if (bgColor == bgBrightWhite)
				std::cout << BGdef[daBrightWhite];
		}
	#endif
		return;
	}

	inline void DAHL::Internal::Print(FGColor fgColor, BGColor bgColor, const char* message)
	{
		Set(fgColor, bgColor);
		std::cout << message;
		daReset();
	}

	inline void DAHL::Internal::Printl(FGColor fgColor, BGColor bgColor, const char* message)
	{
		Print(fgColor, bgColor, message);
		std::cout << std::endl;
	}

	inline void DAHL::Internal::PrintChar(FGColor fgColor, BGColor bgColor, const char* characters)
	{
		Print(fgColor, bgColor, characters);
	}

	inline void DAHL::Internal::End()
	{
		// uh...
	}
}	//	END namespace DAHL::Internal

////////////////////////////////////////////////////////////////////////////////
//  --------------------------------  DALog  -------------------------------  //
////////////////////////////////////////////////////////////////////////////////
#if DAHL_USE_LOG == 1
	inline void DAHL::Log(Level severity, const char* message)
	{		
		if (severity == Level::Critical)
		{
			DAHL::Internal::Set(fgRed, bgUndefined);
			std::cout << "[CRITICAL]: " << message << std::endl;
		}
		else if (severity == Level::Error)
		{
			DAHL::Internal::Set(fgYellow, bgUndefined);
			std::cout << "[ERROR]: " << message << std::endl;
		}
		else if (severity == Level::Warn)
		{
			DAHL::Internal::Set(fgMagenta, bgUndefined);
			std::cout << "[WARN]: " << message << std::endl;
		}
		else if (severity == Level::Info)
		{
			DAHL::Internal::Set(fgGreen, bgUndefined);
			std::cout << "[info]: " << message << std::endl;
		}
		else if (severity == Level::Trace)
		{
			DAHL::Internal::Set(fgWhite, bgUndefined);
			std::cout << "[trace]: " << message << std::endl;
		}
		DAHL::Internal::daReset();
		return;
	}

	//  Overloads
	inline void DAHL::Log(Level severity)
	{
		Log(severity, "");
	}

	inline void DAHL::Log(Level severity, std::string& message)
	{
		const char* msg = message.c_str();
		Log(severity, msg);
	}
#endif  //  DALog

////////////////////////////////////////////////////////////////////////////////
//  ------------------------------  DAClear  -------------------------------  //
////////////////////////////////////////////////////////////////////////////////
#if DAHL_USE_CLEAR == 1
	inline void DAHL::ClearScreen()
	{
		#ifdef DAHL_PLATFORM_WINDOWS
				std::system("cls");
			#else
				std::system("clear");
		#endif
	}
#endif  //  DAClear

////////////////////////////////////////////////////////////////////////////////
//  ------------------------------  DAPrint  -------------------------------  //
////////////////////////////////////////////////////////////////////////////////
#if DAHL_USE_PRINT == 1
	//	Print to screen

	inline int DAHL::Print::daGetFGvalue(FGColor fgColor)
	{
		if (fgColor == fgBlack)
			return daBlack;
		else if (fgColor == fgRed)
			return daRed;
		else if (fgColor == fgGreen)
			return daGreen;
		else if (fgColor == fgYellow)
			return daYellow;
		else if (fgColor == fgBlue)
			return daBlue;
		else if (fgColor == fgMagenta)
			return daMagenta;
		else if (fgColor == fgCyan)
			return daCyan;
		else if (fgColor == fgWhite)
			return daWhite;
		else if (fgColor == fgBrightBlack)
			return daBrightBlack;
		else if (fgColor == fgBrightRed)
			return daBrightRed;
		else if (fgColor == fgBrightGreen)
			return daBrightGreen;
		else if (fgColor == fgBrightYellow)
			return daBrightYellow;
		else if (fgColor == fgBrightBlue)
			return daBrightBlue;
		else if (fgColor == fgBrightMagenta)
			return daBrightMagenta;
		else if (fgColor == fgBrightCyan)
			return daBrightCyan;
		else if (fgColor == fgBrightWhite)
			return daBrightWhite;
		else if (fgColor == fgUndefined)
			return daUndefined;
		else
			return -1;
	}
	inline int DAHL::Print::daGetBGvalue(BGColor bgColor)
	{
		if (bgColor == bgBlack)
			return daBlack;
		else if (bgColor == bgRed)
			return daRed;
		else if (bgColor == bgGreen)
			return daGreen;
		else if (bgColor == bgYellow)
			return daYellow;
		else if (bgColor == bgBlue)
			return daBlue;
		else if (bgColor == bgMagenta)
			return daMagenta;
		else if (bgColor == bgCyan)
			return daCyan;
		else if (bgColor == bgWhite)
			return daWhite;
		else if (bgColor == bgBrightBlack)
			return daBrightBlack;
		else if (bgColor == bgBrightRed)
			return daBrightRed;
		else if (bgColor == bgBrightGreen)
			return daBrightGreen;
		else if (bgColor == bgBrightYellow)
			return daBrightYellow;
		else if (bgColor == bgBrightBlue)
			return daBrightBlue;
		else if (bgColor == bgBrightMagenta)
			return daBrightMagenta;
		else if (bgColor == bgBrightCyan)
			return daBrightCyan;
		else if (bgColor == bgBrightWhite)
			return daBrightWhite;
		else if (bgColor == bgUndefined)
			return daUndefined;
		else
			return -1;
	}

	inline void DAHL::Print::SetDefaults(FGColor fgColor, BGColor bgColor)
	{
		DAHL::Internal::DAlibAttrib.Foreground = FGdef[daGetFGvalue(fgColor)];
		DAHL::Internal::DAlibAttrib.Background = BGdef[daGetBGvalue(bgColor)];
	}

	inline void DAHL::Print::Print(const char* message)	//	Make this use the user-set colors
	{
		DAHL::Internal::Set(fgWhite, bgUndefined);
		std::cout << message;
	}
	inline void DAHL::Print::Print(FGColor fgColor, const char* message)
	{
		DAHL::Internal::Set(fgColor, bgUndefined);
		std::cout << message;
	}
	inline void DAHL::Print::Print(BGColor bgColor, const char* message)
	{
		DAHL::Internal::Set(fgUndefined, bgColor);
		std::cout << message;
	}
	inline void DAHL::Print::Print(FGColor fgColor, BGColor bgColor, const char* message)
	{
		DAHL::Internal::Set(fgColor, bgColor);
		std::cout << message;
	}

	//	Print a single line to screen
	inline void DAHL::Print::Printl(const char* message)
	{
		DAHL::Print::Print(message);
		std::cout << std::endl;
		DAHL::Internal::daReset();
	}
	inline void DAHL::Print::Printl(FGColor fgColor, const char* message)
	{
		DAHL::Print::Print(fgColor, message);
		std::cout << std::endl;
		DAHL::Internal::daReset();
	}
	inline void DAHL::Print::Printl(BGColor bgColor, const char* message)
	{
		DAHL::Print::Print(bgColor, message);
		std::cout << std::endl;
		DAHL::Internal::daReset();
	}
	inline void DAHL::Print::Printl(FGColor fgColor, BGColor bgColor, const char* message)
	{
		DAHL::Print::Print(fgColor, bgColor, message);
		std::cout << std::endl;
		DAHL::Internal::daReset();
	}

	//	Print a single colored character to screen
	inline void DAHL::Print::PrintChar(const char* character)
	{
		DAHL::Print::Print(character);
		DAHL::Internal::daReset();
	}
	inline void DAHL::Print::PrintChar(FGColor fgColor, const char* character)
	{
		DAHL::Print::Print(fgColor, character);
		DAHL::Internal::daReset();
	}
	inline void DAHL::Print::PrintChar(BGColor bgColor, const char* character)
	{
		DAHL::Print::Print(bgColor, character);
		DAHL::Internal::daReset();
	}
	inline void DAHL::Print::PrintChar(FGColor fgColor, BGColor bgColor, const char* character)
	{
		DAHL::Print::Print(fgColor, bgColor, character);
		DAHL::Internal::daReset();
	}

	#ifdef DAHL_PLATFORM_WINDOWS
		inline void DAHL::Print::PrintRGB(COLORREF rgbValue)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, (WORD)rgbValue);
		}
	#endif

#endif  //  DAPrint

////////////////////////////////////////////////////////////////////////////////
//  ------------------------------  DAInput  -------------------------------  //
////////////////////////////////////////////////////////////////////////////////
#if DAHL_USE_INPUT == 1

#endif	//	DAInput


////////////////////////////////////////////////////////////////////////////////
//  -----------------------------  DAProfile  ------------------------------  //
////////////////////////////////////////////////////////////////////////////////
#if DAHL_USE_PROFILE == 1

		inline void DAHL::Profile::daInstrumentor::BeginSession(const std::string& name, const std::string& filepath)
		{
			std::lock_guard lock(m_Mutex);
			if (m_CurrentSession)
			{
				// If there is already a current session, then close it before beginning new one.
				// Subsequent profiling output meant for the original session will end up in the
				// newly opened session instead.  That's better than having badly formatted
				// profiling output.
				InternalEndSession();
			}
			m_OutputStream.open(filepath);

			if (m_OutputStream.is_open())
			{
				m_CurrentSession = new daInstrumentationSession({ name });
				WriteHeader();
			}
			else
			{
				dahlLOG_ERROR(" [DAProfile] Instrumentator could not open results file!");
			}
		}
		inline void DAHL::Profile::daInstrumentor::EndSession()
		{
			std::lock_guard lock(m_Mutex);
			InternalEndSession();
		}
		_Acquires_lock_(m_Mutex) inline void DAHL::Profile::daInstrumentor::WriteProfile(const daProfileResult& result)
		{
			std::stringstream json;

			json << std::setprecision(3) << std::fixed;
			json << (",{");
			json << "\"cat\":\"function\",";
			json << "\"dur\":" << (result.ElapsedTime.count()) << ',';
			json << "\"name\":\"" << result.Name << "\",";
			json << "\"ph\":\"X\",";
			json << "\"pid\":0,";
			json << "\"tid\":" << result.ThreadID << ",";
			json << "\"ts\":" << result.Start.count();
			json << "}";

			std::lock_guard lock(m_Mutex);
			if (m_CurrentSession)
			{
				m_OutputStream << json.str();
				m_OutputStream.flush();
			}
		}

		//	Private functions
		inline void DAHL::Profile::daInstrumentor::WriteHeader()
		{
			m_OutputStream << "{\"otherData\": {},\"traceEvents\":[{}";
			m_OutputStream.flush();
		}
		inline void DAHL::Profile::daInstrumentor::WriteFooter()
		{
			m_OutputStream << "]}";
			m_OutputStream.flush();
		}
		inline void DAHL::Profile::daInstrumentor::InternalEndSession()
		{
			if (m_CurrentSession)
			{
				WriteFooter();
				m_OutputStream.close();
				delete m_CurrentSession;
				m_CurrentSession = nullptr;
			}
		}

		inline void DAHL::Profile::daInstrumentationTimer::Stop()
		{
			auto endTimepoint = std::chrono::steady_clock::now();
			auto highResStart = daFloatingPointMicroseconds{ m_StartTimepoint.time_since_epoch() };
			auto elapsedTime = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch() - std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch();

			daInstrumentor::Get().WriteProfile({ m_Name, highResStart, elapsedTime, std::this_thread::get_id() });

			m_Stopped = true;
		}

#endif	//	DAProfile

////////////////////////////////////////////////////////////////////////////////
//  -------------------------------  DAUUID  -------------------------------  //
////////////////////////////////////////////////////////////////////////////////
#if DAHL_USE_UUID == 1
namespace DAHL
{
	static std::random_device s_RandomDevice;
	static std::mt19937_64 eng(s_RandomDevice());
	static std::uniform_int_distribution<uint64_t> s_UniformDistribution;

	UUID::UUID()
		: m_UUID(s_UniformDistribution(eng))
	{}

	UUID::UUID(uint64_t uuid)
		: m_UUID(uuid)
	{
	}

	UUID::UUID(const UUID& other)
		: m_UUID(other.m_UUID)
	{
	}
}
#endif //	DAUUID

#endif	//	DAHL #include guards