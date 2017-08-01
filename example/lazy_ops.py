import numpy as np

class Any():
    def __init__(self):
        pass

class Vec(Any):
    def __init__(self, vec):
        self._vec = vec
    def __getitem__(self, idx):
        return self._vec[idx]
    def __len__(self):
        return len(self._vec)
    def __repr__(self):
        repr_str = ""
        for i in self:
            print i
            repr_str += str(i)
        return ""
    def __add__(self, vec2):
        print "Vec Add"
        return VecAdd(self, vec2)
    def __mul__(self, vec2):
        return VecMul(self, vec2)

class VecAdd(Vec):
    def __init__(self, vec1, vec2):
        self._vec1 = vec1
        self._vec2 = vec2
        Vec.__init__(self, np.array([]))
    def __len__(self):
        return len(self._vec1)
    def __getitem__(self, idx):
        print "add"
        return self._vec1[idx] + self._vec2[idx]

class VecMul(Vec):
    def __init__(self, vec1, vec2):
        self._vec1 = vec1
        self._vec2 = vec2
        Vec.__init__(self, np.array([]))
    def __len__(self):
        return len(self._vec1)
    def __getitem__(self, idx):
        print "mul"
        return self._vec1[idx] * self._vec2[idx]

class Scalar(Any):
    def __init__(self, var):
        self._var = var
    def var(self):
        return self._var
    def __repr__(self):
        return str(self.var())
    def __add__(self, op):
        return Add(self, op)
    def __radd__(self, op):
        return self.var() + op
    def __mul__(self, op):
        return Mul(self, op)

class Add(Scalar):
    def __init__(self, op1, op2):
        # ops are all Scalar type
        self._op1 = op1
        self._op2 = op2
        Scalar.__init__(self, 0)

    def var(self):
        print "(Add", type(self._op1.var()), type(self._op2.var()), self._op1.var(), self._op2.var(),  ")"
        self._var = self._op1.var() + self._op2.var()
        return self._var

class Mul(Scalar):
    def __init__(self, op1, op2):
        self._op1 = op1
        self._op2 = op2
        Scalar.__init__(self, 0)

    def var(self):
        print "(Mul", type(self._op1.var()), type(self._op2.var()), self._op1.var(), self._op2.var(), ")"
        self._var = self._op1.var() * self._op2.var()
        return self._var


if __name__ == "__main__":
    w = Scalar(5.0)
    x = Scalar(6.0)
    b = Scalar(1.0)
    y = w*x+b
    print "before print"
    print y

    W = Vec(np.random.randn(10, 1))
    X = Vec(np.random.randn(10, 1))
    B = Vec(np.random.randn(10, 1))
    Y = W*X+B+W+X
    print Y
