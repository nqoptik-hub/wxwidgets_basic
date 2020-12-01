# Build stage
FROM ubuntu:focal AS build

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

# Production stage
FROM ubuntu:focal AS production

RUN apt-get update && apt-get install -y --no-install-recommends \
    libwxgtk3.0-gtk3-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /root/wxwidgets_basic

COPY --from=build /root/wxwidgets_basic/build build

CMD [ "build/sample_application" ]
