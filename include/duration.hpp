#ifndef DURATION_H
#define DURATION_H

class Duration
{
private:
    int time;
    int alarm;
    bool alarmHasBeenSet;
    bool checkAndUpdateAlarm();

public:
    Duration();
    ~Duration();

    int getDuration();
    Duration(int t);
    bool tick();
    bool (tick(int dt));
    void (setAlarm(int t));
};
#endif