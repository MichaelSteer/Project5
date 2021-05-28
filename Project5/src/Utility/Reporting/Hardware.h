#pragma once
#include <intrin.h>
#include <windows.h>
#include <sysinfoapi.h>
#include <string>

#define CPU_ADDRESS 0x80000000

class Hardware {
    public:
        Hardware();
        ~Hardware();

        void pollValues();

    private:

        float CPU_Speed();



        // CPU Metrics
        std::string CPU_name;
        float CPU_freq;
        // TODO: Implement float CPU_temp, CPU_usage;
        unsigned long CPU_Core_Count;
        // TODO: Add thread monitor system

        // RAM Metrics
        unsigned long RAM_Allocated, RAM_Used;
        float RAM_freq, RAM_temp, RAM_percent_used, RAM_percent_total_used;

        // PAGE Metrics
        bool PAGE_used;

        // GPU Metrics
        std::string GPU_name;
        float GPU_temp, GPU_usage;
        unsigned long VRAM_Allocated, VRAM_Used, VRAM_Total;

        void getCPUInfo();

};