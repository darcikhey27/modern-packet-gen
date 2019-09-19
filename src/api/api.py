#!/usr/bin/python

from flask import Flask
from pkt_show import PktShow
from subprocess import call
import os

app = Flask(__name__)
pkt_show = PktShow()


@app.route("/")
def home():
    return "Hello World!"


@app.route("/start")
def start():
    # start c lib here
    ret = os.system("./../../obj/modern-pkt-gen")
    if ret == 0:
        return "<h2 class='h2'>pkt-gen started<h2>"
    else:
        return "pkt-gen error"


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



if __name__ == "__main__":
    app.run()
