import pygame

pygame.init()

#ตั้งขนาดจอของเกม
screen = pygame.display.set_mode((760,650))

#ตั้งชื่อที่แสดงแถบข้างบนเกม
pygame.display.set_caption("Connect 4")

Running = True

def KeyCheck():
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            print("out")
            global Running
            Running = False

def CreateLine():
    for z in range(0,6,1):
        x = (z * 15) + 100
        y = 0
        xx = (z * 15) + 100
        yy = 650
        pygame.draw.line(screen,(51,51,204),(x,y),(xx,yy),10)

#51, 102, 255

pygame.
CreateLine()
while Running:
    KeyCheck()