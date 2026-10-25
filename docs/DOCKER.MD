# Building with Docker
If you dont already know what docker is [read this](https://docs.docker.com/get-started/docker-overview/), but in short docker
allows you to to build this project without the hassle of dependencies and environmental incompatibilities.
# Requirements
You will have to install docker desktop in order to use docker this [Setup Guide](https://github.com/WCSCourses/index/blob/main/Docker_guide.md)
will help you install it on any platform. You will also have to setup the iso folder as described in the [ReadMe](../README.md#requirements).
# Quick Start
```sh
# sets docker container up with the required dependencies
docker build -t sotc .                          

# building the binary has a different command depending on the platform
# Powershell:
docker run --rm -v "$($PWD.Path):/workspace" sotc 
# Linux/MacOs:
docker run --rm -v "$(pwd):/workspace" sotc
# WindowsCMD:
docker run --rm -v "%cd%:/workspace" sotc
```
