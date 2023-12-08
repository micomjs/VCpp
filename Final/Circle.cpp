#include "Circle.h"


// 원 그리기 함수
void DrawCircle(HDC hdc, POINT startPoint, POINT endPoint) {

    HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 255));  // 파란색 원
    SelectObject(hdc, hBrush);
    Ellipse(hdc, startPoint.x, startPoint.y, endPoint.x, endPoint.y);
    DeleteObject(hBrush);

}
