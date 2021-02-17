#!/usr/bin/python3
""" UTF-8 Validator """


def validUTF8(data):
    try:
        byteData = bytes(data)
        byteData.decode()
    except:
        return False
    return True
