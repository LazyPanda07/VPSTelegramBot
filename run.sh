#!/bin/bash

set -e

export LD_LIBRARY_PATH=$(pwd):${LD_LIBRARY_PATH}

cp /start_certs/fullchain.pem /certs/
cp /start_certs/privkey.pem /certs/
./VPSTelegramBot
