# LoadBalancer From Scratch

we can create a load balancer from scratch using ebpf

we will create 4 container. 

1. client
2. 2 backend server
3. load balancer


### Create load balancer container 

In the load balancer container we will create a ebpf program that will be attached to veth interface(eth0) as xdp program

using the `Dockerfile`, we wil create a image
```bash
docker build -t load_balancer .
```
now, we will run the container
```bash 
docker run --rm -it -v .:/lb-from-scratch --privileged -h lb --name lb --env TERM=xterm-color load_balancer
```
your terminal will be changed to lb container terminal

Now, run `make` to build the ebpf program and attach to eth0 interface

Remeber to change the ip address in `xdp_lb_kern.c` file
#### Output

To see the output, we can run `sudo cat /sys/kernel/debug/tracing/trace_pipe` in the host machine

for windows machine, running Docker Desktop with wsl2. we need to run the command in wsl distribution terminal like (ubuntu) if ubuntu is the wsl backend for Docker Desktop.

#### Client

In the client container we will create a client that will send a packet to the load balancer.

now, we will run the container
```bash
docker run --rm -it -h client --name client --env TERM=xterm-color ubuntu
```

Now, `curl` the load balancer ip address
we will get `Connection refused` error.
as there is no process running to listen to the port 80. but our xdp program is attached to eth0 interface.
that will produce the simple print message in the terminal.
