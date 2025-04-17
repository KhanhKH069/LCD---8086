#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Ðinh nghia kieu du lieu ban ghi cho man hinh LCD 16x2
typedef struct {
    char text[2][16]; // Noi dung: 2 dong, moi dong 16 ky tu
    bool is_initialized; // Trang thai khoi tao
    int cursor_row; // Vi tri con tro (dong: 0 hoac 1)
    int cursor_col; // Vi tri con tro (cot: 0 den 15)
} LCD_16x2;

// Ham thiet lap du lieu cho man hinh LCD
void lcd_set_data(LCD_16x2 *lcd, int row, int col, const char *data) {
    // Kiem tra con tro hop li
    if (lcd == NULL) {
        printf("Loi: Con tro LCD không hop li\n");
        return;
    }

    // Kiem tra trang thai khoi tao
    if (!lcd->is_initialized) {
        printf("Loi: LCD chua duoc khoi tao\n");
        return;
    }

    // Kiem tra vi tri dong và cot
    if (row < 0 || row > 1 || col < 0 || col > 15) {
        printf("Loi: Vi tri dong (%d) hoac cot (%d) không hop li\n", row, col);
        return;
    }

    // Kiem tra do dai du lieu
    int data_len = strlen(data);
    if (col + data_len > 16) {
        printf("Loi: Du lieu qua dai cho dong %d tu cot %d\n", row, col);
        return;
    }

    // Thiet lap du lieu vao dong tuong ung
    strncpy(&lcd->text[row][col], data, 16 - col);
    lcd->text[row][15] = '\0'; // Dam bao ket thuc chuoi
    lcd->cursor_row = row;
    lcd->cursor_col = col + data_len;

    printf("Da thiet lap du lieu: '%s' toi dong %d, cot %d\n", data, row, col);
}

// Ham hien thi noi dung tren man hinh LCD
void lcd_display(LCD_16x2 *lcd) {
    // Kiem tra con tro hop li
    if (lcd == NULL) {
        printf("Loi: Con tro LCD không hop li\n");
        return;
    }

    // Kiem tra trang thai khoi tao
    if (!lcd->is_initialized) {
        printf("Loi: LCD chua duoc khoi tao\n");
        return;
    }

    // Hien thi noi dung (mo phong trên console)
    printf("\n=== Noi dung man hinh LCD 16x2 ===\n");
    for (int i = 0; i < 2; i++) {
        printf("Dong %d: [%-16s]\n", i, lcd->text[i]);
    }
    printf("Vi tri con tro: Dong %d, Cot %d\n", lcd->cursor_row, lcd->cursor_col);
    printf("=================================\n");
}

// Ham khoi tao LCD (do mo phong)
void lcd_init(LCD_16x2 *lcd) {
    if (lcd == NULL) {
        printf("Loi: Con tro LCD khong hop li\n");
        return;
    }

    lcd->is_initialized = true;
    lcd->cursor_row = 0;
    lcd->cursor_col = 0;
    memset(lcd->text, ' ', sizeof(lcd->text)); // Xoa noi dung
    for (int i = 0; i < 2; i++) {
        lcd->text[i][15] = '\0'; // Ket thuc chuoi
    }
    printf("Khoi tao LCD thanh cong\n");
}

// Ham main de kiem tra
int main() {
    LCD_16x2 lcd;

    // Khoi tao LCD
    lcd_init(&lcd);

    // Thiet lap du lieu
    lcd_set_data(&lcd, 0, 4, "Xin chao");
    lcd_set_data(&lcd, 1, 4, "LCD 16x2");

    // Hien thi noi dung
    lcd_display(&lcd);

    // Thu truong hop loi
    lcd_set_data(&lcd, 2, 0, "Loi dong"); // Dong khong hop li
    lcd_set_data(&lcd, 0, 10, "Qua dai day"); // Du lieu qua dai

    return 0;
}
