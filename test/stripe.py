from argparse import ArgumentParser
from skimage import io
import math
import turtle as tt

FILE_NAME = './duck_green.png'
OUT_FILE  = './duck_green.h'


#################################
#  Do not move the code below   #
#################################

LED_NUM = 8
def picture2Lines(picture, output, num) :
    pic = io.imread(picture).astype('int')

    height, width, _ = pic.shape
    radius = min(height, width) // 2
    center = (width // 2, height // 2)

    with open(output,'w') as f :
        f.write('const int STRIPE_NUM = ' + str(num) + ';\n')

        f.write('const byte lines')
        f.write('[' + str(num) + ']')
        f.write('[' + str(LED_NUM) + ']')
        f.write('[3]')

        f.write(' = {\n')

        for i in range(num) :
            theta = 3/2 * math.pi + 2* math.pi / num * i # 270 + degree
            f.write('{')

            for j in range(LED_NUM) : # LED number
                r = radius / LED_NUM * (j+1) /2 + radius /2
                x = int(center[0] + r*math.cos(theta) + 0.5)
                y = int(center[1] + r*math.sin(theta) + 0.5)

                if x >= width : x = width-1
                if x < 0 : x = 0
                if y >= height : y = height-1
                if y < 0 : y = 0

                pixel = pic[y][x]

                f.write('{' + str(pixel[0]) + ',' + str(pixel[1]) + ',' + str(pixel[2]) + '}')
                if j != LED_NUM -1 : f.write(',')

            f.write('}')
            if i != num -1 : f.write(',')
            f.write('\n')

        f.write('};\n')

# only for linux
def turtle2lines(output, num) :
        tt.getscreen().getcanvas().postscript(file='.temp.ps')
        picture2Lines('.temp.ps', output, num)



if __name__ == '__main__':
    parser = ArgumentParser(description='A program that convert the picture to LED stripes.')
    parser.add_argument('-i', dest='pic', default=FILE_NAME, help='Input pucture.')
    parser.add_argument('-o', dest="out", default=OUT_FILE, help='output header name.')
    parser.add_argument('-n', dest="num", type=int, default=64, help='number of stripes.')

    args = parser.parse_args()
    picture2Lines(args.pic, args.out, args.num)
