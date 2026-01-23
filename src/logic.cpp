//
// Created by Arie Mednikov on 2026-01-07.
//

#include <utility>

#include "goaltracker/logic.h"
#include "goaltracker/types.h"
#include "goaltracker/data.h"
#include "goaltracker/storage.h"
#include "goaltracker/storage.h"

//NEED TO ADD VERIFICATION CHECKS, MAKE SURE NAMES ARE ALL VALID AND WHAT HAPPENS IF THEY AREN'T, AND THAT ALL THE VALUES PROVIDED FOR CREATION ARE CORRECT!!! NEXT TIME
//get functions

//Need to start testing these functions independendently soon, including edge cases. Learn best way to do testing in C++!!
//might make sense to make two delete goal function for delete from goals and delete from completed goals and that way can use those functions when moving from complete to not complete and vice versa... + can use both for full delete function???

std::optional<Goal> getGoal(std::string name) {
    State state = getCurrentState();
    int currentGoalsSize = state.goals.size();
    int completedGoalsSize = state.completedGoals.size();
    for (int i = 0; i < currentGoalsSize; i++) {
        if (state.goals[i].name == name) {
            return state.goals[i];
        }
    }
    for (int i = 0; i < completedGoalsSize; i++) {
        if (state.completedGoals[i].name == name) {
            return state.completedGoals[i];
        }
    }

    return std::nullopt; //figure out null pointer?
}


std::optional<Step> getStep(std::string name, std::string goalName) {
    Goal ownerGoal = getGoal(goalName).value();
    int stepAmount = ownerGoal.steps.size(); //what does narrowing conversion mean?
    for (int i = 0; i < stepAmount; i++) {
        if (ownerGoal.steps[i].name == name) {
            return ownerGoal.steps[i];
        }
    }

    return std::nullopt;//figure out null pointer?
}

std::optional<Task> getTask(std::string name, std::string goalName, std::string stepName) {
    Goal ownerGoal = getGoal(goalName).value();
    Step ownerStep = getStep(stepName, goalName).value();
    int taskAmount = ownerStep.tasks.size();

    for (int i = 0; i < taskAmount; i++) {
        if (ownerStep.tasks[i].name == name) {
            return ownerStep.tasks[i];
        }
    }

    return std::nullopt;
}



//create functions
Goal createGoal(std::string goalName, std::string goalDescription) {
    Goal newGoal;
    newGoal.name = std::move(goalName);
    newGoal.description = std::move(goalDescription); //we can only use std::move becasue we don't need the value again later, destroying it here for efficiency
    newGoal.currentStep = 0;
    newGoal.completed = false;

    State state = getCurrentState();
    state.goals.push_back(newGoal);

    return newGoal;
}

Step createStep(std::string stepName, std::string stepDescription, std::string goalName) {
    Step newStep;
    newStep.name = std::move(stepName);
    newStep.description = std::move(stepDescription);
    newStep.currentTask = 0;
    Goal ownerGoal = getGoal(goalName).value();
    ownerGoal.steps.push_back(newStep); //add step to the end of the last goal

    return  newStep;
}

Task createTask(std::string taskName, std::string taskDescription, std::string goalName, std::string stepName) {
    Task newTask;
    newTask.name = std::move(taskName);
    newTask.description = std::move(taskDescription);

    Step ownerStep = getStep(stepName, goalName).value();
    ownerStep.tasks.push_back(newTask);

    return newTask;
}





//update functions

void CompleteGoal(std::string goalName) {
    Goal ownerGoal = getGoal(goalName).value();

    //check if already completed
    if (ownerGoal.completed == true) {
        return;
    }

    State state = getCurrentState();

    //add to completed goals
    state.completedGoals.push_back(ownerGoal);

    //remove from goals
    int currentIndex;
    int currentGoalsSize = state.goals.size();
    for (int i = 0; i < currentGoalsSize; i++) {
        if (state.goals[i].name == goalName) {
            currentIndex = i;
            break;
        }
    }

    state.goals.erase(state.goals.begin() + currentIndex); //make sure this is the right position

}





