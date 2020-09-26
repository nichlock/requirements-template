import re


class results:
    def successful():
        return "ok"

    def fail():
        return "not ok"


class comments:
    def get_tags(line):
        return re.split(r'[\[ \]]', line)
