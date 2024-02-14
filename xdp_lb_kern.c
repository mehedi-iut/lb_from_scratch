#include "xdp_lb_kern.h"

#define IP_ADDRESS(x) (unsigned int)(172 + (17 << 8) + (0 << 16) + (x << 24))

#define BACKEND_A 2
#define BACKEND_B 3
#define CLIENT 4
#define LB 5

SEC("xdp")
int xdp_load_balancer(struct xdp_md *ctx){
    bpf_printk("xdp_load_balancer\n");
    return XDP_PASS;
}

char _license[] SEC("license") = "GPL";