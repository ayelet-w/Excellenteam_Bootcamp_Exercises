
import pymysql
connection = pymysql.connect(
    host="localhost",
    user="root",
    password="",
    db="store_db",
    charset="utf8",
    cursorclass=pymysql.cursors.DictCursor
)


def get_product(name):
    with connection.cursor() as cursor:
        query = "select * from store where name = %s;".format(name)
        cursor.execute(query, name)
        res = cursor.fetchall()
        return res[0]


def reduce_inventory(name):
    with connection.cursor() as cursor:
        product = get_product(name)
        if product["inventory"] <= 0:
            return False
        inventory = product["inventory"] - 1
        query = f"update store set inventory = %s where name = %s;".format(inventory, name)
        values = (str(inventory), name)
        cursor.execute(query, values)
        connection.commit()
        return True


def make_sale():
    with connection.cursor() as cursor:
        query = f"update store set price = price/2 where inventory > 10;"
        cursor.execute(query)
        connection.commit()

