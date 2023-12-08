#include "Circle.h"


// �� �׸��� �Լ�
void DrawCircle(HDC hdc, POINT startPoint, POINT endPoint) {

    HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 255));  // �Ķ��� ��
    SelectObject(hdc, hBrush);
    Ellipse(hdc, startPoint.x, startPoint.y, endPoint.x, endPoint.y);
    DeleteObject(hBrush);

}
