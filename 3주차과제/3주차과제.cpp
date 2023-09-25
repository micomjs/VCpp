#include <iostream>
#include <conio.h>
#include <chrono>
int main() {
    std::cout << "키보드 입력" << std::endl;
    while (!_kbhit()); // 입력을 받으면 실행

    std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();
    std::chrono::milliseconds inputTime(0);
    std::cout << "입력을 시작합니다. 종료하려면 ESC 키를 누르세요." << std::endl;

    while (inputTime.count() < 1000) { //1초 동안 입력받음
        if (_kbhit()) {
            char input = _getch(); // 키보드 입력을 받음

            if (input == 27) { // ESC 키를 누르면 종료
                break;
            }

            if (input == 72) {
                std::cout << "(^-^)" << std::endl;
            }


            std::cout << input; // 입력받은 내용 출력
        }
        auto currentTime = std::chrono::steady_clock::now();
        inputTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime);
    }

    std::cout << "\n프로그램을 종료합니다." << std::endl;

    return 0;
}
