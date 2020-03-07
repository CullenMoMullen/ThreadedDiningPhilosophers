#pragma once
#include <vector>
#include <valarray>
#include <string>
using namespace std;
class Philosopher;
class Fork;

class DiningPhilosophers
{
public:
	DiningPhilosophers(int numPhilosophers);
	~DiningPhilosophers();
	
	std::vector<Philosopher*>& getPhilosophers();
	int addPhilosopher(Fork* left, Fork* right, string& rname);



private: 
	std::vector<Philosopher*> m_Philosophers;
	std::vector<Fork*> m_Forks;

	string names[5] = {
	"David",
	"Karen",
	"Henry",
	"Marta",
	"Logan"
	};

};

