# 有效 IP 地址


def valid_ip(s: str):
    res = s.strip().split(".")
    if len(res) != 4:
        return False

    for i in res:
        try:
            parsed = int(i)
        except ValueError:
            return False
        if parsed > 255 or parsed < 0:
            return False

        if i != str(parsed):
            return False

    return True


if __name__ == "__main__":
    cases = [
        "1.1.1.1",
        "38.0.101.76",
        "56.14.355.256",
        "01.5.200.6.56..561",
        "1.05.250.6",
        "1.5.250 .6",
        "1.5.25 0.6",
        " 1.1.1.1",
    ]

    for i in cases:
        print(valid_ip(i))
