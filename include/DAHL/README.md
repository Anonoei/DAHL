# DAHL v0.4.3
#### DA Helper Library

This header serves as a cross-platform library for various tasks, such as:

## Features
  * Free and Open Source (FOSS)
  * Cross-platform (Windows/Linux/MacOS)
  * Logging libarary (Critical, Error, Warn, Info, Trace)
  * Asserts (that can be enabled/disabled prior to compile)
  * Colored printing (16-bit color)
  * Instrumenting/Profiling (Check function speed)
  * Timestep/Timer (Use Timestep, or timers)
  * Input (Blocking input) - WiP
  * Easy to use

~Written 2021/04/15

## Usage:
I use this library in my cpp-proj/console-games repository,
In Tetris, I use the timer and timestep to track game time, and I use colored printing to print the pieces to the screen.
#### Include Defines
Name | Purpose | Formatting
---- | ------- | ----------
DAHL_ALL | Include all libraries | #define
DAHL_PRINT | Include colored printing | #define
DAHL_INPUT | Include input | #define
DAHL_PROFILE | Include profiling | #define
DAHL_TIME | Include Timers/Timestep | #define
#### Do not include Defines
Name | Purpose | Formatting
---- | ------- | ----------
NO_DAHL_LOG | Disables daLog | #define
NO_DAHL_ASSERT | Disables daAssert | #define

### Examples:
#### Log
Name | Purpose | Formatting
---- | ------- | ----------
daLOG_CRITICAL()  | Logs message in red | (<message goes here>)
daLOG_ERROR()  | Logs message in yellow | (<message goes here>)
daLOG_WARN()  | Logs message in magenta | (<message goes here>)
daLOG_INFO()  | Logs message in green | (<message goes here>)
daLOG_TRACE()  | Logs message in white | (<message goes here>)
daAssert()  | Asserts | (<statement>, [<message goes here>])
#### Print
Name | Purpose | Formatting
---- | ------- | ----------
daClearScreen() | Cross-platform clear screen | ()
daPrint() | Same as std::cout | ([<FGColor>], [<BGColor>], <message>)
daPrintl() | Print one line then reset colors | ([<FGColor>], [<BGColor>], <message>)
daPrintChar() | Print message then reset colors | ([<FGColor>], [<BGColor>], <message>)
#### Input (coming soon)
#### Profile
Name | Purpose | Formatting
---- | ------- | ----------
daPROFILE_BEGIN_SESSION() | Begin profiling session | (<session name>, <export file.json>)
daPROFILE_END_SESSION() | End profiling session | ()
daPROFILE_SCOPE() | Profile current scope | (<name>)
daPROFILE_FUNCTION() | Profile current function | (<name>)
#### Time
Name | Purpose | Formatting
---- | ------- | ----------
daTimer | A timer | None
daTimestep | Timestep variable | None
#### Colors
Color | Foreground | Background | Index(don't use!)
----- | ---------- | ---------- | -----------------
Black | fgBlack | bgBlack | daBlack
Red | fgRed | bgRed | daRed
Green | fgGreen |  bgGreen | daGreen
Yellow | fgYellow | bgYellow | daYellow
Blue | fgBlue | bgBlue | daBlue
Magenta | fgMagenta | bgMagenta | daMagenta
Cyan | fgCyan | bgCyan | daCyan
Light Gray | fgWhite | bgWhite | daWhite
Dark Gray | fgBrightBlack | bgBrightBlack | daBrightBlack
Pinkish Red | fgBrightRed | bgBrightRed | daBrightRed
Bright Green | fgBrightGreen | bgBrightGreen | daBrightGreen
Bright Yellow | fgBrightYellow | bgBrightYellow  | daBrightYellow
Bright Blue | fgBrightBlue | bgBrightBlue | daBrightBlue
Bright Magenta | fgBrightMagenta | bgBrightMagenta | daBrightMagenta
Bright Cyan | fgBrightCyan | bgBrightCyan | daBrightCyan
White | fgBrightWhite | bgBrightWhite | daBrightWhite
Placeholder | fgUndefined | bgUndefined | daUndefined

## License: GPLv3
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.