// Console Input Output Library - Unified Implementation
// consoleASCII.cpp
//
// Fardad Soleimanloo, Chris Szalwinski
// November 18 2011
// Version 1.0
//

/* table of platforms */
#define CIO_LINUX       1
#define CIO_MICROSOFT   2
#define CIO_BORLAND     3
#define CIO_UNIX        4

/* auto-select your platform here */
#if   defined __BORLANDC__
    #define CIO_PLATFORM CIO_BORLAND
    #define CIO_LOWER_LEVEL_H_ <conio.h>
#elif defined _MSC_VER
    #define CIO_PLATFORM CIO_MICROSOFT
    #include <windows.h>
    #define CIO_LOWER_LEVEL_H_ <conio.h>
#elif defined __MACH__
    #define CIO_PLATFORM CIO_UNIX
    #define CIO_LOWER_LEVEL_H_ <curses.h>
#elif defined __GNUC__
    #define CIO_PLATFORM CIO_LINUX
    #define CIO_LOWER_LEVEL_H_ <ncurses.h>
#elif !defined __BORLANDC__ && !defined _MSC_VER && !defined __GNUC__ && !defined __MACH__
    #error CONSOLE_PLT is undefined
#endif

extern "C" {
    #include CIO_LOWER_LEVEL_H_
}

#include "console.h"

namespace cio { // continuation of cio namespace

//----------------- Platform-Dependent Section ------------------------------
//

#if CIO_PLATFORM == CIO_LINUX || CIO_PLATFORM == CIO_UNIX

// Console initializes the Console Input Output object
//
Console::Console() {
    ::initscr();
    ::noecho();
    ::cbreak();
    ::keypad(stdscr,1);
    bufrows = LINES;
    bufcols = COLS;
    if (bufrows * bufcols > 0)
        buffer  = new char[bufrows * bufcols];
    else
        buffer = 0;
    clear();
}

Console::~Console() {
    clear();
    setPosition(0, 0);
    delete [] buffer;
    ::endwin();
}

void Console::clear() {
    ::erase();
    clearBuffer();
}

int Console::getKey() {
    int key;
    ::refresh();
    key = ::getch();
    return key;
}

// setPosition moves the cursor to row r column c
//
void Console::setPosition(int r, int c) {
    curRow = r;
    curCol = c;
    ::move(r, c);
}

// drawCharacter draws the character at the current cursor position
//
void Console::drawCharacter() {
    if (buffer) ::addch(buffer[curRow * bufcols + curCol]);
}

// << inserts character c at the current cursor position
//
Console& operator<<(Console& os, char c) {
    ::addch(c);
    os.setCharacter(c);
    return os;
}

#elif CIO_PLATFORM == CIO_MICROSOFT

HANDLE  consh;
CONSOLE_SCREEN_BUFFER_INFO bufinfo;

// Console initializes the Console Input Output object
//
Console::Console() {
    consh = ::GetStdHandle(STD_OUTPUT_HANDLE);
    ::GetConsoleScreenBufferInfo(consh, &bufinfo);
    bufrows = bufinfo.srWindow.Bottom + 1;
    bufcols = bufinfo.srWindow.Right + 1;
    if (bufrows * bufcols > 0)
        buffer  = new char[bufrows * bufcols];
    else
        buffer = 0;
    clear();
}

Console::~Console() {
    clear();
    setPosition(0, 0);
    delete [] buffer;
}

void Console::clear() {
    DWORD
        len = bufrows * bufcols,
        actual;
    TCHAR ch = ' ';
    COORD coord;
    coord.X = 0;
    coord.Y = 0;
    ::FillConsoleOutputCharacter(consh, ch, len, coord, &actual);
    clearBuffer();
}

int Console::getKey() {
    int key;
    key = ::_getch();
    return key;
}

// setPosition moves the cursor to row r column c
//
void Console::setPosition(int r, int c) {
    curRow = r;
    curCol = c;
    COORD coord;
    coord.X = c;
    coord.Y = r;
    ::SetConsoleCursorPosition(consh, coord);
}

// drawCharacter draws the character at the current cursor position
//
void Console::drawCharacter() {
    if (buffer) ::_putch(buffer[curRow * bufcols + curCol]);
}

// << inserts character c at the current cursor position
//
Console& operator<<(Console& os, char c) {
    ::_putch(c);
    os.setCharacter(c);
    return os;
}

#elif CIO_PLATFORM == CIO_BORLAND

// Console initializes the Console Input Output object
//
Console::Console() {
    struct text_info x;
    ::gettextinfo(&x);
    bufrows = x.screenheight;
    bufcols = x.screenwidth;
    if (bufrows * bufcols > 0)
        buffer  = new char[bufrows * bufcols];
    else
        buffer = 0;
    clear();
}

Console::~Console() {
    clear();
    setPosition(0, 0);
    delete [] buffer;
}

void Console::clear(){
    ::clrscr();
    clearBuffer();
}

int Console::getKey() {
    int key;
    key = ::getch();
    return key;
}

// setPosition moves the cursor to row r column c
//
void Console::setPosition(int r, int c) {
    curRow = r;
    curCol = c;
    ::gotoxy(c + 1, r + 1);
}

// drawCharacter draws the character at the current cursor position
//
void Console::drawCharacter() {
    if (buffer) ::putch(buffer[curRow * bufcols + curCol]);
}

// << inserts character c at the current cursor position
//
Console& operator<<(Console& os, char c) {
    ::putch(c);
    os.setCharacter(c);
    return os;
}

#endif

//--------------------------- Platform-Independent Section ------------------

// Definition of the Console Input Output object
//
Console console;

// getRows retrieves the number of rows in the output object
//
int  Console::getRows() const {
    return bufrows;
}

// getCols retrieves the number of columns in the output object
//
int  Console::getCols() const {
    return bufcols;
}

// getPosition retrieves the current position of the cursor
//
void Console::getPosition(int& r, int& c) const {
    r = curRow;
    c = curCol;
}

// clearBuffer clears the cio buffer and resets the cursor
// position to the top left corner
//
void Console::clearBuffer() {
    for (int i = 0; buffer && i < bufrows * bufcols; i++)
        buffer[i] = ' ';
    setPosition(0, 0);
}

// pause accepts a key press from the input object
//
void Console::pause() {
    getKey();
}

// setCharacter sets the character at the current cursor position to c
// and moves the currect cursor position one character towards the end
//
void Console::setCharacter(char c) {
    if (buffer)
        buffer[curRow * bufcols + curCol++] = c;
}

// getCharacter returns the character at the current cursor position
//
char Console::getCharacter() const {
    return buffer ? buffer[curRow * bufcols + curCol] : ' ';
}

// >> extracts the next key from the input object
//
Console& operator>>(Console& is, int& c) {
    c = is.getKey();
    return is;
}

// << inserts string str at the current cursor position

Console& operator<<(Console& os, const char* str) {
    for(int i = 0; str[i]; i++)
        os << str[i];
    return os;
}

} // end namespace cio
