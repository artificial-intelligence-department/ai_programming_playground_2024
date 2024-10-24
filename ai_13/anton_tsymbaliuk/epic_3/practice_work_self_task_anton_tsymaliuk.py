_skip = 1

def longestIdentical(text: str):
        max_len = 1
        temp_max= 1
        start = 0

        end = 1
        f_start = 0
        for i in range(len(text) - 1):
            if(text[i] == text[i+1]):
                temp_max += 1
                if(temp_max > max_len):
                    max_len = temp_max
                    start = f_start
                    end = i + 2
            else: 
                f_start = i + 1
                temp_max = 1
        return text[start:end]

def getPalyndrome(max_len ,text: str, j):           #функція з коментаряя нижче, зберігає ~30 ms
        skip = 1
        start = j- 1
        end = j+1
        while j < len(text) - 1:
            if(text[j] == text[j+1]):
                end = j + 2
                skip += 1
                j+=1
            else: 
                break
        temp_max = end - start
        i = start - 1
        j = end
        while i >= 0 and j < len(text):
            if(text[i] == text[j]):
                temp_max += 2
                start = i 
                end = j + 1
            else: break
            i -= 1
            j += 1
        _skip = skip
        return text[start: end] if temp_max > max_len else ""
        


def getPolydrome(max_len, text: str, i, j):
     temp_max = 1
     start, end = i, j
     while i >= 0 and j < len(text):
            if(text[i] == text[j]):
                temp_max += 2
                start = i 
                end = j + 1
            else: break
            i -= 1
            j += 1
     return text[start: end] if temp_max > max_len else ""

def longestPalindrome(text: str) -> str:
        polidrome = longestIdentical(text)
        max_len = len(polidrome)
        i = 1
        while i < len(text) - 1:
            if text[i - 1] == text[i]:
                string = getPalyndrome(max_len, text, i)
                if(string != ""):
                     polidrome = string
                     max_len = len(polidrome)
                i += _skip
                continue
            elif text[i - 1] == text[i + 1]:                    #інколи може два рази пропустити чрез цикл, якщо у верхню перевірку додати можливість виділяти зразу всі однакові символи може вийти швидше
                string = getPolydrome(max_len, text, i - 1, i + 1)
                if(string != ""):
                     polidrome = string
                     max_len = len(polidrome)
            i +=1
        return polidrome



text = "babad"
print(longestPalindrome(text))