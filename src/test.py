import MyModule

# simple functions
print MyModule.getNumber()
print MyModule.setGetNumber(4)
print MyModule.getString()

# struct
point = MyModule.getPoint()
print point.x

# class
classA = MyModule.ClassA( 55 )
print classA.a
print classA.getA();

# struct in class
vector = classA.getVector();
print vector.x

# enum in class
print classA.setGetColor(MyModule.ClassA_COLOR.RED);
