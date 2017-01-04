//#include <windows.h>
//#include <chrono>
#include "Instruction.h"

//inline bool isKeyDown(int virtualCode);
//void keyEvent();

int main()
{
    Insruction i;
    i.InsructionProcess();

    //thread t1(keyEvent);

    return 0;
}
/*
inline bool isKeyDown(int virtualCode){
    return (GetKeyState(virtualCode) && HIGH_ORDER_BIT);
}

void keyEvent(){
    int ret;

    while(1){
        if(isKeyDown(VK_CONTROL)){
            if(isKeyDown(VK_Z)){
                cout << "Ctrl + Z" << endl;
            }
        }
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}*/

