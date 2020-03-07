#include "Fork.h"
#include <mutex>
#include <iostream>
//initialize static id to zero
using namespace std;
int Fork::numInstances = 0;

Fork::Fork(): forklock(nullptr), uid(Fork::numInstances)
{
	forklock = new std::mutex();
	Fork::numInstances += 1;
}

Fork::~Fork()
{
	if (forklock != nullptr)
		delete forklock;
}

bool Fork::useFork()
{
	return forklock->try_lock();
}

bool Fork::finishUsingFork()
{
	forklock->unlock();
	return 0;
}
