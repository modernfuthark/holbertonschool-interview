 #!/usr/bin/python3

def canUnlockAll(boxes):
    if boxes:
        keys = [0] # Box 0 is unlocked
        required = [i[0] for i in enumerate(boxes)] # Gets an array equal to length

        for i in range(0, len(boxes)):
            for v in boxes[i]:
                if v not in keys and v < len(boxes) and v != i:
                    keys.append(v);
                    i = v

        # print(f'Required: {required}\nHas: {sorted(keys)}')

        return sorted(keys) == required
    return False