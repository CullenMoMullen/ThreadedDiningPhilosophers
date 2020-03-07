#include "DiningPhilosophers.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <valarray>
#include "Philosopher.h"
#include "Fork.h"

using namespace std;

DiningPhilosophers::DiningPhilosophers(int numPhilosophers)
{
	cout << "Welcome to the Dining of the " << numPhilosophers << " Philosophers!" << endl;
	cout << "Setting the table with " << numPhilosophers << " chairs and " << numPhilosophers + 1 << " forks." << endl;
	
	m_Forks.resize(numPhilosophers);

	int numForks = numPhilosophers;
	cout << "-------------------------------------" << endl;;
	cout << "Created Fork: ";
	for (int i = 0; i < numForks;i++) {
		Fork* f1 = new Fork();
		m_Forks[i] = f1;
		cout << f1->getId();
		if (i < numForks - 1) {
			cout << ", ";
		}
		else {
			cout << endl;
		}
	}
	cout << "-------------------------------------" << endl;
	
	int num = 0;

	cout << "-------------------------------------" << endl;;
	

	
	for (num = 0; num < numPhilosophers; num++) {
		addPhilosopher(m_Forks[num], m_Forks[(num + 1) % numPhilosophers], names[num]);
		cout << "Created Philosopher: " << m_Philosophers[num]->getName() << " - " << m_Philosophers[num]->getId() << endl;
	}
	cout << "-------------------------------------" << endl << endl << endl;

	cout << "Successfully set table for " << num << " philosophers!" << endl;
	cout << "Shall we Eat?!?" << endl << endl;

	cout << endl << endl;
	for (auto& p : m_Philosophers) {
		cout << p->getName() << " {" << p->leftFork.getId() << ", " << p->rightFork.getId() << "}" << endl;
	}
}

DiningPhilosophers::~DiningPhilosophers()
{
	while (m_Philosophers.size() > 0) {
		Philosopher *philo = m_Philosophers.back();
		m_Philosophers.pop_back();
		delete philo;
	}

	while (m_Forks.size() > 0) {
		Fork *fork = m_Forks.back();
		m_Forks.pop_back();
		delete fork;
	}
}

vector<Philosopher*>& DiningPhilosophers::getPhilosophers()
{
	// TODO: insert return statement here
	return m_Philosophers;
}

int DiningPhilosophers::addPhilosopher(Fork* left, Fork* right, string& rname)
{
	Philosopher* philo = new Philosopher(left, right, rname);
	m_Philosophers.push_back(philo);

	return m_Philosophers.size();
}
