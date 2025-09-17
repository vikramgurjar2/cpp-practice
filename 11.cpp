#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void task1()
{
    for (int i = 0; i < 5; i++)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        cout << "Task 1 is running\n";
    }
}
void task2()
{
    for (int i = 0; i < 5; i++)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        cout << "Task 2 is running\n";
    }
}
void task3()
{
    for (int i = 0; i < 5; i++)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        cout << "Task 3 is running\n";
    }
}

int main()
{
    std::thread t1(task1);
    std::thread t2(task2);
    std::thread t3(task3);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
