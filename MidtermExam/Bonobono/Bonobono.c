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

// 마우스 커서 모양을 저장할 변수
HCURSOR hCrossCursor;

// DrawingWhiteBox 함수로 생성되는 상자의 좌표
int whiteBoxLeft = 16;
int whiteBoxTop = 82;
int whiteBoxRight = 768;
int whiteBoxBottom = 424;


//보노보노
void DrawBonobono(HWND hWnd, HDC hdc) {
    if (isBono) {
        //얼굴
        HBRUSH hBrush = CreateSolidBrush(RGB(127, 200, 255));
        SelectObject(hdc, hBrush);
        Ellipse(hdc, 300, 200, 500, 400);
        //입
        HBRUSH h2Brush = CreateSolidBrush(RGB(255, 150, 255));
        SelectObject(hdc, h2Brush);
        Ellipse(hdc, 385, 300, 415, 350);
        //왼쪽
        HBRUSH h3Brush = CreateSolidBrush(RGB(255, 255, 255));
        SelectObject(hdc, h3Brush);
        Ellipse(hdc, 370, 290, 400, 317);
        //오른쪽
        HBRUSH h4Brush = CreateSolidBrush(RGB(255, 255, 255));
        SelectObject(hdc, h4Brush);
        Ellipse(hdc, 400, 290, 430, 317);
        //코
        HBRUSH h5Brush = CreateSolidBrush(RGB(0, 0, 0));
        SelectObject(hdc, h5Brush);
        Ellipse(hdc, 388, 280, 412, 300);
        //왼쪽 눈
        HBRUSH h6Brush = CreateSolidBrush(RGB(0, 0, 0));
        SelectObject(hdc, h6Brush);
        Ellipse(hdc, 315, 270, 320, 280);
        //오른쪽 눈
        HBRUSH h7Brush = CreateSolidBrush(RGB(0, 0, 0));
        SelectObject(hdc, h6Brush);
        Ellipse(hdc, 485, 270, 490, 280);

        // 직선 그리기
        MoveToEx(hdc, 375, 295, NULL); // 직선 시작점 설정
        LineTo(hdc, 355, 290); // 직선 끝점 설정

        // 직선 그리기
        MoveToEx(hdc, 375, 300, NULL); // 직선 시작점 설정
        LineTo(hdc, 355, 305); // 직선 끝점 설정

        // 직선 그리기
        MoveToEx(hdc, 420, 295, NULL); // 직선 시작점 설정
        LineTo(hdc, 440, 290); // 직선 끝점 설정

        // 직선 그리기
        MoveToEx(hdc, 420, 300, NULL); // 직선 시작점 설정
        LineTo(hdc, 440, 305); // 직선 끝점 설정

        DeleteObject(hBrush);
        DeleteObject(h2Brush);
        DeleteObject(h3Brush);
        DeleteObject(h4Brush);
        DeleteObject(h5Brush);
        DeleteObject(h6Brush);
        DeleteObject(h7Brush);
    }
}


//보노보노2 ><
void DrawBonobono2(HWND hWnd, HDC hdc) {
    if (isBono2) {
        //얼굴
        HBRUSH hbBrush = CreateSolidBrush(RGB(127, 200, 255));
        SelectObject(hdc, hbBrush);
        Ellipse(hdc, 300, 200, 500, 400);
        //입
        HBRUSH hb2Brush = CreateSolidBrush(RGB(255, 150, 255));
        SelectObject(hdc, hb2Brush);
        Ellipse(hdc, 385, 300, 415, 350);
        //왼쪽
        HBRUSH hb3Brush = CreateSolidBrush(RGB(255, 255, 255));
        SelectObject(hdc, hb3Brush);
        Ellipse(hdc, 370, 290, 400, 317);
        //오른쪽
        HBRUSH hb4Brush = CreateSolidBrush(RGB(255, 255, 255));
        SelectObject(hdc, hb4Brush);
        Ellipse(hdc, 400, 290, 430, 317);
        //코
        HBRUSH hb5Brush = CreateSolidBrush(RGB(0, 0, 0));
        SelectObject(hdc, hb5Brush);
        Ellipse(hdc, 388, 280, 412, 300);

        //왼쪽 눈
        MoveToEx(hdc, 330, 270, NULL); // 직선 시작점 설정
        LineTo(hdc, 310, 250); // 직선 끝점 설정

        MoveToEx(hdc, 330, 270, NULL); // 직선 시작점 설정
        LineTo(hdc, 310, 290); // 직선 끝점 설정

        //오른쪽 눈
        MoveToEx(hdc, 470, 270, NULL); // 직선 시작점 설정
        LineTo(hdc, 490, 250); // 직선 끝점 설정

        MoveToEx(hdc, 470, 270, NULL); // 직선 시작점 설정
        LineTo(hdc, 490, 290); // 직선 끝점 설정



        // 직선 그리기
        MoveToEx(hdc, 375, 295, NULL); // 직선 시작점 설정
        LineTo(hdc, 355, 290); // 직선 끝점 설정

        // 직선 그리기
        MoveToEx(hdc, 375, 300, NULL); // 직선 시작점 설정
        LineTo(hdc, 355, 305); // 직선 끝점 설정

        // 직선 그리기
        MoveToEx(hdc, 420, 295, NULL); // 직선 시작점 설정
        LineTo(hdc, 440, 290); // 직선 끝점 설정

        // 직선 그리기
        MoveToEx(hdc, 420, 300, NULL); // 직선 시작점 설정
        LineTo(hdc, 440, 305); // 직선 끝점 설정

        DeleteObject(hbBrush);
        DeleteObject(hb2Brush);
        DeleteObject(hb3Brush);
        DeleteObject(hb4Brush);
        DeleteObject(hb5Brush);

    }
}

