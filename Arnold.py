from PIL import Image
import time


def Arnold(FilePath):

    #读取图片
    Data = FilePath.load()
    #创建新图片
    OutFile = Image.new("RGBA",(FilePath.width,FilePath.width))
    Outdata = OutFile.load()
    #循环读取
    for i in range(FilePath.width):
        for j in range(FilePath.height):
            Outdata[(i+j)%FilePath.width,(i+2*j)%FilePath.width] = Data[i,j]
    return OutFile

##########################################

def Unarnold(FilePath):
    Data = FilePath.load()
    OutFile = Image.new("RGBA",(FilePath.width,FilePath.width))
    Outdata = OutFile.load()
    for i in range(FilePath.width):
        for j in range(FilePath.height):
            Outdata[(2*i-j) % FilePath.width,(j-i) % FilePath.width] = Data[i,j]
    return OutFile


def main(FilePath : str , times : int,do : bool):
    InFile = Image.open(FilePath,"r")
    i = 0
    if do == True:
        while i < times:
            InFile= Arnold(FilePath=InFile)
            InFile.save(str(int(time.time()))+"_"+str(i)+".bmp",bitmap_format='png')
            i += 1
        InFile.save(str(int(time.time()))+".bmp",bitmap_format='png')
    else:
        while i < times:
            InFile = Unarnold(FilePath=InFile)
            i += 1
        InFile.save(str(int(time.time()))+"-u.png",bitmap_format='png')

if __name__ == "__main__":

    a = input("???>")
    main(a,12,False)
    pass
