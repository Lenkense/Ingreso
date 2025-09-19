import sys
import random

# generates options changing 1 bit of the solution
def pokeBits(numOfOptions:int, solution:str) -> list[str]:
    #TODO: Check logic
    maxNumOfChanges = 3
    numOfChars = len(solution)
    n = min(numOfChars, numOfOptions + maxNumOfChanges - 1)
    sample = random.sample(range(numOfChars), n)
    setOfIndeces = []
    for i in range(numOfOptions):
        setOfIndeces.append(sample[i:i + maxNumOfChanges])
    options = []
    for indeces in setOfIndeces:
        option = list(solution)
        numOfChanges = random.randint(1,maxNumOfChanges)
        for i in indeces[:numOfChanges]:
            option[i] = '1' if option[i] == '0' else '0'
        option = "".join(option)
        options.append(option)
    return options

def insertSolution(options:list[str],solution:str) -> int:
    random.shuffle(options)
    # set correct index
    i = random.randint(0,3) # only 4 options
    # insert correct solution
    options.insert(i, solution)
    return i

def bin2dec(numOfQuestions:int, upperBound:int, lowerBound:int) -> list[str]:
    questions = []
    for i in range(numOfQuestions):
        solution = "0"
        reverse = "0"
        # assure there are no palindromes
        while(solution == reverse):
            n = random.randint(lowerBound, upperBound)
            solution = bin(n).replace('0b','')
            # reverse is an option for solutions
            reverse = solution[::-1]
        options = pokeBits(1, solution)
        options.append(reverse)
        options += pokeBits(1, reverse)
        #Assure there are 4 different as
        while(len(options + [solution]) != len(set(options + [solution])) and
              len(set(options + [solution])) != 4):
            options = set(options)
            options.discard(solution)
            options = list(options)
            options += pokeBits(1, reverse)
        correctIndex = insertSolution(options, solution)
        questions.append("Convertir " + str(n) + " a binario,"
            + ",".join(options) + ",300," + str(correctIndex + 1) )
        # index in blooket starts on 1, that's why the + 1
    return questions

#dec 2 Bin
def dec2bin(numOfQuestions:int, upperBound:int, lowerBound:int) -> list[str]:
    questions = []
    for i in range(numOfQuestions):
        n = random.randint(950, 1500)
        solution = bin(n).replace('0b','')
        options = pokeBits(3, solution)
        correctIndex = insertSolution(options, solution)
        options = [ str(int(i,2)) for i in options]
        questions.append("Convertir " + solution + " a decimal,"
            + ",".join(options) + ",300," + str(correctIndex + 1))
        # index in blooket starts on 1, that's why the + 1
    return questions

def sumQuestions(numOfQuestions:int, upperBound:int, lowerBound:int) -> list[str]:
    questions = []
    for i in range(numOfQuestions):
        n1 = random.randint(lowerBound, upperBound)
        n2 = random.randint(lowerBound, upperBound)
        solution = bin(n1 + n2).replace('0b','')
        n1 = bin(n1).replace('0b','')
        n2 = bin(n2).replace('0b','')
        options = pokeBits(3, solution)
        correctIndex = insertSolution(options, solution)
        questions.append("Sumar: " + n1 + " + " + n2
              + "," + ",".join(options) + ",300," + str(correctIndex + 1))
        # index in blooket starts on 1, that's why the + 1
    return questions

def substractionQuestions(numOfQuestions:int, upperBound:int, lowerBound:int) -> list[str]:
    questions = []
    for i in range(numOfQuestions):
        solution = 0
        nMax = 0
        nMin = 0
        # solution must be at least 3 chars
        # that's at leas 100 = 4
        while (len(bin(solution)) < 5):
            n1 = random.randint(lowerBound, upperBound)
            n2 = random.randint(lowerBound, upperBound)
            nMax = max(n1,n2)
            nMin = min(n1,n2)
            solution =  nMax - nMin
        solution = bin(solution).replace('0b','')
        nMax = bin(nMax).replace('0b','')
        nMin = bin(nMin).replace('0b','')
        options = pokeBits(3, solution)
        correctIndex = insertSolution(options, solution)
        questions.append("Restar: " + nMax + " - " + nMin
             + "," + ",".join(options) + ",300," + str(correctIndex + 1))
        # index in blooket starts on 1, that's why the + 1
    return questions

def main():
    if len(sys.argv) > 1:
        numOfQuestions = int(sys.argv[1])
    else:
        numOfQuestions = 10
    upperBound = 1500
    lowerBound = 950
    sumUpperBound = 350
    sumLowerBound = 150
    for i in bin2dec(numOfQuestions, upperBound, lowerBound):
        print(i)
    for i in dec2bin(numOfQuestions, upperBound, lowerBound):
        print(i)
    for i in sumQuestions(numOfQuestions, sumUpperBound, sumLowerBound):
        print(i)
    for i in substractionQuestions(numOfQuestions,
                                   sumUpperBound, sumLowerBound):
        print(i)

if __name__ == "__main__":
    main()
