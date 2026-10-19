# BÁO CÁO TIẾN ĐỘ TUẦN 1

**ĐỀ TÀI: XÂY DỰNG CHƯƠNG TRÌNH QUẢN LÝ THÔNG TIN SINH VIÊN**

## 1. Giới thiệu đề tài

Thông tin sinh viên là dữ liệu quan trọng trong quá trình quản lý và theo dõi người học tại các cơ sở giáo dục. Những thông tin như mã sinh viên, họ tên, khoa, tuổi và ngành học cần được tổ chức rõ ràng để phục vụ việc tra cứu, kiểm tra và tổng hợp dữ liệu khi cần thiết.

Tuy nhiên, khi số lượng thông tin tăng lên, việc quản lý bằng các phương pháp thủ công có thể gây khó khăn trong quá trình tìm kiếm, cập nhật và kiểm soát dữ liệu. Vì vậy, việc xây dựng một chương trình quản lý thông tin sinh viên là giải pháp có thể hỗ trợ tổ chức dữ liệu tập trung và nâng cao tính thuận tiện trong quá trình sử dụng.

Đề tài “Xây dựng chương trình quản lý thông tin sinh viên” hướng đến việc xây dựng một chương trình cho phép lưu trữ, hiển thị và xử lý thông tin sinh viên thông qua các chức năng quản lý cơ bản. Trong tuần đầu tiên, nhóm tập trung xác định các trường thông tin cần quản lý, xây dựng cấu trúc danh sách và triển khai những thao tác ban đầu để hình thành nền tảng của hệ thống.

## 2. Lý do chọn đề tài

Quản lý thông tin sinh viên là một nhu cầu thực tế trong môi trường giáo dục. Dữ liệu cần được tổ chức thống nhất để thuận tiện cho việc theo dõi, kiểm tra và sử dụng trong các hoạt động quản lý.

Nếu thông tin được lưu trữ thiếu hệ thống, người quản lý có thể gặp khó khăn khi tìm kiếm dữ liệu, kiểm tra thông tin của từng sinh viên hoặc bổ sung hồ sơ mới. Ngoài ra, việc nhập liệu không được kiểm soát có thể dẫn đến sai sót và thiếu nhất quán giữa các thông tin.

Từ những vấn đề trên, nhóm lựa chọn đề tài nhằm xây dựng một giải pháp quản lý thông tin sinh viên có cấu trúc rõ ràng, dễ thao tác và có khả năng mở rộng thêm các chức năng xử lý dữ liệu. Trước mắt, chương trình tập trung vào việc tiếp nhận thông tin, tổ chức danh sách và hiển thị dữ liệu; các chức năng quản lý chuyên sâu sẽ được phát triển trong những giai đoạn tiếp theo.

## 3. Mục tiêu của đề tài

- Xây dựng giải pháp quản lý thông tin sinh viên trong một danh sách thống nhất.
- Tổ chức các trường thông tin cơ bản nhằm hỗ trợ việc theo dõi và kiểm tra dữ liệu.
- Cung cấp khả năng bổ sung thông tin sinh viên mới và hiển thị danh sách hiện có.
- Định hướng phát triển các chức năng cập nhật, xóa, thống kê, sắp xếp và lưu trữ dữ liệu.
- Từng bước hoàn thiện chương trình nhằm đáp ứng nhu cầu quản lý thông tin sinh viên một cách thuận tiện và có hệ thống.

## 4. Phạm vi và dữ liệu quản lý

### 4.1. Phạm vi đề tài

Trong giai đoạn đầu, chương trình tập trung vào việc quản lý danh sách sinh viên ở quy mô nhỏ, với sức chứa tối đa 50 sinh viên. Hệ thống hoạt động thông qua giao diện văn bản, cho phép người dùng lựa chọn thao tác bằng menu.

Phạm vi triển khai tuần 1 bao gồm:

- Xác định các trường dữ liệu cần quản lý.
- Tiếp nhận và bổ sung thông tin sinh viên.
- Hiển thị danh sách sinh viên hiện có.
- Tổ chức menu điều khiển các chức năng quản lý.
- Xác định các chức năng cần phát triển trong những giai đoạn tiếp theo.

