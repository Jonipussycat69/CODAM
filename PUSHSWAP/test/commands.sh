@ECHO OFF
CLS
ECHO 1. Compile and Run all .c files
ECHO 2. Compile and Run all .c files with GDB
ECHO 3. Compile and Run all .c files with GDB TUI
ECHO.

CHOICE /C 123 /M "Enter your choice:"

:: Note - list ERRORLEVELS in decreasing order
IF ERRORLEVEL 3 GOTO RunAllGdbTui
IF ERRORLEVEL 2 GOTO RunAllGdb
IF ERRORLEVEL 1 GOTO RunAll

:RunAll
ECHO Compiling and running all .c files...
REM cc *.c
GOTO End

:RunAllGdb
ECHO Compiling and running all .c files with GDB...
REM cc -g *.c && gdb a.out
GOTO End

:RunAllGdbTui
ECHO Compiling and running all .c files with GDB TUI...
REM cc -g *.c && gdb a.out -tui
GOTO End

:End
