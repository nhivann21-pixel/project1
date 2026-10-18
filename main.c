#include <stdio.h>
#include <string.h>

#define MAX_SV 40

typedef struct {
    int maSV;
    char khoa[20];
    char ten[30];
    int tuoi;
    int namKhoa;
    int ngay, thang, namSinh;
    char nganhHoc[30];
} SinhVien;

SinhVien danhSach[MAX_SV];
int soLuong = 0;

// Chưa có chức năng đọc/ghi file để lưu dữ liệu.
// Khi thoát chương trình, dữ liệu thêm hoặc chỉnh sửa sẽ bị mất.

void danhSachPredefined(void) {
    int i;
    for (i = 0; i < 5; ++i) {
        SinhVien *p = &danhSach[i];
        p->maSV = i + 1;
        switch (i % 4) {
            case 0: strcpy(p->khoa, "CNTT"); break;
            case 1: strcpy(p->khoa, "CK"); break;
            case 2: strcpy(p->khoa, "CTF"); break;
            default: strcpy(p->khoa, "COT"); break;
        }
        switch (i % 4) {
            case 0: strcpy(p->nganhHoc, "CNTT"); break;
            case 1: strcpy(p->nganhHoc, "CK"); break;
            case 2: strcpy(p->nganhHoc, "CTF"); break;
            default: strcpy(p->nganhHoc, "COT"); break;
        }
        switch (i % 5) {
            case 0: strcpy(p->ten, "Nguyen Van A"); p->tuoi = 20; p->ngay = 15; p->thang = 3; p->namSinh = 2000; break;
            case 1: strcpy(p->ten, "Tran Thi B"); p->tuoi = 22; p->ngay = 2; p->thang = 7; p->namSinh = 2001; break;
            case 2: strcpy(p->ten, "Le Van C"); p->tuoi = 19; p->ngay = 10; p->thang = 11; p->namSinh = 2002; break;
            case 3: strcpy(p->ten, "Hoang Thi D"); p->tuoi = 21; p->ngay = 25; p->thang = 1; p->namSinh = 2003; break;
            case 4: strcpy(p->ten, "Pham Van E"); p->tuoi = 23; p->ngay = 8; p->thang = 5; p->namSinh = 2000; break;
        }
    }
    soLuong = 5;
}

void themSinhVien(void) {
    if (soLuong >= MAX_SV) {
        printf("Danh sach da day!\n");
        return;
    }
    SinhVien sv;
    int valid, i;
    do {
        printf("\nNhap ma sinh vien: ");

        // Tại sao không tự động tạo mã sinh viên mà lại yêu cầu nhập mã?
        // Cần kiểm tra mã âm hoặc mã không hợp lệ.
        // Hiện tại chỉ kiểm tra mã trùng với sinh viên đã có.

        scanf("%d", &sv.maSV);
        valid = 1;
        for (i = 0; i < soLuong; ++i)
            if (danhSach[i].maSV == sv.maSV) {
                printf("Ma sinh vien %d da ton tai, nhap lai.\n", sv.maSV);
                valid = 0;
                break;
            }
    } while (!valid);

    printf("Nhap ten: ");
    scanf(" %[^\n]", sv.ten);

    // Lưu ý: scanf(" %[^\n]", sv.ten) có thể gây tràn bộ nhớ
    // nếu chuỗi nhập dài hơn kích thước mảng ten[30].
    // Cần giới hạn độ dài chuỗi nhập và kiểm tra dữ liệu đầu vào.

    printf("Nhap khoa (CNTT/CK/CTF/COT): ");
    scanf(" %[^\n]", sv.khoa);

    // Chưa kiểm tra khoa nhập vào có thuộc danh sách cho phép hay không.

    do {
        printf("Nhap tuoi (18-30): ");
        scanf("%d", &sv.tuoi);
        if (sv.tuoi < 18 || sv.tuoi > 30) printf("Tuoi khong hop le, thu lai.\n");

        // Tuổi và năm sinh có thể không khớp nhau.
        // Có thể tính tuổi từ ngày sinh để tránh lưu dữ liệu trùng lặp.

    } while (sv.tuoi < 18 || sv.tuoi > 30);

    do {
        printf("Nhap nam khoa (2020-2035): ");
        scanf("%d", &sv.namKhoa);
        if (sv.namKhoa < 2020 || sv.namKhoa > 2035) printf("Nam khoa khong hop le, thu lai.\n");

        // Tại sao chỉ xét năm khóa trong khoảng 2020-2035?
        // Khoảng năm nên phù hợp với yêu cầu thực tế và có thể thay đổi theo thời gian.

    } while (sv.namKhoa < 2020 || sv.namKhoa > 2035);

    do {
        printf("Nhap ngay sinh (1-31): ");
        scanf("%d", &sv.ngay);
        if (sv.ngay < 1 || sv.ngay > 31) printf("Ngay khong hop le, thu lai.\n");

        // Chưa kiểm tra ngày sinh theo tháng và năm thực tế.
        // Ví dụ: ngày 30/2 hoặc 31/4 vẫn có thể được chấp nhận.

    } while (sv.ngay < 1 || sv.ngay > 31);

    do {
        printf("Nhap thang sinh (1-12): ");
        scanf("%d", &sv.thang);
        if (sv.thang < 1 || sv.thang > 12) printf("Thang khong hop le, thu lai.\n");
    } while (sv.thang < 1 || sv.thang > 12);

    do {
        printf("Nhap nam sinh (1995-2008): ");
        scanf("%d", &sv.namSinh);
        if (sv.namSinh < 1995 || sv.namSinh > 2008) printf("Nam sinh khong hop le, thu lai.\n");

        // Khoảng năm sinh đang được cố định.
        // Cần xem xét điều chỉnh nếu yêu cầu quản lý thay đổi.

    } while (sv.namSinh < 1995 || sv.namSinh > 2008);

    do {
        printf("Nhap nganh hoc (CNTT/CK/CTF/COT): ");
        scanf(" %[^\n]", sv.nganhHoc);
        valid = 0;
        if (strcmp(sv.nganhHoc, "CNTT") == 0 || strcmp(sv.nganhHoc, "CK") == 0 ||
            strcmp(sv.nganhHoc, "CTF") == 0 || strcmp(sv.nganhHoc, "COT") == 0)
            valid = 1;
        if (!valid) printf("Nganh hoc khong hop le, vui long nhap lai.\n");

        // Danh sách ngành đang được cố định trong code.
        // Khi thêm ngành mới, cần cập nhật điều kiện kiểm tra này.

    } while (!valid);

    danhSach[soLuong++] = sv;
    printf(">> Them sinh vien thanh cong!\n");
}

