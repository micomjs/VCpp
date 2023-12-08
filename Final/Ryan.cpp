#include "Ryan.h"

void DrawRyan(HWND hWnd, HDC hdc, int left, int top, int right, int bottom)
{
    double xlength = 0, ylength = 0;

    xlength = right - left;
    ylength = bottom - top;

    //왼쪽 귀
    HBRUSH hLeftEarColor = CreateSolidBrush(RGB(255, 200, 15));
    SelectObject(hdc, hLeftEarColor);
    Ellipse(hdc, left, top, left + xlength / 3, top + ylength / 3);
    DeleteObject(hLeftEarColor);

    //오른쪽 귀
    HBRUSH hRightEarColor = CreateSolidBrush(RGB(255, 200, 15));
    SelectObject(hdc, hRightEarColor);
    Ellipse(hdc, left + xlength * 2 / 3, top, left + xlength, top + ylength / 3);
    DeleteObject(hRightEarColor);

    //얼굴
    HBRUSH hFaceColor = CreateSolidBrush(RGB(255, 200, 15));
    SelectObject(hdc, hFaceColor);
    Ellipse(hdc, left + xlength / 18, top + ylength / 13, left + xlength / 18 * 17, top + ylength);
    DeleteObject(hFaceColor);

    ////눈썹

     // 펜 생성 및 선택
    HPEN hPen = CreatePen(PS_SOLID, 5, RGB(0, 0, 0)); // 굵기 5, 빨간색
    HPEN hOldPen = (HPEN)SelectObject(hdc, hPen);


    // 눈썹 그리기
    MoveToEx(hdc, left + xlength * 2 / 9 + 10, top + ylength * 42 / 144, NULL);
    LineTo(hdc, left + xlength * 10 / 27 + 10, top + ylength * 42 / 144);
    MoveToEx(hdc, left + xlength * 10 / 18 + 10, top + ylength * 42 / 144, NULL);
    LineTo(hdc, left + xlength * 13 / 18 + 10, top + ylength * 42 / 144);

    // 펜 선택 해제 및 삭제
    SelectObject(hdc, hOldPen);
    DeleteObject(hPen);

    // 눈 그리기 (검정색)
    SelectObject(hdc, GetStockObject(BLACK_BRUSH));

    // 왼쪽 눈
    Ellipse(hdc, left + xlength * 15 / 54 + 10, top + ylength * 27 / 72, left + xlength * 18 / 54 + 10, top + ylength * 31 / 72);

    // 오른쪽 눈
    Ellipse(hdc, left + xlength * 32 / 54 + 10, top + ylength * 27 / 72, left + xlength * 35 / 54 + 10, top + ylength * 31 / 72);



    // 입 그리기 (가운데 정렬, 흰색)
    HBRUSH hMouthColor = CreateSolidBrush(RGB(255, 255, 255));  // 흰색 입
    SelectObject(hdc, hMouthColor);
    int mouthLeft = left + xlength * 8 / 20;  // 입 왼쪽 부분
    int mouthRight = left + xlength / 2;  // 입 오른쪽 부분
    int mouthTop = top + ylength * 35 / 72;
    int mouthBottom = top + ylength * 42 / 72;
    Ellipse(hdc, mouthLeft, mouthTop, mouthRight, mouthBottom);

    mouthLeft = left + xlength / 2;  // 두 번째 원의 왼쪽 부분
    mouthRight = left + xlength * 12 / 20;  // 두 번째 원의 오른쪽 부분
    Ellipse(hdc, mouthLeft, mouthTop, mouthRight, mouthBottom);

    DeleteObject(hMouthColor);

    //코 그리기
    HBRUSH hNoseColor = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hNoseColor);
    Ellipse(hdc, left + xlength * 37 / 80, top + ylength * 26 / 50, left + xlength * 43 / 80, top + ylength * 34 / 72);
    DeleteObject(hNoseColor);

}