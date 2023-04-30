# Game Sliding Puzzle 
## Hướng dẫn cài dặt:
- clone git về máy và chạy file game_test.exe
- trong trường hợp không chạy được thì cài codeblock và thư viện SDL2

## Mô tả chung về trò chơi:
- Đây là trò chơi xếp hình. Mỗi hình ảnh sẽ được chia thành nhiều mảnh nhỏ và bị xáo trộn đi. Nhiệm vụ của bạn là sắp xếp các mảnh ghép ấy về đúng vị trí để được một tấm hình hoàn chỉnh.
- Game được lấy nguồn cảm hứng mạnh mẽ từ trò chơi xếp hình trên thước kẻ ngày bé (đã cải tiến thành công)
- Sử dụng các phím mũi tên để di chuyển hình ảnh

## Mô tả các chức năng đã cài đặt:
- game có menu có thể quay lại bất kì lúc nào;
- ĐẶC BIỆT game có con BOT có thể tự chơi game;
- sử dụng cả bàn phím và chuột;
- game có âm thanh (có thể tùy chỉnh tắt đi bật lại);
- game có nhiều level 3x3,4x4,5x5,...,10x10;


## Các kĩ thuật lập trình được sử dụng:
-logic game em tự nghĩ
- thuật toán random các hình ảnh nhỏ
- nghĩ được thuật toán cho con bot
- tìm hiểu về lập trình hướng đối tượng để xây dựng game
- sử dụng mô hình MVC (Model - View - Controller)

## Tài liệu tham khảo
lazyfoo.net(render ảnh, cắt ảnh, âm thanh, event)

## Kết luận, hướng phát triển, các điều tâm đắc:
Game đã tương đối hoàn chỉnh: có đồ hoạ, âm thanh, menu, bot.

 # Hướng cải tiến:
- Thêm giới hạn về thời gian (em không làm điều này vì game có quá nhiều level,bản thân em để chơi qua level 3x3 cũng mất khá nhiều thời gian nên không biết set thời gian thế nào cho hợp lí
- Tính số lượt di chuyển, xếp hạng điểm cao
 # Điều tâm đắc: 
- xây dựng được con bot tự chơi game
- áp dụng được lập trình hướng đối tượng, MVC;
- đồ họa game đẹp, em vẽ 100%
