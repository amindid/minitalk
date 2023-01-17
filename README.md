# minitalk


The purpose of this project is to code a small data exchange program using UNIX signals.

    # Mandatory part

Create a communication program in the form of a client and a server.

    •The server must be started first. After its launch, it has to print its PID.
    •The client takes two parameters:
            ◦The server PID.
            ◦The string to send.
    •The client must send the string passed as a parameter to the server.
        Once the string has been received, the server must print it.
    •The server has to display the string pretty quickly. Quickly means that if you think
        it takes too long, then it is probably too long.
    •Your server should be able to receive strings from several clients in a row without needing to restart.
    •You can only use these two signals: SIGUSR1 and SIGUSR2.

    # Bonus part

    •The server acknowledges every message received by sending back a signal to the client.
    •Unicode characters support!