void hienThi1SV(SinhVien sv) {
    printf("%-6d | %-12s | %-30s | %-5d | %-8d | %02d/%02d/%4d | %-15s\n",
           sv.maSV, sv.khoa, sv.ten, sv.tuoi, sv.namKhoa, sv.ngay, sv.thang, sv.namSinh, sv.nganhHoc);
}

void hienThi(void) {
    if (soLuong == 0) {
        printf("\nDanh sach rong!\n");
        return;
    }
    printf("\n%-6s | %-12s | %-30s | %-5s | %-8s | %-10s | %-15s\n", "MaSV", "Khoa", "Ten", "Tuoi", "NamKhoa", "Ngay/Thang/Nam", "NganhHoc");
    printf("--------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < soLuong; ++i) {
        hienThi1SV(danhSach[i]);
    }
}

int timKiemMa(int ma) {
    for (int i = 0; i < soLuong; ++i)
        if (danhSach[i].maSV == ma) return i;
    return -1;
}

int timKiemTen(const char *ten) {
    for (int i = 0; i < soLuong; ++i)
        if (strcmp(danhSach[i].ten, ten) == 0) return i;
    return -1;
}

void capNhat(int ma) {
    int idx = timKiemMa(ma);
    if (idx == -1) {
        printf("Ma sinh vien %d khong ton tai.\n", ma);
        return;
    }
    SinhVien *sv = &danhSach[idx];
    printf("\n--- Thong tin hien tai ---\n");
    printf("%-6s | %-12s | %-30s | %-5s | %-8s | %-10s | %-15s\n", "MaSV", "Khoa", "Ten", "Tuoi", "NamKhoa", "Ngay/Thang/Nam", "NganhHoc");
    hienThi1SV(*sv);

    printf("\n--- Nhap thong tin moi ---\n");
    printf("Nhap ten: ");
    scanf(" %[^\n]", sv->ten);
    printf("Nhap khoa (CNTT/CK/CTF/COT): ");
    scanf(" %[^\n]", sv->khoa);
    printf("Nhap tuoi hien tai (%d): ", sv->tuoi);
    scanf("%d", &sv->tuoi);
    printf("Nhap nam khoa hien tai (%d): ", sv->namKhoa);
    scanf("%d", &sv->namKhoa);
    printf("Nhap ngay sinh hien tai (%d): ", sv->ngay);
    scanf("%d", &sv->ngay);
    printf("Nhap thang sinh hien tai (%d): ", sv->thang);
    scanf("%d", &sv->thang);
    printf("Nhap nam sinh hien tai (%d): ", sv->namSinh);
    scanf("%d", &sv->namSinh);
    printf("Nhap nganh hoc (CNTT/CK/CTF/COT): ");
    scanf(" %[^\n]", sv->nganhHoc);

    // Hiện tại phải nhập lại toàn bộ thông tin khi cập nhật.
    // Có thể cho phép người dùng chọn riêng trường cần chỉnh sửa.
    // Hàm cập nhật cũng chưa kiểm tra tính hợp lệ của các giá trị mới.

    printf(">> Cap nhat thanh cong!\n");
}

void xoaSV(int ma) {
    int idx = timKiemMa(ma);
    if (idx == -1) {
        printf("Ma sinh vien %d khong ton tai, khong thao tac.\n", ma);
        return;
    }
    for (int i = idx; i < soLuong-1; ++i)
        danhSach[i] = danhSach[i+1];
    --soLuong;
    printf(">> Xoa sinh vien co ma %d thanh cong!\n", ma);
}

