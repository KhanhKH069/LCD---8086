#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LCD_WIDTH 16

// Dinh nghia kieu du lieu ban ghi cho man hinh LCD 16x2
typedef struct {
    char row1[LCD_WIDTH + 1];
    char row2[LCD_WIDTH + 1];
    bool data_set;
} LCD16x2;

// Ham thiet lap du lieu cho man hinh LCD
void setLCDData(LCD16x2 *lcd, const char *row1, const char *row2) {
    if (strlen(row1) <= LCD_WIDTH && strlen(row2) <= LCD_WIDTH) {
        strcpy(lcd->row1, row1);
        strcpy(lcd->row2, row2);
        lcd->data_set = true;
        printf("Du lieu da duoc thiet lap cho man hinh LCD.\n");
    } else {
        printf("Loi: Du lieu vuot qua do dai cho phep (%d ky tu moi dong).\n", LCD_WIDTH);
        lcd->data_set = false;
    }
}

// Ham hien thi du lieu tren man hinh LCD (mo phong)
void displayLCD(const LCD16x2 *lcd) {
    if (lcd->data_set) {
        printf("-------------------\n");
        printf("| %-16s |\n", lcd->row1);
        printf("| %-16s |\n", lcd->row2);
        printf("-------------------\n");
    } else {
        printf("Loi: Chua co du lieu nao duoc thiet lap da hien thi.\n");
    }
}

int main() {
    // Khoi tao mot bien kieu LCD16x2
    LCD16x2 myLCD;
    myLCD.data_set = false; // Ban dau chua có du lieu

    // Thiet lap du lieu
    setLCDData(&myLCD, "Hello, World!", "Second Line");

    // Hien thi du lieu
    displayLCD(&myLCD);

    // Thu thiet lap du lieu qua dai
    setLCDData(&myLCD, "This is a very long string that exceeds the limit", "Another long string");

    // Hien thi loi
    displayLCD(&myLCD);

    // Hien thi khi chua có du lieu (tao mot bien LCD moi)
    LCD16x2 emptyLCD;
    displayLCD(&emptyLCD);

    return 0;
}
