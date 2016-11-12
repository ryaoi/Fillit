# Fillit
**Fillit -42 project-**

<strong>tips:</strong>

1. create a check so that you can eliminate all invalid strings
2. create a structure so that you can store information about tetrimos, such as:
    - [ ] alphabet
    - [ ] position
    - [ ] adress of the next tetrimos
3. create a map for storing tetrimos. 
    Be careful that the map size is neither too big nor too small.
4. change the information (position) of tetrimos so it would look like this before and after:

    Before the modification...
    
   | . | . | . | . |
   |---|---|---|---|
   | . | . | . | . |
   | . | . | # | # |
   | . | . | # | # |
   
 >x[0] = 2
 >y[0] = 2
 
 >x[1] = 2
 >y[1] = 3

 >x[2] = 3
 >y[2] = 2
 
 >x[3] = 3
 >y[3] = 3
 
  After the modification...
 
   | # | # | . | . |
   |---|---|---|---|
   | # | # | . | . |
   | . | . | . | . |
   | . | . | . | . |
   
 >x[0] = 0
 >y[0] = 0
 
 >x[1] = 0
 >y[1] = 1

 >x[2] = 1
 >y[2] = 0
 
 >x[3] = 1
 >y[3] = 1 
 
5. create an algorhythm to solve the problem (use brute-force algorithm aka backtrack)
 
6. print the result

7. ???

8. Profit :)


p.s. :shipit:

*Using my FILLIT program (or whatever it is!) to solve 10 tetrimos (as provided in the z file inside the example folder) takes just over 1 second (precisely 1.07 sec.).*

