# CPP

### An introduction to C++ but not really... 

This is a series of five C++ modules to understand the specifities of the language when compared to C

- Module 00 - Object Oriented Programming
- Module 01 - Memory allocation, reference, pointers to members and the usage of the switch
- Module 02 - Ad-hoc polymorphism, overloads and orthodox canonical classes
- Module 03 - Inheritance
- Module 04 - Subtype polymorphism, abstract classes and interfaces
- Module 05 - Try/Catch and Exceptions in CPP
<br>

---

# My Notes / Lessons

## Rule of Three / Orthodox Canonical Form
- You must include the following 3 class members

#### Destructor
- Cleans up resources when an object is destroyed
Automatically invoked when an object goes out of scope

#### Copy Constructor
- Creates a new object with its own copy of the resources managed by another object (e.g: when an object is initialized from another object of the same class)
`MyClass obj2 = obj1;` or `MyClass obj1(obj2);`
> either method will trigger the copy constructor 

#### Copy Assignment Operator
- Unlike the copy constructor, the copy assignment operator must deal with the existing state of the object. It typically needs to clean up any current resources the object holds before copying new ones.(e.g: you are assigning one already existing object to another with the '=' operator)
`obj2 = obj1`


### But why tf use this shit ?

- Because of Shallow Copy 
- When you don't provide a custom copy constructor or copy assignment operator, C++ defaults to shallow copying
- Shallow copying means copying the values of the data members from one object to another
> (e.g: if the data member is a pointer, it copies the pointer value, not the actual data it points to)

- This is where the Rule of Three becomes essential by creating a Deep Copy
- In a deep copy, you allocate separate memory (or duplicate the resource) for the new object and only then copy the actual data
- This way, each object gets its own separate copy of the resources, like memory
> (With separate memory allocations for each object, it's safe for each object's destructor to free its memory without affecting the other avoiding shit like memory leaks, dangling pointers, and double free)


---

# Parent-Child Inheritance

- When a child class is created in C++ it first calls the constructor of its parent class
- Only after the parent's constructor finished running, the child class constructor begins to run

### The Process

1. Parent Constructor Called: When you create an instance of the child class, the parent class constructor is automatically called first
2. Parent Constructor Executes: The code inside the parent class constructor runs
3. Child Constructor Begins: After the parent class constructor finishes, the child class constructor starts
4. Child Constructor Executes: The code inside the child class constructor runs

- This order ensures that the object is properly and fully initialized from the most fundamental level (the base class / parent class) and moving up to more features (the derived class / child class)
- This order ensures that the parent is in a consistent and predictable state, all members are initialized, no undefined behavior possible ... etc before even attempting to make a child class

### Memory Allocation
- When a child class object is created, memory is allocated for 2 parts, the first part is for the base (parent) class, then the derived (child) class part
- This is why the base class constructor is called first during the initialization process = to initialize the base part of the memory
- This memory is allocated as a single contiguous block, that's why you can access the base's class members because they are physically part of the derived class's memory (ITS ALL ONE !!!)

<div align="center">
  
```txt
+--------------------------------------+
|               Derived Object         |
+--------------------------------------+
| Base Class Part (Parent)             |
| (Memory for base class members)      |
+--------------------------------------+
| Derived Class Part (Child)           |
| (Memory for derived class members)   |
+--------------------------------------+
```
</div>

---

# Initialization Lists in Inheritance

### Base Class Initialization
- The construction order in C++ wants that base classes are fully initialized before any derived class-specific logic is executed
> In inheritance the base class constructor is called before entering the derived class's constructor body, initialization lists respect this specific order


### Handling Non-Default Base Constructors
- If a base class doesn't have a default constructor, or its private/protected or if specific arguments need to be passed to it, the derrived class **must use** an initialization list
- An initialization list specifies which base constructor to call + with what arguments


### Private/Protected Base Class Constructors
- When the base class constructors are private/protected, the derived class cannot directly call the private constructor of the base class, **so they must use** an initialization list to access these non-public constructors from their base class

<br>

<div align="center">
  
![Screenshot from 2023-11-04 19-33-30](https://github.com/spookier/CPP/assets/77325667/b52b7d36-d076-4a4a-b488-d6ec1a7187ee)

</div>
