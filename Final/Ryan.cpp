#include "Ryan.h"

void DrawRyan(HWND hWnd, HDC hdc, int left, int top, int right, int bottom)
{
    double xlength = 0, ylength = 0;

    xlength = right - left;
    ylength = bottom - top;

    //���� ��
    HBRUSH hLeftEarColor = CreateSolidBrush(RGB(255, 200, 15));
    SelectObject(hdc, hLeftEarColor);
    Ellipse(hdc, left, top, left + xlength / 3, top + ylength / 3);
    DeleteObject(hLeftEarColor);

    //������ ��
    HBRUSH hRightEarColor = CreateSolidBrush(RGB(255, 200, 15));
    SelectObject(hdc, hRightEarColor);
    Ellipse(hdc, left + xlength * 2 / 3, top, left + xlength, top + ylength / 3);
    DeleteObject(hRightEarColor);

    //��
    HBRUSH hFaceColor = CreateSolidBrush(RGB(255, 200, 15));
    SelectObject(hdc, hFaceColor);
    Ellipse(hdc, left + xlength / 18, top + ylength / 13, left + xlength / 18 * 17, top + ylength);
    DeleteObject(hFaceColor);

    ////����

     // �� ���� �� ����
    HPEN hPen = CreatePen(PS_SOLID, 5, RGB(0, 0, 0)); // ���� 5, ������
    HPEN hOldPen = (HPEN)SelectObject(hdc, hPen);


    // ���� �׸���
    MoveToEx(hdc, left + xlength * 2 / 9 + 10, top + ylength * 42 / 144, NULL);
    LineTo(hdc, left + xlength * 10 / 27 + 10, top + ylength * 42 / 144);
    MoveToEx(hdc, left + xlength * 10 / 18 + 10, top + ylength * 42 / 144, NULL);
    LineTo(hdc, left + xlength * 13 / 18 + 10, top + ylength * 42 / 144);

    // �� ���� ���� �� ����
    SelectObject(hdc, hOldPen);
    DeleteObject(hPen);

    // �� �׸��� (������)
    SelectObject(hdc, GetStockObject(BLACK_BRUSH));

    // ���� ��
    Ellipse(hdc, left + xlength * 15 / 54 + 10, top + ylength * 27 / 72, left + xlength * 18 / 54 + 10, top + ylength * 31 / 72);

    // ������ ��
    Ellipse(hdc, left + xlength * 32 / 54 + 10, top + ylength * 27 / 72, left + xlength * 35 / 54 + 10, top + ylength * 31 / 72);



    // �� �׸��� (��� ����, ���)
    HBRUSH hMouthColor = CreateSolidBrush(RGB(255, 255, 255));  // ��� ��
    SelectObject(hdc, hMouthColor);
    int mouthLeft = left + xlength * 8 / 20;  // �� ���� �κ�
    int mouthRight = left + xlength / 2;  // �� ������ �κ�
    int mouthTop = top + ylength * 35 / 72;
    int mouthBottom = top + ylength * 42 / 72;
    Ellipse(hdc, mouthLeft, mouthTop, mouthRight, mouthBottom);

    mouthLeft = left + xlength / 2;  // �� ��° ���� ���� �κ�
    mouthRight = left + xlength * 12 / 20;  // �� ��° ���� ������ �κ�
    Ellipse(hdc, mouthLeft, mouthTop, mouthRight, mouthBottom);

    DeleteObject(hMouthColor);

    //�� �׸���
    HBRUSH hNoseColor = CreateSolidBrush(RGB(0, 0, 0));
    SelectObject(hdc, hNoseColor);
    Ellipse(hdc, left + xlength * 37 / 80, top + ylength * 26 / 50, left + xlength * 43 / 80, top + ylength * 34 / 72);
    DeleteObject(hNoseColor);

}