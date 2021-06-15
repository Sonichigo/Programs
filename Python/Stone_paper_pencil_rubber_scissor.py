import random


class Player:
    def __init__(self):
        self.name = ""
        self.cal_score = 0
        self.score_round = []

    def details(self, num):
        self.num = str(num)
        self.name = input("Enter Name of the player"+self.num+":")

    def score(self, cal_score):
        self.cal_score = cal_score
        self.score_round.append(cal_score)

    def choice_entered(self):
        self.choice = input("Enter choice "+self.name+":")
        return self.choice


class PC(Player):

    def details(self):
        self.name = "PC"

    def choice_entered(self):
        choice_list = ["stone", "paper", "pencil", "rubber", "scissor"]
        no = random.randint(0,len(choice_list)-1)
        self.choice = choice_list[no]
        return self.choice


def detailed_score(Player1, Player2, choice1, choice2, rounds):
    print("Round wise score:")
    print(Player1.name, "'s choices and scores are:")
    for i in range(rounds):
        if i < rounds - 1:
            print(choice1[i], end=",")
        else:
            print(choice1[i])
    for i in range(rounds):
        if i < rounds - 1:
            print(Player1.score_round[i], end=",")
        else:
            print(Player1.score_round[i])
    print(Player2.name, "'s choices and scores are:")
    for i in range(rounds):
        if i < rounds - 1:
            print(choice2[i], end=",")
        else:
            print(choice2[i])
    for i in range(rounds):
        if i < rounds - 1:
            print(Player2.score_round[i], end=",")
        else:
            print(Player2.score_round[i])


print("Let the game begin !!")
no_of_players = eval(input("Enter the no of players. 1 or 2:"))
if no_of_players == 1:
    player1 = PC()
    player1.details()
    player2 = Player()
    player2.details(2)
elif no_of_players == 2:
    player1 = Player()
    player1.details(1)
    player2 = Player()
    player2.details(2)
else:
    print("Wrong Input.Restart Game.")
    exit(0)
choice1 = []
choice2 = []
score1 = 0
score2 = 0
i = 0
no_rounds = eval(input("Enter the no of rounds:"))
while i < no_rounds:
    choice1.append(player1.choice_entered())
    choice2.append(player2.choice_entered())
    # player1
    if choice1[i].lower() == "stone" and choice2[i].lower() == "paper":
        score2 += 1
        player1.score(score1)
        player2.score(score2)
    elif choice1[i].lower() == "stone" and choice2[i].lower() == "pencil":
        score1 += 1
        player1.score(score1)
        player2.score(score2)
    elif choice1[i].lower() == "stone" and choice2[i].lower() == "rubber":
        score1 += 1
        player1.score(score1)
        player2.score(score2)
    elif choice1[i].lower() == "stone" and choice2[i].lower() == "scissor":
        score1 += 1
        player1.score(score1)
        player2.score(score2)
    elif choice1[i].lower() == "stone" and choice2[i].lower() == "stone":
        player1.score(score1)
        player2.score(score2)
    elif choice1[i].lower() == "paper" and choice2[i].lower() == "pencil":
        score2 += 1
        player1.score(score1)
        player2.score(score2)
    elif choice1[i].lower() == "paper" and choice2[i].lower() == "rubber":
        score1 += 1
        player1.score(score1)
        player2.score(score2)
    elif choice1[i].lower() == "paper" and choice2[i].lower() == "scissor":
        score2 += 1
        player1.score(score1)
        player2.score(score2)
    elif choice1[i].lower() == "paper" and choice2[i].lower() == "paper":
        player1.score(score1)
        player2.score(score2)
    elif choice1[i].lower() == "pencil" and choice2[i].lower() == "rubber":
        score1 = score1 + 1
        player1.score(score1)
        player2.score(score2)
    elif choice1[i].lower() == "pencil" and choice2[i].lower() == "scissor":
        score1 += 1
        player1.score(score1)
        player2.score(score2)
    elif choice1[i].lower() == "pencil" and choice2[i].lower() == "pencil":
        player1.score(score1)
        player2.score(score2)
    elif choice1[i].lower() == "rubber" and choice2[i].lower() == "scissor":
        score2 += 1
        player1.score(score1)
        player2.score(score2)
    elif choice1[i].lower() == "rubber" and choice2[i].lower() == "rubber":
        player1.score(score1)
        player2.score(score2)
    elif choice1[i].lower() == "scissor" and choice2[i].lower() == "scissor":
        player1.score(score1)
        player2.score(score2)

    # player2
    elif choice2[i].lower() == "stone" and choice1[i].lower() == "paper":
        score1 += 1
        player1.score(score1)
        player2.score(score2)
    elif choice2[i].lower() == "stone" and choice1[i].lower() == "pencil":
        score2 += 1
        player1.score(score1)
        player2.score(score2)
    elif choice2[i].lower() == "stone" and choice1[i].lower() == "rubber":
        score2 += 1
        player1.score(score1)
        player2.score(score2)
    elif choice2[i].lower() == "stone" and choice1[i].lower() == "scissor":
        score2 += 1
        player1.score(score1)
        player2.score(score2)
    elif choice2[i].lower() == "paper" and choice1[i].lower() == "pencil":
        score1 += 1
        player1.score(score1)
        player2.score(score2)
    elif choice2[i].lower() == "paper" and choice1[i].lower() == "rubber":
        score2 += 1
        player1.score(score1)
        player2.score(score2)
    elif choice2[i].lower() == "paper" and choice1[i].lower() == "scissor":
        score1 += 1
        player1.score(score1)
        player2.score(score2)
    elif choice2[i].lower() == "pencil" and choice1[i].lower() == "rubber":
        score2 += 1
        player1.score(score1)
        player2.score(score2)
    elif choice2[i].lower() == "pencil" and choice1[i].lower() == "scissor":
        score2 += 1
        player1.score(score1)
        player2.score(score2)
    elif choice2[i].lower() == "rubber" and choice1[i].lower() == "scissor":
        score1 += 1
        player1.score(score1)
        player2.score(score2)
    else:
        print("Wrong Input")
        print("Try Again")
        no_rounds += 1
    i += 1
choose = eval(input("Enter 1 for only score and Enter 2 for round-wise score:"))
print("Final Result:")
if player1.cal_score > player2.cal_score:
    print(player1.name, " won the game.")
elif player1.cal_score < player2.cal_score:
    print(player2.name, " won the game.")
else:
    print("The game is Draw.")
if choose == 1:
    print("Score of " + player1.name + " is ", int(player1.cal_score))
    print("Score of " + player2.name + " is ", int(player2.cal_score))
elif choose == 2:
    print("Final Score of "+player1.name+" is ", player1.cal_score)
    print("Final Score of " + player2.name + " is ", player2.cal_score)
    detailed_score(player1, player2, choice1, choice2, no_rounds)
else:
    print("Wrong Choice")
