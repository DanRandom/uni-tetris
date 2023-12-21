#pragma once
#include "GameObserver.h"

class ScoringObserver : public GameObserver {
private:
    int& score;
public:
    ScoringObserver(int& gameScore);
    ~ScoringObserver();
    void onRowFilled() override;
};
