import sum_of_squares
import decode
import pokemon


def test_sum_of_sqrt():
    print("test sum of sqrt:")
    print(sum_of_squares.sum_of_squares([2, 3, 55, 4, 6, 8, 43, 10]))


def test_decode():
    print("test decode")
    print(decode.decode("82705145106"))


def test_pokemone():
    print("test pokemone with less data:")
    pokemon.pokemon_with_less_data()
    print("test pokemone names:")
    print(pokemon.pokemon_names())
    print("test strong pokemons- check if the len == 15:")
    print(len(pokemon.strong_pokemons()))
    print("test water pokemone with the list:")
    test_water = ['Charmander', 'Charmeleon', 'Charizard', 'Sandshrew', 'Sandslash', 'Nidoqueen', 'Nidoking', 'Vulpix', 'Ninetales', 'Diglett', 'Dugtrio', 'Growlithe', 'Arcanine', 'Geodude', 'Graveler', 'Golem', 'Ponyta', 'Rapidash', 'Magnemite', 'Magneton', 'Onix', 'Cubone', 'Marowak', 'Rhyhorn', 'Rhydon', 'Magmar', 'Flareon', 'Aerodactyl', 'Moltres']
    print(pokemon.water_pokemons() == test_water)


def test_all():
    test_decode()
    test_pokemone()
    test_sum_of_sqrt()

