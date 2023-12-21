#include "ScoringObserver.h"

ScoringObserver::ScoringObserver(int& gameScore) : score(gameScore) {

}

ScoringObserver::~ScoringObserver() {
}

void ScoringObserver::onRowFilled() {
    score += 100;
}
