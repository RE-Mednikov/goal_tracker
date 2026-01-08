//
// Created by Arie Mednikov on 2026-01-07.
//

#ifndef GOAL_TRACKER_LOGIC_H
#define GOAL_TRACKER_LOGIC_H

#include <string>
#include "types.h"

//these also use the names to get each other, because it's easier to check if goal names are = instead of goal instances
//go over how to check if instances are = in C++
//Should this be done by comparing the instances and not the names, even if we know the names are unique?

//create functions
Goal createGoal(std::string goalName, std::string goalDescription);
Step createStep(std::string stepName, std::string stepDescription, std::string goalName);
Step createTask(std::string taskName, std::string taskDescription, std::string goalName, std::string stepName);

//get functions
Goal getGoal(std::string name);
Step getStep(std::string name, std::string goalName);
Task getTask(std::string name, std::string goalName, std::string stepName);


#endif //GOAL_TRACKER_LOGIC_H