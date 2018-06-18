FROM gcc:4.9
COPY . /usr/src/
WORKDIR /usr/src/callbacks
CMD ["make", "tests"]