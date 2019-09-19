#!/usr/bin/python

from flask import Flask, render_template
from pkt_show import PktShow

app = Flask(__name__)
pkt_show = PktShow()


@app.route("/")
def home():
    return render_template("index.html", message="Modern Packet Generator")


@app.route("/l2/show/ether")
def ether():
    return pkt_show.eth_to_json()


@app.route("/l2/show/arp")
def arp():
    return pkt_show.arp_to_json()


@app.route("/l2/show/stp")
def stp():
    return pkt_show.stp_to_json()


@app.route("/l2/show/dot1q")
def dot1q():
    return pkt_show.dot1Q_to_json()


@app.route("/l3/show/ip")
def ip():
    return pkt_show.ip_to_json()


@app.route("/l3/show/tcp")
def tcp():
    return pkt_show.tcp_to_json()


@app.route("/l3/show/udp")
def udp():
    return pkt_show.udp_to_json()


@app.route("/l3/show/icmp")
def icmp():
    return pkt_show.icmp_to_json()


@app.route("/sys/get/interfaces_list")
def get_interfaces_list():
    return "intefacelist not yet implemented"

if __name__ == "__main__":
    app.run()
