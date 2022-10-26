#!/usr/bin/python

from flask import Flask, render_template
from flask_cors import CORS
from pkt_show import PktShow

# logging.getLogger('flask_cors').level = logging.DEBUG
app = Flask(__name__)
CORS(app, supports_credentials=True)

pkt_show = PktShow()

@app.route("/")
def home():
    return render_template("index.html", message="Modern Packet Generator")

@app.route("/test")
def test():
    return pkt_show.test()


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
    app.run(host="10.0.20.61", port=5000, debug=True);
