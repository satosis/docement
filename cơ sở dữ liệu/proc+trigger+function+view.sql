
/*Bai  1 :Tạo thủ tục có đầu vào là MAHS,đầu ra là điểm trung bình ,lớp ,gvcn trong đó dtb=((toán+van)*2+ly+hoa)/6*/
alter procedure Bai1(@mahs nvarchar(5),@dtb float output,@lop nvarchar(54) output ,@gvcn nvarchar(55) output)
as
begin 
	declare @toan float,@ly float ,@hoa float ,@van float
	select @mahs=DIEM.MAHS ,@dtb=round((TOAN*2+VAN*2+LY+HOA)/6,2),@lop =DSHS.LOP,@gvcn= LOP.GVCN  from DIEM
	join DSHS on DIEM.MAHS=DSHS.MAHS
	join LOP on DSHS.LOP=LOP.LOP
	where DIEM.MAHS=@mahs
end
declare @dtb float,@lop nvarchar(54) ,@gvcn nvarchar(55)
EXEC Bai1 '00020' ,@dtb output ,@lop output ,@gvcn output
print @dtb
print @lop
print @gvcn

/*Bai  2: Tạo hàm có đầu vào là lớp,đầu ra là dshs (mã hs,ten, gt,điểm,dtb ,xếp loại*/
ALTER function Bai2(@lop nvarchar(10))
returns table 
as
return (select DSHS.MAHS,HO,TEN,

(case 
when NU=0 then N'Nữ'
WHEN NU=1 then N'Nam'
end) as GIOITINH ,TOAN,LY,HOA,VAN,
ROUND(((TOAN+VAN)*2+LY+HOA)/6,2) AS DTB,
(
CASE
	WHEN ROUND(((TOAN+VAN)*2+LY+HOA)/6,2) >=5 THEN N'Lên lớp'
	when ROUND(((TOAN+VAN)*2+LY+HOA)/6,2)  <5 then N'Lưu ban'
	end) as XepLoai
from DSHS
JOIN DIEM ON DSHS.MAHS=DIEM.MAHS
)
SELECT * FROM Bai2('10A1')