Chương trình hiện chưa tích hợp cơ sở dữ liệu hoặc cơ chế lưu trữ dữ liệu lâu dài. Vì vậy, dữ liệu được nhập chỉ tồn tại trong bộ nhớ khi chương trình đang chạy.

### 4.2. Các thông tin cần quản lý

| STT | Thông tin | Vai trò trong quản lý |
|---:|---|---|
| 1 | Mã sinh viên | Phân biệt và nhận diện từng sinh viên |
| 2 | Họ và tên | Xác định thông tin cá nhân của sinh viên |
| 3 | Khoa | Phân loại sinh viên theo đơn vị đào tạo |
| 4 | Tuổi | Theo dõi thông tin tuổi của sinh viên |
| 5 | Năm khóa học | Hỗ trợ phân loại sinh viên theo khóa |
| 6 | Ngành học | Xác định ngành đào tạo của sinh viên |

Các trường dữ liệu trên được xác định nhằm tạo cơ sở cho việc tổ chức và xử lý thông tin trong hệ thống. Trong phiên bản tuần 1, trường năm khóa học đã được khai báo nhưng chưa được đưa vào quy trình nhập và hiển thị dữ liệu.

## 5. Phân tích vấn đề và giải pháp đề xuất

### 5.1. Vấn đề cần giải quyết

Từ phạm vi của đề tài, nhóm xác định một số nhu cầu quản lý cơ bản:

1. **Tổ chức dữ liệu thống nhất.** Thông tin của mỗi sinh viên cần được lưu trữ theo cùng một cấu trúc để thuận tiện cho việc theo dõi, kiểm tra và xử lý.
2. **Bổ sung thông tin thuận tiện.** Hệ thống cần cho phép người dùng nhập thông tin của sinh viên mới và bổ sung vào danh sách hiện có mà không phải xây dựng lại toàn bộ dữ liệu.
3. **Quan sát và kiểm tra danh sách.** Người dùng cần có khả năng xem các thông tin đã nhập trong một bảng thống nhất để kiểm tra dữ liệu và phát hiện những thông tin cần điều chỉnh.
4. **Kiểm soát giới hạn lưu trữ.** Trong phạm vi chương trình hiện tại, số lượng sinh viên được giới hạn ở mức 50 bản ghi. Hệ thống cần kiểm tra giới hạn này trước khi tiếp nhận thông tin mới để tránh ghi dữ liệu vượt phạm vi mảng đã khai báo.
5. **Mở rộng các thao tác quản lý.** Ngoài việc thêm và hiển thị thông tin, hệ thống cần được phát triển để hỗ trợ cập nhật, xóa, thống kê, sắp xếp và lưu trữ dữ liệu lâu dài.

### 5.2. Giải pháp triển khai

Để giải quyết các nhu cầu trên, nhóm xây dựng chương trình quản lý theo hướng tổ chức dữ liệu tập trung và phân chia các thao tác thành những chức năng riêng biệt.

Thông tin sinh viên được lưu trữ trong một danh sách chung. Người dùng tương tác với chương trình thông qua menu, từ đó lựa chọn thao tác phù hợp. Mỗi chức năng được tổ chức thành một hàm riêng nhằm thuận tiện cho việc phát triển và kiểm tra.

Trong tuần 1, nhóm đã triển khai hai chức năng chính:

- **Bổ sung thông tin sinh viên:** Tiếp nhận mã sinh viên, họ tên, khoa, tuổi và ngành học; kiểm tra giới hạn danh sách trước khi thêm dữ liệu.
- **Hiển thị danh sách sinh viên:** Kiểm tra tình trạng danh sách và trình bày các thông tin hiện có theo dạng bảng.

Bên cạnh đó, các chức năng cập nhật, xóa, thống kê, sắp xếp và thao tác với tệp đã được xác định trong cấu trúc chương trình nhưng chưa hoàn thiện phần xử lý.

## 6. Các chức năng và trạng thái triển khai

