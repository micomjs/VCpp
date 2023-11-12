#include <windows.h>
#include <stdbool.h>

POINT startPoint;
POINT endPoint;

bool isBox2Visible = false;
bool isBoxVisible = false;
bool isCircle = false;
bool isBono = false;
bool isBono2 = false;
bool isSpacePressed = false;

// ���콺 Ŀ�� ����� ������ ����
HCURSOR hCrossCursor;

// DrawingWhiteBox �Լ��� �����Ǵ� ������ ��ǥ
int whiteBoxLeft = 16;
int whiteBoxTop = 82;
int whiteBoxRight = 768;
int whiteBoxBottom = 424;


//���뺸��
void DrawBonobono(HWND hWnd, HDC hdc) {
    if (isBono) {
        //��
        HBRUSH hBrush = CreateSolidBrush(RGB(127, 200, 255));
        SelectObject(hdc, hBrush);
        Ellipse(hdc, 300, 200, 500, 400);
        //��
        HBRUSH h2Brush = CreateSolidBrush(RGB(255, 150, 255));
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


//���뺸��2 ><
void DrawBonobono2(HWND hWnd, HDC hdc) {
    if (isBono2) {
        //��
        HBRUSH hbBrush = CreateSolidBrush(RGB(127, 200, 255));
        SelectObject(hdc, hbBrush);
        Ellipse(hdc, 300, 200, 500, 400);
        //��
        HBRUSH hb2Brush = CreateSolidBrush(RGB(255, 150, 255));
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
}

// �ڽ� �׸��� �Լ�
void DrawBox2(HWND hWnd, HDC hdc) {
    RECT rect;
    GetClientRect(hWnd, &rect);

    if (isBox2Visible) {
        // �ڽ� �׸���
        HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0)); // ������ �ڽ�
        SelectObject(hdc, hBrush);
        //  Rectangle(hdc, 300, 50, 500, 200);
        DeleteObject(hBrush);
    }
}

// �� �׸��� �Լ�
void DrawCircle(HDC hdc, POINT startPoint, POINT endPoint) {
    if (isCircle) {
        HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 255));  // �Ķ��� ��
        SelectObject(hdc, hBrush);
        Ellipse(hdc, startPoint.x, startPoint.y, endPoint.x, endPoint.y);
        DeleteObject(hBrush);
    }
}


void DrawMarginAndPaddingBox(HWND hWnd, HDC hdc) {
    RECT rect;
    GetClientRect(hWnd, &rect);

    HBRUSH hTransparentBrush = CreateSolidBrush(RGB(255, 240, 200));
    SelectObject(hdc, hTransparentBrush);

    // �׸��� ��ǥ ���
    int left = 8;          // ���� ���� 8px
    int top = 8;           // ���� ���� 8px
    int right = rect.right - 8;   // ������ ���� 8px
    int bottom = rect.bottom - 8; // �Ʒ��� ���� 8px

    Rectangle(hdc, left, top, right, bottom);
    DeleteObject(hTransparentBrush);
}

void DrawingWhiteBox(HWND hWnd, HDC hdc) {
    // ��� ���� �׸���
    HBRUSH hWhiteBrush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hWhiteBrush);

    //RECT rect;
    //  GetClientRect(hWnd, &rect);
    Rectangle(hdc, 16, 82, 768, 424);
    DeleteObject(hWhiteBrush);
}




