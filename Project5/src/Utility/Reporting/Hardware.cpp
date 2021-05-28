#include "Hardware.h"

Hardware::Hardware() {

}

Hardware::~Hardware() {

}

void Hardware::pollValues() {
    int CPUInfo[4] = {-1};
    unsigned int nExids, i = 0;
    char CPUBrandString[0x40];

    // cpuid reformat
    __cpuid(CPUInfo, CPU_ADDRESS);

    for (i = CPU_ADDRESS; i <= nExids; ++i) {
        __cpuid(CPUInfo, i);

        // CPU Brand String (AMD, Intel, Other, ???)
        if (i == CPU_ADDRESS + 0x02)
            memcpy(CPUBrandString, CPUInfo, sizeof(CPUInfo));
        else if (i == CPU_ADDRESS + 0x03)
            memcpy(CPUBrandString + 16, CPUInfo, sizeof(CPUInfo));
        else if (i == CPU_ADDRESS + 0x04) 
            memcpy(CPUBrandString + 32, CPUInfo, sizeof(CPUInfo));
    }

    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);

    CPU_name = CPUBrandString;
    CPU_Core_Count = sysInfo.dwNumberOfProcessors;
    CPU_freq = CPU_Speed();
}

float Hardware::CPU_Speed() {
    wchar_t Buffer[_MAX_PATH];
    DWORD BufSize = _MAX_PATH;
    DWORD dwMHz = _MAX_PATH;
    HKEY hKey;

    // open the key where the proc speed is hidden:
    long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
                                L"HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0",
                                0,
                                KEY_READ,
                                &hKey);
    if(lError != ERROR_SUCCESS)
    {// if the key is not found, tell the user why:
        FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM,
                        NULL,
                        lError,
                        0,
                        Buffer,
                        _MAX_PATH,
                        0);
        wprintf(Buffer);
        return 0;
    }

    // query the key:
    RegQueryValueEx(hKey, L"~MHz", NULL, NULL, (LPBYTE) &dwMHz, &BufSize);
    return (double)dwMHz;
}

// https://stackoverflow.com/questions/850774/how-to-determine-the-hardware-cpu-and-ram-on-a-machine
// Windows specific
void Hardware::getCPUInfo() {
    
}