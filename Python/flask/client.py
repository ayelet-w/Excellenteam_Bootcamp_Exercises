import time

import requests
import sched
global money


def price():
    furniture = input("enter a furniture to check is price:")
    store_url = 'http://localhost:3000/priceCheck/{}'.format(furniture)
    res = requests.get(url=store_url)
    print(res.json())
    res = res.json()
    return res.get("price")


def buy():
    furniture = input("enter a furniture to bay:")
    store_url = 'http://localhost:3000/buy/{}'.format(furniture)
    res = requests.get(url=store_url)
    res = res.json()
    item = res.get("name")
    price_ = res.get("price")
    inventory = res.get("inventory")
    print(f"Congratulations, you've just bought {item} for {price_}. There are {inventory} left now in the store.")


def buy_with_money():
    money = int(input("how mach money do you have? "))
    f_price = int(price())
    if f_price < money:
        money -= f_price
        buy()
    else:
        print("get a job")


def buy_after_sale():
    schedule = sched.scheduler(time.time, time.sleep)

    result = requests.get(url='http://localhost:3000/priceCheck/chair').json()
    curr_price = result["price"]

    def try_to_buy():
        nonlocal curr_price
        res = requests.get(url='http://localhost:3000/priceCheck/chair').json()
        old_price = curr_price
        curr_price = res["price"]
        if curr_price < old_price:
            res = requests.get(url='http://localhost:3000/buy/chair')
            print(res.text)
            print("bought chair for less")
        else:
            print("still waiting for a price drop...")
            schedule.enter(3, 1, try_to_buy)

    schedule.enter(0, 1, try_to_buy)
    schedule.run()


buy_after_sale()



