#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));
    
    // Gyermek processz indítása
    if (!CreateProcess(
        "CI880V_child.exe",   // A gyermek program neve
        NULL,                 // Parancssori argumentumok
        NULL,                // Processz attribútumok
        NULL,                // Szál attribútumok
        FALSE,               // Öröklés handle-ekből
        0,                   // Létrehozási flag-ek
        NULL,                // Környezet
        NULL,                // Aktuális könyvtár
        &si,                 // STARTUPINFO
        &pi)                 // PROCESS_INFORMATION
    ) {
        printf("CreateProcess failed (%d).\n", GetLastError());
        return 1;
    }
    
   
    WaitForSingleObject(pi.hProcess, INFINITE);
    
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    
    printf("A gyermek processz befejeződött.\n");
    return 0;
}