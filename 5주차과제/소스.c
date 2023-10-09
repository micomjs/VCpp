#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif

#include <windows.h>

POINT startPoint = { 0 }; //그리기 시작좌표
POINT endPoint = { 0 }; //그리기 종료 좌표
RECT LastRect = { 0 };
int isMouseLButtonPressed = 0; //마우스 왼쪽버튼 클릭확인
int isMouseRButtonPressed = 0; //마우스 오른쪽버튼 클릭확인


// 윈도우의 이벤트를 처리하는 콜백(Callback) 함수.
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_LBUTTONDOWN:
	{

		startPoint.x = LOWORD(lParam);
		startPoint.y = HIWORD(lParam);
		isMouseLButtonPressed = 1;
	}
	break;

	case WM_LBUTTONUP:
	{

		endPoint.x = LOWORD(lParam);
		endPoint.y = HIWORD(lParam);

		isMouseLButtonPressed = 0;

		// 사각형 좌표 계산
		int left = min(startPoint.x, endPoint.x);
		int top = min(startPoint.y, endPoint.y);
		int right = max(startPoint.x, endPoint.x);
		int bottom = max(startPoint.y, endPoint.y);

		// 화면에 사각형 그리기
		HDC hdc = GetDC(hwnd);
		RECT rect = { left, top, right, bottom };
		HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 255)); // 핑크 브러시 생성

		FillRect(hdc, &rect, hBrush); // 사각형을 핑크색으로 채우기


		LastRect = rect;
	}
	break;


	case WM_RBUTTONDOWN:
	{
		startPoint.x = LOWORD(lParam);
		startPoint.y = HIWORD(lParam);
		isMouseRButtonPressed = 1;
	}
	break;


	case WM_MOUSEMOVE:
	{
		// 마우스 이동 중
		if (isMouseLButtonPressed)
		{
			
		}

	}
	break;

	case WM_RBUTTONUP:
	{
		HDC hdc = GetDC(hwnd);
		endPoint.x = LOWORD(lParam);
		endPoint.y = HIWORD(lParam);

		int newX = endPoint.x - startPoint.x;
		int newY = endPoint.y - startPoint.y;

		// 이전 사각형 삭제
		FillRect(hdc, &LastRect, (HBRUSH)(COLOR_WINDOW + 1));
		ReleaseDC(hwnd, hdc);

		// 바뀐 위치에 사각형 그리기 
		LastRect.left += newX;
		LastRect.right += newX;
		LastRect.top += newY;
		LastRect.bottom += newY;

		hdc = GetDC(hwnd);
		HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 255)); // 핑크 브러시 생성

		FillRect(hdc, &LastRect, hBrush);
		ReleaseDC(hwnd, hdc);
		DeleteObject(hBrush);

		isMouseRButtonPressed = 0;
	}
	break;

	case WM_PAINT:
	{
		PAINTSTRUCT ps = { 0 };
		HDC hdc = GetDC(hwnd);

		if (isMouseLButtonPressed)
		{
			RECT rect;
			GetClientRect(hwnd, &rect);
			FillRect(hdc, &rect, (HBRUSH)(COLOR_WINDOW + 1));
		}

		EndPaint(hwnd, &ps);


		ReleaseDC(hwnd, hdc);


	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}

	return S_OK;
}
#ifdef UNICODE
int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
#else
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR pCmdLine, _In_ int nCmdShow)
#endif
{
	/* 윈도우 클래스 선언.*/
	WNDCLASS wc;
	ZeroMemory(&wc, sizeof(wc));	// 모두 0으로 초기화.

	// 윈도우 클래스 값 설정
	wc.hInstance = hInstance;
	wc.lpszClassName = TEXT("Computer Software");
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_CROSS);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;

	// 윈도우 클래스 등록.
	if (RegisterClass(&wc) == 0)
	{
		MessageBox(NULL, L"RegisterClass failed!", L"Error", MB_ICONERROR);
		exit(-1);	//예외
	}

	// Window viewport 영역 조정
	RECT rect = { 150, 100, 800, 600 };
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, 0);
	int width = rect.right - rect.left;
	int height = rect.bottom - rect.top;

	// 윈도우 생성
	HWND hwnd = CreateWindow(
		wc.lpszClassName,
		TEXT("202217043정서연"),
		WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX, // 크기 조절 및 최대화 버튼 비활성화
		0, 0,
		800, 600,
		NULL, NULL,
		hInstance,
		NULL
	);

	// 오류 검사.
	if (hwnd == NULL)
	{
		MessageBox(NULL, L"CreateWindow failed!", L"Error", MB_ICONERROR);
		exit(-1);
	}

	// 창 보이기.
	ShowWindow(hwnd, SW_SHOW); // 창 띄우고
	UpdateWindow(hwnd); // 업데이트해야 보임. 한 쌍으로 쓴다고 보면 됨.



	// 메시지 처리 루프.
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (msg.message != WM_QUIT)
	{
		// 메시지 처리.
		if (GetMessage(&msg, hwnd, 0, 0))
			//if (PeekMessage(&msg, hwnd, 0, 0, PM_REMOVE)) // PM_REMOVE의 자리는 이 메세지를 쓰고 어떡할거냐.의 의미인데 지운다는 것임.
		{

			// 메시지 해석해줘.
			TranslateMessage(&msg);
			// 메시지를 처리해야할 곳에 전달해줘.
			DispatchMessage(&msg);

		}
		/*else
		{

		}*/
	}

	//종료 메시지 보내기
	return (int)msg.wParam;

}