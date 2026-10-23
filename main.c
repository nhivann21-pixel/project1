#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>

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

void docDong(const char *thongBao, char *chuoi, int kichThuoc) {
    while (1) {
        printf("%s", thongBao);

        if (fgets(chuoi, kichThuoc, stdin) == NULL) {
            chuoi[0] = '\0';
            return;
        }

        size_t len = strlen(chuoi);

        if (len > 0 && chuoi[len - 1] == '\n') {
            chuoi[--len] = '\0';
        } else {
            int kyTu = getchar();

            if (kyTu != '\n' && kyTu != EOF) {
                while (kyTu != '\n' && kyTu != EOF) {
                    kyTu = getchar();
                }

                printf("Du lieu qua dai, vui long nhap lai!\n");
                continue;
            }
        }

        while (len > 0 && isspace((unsigned char)chuoi[len - 1])) {
            chuoi[--len] = '\0';
        }

        char *batDau = chuoi;
        while (*batDau && isspace((unsigned char)*batDau)) {
            batDau++;
        }

        if (batDau != chuoi) {
            memmove(chuoi, batDau, strlen(batDau) + 1);
        }

        return;
    }
}

int nhapSoNguyen(const char *thongBao, int min, int max) {
    char dong[100];

    while (1) {
        docDong(thongBao, dong, sizeof(dong));

        if (dong[0] == '\0') {
            printf("Vui long nhap mot so nguyen!\n");
            continue;
        }

        char *cuoi;
        errno = 0;
        long giaTri = strtol(dong, &cuoi, 10);

        while (isspace((unsigned char)*cuoi)) {
            cuoi++;
        }

        if (errno == ERANGE || cuoi == dong || *cuoi != '\0'
            || giaTri < min || giaTri > max
            || giaTri < INT_MIN || giaTri > INT_MAX) {
            printf("Gia tri khong hop le! Vui long nhap tu %d den %d.\n",
                   min, max);
            continue;
        }

        return (int)giaTri;
    }
}

void nhapChuoiKhongRong(const char *thongBao,
                        char *chuoi, int kichThuoc) {
    while (1) {
        docDong(thongBao, chuoi, kichThuoc);

        if (chuoi[0] != '\0') {
            return;
        }

        printf("Thong tin khong duoc de trong!\n");
    }
}

int timViTriTheoMaSV(int maSV) {
    for (int i = 0; i < soLuong; i++) {
        if (danhSach[i].maSV == maSV) {
            return i;
        }
    }

    return -1;
}

int kiemTraMaSVTrung(int maSV, int viTriBoQua) {
    for (int i = 0; i < soLuong; i++) {
        if (i != viTriBoQua && danhSach[i].maSV == maSV) {
            return 1;
        }
    }

    return 0;
}

int nhapMaSV(int viTriBoQua) {
    while (1) {
        int maSV = nhapSoNguyen("Nhap ma SV: ", 1, INT_MAX);

        if (kiemTraMaSVTrung(maSV, viTriBoQua)) {
            printf("Ma sinh vien da ton tai!\n");
            continue;
        }

        return maSV;
    }
}

void nhapThongTin(SinhVien *sv) {
    nhapChuoiKhongRong("Nhap ten: ", sv->ten, sizeof(sv->ten));
    nhapChuoiKhongRong("Nhap khoa: ", sv->khoa, sizeof(sv->khoa));
    sv->tuoi = nhapSoNguyen("Nhap tuoi: ", 1, 120);
    sv->namKhoa = nhapSoNguyen("Nhap nam khoa: ", 1900, 2100);
    nhapChuoiKhongRong("Nhap nganh hoc: ",
                       sv->nganhHoc, sizeof(sv->nganhHoc));
}

void themSinhVien(void) {
    if (soLuong >= MAX_SV) {
        printf("\nDanh sach da day!\n");
        return;
    }

    SinhVien sv;
    sv.maSV = nhapMaSV(-1);
    nhapThongTin(&sv);

    danhSach[soLuong] = sv;
    soLuong++;

    printf(">> Them sinh vien thanh cong!\n");
}

void hienThi1SV(SinhVien sv) {
    printf("%-8d | %-29s | %-19s | %-4d | %-9d | %-29s\n",
           sv.maSV, sv.ten, sv.khoa, sv.tuoi,
           sv.namKhoa, sv.nganhHoc);
}

void hienThi(void) {
    if (soLuong == 0) {
        printf("\nDanh sach rong!\n");
        return;
    }

    printf("Ma SV\tTen\tKhoa\tTuoi\tNam khoa\tNganh hoc\n");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < soLuong; i++) {
        hienThi1SV(danhSach[i]);
    }
}

void timKiem(void) {
    if (soLuong == 0) {
        printf("\nDanh sach rong!\n");
        return;
    }

    int maSV = nhapSoNguyen("Nhap ma SV can tim: ", 1, INT_MAX);
    int viTri = timViTriTheoMaSV(maSV);

    if (viTri == -1) {
        printf("Khong tim thay sinh vien co ma %d!\n", maSV);
        return;
    }

    printf("\nThong tin sinh vien tim thay:\n");
    printf("Ma SV\tTen\tKhoa\tTuoi\tNam khoa\tNganh hoc\n");
    printf("------------------------------------------------------------\n");
    hienThi1SV(danhSach[viTri]);
}

void capNhat(void) {
    if (soLuong == 0) {
        printf("\nDanh sach rong!\n");
        return;
    }

    int maSV = nhapSoNguyen("Nhap ma SV can cap nhat: ", 1, INT_MAX);
    int viTri = timViTriTheoMaSV(maSV);

    if (viTri == -1) {
        printf("Khong tim thay sinh vien co ma %d!\n", maSV);
        return;
    }

    printf("\nThong tin hien tai:\n");
    hienThi1SV(danhSach[viTri]);

    printf("\nNhap thong tin moi:\n");

    SinhVien svMoi = danhSach[viTri];
    nhapThongTin(&svMoi);

    danhSach[viTri] = svMoi;

    printf(">> Cap nhat sinh vien thanh cong!\n");
}

void xoaSV(void) {
    printf("\n>> Chuc nang xoa do Nguoi B trien khai!\n");
}

void thongKe(void) {
    printf("\n>> Chuc nang thong ke do Nguoi B trien khai!\n");
}

void sapXep(void) {
    printf("\n>> Chuc nang sap xep do Nguoi B trien khai!\n");
}

void docFile(void) {
    /* Bo sung o tuan 3. */
}

void ghiFile(void) {
    /* o sung o tuan 3. */
}

void inMenu(void) {
    printf("\n========== MENU QUAN LY ==========\n");
    printf("1. Them sinh vien\n");
    printf("2. Hien thi danh sach\n");
    printf("3. Cap nhat thong tin sinh vien\n");
    printf("4. Xoa sinh vien\n");
    printf("5. Thong ke sinh vien\n");
    printf("6. Sap xep danh sach\n");
    printf("7. Tim kiem sinh vien\n");
    printf("0. Thoat\n");
    printf("==================================\n");
}

int main(void) {
    int chon;

    do {
        inMenu();
        chon = nhapSoNguyen("Chon chuc nang (0-7): ", 0, 7);

        switch (chon) {
            case 1:
                themSinhVien();
                break;
            case 2:
                hienThi();
                break;
            case 3:
                capNhat();
                break;
            case 4:
                xoaSV();
                break;
            case 5:
                thongKe();
                break;
            case 6:
                sapXep();
                break;
            case 7:
                timKiem();
                break;
            case 0:
                printf("Ket thuc chuong trinh!\n");
                break;
        }
    } while (chon != 0);

    return 0;
}
