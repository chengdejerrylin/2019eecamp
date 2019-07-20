import turtle as tt
tt.speed(0)

# 可以調整size和multi的數字
# size不要太大，盡量在300以內
# multi要是整數
size = 100
multi = 3

angle = 360 / size
pos_list = []
tt.left(90 + angle / 2)
for i in range(size):
    tt.pendown()
    # 記錄經過的點的位置
    # pos()函數會回傳一組座標
    pos_list.append(tt.pos())
    tt.right(angle)
    tt.forward(1000 / size)
    tt.penup()
print(pos_list)
  
for i in range(size):
    tt.goto(pos_list[i])
    tt.pendown()
    # 看影片就知道為什麼了><
    # https://youtu.be/qhbuKbxJsk8
    next = (i*multi) % size
    tt.goto(pos_list[next])
    tt.penup()
tt.goto(pos_list[0])
tt.done()