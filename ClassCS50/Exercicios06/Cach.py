cash = float(input("cash: "))

while True:
    if cash >= 0:
        cents = int(cash * 100)

        cs25 = int(cents / 25)
        cs10 = int((cents - (cs25 * 25)) / 10)
        cs5 = int((cents - (cs25 * 25) - (cs10 * 10)) / 5)
        cs1 = int(cents - (cs25 * 25) - (cs10 * 10) - (cs5 * 5))

        print(cs25 + cs10 + cs5 + cs1)

        break
    else:
        cash = float(input("cash: "))