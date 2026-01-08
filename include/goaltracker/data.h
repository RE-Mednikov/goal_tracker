//
// Created by Arie Mednikov on 2026-01-07.
//

#ifndef GOAL_TRACKER_DATA_H
#define GOAL_TRACKER_DATA_H

#include <vector>
#include "types.h"

struct State {
    std::vector<Goal> goals;
    std::vector<Goal> completedGoals;
};

#endif //GOAL_TRACKER_DATA_H