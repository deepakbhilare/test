#include <iostream>
#include <mach/mach.h>

int main() {
    host_cpu_load_info_data_t cpuLoad;
    mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;
    
    if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, reinterpret_cast<host_info_t>(&cpuLoad), &count) != KERN_SUCCESS) {
        std::cerr << "Failed to retrieve CPU load information." << std::endl;
        return 1;
    }
    
    unsigned long long totalTicks = cpuLoad.cpu_ticks[CPU_STATE_USER] + cpuLoad.cpu_ticks[CPU_STATE_SYSTEM] +
                                    cpuLoad.cpu_ticks[CPU_STATE_NICE] + cpuLoad.cpu_ticks[CPU_STATE_IDLE];
    
    double utilization = static_cast<double>(totalTicks - cpuLoad.cpu_ticks[CPU_STATE_IDLE]) / totalTicks * 100.0;
    
    std::cout << "CPU Utilization: " << utilization << "%" << std::endl;
    
    return 0;
}
