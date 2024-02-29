
//Author: Aleksandra Jelissejeva
//Course: CSCI-135
//Instructor: Gennadiy Maryash
//Assignment: Project 3B

//This program creates skills for profemon.

#include "department.hpp"
using namespace std;

MLDepartment::MLDepartment(vector<Profemon> profemons){
    for(int i = 0; i < profemons.size(); i++){
        if(profemons[i].getSpecialty() == ML){
            addProfemon(profemons[i]);
        }
    }
}
bool MLDepartment::addProfemon(Profemon profemon) {
    if (profemon.getSpecialty() == ML) {
        return Trainer::addProfemon(profemon);
    }
    return false;
}
SoftwareDepartment::SoftwareDepartment(vector<Profemon> profemons){
    for(int i = 0; i < profemons.size(); i++){
        if(profemons[i].getSpecialty() == SOFTWARE){
            addProfemon(profemons[i]);   
        }
    }
}
bool SoftwareDepartment::addProfemon(Profemon profemon){
    if(profemon.getSpecialty() == SOFTWARE){
        return Trainer::addProfemon(profemon);
    }
        return false;
}
HardwareDepartment::HardwareDepartment(vector<Profemon> profemons){
    for(int i = 0; i < profemons.size(); i++){
        if(profemons[i].getSpecialty() == HARDWARE){
            addProfemon(profemons[i]);
        }
    }
}
bool HardwareDepartment::addProfemon(Profemon profemon) {
    if (profemon.getSpecialty() == HARDWARE) {
        return Trainer::addProfemon(profemon);
    }
    return false;
}