void thongKe(void) {
    if (soLuong == 0) {
        printf("\nDanh sach rong, khong the thong ke.\n");
        return;
    }
    int countCK = 0, countCNTT = 0, countCTF = 0, countCOT = 0;

    // Việc thống kê khoa đang sử dụng các điều kiện cố định.
    // Nếu bổ sung khoa mới, cần sửa code.
    // Có thể cải tiến để thống kê linh hoạt theo dữ liệu thực tế.

    for (int i = 0; i < soLuong; ++i) {
        if (strcmp(danhSach[i].khoa, "CNTT") == 0) countCNTT++;
        else if (strcmp(danhSach[i].khoa, "CK") == 0) countCK++;
        else if (strcmp(danhSach[i].khoa, "CTF") == 0) countCTF++;
        else if (strcmp(danhSach[i].khoa, "COT") == 0) countCOT++;
    }

    printf("\n--- So sinh vien theo khoa ---\n");
    printf("CNTT: %d\n", countCNTT);
    printf("CK  : %d\n", countCK);
    printf("CTF : %d\n", countCTF);
    printf("COT : %d\n", countCOT);
}

void sapXep(void) {
    if (soLuong == 0) {
        printf("\nDanh sach rong, khong the sap xep.\n");
        return;
    }
    int chon;

    // Có thể bổ sung sắp xếp theo nhiều tiêu chí,
    // ví dụ: năm khóa tăng dần, sau đó tên theo thứ tự alphabet.

    printf("\nChon cach sap xep (1 = Theo Ten, 2 = Theo Tuoi, 3 = Theo Nam Khoa): ");
    scanf("%d", &chon);
    if (chon < 1 || chon > 3) {
        printf("Lua chon khong hop le!\n");
        return;
    }
    for (int i = 0; i < soLuong - 1; ++i) {
        for (int j = i + 1; j < soLuong; ++j) {
            int canDoiCho = 0;
            if (chon == 1 && strcmp(danhSach[i].ten, danhSach[j].ten) > 0) canDoiCho = 1;
            else if (chon == 2 && danhSach[i].tuoi > danhSach[j].tuoi) canDoiCho = 1;
            else if (chon == 3 && danhSach[i].namKhoa > danhSach[j].namKhoa) canDoiCho = 1;

            if (canDoiCho) {
                SinhVien tmp = danhSach[i];
                danhSach[i] = danhSach[j];
                danhSach[j] = tmp;
            }
        }
    }
    printf(">> Danh sach da duoc sap xep tang dan!\n");
}

void inMenu(void) {
    printf("\n=== MENU QUAN LY SINH VIEN ===\n");
    printf("1. Them sinh vien\n");
    printf("2. Hien thi danh sach\n");
    printf("3. Tim kiem sinh vien theo ma SV\n");
    printf("4. Tim kiem sinh vien theo ten\n");
    printf("5. Cap nhat thong tin sinh vien\n");
    printf("6. Xoa sinh vien\n");
    printf("7. Thong ke\n");
    printf("8. Sap xep danh sach\n");
    printf("9. Thoat\n");
    printf("Chon chuc nang (1-9): ");
}

int main(void) {
    int chon, ma, idx;
    danhSachPredefined();
    do {
        inMenu();
        if (scanf("%d", &chon) != 1) {
            while ( getchar()!='\n' );
            printf("Nhap khong hop le, thu lai!\n");
            continue;
        }
        switch(chon) {
            case 1: themSinhVien(); break;
            case 2: hienThi(); break;
            case 3:
                printf("\nNhap ma sinh vien muon tim: ");
                scanf("%d", &ma);
                idx = timKiemMa(ma);
                if (idx != -1) {
                    printf("\n>> Da tim thay sinh vien:\n");
                    hienThi1SV(danhSach[idx]);
                } else {
                    printf("Khong tim thay ma %d!\n", ma);
                }
                break;
            case 4:
                printf("\nNhap ten sinh vien muon tim (nhap chinh xac): ");
                char ten[30];
                scanf(" %[^\n]", ten);
                idx = timKiemTen(ten);
                if (idx != -1) {
                    printf("\n>> Da tim thay sinh vien:\n");
                    hienThi1SV(danhSach[idx]);
                } else {
                    printf("Khong tim thay sinh vien ten '%s'!\n", ten);
                }
                break;
            case 5:
                printf("\nNhap ma sinh vien muon cap nhat: ");
                scanf("%d", &ma);
                capNhat(ma);
                break;
            case 6:
                printf("\nNhap ma sinh vien muon xoa: ");
                scanf("%d", &ma);
                xoaSV(ma);
                break;
            case 7: thongKe(); break;
            case 8: sapXep(); break;
            case 9: printf("Ket thuc chuong trinh!\n"); break;
            default: printf("Chon khong hop le!\n");
        }
    } while (chon != 9);
    return 0;
}
