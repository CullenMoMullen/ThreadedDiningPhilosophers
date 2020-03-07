#pragma once

#include <thread>
#include <mutex>

class Fork
{
public:
	Fork();
	~Fork();
	
	int getId() {
		return uid;
	}

	bool useFork();
	bool finishUsingFork();

protected:	
	std::mutex* forklock;

private:	
	static int numInstances;
	int uid;

};

