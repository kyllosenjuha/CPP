#include <iostream>
#include <iomanip>

using namespace std;

enum class Color {Red=16711680, Green=32768, Yellow=16776960, Purple=8388736, Blue=255, Black=0, White=16777215};

void print_RGB_enum_name_and_hex_value(Color color);
void print_RGB_enum_name(Color color);
void print_RGB_hex_value(Color color);

int main()
{
    Color color_red { Color::Red };
    Color color_green {Color::Green };
    Color color_yellow { Color::Yellow };
    Color color_purple { Color::Purple };
    Color color_blue {Color::Blue };
    Color color_black { Color::Black };
    Color color_white { Color::White };

    print_RGB_enum_name_and_hex_value(color_red);
    print_RGB_enum_name_and_hex_value(color_green);
    print_RGB_enum_name_and_hex_value(color_yellow);
    print_RGB_enum_name_and_hex_value(color_purple);
    print_RGB_enum_name_and_hex_value(color_blue);
    print_RGB_enum_name_and_hex_value(color_black);
    print_RGB_enum_name_and_hex_value(color_white);

    return 0;
}

void print_RGB_enum_name_and_hex_value(Color color)
{
    print_RGB_enum_name(color);
    print_RGB_hex_value(color);
}

void print_RGB_enum_name(Color color)
{
    switch(color)
    {
        case Color::Red:
        cout << "Red: ";
        break;
        case Color::Green:
        cout << "Green: ";
        break;
        case Color::Yellow:
        cout << "Yellow: ";
        break;
        case Color::Purple:
        cout << "Purple: ";
        break;
        case Color::Blue:
        cout << "Blue: ";
        break;
        case Color::Black:
        cout << "Black: ";
        break;
        case Color::White:
        cout << "White: ";
        break;
        default:
        break;
    }
}

void print_RGB_hex_value(Color color)
{
    cout << hex << showbase << internal << setfill('0') << setw(8) << static_cast<int>(color) << endl;
}
