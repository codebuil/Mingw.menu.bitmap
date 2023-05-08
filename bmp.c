#include <windows.h>
int xx[20];
int yy[20];
int ww[20];
int hh[20];
 HDC hdc;
    PAINTSTRUCT ps;
    RECT rect;
    int iiii=0;
// Ponto para armPOINT ptLastClickazenar as coordenadas do último clique do mouse
POINT ptLastClick[500];
// Protótipo da função de tratamento de mensagens
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);




// Função principal
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // Definir as informações da janela
    WNDCLASSEX wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = "MyWindowClass";
    wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);
    RegisterClassEx(&wcex);
    
    // Criar a janela
    HWND hWnd = CreateWindow("MyWindowClass", "Minha Janela", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 640, 480, NULL, NULL, hInstance, NULL);
    if (!hWnd)
    {
        return -1;
    }

    // Mostrar a janela
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    // Loop de mensagens
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

// Função de tratamento de mensagens
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static HBITMAP hBitmap = NULL;
    PAINTSTRUCT ps;
    HDC hdc ;
    BITMAP bm;
    HDC hdcMem ;
    HBITMAP hbmOld;
        // Obter as coordenadas do clique do mouse
    int ptLastClickx;
    int ptLastClicky;
    int j=0;
    int n=0;
    switch (message)
    {
               case WM_CREATE:
        {
            // Carrega o bitmap
            hBitmap = (HBITMAP)LoadImage(NULL, "menu.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            if (hBitmap == NULL)
            {
                MessageBox(hWnd, "Erro ao carregar o bitmap", "Erro", MB_OK | MB_ICONERROR);
                return -1;
            }
            //get from MS pbrush x,y
            xx[0]=160;
            yy[0]=70;
            ww[0]=310;
            hh[0]=50;
            xx[1]=160;
            yy[1]=142;
            ww[1]=310;
            hh[1]=50;
            xx[2]=160;
            yy[2]=212;
            ww[2]=310;
            hh[2]=50;
            xx[3]=160;
            yy[3]=287;
            ww[3]=310;
            hh[3]=50;
            xx[4]=160;
            yy[4]=365;
            ww[4]=310;
            hh[4]=50;


        
        
        }
         break;
    case WM_LBUTTONDOWN:
        // Obter as coordenadas do clique do mouse
        ptLastClickx = LOWORD(lParam);
        ptLastClicky = HIWORD(lParam);
        
        for(j=0;j<5;j++){
            if(ptLastClickx>=xx[j] && ptLastClicky>=yy[j] && ptLastClickx<=xx[j]+ww[j] && ptLastClicky<=yy[j]+hh[j]){
                MessageBox(hWnd, "button press", "Erro", MB_OK | MB_ICONERROR);
            }
        }
        // Redesenha a janela para exibir o círculo
       // InvalidateRect(hWnd, NULL, TRUE);
        
        break;

    
case WM_PAINT:
            hdc = BeginPaint(hWnd, &ps);

            
            hdcMem = CreateCompatibleDC(hdc);
            hbmOld = (HBITMAP)SelectObject(hdcMem, hBitmap);
            GetObject(hBitmap, sizeof(bm), &bm);
            BitBlt(hdc, 0, 0, bm.bmWidth, bm.bmHeight, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, hbmOld);
            DeleteDC(hdcMem);

            EndPaint(hWnd, &ps);
            break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }

    return 0;
}
