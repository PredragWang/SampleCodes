#!/usr/bin/python

def is_palindrome(name1, name2):
  tmp = name1.lower()+name2.lower()
  ptr1,ptr2 = 0, -1
  while ptr1 - ptr2 < len(tmp):
    if tmp[ptr1] != tmp[ptr2]:
      return False
    ptr1 += 1
    ptr2 -= 1
  return True

def palindromes(names):
  ret = []
  n = len(names)
  for i in range(n):
    for j in range(i+1, n):
      if is_palindrome(names[i], names[j]):
        ret.append([names[i], names[j]])
      if is_palindrome(names[j], names[i]):
        ret.append([names[j], names[i]])
  return ret

def main():
  print "Input names(seperated by spaces)"
  names = raw_input().split()
  pal_combinations = palindromes(names)
  print "Palindrome combinations:"
  for c in pal_combinations:
    print c[0] + " " + c[1]

if __name__ == "__main__":
  main()
