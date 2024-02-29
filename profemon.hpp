//Author: Aleksandra Jelissejeva
//Course: CSCI-135
//Instructor: Gennadiy Maryash
//Assignment: Project 3A

//This program creates skills for profemon.

#ifndef PROFEMON_HPP  
#define PROFEMON_HPP 

#include "skill.hpp"
#include <string>

enum Specialty { 
    ML,
    SOFTWARE,
    HARDWARE 
    
};

class Profemon {
private:
    std::string name;
    int level;
    int requiredXp;
    int currentXp;
    double maximumHealth;
    Specialty specialty;
    Skill skills[3];

public:
    Profemon();
    Profemon(std::string name, double max_health, Specialty specialty);
    std::string getName();
    Specialty getSpecialty();
    int getLevel();
    double getMaxHealth();
    void setName(std::string name);
    void levelUp(int exp);
    bool learnSkill(int slot, Skill skill);
    void printProfemon(bool print_skills);
};
#endif