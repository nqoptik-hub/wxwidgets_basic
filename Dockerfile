FROM ubuntu:focal

RUN apt-get update && apt-get install -y --no-install-recommends \
    cmake \
    g++ \
    libwxgtk3.0-gtk3-dev \
    make \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /root/wxwidgets_basic

COPY assets assets
COPY include include
COPY src src
COPY CMakeLists.txt .

RUN mkdir build && cd build && cmake -DCMAKE_BUILD_TYPE=Release .. && make

RUN rm -rf assets
RUN rm -rf include
RUN rm -rf src
RUN rm CMakeLists.txt

CMD [ "./build/sample_application" ]
