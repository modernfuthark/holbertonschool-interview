#!/usr/bin/python3
""" UTF-8 Validator """


def validUTF8(data):
    sigBits = [byte & 0b11111111 for byte in data]
    try:
        byteData = bytes(eightBits)
        byteData.decode()
    except:
        return False
    return True
