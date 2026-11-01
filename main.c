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
            int kyTu;
            while ((kyTu = getchar()) != '\n' && kyTu != EOF);
            printf("Du lieu qua dai, vui long nhap lai!\n");
            continue;
        }

        while (len > 0 && isspace((unsigned char)chuoi[len - 1])) chuoi[--len] = '\0';
        char *batDau = chuoi;
        while (*batDau && isspace((unsigned char)*batDau)) batDau++;
        if (batDau != chuoi) memmove(chuoi, batDau, strlen(batDau) + 1);

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
        while (isspace((unsigned char)*cuoi)) cuoi++;

        if (errno == ERANGE || cuoi == dong || *cuoi != '\0' || giaTri < min || giaTri > max) {
            printf("Gia tri khong hop le! Vui long nhap tu %d den %d.\n", min, max);
            continue;
        }
        return (int)giaTri;
    }
}

void nhapChuoiKhongRong(const char *thongBao, char *chuoi, int kichThuoc) {
    do {
        docDong(thongBao, chuoi, kichThuoc);
        if (chuoi[0] != '\0') return;
        printf("Thong tin khong duoc de trong!\n");
    } while (1);
}

const char* layTenCuoi(const char* hoTen) {
    const char* lastSpace = strrchr(hoTen, ' ');
    return (lastSpace != NULL) ? lastSpace + 1 : hoTen;
}

void inTieuDe(void) {
    printf("%-8s | %-29s | %-19s | %-4s | %-9s | %-29s\n", "Ma SV", "Ten", "Khoa", "Tuoi", "Nam khoa", "Nganh hoc");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
}

void hienThi1SV(SinhVien sv) {
    printf("%-8d | %-29s | %-19s | %-4d | %-9d | %-29s\n", sv.maSV, sv.ten, sv.khoa, sv.tuoi, sv.namKhoa, sv.nganhHoc);
}

int timViTriTheoMaSV(int maSV) {
    for (int i = 0; i < soLuong; i++) {
        if (danhSach[i].maSV == maSV) return i;
    }
    return -1;
}

int kiemTraMaSVTrung(int maSV, int viTriBoQua) {
    for (int i = 0; i < soLuong; i++) {
        if (i != viTriBoQua && danhSach[i].maSV == maSV) return 1;
    }
    return 0;
}

void nhapThongTin(SinhVien *sv) {
    nhapChuoiKhongRong("Nhap ten: ", sv->ten, sizeof(sv->ten));
    nhapChuoiKhongRong("Nhap khoa: ", sv->khoa, sizeof(sv->khoa));
    for (int i = 0; sv->khoa[i] != 0; i++) {
        sv->khoa[i] = (char)toupper((unsigned char)sv->khoa[i]);
    }
    sv->tuoi = nhapSoNguyen("Nhap tuoi: ", 1, 120);
    sv->namKhoa = nhapSoNguyen("Nhap nam khoa: ", 1900, 2100);
    nhapChuoiKhongRong("Nhap nganh hoc: ", sv->nganhHoc, sizeof(sv->nganhHoc));
}

void themSinhVien(void) {
    if (soLuong >= MAX_SV) {
        printf("\nDanh sach da day (%d/%d)!\n", soLuong, MAX_SV);
        return;
    }
    SinhVien sv;
    while (1) {
        sv.maSV = nhapSoNguyen("Nhap ma SV: ", 1, INT_MAX);
        if (!kiemTraMaSVTrung(sv.maSV, -1)) break;
        printf("Ma sinh vien da ton tai!\n");
    }
    nhapThongTin(&sv);
    danhSach[soLuong++] = sv;
    printf(">> Them sinh vien thanh cong!\n");
}

void hienThi(void) {
    if (soLuong == 0) {
        printf("\nDanh sach rong!\n");
        return;
    }
    inTieuDe();
    for (int i = 0; i < soLuong; i++) hienThi1SV(danhSach[i]);
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
    inTieuDe();
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
    inTieuDe();
    hienThi1SV(danhSach[viTri]);

    printf("\nNhap thong tin moi:\n");
    nhapThongTin(&danhSach[viTri]);
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
    inTieuDe();
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
    typedef struct {
        char tenKhoa[20];
        int dem;
    } ThongKeKhoa;

    ThongKeKhoa tk[MAX_SV];
    int soKhoa = 0;

    for (int i = 0; i < soLuong; i++) {
        int daCo = 0;
        for (int j = 0; j < soKhoa; j++) {
            if (strcmp(danhSach[i].khoa, tk[j].tenKhoa) == 0) {
                tk[j].dem++;
                daCo = 1;
                break;
            }
        }
        if (!daCo) {
            strcpy(tk[soKhoa].tenKhoa, danhSach[i].khoa);
            tk[soKhoa].dem = 1;
            soKhoa++;
        }
    }
    printf("\n--- Thong ke sinh vien theo khoa ---\n");
    printf("%-20s | %-10s\n", "Khoa", "So luong");
    printf("-----------------------------------\n");
    for (int i = 0; i < soKhoa; i++) {
        printf("%-20s | %-10d\n", tk[i].tenKhoa, tk[i].dem);
    }
}

