#pragma once

class Console
{
private:
    SHORT height, width;
    HANDLE hConsoleOutput;
    HANDLE hConsoleInput;
public:
    Console();
    SHORT getHeight() { return height; };
    SHORT getWidth() { return width; };

    void SetWindowSize()
    {
        HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
        SMALL_RECT WindowSize;
        WindowSize.Top = 0;
        WindowSize.Left = 0;
        WindowSize.Bottom = height - 1;
        WindowSize.Right = width - 1;

        SetConsoleWindowInfo(hStdout, 1, &WindowSize);
    }

    void SetScreenBufferSize()
    {
        HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

        COORD NewSize;
        NewSize.X = width;
        NewSize.Y = height;

        SetConsoleScreenBufferSize(hStdout, NewSize);
    }

    void SetColor(int backgound_color, int text_color)
    {
        HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

        int color_code = backgound_color * 16 + text_color;
        SetConsoleTextAttribute(hStdout, color_code);
    }

    void GoToXY(SHORT posX, SHORT posY)
    {
        HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD Position;
        Position.X = posX;
        Position.Y = posY;

        SetConsoleCursorPosition(hStdout, Position);
    }

    void setBackgroundColor(WORD color) {
        CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &screen_buffer_info);

        WORD wAttributes = screen_buffer_info.wAttributes;
        color &= 0x000f;
        color <<= 4; // Dich trai 3 bit de phu hop voi mau nen
        wAttributes &= 0xff0f; // Cai 0 cho 1 bit chu nhay va 3 bit mau nen
        wAttributes |= color;

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wAttributes);
    }

    void Nocursortype()
    {
        CONSOLE_CURSOR_INFO Info;
        Info.bVisible = FALSE;
        Info.dwSize = 20;
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
    }
  

};
class CMAP : Console
{
private:

public:
    void draw();
};
