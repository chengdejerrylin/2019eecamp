#10階
import turtle as tt  # 開頭必須！
def stairs(x):       # 包成一個function
    # 裡面是一個for loop
    for i in range(x):
        tt.forward(100 / x)
        tt.setheading(270)
        tt.forward(100 / x)
        tt.setheading(0)
stairs(10)
stairs(5)
tt.done()  # 結尾必須！