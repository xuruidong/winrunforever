// runforever_vs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <process.h>

using namespace std;

#pragma comment(linker,"/subsystem:\"windows\"  /entry:\"mainCRTStartup\"" )

int Daemonproc(const char *path)
{
	//char *path = (char *)lpParameter;
	cout << "child process  " << path << endl;
	STARTUPINFO si;

	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	do {
		cout << "hahah  " << path << endl;
		// Sleep(3000);
		
		//if (!CreateProcess(NULL, (LPSTR)path, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi))
		if (!CreateProcess(NULL, (LPSTR)path, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
		{
			cout << "创建进程失败.." << GetLastError() << endl;
			return 0;
		}
		cout << "hahah1  " << path << endl;
		WaitForSingleObject(pi.hProcess, INFINITE);

		cout << "子进程已经退出..." << endl;
		Sleep(1000);
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
		
	} while (true);

	return 0;
}

int main()
{
    std::cout << "Hello World!\n";
	Daemonproc("dahua_vs.exe");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
