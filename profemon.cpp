//Author: Aleksandra Jelissejeva
//Course: CSCI-135
//Instructor: Gennadiy Maryash
//Assignment: Project 3A

//This program creates skills for profemon.

#include <iostream>
#include "profemon.hpp"



Profemon::Profemon() {
    name = "Undefined";
    level = 0;
    requiredXp = 50;
    currentXp = 0;
    maximumHealth = 0;
    specialty =  ML;
}

Profemon::Profemon(std::string name, double maximumHealth, Specialty specialty) {
    this->name = name;
    this->level = 0;
    this->currentXp = 0;
    this->requiredXp = 50;
    this->maximumHealth = maximumHealth;
    this->specialty = specialty;
}

std::string Profemon::getName() {
    return name;
}

Specialty Profemon::getSpecialty() {
    return specialty;
}

int Profemon::getLevel() {
    return level;
}

double Profemon::getMaxHealth() {
    return maximumHealth;
}
void Profemon::setName(std::string name) {
    this->name = name;
}

void Profemon::levelUp(int exp) {
    currentXp += exp;
    while (currentXp >= requiredXp) {
        currentXp -= requiredXp;
        level++;
        switch (specialty) {
            case ML:
                requiredXp += 10;
                break;
            case SOFTWARE:
                requiredXp += 15;
                break;
            case HARDWARE:
                requiredXp += 20;
                break;
        }
    }
}

bool Profemon::learnSkill(int slot, Skill skill) {
    if (slot < 0 || slot > 2) {
        return false;
    }
    if (skill.getSpecialty() != specialty) {
        return false;
    }
    skills[slot] = skill;
    return true;
}

void Profemon::printProfemon(bool print_skills) {
    std::string word="";
    if (specialty == ML){
    word="ML";
    }
    if (specialty == SOFTWARE){
    word="SOFTWARE";
    }
    if (specialty == HARDWARE){
    word="HARDWARE";
    }
    std::cout << name << " [" << word << "] | lvl " << level << " | exp " << currentXp << "/" << requiredXp << " | hp " << maximumHealth << std::endl;
    if (print_skills) {
        for (int i = 0; i < 3; i++) {
            if (skills[i].getName() != "Undefined") {
                std::cout << "    " << skills[i].getName() << " [" << skills[i].getTotalUses() << "] : " << skills[i].getDescription() << std::endl;
            }
        }
    }
}