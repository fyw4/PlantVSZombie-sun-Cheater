#include <stdio.h>
#include <windows.h>
#define SUN_SHINE_BASE_ADDR 0x006A9EC0 //阳光基址 
#define SUN_SHINE_OFFSET_FIRST 0x768 //一级偏移 
#define SUN_SHINE_OFFSET_SECOND 0x5560 //二级偏移值 
main() 
{ 
	int modifySunshine = 0; 
	DWORD ErrorInfo = 0; 
	DWORD Size = 0; 
	DWORD SunShineNum=0; //最后值 
	DWORD PID = 0; 
	DWORD SunShineBaseAddress = SUN_SHINE_BASE_ADDR; //阳光基址 
	DWORD SunShineBaseAddressValue = 0; //阳光基址值 
	DWORD SunShineOffsetFirst = SUN_SHINE_OFFSET_FIRST; //一级偏移 
	DWORD SunShineOffsetFirstValue = 0; //一级偏移值 
	DWORD SunShineOffsetSecond = SUN_SHINE_OFFSET_SECOND; //二级偏移 
	HANDLE Process = 0; 
	HWND hWinmine = FindWindowW(NULL, L"植物大战僵尸中文版"); //找到窗口 
	GetWindowThreadProcessId(hWinmine, &PID); //获取进程标识 
	if (0 == PID) 
	{ 
		printf_s("获取PID失败\n"); 
		return -1; 
	} 
	Process = OpenProcess(PROCESS_ALL_ACCESS, 0, PID); 
	if (NULL == Process ) 
	{
		printf_s("进程打开失败\n"); 
		ErrorInfo = GetLastError(); 
		return -1; 
	} 
	if (0 == ReadProcessMemory(Process, (LPVOID)SunShineBaseAddress, &SunShineBaseAddressValue, sizeof(DWORD), &Size)) 
	{
		printf_s("获取基址失败\n"); 
		ErrorInfo = GetLastError(); 
		return -1; 
	} 
	if (0 == ReadProcessMemory(Process, (LPVOID)(SunShineBaseAddressValue + SunShineOffsetFirst), &SunShineOffsetFirstValue, sizeof(DWORD), &Size)) 
	{ 
		printf_s("获取一级偏移失败\n"); 
		ErrorInfo = GetLastError(); 
		return -1; 
	} 
	if (0 == ReadProcessMemory(Process, (LPVOID)(SunShineOffsetFirstValue + SunShineOffsetSecond), &SunShineNum, sizeof(DWORD), &Size)) 
	{
		printf_s("获取二级偏移失败\n");
		ErrorInfo = GetLastError(); 
		return -1; 
	} 
	printf_s("SunShineNum:%d\n", SunShineNum); 
	printf_s("输入你要修改的值："); 
	scanf_s("%d", &modifySunshine); 
	WriteProcessMemory(Process, (LPVOID)(SunShineOffsetFirstValue + SunShineOffsetSecond), &modifySunshine, sizeof(DWORD), &Size);
	CloseHandle(Process); //关闭句柄 
	system("pause"); 
	return -1;
}

