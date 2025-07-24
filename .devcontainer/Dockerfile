# .devcontainer/Dockerfile

FROM ubuntu:22.04

# 필수 패키지 설치 (g++, cmake, make 등)
RUN apt-get update && apt-get install -y \
    build-essential \
    g++ \
    cmake \
    git \
    curl \
    vim \
    && apt-get clean

# 기본 작업 디렉토리
WORKDIR /workspace

# 기본 g++ 버전 확인 (Ubuntu 22.04의 경우 g++-11 이상, C++17 지원)
RUN g++ --version
