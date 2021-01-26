import json


def pokemon_with_less_data():
    pokemon_data = json.load(open("pokemone.json"))
    print(list(map(lambda x: {"id": x["id"],
                        "name": x["name"],
                        "type": x["type"],
                        "weight": x["weight"],
                        "height": x["height"],
                        "weaknesses": x["weaknesses"]}, pokemon_data))[0])



def pokemon_names():
    pokemon_data = json.load(open("pokemone.json"))
    return list(map(lambda x:  x["name"], pokemon_data))


def strong_pokemons():
    pokemon_data = json.load(open("pokemone.json"))
    return list(filter(lambda p: p["weight"] > 100, pokemon_data))


def water_pokemons():
    pokemon_data = json.load(open("pokemone.json"))
    return list(map(lambda x: x["name"], list(filter(lambda p: "Water" in p["weaknesses"], pokemon_data))))






