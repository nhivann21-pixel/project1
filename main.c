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
            if (feof(stdin)) {
                exit(0);
            }
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

void nhapChuoiKhongRong(const char *thongBao, char *chuoi, int kichThuoc) {
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
    nhapChuoiKhongRong("Nhap nganh hoc: ", sv->nganhHoc, sizeof(sv->nganhHoc));
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

    printf("%-8s | %-29s | %-19s | %-4s | %-9s | %-29s\n", "Ma SV", "Ten", "Khoa", "Tuoi", "Nam khoa", "Nganh hoc");
    printf("------------------------------------------------------------------------------------------------------------\n");

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
    printf("%-8s | %-29s | %-19s | %-4s | %-9s | %-29s\n", "Ma SV", "Ten", "Khoa", "Tuoi", "Nam khoa", "Nganh hoc");
    printf("------------------------------------------------------------------------------------------------------------\n");
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
    if (soLuong == 0) {
        printf("\nDanh sach rong!\n");
        return;
    }

    int maSV = nhapSoNguyen("Nhap ma SV can xoa: ", 1, INT_MAX);
    int viTri = timViTriTheoMaSV(maSV);

    if (viTri == -1) {
        printf("Khong tim thay sinh vien co ma %d!\n", maSV);
        return;
    }

    printf("\nThong tin sinh vien bi xoa:\n");
    hienThi1SV(danhSach[viTri]);

    for (int i = viTri; i < soLuong - 1; i++) {
        danhSach[i] = danhSach[i + 1];
    }
    soLuong--;

    printf(">> Xoa sinh vien thanh cong!\n");
}

void thongKe(void) {
    if (soLuong == 0) {
        printf("\nDanh sach rong!\n");
        return;
    }

    char dsKhoa[MAX_SV][20];
    int demKhoa[MAX_SV] = {0};
    int soKhoa = 0;

    for (int i = 0; i < soLuong; i++) {
        int daCo = 0;
        for (int j = 0; j < soKhoa; j++) {
            if (strcmp(danhSach[i].khoa, dsKhoa[j]) == 0) {
                demKhoa[j]++;
                daCo = 1;
                break;
            }
        }
        if (!daCo) {
            strcpy(dsKhoa[soKhoa], danhSach[i].khoa);
            demKhoa[soKhoa] = 1;
            soKhoa++;
        }
    }

    printf("\n--- Thong ke sinh vien theo khoa ---\n");
    printf("%-20s | %-10s\n", "Khoa", "So luong");
    printf("-----------------------------------\n");
    for (int i = 0; i < soKhoa; i++) {
        printf("%-20s | %-10d\n", dsKhoa[i], demKhoa[i]);
    }
}

const char* layTenCuoi(const char* hoTen) {
    const char* lastSpace = strrchr(hoTen, ' ');
    if (lastSpace != NULL) {
        return lastSpace + 1;
    }
    return hoTen;
}

void sapXep(void) {
    if (soLuong == 0) {
        printf("\nDanh sach rong!\n");
        return;
    }

    printf("\n1. Sap xep theo Ma SV tang dan\n");
    printf("2. Sap xep theo Ten (theo thu tu tu dien)\n");
    int chon = nhapSoNguyen("Chon tieu chi sap xep (1-2): ", 1, 2);

    for (int i = 0; i < soLuong - 1; i++) {
        for (int j = i + 1; j < soLuong; j++) {
            int doiCho = 0;

            if (chon == 1) {
                if (danhSach[i].maSV > danhSach[j].maSV) {
                    doiCho = 1;
                }
            } else if (chon == 2) {
                int cmp = strcmp(layTenCuoi(danhSach[i].ten), layTenCuoi(danhSach[j].ten));
                if (cmp > 0) {
                    doiCho = 1;
                } else if (cmp == 0) {
                    if (strcmp(danhSach[i].ten, danhSach[j].ten) > 0) {
                        doiCho = 1;
                    }
                }
            }

            if (doiCho) {
                SinhVien temp = danhSach[i];
                danhSach[i] = danhSach[j];
                danhSach[j] = temp;
            }
        }
    }

    printf(">> Sap xep danh sach thanh cong!\n");
    hienThi();
}

void docFile(void) {
    FILE *f = fopen("sinhvien.dat", "rb");
    if (f != NULL) {
        if (fread(&soLuong, sizeof(int), 1, f) == 1) {
            if (soLuong < 0 || soLuong > MAX_SV) {
                soLuong = 0;
            } else if (soLuong > 0) {
                if (fread(danhSach, sizeof(SinhVien), soLuong, f) != (size_t)soLuong) {
                    soLuong = 0;
                }
            }
        } else {
            soLuong = 0;
        }
        fclose(f);
        if (soLuong > 0) {
            printf(">> Da tai du lieu tu file 'sinhvien.dat' (%d sinh vien).\n", soLuong);
        } else {
            printf(">> Du lieu trong hoac khong hop le. Tao danh sach moi.\n");
        }
    } else {
        printf(">> Khong tim thay file du lieu cu. He thong se tao danh sach moi.\n");
    }
}

void ghiFile(void) {
    FILE *f = fopen("sinhvien.dat", "wb");
    if (f != NULL) {
        fwrite(&soLuong, sizeof(int), 1, f);
        fwrite(danhSach, sizeof(SinhVien), soLuong, f);
        fclose(f);
        printf(">> Da luu du lieu vao file 'sinhvien.dat' thanh cong!\n");
    } else {
        printf(">> Loi: Khong the luu file!\n");
    }
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
    printf("0. Thoat (Luu du lieu)\n");
    printf("==================================\n");
}

int main(void) {
    int chon;

    docFile();

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
                ghiFile();
                printf("Ket thuc chuong trinh!\n");
                break;
        }
    } while (chon != 0);

    return 0;
}