| Chức năng | Mục đích quản lý | Tiến độ tuần 1 |
|---|---|---|
| Thêm sinh viên | Bổ sung bản ghi sinh viên mới | Đã triển khai |
| Hiển thị danh sách | Theo dõi và kiểm tra thông tin đã nhập | Đã triển khai |
| Cập nhật thông tin | Điều chỉnh thông tin khi có thay đổi | Chưa triển khai |
| Xóa sinh viên | Loại bỏ bản ghi không còn cần thiết | Chưa triển khai |
| Thống kê | Tổng hợp số lượng sinh viên theo tiêu chí | Chưa triển khai |
| Sắp xếp | Tổ chức danh sách theo thứ tự mong muốn | Chưa triển khai |
| Đọc dữ liệu từ tệp | Khôi phục dữ liệu đã lưu | Chưa triển khai |
| Ghi dữ liệu vào tệp | Duy trì dữ liệu sau khi kết thúc chương trình | Chưa triển khai |

Menu hiện cung cấp các lựa chọn tương ứng với những chức năng trên. Đối với các chức năng chưa hoàn thiện, chương trình mới hiển thị thông báo trạng thái thay vì thực hiện thao tác quản lý thực tế.

Việc phân chia các chức năng giúp xác định rõ phạm vi đã hoàn thành và những nội dung cần tiếp tục giải quyết trong quá trình phát triển đề tài.

## 7. Quy trình hoạt động hiện tại

Trong phiên bản tuần 1, quy trình sử dụng chương trình được tổ chức như sau:

1. Người dùng khởi động chương trình quản lý thông tin sinh viên.
2. Chương trình hiển thị menu các chức năng.
3. Người dùng lựa chọn thao tác cần thực hiện.
4. Nếu lựa chọn thêm sinh viên, chương trình kiểm tra sức chứa của danh sách và tiếp nhận các thông tin cần thiết.
5. Nếu lựa chọn hiển thị danh sách, chương trình kiểm tra dữ liệu hiện có và trình bày thông tin theo dạng bảng.
6. Với các chức năng chưa hoàn thiện, chương trình thông báo tình trạng triển khai.
7. Sau mỗi thao tác, chương trình quay lại menu để tiếp tục nhận yêu cầu.
8. Người dùng chọn chức năng thoát để kết thúc chương trình.

Do chưa có chức năng lưu trữ lâu dài, danh sách sinh viên hiện chỉ được duy trì trong thời gian chương trình hoạt động. Đây là một hạn chế cần được giải quyết trong các giai đoạn tiếp theo.

## 8. Kết quả đạt được trong tuần 1

Trong tuần đầu tiên, nhóm đã xây dựng được nền tảng ban đầu cho chương trình quản lý thông tin sinh viên.

Các kết quả chính bao gồm:

- Xác định được những thông tin cơ bản cần quản lý đối với mỗi sinh viên.
- Xây dựng danh sách dữ liệu tập trung với sức chứa tối đa 50 sinh viên.
- Triển khai khả năng bổ sung thông tin sinh viên mới.
- Triển khai khả năng hiển thị danh sách để người dùng kiểm tra dữ liệu.
- Xây dựng menu điều khiển, định hướng các thao tác quản lý cần thiết.
- Xác định các chức năng còn thiếu và những hạn chế cần khắc phục.

Xét theo mục tiêu giải quyết vấn đề, phiên bản hiện tại đã đáp ứng bước đầu nhu cầu nhập và quan sát thông tin sinh viên trong một danh sách thống nhất. Tuy nhiên, chương trình chưa đáp ứng đầy đủ nhu cầu quản lý vì chưa hỗ trợ chỉnh sửa, xóa, thống kê và bảo toàn dữ liệu sau khi thoát.

## 9. Hạn chế và định hướng phát triển

### 9.1. Hạn chế hiện tại

