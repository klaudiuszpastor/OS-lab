#include <iostream>
#include <Windows.h>

DWORD WINAPI thread_func(LPVOID param) {
    std::cout << "Running thread # " << (int)param << std::endl;
    for (;;) {}
    return 0;
}

int main()
{
    //Creating 4 threads
    CreateThread(NULL, 0, thread_func, (LPVOID)1, 0, NULL);
    CreateThread(NULL, 0, thread_func, (LPVOID)2, 0, NULL);
    CreateThread(NULL, 0, thread_func, (LPVOID)3, 0, NULL);
    CreateThread(NULL, 0, thread_func, (LPVOID)4, 0, NULL);

    Sleep(60000);
    
    return 0;
}
