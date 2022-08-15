
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>


int main    (){
   //take screenshot and save it to clipboard
    HWND hwnd = GetDesktopWindow();
    HDC hdc = GetDC(hwnd);
    HDC hdcMem = CreateCompatibleDC(hdc);
    HBITMAP hbmp = CreateCompatibleBitmap(hdc, GetDeviceCaps(hdc, HORZRES), GetDeviceCaps(hdc, VERTRES));
    SelectObject(hdcMem, hbmp);
    BitBlt(hdcMem, 0, 0, GetDeviceCaps(hdc, HORZRES), GetDeviceCaps(hdc, VERTRES), hdc, 0, 0, SRCCOPY);
    OpenClipboard(NULL);
    EmptyClipboard();
    SetClipboardData(CF_BITMAP, hbmp);
    CloseClipboard();
    DeleteDC(hdcMem);
    ReleaseDC(hwnd, hdc);
    DeleteObject(hbmp);
    return 0;
    
}