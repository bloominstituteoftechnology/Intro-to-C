# Quicksort 

For this module, you're going to implement a quicksort function. Feel free to reference prior implementation(s) and simply transpose the code from one language to the other. Typically this is a good way to practice new languages you're trying to learn: by transposing code you've written from one language to another.

In case you haven't seen the quicksort algorithm before, here's a Python implementation that you can use as a reference:
```python
def quicksort(alist, begin=0, end=None):
  if end is None:
    end = len(alist) - 1
  if begin < end:
    pivot = partition(alist, begin, end)
    quicksort(alist, begin, pivot-1)
    quicksort(alist, pivot+1, end)

def partition(alist, begin, end):
  pivot = begin

  for i in range(begin+1, end+1):
    if alist[i] <= alist[begin]:
      pivot += 1
      alist[i], alist[pivot] = alist[pivot], alist[i]
  
  alist[pivot], alist[begin] = alist[begin], alist[pivot]

  return pivot
```
Keep in mind that since Python is a higher-level language than C, it provides language features and constructs that aren't available in C. For example, the swapping syntax in Python isn't going to work in C without some additional work. The `swap` that you implemented earlier in the sprint has been included in this directory in the `lib.h` header file though, so you can use it here to swap values within an array in-place. Another Python language feature that you can't replicate in C are the default function parameters.

Navigate to the `quicksort.c` file. Implement your quicksort algorithm, then type `make tests` to check if you have all the tests passing. 