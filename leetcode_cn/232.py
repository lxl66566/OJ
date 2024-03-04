class stack:
    def __init__(self):
        self.stack = []

    def push(self, x: int) -> None:
        self.stack.append(x)

    def pop(self) -> int:
        return self.stack.pop()

    def peek(self) -> int:
        return self.stack[-1]

    def empty(self) -> bool:
        return len(self.stack) == 0


class MyQueue:
    def __init__(self):
        self.s1 = stack()
        self.s2 = stack()

    def push(self, x: int) -> None:
        self.s1.push(x)

    def pop(self) -> int:
        assert not self.empty()
        if not self.s2.empty():
            return self.s2.pop()
        self.balance()
        return self.pop()

    def peek(self) -> int:
        assert not self.empty()
        if not self.s2.empty():
            return self.s2.peek()
        self.balance()
        return self.peek()

    def empty(self) -> bool:
        return self.s1.empty() and self.s2.empty()

    def balance(self):
        if self.s2.empty():
            while not self.s1.empty():
                self.s2.push(self.s1.pop())


# Your MyQueue object will be instantiated and called as such:
obj = MyQueue()
obj.push(1)
obj.push(2)
param_1 = obj.pop()
param_2 = obj.peek()
obj.push(3)
param_3 = obj.pop()
param_4 = obj.empty()
param_5 = obj.pop()
param_6 = obj.empty()

print(param_1)
print(param_2)
print(param_3)
print(param_4)
print(param_5)
print(param_6)
