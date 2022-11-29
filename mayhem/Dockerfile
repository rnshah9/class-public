FROM --platform=linux/amd64 ubuntu:20.04 as builder

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential clang

COPY . /repo
WORKDIR /repo
RUN make -j8 class
RUN make libclass.a
RUN clang++ /repo/mayhem/fuzz_get_number_of_titles.cpp -fsanitize=fuzzer,address -L /repo/ -lclass -o /fuzz

FROM ubuntu:20.04 as package
RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y libgomp1
COPY --from=builder /repo /repo
COPY --from=builder /fuzz /fuzz_get_number_of_titles
