#include <stdio.h>
#include <string.h>

#define MAX_SV 50

typedef struct {
    int maSV;
    char khoa[20];
    char ten[30];
    int tuoi;
    int namKhoa;
    char nganhHoc[30];
} SinhVien;

SinhVien danhSach[MAX_SV];
int soLuong = 0;

void themSinhVien(void) {
    if (soLuong >= MAX_SV) {
        printf("Danh sach da day!\n");
        return;
    }

    printf("\nNhap ma SV: ");
    scanf("%d", &danhSach[soLuong].maSV);

    printf("Nhap ten: ");
    scanf(" %30[^\n]", danhSach[soLuong].ten);

    printf("Nhap khoa: ");
    scanf(" %20[^\n]", danhSach[soLuong].khoa);

    printf("Nhap tuoi: ");
    scanf("%d", &danhSach[soLuong].tuoi);

    printf("Nhap nganh hoc: ");
    scanf(" %30[^\n]", danhSach[soLuong].nganhHoc);

    soLuong++;
    printf(">> Them sinh vien thanh cong!\n");
}

void hienThi(void) {
    if (soLuong == 0) {
        printf("\nDanh sach rong!\n");
        return;
    }
    printf("\nMaSV  | Ten                            | Khoa       | Tuoi | Nganh Hoc\n");
    printf("-------------------------------------------------------------------------\n");
    for (int i = 0; i < soLuong; ++i) {
        printf("%-5d | %-30s | %-10s | %-4d | %-15s\n",
            danhSach[i].maSV, danhSach[i].ten, danhSach[i].khoa, danhSach[i].tuoi, danhSach[i].nganhHoc);
    }
}

void capNhat(void) {
    printf("\n>> Chuc nang cap nhat chua lam xong!\n");
}

void xoaSV(void) {
    printf("\n>> Chuc nang xoa chua lam xong!\n");
}

void thongKe(void) {
    printf("\n>> Chuc nang thong ke chua viet code!\n");
}

void sapXep(void) {
    printf("\n>> Chua hoc thuat toan sap xep!\n");
}

void docFile(void) {
}

void ghiFile(void) {
    printf("\n>> Chua biet cach thao tac voi File!\n");
}

void inMenu(void) {
    printf("\n========== MENU QUAN LY ==========\n");
    printf("1. Them sinh vien\n");
    printf("2. Hien thi danh sach\n");
    printf("3. Cap nhat thong tin sinh vien (Chua lam)\n");
    printf("4. Xoa sinh vien (Chua lam)\n");
    printf("5. Thong ke (Chua lam)\n");
    printf("6. Sap xep danh sach (Chua lam)\n");
    printf("0. Thoat\n");
    printf("==================================\n");
    printf("Chon chuc nang (0-6): ");
}

int main(void) {
    int chon;

    do {
        inMenu();
        scanf("%d", &chon);
        
        switch (chon) {
            case 1: themSinhVien(); break;
            case 2: hienThi(); break;
            case 3: capNhat(); break;
            case 4: xoaSV(); break;
            case 5: thongKe(); break;
            case 6: sapXep(); break;
            case 0:
                printf("Ket thuc chuong trinh!\n");
                break;
            default:
                printf("Nhap sai, vui long nhap lai!\n");
        }
    } while (chon != 0);

    return 0;
}
