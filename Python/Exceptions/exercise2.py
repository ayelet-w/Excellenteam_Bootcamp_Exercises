def get_list_element(my_list, index):
    try:
        print(my_list[index])
    except IndexError as e:
        print("invalid index", e.args)
    except Exception as e:
        print("Exception is:", e.args)



