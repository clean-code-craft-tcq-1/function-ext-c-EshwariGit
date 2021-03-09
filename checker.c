#include <stdio.h>
#include <assert.h>
#include "checker.h"


IsBatteryStatusInRange TemparatureValue = {
        0.0,
        45.0,
        "Temparature"
};
IsBatteryStatusInRange SocValue = {
        20.0,
        80.0,
        "StateOfCharge"
};
IsBatteryStatusInRange ChargeRateValue = {
        0.0,
        0.8,
        "ChargeRate"
};

IsBatteryStatusInRange Stateofhealth = {
        0.5,
        1,
        "StateOfHealth"
};


int ChecktemperatureInRange(float temperature) {

    int istemperatureinrange = BATTERY_CONDITION_GOOD;
    if (temperature<TemparatureValue.BatteryL|| temperature>TemparatureValue.BatteryU)
    {
        istemperatureinrange = BATTERY_CONDITION_BAD;
    }
    PrintBatterycondition(TemparatureValue,istemperatureinrange );
    return istemperatureinrange;
}

int CheckStateofHealthInRange(float stateofhealth) {

    int isstateofhealthinrange = BATTERY_CONDITION_GOOD;
    if (stateofhealth<Stateofhealth.BatteryL|| stateofhealth>Stateofhealth.BatteryU)
    {
        isstateofhealthinrange = BATTERY_CONDITION_BAD;
    }
    PrintBatterycondition(Stateofhealth,isstateofhealthinrange );
    return isstateofhealthinrange;
}

int ChecksocInRange(float soc){
    int issocinrange = BATTERY_CONDITION_GOOD;
    if(soc<SocValue.BatteryL || soc>SocValue.BatteryU )
    {
        issocinrange = BATTERY_CONDITION_BAD;
    }
    PrintBatterycondition(SocValue,issocinrange);
    return issocinrange;
}


int CheckchargeRateInRange(float chargeRate){
    int ischargerateinrange = BATTERY_CONDITION_GOOD;
    if(chargeRate<ChargeRateValue.BatteryL || chargeRate>ChargeRateValue.BatteryU )
    {
        ischargerateinrange = BATTERY_CONDITION_BAD;
    }

    PrintBatterycondition(ChargeRateValue,ischargerateinrange );
    return ischargerateinrange;
}



void PrintBatterycondition(IsBatteryStatusInRange BatteryData_Type, int BatteryMessageI)
{
    printf("%s %s \n", BatteryData_Type.BatteryD, BatteryMessage[BatteryMessageI]);
}

int batteryIsOk(float temperature, float soc, float chargeRate, float stateofhealth) {
    int CompleteParamstatus;
    CompleteParamstatus = (ChecktemperatureInRange(temperature)) & (ChecksocInRange(soc)) & (CheckchargeRateInRange(chargeRate)) & (CheckStateofHealthInRange(stateofhealth));
    return (CompleteParamstatus);
}

int main() {
  assert(batteryIsOk(25, 70, 0.7, 0.5));
  assert(!batteryIsOk(50, 85, 0, 1));
    
}
