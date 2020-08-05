#include "Door.hpp"
#include <iostream>

using namespace std;

Door::Door() :
	StateMachine(ST_MAX_STATES)
{
}
	
// set motor speed external event
/*
void ex_Lock();
    void ex_Unlock();
    void ex_Open();
    void ex_Close();
*/
void Door::ex_Lock()
{
	BEGIN_TRANSITION_MAP			              			// - Current State -
		TRANSITION_MAP_ENTRY (EVENT_IGNORED)                 // ST_IDLE
        TRANSITION_MAP_ENTRY (ST_Locked)				// ST_Closed
		TRANSITION_MAP_ENTRY (ST_Locked)				    // ST_Unlocked
		TRANSITION_MAP_ENTRY (EVENT_IGNORED)				// ST_Locked
		TRANSITION_MAP_ENTRY (EVENT_IGNORED)				// ST_Opened
	END_TRANSITION_MAP(NULL)
}

void Door::ex_Unlock()
{
	BEGIN_TRANSITION_MAP			              			// - Current State -
		TRANSITION_MAP_ENTRY (ST_Unlocked)                       // ST_IDLE
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)				// ST_Closed
		TRANSITION_MAP_ENTRY (EVENT_IGNORED)				// ST_Unlocked
		TRANSITION_MAP_ENTRY (ST_Unlocked)				// ST_Locked
		TRANSITION_MAP_ENTRY (EVENT_IGNORED)				// ST_Opened
	END_TRANSITION_MAP(NULL)
}

void Door::ex_Open()
{
	BEGIN_TRANSITION_MAP			              			// - Current State -
        TRANSITION_MAP_ENTRY (ST_Unlocked)                   // ST_IDLE
		TRANSITION_MAP_ENTRY (ST_Unlocked)				// ST_Closed
		TRANSITION_MAP_ENTRY (ST_Opened)				// ST_Unlocked
		TRANSITION_MAP_ENTRY (ST_Unlocked)				// ST_Locked
		TRANSITION_MAP_ENTRY (ST_Locked)				// ST_Opened
	END_TRANSITION_MAP(NULL)
}

void Door::ex_Close()
{
	BEGIN_TRANSITION_MAP			              			// - Current State -
		TRANSITION_MAP_ENTRY (EVENT_IGNORED)                 // ST_IDLE
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)				// ST_Closed
		TRANSITION_MAP_ENTRY (EVENT_IGNORED)				// ST_Unlocked
		TRANSITION_MAP_ENTRY (EVENT_IGNORED)				// ST_Locked
		TRANSITION_MAP_ENTRY (ST_Closed)				// ST_Opened
	END_TRANSITION_MAP(NULL)
}


STATE_DEFINE(Door, Idle, NoEventData)
{
	cout << "Door::ST_Idle" << endl;
}

// state machine sits here when motor is not running
STATE_DEFINE(Door,Lock,NoEventData)
{
    std::cout << "Enter Locked state." << std::endl;

}

STATE_DEFINE(Door,Unlock,NoEventData)
{
    std::cout << "Enter Unlocked state." << std::endl;
    // InternalEvent(ST_Opened);
}

STATE_DEFINE(Door,Open,NoEventData)
{
    std::cout << "Enter Opened state." << std::endl;
    // InternalEvent(ST_Closed);
}

STATE_DEFINE(Door,Close,NoEventData)
{
    std::cout << "Enter Closed state." << std::endl;
    // InternalEvent(ST_Locked);
}