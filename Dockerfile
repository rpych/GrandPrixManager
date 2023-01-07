FROM alpine

RUN apk update && \
    apk add --no-cache \
    build-base \
    cmake

WORKDIR /gpManager

COPY data/ ./data/
COPY model/ ./model/
COPY simulator/ ./simulator/
COPY storage/ ./storage/
COPY utils/ ./utils/
COPY viewer/ ./viewer/
COPY main.cpp .
COPY CMakeLists.txt .


WORKDIR /gpManager/build

RUN cmake .. && make

CMD [ "./grand_prix_manager" ]
