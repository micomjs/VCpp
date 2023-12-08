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

// 마우스 커서 모양을 저장할 변수
HCURSOR hCrossCursor;

// DrawingWhiteBox 함수로 생성되는 상자의 좌표
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

    // 네모의 좌표 계산
    int left = 8;          // 왼쪽 마진 8px
    int top = 8;           // 위쪽 마진 8px
    int right = rect.right - 8;   // 오른쪽 마진 8px
    int bottom = rect.bottom - 8; // 아래쪽 마진 8px

    Rectangle(hdc, left, top, right, bottom);
    DeleteObject(hTransparentBrush);
}

void DrawingWhiteBox(HWND hWnd, HDC hdc) {
    // 흰색 상자 그리기
    HBRUSH hWhiteBrush = CreateSolidBrush(RGB(255, 255, 255));
    SelectObject(hdc, hWhiteBrush);

    //RECT rect;
    //  GetClientRect(hWnd, &rect);
    Rectangle(hdc, 16, 82, 768, 424);
    DeleteObject(hWhiteBrush);
}




// 윈도우 프로시저
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

    // 마우스 좌표 가져오기
    int x = LOWORD(lParam);
    int y = HIWORD(lParam);
    int currentX = LOWORD(lParam);
    int currentY = HIWORD(lParam);

    switch (message) {

    case WM_LBUTTONDOWN:
        if (x >= whiteBoxLeft && y <= whiteBoxRight && x >= whiteBoxTop && y <= whiteBoxBottom) {
            // 마우스 왼쪽 버튼을 누르고 DrawingWhiteBox 내부에서 시작
         //   isCircle = true;
            startPoint.x = LOWORD(lParam);
            startPoint.y = HIWORD(lParam);
            endPoint = startPoint;

        }
        InvalidateRect(hWnd, NULL, TRUE);
        //else {
        //    isCircle = false;  // 이 부분을 추가하여 박스 그리기 모드에서 원 그리지 않음
        //}
        break;

        // 윈도우 프로시저 내에서 키보드 이벤트 처리
    case WM_KEYDOWN:
        if (wParam == VK_SPACE) {
            // 스페이스바가 눌렸을 때
            isSpacePressed = true;
            blink = 1;
            InvalidateRect(hWnd, NULL, TRUE);

        }
        break;

    case WM_KEYUP:
        if (wParam == VK_SPACE) {
            // 스페이스바가 떼어졌을 때
            isSpacePressed = false;
            blink = 0;
            InvalidateRect(hWnd, NULL, TRUE);
        }
        break;



        // 윈도우 프로시저 내부에서 마우스 진입 이벤트를 처리
    case WM_MOUSEMOVE: {

        hCrossCursor = LoadCursor(NULL, IDC_CROSS);
        // 마우스가 흰색 상자 안으로 들어갔을 때 커서 모양 변경
        if (x >= whiteBoxLeft && x <= whiteBoxRight && y >= whiteBoxTop && y <= whiteBoxBottom) {
            SetCursor(hCrossCursor);
        }
        else {
            // 마우스가 흰색 상자 밖에 있을 때 기본 커서 모양으로 변경
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


        // 다른 메시지 핸들러 추가

        endPoint.x = LOWORD(lParam);
        endPoint.y = HIWORD(lParam);


        InvalidateRect(hWnd, NULL, TRUE);
        break;

    case WM_COMMAND:
        if (LOWORD(wParam) == 1) {
            // 첫 번째 버튼 클릭
            isBoxVisible = true;
            isCircle = false;
            isBono = false;
            isRyan = false;

            // 초기화
            startPoint = { 0 };
            endPoint = { 0 };
            // 포커스를 윈도우로 변경
            SetFocus(hWnd);
            InvalidateRect(hWnd, NULL, TRUE);
        }
        else if (LOWORD(wParam) == 2) {
            // 두 번째 버튼 클릭
            isBoxVisible = false;
            isCircle = true;
            isBono = false;
            isRyan = false;
            // 초기화
            startPoint = { 0 };
            endPoint = { 0 };
            // 포커스를 윈도우로 변경
            SetFocus(hWnd);
            InvalidateRect(hWnd, NULL, TRUE);
        }
        else if (LOWORD(wParam) == 3) {
            // 세 번째 버튼 클릭
            isBoxVisible = false;
            isCircle = false;
            isRyan = false;
            isBono = true;
            // 초기화
            startPoint = { 0 };
            endPoint = { 0 };
            // 포커스를 윈도우로 변경
            SetFocus(hWnd);
            InvalidateRect(hWnd, NULL, TRUE);
        }
        else if (LOWORD(wParam) == 4) {
            // 네 번째 버튼 클릭
            isBoxVisible = false;
            isCircle = false;
            isBono = false;
            isRyan = true;
            // 초기화
            startPoint = { 0 };
            endPoint = { 0 };
            // 포커스를 윈도우로 변경
            SetFocus(hWnd);
            InvalidateRect(hWnd, NULL, TRUE);
        }
        else if (LOWORD(wParam) == 5) {
            // 다섯 번째 버튼 클릭
            isBoxVisible = false;
            isCircle = false;
            isBono = false;
            isRyan = false;
            // 초기화
            startPoint = { 0 };
            endPoint = { 0 };
            // 포커스를 윈도우로 변경
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
        DrawingWhiteBox(hWnd, hdc);// 새로운 함수 호출

        if (isBono) {
            DrawBonobono(hWnd, hdc, blink);
        }
        if (isRyan)
        {
            RECT rect;
            GetClientRect(hWnd, &rect);

            //// 드래그 중인 상자 그리기

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

            //// 드래그 중인 상자 그리기

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
        // 새로운 박스 그리기
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



// 프로그램 진입점
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
        L"ButtonWindowClass", L"202217043정서연", WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,
        CW_USEDEFAULT, 0, 800, 480, NULL, NULL, hInstance, NULL);

    if (!hWnd) {
        return FALSE;
    }

    int margin = 16; // 마진 값

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

    // 윈도우 생성 및 화면에 표시
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    // 메시지 루프
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // 프로그램 종료
    return (int)msg.wParam;
}


