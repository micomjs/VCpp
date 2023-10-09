#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif

#include <windows.h>

POINT startPoint = { 0 }; //�׸��� ������ǥ
POINT endPoint = { 0 }; //�׸��� ���� ��ǥ
RECT LastRect = { 0 };
int isMouseLButtonPressed = 0; //���콺 ���ʹ�ư Ŭ��Ȯ��
int isMouseRButtonPressed = 0; //���콺 �����ʹ�ư Ŭ��Ȯ��


// �������� �̺�Ʈ�� ó���ϴ� �ݹ�(Callback) �Լ�.
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

		// �簢�� ��ǥ ���
		int left = min(startPoint.x, endPoint.x);
		int top = min(startPoint.y, endPoint.y);
		int right = max(startPoint.x, endPoint.x);
		int bottom = max(startPoint.y, endPoint.y);

		// ȭ�鿡 �簢�� �׸���
		HDC hdc = GetDC(hwnd);
		RECT rect = { left, top, right, bottom };
		HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 255)); // ��ũ �귯�� ����

		FillRect(hdc, &rect, hBrush); // �簢���� ��ũ������ ä���


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
		// ���콺 �̵� ��
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

		// ���� �簢�� ����
		FillRect(hdc, &LastRect, (HBRUSH)(COLOR_WINDOW + 1));
		ReleaseDC(hwnd, hdc);

		// �ٲ� ��ġ�� �簢�� �׸��� 
		LastRect.left += newX;
		LastRect.right += newX;
		LastRect.top += newY;
		LastRect.bottom += newY;

		hdc = GetDC(hwnd);
		HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 255)); // ��ũ �귯�� ����

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
	/* ������ Ŭ���� ����.*/
	WNDCLASS wc;
	ZeroMemory(&wc, sizeof(wc));	// ��� 0���� �ʱ�ȭ.

	// ������ Ŭ���� �� ����
	wc.hInstance = hInstance;
	wc.lpszClassName = TEXT("Computer Software");
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_CROSS);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;

	// ������ Ŭ���� ���.
	if (RegisterClass(&wc) == 0)
	{
		MessageBox(NULL, L"RegisterClass failed!", L"Error", MB_ICONERROR);
		exit(-1);	//����
	}

	// Window viewport ���� ����
	RECT rect = { 150, 100, 800, 600 };
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, 0);
	int width = rect.right - rect.left;
	int height = rect.bottom - rect.top;

	// ������ ����
	HWND hwnd = CreateWindow(
		wc.lpszClassName,
		TEXT("202217043������"),
		WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX, // ũ�� ���� �� �ִ�ȭ ��ư ��Ȱ��ȭ
		0, 0,
		800, 600,
		NULL, NULL,
		hInstance,
		NULL
	);

	// ���� �˻�.
	if (hwnd == NULL)
	{
		MessageBox(NULL, L"CreateWindow failed!", L"Error", MB_ICONERROR);
		exit(-1);
	}

	// â ���̱�.
	ShowWindow(hwnd, SW_SHOW); // â ����
	UpdateWindow(hwnd); // ������Ʈ�ؾ� ����. �� ������ ���ٰ� ���� ��.



	// �޽��� ó�� ����.
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (msg.message != WM_QUIT)
	{
		// �޽��� ó��.
		if (GetMessage(&msg, hwnd, 0, 0))
			//if (PeekMessage(&msg, hwnd, 0, 0, PM_REMOVE)) // PM_REMOVE�� �ڸ��� �� �޼����� ���� ��Ұų�.�� �ǹ��ε� ����ٴ� ����.
		{

			// �޽��� �ؼ�����.
			TranslateMessage(&msg);
			// �޽����� ó���ؾ��� ���� ��������.
			DispatchMessage(&msg);

		}
		/*else
		{

		}*/
	}

	//���� �޽��� ������
	return (int)msg.wParam;

}