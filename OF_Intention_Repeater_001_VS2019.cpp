/*************************************************************************************************************
Can NOT be run online at : https://www.onlinegdb.com/online_c++_compiler (C++/C++14 seem to be faster than C++17)
Also CAN NOT BE RUN AT : https://repl.it/languages/cpp
THIS SOURCE CODE IS TO BE COMPILED WITH VISUAL STUDIO 2019 (C++ PROJECT)
*************************************************************************************************************/

#include <iostream>
//#include <unistd.h>
#include <cstdlib>
#include <signal.h>
#include <chrono>
#include <string>
//#include <cpuid.h>

using namespace std;

unsigned long long intention_repeats_counter = 0; unsigned int M = 0;

std::chrono::steady_clock::time_point t1;
std::chrono::steady_clock::time_point t2;

// When CTRL+C (SIGINT), this is executed, also when program is stopped (SIGTERM, eg. useful on repl.it but not on onlinegdb)
void signal_callback_handler(int signum) {
    t2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = t2 - t1;
    std::cout << "Total execution time is " << diff.count() << " seconds" << " = " << diff.count()/60 << " minutes" << " = " << diff.count()/60/60 << " hours" << endl;
    unsigned long long average_intention_repeats_per_sec = (unsigned long long)(intention_repeats_counter / diff.count());
    std::cout << "Number of average intention repeats per microsecond was " << std::to_string(((float)average_intention_repeats_per_sec) / 1000 / 1000) << endl;
    std::cout << "Number of average intention repeats per millisecond was " << std::to_string(average_intention_repeats_per_sec/1000) << endl;
    std::cout << "Number of average intention repeats per second was " << std::to_string(average_intention_repeats_per_sec) << endl;
    std::cout << "Number of average intention repeats per minute was " << std::to_string(average_intention_repeats_per_sec * 60) << endl;
    std::cout << "Number of average intention repeats per minute was " << std::to_string(((float)(average_intention_repeats_per_sec * 60))/1000000) << " millions\n";
    std::cout << "Number of effective intention repeats = " << intention_repeats_counter << endl;
    std::cout << "Number of effective intention repeats = " << ((float)intention_repeats_counter)/1000000 << " millions" << endl;
    // Terminate program
    exit(signum);
}


int main()
{
    signal(SIGINT, signal_callback_handler);
    signal(SIGTERM, signal_callback_handler);

    std::string intention, process_intention;

    cout << "Start sending. CTRL+C to stop." << endl;
    t1 = std::chrono::steady_clock::now();
    intention = "LOVE";
    while (true) {
        process_intention = intention;
        intention_repeats_counter++;
        //if (intention_repeats_counter % 1000000 == 0) { M++; cout << M << "M\r"; } // This line slows the processing
        //cout << M++ << "\r";
    }
    return 0;
}
