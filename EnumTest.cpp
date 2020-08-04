#include <stdio.h>

enum { name, pass, };
enum DAY { MON = 1, TUE, WED, THU, FRI, SAT, SUN };
enum class ENUM_CLASS { month = 0x1, year, day, };
enum struct ENUM_STRUCT{ mac = 0x234, acer, think,};

int main()
{
    int iName = name;
    int iPass = pass;

    int iDay;
    iDay = MON;
    // 隐式转换为int
    iDay = DAY::WED;
    enum DAY myDay;
    myDay = TUE;

    int iClass;
    // 无法隐式转换，必须进行强制转换为int
    iClass = (int)ENUM_CLASS::month;
    iClass = static_cast<int>(ENUM_CLASS::year);
    ENUM_CLASS myClass;
    myClass = ENUM_CLASS::month;
    myClass = ENUM_CLASS::year;

    int iStruct;
    // 无法隐式转换，必须进行强制转换为int
    iStruct = (int)ENUM_STRUCT::acer;
    iStruct = static_cast<int>(ENUM_STRUCT::mac);
    ENUM_STRUCT myStruct;
    myStruct = ENUM_STRUCT::mac;
    myStruct = ENUM_STRUCT::think;

    return 0;
}