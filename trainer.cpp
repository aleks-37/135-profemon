
//Author: Aleksandra Jelissejeva
//Course: CSCI-135
//Instructor: Gennadiy Maryash
//Assignment: Project 3B

//This program creates skills for profemon.

#include "trainer.hpp"
#include "profemon.hpp"
#include <iostream>
using namespace std;
Trainer::Trainer() {
    currentlySelected = nullptr;
}
Trainer::Trainer(vector<Profemon> profemons){
    int index = 0;
    for(int i = 0; i < 3; i++){
        if(team[i].getName() == "Undefined"){
            team[i] = profemons[index];
            index++;
        }
    }
    for(int j = index; j < profemons.size(); j++){
        profedex.push_back(profemons[j]);
    }
    currentlySelected = &team[0];
}
bool Trainer::contains(string name){
	for(int i = 0; i < 3; i++){
		if(team[i].getName() == name){
			return true;
		}
	}
	for(int j = 0; j < profedex.size(); j++){
		if(profedex[j].getName() == name)
		{
			return true;
		}
	}
	return false;
}
bool Trainer::addProfemon(Profemon profemon){
	if(contains(profemon.getName())){
		return false;
	}
	for(int i = 0; i < 3; i++){
		if(team[i].getName() == "Undefined"){
			team[i] = profemon;
			return true;
		}
	}
	profedex.push_back(profemon);
	return true;
}
bool Trainer::removeProfemon(string name){
	if(!contains(name)){
		return false;
	}
    for(int i = 0; i < 3; i++){
		if(team[i].getName() == name){
			Profemon p;
			team[i] = p;
			return true;
		}
	}
	for(int i = 0; i < profedex.size(); i++){
		if(profedex[i].getName() == name){
			profedex[i] = profedex[profedex.size() - 1];
			for(int j = i; j < profedex.size() - 1; j++){
				profedex[j] = profedex[j + 1];
			}
			profedex.pop_back();
			return true;
		}
	}
	return false;
}
void Trainer::setTeamMember(int slot, string name){
    int index = 0;
    for(int i = 0; i < profedex.size(); i++){
        if(profedex[i].getName() == name){
            index = i;
				break;
        }
    }
    if(team[slot].getName() == "Undefined"){
        team[slot] = profedex[index];
        profedex[index] = profedex[profedex.size() - 1];
        for(int i = index; i < profedex.size() - 1; i++){
            profedex[i] = profedex[i + 1];
        }
        profedex.pop_back();
    }
    else
    {
        Profemon currentlyy = team[slot];
        team[slot] = profedex[index];
        profedex[index] = currentlyy;
    }
}
bool Trainer::chooseProfemon(int slot){
	if(team[slot].getName() == "Undefined"){
		return false;
	}
	currentlySelected = &team[slot];
	return true; 
}
Profemon Trainer::getCurrent() {
    return *currentlySelected;
}
void Trainer::printProfedex(){
	for(int i = 0; i < profedex.size(); i++){
	    if(profedex[i].getName() != "Undefined"){
		    profedex[i].printProfemon(true);
		}
		cout << "\n";
	}
}
void Trainer::printTeam(){
	for(int i = 0; i < 3; i++){
	    if(team[i].getName() != "Undefined")
	    {
		    team[i].printProfemon(true);
		    cout << "\n";
		}
	}
}
