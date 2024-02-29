//Author: Aleksandra Jelissejeva
//Course: CSCI-135
//Instructor: Gennadiy Maryash
//Assignment: Project 3A

//This program creates skills for profemon.

#include "skill.hpp"
#include <iostream>

Skill::Skill() {
    name = "Undefined";
    description = "Undefined";
    total_uses = -1;
    specialty = -1;
}
Skill::Skill(std::string name, std::string description, int specialty, int uses) {
    this->name = name;
    this->description = description;
    this->total_uses = uses;
    this->specialty = specialty;
}
std::string Skill::getName() {
    return name;
}
std::string Skill::getDescription() {
    return description;
}
int Skill::getTotalUses() {
    return total_uses;
}
int Skill::getSpecialty() {
    return specialty;
}
void Skill::setName(std::string name) {
    this->name = name;
}
void Skill::setDescription(std::string description) {
    this->description = description;
}
void Skill::setTotalUses(int uses) {
    this->total_uses = uses;
}
bool Skill::setSpecialty(int specialty) {
    if (specialty == 0 || specialty == 1 || specialty == 2) {
        this->specialty = specialty;
        return true;
    }
    return false;
}