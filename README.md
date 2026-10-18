# BÁO CÁO ĐỀ TÀI: XÂY DỰNG CHƯƠNG TRÌNH QUẢN LÝ THÔNG TIN SINH VIÊN

Chương trình quản lý thông tin sinh viên được viết bằng ngôn ngữ lập trình C, hỗ trợ tổ chức, lưu trữ và xử lý dữ liệu sinh viên một cách nhanh chóng, chính xác.

---

## 1. Giới Thiệu Đề Tài

Trong công tác quản lý sinh viên, việc lưu trữ, tìm kiếm và cập nhật thông tin cần được thực hiện một cách chính xác, nhanh chóng và có hệ thống. Vì vậy, đề tài **“Xây dựng chương trình quản lý thông tin sinh viên bằng ngôn ngữ C”** được thực hiện nhằm vận dụng các kiến thức lập trình cơ bản để xây dựng một chương trình hỗ trợ quản lý danh sách sinh viên.

Chương trình cho phép người dùng thực hiện các thao tác:
* Thêm mới sinh viên
* Hiển thị danh sách
* Tìm kiếm và cập nhật thông tin
* Xóa sinh viên
* Thống kê và sắp xếp dữ liệu
* Lưu trữ dữ liệu vào tệp để sử dụng lại trong những lần chạy tiếp theo

---

## 2. Lý Do Chọn Đề Tài

Trong môi trường giáo dục, việc quản lý thông tin sinh viên đóng vai trò quan trọng trong quá trình lưu trữ, tra cứu và thống kê dữ liệu. Nếu thực hiện thủ công, công việc này có thể mất nhiều thời gian và dễ xảy ra sai sót.

Vì vậy, nhóm lựa chọn đề tài **“Xây dựng chương trình quản lý thông tin sinh viên”** nhằm:
* Hỗ trợ quản lý dữ liệu sinh viên thuận tiện và hiệu quả hơn.
* Tạo cơ hội vận dụng kiến thức lập trình C vào một bài toán thực tế.
* Rèn luyện tư duy logic và kỹ năng xây dựng, tối ưu hóa chương trình.

---

## 3. Mục Tiêu Của Đề Tài

* **Tính khoa học & hiệu quả:** Xây dựng chương trình hỗ trợ quản lý thông tin sinh viên một cách khoa học.
* **Tính chính xác:** Đảm bảo tính chính xác, thuận tiện trong quá trình quản lý và tra cứu thông tin.
* **Tối ưu hóa xử lý:** Nâng cao hiệu quả tổ chức, tìm kiếm và xử lý dữ liệu sinh viên.
* **Ứng dụng thực tế:** Vận dụng kiến thức lập trình để giải quyết bài toán quản lý trong thực tế.

---

## 4. Mô Tả Dữ Liệu Quản Lý

Chương trình sử dụng cấu trúc `struct SinhVien` để lưu trữ thông tin của từng sinh viên. Danh sách sinh viên được quản lý bằng một mảng có sức chứa tối đa **50 sinh viên**.

### Cấu trúc bảng dữ liệu:

| STT | Trường dữ liệu | Ý nghĩa |
| :---: | :--- | :--- |
| **1** | `maSV` | Mã sinh viên (được tạo tự động) |
| **2** | `khoa` | Mã khoa của sinh viên |
| **3** | `ten` | Họ và tên sinh viên |
| **4** | `ngay`, `thang`, `namSinh` | Ngày, tháng và năm sinh |
| **5** | `tuoi` | Tuổi sinh viên (được tính từ năm hiện tại và năm sinh) |
| **6** | `namKhoa` | Năm khóa học của sinh viên |
| **7** | `nganhHoc` | Mã ngành học của sinh viên |

> **Lưu ý:** Chương trình hiện tại hỗ trợ 6 mã khoa/ngành bao gồm: **CNTT**, **CK**, **CTP**, **CDT**, **DTVT** và **QTKD**.oa/ngành: CNTT, CK, CTP, CDT, DTVT và QTKD.
