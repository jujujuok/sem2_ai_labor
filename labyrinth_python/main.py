

def import_lab(path) -> list[str]:
    with open(path, "r") as file:
        lines = file.read().split("\n")
        return lines


def get_lab_attributes(labyrinth) -> dict:
    lab = labyrinth["lab"]

    for col in range(len(lab)):
        for row in range(len(lab[col])):

            if "S" == lab[col][row]:
                labyrinth["start"] = [col, row]

            elif "X" == lab[col][row]:
                labyrinth["treasure"] = [col, row]

    return labyrinth


def find_solution(lab: list[str], x: int, y: int) -> bool:
    if x == labyrinth["treasure"][0] and y == labyrinth["treasure"][1]:
        global solution
        solution = lab
        return True

    if lab[x][y] == "#" or lab[x][y] == ".":
        return False

    if lab[x][y] == " ":
        lab[x][y] = "."

        if (find_solution(lab, x + 1, y) or
                find_solution(lab, x, y + 1) or
                find_solution(lab, x - 1, y) or
                find_solution(lab, x, y - 1)):
            return True
        else:
            lab[x][y] = " "
    return False


def print_lab(lab: dict):
    print(f"start: {lab['start']}\t treasure: {lab['treasure']}")
    for line in lab["lab"]:
        print(line)


def main(path: str, labyrinth: dict):
    labyrinth["lab"] = import_lab(path)

    labyrinth = get_lab_attributes(labyrinth)
    print_lab(labyrinth)

    find_solution(labyrinth['lab'], labyrinth["start"][1], labyrinth["start"][0])
    print("\nSolution:")
    global solution
    print(solution)


if __name__ == '__main__':
    path = r"C:\DHBW\2.Semester\sem2_ai_labor\labyrinth\data\testlab.txt"

    labyrinth = {
        "lab": list[str],
        "costs": 0,
        # "max_row": 0,
        "start": [],
        "treasure": []
    }

    main(path, labyrinth)
