#include <stdio.h>

typedef struct{
    float BatteryL;
    float BatteryU;
    const char* BatteryD;
}BatteryStatus;

const char *BatteryMessage[] =
{
    "Not as Expected! ALERT!!!!!!",
    "As Expected"
};

int ChecktemperatureInRange(float temperature);
int ChecksocInRange(float soc);
int CheckchargeRateInRange(float chargeRate);
int batteryIsOk(float temperature, float soc, float chargeRate);
void PrintBatterycondition(BatteryStatus BatteryData_Type, int BatteryMessageI);

#define BATTERY_CONDITION_GOOD 1
#define BATTERY_CONDITION_BAD 0
