#pragma once
#include <string>

using namespace std;

class Fork;

class Philosopher
{
public:
	Philosopher(Fork* left, Fork* right, string& rname);
	~Philosopher();
	
	int getId() { 
		return id; 
	}
	string& getName();
	void pigOut();
	Fork& rightFork;
	Fork& leftFork;

	bool hasLeftFork();
	bool hasRightFork();
	bool bEating;
	int numBites;


private:
	void setId(int uid) {
		id = uid;
	}
	const int eatTimeSec = 5;
	int id;
	bool ownsLeftFork;
	bool ownsRightFork;
	string name;

	bool takeLeftHandFork();
	bool takeRightHandFork();
	bool releaseForks();
	static int numInstances;
	bool isEating();
};

