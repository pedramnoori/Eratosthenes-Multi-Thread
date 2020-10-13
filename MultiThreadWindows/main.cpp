
#include <iostream>
#include <time.h>
#include <math.h>
#include<fstream>
#include <string.h>
#include <chrono>
#include <windows.h>
#include <thread>
#include <psapi.h>

using namespace std;


//Global variables
const int upper = 1000000;
bool flags[upper+1];

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

double getCurrentValue(){
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

SIZE_T Mem(){

   PROCESS_MEMORY_COUNTERS_EX pmc;
   GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
   return pmc.PrivateUsage;
}



void prime(int upper ,int  i){



    for (int j = i*i; j <= upper; j = j+i) {
        flags[j] = true;
    }
}

void check() {

    int numbSq =int (sqrt(upper));
    thread threads[numbSq + 1];

    for (int i = 2; i <= numbSq; i = i * i) {
        for (int j = i; j <min((i * i) , numbSq + 1) ; j++) {
            if (flags[j] == false){
                threads[j] = thread(prime , upper , j);

            }
        }

        for (int k = i; k < min((i * i) , numbSq + 1); ++k) {
            if (flags[k] == false){
                threads[k].join();
            }
        }
    }
}

int main () {

    clock_t start;
    clock_t finish;

    start = clock();

    init();

    check();

    int counter = 0;


    for (int i = 2; i <= upper; i++) {
        if (flags[i] == false){
            counter++;
        }
    }

    finish = clock();

    double time =((double) (finish - start) /CLOCKS_PER_SEC)*1000;

    printf("time : %f ms" , time);
    cout << "\n";
    cout << "CPU utilization = ";
    cout << getCurrentValue();
    cout << " %\n";
    cout << "Mem : ";
    cout << Mem();
    cout << endl;

    cout << "counter = " << counter << endl;


    return 0;

}





