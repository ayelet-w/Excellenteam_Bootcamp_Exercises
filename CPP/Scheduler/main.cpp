#include <iostream>
#include "Schedulr.h"
#include "Task_hello_world.h"
#include "Task_five_sec.h"
int main() {
    Schedulr s;
    Task_hello_word taskHelloWord(3,5);
    Task_five_sec taskFiveSec(2);
    s.insert_task(&taskHelloWord);
    s.insert_task(&taskFiveSec);
    s.run_tasks();
    return 0;
}
