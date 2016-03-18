# In The Name Of God
# ========================================
# [] File Name : rpc-client.py
#
# [] Creation Date : 10/16/15
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

from xmlrpc.client import ServerProxy


n = int(input("Please enter n: "))
proxy = ServerProxy('http://localhost:1373')
print(proxy.is_complete(n))
