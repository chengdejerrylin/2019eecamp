import turtle as tt  # 開頭必須！
def stairs(x):
    tt.forward(100 / x)
    tt.setheading(270)
    tt.forward(100 / x)
    tt.setheading(0)
# x不能是0，所以range從1開始
for i in range(1, 10):
    stairs(i)
tt.done()  # 結尾必須！