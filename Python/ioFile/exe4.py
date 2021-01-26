import csv
import json

the_file = open("txt_file_exe4.txt")
data = the_file.read().split("\n")

data_json = []
for my_data in data:
    temp_list = my_data.split('-')
    temp_dict = dict()
    temp_dict[temp_list[0]] = temp_list[1]
    data_json.append(temp_dict)

with open("file_json_exe_4.json", "w") as json_file:
    json.dump(data_json, json_file)

with open("file_csv_exe_4.csv", "w") as csv_file:
    csv_writer = csv.writer(csv_file)
    csv_writer.writerow(["item","price"])
    for my_data in data:
        csv_writer.writerow(my_data.split('-'))





