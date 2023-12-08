#include "Bonobono.h"
#include "Ryan.h"
#include "Circle.h"
#include "Box.h"

POINT startPoint = { 0 };
POINT endPoint = { 0 };

//bool isBox2Visible = false;
bool isBoxVisible = false;
bool isCircle = false;
bool isBono = false;
bool isSpacePressed = false;
bool isRyan = false;

// ���콺 Ŀ�� ����� ������ ����
HCURSOR hCrossCursor;

// DrawingWhiteBox �Լ��� �����Ǵ� ������ ��ǥ
int whiteBoxLeft = 16;
int whiteBoxTop = 82;
int whiteBoxRight = 768;
int whiteBoxBottom = 424;

int blink = 0;

int xlength = 0, ylength = 0, left = 0, top = 0, right = 0, bottom = 0;


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
        InvalidateRect(hWnd, NULL, TRUE);
        //else {
        //    isCircle = false;  // �� �κ��� �߰��Ͽ� �ڽ� �׸��� ��忡�� �� �׸��� ����
        //}
        break;

        // ������ ���ν��� ������ Ű���� �̺�Ʈ ó��
    case WM_KEYDOWN:
        if (wParam == VK_SPACE) {
            // �����̽��ٰ� ������ ��
            isSpacePressed = true;
            blink = 1;
            InvalidateRect(hWnd, NULL, TRUE);

        }
        break;

    case WM_KEYUP:
        if (wParam == VK_SPACE) {
            // �����̽��ٰ� �������� ��
            isSpacePressed = false;
            blink = 0;
            InvalidateRect(hWnd, NULL, TRUE);
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

        endPoint.x = LOWORD(lParam);
        endPoint.y = HIWORD(lParam);


        InvalidateRect(hWnd, NULL, TRUE);
        break;

    case WM_COMMAND:
        if (LOWORD(wParam) == 1) {
            // ù ��° ��ư Ŭ��
            isBoxVisible = true;
            isCircle = false;
            isBono = false;
            isRyan = false;

            // �ʱ�ȭ
            startPoint = { 0 };
            endPoint = { 0 };
            // ��Ŀ���� ������� ����
            SetFocus(hWnd);
            InvalidateRect(hWnd, NULL, TRUE);
        }
        else if (LOWORD(wParam) == 2) {
            // �� ��° ��ư Ŭ��
            isBoxVisible = false;
            isCircle = true;
            isBono = false;
            isRyan = false;
            // �ʱ�ȭ
            startPoint = { 0 };
            endPoint = { 0 };
            // ��Ŀ���� ������� ����
            SetFocus(hWnd);
            InvalidateRect(hWnd, NULL, TRUE);
        }
        else if (LOWORD(wParam) == 3) {
            // �� ��° ��ư Ŭ��
            isBoxVisible = false;
            isCircle = false;
            isRyan = false;
            isBono = true;
            // �ʱ�ȭ
            startPoint = { 0 };
            endPoint = { 0 };
            // ��Ŀ���� ������� ����
            SetFocus(hWnd);
            InvalidateRect(hWnd, NULL, TRUE);
        }
        else if (LOWORD(wParam) == 4) {
            // �� ��° ��ư Ŭ��
            isBoxVisible = false;
            isCircle = false;
            isBono = false;
            isRyan = true;
            // �ʱ�ȭ
            startPoint = { 0 };
            endPoint = { 0 };
            // ��Ŀ���� ������� ����
            SetFocus(hWnd);
            InvalidateRect(hWnd, NULL, TRUE);
        }
        else if (LOWORD(wParam) == 5) {
            // �ټ� ��° ��ư Ŭ��
            isBoxVisible = false;
            isCircle = false;
            isBono = false;
            isRyan = false;
            // �ʱ�ȭ
            startPoint = { 0 };
            endPoint = { 0 };
            // ��Ŀ���� ������� ����
            SetFocus(hWnd);
            InvalidateRect(hWnd, NULL, TRUE);
        }
        break;
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        RECT rc;
        GetClientRect(hWnd, &rc);


        DrawMarginAndPaddingBox(hWnd, hdc);
        DrawingWhiteBox(hWnd, hdc);// ���ο� �Լ� ȣ��

        if (isBono) {
            DrawBonobono(hWnd, hdc, blink);
        }
        if (isRyan)
        {
            RECT rect;
            GetClientRect(hWnd, &rect);

            //// �巡�� ���� ���� �׸���

            left = min(startPoint.x, endPoint.x);
            top = min(startPoint.y, endPoint.y);
            right = max(startPoint.x, endPoint.x);
            bottom = max(startPoint.y, endPoint.y);

            DrawRyan(hWnd, hdc, left, top, right, bottom);
        }
        if (isCircle) {
            DrawCircle(hdc, startPoint, endPoint);
        }
        if (isBoxVisible) {
            RECT rect;
            GetClientRect(hWnd, &rect);

            //// �巡�� ���� ���� �׸���

            left = min(startPoint.x, endPoint.x);
            top = min(startPoint.y, endPoint.y);
            right = max(startPoint.x, endPoint.x);
            bottom = max(startPoint.y, endPoint.y);

            DrawBox(hWnd, hdc, startPoint, endPoint);
        }
        ReleaseDC(hWnd, hdc);
        EndPaint(hWnd, &ps);
        break;
    }

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


