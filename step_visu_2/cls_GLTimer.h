#pragma once

#include "GL/glew.h"

/**
 * This is a primitive timer class which is using the OpenGL TIMESTAMP functionality.
 * Return values in milliseconds.
 *
 * First you Start() the timer and get the system
 * timestamp (which you most probably will not use).
 * Then you may call Milestone() to get the diff
 * from the last Milestone() or Start() if there were no Milestone() yet.
 * Or you may call MilestoneFromStart() to set the milestone but
 * get the diff specifically from the Start().
 * FromStart() does not set the milestome and returns the diff from the Start().
 * Stop returns the diff from the Start() and clears the timer.
 * If you call anything but Start() after Stop() it will return 0.
 * Example:
 * timer.Start();
 * timer.Milestone();
 * timer.Milestone();
 * timer.Milestone();
 * timer.Stop();
 */

class cls_GLTimer
{
private:
    GLint64 mTimerStart;
    GLint64 mTimerIntermid;

public:
    cls_GLTimer(void);
    ~cls_GLTimer(void);

    double Start(void);
    double Milestone(void);
    double MilestoneFromStart(void);
    double FromStart(void);
    double Stop(void);
};
