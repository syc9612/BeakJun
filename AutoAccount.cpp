#include <windows.h>
#include <iostream>

// 후킹된 키보드 이벤트를 처리하는 콜백 함수
LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION) {
        KBDLLHOOKSTRUCT* pKeyBoard = (KBDLLHOOKSTRUCT*)lParam;

        // 키가 눌렸을 때 (wParam이 WM_KEYDOWN일 때)
        if (wParam == WM_KEYDOWN) {
            if ((GetAsyncKeyState(VK_CONTROL) & 0x8000) && pKeyBoard->vkCode == '1') {
                // Ctrl + 1 키가 눌렸을 때 "Hello, World!" 입력
                std::string text = "Qa1xla980502!";
                for (char c : text) {
                    // 키 입력 이벤트 생성
                    INPUT ip;
                    ip.type = INPUT_KEYBOARD;
                    ip.ki.wVk = 0;
                    ip.ki.wScan = c;
                    ip.ki.dwFlags = KEYEVENTF_UNICODE;
                    ip.ki.time = 0;
                    ip.ki.dwExtraInfo = 0;

                    // 키 입력 이벤트 전송
                    SendInput(1, &ip, sizeof(INPUT));
                }

                // 엔터 키 입력
                INPUT ip;
                ip.type = INPUT_KEYBOARD;
                ip.ki.wVk = VK_RETURN;
                ip.ki.wScan = 0;
                ip.ki.dwFlags = 0;
                ip.ki.time = 0;
                ip.ki.dwExtraInfo = 0;
                SendInput(1, &ip, sizeof(INPUT));
            }
        }
    }

    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

int main() {
    // 키보드 후킹
    HHOOK hhkLowLevelKybd = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, 0, 0);

    // 메시지 루프
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // 후킹 해제
    UnhookWindowsHookEx(hhkLowLevelKybd);

    return 0;
}