def decode(str_input):
    code = {
        "0": "A",
        "1": "E",
        "2": "O",
        "3": "U",
        "4": "G",
        "5": "R",
        "6": "T",
        "7": "U",
        "8": "Y"
    }
    result = ""
    return result.join(list(map(lambda x: code[x], str_input)))



