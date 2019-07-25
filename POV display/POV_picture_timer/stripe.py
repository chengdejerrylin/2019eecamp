from argparse import ArgumentParser
from skimage import io
import math

if __name__ == "__main__":
    FILE_NAME = './duck_green.png'
    OUT_FILE  = './duck_green.h'
    FLATTEN = False
    WHITE = False


#################################
#  Do not move the code below   #
#################################

LED_NUM = 8

def is_white(pixel) :
    step = 230
    return pixel[0] > step and pixel[1] > step and pixel[2] > step

def picture2Lines(picture, output, num, white = False) :
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

                if (not is_white(pixel)) or white: # remove white
                    f.write('{' + str(pixel[0]) + ',' + str(pixel[1]) + ',' + str(pixel[2]) + '}')
                else :
                    f.write('{0,0,0}')
                if j != LED_NUM -1 : f.write(',')

            f.write('}')
            if i != num -1 : f.write(',')
            f.write('\n')

        f.write('};\n')

def flatten(picture, output, num, white = False) :
    pic = io.imread(picture).astype('int')

    height, width, _ = pic.shape
    grid = (width // num, height // LED_NUM)
    

    with open(output,'w') as f :
        f.write('const int STRIPE_NUM = ' + str(num) + ';\n')

        f.write('const byte lines')
        f.write('[' + str(num) + ']')
        f.write('[' + str(LED_NUM) + ']')
        f.write('[3]')

        f.write(' = {\n')

        for stripe in range(num) :
            f.write('{')
            for led in range(LED_NUM) :
                result = [0.0,0.0,0.0]

                for x in range(grid[0]*stripe, grid[0]*(stripe+1)) :
                    for y in range(grid[1] * (LED_NUM - led-1), grid[1] * (LED_NUM - led)) :
                        pixel = pic[y][x]
                        if (not is_white(pixel)) or white: # remove white
                            for i in range(3) : result[i] += pixel[i]
                
                for i in range(3) : result[i] = int(result[i] / (grid[0] * grid[1]) + 0.5)

                f.write('{' + str(result[0]) + ',' + str(result[1]) + ',' + str(result[2]) + '}')
                if led != LED_NUM -1 : f.write(',')
            
            f.write('}')
            if stripe != num -1 : f.write(',')
            f.write('\n')
            
        f.write('};\n')

if __name__ == '__main__':
    parser = ArgumentParser(description='A program that convert the picture to LED stripes.')
    parser.add_argument('-i', dest='pic', default=FILE_NAME, help='Input pucture.')
    parser.add_argument('-o', dest="out", default=OUT_FILE, help='output header name.')
    parser.add_argument('-n', dest="num", type=int, default=64, help='number of stripes.')
    parser.add_argument('-f', dest="flat", action='store_true',  help='flatten.')
    parser.add_argument('-w', dest="white", action='store_true',  help='remain white.')

    args = parser.parse_args()
    if args.flat or FLATTEN :
        flatten(args.pic, args.out, args.num, args.white or WHITE)
    else :
        picture2Lines(args.pic, args.out, args.num, args.white or WHITE)
