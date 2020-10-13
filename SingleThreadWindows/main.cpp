#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include "psapi.h"
#include <psapi.h>

using namespace std;


//Global variables


static ULARGE_INTEGER lastCPU, lastSysCPU, lastUserCPU;
static int numProcessors;
static HANDLE self;

void init(){
    SYSTEM_INFO sysInfo;
    FILETIME ftime, fsys, fuser;

    GetSystemInfo(&sysInfo);
    numProcessors = sysInfo.dwNumberOfProcessors;

    GetSystemTimeAsFileTime(&ftime);
    memcpy(&lastCPU, &ftime, sizeof(FILETIME));

    self = GetCurrentProcess();
    GetProcessTimes(self, &ftime, &ftime, &fsys, &fuser);
    memcpy(&lastSysCPU, &fsys, sizeof(FILETIME));
    memcpy(&lastUserCPU, &fuser, sizeof(FILETIME));
}

double getCurrentValue() {
    FILETIME ftime, fsys, fuser;
    ULARGE_INTEGER now, sys, user;
    double percent;

    GetSystemTimeAsFileTime(&ftime);
    memcpy(&now, &ftime, sizeof(FILETIME));

    GetProcessTimes(self, &ftime, &ftime, &fsys, &fuser);
    memcpy(&sys, &fsys, sizeof(FILETIME));
    memcpy(&user, &fuser, sizeof(FILETIME));
    percent = (sys.QuadPart - lastSysCPU.QuadPart) +
              (user.QuadPart - lastUserCPU.QuadPart);
    percent /= (now.QuadPart - lastCPU.QuadPart);
    percent /= numProcessors;
    lastCPU = now;
    lastUserCPU = user;
    lastSysCPU = sys;

    return percent * 100;
}

SIZE_T getMemoryUsage(){
    PROCESS_MEMORY_COUNTERS_EX pmc;
    GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
    return pmc.PrivateUsage;
}

int main() {

    clock_t start;
    clock_t finish;

    init();

    start = clock();

    const int number = 2000000;
    bool flags[number+1];


    for (int i = 0; i <= number; i++)
        flags[i] =  false;



    for (int i = 2; i <= (int)sqrt(number); i++) {
        if(!flags[i]){
            for (double j = pow(i,2); j <= number; j+=i) {
                flags[(int)(j)] = true;
            }
        }
    }

    int counter = 0;


    for (int k = 2; k <= number; ++k) {
        if(!flags[k]) {
            counter++;
        }


    }
    finish = clock();

    double time =((double) (finish - start) /CLOCKS_PER_SEC)*1000;

    cout << "SingleThread : " << endl;
    printf("time : %f ms" , time);
    cout << "\n";
    cout << "CPU utilization = ";
    cout << getCurrentValue();
    cout << " %\n";
    cout << "Mem : ";
    cout << getMemoryUsage();
    cout << endl;

    cout << "counter = " << counter << endl;

    return 0;
}