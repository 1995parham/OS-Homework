# In The Name Of God
# ========================================
# [] File Name : rpc-server.py
#
# [] Creation Date : 10/16/15
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

from xmlrpc.server import SimpleXMLRPCServer


def is_complete(n):
    divisor_sum = 0
    for i in range(1, n):
        if n % i == 0:
            divisor_sum += i
    if divisor_sum == n:
        return True
    else:
        return False


server = SimpleXMLRPCServer(('localhost', 1373))
server.register_function(is_complete, 'is_complete')
server.serve_forever()
