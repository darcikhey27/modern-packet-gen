#!/usr/bin/python

from flask import Flask
from pkt_show import PktShow

app = Flask(__name__)
pkt_show = PktShow()


@app.route("/")
def home():
    return "Hello World!"


@app.route("/l2/ether")
def ether():
    return pkt_show.eth_to_json()


@app.route("/l2/arp")
def arp():
    return pkt_show.arp_to_json()


@app.route("/l2/stp")
def stp():
    return pkt_show.stp_to_json()


@app.route("/l2/dot1q")
def dot1q():
    return pkt_show.dot1Q_to_json()


@app.route("/l3/ip")
def ip():
    return pkt_show.ip_to_json()


@app.route("/l3/tcp")
def tcp():
    return pkt_show.tcp_to_json()


@app.route("/l3/udp")
def udp():
    return pkt_show.udp_to_json()


@app.route("/l3/icmp")
def icmp():
    return pkt_show.icmp_to_json()



if __name__ == "__main__":
    app.run()
