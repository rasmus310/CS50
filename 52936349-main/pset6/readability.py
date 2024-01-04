from cs50 import get_string
import re

txt = get_string("Write your text: ")

#letters
letters = sum(c.isalpha() for c in txt) #sum of all letters in text
#print(f"Amount of letters in text: {letters}")

#words
words = len(txt.split())
#print(f"Amount of words in text: {words}")

#sentences
sentences = txt.count('.') + txt.count('!') + txt.count('?')
#print(f"Amount of sentences in text: {sentences}")

#Coleman-Liau index
l = letters / words * 100
s = sentences / words * 100

index = (0.0588 * l - 0.296 * s - 15.8)
index = round(index)
#if index is 16 or higher, print "Grade 16+"
if index > 16:
    print("Grade 16+")
# if index is less than 1, print "Before Grade 1"
elif index > 1 and index < 17:
    print(f"Grade {index}")
#if the index is less than 1, print "Before Grade 1"
else:
    print("Before Grade 1")