- Số lượng bản ghi được giới hạn ở mức 50 sinh viên.
- Chưa có cơ chế kiểm tra đầy đủ tính hợp lệ và tính duy nhất của mã sinh viên.
- Chưa triển khai chức năng cập nhật và xóa thông tin.
- Chưa có khả năng tổng hợp dữ liệu theo khoa, ngành học hoặc năm khóa học.
- Chưa hỗ trợ sắp xếp danh sách để thuận tiện cho việc theo dõi.
- Chưa có cơ chế lưu trữ lâu dài nên dữ liệu sẽ mất khi chương trình kết thúc.
- Một số trường thông tin đã được xác định nhưng chưa được sử dụng đầy đủ trong quy trình nhập và hiển thị.

### 9.2. Định hướng phát triển

Trong các giai đoạn tiếp theo, nhóm dự kiến tập trung vào các nội dung sau:

- **Hoàn thiện quản lý hồ sơ:** Cho phép cập nhật và xóa thông tin sinh viên khi cần thiết.
- **Nâng cao chất lượng dữ liệu:** Kiểm tra mã sinh viên trùng lặp, giới hạn độ dài thông tin và xử lý các trường hợp nhập dữ liệu không hợp lệ.
- **Cải thiện khả năng tra cứu:** Bổ sung chức năng tìm kiếm sinh viên theo mã hoặc họ tên.
- **Hỗ trợ tổng hợp thông tin:** Thống kê số lượng sinh viên theo khoa, ngành học hoặc năm khóa học.
- **Tổ chức dữ liệu thuận tiện hơn:** Bổ sung chức năng sắp xếp danh sách theo những tiêu chí phù hợp.
- **Đảm bảo tính liên tục của dữ liệu:** Xây dựng cơ chế đọc và ghi tệp để thông tin được duy trì giữa các lần chạy chương trình.

Các định hướng này nhằm từng bước chuyển chương trình từ công cụ nhập và hiển thị dữ liệu ban đầu thành một giải pháp quản lý thông tin sinh viên có đầy đủ hơn các thao tác cần thiết.

## 10. Kết luận

Trong tuần 1, nhóm đã bước đầu xây dựng được chương trình quản lý thông tin sinh viên với hai chức năng cốt lõi là thêm mới và hiển thị danh sách. Đây là nền tảng ban đầu để tổ chức dữ liệu sinh viên theo một cấu trúc thống nhất và hỗ trợ người dùng theo dõi thông tin thuận tiện hơn.

Tuy nhiên, để giải quyết đầy đủ nhu cầu quản lý, chương trình cần tiếp tục được hoàn thiện về khả năng chỉnh sửa, xóa, tìm kiếm, thống kê và lưu trữ dữ liệu. Trong những giai đoạn tiếp theo, nhóm sẽ tập trung phát triển các chức năng này nhằm nâng cao tính hữu ích, độ tin cậy và khả năng đáp ứng yêu cầu quản lý của chương trình.

## 11. Phân công công việc

### Người A – Xây dựng khung chương trình và nền tảng

- Khởi tạo repository GitHub, cấu hình `.gitignore` và thêm thành viên B.
- Khai báo `struct SinhVien`, mảng `danhSach[MAX_SV]`.
- Xây dựng hàm `main()` và giao diện menu `inMenu()`.
- Triển khai các hàm xử lý nhập liệu: `docDong()`, `nhapSoNguyen()`, `nhapChuoiKhongRong()`.
- Xây dựng chức năng hiển thị danh sách sinh viên: `hienThi()` và `hienThi1SV()`.

### Người B – Xây dựng chức năng nghiệp vụ và xử lý dữ liệu

- Khởi tạo file `README.md` giới thiệu đề tài và thành viên nhóm.
- Xây dựng các hàm kiểm tra dữ liệu: `kiemTraKhoaNganh()`, `nhapMaKhoaNganh()`, `nhapNgaySinh()`, `taoMaSV()`, `chuanHoaMaCu()`.
- Triển khai chức năng thêm sinh viên `themSinhVien()`.
- Xây dựng hàm tạo dữ liệu mẫu `danhSachSinhVien()` để phục vụ kiểm thử.

**Mục tiêu tuần 1:** Hoàn thành khung chương trình, cơ chế nhập liệu cơ bản, hiển thị danh sách và chức năng thêm sinh viên ban đầu.
