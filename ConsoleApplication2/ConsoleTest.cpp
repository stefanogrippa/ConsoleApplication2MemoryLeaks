#include "ConsoleTest.h"

#include <iostream>
#include <windows.h>
#include <Memoryapi.h>

#include <malloc.h>


// https://docs.microsoft.com/it-it/visualstudio/debugger/finding-memory-leaks-using-the-crt-library?view=vs-2022
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "leak_detector_c.h"

// https://stackoverflow.com/questions/5421754/what-is-the-usage-of-debug-new-and-file
#define DEBUG_NEW new(__FILE__, __LINE__)

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

void ConsoleTest::mytest()
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



	int numero = 100;
	//int* myarray = (int *)malloc(sizeof(int) * numero);
	//free (myarray);

	//int * test = new  int;
	//int * test1 = new  int;
	//delete test;
	//delete test1;
}