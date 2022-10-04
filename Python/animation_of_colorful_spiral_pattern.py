import  turtle
import  time
#defining function
def myFun():
    #list for storing colors
    mycolors=["red","blue","green","yellow","orange","brown"]
    #creating turtle variable
    t=turtle
    #setting pensize 
    t.pensize(5)
    #setting background color
    t.bgcolor('black')
    #setting speed of drawing
    t.speed(1000)
    #loop for creating design
    for x in range(360):
        t.pencolor(mycolors[x%len(mycolors)])
        t.pensize(x/50)
        t.forward(x)
        t.left(59)
myFun()
time.sleep(5)
