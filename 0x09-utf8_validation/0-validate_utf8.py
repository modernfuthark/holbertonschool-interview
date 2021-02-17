#!/usr/bin/python3
""" UTF-8 Validator """


def validUTF8(data):
    sigBits = [byte & 0xFF for byte in data]
    try:
        byteData = bytes(sigBits)
        byteData.decode()
    except:
        return False
    return True
