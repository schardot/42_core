# Minitalk 📡💬 ![Static Badge](https://img.shields.io/badge/moulinette-125%25-brightgreen?style=flat-square)

Minitalk is a project that demonstrates inter-process communication (IPC) using Unix signals. It allows clients to send messages to a server, which receives and processes them in real-time. The project also supports Unicode characters, enabling the transmission of a broader range of messages.

## Features

- **Signal-based Communication**: Uses Unix signals to transmit messages between a client and a server.
- **Server and Client**: The server listens for incoming messages, while the client sends messages using signals.
- **Dynamic Message Handling**: Supports sending messages of variable length, including Unicode characters.

## Usage
### Starting the Server

Run the server in one terminal:

````bash
./server
````
The server will print its process ID (PID), which is required for the client to send messages.

### Sending Messages from the Client
In another terminal, run the client and provide the server's PID along with the message:

````bash
./client <server_pid> "<message>"
````
Parameters:

`<server_pid>`: The process ID of the running server.

`"<message>"`: The message to be sent to the server (supports Unicode).
