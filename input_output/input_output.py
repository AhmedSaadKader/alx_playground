import os

with open("mydata.txt", mode="w", encoding="utf-8") as myFile:
    myFile.write("Some random text\nMore random text\nAnd some more\n")

with open("mydata.txt", encoding="utf-8") as myFile:
    print(myFile.read())

os.rename("mydata.txt", "mydata2.txt")

os.mkdir("mydir")
os.chdir("mydir")

print("Current directory :", os.getcwd())

os.chdir("..")

print("Current directory :", os.getcwd())
os.rmdir("mydir")
