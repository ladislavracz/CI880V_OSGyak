#include <stdio.h>
#include <stdlib.h>
#include <windows.h> 

int main() {
    // 1. Létező parancs futtatása (pl. "dir" a Windowsban)
    int ret1 = system("dir");
    printf("Visszatérési érték (dir): %d\n", ret1);

    // 2. Nem létező parancs futtatása
    int ret2 = system("ez_nem_letezo_parancs");
    printf("Visszatérési érték (nemlétező parancs): %d\n", ret2);

    // 3. További példa: "echo" parancs
    int ret3 = system("echo Helló, Windows!");
    printf("Visszatérési érték (echo): %d\n", ret3);

    return 0;
}