// 박스 그리기 함수
void DrawBox2(HWND hWnd, HDC hdc) {
    RECT rect;
    GetClientRect(hWnd, &rect);

    if (isBox2Visible) {
        // 박스 그리기
        HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0)); // 빨간색 박스
        SelectObject(hdc, hBrush);
        //  Rectangle(hdc, 300, 50, 500, 200);
        DeleteObject(hBrush);
    }
}

// 원 그리기 함수
void DrawCircle(HDC hdc, POINT startPoint, POINT endPoint) {
    if (isCircle) {
        HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 255));  // 파란색 원
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
        else {
            isCircle = false;  // 이 부분을 추가하여 박스 그리기 모드에서 원 그리지 않음
        }
        break;

        // 윈도우 프로시저 내에서 키보드 이벤트 처리
    case WM_KEYDOWN:
        if (wParam == VK_SPACE) {
            // 스페이스바가 눌렸을 때
            isSpacePressed = true;
            if (isBono) {
                isBono2 = true;
                InvalidateRect(hWnd, NULL, TRUE);
            }
        }
        break;

    case WM_KEYUP:
        if (wParam == VK_SPACE) {
            // 스페이스바가 떼어졌을 때
            isSpacePressed = false;
            if (isBono2) {
                isBono2 = false;
                isBono = true;
                InvalidateRect(hWnd, NULL, TRUE);
              }
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

       // endPoint.x = LOWORD(lParam);
      //  endPoint.y = HIWORD(lParam);

        if (isBox2Visible) {
            HDC hdc = GetDC(hWnd);
            HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0)); // 빨간색 박스
            SelectObject(hdc, hBrush);
            Rectangle(hdc, startPoint.x, startPoint.y, endPoint.x, endPoint.y);
            DeleteObject(hBrush);
            ReleaseDC(hWnd, hdc);
        }

        if (isCircle) {
            isCircle = false; // 마우스 왼쪽 버튼을 놓을 때 그리기 종료
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
            // 첫 번째 버튼 클릭
            isBox2Visible = true;
            isCircle = false;
            isBono = false;
            isBono2 = false;
            // 포커스를 윈도우로 변경
            SetFocus(hWnd);
            InvalidateRect(hWnd, NULL, TRUE);
        }
        else if (LOWORD(wParam) == 2) {
            // 두 번째 버튼 클릭
            isBox2Visible = false;
            isCircle = true;
            isBono = false;
            isBono2 = false;
            // 포커스를 윈도우로 변경
            SetFocus(hWnd);
            InvalidateRect(hWnd, NULL, TRUE);
        }
        else if (LOWORD(wParam) == 3) {
            // 세 번째 버튼 클릭
            isBox2Visible = false;
            isCircle = false;
            // 포커스를 윈도우로 변경
            SetFocus(hWnd);
            // isBono = true;

            if (isSpacePressed) {
                // 스페이스바가 눌렸을 때

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
            // 네 번째 버튼 클릭
            isBox2Visible = false;
            isCircle = false;
            isBono = false;
            isBono2 = false;
            // 포커스를 윈도우로 변경
            SetFocus(hWnd);
            InvalidateRect(hWnd, NULL, TRUE);
        }
        else if (LOWORD(wParam) == 5) {
            // 다섯 번째 버튼 클릭
            isBox2Visible = false;
            isCircle = false;
            isBono = false;
            isBono2 = false;
            // 포커스를 윈도우로 변경
            SetFocus(hWnd);
            InvalidateRect(hWnd, NULL, TRUE);
        }
        break;
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        DrawMarginAndPaddingBox(hWnd, hdc);
        DrawingWhiteBox(hWnd, hdc);// 새로운 함수 호출
        DrawBox2(hWnd, hdc);
        DrawCircle(hdc, startPoint, endPoint);
        DrawBonobono(hWnd, hdc);
        DrawBonobono2(hWnd, hdc);

        EndPaint(hWnd, &ps);
        break;
    }
                 // WM_CREATE 메시지 핸들러
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
