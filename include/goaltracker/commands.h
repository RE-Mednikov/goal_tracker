//
// Created by Arie Mednikov on 2026-01-07.
//

#ifndef GOAL_TRACKER_COMMANDS_H
#define GOAL_TRACKER_COMMANDS_H

#include <string>
#include "types.h"

//utilizing distinct names, ids add for extra confusion and the user doesn't want to always reference the id list
//in the future might switch to ID's, or make it so that completed goals names can be reused, but they cant be uncompleted if their is a active goal with the same name? Although this is annoying for checking if goal is completed.
    //ie. might have to switch to ID's in the future if I find this annoying

// add functions (create_
void addGoal(std::string goalName);
void addStep(std::string stringName, std::string goalName);
void addStepPositional(std::string stringName, std::string goalName, int stepPosition);
void addTask(std::string taskName, std::string goalName, std::string stepName);
void addTaskPositional(std::string taskName, std::string goalName, std::string stepName, int taskPosition);


//view functions (read_
void viewGoals();
void viewGoal(std::string goalName);
void viewStep(std::string stepName, std::string goalName);
void viewTask(std::string taskName, std::string goalName, std::string stepName);
void viewGoalCompletionStatus(std::string goalName);
void viewGoalSteps(std::string goalName);
void viewGoalDescription(std::string goalName);
void viewStepCompletionStatus(std::string stepName, std::string goalName);
void viewStepTasks(std::string stepName, std::string goalName);
void viewStepDescription(std::string stepName, std::string goalName);
void viewTaskCompletionStatus(std::string taskName, std::string goalName, std::string stepName);
void viewTaskDescription(std::string taskName, std::string goalName, std::string stepName);

//update functions (update)
void updateGoalName(std::string newName, std::string goalName);
void updateGoalDescription(std::string newDescription, std::string goalName);
void updateStepName(std::string newName, std::string name, std::string goalName);
void updateStepDescription(std::string newDescription, std::string name, std::string goalName);
void updateStepPosition(std::string name, std::string goalName, int stepPosition);
void updateTaskName(std::string name, std::string goalName, std::string stepName);
void updateTaskDescription(std::string name, std::string goalName, std::string stepName);
void updateTaskPosition(std::string name, std::string goalName, std::string stepName, int taskPosition);

    //completed updates
void completeGoal(std::string goalName);
void uncompleteGoal(std::string goalName);
void completeStep(std::string stepName, std::string goalName); //this just iterates the goals current step counter, assuming that it is within all its bounds
void uncompleteStep(std::string stepName, std::string goalName);
void completeTask(std::string taskName, std::string goalName, std::string stepName);
void uncompleteTask(std::string taskName, std::string goalName, std::string stepName);

//remove functions (delete)
void removeGoal(std::string name);
void removeStep(std::string name, std::string goalName);
void removeTask(std::string name, std::string goalName, std::string stepName);


#endif //GOAL_TRACKER_COMMANDS_H