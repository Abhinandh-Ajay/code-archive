import json
data = json.load(open("data.json"))
word = input("Enter a word\n")
if word in data.keys():
    print(data[word])
else:
    print("That word does not exist. Please check your input.\n")
