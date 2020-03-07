// ThreadedDiningPhilosophers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <thread>
#include "DiningPhilosophers.h"
#include "Philosopher.h"
using namespace std;

/*
void accumulator_function2(const std::vector<int>& v, unsigned long long& acm,
    unsigned int beginIndex, unsigned int endIndex);

void accumulator_function2(const std::vector<int>& v, unsigned long long& acm,
    unsigned int beginIndex, unsigned int endIndex)
{
    acm = 0;
    for (unsigned int i = beginIndex; i < endIndex; ++i)
    {
        acm += v[i];
    }
}
*/

int main()
{
    
    std::vector<std::thread> threads;
    DiningPhilosophers diners(5);
    
    for (auto &p : diners.getPhilosophers()) {
        threads.push_back(std::thread(&Philosopher::pigOut, p));
    }
    
    for (auto& thread : threads) {      
        thread.join();
        cout << "One thread returned." << endl;
    }

    cout << "Yummy!!!" << endl;


    //vector<int> v({ 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25 });
    //unsigned long long acm1 = 0;
    //unsigned long long acm2 = 0;
    //thread t1(accumulator_function2, std::ref(v),std::ref(acm1), 0, v.size() / 2);
    //thread t2(accumulator_function2, std::ref(v),std::ref(acm2), v.size() / 2, v.size());
    //t1.join();
    //t2.join();

    //cout << "acm1: " << acm1 << endl;
    //cout << "acm2: " << acm2 << endl;
    //cout << "acm1 + acm2: " << acm1 + acm2 << endl;
    

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
