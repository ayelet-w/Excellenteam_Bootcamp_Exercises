import csv
import json

data_csv = json.load(open("file_exe3.json"))
with open("file_csv_exe_3.csv", "w") as csv_file:
    csv_writer = csv.writer(csv_file)

    for data in data_csv:
        # create a list with our data (the values from the dict above)
        if (data.get("nutrition-per-100g")):
            data_in_list = [data["name"], data["nutrition-per-100g"]["protein"], data["nutrition-per-100g"]["fat"], data["nutrition-per-100g"]["carbohydrate"], data["nutrition-per-100g"].get("sugars")]
        if (data.get("nutrition-per-100ml")):
            data_in_list = [data["name"], data["nutrition-per-100ml"]["protein"], data["nutrition-per-100ml"]["fat"], data["nutrition-per-100ml"]["carbohydrate"], data["nutrition-per-100ml"]["sugars"]]

        # writes a single row each time
        csv_writer.writerow(data_in_list)

