## grpc
Use grpc to commit between obu and car, car acts as server, and obu acts as client.

## Features
#### Server Push
because grpc support stream mode, then we can achieve bidirectional communication.
- clinet to server. Use request which is the usual pattern
- server to client. First, the client subscribes to some topics. In fact, the client sends some requests first, and then the server uses the stream to push to client.

## Design

## Testcase