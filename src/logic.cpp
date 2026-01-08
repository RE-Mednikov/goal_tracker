//
// Created by Arie Mednikov on 2026-01-07.
//

#include <utility>

#include "goaltracker/logic.h"
#include "goaltracker/types.h"
#include "goaltracker/data.h"
#include "goaltracker/storage.h"
#include "goaltracker/storage.h"

//get functions

Goal getGoal(std::string name) {
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

    return nullptr; //figure out null pointer?
}

//create functions
Goal createGoal(std::string goalName, std::string goalDescription) {
    Goal newGoal;
    newGoal.name = std::move(goalName);
    newGoal.description = std::move(goalDescription); //we can only use std::move becasue we don't need the value again later, destroying it here for efficiency
    newGoal.currentStep = 0;
    newGoal.completed = false;

    return newGoal;
}


