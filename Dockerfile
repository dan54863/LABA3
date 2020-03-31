FROM ubuntu
COPY ./laba3.cpp .
RUN apt update
RUN apt install -y vim
RUN apt install -y build-essential

