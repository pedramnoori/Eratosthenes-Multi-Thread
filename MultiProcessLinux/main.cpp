#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <iostream>
#include <math.h>
#include <cstring>

#include <iostream>
#include <time.h>
#include <math.h>
#include <thread>

using namespace std;
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include<fstream>
#include<iostream>
#include <stdio.h>
#include <string.h>
#include <chrono>
#include <unistd.h>
#include <thread>
#include <sys/mman.h>
#include <sys/times.h>
#include <sys/vtimes.h>


const int upper = 1000000;
bool* flags = static_cast<bool *>(mmap(NULL, sizeof(bool) * (upper + 1) , PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS , -1, 0));

int parseLine(char* line){
    // This assumes that a digit will be found and the line ends in " Kb".
    int i = strlen(line);
    const char* p = line;
    while (*p <'0' || *p > '9') p++;
    line[i-3] = '\0';
    i = atoi(p);
    return i;
}

int getValue(){ //Note: this value is in KB!
    FILE* file = fopen("/proc/self/status", "r");
    int result = -1;
    char line[128];

    while (fgets(line, 128, file) != NULL){
        if (strncmp(line, "VmSize:", 7) == 0){
            result = parseLine(line);
            break;
        }
    }
    fclose(file);
    return result;
}





static clock_t lastCPU, lastSysCPU, lastUserCPU;
static int numProcessors;

void init(){
    FILE* file;
    struct tms timeSample;
    char line[128];

    lastCPU = times(&timeSample);
    lastSysCPU = timeSample.tms_stime;
    lastUserCPU = timeSample.tms_utime;


    file = fopen("/proc/cpuinfo", "r");
    numProcessors = 0;
    while(fgets(line, 128, file) != NULL){
        if (strncmp(line, "processor", 9) == 0) numProcessors++;
    }
    fclose(file);
}

double getCurrentValue(){
    struct tms timeSample;
    clock_t now;
    double percent;

    now = times(&timeSample);
    if (now <= lastCPU || timeSample.tms_stime < lastSysCPU ||
        timeSample.tms_utime < lastUserCPU){
        //Overflow detection. Just skip this value.
        percent = -1.0;
    }
    else{
        percent = (timeSample.tms_stime - lastSysCPU) +
                  (timeSample.tms_utime - lastUserCPU);
        percent /= (now - lastCPU);
        percent /= numProcessors;
        percent *= 100;
    }
    lastCPU = now;
    lastSysCPU = timeSample.tms_stime;
    lastUserCPU = timeSample.tms_utime;

    return percent;
}

void prime(int upper ,int  i){

    for (int j = i*i; j <= upper; j = j+i) {
        flags[j] = true;
    }
}

bool check() {

    int numbSq =int (sqrt(upper));
//    thread threads[numbSq + 1];
    pid_t pid[numbSq + 1];

    for (int i = 2; i <= numbSq; i = i * i) {
        for (int j = i; j <min((i * i) , numbSq + 1) ; j++) {
            if (flags[j] == false){
                pid[j] = fork();

                if(pid[j] == 0){
                    prime(upper,j);
                    return 1;
                }

            }
        }

        for (int k = i; k < min((i * i) , numbSq + 1); ++k) {
            if (flags[k] == false){
                int what;
                waitpid(pid[k] , &what , 0);
            }
        }
    }
    return 0;
}

int main () {

    clock_t start;
    clock_t finish;

    start = clock();

    init();

    bool findChild = check();
    if (findChild) {
        return 0;
    }

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
    cout << getValue();
    cout << endl;

    cout << "counter = " << counter << endl;


    return 0;

}
