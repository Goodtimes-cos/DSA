def gameWinner(colors):
    moves = 0
    index = 0
    colour = 'w'
    colourCount = 0
    while index != len(colors):
        if colors[index] == colour and colourCount > 2:
            colors.pop(index)
            moves += 1
        elif colors[index] != colour:
            colour = colors[index]
            colourCount = 1
            index += 1
            moves += 1
        else:
            index += 1
            moves += 1
    
    if moves % 2 == 0 or moves == 0:
        return 'bob'
    else:
        return 'wendy'
    
    print(gameWinner("wwwbbbwww"))