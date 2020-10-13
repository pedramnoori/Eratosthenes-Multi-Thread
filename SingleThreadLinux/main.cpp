#include <iostream>
#include <time.h>
#include <math.h>
#include <thread>
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include<fstream>
#include <stdio.h>
#include <string.h>
#include <chrono>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/times.h>
#include <sys/vtimes.h>

using namespace std;

//Global variables

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


int main() {

    clock_t start;
    clock_t finish;

    init();

    start = clock();

    const int number = 1000000;
    bool flags[number+1];

    int counter = 0;

    for (int i = 0; i <= number; i++)
        flags[i] =  false;



    for (int i = 2; i <= (int)sqrt(number); i++) {
        if(!flags[i]){
            for (int j = (int)(pow(i,2)); j <= number; j+=i) {
                flags[j] = true;
            }
        }
    }



    for (int k = 2; k <= number; ++k) {
        if(!flags[k]) {
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