// ������ ���ν���
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

    // ���콺 ��ǥ ��������
    int x = LOWORD(lParam);
    int y = HIWORD(lParam);
    int currentX = LOWORD(lParam);
    int currentY = HIWORD(lParam);

    switch (message) {

    case WM_LBUTTONDOWN:
        if (x >= whiteBoxLeft && y <= whiteBoxRight && x >= whiteBoxTop && y <= whiteBoxBottom) {
            // ���콺 ���� ��ư�� ������ DrawingWhiteBox ���ο��� ����
         //   isCircle = true;
            startPoint.x = LOWORD(lParam);
            startPoint.y = HIWORD(lParam);
            endPoint = startPoint;
        }
        else {
            isCircle = false;  // �� �κ��� �߰��Ͽ� �ڽ� �׸��� ��忡�� �� �׸��� ����
        }
        break;

        // ������ ���ν��� ������ Ű���� �̺�Ʈ ó��
    case WM_KEYDOWN:
        if (wParam == VK_SPACE) {
            // �����̽��ٰ� ������ ��
            isSpacePressed = true;
            if (isBono) {
                isBono2 = true;
                InvalidateRect(hWnd, NULL, TRUE);
            }
        }
        break;

    case WM_KEYUP:
        if (wParam == VK_SPACE) {
            // �����̽��ٰ� �������� ��
            isSpacePressed = false;
            if (isBono2) {
                isBono2 = false;
                isBono = true;
                InvalidateRect(hWnd, NULL, TRUE);
              }
            }
        break;



        // ������ ���ν��� ���ο��� ���콺 ���� �̺�Ʈ�� ó��
    case WM_MOUSEMOVE: {

        hCrossCursor = LoadCursor(NULL, IDC_CROSS);
        // ���콺�� ��� ���� ������ ���� �� Ŀ�� ��� ����
        if (x >= whiteBoxLeft && x <= whiteBoxRight && y >= whiteBoxTop && y <= whiteBoxBottom) {
            SetCursor(hCrossCursor);
        }
        else {
            // ���콺�� ��� ���� �ۿ� ���� �� �⺻ Ŀ�� ������� ����
            SetCursor(LoadCursor(NULL, IDC_ARROW));
        }


        if (wParam & MK_LBUTTON) {
            endPoint.x = LOWORD(lParam);
            endPoint.y = HIWORD(lParam);
            InvalidateRect(hWnd, NULL, TRUE);
        }
        break;
    }

    case WM_LBUTTONUP:


        // �ٸ� �޽��� �ڵ鷯 �߰�

       // endPoint.x = LOWORD(lParam);
      //  endPoint.y = HIWORD(lParam);

        if (isBox2Visible) {
            HDC hdc = GetDC(hWnd);
            HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0)); // ������ �ڽ�
            SelectObject(hdc, hBrush);
            Rectangle(hdc, startPoint.x, startPoint.y, endPoint.x, endPoint.y);
            DeleteObject(hBrush);
            ReleaseDC(hWnd, hdc);
        }

        if (isCircle) {
            isCircle = false; // ���콺 ���� ��ư�� ���� �� �׸��� ����
            HDC hdc = GetDC(hWnd);
            HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));
            SelectObject(hdc, hBrush);
            DrawCircle(hdc, startPoint, endPoint);
            ReleaseDC(hWnd, hdc);
            DeleteObject(hBrush);
        }
        break;

    case WM_COMMAND:
        if (LOWORD(wParam) == 1) {
            // ù ��° ��ư Ŭ��
            isBox2Visible = true;
            isCircle = false;
            isBono = false;
            isBono2 = false;
            // ��Ŀ���� ������� ����
            SetFocus(hWnd);
            InvalidateRect(hWnd, NULL, TRUE);
        }
        else if (LOWORD(wParam) == 2) {
            // �� ��° ��ư Ŭ��
            isBox2Visible = false;
            isCircle = true;
            isBono = false;
            isBono2 = false;
            // ��Ŀ���� ������� ����
            SetFocus(hWnd);
            InvalidateRect(hWnd, NULL, TRUE);
        }
        else if (LOWORD(wParam) == 3) {
            // �� ��° ��ư Ŭ��
            isBox2Visible = false;
            isCircle = false;
            // ��Ŀ���� ������� ����
            SetFocus(hWnd);
            // isBono = true;

            if (isSpacePressed) {
                // �����̽��ٰ� ������ ��

                isBono2 = true;
                isBono = false;
                InvalidateRect(hWnd, NULL, TRUE);
            }
            else {
                isBono = true;
            }

            InvalidateRect(hWnd, NULL, TRUE);
        }
        else if (LOWORD(wParam) == 4) {
            // �� ��° ��ư Ŭ��
            isBox2Visible = false;
            isCircle = false;
            isBono = false;
            isBono2 = false;
            // ��Ŀ���� ������� ����
            SetFocus(hWnd);
            InvalidateRect(hWnd, NULL, TRUE);
        }
        else if (LOWORD(wParam) == 5) {
            // �ټ� ��° ��ư Ŭ��
            isBox2Visible = false;
            isCircle = false;
            isBono = false;
            isBono2 = false;
            // ��Ŀ���� ������� ����
            SetFocus(hWnd);
            InvalidateRect(hWnd, NULL, TRUE);
        }
        break;
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        DrawMarginAndPaddingBox(hWnd, hdc);
        DrawingWhiteBox(hWnd, hdc);// ���ο� �Լ� ȣ��
        DrawBox2(hWnd, hdc);
        DrawCircle(hdc, startPoint, endPoint);
        DrawBonobono(hWnd, hdc);
        DrawBonobono2(hWnd, hdc);

        EndPaint(hWnd, &ps);
        break;
    }
                 // WM_CREATE �޽��� �ڵ鷯
    case WM_CREATE: {
        // ���ο� �ڽ� �׸���
        HDC hdc = GetDC(hWnd);
        DrawMarginAndPaddingBox(hWnd, hdc);
        ReleaseDC(hWnd, hdc);
        break;
    }

    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;


}



// ���α׷� ������
int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow) {

    HWND hWnd;
    HWND hButton1, hButton2, hButton3, hButton4, hButton5;

    WNDCLASSEX wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = CreateSolidBrush(RGB(255, 240, 200));
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = L"ButtonWindowClass";
    wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

    if (!RegisterClassEx(&wcex)) {
        return 1;
    }

    hWnd = CreateWindow(
        L"ButtonWindowClass", L"202217043������", WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,
        CW_USEDEFAULT, 0, 800, 480, NULL, NULL, hInstance, NULL);

    if (!hWnd) {
        return FALSE;
    }

    int margin = 16; // ���� ��

    hButton1 = CreateWindow(
        L"BUTTON", L"Box", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        margin, 20, 137, 50, hWnd, (HMENU)1, hInstance, NULL);

    hButton2 = CreateWindow(
        L"BUTTON", L"Circle", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        margin * 2 + 137, 20, 137, 50, hWnd, (HMENU)2, hInstance, NULL);

    hButton3 = CreateWindow(
        L"BUTTON", L"Bonobono", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        margin + (137 + margin) * 2, 20, 137, 50, hWnd, (HMENU)3, hInstance, NULL);

    hButton4 = CreateWindow(
        L"BUTTON", L"Ryan", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        margin + (137 + margin) * 3, 20, 137, 50, hWnd, (HMENU)4, hInstance, NULL);

    hButton5 = CreateWindow(
        L"BUTTON", L"Cube", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        margin + (137 + margin) * 4, 20, 137, 50, hWnd, (HMENU)5, hInstance, NULL);

    // ������ ���� �� ȭ�鿡 ǥ��
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);
    
    // �޽��� ����
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // ���α׷� ����
    return (int)msg.wParam;
}
