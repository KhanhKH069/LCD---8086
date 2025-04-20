#include <stdio.h>
#include <stdbool.h>

// Dinh nghia kieu du lieu ban ghi cho vi xu ly 8086
typedef struct {
    bool mn_mx; // Trang thai chan MN/MX: 0 (max mode), 1 (min mode)
    bool is_initialized; // Trang thai khoi tao
    char processor_name[20]; // Ten vi xu ly (vi du: "Intel 8086")
    int clock_speed_mhz; // Ten so xung nhap (MHz)
} Intel8086;

// Ham khoi tao vi xu ly (mo phong)
void processor_init(Intel8086 *proc) {
    if (proc == NULL) {
        printf("Loi: Con tro vi xu ly khong hop li\n");
        return;
    }

    proc->is_initialized = true;
    proc->mn_mx = true; // Mac dinh là min mode (MN/MX = 1)
    snprintf(proc->processor_name, sizeof(proc->processor_name), "Intel 8086");
    proc->clock_speed_mhz = 5; // Tan so mac dinh 5 MHz
    printf("Khoi tao vi xu ly %s thanh cong\n", proc->processor_name);
}

// Ham thiet lap chi de lam viec (min/max)
void processor_set_mode(Intel8086 *proc, bool mode) {
    // Kiem tra con tro hop li
    if (proc == NULL) {
        printf("Loi: Con tro vi xu ly khong hop li\n");
        return;
    }

    // Kiem tra trang thai khoi tao
    if (!proc->is_initialized) {
        printf("Loi: Vi xu ly chua duoc khoi tao\n");
        return;
    }

    // Thiet lap che do: mode = false (max, MN/MX = 0), mode = true (min, MN/MX = 1)
    proc->mn_mx = mode;
    printf("Da thiet lap che do lam viec: %s\n", 
           proc->mn_mx ? "Minimum mode (MN/MX = 1)" : "Maximum mode (MN/MX = 0)");
}

// Ham kiem tra che do lam viec
void processor_check_mode(Intel8086 *proc) {
    // Kiem tra con tro hop li
    if (proc == NULL) {
        printf("Loi: Con tro vi xu ly khong hop li\n");
        return;
    }

    // Kiem tra trang thai khoi tao
    if (!proc->is_initialized) {
        printf("Loi: Vi xu ly chua duoc khoi tao\n");
        return;
    }

    // Kiem tra va in thong bao che do
    printf("Che do lam viec hien tai: %s\n", 
           proc->mn_mx ? "Minimum mode (MN/MX = 1)" : "Maximum mode (MN/MX = 0)");
}

// Ham main de kiem tra
int main() {
    Intel8086 proc;

    // Khoi tao vi xu ly
    processor_init(&proc);

    // Thiet lap va kiem tra che do minimum
    processor_set_mode(&proc, true); // Min mode
    processor_check_mode(&proc);

    // Thiet lap và kiem tra che do maximum
    processor_set_mode(&proc, false); // Max mode
    processor_check_mode(&proc);

    // Thu truong hop loi
    processor_set_mode(NULL, true); // Con tro khong hop li
    processor_check_mode(NULL); // Con tro khong hop li

    return 0;
}
