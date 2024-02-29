//Author: Aleksandra Jelissejeva
//Course: CSCI-135
//Instructor: Gennadiy Maryash
//Assignment: Project 3A

//This program creates skills for profemon.

#ifndef SKILL_HPP
#define SKILL_HPP

#include <string>

class Skill {
    private:
        std::string name;
        std::string description;
        int total_uses;
        int specialty;

    public:
        Skill();
        Skill(std::string name, std::string description, int specialty, int uses);
        std::string getName();
        std::string getDescription();
        int getTotalUses();
        int getSpecialty();
        void setName(std::string name);
        void setDescription(std::string description);
        void setTotalUses(int uses);
        bool setSpecialty(int specialty);
};
#endif