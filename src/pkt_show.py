from scapy.all import *
import sys

def ether_to_str():
    a = repr(Ether().show())
    return a.capitalize()


if __name__ == "__main__":
    ether_to_str()