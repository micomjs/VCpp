#include "Bonobono.h"

void DrawBonobono(HWND hWnd, HDC hdc, int blink)
{
    if (blink) {
        //얼굴
        HBRUSH hbBrush = CreateSolidBrush(RGB(127, 200, 255));
        SelectObject(hdc, hbBrush);
        Ellipse(hdc, 300, 200, 500, 400);
        //입
        HBRUSH hb2Brush = CreateSolidBrush(RGB(251, 150, 251));
        SelectObject(hdc, hb2Brush);
        Ellipse(hdc, 385, 300, 415, 350);
        //왼쪽
        HBRUSH hb3Brush = CreateSolidBrush(RGB(255, 255, 255));
        SelectObject(hdc, hb3Brush);
        Ellipse(hdc, 370, 290, 400, 317);
        //오른쪽
        HBRUSH hb4Brush = CreateSolidBrush(RGB(255, 255, 255));
        SelectObject(hdc, hb4Brush);
        Ellipse(hdc, 400, 290, 430, 317);
        //코
        HBRUSH hb5Brush = CreateSolidBrush(RGB(0, 0, 0));
        SelectObject(hdc, hb5Brush);
        Ellipse(hdc, 388, 280, 412, 300);

        //왼쪽 눈
        MoveToEx(hdc, 330, 270, NULL); // 직선 시작점 설정
        LineTo(hdc, 310, 250); // 직선 끝점 설정

        MoveToEx(hdc, 330, 270, NULL); // 직선 시작점 설정
        LineTo(hdc, 310, 290); // 직선 끝점 설정

        //오른쪽 눈
        MoveToEx(hdc, 470, 270, NULL); // 직선 시작점 설정
        LineTo(hdc, 490, 250); // 직선 끝점 설정

        MoveToEx(hdc, 470, 270, NULL); // 직선 시작점 설정
        LineTo(hdc, 490, 290); // 직선 끝점 설정



        // 직선 그리기
        MoveToEx(hdc, 375, 295, NULL); // 직선 시작점 설정
        LineTo(hdc, 355, 290); // 직선 끝점 설정

        // 직선 그리기
        MoveToEx(hdc, 375, 300, NULL); // 직선 시작점 설정
        LineTo(hdc, 355, 305); // 직선 끝점 설정

        // 직선 그리기
        MoveToEx(hdc, 420, 295, NULL); // 직선 시작점 설정
        LineTo(hdc, 440, 290); // 직선 끝점 설정

        // 직선 그리기
        MoveToEx(hdc, 420, 300, NULL); // 직선 시작점 설정
        LineTo(hdc, 440, 305); // 직선 끝점 설정

        DeleteObject(hbBrush);
        DeleteObject(hb2Brush);
        DeleteObject(hb3Brush);
        DeleteObject(hb4Brush);
        DeleteObject(hb5Brush);

    }

    else
    {
        //얼굴
        HBRUSH hBrush = CreateSolidBrush(RGB(127, 200, 255));
        SelectObject(hdc, hBrush);
        Ellipse(hdc, 300, 200, 500, 400);
        //입
        HBRUSH h2Brush = CreateSolidBrush(RGB(251, 150, 251));
        SelectObject(hdc, h2Brush);
        Ellipse(hdc, 385, 300, 415, 350);
        //왼쪽
        HBRUSH h3Brush = CreateSolidBrush(RGB(255, 255, 255));
        SelectObject(hdc, h3Brush);
        Ellipse(hdc, 370, 290, 400, 317);
        //오른쪽
        HBRUSH h4Brush = CreateSolidBrush(RGB(255, 255, 255));
        SelectObject(hdc, h4Brush);
        Ellipse(hdc, 400, 290, 430, 317);
        //코
        HBRUSH h5Brush = CreateSolidBrush(RGB(0, 0, 0));
        SelectObject(hdc, h5Brush);
        Ellipse(hdc, 388, 280, 412, 300);
        //왼쪽 눈
        HBRUSH h6Brush = CreateSolidBrush(RGB(0, 0, 0));
        SelectObject(hdc, h6Brush);
        Ellipse(hdc, 315, 270, 320, 280);
        //오른쪽 눈
        HBRUSH h7Brush = CreateSolidBrush(RGB(0, 0, 0));
        SelectObject(hdc, h6Brush);
        Ellipse(hdc, 485, 270, 490, 280);

        // 직선 그리기
        MoveToEx(hdc, 375, 295, NULL); // 직선 시작점 설정
        LineTo(hdc, 355, 290); // 직선 끝점 설정

        // 직선 그리기
        MoveToEx(hdc, 375, 300, NULL); // 직선 시작점 설정
        LineTo(hdc, 355, 305); // 직선 끝점 설정

        // 직선 그리기
        MoveToEx(hdc, 420, 295, NULL); // 직선 시작점 설정
        LineTo(hdc, 440, 290); // 직선 끝점 설정

        // 직선 그리기
        MoveToEx(hdc, 420, 300, NULL); // 직선 시작점 설정
        LineTo(hdc, 440, 305); // 직선 끝점 설정

        DeleteObject(hBrush);
        DeleteObject(h2Brush);
        DeleteObject(h3Brush);
        DeleteObject(h4Brush);
        DeleteObject(h5Brush);
        DeleteObject(h6Brush);
        DeleteObject(h7Brush);
    }
}



