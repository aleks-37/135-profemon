
//Author: Aleksandra Jelissejeva
//Course: CSCI-135
//Instructor: Gennadiy Maryash
//Assignment: Project 3B

//This program creates skills for profemon.

#ifndef TRAINER_HPP
#define TRAINER_HPP
#include <vector>
#include <string>
#include "profemon.hpp"

using namespace std;

class Trainer {
    
public:
    Trainer();
		Trainer(vector <Profemon> profemons);
		bool contains(string name);
		bool addProfemon(Profemon profemon);
		bool removeProfemon(string name);
		void setTeamMember(int slot, string name);
		bool chooseProfemon(int slot);
		Profemon getCurrent();
		void printProfedex();
		void printTeam();
private:
    string nameofProfemon;
    vector<Profemon> profedex;
    Profemon team[3];
    Profemon* currentlySelected;
};

#endif 