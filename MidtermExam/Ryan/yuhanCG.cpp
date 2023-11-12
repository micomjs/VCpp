#include "yuhanCG.h"


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

    //����
    SelectObject(hdc, GetStockObject(BLACK_PEN));

    // ���� �� ���μ� �׸���
    MoveToEx(hdc, left + xlength * 2 / 9 + 10, top + ylength * 40 / 144, NULL);
    LineTo(hdc, left + xlength * 10 / 27 + 10, top + ylength * 40 / 144);
    MoveToEx(hdc, left + xlength * 10 / 18 + 10, top + ylength * 40 / 144, NULL);
    LineTo(hdc, left + xlength * 13 / 18 + 10, top + ylength * 40 / 144);

    // ���� �� ���μ� �׸���
    MoveToEx(hdc, left + xlength * 2 / 9 + 10, top + ylength * 41 / 144, NULL);
    LineTo(hdc, left + xlength * 10 / 27 + 10, top + ylength * 41 / 144);
    MoveToEx(hdc, left + xlength * 10 / 18 + 10, top + ylength * 41 / 144, NULL);
    LineTo(hdc, left + xlength * 13 / 18 + 10, top + ylength * 41 / 144);

    // ���� �� �� �κ� �׸���
    MoveToEx(hdc, left + xlength * 2 / 9 + 10, top + ylength * 42 / 144, NULL);
    LineTo(hdc, left + xlength * 10 / 27 + 10, top + ylength * 42 / 144);
    MoveToEx(hdc, left + xlength * 10 / 18 + 10, top + ylength * 42 / 144, NULL);
    LineTo(hdc, left + xlength * 13 / 18 + 10, top + ylength * 42 / 144);

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
}
