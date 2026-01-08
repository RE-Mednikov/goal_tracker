//
// Created by Arie Mednikov on 2026-01-07.
//

#ifndef GOAL_TRACKER_TYPES_H
#define GOAL_TRACKER_TYPES_H

#include <string>
#include <vector>

struct Task {
    std::string name;
    std::string description;
};

struct Step {
    std::string name;
    std::vector<Task> tasks;
    std::string description;
    int currentTask;
};

struct Goal {
    std::string name;
    std::vector<Step> steps;
    std::string description;
    int currentStep;
    bool completed; //not actually required (can just check the states array), but might make it easier to do a check if goal completed function
};


#endif //GOAL_TRACKER_TYPES_H

