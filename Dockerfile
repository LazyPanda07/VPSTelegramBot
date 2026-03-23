FROM ubuntu:24.04 AS builder

RUN apt update
RUN apt install -y cmake git unzip gcc g++ ninja-build

COPY ./ /opt/VPSTelegramBot

WORKDIR /opt/VPSTelegramBot

RUN mkdir build

WORKDIR /opt/VPSTelegramBot/build

RUN cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/opt/app -G "Ninja" .. 
RUN cmake --build . -j
RUN cmake --install .

FROM ubuntu:24.04 AS deploy

RUN apt update
RUN apt upgrade -y

COPY --from=builder /opt/app ./

EXPOSE 88 4923
CMD LD_LIBRARY_PATH=$(pwd) ./VPSTelegramBot
