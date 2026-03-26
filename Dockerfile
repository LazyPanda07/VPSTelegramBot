FROM ubuntu:24.04 AS builder

RUN apt update
RUN apt install -y cmake git unzip gcc g++ ninja-build

COPY ./ /opt/VPSTelegramBot

WORKDIR /opt/VPSTelegramBot

RUN mkdir build

WORKDIR /opt/VPSTelegramBot/build

RUN cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo -DCMAKE_INSTALL_PREFIX=/opt/app -G "Ninja" .. 
RUN cmake --build . -j
RUN cmake --install .

FROM ubuntu:24.04 AS deploy

RUN apt update
RUN apt install -y speedtest-cli
RUN apt upgrade -y

RUN mkdir /certs
RUN mkdir /opt/vps_telegram_bot

WORKDIR /opt/vps_telegram_bot

COPY --from=builder /opt/app ./

RUN chmod +x run.sh

EXPOSE 88
ENTRYPOINT ["./run.sh"]
