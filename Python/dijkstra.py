class Position:
    def __init__(self, north = False, east = False, south = False, west = False, exit = False):
        self.north = north
        self.east = east
        self.south = south
        self.west = west
        self.exit = exit

def get_maze_size(maze):
    try:
        height = len(maze)
        width = len(maze[0])
        return (height, width)
    except IndexError:
        return (0, 0)

# returns (y, x), index is 0-3 referencing north-west
def get_offset(index):
    return [
        (-1, 0), # north
        (0, 1), # east
        (1, 0), # south
        (0, -1) # west
    ][index]

# the opposite direction's index
def get_opposite_index(index):
    return [2, 3, 0, 1][index]

def get_direction(index):
    return ["north", "east", "south", "west"][index]

# the "closed list"
def create_unavailable_grid(height, width):
    # False if empty, True if occupied
    return [[False for x in range(width)] for y in range(height)]

# the parent of a node (at its position)
def create_parent_grid(height, width):
    return [[None for x in range(width)] for y in range(height)]

def escape_route(maze):
    final = []

    # check if the maze has valid dimensions
    height, width = get_maze_size(maze)
    if height < 1 or width < 1:
        return None

    # create status tracking lists
    y, x = 0, 0
    parent = create_parent_grid(height, width)
    unavailable = create_unavailable_grid(height, width)

    # initialise lists with current node
    available = [ # the "open list"
        [], # y positions
        []  # x positions
    ]
    unavailable[y][x] = True

    # find a path to the exit
    while not maze[y][x].exit:
        # mark adjacent nodes as available
        current = maze[y][x]
        directions = [
            current.north,
            current.east,
            current.south,
            current.west
        ]
        for index in range(4):
            if directions[index]:
                yo, xo = get_offset(index)
                yn, xn = (y + yo), (x + xo)
                if not unavailable[yn][xn]:
                    available[0].append(yn)
                    available[1].append(xn)
                    parent[yn][xn] = get_opposite_index(index)

        # mark the current node as unavailable
        unavailable[y][x] = True

        # ran out of positions to move to
        if len(available[0]) < 1 or len(available[1]) < 1:
            return None

        # get the next available node
        y, x = available[0].pop(0), available[1].pop(0)

    # backtrack current node to get the path
    while parent[y][x] is not None:
        index = get_opposite_index(parent[y][x])
        final.insert(0, get_direction(index))
        # reference the next parent
        yo, xo = get_offset(parent[y][x])
        y, x = (y + yo), (x + xo)

    return final

def can_escape(maze):
    return escape_route(maze) is not None

def create_maze(height, width):
    return [[None for x in range(width)] for y in range(height)]

if __name__ == "__main__":
    maze = create_maze(2, 2)
    maze[0][0] = Position(False, True, False, False, False)
    maze[0][1] = Position(False, False, True, False, False)
    maze[1][1] = Position(False, False, False, True, False)
    maze[1][0] = Position(False, False, False, True, True)
    path = escape_route(maze)
    print(path)


