import random

name = ""

question = "Will I find wifey?"

answer = ""

number = random.randint(1,9)
print(number)

if (number == 1):
  answer = "Yes - definitely"
elif (number == 2):
  answer = "It is decidedly so"
elif (number == 3):
  answer = "Without a doubt"
elif (number == 4):
  answer = "Reply hazy, try again"
elif (number == 5):
  answer = "Ask again later"
elif (number == 6):
  answer = "Better not tell you now"
elif (number == 7):
  answer = "My sources say no"
elif (number == 8):
  answer = "Outlook not so good"
elif (number == 9):
  answer = "Very doubtful"
else:
  answer = "Error"

if (name == ""):
  print("Question: " + question)
  print("Magic 8-Ball's answer: " + answer)
else:
  print(name + " asks: " + question)
  print("Magic 8-Ball's answer: " + answer)