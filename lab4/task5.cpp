#include <Windows.h>
#include <iostream>

int a, b;
CRITICAL_SECTION criticalSection;

DWORD WINAPI thread_calculations(LPVOID param) {
    for (;;) {
        //EnterCriticalSection(&criticalSection);
        a = 1;
        a = 2;
        a = 3;
        b = 1;
        b = 2;
        b = 3;
        //LeaveCriticalSection(&criticalSection);
    }
}

DWORD WINAPI thread_display(LPVOID param) {
    for (;;) {
        //EnterCriticalSection(&criticalSection);
        std::cout << "a=" << a << " b=" << b << std::endl;
        //LeaveCriticalSection(&criticalSection);
        Sleep(100);
    }
}


int main()
{
    //InitializeCriticalSection(&criticalSection);

    CreateThread(NULL, 0, thread_calculations, NULL, 0, NULL);
    CreateThread(NULL, 0, thread_display, NULL, 0, NULL);

    Sleep(60000); 

    //DeleteCriticalSection(&criticalSection);

    return 0;
}

// volatile int a; The 'volatile' keyword ensures that the value of 'a' 
// is always read directly from memory, and not from a CPU register. 
// This prevents the compiler from optimizing access to this variable, 
// as it might be modified by another thread or hardware outside the 
// current code.

