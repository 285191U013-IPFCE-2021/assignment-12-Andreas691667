#include <stddef.h>
#include <assert.h>
#include "duration.hpp"

//constructor (no start value)
Duration::Duration() {
    time = 0; //in this constructor, the time should be initialized to 0
    alarm = 0; //alarm is initialized to 0
    alarmHasBeenSet = false; //no alarm has been set constructor
}

//constructor (with start value)
Duration::Duration(int t) {
    assert(time>=0); //precondition

    time = t; //in this constructor, the time should be set to input value t
    alarm = 0; //alarm is initialized to 0
    alarmHasBeenSet = false; //no alarm has been set in constructor
}

//returns the current time
int Duration::getDuration() {
    return time;
}

//increments time with 1 and return true if time exceeds alarm, else false is returned
bool Duration::tick() {
    assert(time >= 0); //precondition
    time++;    
    return checkAndUpdateAlarm();
}

//increments time with input value dt and return true if time exceeds alarm, else false is returned
bool Duration::tick(int dt) {
    assert(time>=0); //precondition
    time += dt;
    return checkAndUpdateAlarm();
}

//sets alarm to input value t
void Duration::setAlarm(int t) {
    assert(time>=0 && t>time); //precondition
    alarm = t;
}

//updates and returns private attribute alarmHasBeenSet to true if time exceeds alarm, false otherwise.
bool Duration::checkAndUpdateAlarm() {

    if (time >= alarm)
    {
        alarmHasBeenSet = true;
        alarm = 0; //alarm is reset
    }
    else
        alarmHasBeenSet = false;
    
    return alarmHasBeenSet;
}

//destructor
Duration::~Duration() 
{}
