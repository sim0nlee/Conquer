# CONQUER

![image](https://github.com/sim0nlee/Conquer/assets/94008546/69ceed33-eb6a-44b5-ba6d-94561cc53ebe)
![image](https://github.com/sim0nlee/Conquer/assets/94008546/6a1607be-9a1b-4bb7-9410-ad84eb347e7e)




Conquer is a game of strategy developed as an Android application, in which players take turns fighting for control over a square grid.

The application features a Log In system for the users, which can decide to join a match by entering a queue. As soon as two users are in queue, the server pairs them and starts a game. Users can also, at any given time, check a list of other currently active users.

The game server is multi-threaded, written in C and hosted on a Microsoft Azure virtual machine, communicating with the Java Android client through TCP/IP Sockets. The multi-threaded nature of the server allows multiple games to be active at once. Concurrence is avoided through mutex semaphores.

