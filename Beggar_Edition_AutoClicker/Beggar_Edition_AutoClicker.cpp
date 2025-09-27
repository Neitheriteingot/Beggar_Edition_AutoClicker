#include <iostream>
#include <windows.h>
bool is_enabled = false; //状态
int delay_time = 499; //默认延迟时间500毫秒
void get_time(int&);

void get_time(int& delay_time_ref) 
{

    int time_temp = 0;
    bool invalid = true;
    while (invalid)
    {
        std::cout << "Enter new delay time (in ms,more than 10ms): ";

        
        if (std::cin >> time_temp) 
        {
            if (time_temp >= 10)
            {
                invalid = false;
                delay_time_ref = time_temp - 1;
                std::cout << "Delay time set to " << time_temp << " ms." << std::endl;
            }
            else
            {
                std::cout << "invalid time!" << std::endl;
            }
        }
        else {
            std::cin.clear();
            std::cin.ignore(65535, '\n');
            std::cout << "Not a number!" << std::endl;
        }

    }    
}

int main()
{
    std::cout << "Press F8 to enable/disable auto clicker. Press F10 to set delay time." << std::endl;

    while (true)
    {
        if (GetAsyncKeyState(VK_F10) && GetForegroundWindow() == GetConsoleWindow())
        {
            get_time(delay_time);
        }

        if (GetAsyncKeyState(VK_F8))
        {
            is_enabled = !is_enabled;

            if (is_enabled)
            {
                std::cout << "Auto clicker enabled." << std::endl;
            }
            else
            {
                std::cout << "Auto clicker disabled." << std::endl;
            }

            while (GetAsyncKeyState(VK_F8)) {
                Sleep(20);
            }
        }

        if (is_enabled)
        {
             mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0); //当前位置点击一次鼠标
             Sleep(delay_time);  
        }

        if (GetAsyncKeyState(VK_ESCAPE) && GetForegroundWindow() == GetConsoleWindow()) 
        {
            return 0;
        }

        Sleep(1);
    }
    return 0;
}