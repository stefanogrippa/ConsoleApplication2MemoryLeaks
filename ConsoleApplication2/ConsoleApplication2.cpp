// ConsoleApplication2.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <windows.h>
#include <Memoryapi.h>

#include <malloc.h>

// https://docs.microsoft.com/it-it/visualstudio/debugger/finding-memory-leaks-using-the-crt-library?view=vs-2022
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "leak_detector_c.h"

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	int const mysize = sizeof(int);
	LPVOID ptr = VirtualAlloc(NULL, mysize, MEM_COMMIT, PAGE_NOACCESS);
	DWORD result = 0;
	if (ptr == NULL)
	{
		result = GetLastError();
	}
	
    std::cout << "Hello World!\n";
	DWORD resultFree = 0;
	bool ret = VirtualFree(ptr, mysize, MEM_DECOMMIT);
	if (!ret)
	{
		resultFree = GetLastError();
	}



	int numero = 100;
	int* myarray = (int *)malloc(sizeof(int) * numero);
	free (myarray);

	int * test = DBG_NEW  int;
	int * test1 = DBG_NEW  int;
	//delete test;
	//delete test1;
	//_CrtDumpMemoryLeaks();


	atexit(report_mem_leak);
}

// Per eseguire il programma: CTRL+F5 oppure Debug > Avvia senza eseguire debug
// Per eseguire il debug del programma: F5 oppure Debug > Avvia debug

// Suggerimenti per iniziare: 
//   1. Usare la finestra Esplora soluzioni per aggiungere/gestire i file
//   2. Usare la finestra Team Explorer per connettersi al controllo del codice sorgente
//   3. Usare la finestra di output per visualizzare l'output di compilazione e altri messaggi
//   4. Usare la finestra Elenco errori per visualizzare gli errori
//   5. Passare a Progetto > Aggiungi nuovo elemento per creare nuovi file di codice oppure a Progetto > Aggiungi elemento esistente per aggiungere file di codice esistenti al progetto
//   6. Per aprire di nuovo questo progetto in futuro, passare a File > Apri > Progetto e selezionare il file con estensione sln
