BÁO CÁO 
ĐỀ TÀI: XÂY DỰNG CHƯƠNG TRÌNH QUẢN LÝ THÔNG TIN SINH VIÊN
1. Giới thiệu đề tài
Trong công tác quản lý sinh viên, việc lưu trữ, tìm kiếm và cập nhật thông tin cần được thực hiện một cách chính xác, nhanh chóng và có hệ thống. Vì vậy, đề tài “Xây dựng chương trình quản lý thông tin sinh viên bằng ngôn ngữ C” được thực hiện nhằm vận dụng các kiến thức lập trình cơ bản để xây dựng một chương trình hỗ trợ quản lý danh sách sinh viên.
Chương trình cho phép người dùng thực hiện các thao tác như: thêm mới, hiển thị, tìm kiếm, cập nhật, xóa, thống kê và sắp xếp thông tin sinh viên. Ngoài ra, chương trình còn hỗ trợ lưu trữ dữ liệu vào tệp để sử dụng lại trong những lần chạy tiếp theo.
2. Lý do chọn đề tài:
Trong môi trường giáo dục, việc quản lý thông tin sinh viên đóng vai trò quan trọng trong quá trình lưu trữ, tra cứu và thống kê dữ liệu. Nếu thực hiện thủ công, công việc này có thể mất nhiều thời gian và dễ xảy ra sai sót.
Vì vậy, nhóm lựa chọn đề tài “Xây dựng chương trình quản lý thông tin sinh viên” nhằm hỗ trợ quản lý dữ liệu sinh viên thuận tiện và hiệu quả hơn. Đồng thời, đề tài tạo cơ hội vận dụng kiến thức lập trình C vào một bài toán thực tế, qua đó rèn luyện tư duy logic và kỹ năng xây dựng chương trình.
3. Mục tiêu của đề tài
Xây dựng chương trình hỗ trợ quản lý thông tin sinh viên một cách khoa học và hiệu quả.
Đảm bảo tính chính xác, thuận tiện trong quá trình quản lý và tra cứu thông tin.
Nâng cao hiệu quả tổ chức, tìm kiếm và xử lý dữ liệu sinh viên.
Vận dụng kiến thức lập trình để giải quyết bài toán quản lý trong thực tế.
4. Mô tả dữ liệu quản lý
Chương trình sử dụng cấu trúc struct SinhVien để lưu trữ thông tin của từng sinh viên. Danh sách sinh viên được quản lý bằng một mảng có sức chứa tối đa 50 sinh viên.
Các thông tin được quản lý bao gồm:
STT
Trường dữ liệu
Ý nghĩa
1
maSV
Mã sinh viên được tạo tự động.
2
khoa
Mã khoa của sinh viên.
3
ten
Họ và tên sinh viên.
4
ngay, thang, namSinh
Ngày, tháng và năm sinh.
5
tuoi
Tuổi sinh viên, được tính từ năm hiện tại và năm sinh.
6
namKhoa
Năm khóa học của sinh viên.
7
nganhHoc
Mã ngành học của sinh viên.

Chương trình hiện tại hỗ trợ sáu mã khoa/ngành: CNTT, CK, CTP, CDT, DTVT và QTKD.
