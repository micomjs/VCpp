#include <stdio.h>
#include <conio.h>



int main()
{
    printf("202217043 정서연\n");
    int ch = 0;
    int ch2 = 0;
    while (1)
    {
        printf("command>");
        ch = _getche();  //커맨드 입력


        if (ch == 113) //q입력 시 실행
        {
            ch2 = _getche(); //q다음 값 입력
            if (ch2 == 13) {  // 엔터 입력 시 실행
                printf("\n q:화이팅\n");
            }
            else if (ch2 == 27) { // Esc키 입력 시 실행
                break;
            }
            else {
                ch = _getche(); //엔터나 Esc가 아닌 다른 키 입력 시 실행
            }
        }

        else if (ch == 119) // w입력
        {
            ch2 = _getche();
            if (ch2 == 13) {
                printf("\n w:과제 너무 좋다\n");
            }
            else if (ch2 == 27) {
                break;
            }
            else {
                ch = _getche();
            }
        }

        else if (ch == 101) // e입력
        {
            ch2 = _getche();
            if (ch2 == 13) {
                printf("\n e:담주부턴 과제량 3배다\n");
            }
            else if (ch2 == 27) {
                break;
            }
            else {
                ch = _getche();
            }
        }

        else if (ch == 114)  //r입력
        {
            ch2 = _getche();
            if (ch2 == 13) {
                printf("\n r:행복합니다\n");
            }
            else if (ch2 == 27) {
                break;
            }
            else {
                ch = _getche();
            }
        }

        else if (ch == 27) //Esc키 입력
        {
            break;
        }

        else //위의 키들을 제외한 다른 키 입력 시 실행
        {
            ch2 = _getche();
            if (ch2 == 13) {
                printf("\n다시입력\n");
                continue;
            }
            else if (ch2 == 27) {
                break;
            }
            else {
                ch = _getche();
            }
        }
    }
}
