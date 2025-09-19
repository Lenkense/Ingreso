import sys
import re

#TODO: change function tu include number of line
def validateOptions(options:list[str], answer:int, num:str, line:int) -> int:
    if len(options) != len(set(options)):
        print("Repeated options in line:", line + 1)
        return 1
    for j,option in enumerate(options):
        if (option == num) ^ (j == answer - 1):
            print("Number of correct answers is not one in line:", line + 1)
            return 1
    return 0

def main():
    if len(sys.argv) != 2:
        print("No file found!")
        exit()

    filename = sys.argv[1]
    try:
        with open(filename, "r") as f:
            lines = f.readlines()
            errors = 0 
            for i,line in enumerate(lines):
                fields = line.split(",")
                question = fields[0]
                answer = int(fields[-1])
                options = fields[1:5]
                if match := re.fullmatch(r"Convertir (\d+) a binario",
                        question):
                    num = int(match.groups()[0])
                    num = bin(num).replace("0b","")
                    errors += validateOptions(options, answer, num, i)
                elif match := re.fullmatch(r"Convertir (\d+) a decimal",
                        question):
                    num = str(int(match.groups()[0],2))
                    errors += validateOptions(options, answer, num, i)
                elif match := re.fullmatch(r"Sumar: (\d+) \+ (\d+)",
                        question):
                    n1 = int(match.groups()[0],2)
                    n2 = int(match.groups()[1],2)
                    result = bin(n1 + n2).replace("0b","")
                    errors += validateOptions(options, answer, result, i)
                elif match := re.fullmatch(r"Restar: (\d+) - (\d+)",
                        question):
                    n1 = int(match.groups()[0],2)
                    n2 = int(match.groups()[1],2)
                    result = bin(n1 - n2).replace("0b","")
                    errors += validateOptions(options, answer, result, i)
                else:
                    print("Not a valid question.")
            if(errors != 0):
                print(errors, "errors found.")
            else:
                print("No errors found.")
    except FileNotFoundError:
        print(f"Error: File '{filename}' not found.")

if __name__ == "__main__":
    main()
