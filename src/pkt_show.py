import scapy
from scapy.layers.inet import IP, TCP
from scapy.layers.l2 import Ether, ARP, STP, Dot1Q


class PktShow:
    def __init__(self):
        self.eth_len = len('ff:ff:ff:ff:ff:ff')
        self.eth_proto_len = len('0x9000')
        self.ip_len = len('255.255.255.255')

    def eth_to_json(self):
        eth = Ether()

        # json convert
        eth_json = {
            'name': eth.name,
            'fields': {
                "dst": eth.dst,
                "src": eth.src,
                "type": hex(eth.type)
            }
        }

        return eth_json

    def arp_to_json(self):
        frame = ARP()

        arp_json = {
            'name': frame.name,
            'fields': {
                'hwtype': hex(frame.hwtype),
                'ptype': hex(frame.ptype),
                'hwlen': frame.hwlen,
                'plen': frame.plen,
                'op': frame.op,
                'hwsrc': frame.hwsrc,
                'psrc': frame.psrc,
                'hwdst': frame.hwdst,
                'pdst': frame.pdst
            }
        }

        return arp_json

    def stp_to_json(self):
        stp = STP()

        stp_json = {
            'name': stp.name
            # TODO: add other fields
        }

        return stp_json

    def dot1Q_to_json(self):
        pkt = Dot1Q()

        pkt_json = {
            'name': pkt.name,
            'fields': {
                # todo: add fields
            }
        }

        return pkt_json

    def ip_to_json(self):
        ip = IP()

        ip_json = {
            'name': ip.name,
            'fields': {
                'version': ip.version,
                'ihl': ip.ihl,
                'tos': ip.tos,
                'len': ip.len,
                'id': ip.id,
                'ttl': ip.ttl,
                'proto': ip.proto,
                'chksum': ip.chksum,
                'src': ip.src,
                'dst': ip.dst
            }
        }

        return ip_json

    def icmp_to_json(self):
        return "no yet"

    def tcp_to_json(self):
        tcp = TCP()

        tcp_json = {
            'name': tcp.name,
            'fields': {
                'sport': tcp.sport,
                'dport': tcp.dport,
                'seq': tcp.seq,
                'ack': tcp.ack,
                'dataofs': tcp.dataofs,
                'reserved': tcp.reserved,
                'flags': tcp.flags,
                'window': tcp.window,
                'chksum': tcp.chksum,
                'options': tcp.options
            }
        }

        return tcp_json

    def udp_to_json(self):
        return "no yet"

test = PktShow()

print test.eth_to_json()
print test.arp_to_json()
print test.ip_to_json()
print test.tcp_to_json()
# print isinstance(capture.getvalue(), basestring)
