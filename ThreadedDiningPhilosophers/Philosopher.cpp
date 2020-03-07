#include "Philosopher.h"
#include "Fork.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int Philosopher::numInstances = 0;

Philosopher::Philosopher(Fork* left, Fork* right, string& rname): numBites(0), bEating(false), name(rname), id(Philosopher::numInstances), leftFork(*left), rightFork(*right), ownsLeftFork(false), ownsRightFork(false)
{

	Philosopher::numInstances += 1;
}

Philosopher::~Philosopher()
{
	if (ownsLeftFork == true) {
		leftFork.finishUsingFork();
	}
	if (ownsRightFork == true) {
		rightFork.finishUsingFork();
	}
}

bool Philosopher::hasLeftFork()
{
	return ownsLeftFork;
}

bool Philosopher::hasRightFork()
{
	return ownsRightFork;
}

bool Philosopher::takeLeftHandFork()
{
	ownsLeftFork = leftFork.useFork();
	return ownsLeftFork;
}

bool Philosopher::takeRightHandFork()
{
	ownsRightFork = rightFork.useFork();
	return ownsRightFork;
}

bool Philosopher::releaseForks()
{
	if (hasRightFork()) {
		rightFork.finishUsingFork();
		ownsRightFork = false;
	}
	if (hasLeftFork()) {
		leftFork.finishUsingFork();
		ownsLeftFork = false;
	}
	return true;
}

string& Philosopher::getName()
{
	// TODO: insert return statement here
	return name;
}

void Philosopher::pigOut() {
	bool bDone = false;
	//this should be a thread so we will turn it into a lambda
	
	while (!bDone) {
		
		chrono::milliseconds pauseTime(250);
		if (id == 0) {
			if (!hasRightFork()) {
				//cout << name << " needs Right fork(" << rightFork.getId() << ")" << endl;
				if (takeRightHandFork()) {
					//Allow others to prepare
					chrono::milliseconds prepTime(250);
					std::this_thread::sleep_for(prepTime);
					if (!hasLeftFork()) {
						//cout << name << " needs Left fork(" << leftFork.getId() << ")" << endl;
						if (takeLeftHandFork()) {
							bEating = true;
							pauseTime = chrono::milliseconds(1000*2);
							numBites++;
						}
						else {
							releaseForks();
						}
					}
				}
			}
		}
		else {
			if (!hasLeftFork()) {
				//cout << name << " needs Right fork(" << rightFork.getId() << ")" << endl;
				if (takeLeftHandFork()) {
					//Allow others to prepare
					chrono::milliseconds prepTime(250);
					std::this_thread::sleep_for(prepTime);
					if (!hasRightFork()) {
						//cout << name << " needs Left fork(" << leftFork.getId() << ")" << endl;
						if (takeRightHandFork()) {
							bEating = true;
							pauseTime = chrono::milliseconds(1000*2);
							numBites++;
						}
						else {
							releaseForks();
							bEating = false;
							//cout << "******" << name << " got Left " << leftFork.getId() << " but failed to get Right " << rightFork.getId() << endl;;
						}
						//cout << name << " took Left fork(" << leftFork.getId() << ")" << endl;
					}
				}
				//cout << name << " took Right fork(" << rightFork.getId() << ")" << endl;
			}
		}

		if (bEating) {
			cout << name << " is eating for " << pauseTime.count()/1000 << " seconds with forks:  " << leftFork.getId() << " and " << rightFork.getId() << endl;
		}
		else {
			//cout << name << " is waiting for " << pauseTime.count() << " milliseconds for forks:  " << leftFork.getId() << " and " << rightFork.getId() << endl;
		}
		
		if (bEating) {
			releaseForks();
			bEating = false;
			
		}
		std::this_thread::sleep_for(pauseTime);
		//cout << name << " is resting for " << 10 << " seconds" << endl;
		if (numBites > 4) {
			bDone = true;
			
		}
	}
	cout << name << " has had 4 bites already and is finished eating!" << endl;
}