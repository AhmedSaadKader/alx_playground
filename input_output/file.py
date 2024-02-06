import os

with open("mydata2.txt", encoding='utf-8') as myFile:
    lineNum = 1
    while True:
        line = myFile.readline()
        if not line:
            break

        print("Line", lineNum)
        # Split()
        wordList = line.split()
        # len()
        print("Number of words:", len(wordList))
        # loop count characters in the word list
        charCount = 0
        for word in wordList:
            for char in word:
                charCount += 1
        #Divide character count / len word list
        avgNumCars = charCount/len(wordList)
        print("Avg Word Length: {:.2}".format(avgNumCars))
        lineNum += 1
