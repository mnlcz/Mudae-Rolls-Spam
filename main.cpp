#include <iostream>
#include <windows.h>

void Spam();

int main()
{
    Spam();
    return 0;
}

void Spam()
{
    Sleep(3000);
    if(GetAsyncKeyState(VK_MBUTTON))
    {
        for(int i = 0; i < 20; i++)
        {
            INPUT input[10];
            input[0].type = INPUT_KEYBOARD;
            input[1].type = INPUT_KEYBOARD;
            input[2].type = INPUT_KEYBOARD;
            input[3].type = INPUT_KEYBOARD;


            input[0].ki.wVk = VK_SHIFT;
            input[1].ki.wVk = 0x34;     // 4
            input[2].ki.wVk = 0x4D;     // m
            input[3].ki.wVk = 0x42;     // b


            input[4] = input[1];
            input[5] = input[0];
            input[6] = input[2];
            input[7] = input[3];

            input[4].ki.dwFlags = KEYEVENTF_KEYUP;
            input[5].ki.dwFlags = KEYEVENTF_KEYUP;
            input[6].ki.dwFlags = KEYEVENTF_KEYUP;
            input[7].ki.dwFlags = KEYEVENTF_KEYUP;


            // La VK correspondiente al enter se asigna luego de asignar tanto el valor como las flags del input previo.
            input[8].type = INPUT_KEYBOARD;
            input[8].ki.wVk = VK_RETURN;

            input[9] = input[8];
            input[9].ki.dwFlags = KEYEVENTF_KEYUP;
            SendInput(10, input, sizeof(input[0]));
            Sleep(200);

        }
    }
}
