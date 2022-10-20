// code modified from the  source: dzone.com
#include <iostream>

using namespace std;

class Alarm {
  public:
    void alarm_on()  { cout << "Alarm is on" << endl; }
    void alarm_off() { cout << "Alarm is off" << endl; }
};

class Ac {
  public:
    void ac_on()    { cout << "Ac is on" << endl; }
    void ac_off()   { cout << "AC is off" << endl; }
};

class Tv {
  public:
    void tv_on()    { cout << "Tv is on" << endl; }
    void tv_off()   { cout << "TV is off" << endl; }
};

class HouseFacade {
  public:
    void go_to_work() {
        m_ac.ac_off();
        m_tv.tv_off();
        m_alarm.alarm_on();
    }
    void come_home() {
        m_alarm.alarm_off();
        m_ac.ac_on();
        m_tv.tv_on();
    }

    Alarm   m_alarm;
    Ac      m_ac;
    Tv      m_tv;
};

int main() {
    HouseFacade hf;
    // Rather than calling 100 different on and off functions 
    // thanks to facade I only have 2 functions...
    hf.go_to_work();
    hf.come_home();
    return 0;
}

