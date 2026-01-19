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












