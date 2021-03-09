#include <stdio.h>

typedef struct{
    float BatteryL;    //Battery status Low.
    float BatteryU;    //Battery status High
    const char* BatteryD;  //Message Display paramter
}IsBatteryStatusInRange;

const char *BatteryMessage[] =
{
    "Not as Expected! ALERT!!!!!!",
    "As Expected"
};

int ChecktemperatureInRange(float temperature);
int ChecksocInRange(float soc);
int CheckchargeRateInRange(float chargeRate);
int batteryIsOk(float temperature, float soc, float chargeRate);

int batteryIsOk(float temperature, float soc, float chargeRate);
void PrintBatterycondition(IsBatteryStatusInRange BatteryData_Type, int BatteryMessageI);

#define BATTERY_CONDITION_GOOD 1
#define BATTERY_CONDITION_BAD 0
