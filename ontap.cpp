#include <iostream>
#include <vector>
#include <string>
#include <random>    // Dành cho bộ sinh số ngẫu nhiên
#include <clocale>   // Dành cho setlocale

// Thêm thư viện này nếu bạn biên dịch trên Windows
#ifdef _WIN32
#include <windows.h>
#endif

/**
 * @brief Thiết lập console để hỗ trợ hiển thị ký tự UTF-8 (tiếng Việt).
 */
void setupConsoleForUTF8() {
#ifdef _WIN32
    // Đặt mã trang (code page) của console thành UTF-8 trên Windows
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    // Đặt locale của C++ để xử lý các chuỗi wide-character (nếu cần)
    // và I/O chuẩn. "en_US.UTF-8" là một locale phổ biến,
    // bạn cũng có thể thử "vi_VN.UTF-8" nếu hệ thống hỗ trợ.
    std::setlocale(LC_ALL, "en_US.UTF-8");
    std::cout.imbue(std::locale("en_US.UTF-8"));
}

int main() {
    // 1. Gọi hàm thiết lập UTF-8
    setupConsoleForUTF8();

    // 2. Khởi tạo danh sách câu hỏi
    // Dữ liệu được trích xuất từ các hình ảnh bạn cung cấp.
    // 
    // !!! QUAN TRỌNG: Bạn hãy thêm tất cả các câu hỏi còn lại vào đây.
    // Hãy giữ nguyên định dạng:
    // "Nội dung câu hỏi\nA. Lựa chọn A\nB. Lựa chọn B\nC. Lựa chọn C\nD. Lựa chọn D",
    // 
    std::vector<std::string> questions = {
        // --- Trích từ ảnh 1 ---
        "Câu 8 (Ảnh 1): Thành phần nào của rễ tham gia hấp thụ nước và ion khoáng chủ yếu?\nA. Lông hút\nB. Tế bào vỏ\nC. Tế bào nội bì\nD. Mạch gỗ",
        "Câu 9 (Ảnh 1): Đâu không phải là nguyên nhân làm giảm hô hấp và sức khoẻ con người?\nA. Sử dụng nhiều thuốc lá\nB. Cây xanh bị che khuất\nC. Không khí bị ô nhiễm\nD. Không gian nơi ở quá nhỏ, ảnh hưởng hô hấp",
        "Câu 11 (Ảnh 1): Trong các hoạt động sau: Sản xuất giấm, muối dưa, làm sữa chua. Có bao nhiêu hoạt động là ứng dụng của lên men lactic?\nA. 1\nB. 2\nC. 3\nD. 0",
        "Câu 5 (Ảnh 1): Các sản phẩm của quá trình đường phân là:\nA. Pyruvate, CO2 và H2O\nB. ATP, NADH, lactic acid\nC. Pyruvate, ATP và NADH\nD. CO2, H2O và ATP",
        "Câu 8 (Ảnh 1): Cho các bệnh sau: Viêm gan B, Sida, cúm, HIV/AIDS, ung thư phổi, lao phổi, COVID-19. Có bao nhiêu bệnh không liên quan về hô hấp?\nA. 3\nB. 4\nC. 5\nD. 6",

        // --- Trích từ ảnh 2 ---
        "Câu 1 (Ảnh 2): Thực vật trên cạn có thể chết khi bị ngập úng. Các giải thích nào dưới đây về hiện tượng trên là đúng?\na) Rễ cây thiếu oxy nên không hô hấp được.\nb) Cây mất nước quá nhiều làm mất cân bằng nước.\nc) Quá trình phân giải hiếu khí diễn ra tạo nhiều sản phẩm độc cho cây.\nd) Lông hút bị chết (hoặc tiêu biến).\n",
        "Câu 4 (Ảnh 2): Các chất hữu cơ được tạo ra trong quang hợp mà mầm (thân mầm và lá mầm) của hạt sử dụng cho sự sống của nó trong thời gian đầu tiên khi hạt nảy mầm là gì?\nA. Chất hữu cơ của mầm\nB. Chất hữu cơ của phôi\nC. Chất hữu cơ của nội nhũ\nD. Chất hữu cơ của lá mầm",
        "Câu 7 (Ảnh 2): Cho các phát biểu sau: (1) Cả 3 con đường... (2) Hô hấp... (3) Có quá trình... (4) Ở ống... Có bao nhiêu phát biểu đúng?\nA. 1\nB. 2\nC. 3\nD. 4",

        // --- Trích từ ảnh 3 ---
        "Câu 18 (Ảnh 3): Những nguyên tố nào sau đây là nguyên tố vi lượng?\nA. C, H, O, K\nB. Fe, Mn, Zn, Cu\nC. P, Mg, S, N\nD. P, K, N, Ca",
        "Câu 20 (Ảnh 3): Vai trò chính của quá trình lên men ở vi sinh vật là gì?\nA. Chuỗi truyền electron\nB. Tổng hợp Acetyl – CoA\nC. Chu trình Krebs\nD. Vòng phân hủy",
        "Câu 26 (Ảnh 3): Trong hệ tiêu hoá của người, dưới tác động của enzyme tiêu hoá, tinh bột được biến đổi thành chất nào sau đây?\nA. Glycerol\nB. Glucose\nC. Acid béo\nD. Amino acid",
        "Câu 29 (Ảnh 3): Khi ăn, gà thường hay nuốt những viên sỏi nhỏ vào dạ dày cơ (mề). Tác dụng của nó là gì?\nA. Cung cấp canxi cho cơ thể\nB. Làm tăng hiệu quả tiêu hoá thức ăn\nC. Làm tăng hiệu quả hoá học\nD. Làm tăng tiết dịch dạ dày của gà",

        // --- Trích từ ảnh 4 ---
        "Câu 1 (Ảnh 4): Các yếu tố nào sau đây ảnh hưởng đến năng suất cây trồng khi được trồng ở điều kiện...?\nA. Quá trình quang hợp lớn hơn hô hấp và...\nB. Tỉ số ... bằng 0\nC. Quá trình hô hấp chiếm ưu thế so với quang hợp\nD. Quá trình ... và hô hấp cân bằng",
        "Câu 3 (Ảnh 4): Nguyên tố đa lượng đóng vai trò chủ yếu là gì?\nA. Thành phần cấu trúc nên tế bào\nB. Hoạt hoá enzyme trong trao đổi chất\nC. Quy định áp suất thẩm thấu của dịch tế bào\nD. Quy định tính thấm của qua và hạt",
        "Câu 12 (Ảnh 4): Nguồn năng lượng khởi đầu của sự sống trên Trái Đất là gì?\nA. Điện năng\nB. Hoá năng\nC. Ánh sáng mặt trời\nD. Năng lượng phóng xạ",
        "Câu 13 (Ảnh 4): Ở thủy tức, bộ phận hấp thụ chất dinh dưỡng chủ yếu là các tế bào:\nA. Xúc tu\nB. Trên thành túi\nC. Chân đế\nD. Ruột non",
        "Câu 16 (Ảnh 4): Trong hệ tiêu hoá ở người, các bộ phận nào vừa diễn ra tiêu hoá hoá học, vừa diễn ra tiêu hoá cơ học?\nA. Miệng, thực quản, dạ dày\nB. Miệng, dạ dày, ruột non\nC. Thực quản, dạ dày, ruột non\nD. Thực quản, dạ dày, ruột già"
    };

    // 3. Kiểm tra xem véc-tơ có rỗng không
    if (questions.empty()) {
        std::cout << "Không có câu hỏi nào trong danh sách." << std::endl;
        return 1; // Thoát nếu không có câu hỏi
    }

    // 4. Thiết lập bộ sinh số ngẫu nhiên
    std::random_device rd;  // Tạo nguồn seed ngẫu nhiên (từ phần cứng nếu có)
    std::mt19937 gen(rd()); // Khởi tạo bộ sinh số Mersenne Twister với seed
    
    // Tạo một phân phối ngẫu nhiên đồng đều trong phạm vi [0, số lượng câu hỏi - 1]
    std::uniform_int_distribution<> distrib(0, questions.size() - 1);

    int soLanLap = 50; // Số lần lặp lại theo yêu cầu

    // 5. Bắt đầu vòng lặp
    std::cout << "--- CHUONG TRINH ON TAP SINH HOC 11 ---\n";
    std::cout << "Se hien thi " << soLanLap << " cau hoi ngau nhien.\n\n";

    for (int i = 0; i < soLanLap; ++i) {
        // Lấy một chỉ số ngẫu nhiên
        int randomIndex = distrib(gen);

        // In câu hỏi ra màn hình
        std::cout << "========== Câu hỏi " << (i + 1) << "/" << soLanLap << " ==========\n";
        std::cout << questions[randomIndex] << "\n";
        std::cout << "======================================\n\n";
    }

    return 0;
}