void sapXep(void) {
    if (soLuong == 0) {
        printf("\nDanh sach rong!\n");
        return;
    }
    printf("\n1. Sap xep theo Ma SV tang dan\n2. Sap xep theo Ten (theo thu tu tu dien)\n");
    int chon = nhapSoNguyen("Chon tieu chi sap xep (1-2): ", 1, 2);

    for (int i = 0; i < soLuong - 1; i++) {
        for (int j = i + 1; j < soLuong; j++) {
            int doiCho = 0;
            if (chon == 1 && danhSach[i].maSV > danhSach[j].maSV) {
                doiCho = 1;
            } else if (chon == 2) {
                int cmp = strcmp(layTenCuoi(danhSach[i].ten), layTenCuoi(danhSach[j].ten));
                if (cmp > 0 || (cmp == 0 && strcmp(danhSach[i].ten, danhSach[j].ten) > 0)) {
                    doiCho = 1;
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
            if (soLuong < 0) soLuong = 0;
            if (soLuong > MAX_SV) soLuong = MAX_SV;

            fread(danhSach, sizeof(SinhVien), soLuong, f);
            printf(">> Da tai du lieu tu file 'sinhvien.dat' (%d sinh vien).\n", soLuong);
        }
        fclose(f);
    } else {
        printf(">> Khong tim thay file du lieu cu.\n");
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

void taoDuLieuMau(void) {
    SinhVien mau[20] = {
        {1, "CNTT", "Nguyen Van An", 19, 2025, "Ky thuat phan mem"},
        {2, "CNTT", "Tran Thi Binh", 18, 2026, "Khoa hoc may tinh"},
        {3, "Kinh Te", "Le Hoang Cuong", 20, 2024, "Quan tri kinh doanh"},
        {4, "Ngoai Ngu", "Pham Thi Dung", 19, 2025, "Ngon ngu Anh"},
        {5, "Dien Tu", "Hoang Van Em", 21, 2023, "Dien tu vien thong"},
        {6, "CNTT", "Vu Thi Hoa", 18, 2026, "An toan thong tin"},
        {7, "Kinh Te", "Dang Van Giang", 20, 2024, "Tai chinh ngan hang"},
        {8, "Du Lich", "Bui Thi Hanh", 19, 2025, "Quan tri khach san"},
        {9, "CNTT", "Doan Van Inh", 22, 2022, "He thong thong tin"},
        {10, "Ngoai Ngu", "Ngo Thi Kieu", 19, 2025, "Ngon ngu Trung"},
        {11, "Kinh Te", "Ly Van Long", 18, 2026, "Ke toan"},
        {12, "Dien Tu", "Truong Thi Mai", 20, 2024, "Dieu khien tu dong"},
        {13, "CNTT", "Dinh Van Nam", 19, 2025, "Khoa hoc du lieu"},
        {14, "Du Lich", "Vo Thi Oanh", 21, 2023, "Huong dan vien"},
        {15, "Ngoai Ngu", "Nguyen Van Phong", 18, 2026, "Ngon ngu Nhat"},
        {16, "Kinh Te", "Tran Thi Quynh", 20, 2024, "Kinh te quoc te"},
        {17, "CNTT", "Le Van Rung", 19, 2025, "Mang may tinh"},
        {18, "Dien Tu", "Pham Thi Suong", 21, 2023, "Ky thuat y sinh"},
        {19, "Ngoai Ngu", "Hoang Van Toan", 18, 2026, "Ngon ngu Han"},
        {20, "Kinh Te", "Vu Thi Uyen", 19, 2025, "Marketing"}
    };

    for (int i = 0; i < 20; i++) {
        danhSach[i] = mau[i];
    }
    soLuong = 20;
    printf(">> Da tao tu dong 20 sinh vien mau!\n");
}

void inMenu(void) {
    printf("\n========== MENU QUAN LY ==========\n");
    printf("1. Them sinh vien\n2. Hien thi danh sach\n3. Cap nhat thong tin sinh vien\n");
    printf("4. Xoa sinh vien\n5. Thong ke sinh vien\n6. Sap xep danh sach\n");
    printf("7. Tim kiem sinh vien\n0. Thoat (Luu du lieu)\n");
    printf("==================================\n");
}

int main(void) {
    int chon;
    docFile();

    if (soLuong == 0) {
        taoDuLieuMau();
    }

    do {
        inMenu();
        chon = nhapSoNguyen("Chon chuc nang (0-7): ", 0, 7);
        switch (chon) {
            case 1: themSinhVien(); break;
            case 2: hienThi(); break;
            case 3: capNhat(); break;
            case 4: xoaSV(); break;
            case 5: thongKe(); break;
            case 6: sapXep(); break;
            case 7: timKiem(); break;
            case 0:
                ghiFile();
                printf("Ket thuc chuong trinh!\n");
                break;
        }
    } while (chon != 0);
    return 0;
}
