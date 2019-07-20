import stripe
import turtle as tt
import svgwrite
from svg_turtle import SvgTurtle
from svglib.svglib import svg2rlg
from reportlab.graphics import renderPDF, renderPM
#import cairosvg

#turtle
tt.forward(200)
tt.done()


# turtle2fan

OUTPUT_FILE = 'picture.h' # modify this line
TEMP_FILE = 'temp'
drawing = svgwrite.Drawing(TEMP_FILE + '.svg', size=("500px", "500px"))
drawing.add(drawing.rect(fill='white', size=("100%", "100%")))
t = SvgTurtle(drawing)
tt.Turtle._screen = t.screen
tt.Turtle._pen = t

############################
# draw your picture below  #
############################

tt.fillcolor('blue')
tt.begin_fill()
for i in range(20):
    d = 50 + i*i*1.5
    tt.pencolor(0, 0.05*i, 0)
    tt.width(i)
    tt.forward(d)
    tt.right(144)
tt.end_fill()

############################
# draw your picture above  #
############################
drawing.save()
drawing = svg2rlg(TEMP_FILE + ".svg")
renderPM.drawToFile(drawing, TEMP_FILE + ".png", fmt="PNG")
#cairosvg.svg2png(url=TEMP_FILE + '.svg', write_to=TEMP_FILE + '.png')
stripe.picture2Lines(TEMP_FILE + '.png', OUTPUT_FILE, 64)
