FROM ubuntu:latest

RUN apt-get update && apt-get install -y binutils build-essential sysstat vim strace man-db
WORKDIR /ubuntu-sample
ADD . .

ENTRYPOINT [ "bash" ]
