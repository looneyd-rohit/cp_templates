class sample:
    def __init__(self, a, b=1):
        self.a = a
        self.b = b
    def display(self):
        print("Hi".capitalize(format(self.a, self.b))) 
obj1 = sample(5,10)
obj2 = sample(1)
obj1.c = 2
obj1.display()
