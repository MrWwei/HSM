#ifndef _DOOR_HPP__
#define _DOOR_HPP__

#include "StateMachine.h"

class DoorData : public EventData
{
public:
    INT speed;
};

class Door : public StateMachine
{
public:
    Door();
    // 外部事件
    // External events taken by this state machine
    void ex_Lock();
    void ex_Unlock();
    void ex_Open();
    void ex_Close();

private:
    // State enumeration order must match the order of state method entries
    // in the state map.
    // 状态
    enum States
    {
        ST_IDLE,
        ST_Closed,
        ST_Unlocked,
        ST_Locked,
        ST_Opened,
        ST_MAX_STATES
    };
    // 声明状态函数
    // Define the state machine state functions with event data type
    STATE_DECLARE(Door,Idle,NoEventData)
    STATE_DECLARE(Door, Close, NoEventData)
    STATE_DECLARE(Door, Unlock, NoEventData)
    STATE_DECLARE(Door, Lock, NoEventData)
    STATE_DECLARE(Door, Open, NoEventData)


    // State map to define state object order. Each state map entry defines a
    // state object.
    BEGIN_STATE_MAP
    STATE_MAP_ENTRY(&Idle)
    STATE_MAP_ENTRY(&Close)
    STATE_MAP_ENTRY(&Unlock)
    STATE_MAP_ENTRY(&Lock)
    STATE_MAP_ENTRY(&Open)
    END_STATE_MAP
};

#endif