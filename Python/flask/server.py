import json

from flask import Flask, request
import store_model

app = Flask(__name__, static_url_path='', static_folder='dist')


@app.route('/priceCheck/<name>')
def price(name):
    product = store_model.get_product(name)
    if not product:
        return json.dumps({"Error": "not such product " + name}), 404
    return json.dumps({"price": product.get("price")})


@app.route('/buy/<name>')
def buy(name):
    product = store_model.get_product(name)
    if not product:
        return json.dumps({"Error": "not such product " + name}), 404
    flag = store_model.reduce_inventory(name)
    if not flag:
        return json.dumps({"Error": "product " + name + " not in stock"})
    return product


@app.route('/sale')
def sale():
    admin = request.args.get('admin')
    if admin == 'true':
        store_model.make_sale()
        return "prices in sale"
    return "prices not in sale"


if __name__ == '__main__':
    app.run(port=3000)
