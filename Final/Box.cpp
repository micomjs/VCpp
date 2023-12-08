#include "Box.h"

// 박스 그리기 함수
void DrawBox(HWND hWnd, HDC hdc, POINT startPoint, POINT endPoint) {

    HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));
    //    RECT rect = { left,top,right,bottom };
    //    FillRect(hdc, &rect, hBrush);
    SelectObject(hdc, hBrush);
    Rectangle(hdc, startPoint.x, startPoint.y, endPoint.x, endPoint.y);
    DeleteObject(hBrush);
    ReleaseDC(hWnd, hdc);


}


