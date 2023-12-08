#include "Bonobono.h"

void DrawBonobono(HWND hWnd, HDC hdc, int blink)
{
    if (blink) {
        //��
        HBRUSH hbBrush = CreateSolidBrush(RGB(127, 200, 255));
        SelectObject(hdc, hbBrush);
        Ellipse(hdc, 300, 200, 500, 400);
        //��
        HBRUSH hb2Brush = CreateSolidBrush(RGB(251, 150, 251));
        SelectObject(hdc, hb2Brush);
        Ellipse(hdc, 385, 300, 415, 350);
        //����
        HBRUSH hb3Brush = CreateSolidBrush(RGB(255, 255, 255));
        SelectObject(hdc, hb3Brush);
        Ellipse(hdc, 370, 290, 400, 317);
        //������
        HBRUSH hb4Brush = CreateSolidBrush(RGB(255, 255, 255));
        SelectObject(hdc, hb4Brush);
        Ellipse(hdc, 400, 290, 430, 317);
        //��
        HBRUSH hb5Brush = CreateSolidBrush(RGB(0, 0, 0));
        SelectObject(hdc, hb5Brush);
        Ellipse(hdc, 388, 280, 412, 300);

        //���� ��
        MoveToEx(hdc, 330, 270, NULL); // ���� ������ ����
        LineTo(hdc, 310, 250); // ���� ���� ����

        MoveToEx(hdc, 330, 270, NULL); // ���� ������ ����
        LineTo(hdc, 310, 290); // ���� ���� ����

        //������ ��
        MoveToEx(hdc, 470, 270, NULL); // ���� ������ ����
        LineTo(hdc, 490, 250); // ���� ���� ����

        MoveToEx(hdc, 470, 270, NULL); // ���� ������ ����
        LineTo(hdc, 490, 290); // ���� ���� ����



        // ���� �׸���
        MoveToEx(hdc, 375, 295, NULL); // ���� ������ ����
        LineTo(hdc, 355, 290); // ���� ���� ����

        // ���� �׸���
        MoveToEx(hdc, 375, 300, NULL); // ���� ������ ����
        LineTo(hdc, 355, 305); // ���� ���� ����

        // ���� �׸���
        MoveToEx(hdc, 420, 295, NULL); // ���� ������ ����
        LineTo(hdc, 440, 290); // ���� ���� ����

        // ���� �׸���
        MoveToEx(hdc, 420, 300, NULL); // ���� ������ ����
        LineTo(hdc, 440, 305); // ���� ���� ����

        DeleteObject(hbBrush);
        DeleteObject(hb2Brush);
        DeleteObject(hb3Brush);
        DeleteObject(hb4Brush);
        DeleteObject(hb5Brush);

    }

    else
    {
        //��
        HBRUSH hBrush = CreateSolidBrush(RGB(127, 200, 255));
        SelectObject(hdc, hBrush);
        Ellipse(hdc, 300, 200, 500, 400);
        //��
        HBRUSH h2Brush = CreateSolidBrush(RGB(251, 150, 251));
        SelectObject(hdc, h2Brush);
        Ellipse(hdc, 385, 300, 415, 350);
        //����
        HBRUSH h3Brush = CreateSolidBrush(RGB(255, 255, 255));
        SelectObject(hdc, h3Brush);
        Ellipse(hdc, 370, 290, 400, 317);
        //������
        HBRUSH h4Brush = CreateSolidBrush(RGB(255, 255, 255));
        SelectObject(hdc, h4Brush);
        Ellipse(hdc, 400, 290, 430, 317);
        //��
        HBRUSH h5Brush = CreateSolidBrush(RGB(0, 0, 0));
        SelectObject(hdc, h5Brush);
        Ellipse(hdc, 388, 280, 412, 300);
        //���� ��
        HBRUSH h6Brush = CreateSolidBrush(RGB(0, 0, 0));
        SelectObject(hdc, h6Brush);
        Ellipse(hdc, 315, 270, 320, 280);
        //������ ��
        HBRUSH h7Brush = CreateSolidBrush(RGB(0, 0, 0));
        SelectObject(hdc, h6Brush);
        Ellipse(hdc, 485, 270, 490, 280);

        // ���� �׸���
        MoveToEx(hdc, 375, 295, NULL); // ���� ������ ����
        LineTo(hdc, 355, 290); // ���� ���� ����

        // ���� �׸���
        MoveToEx(hdc, 375, 300, NULL); // ���� ������ ����
        LineTo(hdc, 355, 305); // ���� ���� ����

        // ���� �׸���
        MoveToEx(hdc, 420, 295, NULL); // ���� ������ ����
        LineTo(hdc, 440, 290); // ���� ���� ����

        // ���� �׸���
        MoveToEx(hdc, 420, 300, NULL); // ���� ������ ����
        LineTo(hdc, 440, 305); // ���� ���� ����

        DeleteObject(hBrush);
        DeleteObject(h2Brush);
        DeleteObject(h3Brush);
        DeleteObject(h4Brush);
        DeleteObject(h5Brush);
        DeleteObject(h6Brush);
        DeleteObject(h7Brush);
    }
}



