import random
import os
import string


def ReadDataFromFile(Path):
    # Read data from supplied path, raise IO error if faulty.
    WordList = []
    try:

        with open(Path,"r+") as file:
            content = file.read();
            file = NormalizeInput(content)
            for word in file.split("\n"):
                WordList.append(word)
    
        return WordList

    except Exception as excpt :
        print(excpt.args)  

def NormalizeInput(input):
    # Read string input and normalize it, removing not important characters and whitespaces.
    for character in string.punctuation:
        if character in input:
            input = input.replace(character,"")
    return input.lower()


def ReturnRandomNletterWord(WordList,N):
    # Returns a random N-letter word from supplied list of strings of words.
    twoWordList = [ word for word in WordList if len(word) == N]
    return random.choice(twoWordList);

def ChooseNextIteration(Word,WordList):
    # Checks whether there are possible word outputs and randomly chooses next word of len(Word) + 1.
    # To do: 

    possibleOutputs = [nextword for nextword in WordList if nextword.find(Word)!= -1 and len(nextword) == (len(Word) + 1)] # Get possible outputs.
    if len(possibleOutputs) == 0:
        return 0
    else:
        return random.choice(possibleOutputs)    
    
def appendAtEnd(word, letter):
    # Unused
    # Appends letter character at the end of string(word).
    strg= letter;
    for x in word:
        strg +=x;
    return strg;


def TestProgram(count):
    # Tests main program component (int) count times.
    i = 0
    WordList = ReadDataFromFile("C:/Users/User/Desktop/sjp-20170521/slowa.txt")
    while i < count:
        word = ReturnRandomNletterWord(WordList,2)
        print(word)
        word = ChooseNextIteration(word,WordList)
        while word!= 0:
            print(word)
            word = ChooseNextIteration(word,WordList)

        i= i+1


def main():
   TestProgram(100)



main()  