#include "ConsoleTest.h"

#include <iostream>
#include <windows.h>
#include <Memoryapi.h>





void ConsoleTest::mytestVirtualMemory()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	int const mysize = sizeof(int);
	LPVOID ptr = VirtualAlloc(NULL, mysize, MEM_COMMIT, PAGE_NOACCESS);
	DWORD result = 0;
	if (ptr == NULL)
	{
		result = GetLastError();
	}
	int * ptest = (int*)ptr;
	std::cout << "Hello World!\n";
	DWORD resultFree = 0;
	bool ret = VirtualFree(ptr, mysize, MEM_DECOMMIT);
	if (!ret)
	{
		resultFree = GetLastError();
	}

}