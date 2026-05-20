# iLearn-Algo

Tui đã học thuật toán một cách lan man và không có chiến thuật. Tui tham gia khoá học thuật toán, được A môn DSA ở trường (môn này A samsung ting ting tài khoản nha :v )

Vấn đề là, sau thời gian đó, tôi quên sạch. Tôi cần một chiến thuật hợp lý hơn. Tự viết nhật ký, viết lại giáo trình để giảng cho người khác là cách học hiệu quả nhất trên đời này. Đồng thời đó cũng là những cống hiến thầm lặng của bạn cho cộng đồng, cho thế giới.

## Files

```text
00 roadmap/      Lộ trình học theo ngày
01 solutions/    Solution notes (mỗi bài 1 file)
02 templates/    Template ghi chép và code
04 mistakes/     Tổng hợp lỗi thường gặp
05 tricks/       Mẹo tối ưu C++/Python/general
docs/            Tài liệu tham khảo
.claude/skills/  Claude custom skill cho DSA
HOME.md          Dashboard review và thống kê
```

## Usage

>**Important:** repo này là nhật kí học của tôi. Vì tôi đã có nền tảng, nên kiến thức trong này không được đầy đủ và thiên hướng góc nhìn cá nhân.
>Để hiệu quả nhất, khi clone về bạn hãy xoá hết hoặc đặt các file solutions ra chỗ khác.
>Cũng đừng bắt AI viết solutions. Hãy tự viết solutions như cách bạn viết nhật ký.

Bạn có thể tham khảo roadmap của tui hoặc các nguồn tín hơn. Tui sẽ để các nguồn ở phía cuối cho bạn tham khảo

0. Để bắt đầu, hãy cài [Obsidian](https://obsidian.md/), mở các community plugin là `Dataview`, `templater`, `homepage` (homepage để set auto open `HOME.md` on startup)
1. Mở `HOME.md` để xem bài cần review hôm nay, cập nhật lại `lastReviewed` và `reviewcount`
2. Học theo `00 roadmap/roadmap.md`.
3. Khi giải bài mới, tạo file trong `01 solutions/` từ `02 templates/solution-template.md` (phím tắt `alt + E` để ốp nhanh template)
4. Tự viết chiến lược của bạn. Nhớ viết tag đánh dấu topic

## Spaced Repetition

Có thể tuỳ chỉnh trong `HOME.md`
Lịch review theo `difficulty`:
- `Easy`: `[3, 7, 15, 30, 60, 120, 240]`
- `Medium`: `[1, 3, 7, 14, 30, 60, 120]`
- `Hard`: `[1, 2, 4, 7, 14, 30, 60]`

## AI Mentor

Thời đại AI agent phải có cái này rồi.
Skill nằm tại `.claude/skills/iLearn-algo/SKILL.md`.
- Skill name: `iLearn-algo`
- Chức năng: dạy DSA theo kiểu adaptive (Socratic, progressive hints, pattern-first)
- Kích hoạt:
  - Tự động qua intent (ví dụ: `learn dsa`, `give me a hint`, `review my code`)
  - Gọi trực tiếp mode: `/ilearn-algo <mode>`
Các mode chính:
- `tutor`, `hint`, `solve`, `review`, `interview`, `pattern`, `quiz`, `roadmap`, `compare`
## Reference

Problems: 
- [cses](https://cses.fi/problemset/), [codeforce](https://codeforces.com/) phù hợp với competitive Programming
- [leetcode](https://leetcode.com/), [hackerrank](https://www.hackerrank.com/) phù hợp phỏng vấn, bộ leetcode 75 kinh điển

Books:
- [Competitive Programmer's Handbook](cses.fi/book/book.pdf) - Guide to Competitive Programming/ Antti Laaksonen
- [coding-interview-university](https://github.com/jwasham/coding-interview-university.git)
- [hello-algo](https://github.com/krahets/hello-algo.git)
- Cấu trúc dữ liệu giải thuật - thầy Đỗ Xuân Lôi
- Cpp Primer, Python Crash Course, Core Java - kinh thánh của ngành

Cần file ib

Extension:
- [Competitive Companion](https://chromewebstore.google.com/detail/cjnmckjndlpiamhfimnnjmnckgghkjbl?utm_source=item-share-cb)
- [Competitive Programming Helper (cph)]([Competitive Programming Helper (cph) - Visual Studio Marketplace](https://marketplace.visualstudio.com/items?itemName=DivyanshuAgrawal.competitive-programming-helper))
- (tele) [Codeforces Official](https://t.me/codeforces_official)
- (tele) [Leetcode daily question reminder](https://t.me/MyLeetCodeDailybot)

## License

Personal notes. Free to fork. Good luck.

>Đi một ngày đàng, học một sàng khôn
