class Pizza():
    def __init__(self, index):
        self.ingredients = set()
        self.index = index

    def addIngredients(self, ingredient):
        self.ingredients.add(ingredient)

    def getIngredients(self):
        return self.ingredients
    
    def getIndex(self):
        return self.index
    
    def settIndex(self, index):
        self.index = index

class Operation():

    def __init__(self):
        self.M = 0 #pizzas available
        self.T_2 = 0 #number of 2 people teams
        self.T_3 = 0 #number of 3 people teams
        self.T_4 = 0 #number of 4 people teams
        self.pizzas = [] # pizzas of pizzas with indredients
    
    def readData(self, filename):
        contents = []
        filedata = open(filename, 'r+')
        for line in filedata:
            contents.append(line.split())
        self.M = int(contents[0][0])
        self.T_2 = int(contents[0][1])
        self.T_3 = int(contents[0][2])
        self.T_4 = int(contents[0][3])
        for i in range(1, self.M+1):
            ingredients = int(contents[i][0])
            self.pizzas.append(Pizza(i-1))
            for j in range(1, ingredients+1):
                self.pizzas[i-1].addIngredients(contents[i][j])
                self.pizzas[i-1].settIndex(i-1)
   
    def writeOutput(self, filename):
        deliveries = self.algorithm()
        """deliveries = [T_n, P_n, P_n+1, ...]"""
        f = open(filename, 'w')
        f.write(str(len(deliveries)))
        f.write('\n')
        for line in deliveries:
            for item in line:
                string = str(item) + ' '
                f.write(string)
            f.write('\n')

    def algorithm(self):
        deliveries = []
        pizza = len(self.pizzas)-1
        while pizza >=0:
            if self.T_2 > 0 and len(self.pizzas)>=2:
                deliveries.append([2, pizza-1, pizza]) 
                self.pizzas.pop(pizza)
                self.pizzas.pop(pizza-1);
                self.T_2-=1
                pizza -=2
            elif self.T_3 > 0 and len(self.pizzas)>=3:
                deliveries.append([3, pizza-2, pizza-1, pizza])
                self.pizzas.pop(pizza)
                self.pizzas.pop(pizza-1)
                self.pizzas.pop(pizza-2)
                self.T_3-=1
                pizza -=3
            elif self.T_4 > 0 and len(self.pizzas)>=4:
                deliveries.append([4, pizza-3, pizza-2, pizza-1, pizza])
                self.pizzas.pop(pizza)
                self.pizzas.pop(pizza-1)
                self.pizzas.pop(pizza-2)
                self.pizzas.pop(pizza-3)
                self.T_4-=1
                pizza -=4
            else:
                break
        return deliveries


operation_a = Operation()
operation_a.readData("./Input/a_example.in")
operation_a.writeOutput("./Output/a.out")
