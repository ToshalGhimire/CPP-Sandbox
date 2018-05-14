"""
Created on Fri Apr  6 10:52:29 2018
PE 13

@author: Toshal Ghimire
"""
from functools import reduce

#Given a list of numbers and a number
#find all multiples of the given number 
def problemOne(ls,num):
    filterd = list(filter(lambda x: x if(x % num == 0) else None,ls)) # if multiples exisit it makes a new list
    return filterd

#Given a list of elements
#find the maximum element without using the max function.
def problemTwo(ls):
    
    
    return reduce(lambda x,y: x if x>y else y, ls) #uses reduce to compare two elements to find max


#Given a list of strings
#create one string that is the concatenation of all unique characters in the strings, case insensitive. 
def problemThree(ls):
    concated = reduce(lambda x,y: x+y, ls) # concats all the elements of a list into a string
    lowercase = list(map(lambda x : x.lower(),concated)) #lower cases all chars inoder to preform the set operation
    output = reduce(lambda x,y: x + [y] if y not in x else x,lowercase,[]) #preforms the set operation using reduce
    output = reduce(lambda x,y: x+y, output) #concats the chars into a string for output
    
    return output

#testing the functions
l = [-2,1,2,3,4,8,10,15,20,100,30]
string = ["hi", "thEre", "Hat"] 


print(problemOne(l,3)) # returns [3,15,30]
print(problemTwo(l)) # returns 100
print(problemThree(string)) # returns hitera
